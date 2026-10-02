#!/usr/bin/env python3
"""permute.py -- decomp-permuter on one stored draft, scored by the masked scorer (container).

  permute.py --draft drafts/<prog>/<func>.c --iterations N --seed S
      -> `PERMUTE <func> iterations <n> distinct <d> base <b> best <s>`; best candidate .run/permute/<func>/best.c;
         a score-0 best adds `PERMUTE CANDIDATE <func> score 0 <path> (not banked)`; rc 0 iff it iterated (n >= 1)
  permute.py --self-test
      -> planted controls in .run/permute/ (xor operand swap must reach masked 0; stock contrast
         `PERMUTE STOCK <n>`; register-pin hide/restore; K&R refusal; upstream clean); last line `PERMUTE CONTROL OK`

One cycle: .run/permute/<func>/ gets base.c (the draft through the cpp stage of the C rule's dry-run recipe for the
draft, `make -n`: the Makefile's CPPFLAGS, never a copied list, plus -P), cflags (probe.draft_cflags: the draft TU's
cc1 flags, CFLAGS_<tu> override included, which compile.sh passes as CFLAGS_cand; absent outside a C TU), target.o (retail words from
probe.retail_words as `.word` data, symbol <func>), compile.sh (tools/mmx6/permuter/compile.sh: the product C rule),
settings.toml, mmx6.json {func, vram}; then `masked_scorer.py <permdir> -j1 --seed S` runs as a subprocess.
Its stdout (permuter.log) is split on \\r and \\n; `iteration N, ...` lines are counted and the child is killed by
pid once N >= --iterations. distinct = unique input hashes in sources.log (compile.sh); base = the permuter's
`base score = <b>`; best = min over output-<score>-<k>/ (base when none), its source copied to best.c.
DK-15 guards: a K&R definition of <func> is refused (`PERMUTE REFUSED K&R <func>`, rc 1); `register ... __asm__(...)`
pins are hidden from the randomizer as PERM_IGNORE(...) (compiled verbatim, never permuted) and base.c is restored
byte-exact after the cycle (asserted); a refused or zero-iteration cycle is rc 1. A score-0 candidate is printed,
never banked: this tool never writes src/ and never calls bank.py (C0062; only bank.py banks, G61).
Firewall G12: retail words only in .run/; prints counts and scores only.
"""
import argparse
import hashlib
import json
import os
import re
import shutil
import signal
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
sys.path.insert(0, os.path.join(ROOT, "tools", "mmx6"))
sys.path.insert(0, os.path.join(ROOT, "tools", "mmx6", "permuter"))
import dumps  # noqa: E402
import probe  # noqa: E402
import masked_scorer  # noqa: E402

RUN = ".run/permute"
COMPILE_SH = "tools/mmx6/permuter/compile.sh"
SCORER = "tools/mmx6/permuter/masked_scorer.py"
AS = ["mipsel-linux-gnu-as", "-EL", "-march=r3000", "-mabi=32", "-G0"]
ITER_RE = re.compile(rb"iteration (\d+),")
BASE_RE = re.compile(rb"base score = (\d+)")
PIN_RE = re.compile(r'\bregister\b[^;{}()]*(?:__asm__|__asm|asm)\s*\(\s*"[^"]*"\s*\)[^;{}]*;')
DRAFT_RE = re.compile(r"(?:^|/)drafts/([^/]+)/([A-Za-z_]\w*)\.c$")
# Self-test plants (our own C; targets are their own compiles, nothing game-derived).
FAKE_ADDR, FAKE_VRAM = 0x80123458, 0x80010000
XOR_A = "extern int g;\nint xorplant(int a) { return a ^ g; }\n"
XOR_B = "extern int g;\nint xorplant(int a) { return g ^ a; }\n"  # 2.95.2: xor v0,v0,a0 vs xor v0,a0,v0
PIN_SRC = 'extern int g;\nint pinplant(int a) {\n    register int x __asm__("$16");\n    x = a ^ g;\n    return x;\n}\n'
KR_SRC = "extern int g;\nint krplant(a)\nint a;\n{\n    return a ^ g;\n}\n"
SELFTEST_SEED, SELFTEST_CAP = 7, 400


