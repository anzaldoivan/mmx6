#!/usr/bin/env python3
"""declsync.py -- move a defined function's declarations across a program's C files to its definition's signature
(reconcile rung R3, tools/mmx6/bank.py; container python3, stdlib only, text only).

  declsync.py --prog <p> --def <body.c> [--dry-run]
      -> per C definition in <body.c>, over every src/<p>/*.c and each file they `#include "<rel>"` from src/:
         each prototype `<ret> <func>(<params>);` and each call-site cast `((<ret> (*)(<params>))<func>)` that
         differs from the definition is rewritten to the definition's signature (cast removed) when width-compatible
         (same return width, same param count, each param width equal; pointers/s32/u32/int = 4), else refused.
         An unprototyped prototype `<ret> <func>();` or cast `((<ret> (*)())<func>)` (C0124) is left as written
         (return width compared; a `void` return accepted); a `void`-returning cast of a non-void definition is
         left as written (params compared). M2C_UNK counts as width 4.
         One line per change `DECLSYNC synced|uncast|refused <path>:<line> <func> [<why>]`; last line
         `DECLSYNC <funcs> synced <s> uncast <c> refused <r> files <k>`; rc 0 iff r = 0. Nothing is written when any
         declaration is refused, or under --dry-run.
  Library: sync_text(..., force=True) (gate.py's `tusync`) refuses nothing and also rewrites a top-level
      `extern <type> <func>;` object declaration to the definition's prototype; unit_files(prog, start) follows the
      #include closure of the given files only (one TU); header_decls(files, func) lists func's column-0 prototypes in
      the .h files that closure reaches (`#include` resolved relative, then under include/, then src/).
      Repair switch declunify (3.1 T3, bank.declunify): body_decl(text, name) reads the body's declaration of name;
      unify_text(path, text, name, decl, old) gives a file's disagreeing declarations decl's spelling and its
      mismatching direct calls an unprototyped cast of the prevailing return (`DECLUNIFY synced|cast <path>:<line>`).
  declsync.py --self-test
      -> in memory: width-compatible prototype synced, width-incompatible (`s16` param) refused, cast removed;
         force: the `s16` prototype and an extern object synced; an unprototyped cast of other arity left as
         written, not refused (plain and force); an M2C_UNK definition vs `()` prototypes and void casts left as
         written, an s32 prototype synced, s16/s8 width conflicts refused; role-tree pass: a thin unit over a role
         file (src/P/sys/r.c), the role file's prototype synced, the unit untouched.
         Ends `DECLSYNC CONTROL OK` (rc 0), else rc 1.
"""
import argparse
import glob
import os
import re
import sys

WIDTH = {"void": 0, "char": 1, "s8": 1, "u8": 1, "signed char": 1, "unsigned char": 1, "short": 2, "s16": 2,
         "u16": 2, "unsigned short": 2, "int": 4, "s32": 4, "u32": 4, "long": 4, "unsigned": 4, "unsigned int": 4,
         "unsigned long": 4, "signed": 4, "signed int": 4, "M2C_UNK": 4}  # M2C_UNK: s32 (scaffold prelude)
TYPE = r"[A-Za-z_][\w \t\*]*?"
DEF_RE = re.compile(rf"^(?:static\s+)?({TYPE})\s*\b([A-Za-z_]\w*)\s*\(([^;{{}}()]*)\)\s*\{{", re.M)
INCL_RE = re.compile(r"^#include \"([^\"]+)\"", re.M)


def width(t):
    """Byte width of a C type text (pointer 4), None when unknown."""
    t = " ".join(t.replace("*", " * ").split())
    t = re.sub(r"\b(const|volatile|extern|static|register)\b ?", "", t).strip()
    if "*" in t:
        return 4
    return WIDTH.get(t)


def ptype(p):
    """Type of one parameter text (its trailing name dropped)."""
    p = " ".join(p.replace("*", " * ").split())
    m = re.fullmatch(r"(.*?[\w\*])\s+([A-Za-z_]\w*)", p)
    if m and m.group(2) not in WIDTH and width(m.group(1)) is not None:
        return m.group(1)
    return p


def params(s):
    s = s.strip()
    return [] if s in ("", "void") else [ptype(p) for p in s.split(",")]


def norm(t):
    return " ".join(t.replace("*", " * ").split())


