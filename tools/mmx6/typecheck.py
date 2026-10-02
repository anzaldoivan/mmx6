#!/usr/bin/env python3
"""typecheck.py -- one home for types: every typedef/struct keyed by shape (stdlib, text only, no build needed).

  typecheck.py --all
      -> scans include/**/*.h and src/**/*.{c,h}; refusal lines, then last line
         `TYPES <d> definitions <s> shapes of <f> files; duplicates <n>; raw casts <m>`; rc 0 iff no refusal.
  typecheck.py --files <paths>
      -> as --all over those files plus include/mmx6/*.h (the canonical baseline).
  typecheck.py --self-test
      -> in memory ({path: text} over the real files + planted texts, no disk writes): real set passes; planted dup
         (Probe800473EC's shape, new name, include/mmx6/), raw cast (src/SLUS_013.95/), outside (struct in src/),
         unkeyable (fn-pointer typedef) each alone rc 1 with the right reason. Ends `TYPES CONTROL OK`.

Refusals: `TYPES REFUSE <dup|outside|raw-cast|unkeyable> <path>:<line> <name/text>`.
  dup       a definition whose shape (or name) an earlier one already has (include/mmx6/ is read first).
  outside   a definition in a file not under include/mmx6/.
include/mmx6/x4.h (x4port.py's generated X4_ mirror of mmx4 types, its own namespace) is read and counted, never
refused, and its shapes are not registered (an X4_ type may share a shape with ours).
  raw-cast  `*(T *)0x...` (any spacing, any pointer depth) in comment-stripped src/<prog>/ text.
  unkeyable a definition the parser cannot key (unknown member type, fn pointer, bitfield, inline nested struct...);
            refused with the reason, never skipped.
Shape key: scalar typedef = (width, signed); struct = (size, ((offset, width) per member)), PSX MIPS natural
alignment (1/2/4, pointer 4, array = elem x count, hex/dec counts, known types resolved; struct align = max member
align, size padded); union = members at offset 0. `extern` declarations and prototypes are not definitions.
"""
import argparse
import glob
import os
import re
import sys

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), "..", ".."))
HOME = "include/mmx6/"
X4H = HOME + "x4.h"
QUALIFIERS = {"const", "volatile", "register", "static", "extern"}
SCALAR_WORDS = {"unsigned", "signed", "char", "short", "int", "long", "float", "double"}
TOKEN = re.compile(r"\[[^\]]*\]|\w+|\S")
DEF_START = re.compile(r"\btypedef\b|\b(?:struct|union)\b(?:\s+\w+)?\s*\{")
RAW_CAST = re.compile(r"\*\s*\(\s*[A-Za-z_]\w*(?:\s+[A-Za-z_]\w*)*\s*(?:\*\s*)+\)\s*0[xX][0-9A-Fa-f]+")


class Unkeyable(Exception):
    pass


def strip(text):
    """Comments -> spaces (newlines kept), strings kept; then preprocessor lines (with continuations) blanked."""
    out, i, n = [], 0, len(text)
    while i < n:
        c = text[i]
        if text.startswith("/*", i):
            j = text.find("*/", i + 2)
            j = n if j < 0 else j + 2
            out.append(re.sub(r"[^\n]", " ", text[i:j]))
            i = j
        elif text.startswith("//", i):
            j = text.find("\n", i)
            j = n if j < 0 else j
            out.append(" " * (j - i))
            i = j
        elif c in "\"'":
            j = i + 1
            while j < n and text[j] != c and text[j] != "\n":
                j += 2 if text[j] == "\\" else 1
            out.append(text[i:j + 1])
            i = j + 1
        else:
            out.append(c)
            i += 1
    lines, cont = "".join(out).split("\n"), False
    for k, line in enumerate(lines):
        if cont or line.lstrip().startswith("#"):
            cont = line.rstrip().endswith("\\")
            lines[k] = ""
    return "\n".join(lines)


def scalar(words):
    ws = [w for w in words if w not in ("signed", "unsigned")]
    if ws in (["float"], ["double"]):
        return ("float", 4 if ws == ["float"] else 8)
    width = {(): 4, ("int",): 4, ("char",): 1, ("short",): 2, ("short", "int"): 2, ("long",): 4,
             ("long", "int"): 4, ("long", "long"): 8, ("long", "long", "int"): 8}.get(tuple(ws))
    if width is None:
        raise Unkeyable("scalar " + " ".join(words))
    return ("scalar", width, "unsigned" not in words)


def count(dim):
    s = dim[1:-1].strip()
    if not re.fullmatch(r"0[xX][0-9A-Fa-f]+|\d+", s):
        raise Unkeyable("array count " + dim)
    return int(s, 0)