def is_kr(text, func):
    """True when func's definition is K&R (identifier-only parameter list, or declarations before the body)."""
    for m in re.finditer(rf"^[A-Za-z_][^;{{}}()]*\b{func}\s*\(([^()]*)\)\s*(\S)", text, re.M):
        params, nxt = m.group(1).strip(), m.group(2)
        if nxt == ";":
            continue
        if nxt != "{":
            return True
        parts = [p.strip() for p in params.split(",")]
        return bool(params) and params != "void" and all(re.fullmatch(r"[A-Za-z_]\w*", p) for p in parts)
    return False


def hide_pins(text):
    pins = PIN_RE.findall(text)
    return PIN_RE.sub(lambda m: f"PERM_IGNORE({m.group(0)})", text), pins


def restore_pins(text, pins):
    for p in pins:
        text = text.replace(f"PERM_IGNORE({p})", p, 1)
    return text


def cpp_argv(src):
    """The C rule's cpp stage for src (make dry run, so the Makefile's CPPFLAGS), input dropped, plus -P."""
    stage = dumps.recipe(src)[0]
    if stage[-1] != src:
        raise RuntimeError(f"cpp stage of {src} does not end in its input: {stage[-1]}")
    return stage[:1] + ["-P"] + stage[1:-1]


def write_target(permdir, func, words):
    s = os.path.join(permdir, "target.s")
    with open(s, "w") as f:
        f.write(f".set noreorder\n.section .text\n.globl {func}\n.type {func}, @function\n{func}:\n")
        f.writelines(f".word 0x{w:08X}\n" for w in words)
        f.write(f".size {func}, . - {func}\n")
    subprocess.run(AS + ["-o", os.path.join(permdir, "target.o"), s], check=True)


def compile_c(workdir, name, text):
    """Compile text through compile.sh in workdir; the .o path, or None."""
    os.makedirs(workdir, exist_ok=True)
    shutil.copyfile(COMPILE_SH, os.path.join(workdir, "compile.sh"))
    c, o = os.path.join(workdir, name + ".c"), os.path.join(workdir, name + ".o")
    with open(c, "w") as f:
        f.write(text)
    rc = subprocess.run(["bash", os.path.join(workdir, "compile.sh"), c, "-o", o]).returncode
    return o if rc == 0 else None