def sig(ret, ps):
    """(ret, [param types]) normalised."""
    return norm(ret), [norm(p) for p in params(ps)]


def compatible(a, b):
    """'' when sig b may be moved to sig a by width, else the reason."""
    (ra, pa), (rb, pb) = a, b
    if width(ra) is None or width(rb) is None or width(ra) != width(rb):
        return f"return {rb} vs {ra}"
    if len(pa) != len(pb):
        return f"{len(pb)} params vs {len(pa)}"
    for i, (x, y) in enumerate(zip(pa, pb)):
        if width(x) is None or width(y) is None or width(x) != width(y):
            return f"param {i} {y} vs {x}"
    return ""


def ret_ok(a, b):
    """'' when an unprototyped `()` declaration or cast returning b may stand for a definition returning a: return
    width only, and a `void` return (the caller discards the value) always; else the reason."""
    return "" if norm(b) == "void" else compatible((a, []), (b, []))


def definitions(text):
    """[(name, ret, params text)] of the C definitions in text."""
    return [(m.group(2), m.group(1).strip(), m.group(3).strip()) for m in DEF_RE.finditer(text)]


def unit_files(prog, start=None):
    """src/<prog>/*.c (or the files of start) plus each file they #include from src/ (relative to the including
    file), sorted."""
    out, todo = set(), sorted(start if start is not None else glob.glob(f"src/{prog}/*.c"))
    while todo:
        p = todo.pop()
        if p in out or not os.path.isfile(p):
            continue
        out.add(p)
        with open(p, errors="replace") as f:
            for rel in INCL_RE.findall(f.read()):
                q = os.path.relpath(os.path.normpath(os.path.join(os.path.dirname(p), rel)))
                if q.startswith("src" + os.sep):
                    todo.append(q)
    return sorted(out)


def header_decls(files, func):
    """[(header, line, ret, params text)] of the column-0 prototypes of func in the .h files reached from files by
    `#include "<rel>"` (relative to the includer, then include/, then src/; transitively), sorted."""
    proto = re.compile(rf"^(?:extern\s+)?({TYPE})\s*\b{re.escape(func)}\s*\(([^;{{}}()]*)\)\s*;", re.M)
    seen, todo, out = set(), list(files), []
    while todo:
        p = todo.pop()
        if p in seen or not os.path.isfile(p):
            continue
        seen.add(p)
        with open(p, errors="replace") as f:
            text = f.read()
        if p.endswith(".h"):
            out += [(p, text.count("\n", 0, m.start()) + 1, m.group(1).strip(), m.group(2).strip())
                    for m in proto.finditer(text)]
        for rel in INCL_RE.findall(text):
            for q in (os.path.join(os.path.dirname(p), rel), os.path.join("include", rel), os.path.join("src", rel)):
                q = os.path.relpath(os.path.normpath(q))
                if os.path.isfile(q):
                    todo.append(q)
                    break
    return sorted(out)


