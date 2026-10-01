#!/usr/bin/env python3
"""boundcheck.py -- every forced lib edge of config/boundaries.txt is a subsegment edge of its splat config.

    boundcheck.py [--self-test]         (make health; PyYAML from the container venv)

Forced edges are recomputed here from config/segmentation.md "Rules per row kind", independently of segment.py:
non-weak lib rows only, a span wholly inside an earlier span dropped, a partial overlap merged into one span.
Prints `BOUNDARIES OK <k> of <N> programs` (rc 0; k = programs checked, N = config/*.yaml count, only when k = N)
or the first violation (rc 1); an empty total forced-edge list is refused (G28). --self-test controls, each must be
refused: one lib TU line deleted from a copy of the exe yaml under .run/ (names that edge); one program's yaml hidden
(N-1 paths checked against N); an empty forced-edge list. Last line `BOUNDCHECK CONTROL OK` (else FAIL, rc 1).
"""
import glob
import os
import sys

import yaml

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
BOUNDARIES = os.path.join(ROOT, "config", "boundaries.txt")
WEAK = {"LIBSND.LIB/VM_VIB.OBJ"}
SELFTEST_DIR = os.path.join(ROOT, ".run", "boundcheck-selftest")
SELFTEST_TU, SELFTEST_EDGE = "LIBSPU_SPU", 0x80054D34


def forced_edges():
    """{program: [(addr, lib name)]} sorted by addr."""
    libs, cur = {}, None
    with open(BOUNDARIES) as f:
        for line in f:
            w = line.split()
            if line.startswith("# program "):
                cur = w[2]
                libs[cur] = []
            elif w and w[0] == "lib" and w[3] not in WEAK:
                libs[cur].append((int(w[1], 16), int(w[2], 16), w[3]))
    edges = {}
    for prog, rows in libs.items():
        spans = []  # [lo, hi, names]
        for lo, hi, name in sorted(rows, key=lambda r: (r[0], -r[1])):
            if spans and lo < spans[-1][1]:
                if hi > spans[-1][1]:
                    spans[-1][1] = hi
                    spans[-1][2] += "+" + name
                continue
            spans.append([lo, hi, name])
        edges[prog] = sorted({(a, n) for lo, hi, n in spans for a in (lo, hi)})
    return edges


def yaml_edges(cfg):
    """Every subsegment start vram plus each code segment's end vram."""
    out, segs = set(), cfg["segments"]
    for i, seg in enumerate(segs):
        if not isinstance(seg, dict) or "vram" not in seg:
            continue
        start, vram = seg["start"], seg["vram"]
        nxt = segs[i + 1]
        out.add(vram + ((nxt["start"] if isinstance(nxt, dict) else nxt[0]) - start))
        for sub in seg.get("subsegments", []):
            off = sub["start"] if isinstance(sub, dict) else sub[0]
            out.add(vram + off - start)
    return out


def config_yamls():
    return glob.glob(os.path.join(ROOT, "config", "*.yaml"))


def check(paths, total=None, edges=None):
    """(rc, message) over the splat configs in paths; total = programs expected (default config/*.yaml count)."""
    total = len(config_yamls()) if total is None else total
    edges, n = forced_edges() if edges is None else edges, 0
    if not sum(len(e) for e in edges.values()):
        return 1, "BOUNDARIES FAIL: empty forced-edge list from %s" % BOUNDARIES
    for path in sorted(paths):
        with open(path) as f:
            cfg = yaml.safe_load(f)
        if not isinstance(cfg, dict) or "segments" not in cfg or "options" not in cfg:
            continue
        prog = os.path.basename(path)[:-len(".yaml")]
        if prog not in edges:
            return 1, "BOUNDARIES FAIL %s: no '# program %s' in config/boundaries.txt" % (path, prog)
        have = yaml_edges(cfg)
        for addr, name in edges[prog]:
            if addr not in have:
                return 1, "BOUNDARIES FAIL %s 0x%08X %s: not a subsegment edge" % (prog, addr, name)
        n += 1
    if n != total:
        return 1, "BOUNDARIES FAIL %d of %d programs checked" % (n, total)
    return 0, "BOUNDARIES OK %d of %d programs" % (n, total)


def self_test():
    os.makedirs(SELFTEST_DIR, exist_ok=True)
    src = os.path.join(ROOT, "config", "SLUS_013.95.yaml")
    dst = os.path.join(SELFTEST_DIR, "SLUS_013.95.yaml")
    with open(src) as f:
        lines = f.readlines()
    hit = [l for l in lines if l.rstrip().endswith(", asm, %s]" % SELFTEST_TU)]
    if len(hit) != 1:
        print("boundcheck: %s line not found once in %s" % (SELFTEST_TU, src))
        return 1, "BOUNDCHECK CONTROL FAIL"
    with open(dst, "w") as f:
        f.writelines(l for l in lines if l is not hit[0])
    rc, msg = check([dst], total=1)
    print(msg)
    ok = rc == 1 and ("SLUS_013.95 0x%08X " % SELFTEST_EDGE) in msg
    print("dropped edge: %s" % ("refused" if ok else "NOT refused"))
    paths = sorted(config_yamls())
    rc, msg = check(paths[1:], total=len(paths))
    print(msg)
    hid = rc == 1 and ("%d of %d programs" % (len(paths) - 1, len(paths))) in msg
    print("hidden yaml %s: %s" % (os.path.basename(paths[0]), "refused" if hid else "NOT refused"))
    rc, msg = check(paths, edges={p: [] for p in forced_edges()})
    print(msg)
    empty = rc == 1 and "empty forced-edge list" in msg
    print("empty edge list: %s" % ("refused" if empty else "NOT refused"))
    if ok and hid and empty:
        return 0, "BOUNDCHECK CONTROL OK"
    return 1, "BOUNDCHECK CONTROL FAIL"


def main(argv):
    if argv and argv[0] == "--self-test":
        rc, msg = self_test()
    elif argv:
        print(__doc__.strip())
        return 2
    else:
        rc, msg = check(config_yamls())
    print(msg)
    return rc


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
