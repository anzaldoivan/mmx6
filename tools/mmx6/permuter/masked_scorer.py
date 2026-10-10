#!/usr/bin/env python3
"""masked_scorer.py -- decomp-permuter (/opt/decomp-permuter, pinned) with our masked scorer bound at import (container).

  masked_scorer.py <permdir> [permuter args...]   upstream `src.main.main()` with the Scorer replaced
  masked_scorer.py --stock <target.o> <cand.o>    upstream stock Scorer, unpatched: prints its score (one int)

Binding: /opt/decomp-permuter goes on sys.path; `src.scorer.Scorer` is replaced by MaskedScorer before `src.main` is
imported (main does `from .scorer import Scorer`), and `src.main.Scorer` is set again after; no upstream file is
edited (tools/mmx6/permute.py asserts `git status --porcelain` empty). Run by permute.py, never by hand.
Score: <permdir>/mmx6.json {"func", "vram"}; retail words = target.o's function (probe.elf_function; target.o is
`.word` data, no relocations); candidate words + masks = probe.elf_function (probe.MASKS) plus R_MIPS_PC16 low 16
masked here; an R_MIPS_26 against the function's own section compares opcode + target relative to function start
(retail: target - vram) instead of opcode only; other R_MIPS_26 keep opcode. score = masked word mismatches +
|length difference|, 0 only when every masked word equals retail and the lengths agree (probe's MATCH, with the PC16
and internal-jump refinements). Hash = sha256 of the candidate's masked words. Firewall G12: prints scores only.
"""
import hashlib
import json
import os
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.dirname(HERE))  # tools/mmx6 -> probe
import probe  # noqa: E402

UPSTREAM = "/opt/decomp-permuter"
R_MIPS_26, R_MIPS_HI16, R_MIPS_LO16, R_MIPS_PC16 = 4, 5, 6, 10
STOCK_OBJDUMP = "mipsel-linux-gnu-objdump -drz -m mips:4300"  # upstream MIPS arguments; its executable list lacks mipsel


def relocs(path, func):
    """[(word index, type, symbol value, symbol in the function's own section)] for func's .rel.text entries."""
    with open(path, "rb") as f:
        elf = f.read()
    e_shoff, = struct.unpack_from("<I", elf, 0x20)
    e_shentsize, e_shnum = struct.unpack_from("<HH", elf, 0x2E)
    secs = [struct.unpack_from("<10I", elf, e_shoff + i * e_shentsize) for i in range(e_shnum)]
    st = next(s for s in secs if s[1] == 2)
    strtab = secs[st[6]]
    syms = []
    for k in range(st[5] // 16):
        st_name, st_value, _, _, _, st_shndx = struct.unpack_from("<IIIBBH", elf, st[4] + 16 * k)
        b = strtab[4] + st_name
        syms.append((elf[b : elf.index(b"\0", b)].decode(), st_value, st_shndx))
    value, shndx = next((s[1], s[2]) for s in syms if s[0] == func and 0 < s[2] < 0xFF00)
    out = []
    for s in secs:
        if s[1] == 9 and s[7] == shndx:
            for k in range(s[5] // 8):
                r_offset, r_info = struct.unpack_from("<II", elf, s[4] + 8 * k)
                if r_offset >= value:
                    sym = syms[r_info >> 8]
                    out.append(((r_offset - value) // 4, r_info & 0xFF, sym[1] - value, sym[2] == shndx))
    return out


def masked(path, func):
    """(words, keys): keys[i] = the comparable form of word i -- (masked word,) or (opcode, target - func start)."""
    words, masks = probe.elf_function(path, func)
    internal = {}
    for i, typ, symoff, own in relocs(path, func):
        if i >= len(words):
            continue
        if typ == R_MIPS_PC16:
            masks[i] = masks.get(i, 0) | 0xFFFF
        elif typ == R_MIPS_26 and own:
            internal[i] = symoff + ((words[i] & 0x03FFFFFF) << 2)
    keys = []
    for i, w in enumerate(words):
        if i in internal:
            keys.append((w >> 26, internal[i]))
        else:
            keys.append((w & ~masks.get(i, 0) & 0xFFFFFFFF,))
    return words, keys, masks, internal


def score_words(cand_o, func, target, vram):
    """Masked score of cand_o's func against retail words `target` (function at `vram`), and the candidate hash."""
    words, keys, masks, internal = masked(cand_o, func)
    bad = abs(len(words) - len(target))
    for i in range(min(len(words), len(target))):
        r = target[i]
        if i in internal:
            pc = vram + 4 * i
            rel = (((pc + 4) & 0xF0000000) | ((r & 0x03FFFFFF) << 2)) - vram
            bad += keys[i] != (r >> 26, rel)
        else:
            keep = ~masks.get(i, 0) & 0xFFFFFFFF
            bad += (r & keep) != keys[i][0]
    return bad, hashlib.sha256(repr(keys).encode()).hexdigest()


def bind():
    """Import upstream with MaskedScorer bound in place of src.scorer.Scorer; returns src.main."""
    sys.path.insert(0, UPSTREAM)
    import src.scorer as upstream_scorer

    class MaskedScorer(upstream_scorer.Scorer):
        def __init__(self, target_o, **_kw):  # upstream kwargs (stack_differences, algorithm, ...) do not apply
            self.target_o = target_o
            with open(os.path.join(os.path.dirname(target_o), "mmx6.json")) as f:
                cfg = json.load(f)
            self.func, self.vram = cfg["func"], int(cfg["vram"], 0)
            self.target = probe.elf_function(target_o, self.func)[0]

        def score(self, cand_o):
            if not cand_o:
                return self.PENALTY_INF, ""
            try:
                return score_words(cand_o, self.func, self.target, self.vram)
            except (SystemExit, StopIteration, struct.error):  # function missing / unreadable object
                return self.PENALTY_INF, ""

    upstream_scorer.Scorer = MaskedScorer
    import src.main as upstream_main
    upstream_main.Scorer = MaskedScorer
    return upstream_main


def stock(target_o, cand_o):
    sys.path.insert(0, UPSTREAM)
    from src.scorer import Scorer

    s = Scorer(target_o, stack_differences=False, algorithm="difflib", debug_mode=False, ign_branch_targets=True,
               objdump_command=STOCK_OBJDUMP)
    return s.score(cand_o)[0]


if __name__ == "__main__":
    if len(sys.argv) == 4 and sys.argv[1] == "--stock":
        print(stock(sys.argv[2], sys.argv[3]))
        sys.exit(0)
    main = bind()
    sys.argv = [os.path.join(UPSTREAM, "permuter.py")] + sys.argv[1:]
    main.main()