def parse_decl(toks, known, need_base=True):
    """toks of one declaration -> (base, [(name, ptr_depth, dims)]); base = (key, size, align) or None."""
    i = 0
    while i < len(toks) and toks[i] in QUALIFIERS:
        i += 1
    if i < len(toks) and toks[i] in ("struct", "union"):
        name, i = toks[i] + " " + (toks[i + 1] if i + 1 < len(toks) else ""), i + 2
    elif i < len(toks) and toks[i] in SCALAR_WORDS:
        j = i
        while j < len(toks) and toks[j] in SCALAR_WORDS:
            j += 1
        name, i = " ".join(toks[i:j]), j
    elif i < len(toks) and re.fullmatch(r"[A-Za-z_]\w*", toks[i]):
        name, i = toks[i], i + 1
    else:
        raise Unkeyable("no type in '%s'" % " ".join(toks))
    if name in known:
        base = known[name]
    elif re.fullmatch(r"[A-Za-z_\s]+", name) and set(name.split()) <= SCALAR_WORDS:
        key = scalar(name.split())
        base = (key, key[1], min(key[1], 4))
    else:
        base = None
    decls, cur = [], []
    for t in toks[i:] + [","]:
        if t != ",":
            cur.append(t)
            continue
        while cur and cur[0] in QUALIFIERS:
            cur.pop(0)
        depth = 0
        while cur and cur[0] == "*":
            depth, cur = depth + 1, cur[1:]
            while cur and cur[0] in QUALIFIERS:
                cur.pop(0)
        if not cur or not re.fullmatch(r"[A-Za-z_]\w*", cur[0]):
            raise Unkeyable("declarator '%s'" % " ".join(cur) if cur else "no declarator")
        bad = [x for x in cur[1:] if not x.startswith("[")]
        if bad:
            raise Unkeyable(("bitfield" if ":" in bad else "function pointer or unparsed")
                            + " '%s'" % " ".join(cur))
        decls.append((cur[0], depth, [count(d) for d in cur[1:]]))
        cur = []
    if base is None and (need_base or any(d[1] == 0 for d in decls)):
        raise Unkeyable("unknown type " + name)
    return base, name, decls


def member_layout(base, depth, dims):
    size, align = (4, 4) if depth else (base[1], base[2])
    for d in dims:
        size *= d
    return size, align


def struct_key(kind, body, known):
    members, off, align = [], 0, 1
    for decl in split_top(body, ";"):
        toks = TOKEN.findall(decl)
        if not toks:
            continue
        if "{" in toks:
            raise Unkeyable("inline nested struct/union")
        base, _, decls = parse_decl(toks, known, need_base=False)
        for _, depth, dims in decls:
            size, a = member_layout(base, depth, dims)
            align = max(align, a)
            if kind == "struct":
                off = (off + a - 1) // a * a
                members.append((off, size))
                off += size
            else:
                members.append((0, size))
                off = max(off, size)
    if not members:
        raise Unkeyable("empty body")
    size = (off + align - 1) // align * align
    return (kind, size, tuple(members)), size, align


def split_top(text, sep):
    parts, depth, cur = [], 0, []
    for c in text:
        depth += (c in "{(") - (c in "})")
        if c == sep and depth == 0:
            parts.append("".join(cur))
            cur = []
        else:
            cur.append(c)
    parts.append("".join(cur))
    return parts


def match_brace(text, i):
    depth = 0
    for j in range(i, len(text)):
        depth += (text[j] == "{") - (text[j] == "}")
        if depth == 0:
            return j
    return len(text) - 1


def defs_of(text, known):
    """Yield (offset, name, key|None, reason|None) for each definition in stripped text; updates known."""
    pos = 0
    while True:
        m = DEF_START.search(text, pos)
        if not m:
            return
        start, is_td = m.start(), m.group(0) == "typedef"
        brace = text.find("{", start) if not is_td else -1
        if is_td:
            semi = text.find(";", start)
            ob = text.find("{", start)
            if 0 <= ob < (semi if semi >= 0 else len(text)):
                brace = ob
        end = match_brace(text, brace) if brace >= 0 else start
        semi = text.find(";", end)
        semi = len(text) if semi < 0 else semi
        pos, name = semi + 1, "?"
        try:
            if brace >= 0:
                head = TOKEN.findall(text[start:brace])
                head = head[1:] if is_td else head
                if not head or head[0] not in ("struct", "union") or len(head) > 2:
                    raise Unkeyable("head '%s'" % " ".join(head))
                kind, tag = head[0], (head[1] if len(head) == 2 else None)
                tail = TOKEN.findall(text[end + 1:semi])
                if is_td and (len(tail) != 1 or not re.fullmatch(r"[A-Za-z_]\w*", tail[0])):
                    raise Unkeyable("typedef declarators '%s'" % " ".join(tail))
                name = tail[0] if is_td else "%s %s" % (kind, tag or "<anon>")
                ent = struct_key(kind, text[brace + 1:end], known)
                if tag:
                    known["%s %s" % (kind, tag)] = ent
            else:
                toks = TOKEN.findall(text[start:semi])[1:]
                fp = re.search(r"\(\s*\*+\s*(\w+)", text[start:semi])
                name = fp.group(1) if fp else next((t for t in reversed(toks) if re.fullmatch(r"\w+", t)), "?")
                base, bname, decls = parse_decl(toks, known, need_base=False)
                if len(decls) != 1:
                    raise Unkeyable("typedef declarators")
                name, depth, dims = decls[0]
                if depth:
                    ent = (("ptr", depth, base[0] if base else bname), 4, 4)
                elif dims:
                    size, a = member_layout(base, 0, dims)
                    ent = (("array", base[0], tuple(dims)), size, a)
                else:
                    ent = base
            yield start, name, ent[0], None
            known.setdefault(name, ent)
        except Unkeyable as e:
            yield start, name, None, str(e)


