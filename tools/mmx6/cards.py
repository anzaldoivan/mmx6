#!/usr/bin/env python3
"""cards.py -- wave packs: card writing (T2.c2) and the pack probe (container, stdlib only).

  cards.py --probe-pack <dir> [--hold S] [--no-snapshot]
      -> `PACK <pv> match <m>/<n>` | `PACK <pv> fail <m>/<n>` | `PACK <pv> nocompile`; rc 0 on any PACK line
      Compiles <dir>/draft.c as drafts/<prog>/<func>.c (its TU's flags, probe.draft_cflags) inside a fresh snapshot
      waves/.iso/<tag>/ of every input probe reads, cwd = the snapshot, so an `mx.sh sync` (which spares waves/)
      cannot pull the tree out from under a running gate; the snapshot is removed after. --hold S sleeps S seconds
      after the snapshot is built (`PACK HOLD <s>` printed first); --no-snapshot compiles in /work itself (the
      negative control of tools/docker/pack_control.sh only).

Pack dir waves/W<n>/<prog>_<func>/: pack.json {pv,prog,func,tu,words}, target.s, draft.c, verdict.json
(docs/ops/campaign.md ## Packs). Snapshot: asm/ and extracted/ hardlinked (nothing writes them in place), Makefile,
mk/, include/, src/, config/, tools/, build/corpus/, build/split/ copied. Firewall G12: prints counts only.
"""
import argparse
import json
import os
import re
import shutil
import subprocess
import sys
import time

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import probe  # noqa: E402  (relative paths only: retail_words, draft_cflags, compile_obj, elf_function)

ISO = "waves/.iso"
LINK = ("asm", "extracted")
COPY = ("Makefile", "mk", "include", "src", "config", "tools", "build/corpus", "build/split")


def triple():
    """The Makefile's default TRIPLE (`TRIPLE ?= <name>`)."""
    with open("Makefile") as f:
        for line in f:
            m = re.match(r"TRIPLE \?= (\S+)", line)
            if m:
                return m.group(1)
    sys.exit("cards: no `TRIPLE ?=` in the Makefile")


def snapshot(tag):
    """Build waves/.iso/<tag>/ from the current tree; returns its absolute path."""
    dst = os.path.abspath(os.path.join(ISO, tag))
    shutil.rmtree(dst, ignore_errors=True)
    os.makedirs(dst)
    for p in LINK + COPY:
        if not os.path.exists(p):
            continue
        os.makedirs(os.path.dirname(os.path.join(dst, p)) or dst, exist_ok=True)
        subprocess.run(["cp", "-al" if p in LINK else "-a", p, os.path.join(dst, p)], check=True)
    return dst


def score(func, prog, src, t):
    """('match'|'fail', m, n) or ('nocompile', 0, n): probe.probe's comparison, with a compile failure kept apart."""
    ret = probe.retail_words(prog, func)
    obj = probe.compile_obj(src, t)
    if obj is None:
        return "nocompile", 0, len(ret)
    ours, masks = probe.elf_function(obj, func)
    m = 0
    for i in range(min(len(ret), len(ours))):
        keep = ~masks.get(i, 0) & 0xFFFFFFFF
        m += (ret[i] & keep) == (ours[i] & keep)
    return ("match" if len(ours) == len(ret) and m == len(ret) else "fail"), m, len(ret)


def probe_pack(pack, hold, iso):
    with open(os.path.join(pack, "pack.json")) as f:
        meta = json.load(f)
    with open(os.path.join(pack, "draft.c"), "rb") as f:
        draft = f.read()
    pv, prog, func = meta["pv"], meta["prog"], meta["func"]
    t = triple()
    src = f"drafts/{prog}/{func}.c"
    if not iso and os.path.exists(src):
        sys.exit(f"cards: --no-snapshot would overwrite the stored draft {src}")
    snap = snapshot(f"{prog}_{func}.{os.getpid()}") if iso else None
    try:
        if snap:
            os.chdir(snap)
        os.makedirs(os.path.dirname(src), exist_ok=True)
        with open(src, "wb") as f:
            f.write(draft)
        if hold:
            print(f"PACK HOLD {hold}", flush=True)
            time.sleep(hold)
        state, m, n = score(func, prog, src, t)
    finally:
        if snap:
            os.chdir(os.path.dirname(os.path.dirname(os.path.dirname(snap))))
            shutil.rmtree(snap, ignore_errors=True)
        elif os.path.exists(src):
            os.remove(src)
    print(f"PACK {pv} {state}" + (f" {m}/{n}" if state != "nocompile" else ""), flush=True)
    return 0


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n", 1)[0])
    ap.add_argument("--probe-pack", metavar="DIR", required=True)
    ap.add_argument("--hold", type=float, default=0)
    ap.add_argument("--no-snapshot", action="store_true")
    a = ap.parse_args()
    return probe_pack(a.probe_pack, a.hold, not a.no_snapshot)


if __name__ == "__main__":
    sys.exit(main())
