"""paths.py — the version axis (3.3 T37; docs/ops/multi-version.md items 3, 7): the generated trees, repo-relative.

VERSION (env, default `us`) selects the build target; BUILD_ROOT (env, default `build`) moves every build output, so
a self-test ladder can build in its own tree. The Makefile exports both with the same defaults, so a tool run by make
and the make it runs agree. Shell scripts read the same two variables with the same defaults.
  BUILD      $BUILD_ROOT/$VERSION   every build output (objects, elfs, maps, corpus, census, propagate, ...)
  EXTRACTED  extracted/$VERSION     the retail medium's files (`make extract`; read-only, never cleaned)
  EXPECTED   expected/$VERSION      asm-differ's baseline (`make expected`)
  MANIFEST   manifest/$VERSION.jsonl the hash manifest of EXTRACTED
  ASM        asm/$VERSION           splat's output (3.3 T38); INCLUDE_ASM folders are version-neutral (`<bin>/nonmatchings/
                                    <tu>`): gas finds them through `-Iasm/$VERSION` (Makefile ASFLAGS)
  CONFIG_V   config/$VERSION        the address-bound config (3.3 T37.c3): splat yamls, symbols.<bin>.txt, carve.<bin>.*,
                                    dedup_registry, equiv-keys, loadmap, boundaries, boundary_exceptions, data_bytes.
                                    Shared config (names, units, layout, check.*.sha, medium.sha1, ...) stays in config/.
  MAIN       main                   the main program's key (3.3 T38: was its disc file name): src/main/, asm/$VERSION/
                                    main/, config/$VERSION/main.yaml, symbols.main.txt, `main:0x<vram>` ids
  MAIN_EXE   (registry)             the main program's disc file name (the boot executable; the final binary
                                    $BUILD/<MAIN_EXE>, check.<MAIN_EXE>.sha, extracted/$VERSION/iso/<MAIN_EXE>):
                                    config/versions.tsv's serial joined to config/discs.tsv's executable. The one
                                    mapping; the Makefile derives MAIN_EXE the same way. `paths.py <NAME>` prints one.
"""
import os
import sys

VERSION = os.environ.get("VERSION") or "us"
BUILD_ROOT = os.environ.get("BUILD_ROOT") or "build"
BUILD = f"{BUILD_ROOT}/{VERSION}"
EXTRACTED = f"extracted/{VERSION}"
EXPECTED = f"expected/{VERSION}"
MANIFEST = f"manifest/{VERSION}.jsonl"
ASM = f"asm/{VERSION}"
CONFIG_V = f"config/{VERSION}"
MAIN = "main"


def _main_exe():
    root = os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "..")
    rows = lambda f: [ln.rstrip("\n").split("\t") for ln in open(os.path.join(root, "config", f))
                      if ln.strip() and not ln.startswith("#")]
    serial = {r[0]: r[1] for r in rows("versions.tsv")[1:]}.get(VERSION)
    exe = {r[1]: r[2] for r in rows("discs.tsv")[1:]}.get(serial)
    if not exe:
        sys.exit(f"paths.py: VERSION {VERSION!r} has no executable (config/versions.tsv serial -> config/discs.tsv)")
    return exe


MAIN_EXE = _main_exe()


def prog_key(key):
    """A program key or `<prog>:0x<vram>` id under today's key: records written before 3.3 T38 (the hash-chained
    journals, harvest/, rec/, refusecause.*, priorart, methods-before/after, wave-rows, methods-arm, imported x5/xref
    tables) stay at their old key, the disc file name MAIN_EXE; their readers map it to MAIN here (the one alias)."""
    prog, sep, rest = key.partition(":")
    return (MAIN if prog == MAIN_EXE else prog) + sep + rest

if __name__ == "__main__":
    print(globals()[sys.argv[1]])