def check(files):
    """files: {relpath: text} -> (refusal lines, d, s, f)."""
    order = sorted(files, key=lambda p: (not p.startswith(HOME), p))
    known, shapes, names, refusals, d, ndup, nraw = {}, {}, {}, [], 0, 0, 0
    for path in order:
        text = strip(files[path])
        line = lambda off: text.count("\n", 0, off) + 1
        for off, name, key, reason in defs_of(text, known):
            d += 1
            if path == X4H:
                continue
            where = "%s:%d" % (path, line(off))
            if reason:
                refusals.append("TYPES REFUSE unkeyable %s %s (%s)" % (where, name, reason))
            elif key in shapes or name in names:
                ndup += 1
                first = shapes.get(key) or names[name]
                refusals.append("TYPES REFUSE dup %s %s (shape of %s at %s)" % (where, name, first[0], first[1]))
            else:
                shapes[key] = names[name] = (name, where)
            if not path.startswith(HOME):
                refusals.append("TYPES REFUSE outside %s %s" % (where, name))
        parts = path.split("/")
        if len(parts) >= 3 and parts[0] == "src":
            for m in RAW_CAST.finditer(text):
                nraw += 1
                refusals.append("TYPES REFUSE raw-cast %s:%d %s" % (path, line(m.start()), " ".join(m.group(0).split())))
    summary = "TYPES %d definitions %d shapes of %d files; duplicates %d; raw casts %d" % (
        d, len(shapes), len(files), ndup, nraw)
    return refusals, summary, d, len(shapes)


def read(paths):
    return {p: open(os.path.join(ROOT, p), encoding="utf-8").read() for p in paths}


def all_paths():
    pats = ["include/**/*.h", "src/**/*.c", "src/**/*.h"]
    found = {os.path.relpath(p, ROOT).replace(os.sep, "/")
             for pat in pats for p in glob.glob(os.path.join(ROOT, pat), recursive=True)}
    return sorted(found)


def home_paths():
    return [os.path.relpath(p, ROOT).replace(os.sep, "/") for p in sorted(glob.glob(os.path.join(ROOT, HOME, "*.h")))]


def report(files):
    refusals, summary, _, _ = check(files)
    for r in refusals:
        print(r)
    print(summary)
    return 1 if refusals else 0


def self_test():
    real = read(all_paths())
    refusals, summary, _, _ = check(real)
    assert not refusals, (refusals, summary)
    _, summary, d, s = check({p: t for p, t in real.items() if p != X4H})  # ours only: x4.h's X4_ types are counted
    assert d == s == 7, summary  # but not ours (T7.c3: x4.h tracked)
    known = {}
    probe = [k for _, n, k, _ in defs_of(strip(real[HOME + "types.h"]), known) if n == "Probe800473EC"]
    assert probe == [("struct", 0x20, ((0, 5), (5, 1), (6, 14), (0x14, 2), (0x16, 2), (0x18, 4), (0x1C, 4)))], probe
    controls = {
        "dup": (HOME + "zplanted.h", "typedef struct {\n u8 a[5]; u8 b; u8 c[0xE];\n s16 d; s16 e; s32 f; s32 g;\n} "
                "PlantedTwin;\n"),
        "raw-cast": ("src/SLUS_013.95/planted.c", "void f(void) {\n    * ( volatile u32 ** ) 0x80001000 = 0;\n}\n"),
        "outside": ("src/SLUS_013.95/planted.c", "/* typedef struct { int x; } Commented; */\n"
                    "struct PlantedOut {\n    s32 a;\n    u8 b;\n};\nextern struct PlantedOut g;\n"),
        "unkeyable": (HOME + "zplanted.h", "typedef void (*PlantedFn)(s32);\n"),
    }
    for reason, (path, text) in controls.items():
        files = dict(real)
        files[path] = text
        refusals, summary, _, _ = check(files)
        kinds = {r.split()[2] for r in refusals}
        assert refusals and kinds == {reason} and all(path in r for r in refusals), (reason, refusals)
        print("control %s: %s" % (reason, refusals[0]))
    print("TYPES CONTROL OK")
    return 0


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    g = ap.add_mutually_exclusive_group(required=True)
    g.add_argument("--all", action="store_true")
    g.add_argument("--self-test", action="store_true")
    g.add_argument("--files", nargs="+")
    a = ap.parse_args()
    if a.self_test:
        return self_test()
    if a.all:
        return report(read(all_paths()))
    paths = {os.path.relpath(os.path.abspath(p), ROOT).replace(os.sep, "/") for p in a.files}
    return report(read(sorted(paths | set(home_paths()))))


if __name__ == "__main__":
    sys.exit(main())