def sync_text(path, text, defs, force=False):
    """(new text, [lines], refused count) of one file against defs [(name, ret, params)]; force: no width refusal,
    and a top-level extern object declaration of name becomes the definition's prototype."""
    lines, refused = [], 0
    for name, ret, ps in defs:
        want = sig(ret, ps)
        proto = re.compile(rf"^((?:extern\s+)?)({TYPE})\s*\b{name}\s*\(([^;{{}}()]*)\)\s*;", re.M)
        cast = re.compile(rf"\(\(\s*({TYPE})\s*\(\s*\*\s*\)\s*\(([^;{{}}()]*)\)\s*\)\s*{name}\s*\)")
        obj = re.compile(rf"^extern\s+({TYPE})\s*\b{name}\s*;", re.M)

        def at(m):
            return text.count("\n", 0, m.start()) + 1

        def fix_proto(m):
            nonlocal refused
            got = sig(m.group(2), m.group(3))
            if got == want:
                return m.group(0)
            if not force and not m.group(3).strip():  # unprototyped `()`: return width only, left as written
                why = ret_ok(want[0], got[0])
                if why:
                    refused += 1
                    lines.append(f"DECLSYNC refused {path}:{at(m)} {name} {why}")
                return m.group(0)
            why = "" if force else compatible(want, got)
            if why:
                refused += 1
                lines.append(f"DECLSYNC refused {path}:{at(m)} {name} {why}")
                return m.group(0)
            lines.append(f"DECLSYNC synced {path}:{at(m)} {name}")
            return f"{m.group(1)}{ret} {name}({ps});"

        def fix_cast(m):
            nonlocal refused
            got = sig(m.group(1), m.group(2))
            if not m.group(2).strip():  # unprototyped `(*)()` (C0124): params not compared, never uncast
                why = "" if force else ret_ok(want[0], got[0])
                if why:
                    refused += 1
                    lines.append(f"DECLSYNC refused {path}:{at(m)} {name} cast {why}")
                return m.group(0)
            if not force and got[0] == "void" and want[0] != "void":  # value discarded: params compared, cast kept
                why = compatible((want[0], want[1]), (want[0], got[1]))
                if why:
                    refused += 1
                    lines.append(f"DECLSYNC refused {path}:{at(m)} {name} cast {why}")
                return m.group(0)
            why = "" if force else compatible(want, got)
            if why:
                refused += 1
                lines.append(f"DECLSYNC refused {path}:{at(m)} {name} cast {why}")
                return m.group(0)
            lines.append(f"DECLSYNC uncast {path}:{at(m)} {name}")
            return name

        def fix_obj(m):
            lines.append(f"DECLSYNC synced {path}:{at(m)} {name}")
            return f"{ret} {name}({ps});"

        text = proto.sub(fix_proto, text)
        text = cast.sub(fix_cast, text)
        if force:
            text = obj.sub(fix_obj, text)
    return text, lines, refused


KW = r"(?:return|else|case|goto|do|sizeof|typedef)\b"  # statement words TYPE would read as a type (indented forms)


def body_decl(text, name):
    """The body text's own declaration of name: ("fn", ret, params text) from its definition, else its first
    top-level prototype (params "" = unprototyped `()`), its first prototyped one when it has one (T3.c2: gcc keeps
    the prototype past a later or earlier `()` one, so that is what the unit's calls after the body see);
    ("obj", type, dims) from a top-level `extern <type> name[dims];`; else None."""
    for n, ret, ps in definitions(text):
        if n == name:
            return "fn", ret, ps
    ms = list(re.finditer(rf"^(?:extern\s+)?(?!{KW})({TYPE})\s*\b{re.escape(name)}\s*\(([^;{{}}()]*)\)\s*;", text,
                          re.M))
    m = next((x for x in ms if x.group(2).strip()), ms[0] if ms else None)
    if m:
        return "fn", m.group(1).strip(), m.group(2).strip()
    m = re.search(rf"^extern\s+({TYPE})\s*\b{re.escape(name)}\s*((?:\[[^\]]*\]\s*)*);", text, re.M)
    return ("obj", m.group(1).strip(), "".join(m.group(2).split())) if m else None


def call_args(text, i):
    """(end index after the `)`, argument count) of the call whose `(` is at text[i]; None when unbalanced."""
    depth, commas, j, quote = 0, 0, i, ""
    while j < len(text):
        c = text[j]
        if quote:
            quote = "" if c == quote and text[j - 1] != "\\" else quote
        elif c in "\"'":
            quote = c
        elif c in "([{":
            depth += 1
        elif c in ")]}":
            depth -= 1
            if depth == 0:
                return j + 1, (commas + 1 if text[i + 1:j].strip() else 0)
        elif c == "," and depth == 1:
            commas += 1
        j += 1
    return None


