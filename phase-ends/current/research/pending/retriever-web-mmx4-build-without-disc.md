# mmx4 build without disc
task: can sozud/mmx4 compile matched C to objects without X4 disc
agent: retriever-web
tags: mmx4, psx, decomp, toolchain

## Answer
Not cleanly. The documented build needs SLUS_005.61 (splat output plus linker script). Per-file C compile is likely feasible with INCLUDE_ASM stubbed, but I did not verify it.

## Findings
- README: place SLUS_005.61 in disks/us. License AGPL-3.0. 419 commits, WIP.
- Wiki Getting Started: CD image in ./disks, extract by script, download compiler by script, run splat on yaml, then build.py, ninja, sha1 check. Deps: gcc-mipsel-linux-gnu (binutils), bchunk, ninja, splat64, spimdisasm, rabbitizer.
- build.py (ninja generator): C goes cpp_263 -> cc1_263 -> aspsx_263 -> as, i.e. gcc 2.6.3 cc1 plus aspsx 2.63. Each .c yields its own .c.o via an independent ninja rule. The source list is filtered by parsing the splat-generated linker script (main.ld), and asm comes from asm/{VERSION}/main. So the ninja path depends on splat output from the disc.
- build.sh: build.py, ninja, sha1sum check.check.$VERSION.txt. No toolchain download in it; the wiki says a separate script downloads it. Source not identified (decompals old-gcc releases not confirmed).
- CMakeLists.txt is a separate PC port (MMX4_PC, psyz submodule), not the matching build.
- Implication: matched functions can in principle be compiled one by one by running the cpp/cc1/aspsx chain on a .c with INCLUDE_ASM defined empty or stubbed. Their bytes would then be raw .text per function with relocations unresolved. This needs the old-gcc toolchain, not the disc. Not tested. INCLUDE_ASM macro file not located (include/include_asm.h 404). Check whether headers or data are disc-derived. Fall back to asm/ only if committed in the repo (unknown).
- Counts: not independently verified; the caller's KNOWN figures are 475 C files and 961 INCLUDE_ASM still open.
- Cross-game signature tools: the search found no dedicated PSX tool. decomp-toolkit has a signature DB, but it is GameCube-focused. I did not confirm sotn-decomp's dups tool or find_duplicates.

## Dead ends
Makefile 404 (the build is ninja). The wiki Home page had no content. Search found nothing on sotn dups.

sources:
- https://github.com/sozud/mmx4 (fetched 2026-10-01)
- https://github.com/sozud/mmx4/wiki/Getting-Started (fetched 2026-10-01)
- https://raw.githubusercontent.com/sozud/mmx4/main/build.py (fetched 2026-10-01)
- https://raw.githubusercontent.com/sozud/mmx4/main/build.sh (fetched 2026-10-01)
- https://raw.githubusercontent.com/sozud/mmx4/main/CMakeLists.txt (fetched 2026-10-01)