def cycle(func, draft, words, vram, iterations, seed, stop_on_zero=False):
    """One permuter cycle on draft (a .c path). Returns a dict (rc, n, d, b, s, best, pins, restored, refused)."""
    res = {"rc": 1, "n": 0, "d": 0, "b": None, "s": None, "best": None, "pins": [], "restored": False,
           "refused": False}
    with open(draft) as f:
        if is_kr(f.read(), func):
            print(f"PERMUTE REFUSED K&R {func}", flush=True)
            res["refused"] = True
            return res
    permdir = os.path.join(RUN, func)
    shutil.rmtree(permdir, ignore_errors=True)
    os.makedirs(os.path.join(permdir, "tmp"))
    shutil.copyfile(COMPILE_SH, os.path.join(permdir, "compile.sh"))
    with open(os.path.join(permdir, "settings.toml"), "w") as f:
        f.write(f'func_name = "{func}"\ncompiler_type = "gcc"\n')
    with open(os.path.join(permdir, "mmx6.json"), "w") as f:
        json.dump({"func": func, "vram": f"0x{vram:08X}"}, f)
    write_target(permdir, func, words)
    cflags = probe.draft_cflags(draft)
    if cflags:
        with open(os.path.join(permdir, "cflags"), "w") as f:
            f.write(" ".join(cflags))
        print(f"PERMUTE CFLAGS {func} {' '.join(cflags)}", flush=True)
    base = subprocess.run(cpp_argv(draft) + [draft], check=True, capture_output=True, text=True).stdout
    if is_kr(base, func):
        print(f"PERMUTE REFUSED K&R {func}", flush=True)
        res["refused"] = True
        return res
    hidden, res["pins"] = hide_pins(base)
    base_c = os.path.join(permdir, "base.c")
    with open(base_c, "w") as f:
        f.write(hidden)
    cmd = [sys.executable, SCORER, permdir, "-j1", "--seed", str(seed)] + (["--stop-on-zero"] if stop_on_zero else [])
    env = dict(os.environ, PYTHONUNBUFFERED="1", TMPDIR=os.path.abspath(os.path.join(permdir, "tmp")))
    n, b, buf = 0, None, b""
    with open(os.path.join(permdir, "permuter.log"), "wb") as log:
        child = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, env=env)
        while True:
            chunk = os.read(child.stdout.fileno(), 65536)
            if not chunk:
                break
            log.write(chunk)
            buf += chunk
            *lines, buf = re.split(rb"[\r\n]", buf)
            for line in lines:
                m = ITER_RE.search(line) or BASE_RE.search(line)
                if m and m.re is ITER_RE:
                    n = max(n, int(m.group(1)))
                elif m:
                    b = int(m.group(1))
            if n >= iterations:
                os.kill(child.pid, signal.SIGKILL)
                break
        child.wait()
    # Restore base.c (DK-15): unwrap the hidden pins; must equal the pre-hide text byte for byte.
    with open(base_c) as f:
        restored = restore_pins(f.read(), res["pins"])
    with open(base_c, "w") as f:
        f.write(restored)
    with open(base_c) as f:
        res["restored"] = f.read() == base
    outs = []
    for name in os.listdir(permdir):
        m = re.fullmatch(r"output-(\d+)-(\d+)", name)
        if m:
            outs.append((int(m.group(1)), int(m.group(2)), name))
    best_c = os.path.join(permdir, "best.c")
    if outs and (b is None or min(outs)[0] <= b):
        s, _, name = min(outs)
        shutil.copyfile(os.path.join(permdir, name, "source.c"), best_c)
    else:
        s = b
        with open(best_c, "w") as f:
            f.write(base)
    with open(os.path.join(permdir, "sources.log")) as f:
        d = len(set(f.read().split()))
    res.update(n=n, d=d, b=b, s=s, best=best_c)
    print(f"PERMUTE {func} iterations {n} distinct {d} base {b} best {s}", flush=True)
    if s == 0:
        print(f"PERMUTE CANDIDATE {func} score 0 {best_c} (not banked)", flush=True)
    res["rc"] = 0 if n >= 1 and b is not None and res["restored"] else 1
    return res


def fake_fill(o, func):
    """Words of func in o with HI16/LO16 fields filled with FAKE_ADDR (a retail-like target)."""
    words, _ = probe.elf_function(o, func)
    hi, lo = ((FAKE_ADDR + 0x8000) >> 16) & 0xFFFF, FAKE_ADDR & 0xFFFF
    for i, typ, _, _ in masked_scorer.relocs(o, func):
        if typ == masked_scorer.R_MIPS_HI16:
            words[i] = (words[i] & 0xFFFF0000) | hi
        elif typ == masked_scorer.R_MIPS_LO16:
            words[i] = (words[i] & 0xFFFF0000) | lo
    return words