def unify_text(path, text, name, decl, old=None):
    """(new text, [lines], [old returns]) of one file under repair switch `declunify` (3.1 T3): each declaration of
    name (prototype or extern object, any indent) that disagrees with decl (body_decl) gets decl's spelling (an
    unprototyped `()` prototype with decl's return and width-4 params is left: compatible); when decl is a function,
    each direct call whose argument count differs from decl's prototype, or whose prevailing return type (this file's
    rewritten or kept declaration, else old: the TU's first rewritten one) differs from decl's, is called through an
    unprototyped cast `((<that return> (*)())name)(...)` (C0391, C0377). Old returns: of the rewritten prototypes."""
    n = re.escape(name)
    proto = re.compile(rf"^([ \t]*)((?:(?:extern|static)\s+)?)(?!{KW})({TYPE})\s*\b{n}\s*\(([^;{{}}()]*)\)\s*;", re.M)
    obj = re.compile(rf"^([ \t]*)extern\s+(?!{KW})({TYPE})\s*\b{n}\s*((?:\[[^\]]*\]\s*)*);", re.M)
    lines, olds, kept = [], [], []

    def at(m):
        return text.count("\n", 0, m.start()) + 1

    def fix_proto(m):
        if decl[0] != "fn":
            return m.group(0)
        got, want = sig(m.group(3), m.group(4)), sig(decl[1], decl[2])
        if got == want or (not m.group(4).strip() and got[0] == want[0] and all(width(p) == 4 for p in want[1])):
            kept.append(m.group(3))
            return m.group(0)
        olds.append(m.group(3).strip())
        lines.append(f"DECLUNIFY synced {path}:{at(m)} {name}")
        return f"{m.group(1)}{m.group(2)}{decl[1]} {name}({decl[2]});"

    def fix_obj(m):
        dims = "".join(m.group(3).split())
        if decl[0] == "obj" and norm(m.group(2)) == norm(decl[1]) and \
                re.sub(r"\[[^\]]*\]", "[]", dims) == re.sub(r"\[[^\]]*\]", "[]", decl[2]):
            return m.group(0)
        lines.append(f"DECLUNIFY synced {path}:{at(m)} {name}")
        if decl[0] == "fn":
            return f"{m.group(1)}{decl[1]} {name}({decl[2]});"
        return f"{m.group(1)}extern {decl[1]} {name}{decl[2]};"

    text = proto.sub(fix_proto, text)
    text = obj.sub(fix_obj, text)
    if decl[0] != "fn":
        return text, lines, olds
    ret = olds[0] if olds else kept[0].strip() if kept else old
    arity = len(params(decl[2])) if decl[2].strip() else None  # None: decl unprototyped, any count
    skip = [m.span() for rx in (proto, DEF_RE) for m in rx.finditer(text)]
    casts = []
    for m in re.finditer(rf"\b{n}\s*\(", text):
        s = m.start()
        bol = text.rfind("\n", 0, s) + 1
        if text[s - 1:s] == "." or text[s - 2:s] == "->" or text[bol:s].lstrip().startswith("#") \
                or any(a <= s < b for a, b in skip):
            continue
        ca = call_args(text, m.end() - 1)
        if ca is None:
            continue
        r = ret if ret is not None and norm(ret) != norm(decl[1]) else None
        if r is None and arity is not None and ca[1] != arity:
            r = ret if ret is not None else decl[1]
        if r is not None:
            casts.append((s, s + len(name), r.strip()))
    lines += [f"DECLUNIFY cast {path}:{text.count(chr(10), 0, s) + 1} {name}" for s, _, _ in casts]
    for s, e, r in reversed(casts):
        text = f"{text[:s]}(({r} (*)()){name}){text[e:]}"
    return text, lines, olds


def sync(prog, def_path, files=None, texts=None):
    """({path: new text} of changed files, [lines], refused, defs); texts {path: text} overrides the disk."""
    texts = dict(texts or {})
    if def_path not in texts:
        with open(def_path, errors="replace") as f:
            texts[def_path] = f.read()
    defs = definitions(texts[def_path])
    if not defs:
        sys.exit(f"declsync: no C definition in {def_path}")
    edits, out, refused = {}, [], 0
    for p in (files if files is not None else unit_files(prog)):
        if p not in texts:
            with open(p, errors="replace") as f:
                texts[p] = f.read()
        new, lines, r = sync_text(p, texts[p], defs)
        out += lines
        refused += r
        if new != texts[p]:
            edits[p] = new
    return edits, out, refused, defs


def summary(defs, lines, refused, edits):
    n = lambda k: sum(1 for l in lines if l.split()[1] == k)  # noqa: E731
    return (f"DECLSYNC {','.join(d[0] for d in defs)} synced {n('synced')} uncast {n('uncast')} refused {refused} "
            f"files {len(edits)}")


