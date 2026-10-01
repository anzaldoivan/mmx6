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