def self_test():
    ok = True

    def check(cond, what):
        nonlocal ok
        if not cond:
            print(f"PERMUTE SELFTEST FAIL {what}", flush=True)
            ok = False
        return cond

    src = os.path.join(RUN, "selftest-src")
    shutil.rmtree(src, ignore_errors=True)
    # 1. xor plant: target = operand-swapped compile with a fixed fake address; base must start masked > 0.
    a_o, b_o = compile_c(src, "xor_a", XOR_A), compile_c(src, "xor_b", XOR_B)
    if not check(a_o and b_o, "plant compile"):
        return 1
    target = fake_fill(b_o, "xorplant")
    a_words = probe.elf_function(a_o, "xorplant")[0]
    base_score, _ = masked_scorer.score_words(a_o, "xorplant", target, FAKE_VRAM)
    print(f"PERMUTE PLANT xorplant base masked {base_score}", flush=True)
    check(base_score > 0, "precondition base masked score > 0")
    check(hashlib.sha256(repr(a_words).encode()).digest() != hashlib.sha256(repr(target).encode()).digest(),
          "precondition base vs target hashes differ")
    r = cycle("xorplant", os.path.join(src, "xor_a.c"), target, FAKE_VRAM, SELFTEST_CAP, SELFTEST_SEED, True)
    check(r["rc"] == 0 and r["b"] == base_score and r["s"] == 0, "xor plant reaches masked 0")
    # 2. Stock contrast: upstream's own scorer on that 0-candidate against target.o.
    with open(r["best"]) as f:
        best_o = compile_c(src, "xor_best", f.read())
    if check(best_o, "best.c compiles"):
        out = subprocess.run([sys.executable, SCORER, "--stock", os.path.join(RUN, "xorplant", "target.o"), best_o],
                             capture_output=True, text=True, env=dict(os.environ, TMPDIR=os.path.abspath(src)))
        stock = int(out.stdout.split()[-1]) if out.returncode == 0 and out.stdout.split() else -1
        print(f"PERMUTE STOCK {stock}", flush=True)
        check(stock > 0, "stock scorer nonzero on the masked-0 candidate")
    # 3. Pinned seed, target = its own unhidden compile: base 0 proves the hidden (PERM_IGNORE) pin still compiled;
    # base.c restored byte-exact; best.c carries the pin.
    pin_o = compile_c(src, "pin", PIN_SRC)
    if check(pin_o, "pin plant compile"):
        r = cycle("pinplant", os.path.join(src, "pin.c"), fake_fill(pin_o, "pinplant"), FAKE_VRAM, 5, SELFTEST_SEED)
        with open(r["best"]) as f:
            best = f.read()
        check(r["rc"] == 0 and len(r["pins"]) == 1 and r["restored"], "pin hidden, cycle iterated, restored exact")
        check(r["b"] == 0, "hidden pin compiled (base masked 0 vs the pinned target)")
        check(all(p in best for p in r["pins"]), "best.c carries the pin")
        print(f"PERMUTE PIN pinplant hidden {len(r['pins'])} restored {r['restored']}", flush=True)
    # 4. K&R seed: refused, rc != 0.
    with open(os.path.join(src, "kr.c"), "w") as f:
        f.write(KR_SRC)
    r = cycle("krplant", os.path.join(src, "kr.c"), target, FAKE_VRAM, 5, SELFTEST_SEED)
    check(r["refused"] and r["rc"] != 0, "K&R seed refused")
    # 5. Upstream untouched.
    st = subprocess.run(["git", "-C", masked_scorer.UPSTREAM, "status", "--porcelain"], capture_output=True, text=True)
    check(st.returncode == 0 and st.stdout == "", "upstream clean")
    print("PERMUTE CONTROL OK" if ok else "PERMUTE CONTROL FAIL", flush=True)
    return 0 if ok else 1


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n", 1)[0])
    ap.add_argument("--draft")
    ap.add_argument("--iterations", type=int, default=100)
    ap.add_argument("--seed", type=int, default=1)
    ap.add_argument("--self-test", action="store_true")
    a = ap.parse_args()
    os.chdir(ROOT)
    if a.self_test:
        return self_test()
    m = DRAFT_RE.search(a.draft or "")
    if not m:
        ap.error("need --draft drafts/<prog>/<func>.c, or --self-test")
    if a.seed == 0 or a.iterations < 1:
        ap.error("--seed must be nonzero (upstream treats 0 as unseeded) and --iterations >= 1")
    prog, func = m.groups()
    vram = probe.find_extent(prog, func)[0]
    return cycle(func, a.draft, probe.retail_words(prog, func), vram, a.iterations, a.seed)["rc"]


if __name__ == "__main__":
    sys.exit(main())
