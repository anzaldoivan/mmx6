#!/usr/bin/env python3
"""splat_closure.py -- `splat` with each C unit's #include closure scanned (container python3, splat 0.50.0).

    splat_closure.py split config/<bin>.yaml        (the Makefile split rule; same arguments as `splat`)
    splat_closure.py --self-test

splat decides which asm/<bin>/nonmatchings/<tu>/<func>.s files to write, and which names its C units define, by
regex-scanning only the unit file src/<bin>/<tu>.c (segtypes/common/c.py CommonSegC.get_global_asm_funcs,
get_global_asm_rodata_syms, get_funcs_defined_in_c). Under scheme L-B (docs/layout.md) a unit is a thin list of
`#include "<role>.c"` lines, so its INCLUDE_ASM lines sit in role files. This launcher replaces those three scanners
with ones that read the unit's #include closure (the unit, then every `#include "*.c"` it reaches, resolved as
layout.py includers: relative to the including file, `src/...` from the repo root), then runs splat's own main.
Old flat units and L-B units get the same answer; splat's parsing of the text is unchanged (GCC INCLUDE_ASM form, the
project compiler; not IDO GLOBAL_ASM) (2.4 T15.c1).
"""
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import layout  # noqa: E402  (parse/norm: the one #include walker)


def closure(c_file, root=layout.ROOT):
    """Repo-relative paths of c_file's #include "*.c" closure, c_file first, depth-first in textual order."""
    tree = layout.Tree(root)
    start = os.path.relpath(os.path.abspath(str(c_file)), root).replace(os.sep, "/")
    out, seen, todo = [], set(), [start]
    while todo:
        r = todo.pop()
        if r in seen or not tree.exists(r):
            continue
        seen.add(r)
        out.append(r)
        incs = [e.target for e in layout.parse(tree.lines(r)) if e.kind == "inc"]
        todo.extend(reversed([t if t.startswith("src/") else layout.norm(r, t) for t in incs]))
    return out


def closure_text(c_file, root=layout.ROOT):
    parts = []
    for r in closure(c_file, root):
        with open(os.path.join(root, r), encoding="utf-8") as f:
            parts.append(f.read())
    return "\n".join(parts)


def patch():
    from splat.segtypes.common import c as segc

    seg = segc.CommonSegC

    def text(c_file):
        return seg.strip_c_comments(closure_text(c_file))

    def defined(c_file):
        return {m.group(1) for m in segc.C_FUNC_RE.finditer(text(c_file))}

    def asm_funcs(c_file):
        return set(seg.find_include_asm(text(c_file)))

    def asm_rodata(c_file):
        return set(seg.find_include_rodata(text(c_file)))

    seg.get_funcs_defined_in_c = staticmethod(defined)
    seg.get_global_asm_funcs = staticmethod(asm_funcs)
    seg.get_global_asm_rodata_syms = staticmethod(asm_rodata)


def self_test():
    import tempfile

    with tempfile.TemporaryDirectory(dir=os.path.join(layout.ROOT, ".run")) as root:
        os.makedirs(os.path.join(root, "src/p/sys"))
        os.makedirs(os.path.join(root, "src/shared/x"))
        files = {
            "src/p/U.c": '#include "common.h"\n\n#include "sys/a.c"\n#include "b.c"\n',
            "src/p/sys/a.c": 'INCLUDE_ASM("asm/p/nonmatchings/U", f1);\n#include "../../shared/x/t.c"\n',
            "src/p/b.c": 'INCLUDE_ASM("asm/p/nonmatchings/U", f3);\n',
            "src/shared/x/t.c": "void f2(void) {\n}\n",
            "src/p/F.c": 'INCLUDE_ASM("asm/p/nonmatchings/F", g1);\n#include "../shared/x/t.c"\n',
        }
        for rel, body in files.items():
            with open(os.path.join(root, rel), "w") as f:
                f.write(body)
        got = closure(os.path.join(root, "src/p/U.c"), root)
        assert got == ["src/p/U.c", "src/p/sys/a.c", "src/shared/x/t.c", "src/p/b.c"], got
        got = closure(os.path.join(root, "src/p/F.c"), root)
        assert got == ["src/p/F.c", "src/shared/x/t.c"], got
        assert "f3);" in closure_text(os.path.join(root, "src/p/U.c"), root)
    print("splat_closure self-test ok: L-B closure 4 files in textual order, flat unit 2")


if __name__ == "__main__":
    if sys.argv[1:] == ["--self-test"]:
        self_test()
        sys.exit(0)
    from splat.__main__ import splat_main

    patch()
    sys.argv[0] = "splat"
    sys.exit(splat_main())
