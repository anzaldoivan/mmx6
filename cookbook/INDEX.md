<!-- Cookbook index. One line per entry, appended by tools/cookbook_add.sh. Grep this file by tag or title; never read it whole; never read an entry you did not find here. -->
<!-- C<nnnn> | <title> | <tags> | <date> | <phase>/<task> | origin: <source section or report id> -->
C0001 | The decomp idiom entry shape: residual, mechanism, lever, byte proof | cookbook-format,idiom,residual,mechanism,lever,byte-proof | 2026-10-01 | - | decomp-architect
C0002 | The triage table: diff tell to mechanism to lever family | triage,symptom,tell,spill,register-pressure,aliasing,callee-saved,branch-polarity,cross-jump | 2026-10-01 | - | decomp-architect
C0003 | Offline tooling first: every computable step becomes a zero-token deterministic tool | strategy,deterministic,recovery,permuter,economics,tooling | 2026-10-01 | - | decomp-architect
C0004 | A slow gate is a bug: parallel worktrees, a per-binary lock, the parallel flag on every build | gate,parallel,worktree,lock,build,throughput | 2026-10-01 | - | decomp-architect
C0005 | Breadth is isolated agents: per-item agents cost about linearly, one serial loop about quadratically | breadth,agents,drafting,fan-out,cost | 2026-10-01 | - | decomp-architect
C0006 | Route drafters by a difficulty cliff measured on your own corpus | routing,model-tier,drafting,cliff,escalation,cost | 2026-10-01 | - | decomp-architect
C0007 | dumpsxiso writes XA/STR at 2336 B/sector; compare by sectors, not ISO size | psx,iso9660,xa,str,dumpsxiso,extract | 2026-10-01 | - | carried from dino-crisis-2-decomp C0007
C0008 | dumpsxiso -x dir holds license_data.dat (and DA .WAV); move out before diffing | psx,dumpsxiso,extract,diff,reference | 2026-10-01 | - | carried from dino-crisis-2-decomp C0008
C0009 | fnmatch **/X misses root-level X; add a sibling root glob | firewall,glob,fnmatch,audit | 2026-10-01 | 1.0/T1 | mmx6 T1
C0010 | Pin docker images by config digest, not image Id, under buildx | docker,pin,buildx,reproducibility | 2026-10-01 | 1.0/T2 | mmx6 T2
C0011 | ISO9660 dir-record XA attribute is big-endian; Form 2 = 0x1000, cross-check submode bit 5 | psx,iso9660,xa,form2,extract | 2026-10-01 | 1.1/T1 | mmx6 T1
C0012 | objdump a PS-X EXE as raw binary with --adjust-vma=load-0x800; keep listing in .run | psx,mips,objdump,exe,disassembly | 2026-10-01 | 1.1/T2 | mmx6 T2
C0013 | dumpsxiso also writes an XML project into its cwd; move it out before diffing | psx,dumpsxiso,extract,diff,reference | 2026-10-01 | 1.1/T4 | mmx6 T4
C0014 | Ghidra headless: preScript setAnalysisOption does not disable a psx_ldr analyzer; use -noanalysis as control | ghidra,psx_ldr,headless,analysis,negative-control | 2026-10-01 | 1.2/T1 | mmx6 T1
C0015 | GhidrAssistMCP headless: stop via completion_file so the project saves; killing the JVM skips the save | ghidra,mcp,ghidrassistmcp,headless,save | 2026-10-01 | 1.2/T2 | mmx6 T2
C0016 | Ghidra headless refuses project paths with a dot-leading element; reach .run/ scratch via a symlink | ghidra,headless,project,path | 2026-10-01 | 1.2/T3 | mmx6 T3
C0017 | analyzeHeadless exits 0 when a script prints an error and returns; grep the script's error marker | ghidra,headless,exit-code,wrapper | 2026-10-01 | 1.2/T3 | mmx6 T3
C0018 | PCSX-Redux on macOS arm64 crashes under the dynarec headless; run with -interpreter | pcsx-redux,macos,arm64,headless,interpreter | 2026-10-01 | 1.2/T4 | mmx6 T4
C0019 | PCSX-Redux Lua Exec breakpoints never fire without -debugger | pcsx-redux,lua,breakpoint,debugger | 2026-10-01 | 1.2/T4 | mmx6 T4
C0020 | PCSX-Redux -portable keeps config in the run dir; spu.Speed = 0 runs unthrottled | pcsx-redux,portable,speed,headless | 2026-10-01 | 1.2/T4 | mmx6 T4
C0021 | Ghidra function starts without extents over-include data tails; trim to last jr ra + delay slot | ghidra,export,function-extent,mips,compare | 2026-10-01 | 1.2/T4 | mmx6 T4
C0022 | PCSX-Redux Lua pad input: SIO0.slots[1].pads[1].setOverride/clearOverride | pcsx-redux,lua,pad,input | 2026-10-01 | 1.2/T5 | mmx6 T5
C0023 | macOS host has no MIPS objdump; disassemble in the build container or decode words in the tool | macos,mips,objdump,disassembly,container | 2026-10-01 | 1.2/T6 | mmx6 T6
C0024 | Ghidra BinaryLoader headless -loader-baseAddr can leave image_base 0; import at 0 and setImageBase in a preScript | ghidra,binaryloader,image-base,headless,overlay | 2026-10-01 | 1.2/T7 | mmx6 T7
C0025 | Ghidra multi-import JVM: per-program analysis summary missing from log; check per-program artifacts | ghidra,headless,batch,log,verification | 2026-10-01 | 1.2/T7 | mmx6 T7
C0026 | Ghidra may emit switchdataD_ labels every 8 B inside one switch table; merge labels within a bounded table | ghidra,switch,jump-table,labels,boundaries | 2026-10-01 | 1.2/T8 | mmx6 T8
C0027 | make target failure rc is 2, not 1 | make,gates | 2026-10-01 | 1.3/T1 | -
C0028 | splat symbol_addrs parses trailing // comments | splat,symbols | 2026-10-01 | 1.3/T2 | -
C0029 | .DELETE_ON_ERROR for rules ending in a hash check | make,hash,gates | 2026-10-01 | 1.3/T2 | -
C0030 | Count TUs from forced edges before editing yaml | segmentation,splat | 2026-10-01 | 1.3/T3 | -
C0031 | splat psx many asm subsegments: subalign 4 | splat,psx,linker,hash | 2026-10-01 | 1.3/T4 | -
C0032 | mipsel as inserts sync before ll: -mno-fix-loongson3-llsc | binutils,mips,asm | 2026-10-01 | 1.3/T5 | -
C0033 | All-asm overlays: data words through gas need -march=r4000 | binutils,mips,overlays | 2026-10-01 | 1.3/T5 | -
C0034 | A gate that must re-hash needs a clean step | make,hash,gates | 2026-10-01 | 1.3/T6 | -
C0035 | A cpp|cc1|maspsx|as pipe returns only as's rc; a dead cc1 still exits 0 | make,pipefail,toolchain,psx | 2026-10-01 | 1.4/T1 | mmx6 T1
C0036 | Ubuntu make recipes run under dash (no pipefail); set SHELL bash + .SHELLFLAGS per target | make,pipefail,dash,ubuntu | 2026-10-01 | 1.4/T2 | mmx6 T2
C0037 | cpp 12 -nostdinc drops the stdc-predef.h pre-include that old gcc 2.x cc1 warns on | cpp,old-gcc,cc1,psx | 2026-10-01 | 1.4/T2 | mmx6 T2
C0038 | An INCLUDE_ASM probe control is triple-independent; pair it with a planted one-word mutation | probe,control,compare,masking | 2026-10-01 | 1.4/T3 | mmx6 T3
C0039 | asm-differ arch mips is big-endian; PSX needs mipsel (m2c target mipsel-gcc-c) | asm-differ,m2c,mips,endianness,psx | 2026-10-01 | 1.4/T4 | mmx6 T4
C0040 | make -j extract build races; run extract as its own make call first | make,parallel,extract,race | 2026-10-01 | 1.4/T4 | mmx6 T4
C0041 | splat's instruction comment word is in file byte order; decode as little-endian before field extraction | splat,mips,decode,endianness | 2026-10-01 | 1.4/T5 | mmx6 T5
C0042 | A splat asm subsegment can come out as dlabel + .word with 0 glabel; per-function tools must detect it | splat,spimdisasm,census,functions | 2026-10-01 | 1.4/T5 | mmx6 T5
C0043 | A break 7 near a div is not an expanded-div test; classify by break 6 presence and mflo position | mips,division,maspsx,expand-div,fingerprint | 2026-10-01 | 1.4/T6 | mmx6 T6
C0044 | maspsx aspsx-version rungs >= 2.60 are byte-identical under -G0 with no $gp access | maspsx,aspsx,pin,ladder,psx | 2026-10-01 | 1.4/T6 | mmx6 T6
C0045 | A trailing # comment on a make VAR ?= value line keeps the space before # in the value | make,variables,comments | 2026-10-01 | 1.4/T6.1 | mmx6 T6.1
C0046 | splat 0.50 c-mode writes a jr ra; nop function as empty C; measure the stub-only baseline before banking | splat,c-mode,count,baseline | 2026-10-01 | 1.4/T8 | mmx6 T8
C0047 | Once a function is C, splat writes no nonmatchings .s for it; extent tools must fall back to symbol order | splat,nonmatchings,extent,probe | 2026-10-01 | 1.4/T8 | mmx6 T8
C0048 | spimdisasm farthestBranch survives function ends; declare sized func symbols | splat,spimdisasm,overlay,boundaries | 2026-10-01 | 1.5/T1 | T1 overlay 0-glabel fix
C0049 | jr ra count overcounts functions (multi-return) | boundaries,census,mips | 2026-10-01 | 1.5/T1 | T1
C0050 | Coverage oracle: closed set of uncovered-byte kinds with precedence | oracle,coverage,corpus | 2026-10-01 | 1.5/T2 | T2 corpus spans
C0051 | Narrowing control from the real population (hide one input dir) | self-test,control,scanner | 2026-10-01 | 1.5/T3 | T3 optscan
C0052 | Post-return start rule chains through data; scope it | boundaries,bound2,data | 2026-10-01 | 1.5/T4 | T4 bound2
C0053 | spimdisasm ends sized symbols only at size >= 8 | splat,spimdisasm,symbols | 2026-10-01 | 1.5/T5 | T5 symbols
C0054 | Self-test controls inject disagreements, never borrow real ones | self-test,control | 2026-10-01 | 1.5/T5 | T5 bound2 ledger
C0055 | Dup census: load-bearing-mask control (twin must split unmasked) | census,duplicates,control | 2026-10-01 | 1.5/T6 | T6 census
C0056 | Report over a census: currency guard plus planted mutation | report,census,control | 2026-10-01 | 1.5/T7 | T7 report
C0057 | Harness pair whose instrument never ran is NOT-RUN, counted as disagreement | harness,differential,control | 2026-10-01 | 1.5/T8 | T8 harness P3
C0058 | Splat can fuse dozens of real functions into one; check B2 starts strictly inside each function | boundaries,splat,spimdisasm,merge,bound2 | 2026-10-01 | 1.6/T1 | mmx6 T1
C0059 | Code after an interior jr ra reached by no edge is its own function; splitting is byte-neutral | boundaries,mips,multi-return,merge | 2026-10-01 | 1.6/T1 | mmx6 T1
C0060 | Near-duplicate band: lossless prefilter by length and opcode-histogram bounds | twins,near-dup,edit-distance,census | 2026-10-01 | 1.6/T2 | mmx6 T2
C0061 | Moving a type to a shared header: remove its copies from probe sources too | types,header,probe,common.h | 2026-10-01 | 1.6/T3 | mmx6 T3
C0062 | A masked standalone match can name the wrong symbol; only the whole-binary hash catches it | probe,masking,relocation,bank | 2026-10-01 | 1.6/T4 | mmx6 T4
C0063 | Format a body before the first probe; clang-format changes its sha1 afterwards | clang-format,bank,sha1 | 2026-10-01 | 1.6/T4 | mmx6 T4
C0064 | Verify c-unit conversions from a clean sync; splat skips .s for functions only named D_<addr> | splat,c-unit,nonmatchings,overlay | 2026-10-01 | 1.6/T5 | mmx6 T5
C0065 | Parameterise a shared body per member with name #defines; gate with an unmasked linked compare | dedup,propagate,define,relocation | 2026-10-01 | 1.6/T5 | mmx6 T5
C0066 | Plant a self-test precondition that real progress consumed; prove the plant by the binary hash | self-test,control,plant | 2026-10-01 | 1.6/T6.1 | mmx6 T6.1
C0067 | A corpus regeneration rewrites several outputs together; scratch runs save and restore all of them | corpus,scratch,self-test | 2026-10-01 | 1.6/T6.1 | mmx6 T6.1
C0068 | A planted .word .s must span the corpus extent to its end, or the link shifts | plant,probe,extent,link | 2026-10-01 | 1.6/T6.1 | mmx6 T6.1
C0069 | splat pairs rodata with a c unit only as type .rodata; derive the dispatcher from %hi | splat,rodata,jtbl,carve | 2026-10-01 | 1.6/T6 | mmx6 T6
C0070 | Splitting a c unit must rewrite the moved INCLUDE_ASM folders to the new unit | splat,carve,include_asm,nonmatchings | 2026-10-01 | 1.6/T6 | mmx6 T6
C0071 | Family-only siblings differ in a non-relocated field; relocation remap gates few | family,remap,dedup,relocation | 2026-10-01 | 1.6/T7 | mmx6 T7
C0072 | #define A B with #define B A collapses under cpp rescanning; refuse such mappings | cpp,define,remap | 2026-10-01 | 1.6/T7 | mmx6 T7
C0073 | Test sibling-game sharing under the target's compiler pin; vary only the compiler as the control | prior-art,sibling-game,pin,control | 2026-10-01 | 1.6/T8 | mmx6 T8
C0074 | Draw filter over a twin graph: at most one member per connected component per wave | draw,twins,wave,routing | 2026-10-01 | 1.6/T9 | mmx6 T9