def self_test():
    body = "src/shared/_t/body.c"
    texts = {body: '#include "common.h"\n\nvoid func_T(s8* arg0, s32 arg1) {\n    func_U(arg0);\n}\n',
             "src/P/a.c": "void func_T(s32, u32);\nvoid f(void) {\n    ((void (*)(s32, s32))func_T)(0, 1);\n}\n",
             "src/P/b.c": "extern void func_T(s8*, s16);\n"}
    fails = []

    def ok(cond, what):
        if not cond:
            fails.append(what)
        print(f"self-test {'ok' if cond else 'FAIL'}: {what}")

    edits, lines, refused, _ = sync("P", body, files=["src/P/a.c"], texts=texts)
    a = edits.get("src/P/a.c", "")
    ok("void func_T(s8* arg0, s32 arg1);" in a and "DECLSYNC synced src/P/a.c:1 func_T" in lines,
       "width-compatible prototype synced")
    ok("    func_T(0, 1);" in a and any(l.startswith("DECLSYNC uncast src/P/a.c:3") for l in lines), "cast removed")
    ok(refused == 0, "no refusal on the compatible file")
    edits, lines, refused, _ = sync("P", body, files=["src/P/b.c"], texts=texts)
    ok(refused == 1 and not edits and any("refused src/P/b.c:1 func_T param 1 s16" in l for l in lines),
       "width-incompatible (s16 param) refused")
    b, lines, refused = sync_text("src/P/b.c", texts["src/P/b.c"] + "extern M2C_UNK func_T;\n",
                                  definitions(texts[body]), force=True)
    ok(refused == 0 and b == "extern void func_T(s8* arg0, s32 arg1);\nvoid func_T(s8* arg0, s32 arg1);\n"
       and len(lines) == 2, "force: s16 prototype and extern object synced")
    u = "void f(void) {\n    ((void (*)())func_T)(0);\n}\n"
    for force in (False, True):
        t, lines, refused = sync_text("src/P/c.c", u, definitions(texts[body]), force=force)
        ok(t == u and refused == 0 and not lines, f"unprototyped cast of other arity left as written (force={force})")
    dv = definitions("M2C_UNK func_V(void* arg0) {\n}\n")
    u = ("M2C_UNK func_V();\ns32 func_V();\nvoid g(void) {\n    ((void (*)())func_V)();\n"
         "    ((void (*)(void*))func_V)(0);\n}\n")
    t, lines, refused = sync_text("src/P/d.c", u, dv)
    ok(t == u and refused == 0 and not lines, "M2C_UNK def: `()` decls and void casts left as written, not refused")
    t, lines, refused = sync_text("src/P/d.c", "s32 func_V(u32);\n", dv)
    ok(t == "M2C_UNK func_V(void* arg0);\n" and refused == 0, "M2C_UNK width 4: s32 prototype synced")
    for bad, why in (("s16 func_V();\n", "return s16 vs M2C_UNK"), ("((void (*)(s16))func_V)(0);\n", "param 0 s16"),
                     ("((s8 (*)())func_V)();\n", "return s8 vs M2C_UNK")):
        t, lines, refused = sync_text("src/P/d.c", bad, dv)
        ok(t == bad and refused == 1 and why in lines[0], f"real width conflict refused: {why}")
    # role-tree pass (T5, in memory): a thin unit `#include "sys/r.c"` over a role file holding the prototype
    rt = {body: texts[body], "src/P/u.c": '#include "sys/r.c"\n', "src/P/sys/r.c": "void func_T(s32, u32);\n"}
    edits, lines, refused, _ = sync("P", body, files=["src/P/u.c", "src/P/sys/r.c"], texts=rt)
    ok(edits == {"src/P/sys/r.c": "void func_T(s8* arg0, s32 arg1);\n"} and refused == 0,
       "role-tree pass: the role file's prototype synced, the thin unit untouched")
    if fails:
        print(f"DECLSYNC SELF-TEST FAIL {len(fails)}")
        return 1
    print("DECLSYNC CONTROL OK")
    return 0


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n", 1)[0])
    ap.add_argument("--prog")
    ap.add_argument("--def", dest="defn")
    ap.add_argument("--dry-run", action="store_true")
    ap.add_argument("--self-test", action="store_true")
    a = ap.parse_args()
    if a.self_test:
        return self_test()
    if not (a.prog and a.defn):
        ap.error("need --prog <p> --def <body.c>, or --self-test")
    edits, lines, refused, defs = sync(a.prog, a.defn)
    for l in lines:
        print(l)
    if not refused and not a.dry_run:
        for p, t in edits.items():
            with open(p, "w") as f:
                f.write(t)
    print(summary(defs, lines, refused, edits))
    return 1 if refused else 0


if __name__ == "__main__":
    sys.exit(main())
