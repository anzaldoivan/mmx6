"""scratch.py — the .run/ size cap (`make scratch-check`): warn at >= warn_gb, rc 1 above cap_gb."""

from __future__ import annotations

import argparse
import os
import sys

GB = 1024**3


def check(root: str = ".run", cap_gb: float = 25, warn_gb: float = 20) -> int:
    total = 0
    for dirpath, _dirs, files in os.walk(root):
        for name in files:
            p = os.path.join(dirpath, name)
            if not os.path.islink(p):
                total += os.path.getsize(p)
    gb = total / GB
    print(f"scratch {root}: {gb:.3f} GB ({total} B); warn {warn_gb} GB, cap {cap_gb} GB")
    if gb > cap_gb:
        print(f"FAIL: {root} over cap ({gb:.3f} > {cap_gb} GB)")
        return 1
    if gb >= warn_gb:
        print(f"WARN: {root} at or above warn threshold ({gb:.3f} >= {warn_gb} GB)")
    return 0


def main(argv: list[str] | None = None) -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--root", default=".run")
    ap.add_argument("--cap-gb", type=float, default=25)
    ap.add_argument("--warn-gb", type=float, default=20)
    a = ap.parse_args(argv)
    return check(a.root, a.cap_gb, a.warn_gb)


if __name__ == "__main__":
    sys.exit(main())
