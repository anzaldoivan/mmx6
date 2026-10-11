<!-- Cookbook index. One line per entry, appended by tools/cookbook_add.sh. Grep this file by tag or title; never read it whole; never read an entry you did not find here. -->
<!-- C<nnnn> | <title> | <tags> | <date> | <phase>/<task> | origin: <source section or report id> -->
C0001 | The decomp idiom entry shape: residual, mechanism, lever, byte proof | cookbook-format,idiom-shape,residual,mechanism,lever,byte-proof | 2026-10-01 | - | decomp-architect
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
C0075 | Global reloaded after *p= but kept after p[k]=/p->f= (cse /s aliasing) | idiom,sym-global-reload,G-expr,cse,aliasing,reload | 2026-10-01 | 1.7/T4 | mmx6 repro
C0076 | &local cached in $s0 via a named pointer vs per-site addiu (call args) | idiom,sym-phantom-callee-saved,G-expr,rtl,callee-saved,address | 2026-10-01 | 1.7/T4 | mmx6 repro
C0077 | Up-count loop reversed to bgez; write the down-count for bgtz/bne | idiom,sym-loop-reversed,G-loop,loop,dbra,branch | 2026-10-01 | 1.7/T4 | mmx6 repro
C0078 | lw+andi 0xff vs lbu: combine merges the mask only if the word dies | idiom,sym-narrow-load,G-combine,combine,lbu,mask | 2026-10-01 | 1.7/T4 | mmx6 repro
C0079 | $16/$17 swapped at equal priority: declaration order breaks the global-alloc tie | idiom,sym-sreg-swapped,G-alloc,greg,regalloc,decl-order | 2026-10-02 | 1.7/T5 | mmx6 repro
C0080 | $16/$17 swapped by ref count: global-alloc density floor_log2(refs)*refs/live | idiom,sym-sreg-swapped,G-alloc,greg,regalloc,refs | 2026-10-02 | 1.7/T5 | mmx6 repro
C0081 | Load held below *p= but hoisted above p->f= (sched /s aliasing) | idiom,sym-load-below-store,G-sched,sched,aliasing,order | 2026-10-02 | 1.7/T5 | mmx6 repro
C0082 | beqz vs bnez: the if arm falls through; invert the condition and swap arms | idiom,sym-branch-arms-swapped,G-jump,jump,polarity,branch | 2026-10-02 | 1.7/T5 | mmx6 repro
C0083 | Cross-jump: a fall-through arm ending in a call never merges; a store tail merges the call | idiom,sym-cross-jump,G-jump,jump2,cross-jump,call | 2026-10-02 | 1.7/T5 | mmx6 repro
C0084 | Index sll 2 vs none: p[i] on int * scales, a char * byte offset does not | idiom,sym-shift-x4,G-expr,rtl,pointer,shift | 2026-10-02 | 1.7/T5 | mmx6 repro
C0085 | Spill slots swapped: reload assigns slots in pseudo (declaration) order | idiom,sym-spill-slot,G-alloc,greg,spill,decl-order | 2026-10-02 | 1.7/T5 | mmx6 repro
C0086 | Struct base reloaded per member store: name the pointer-derived base in a local | idiom,sym-global-reload,G-expr,cse,alias,struct | 2026-10-02 | 1.7/T6 | BFM §193-H re-proven
C0087 | Loop guard: while copies its exit test as the guard; a written guard + do-while keeps yours | idiom,sym-loop-reversed,G-jump,jump,loop,guard | 2026-10-02 | 1.7/T6 | BFM §279 re-proven
C0088 | lhu vs lh on a masked short: & in the expression is shortened; an int temp keeps lh | idiom,sym-narrow-load,G-expr,rtl,shorten,short | 2026-10-02 | 1.7/T6 | BFM §329 re-proven
C0089 | Volatile short read: lhu + sll/sra instead of lh (combine skips volatile) | idiom,sym-narrow-load,G-combine,combine,volatile,short | 2026-10-02 | 1.7/T6 | BFM §345 re-proven
C0090 | A release archive's sha256 is not its binary's; prove a binary by the extracted file | pin,hash,toolchain,provenance | 2026-10-02 | 1.7/T1 | mmx6 T1
C0091 | decompals/old-gcc releases rebuild bit-identical from the tag's Dockerfile on a pinned focal base | toolchain,provenance,gcc,docker,pin | 2026-10-02 | 1.7/T1 | mmx6 T1
C0092 | Target-specific make vars are invisible to other targets: splice make -n -B's recipe line | make,toolchain,flags,dumps | 2026-10-02 | 1.7/T2 | mmx6 T2
C0093 | Prove an instrumented compile matches the build by diffing .text bytes, not RTL insn counts | toolchain,dumps,control,gcc | 2026-10-02 | 1.7/T2 | mmx6 T2
C0094 | Line-numbered citations into C sources: split on \n only, never str.splitlines() | python,citations,gcc,self-test | 2026-10-02 | 1.7/T3 | mmx6 T3
C0095 | Allocation-order reproducers must keep values live across a block boundary | gcc,greg,regalloc,reproducer | 2026-10-02 | 1.7/T3 | mmx6 T3
C0096 | Pipe-delimited rows break on citation fragments containing a pipe | docs,format,citations | 2026-10-02 | 1.7/T4 | mmx6 T4
C0097 | The same C idiom can move pass between gcc versions: re-prove, never port the citation | gcc,G67,citations,porting | 2026-10-02 | 1.7/T4 | mmx6 T4
C0098 | A spill-slot swap lever cannot be a pure order diff: declare a length 0 diff | reproducer,spill,G-alloc,diff | 2026-10-02 | 1.7/T5 | mmx6 T5
C0099 | Inherited gcc 2.7.2 idioms often go byte-identical under 2.95.2: reproduce before entering | gcc,porting,BFM,reproducer | 2026-10-02 | 1.7/T6 | mmx6 T6
C0100 | decomp-permuter --seed random-walks one candidate; seed 0 means unseeded | permuter,seed,random | 2026-10-02 | 1.7/T7 | mmx6 T7
C0101 | decomp-permuter writes its iteration status with \b/\r: split on \r and \n to count | permuter,parsing,iterations | 2026-10-02 | 1.7/T7 | mmx6 T7
C0102 | Stock permuter objdump scorer never reaches 0 on a relocated function: mask relocations both sides | permuter,relocation,scorer,masking | 2026-10-02 | 1.7/T7 | mmx6 T7
C0103 | Unused-result call cast to (void) splits or merges identical call arms (jump2) | idiom,sym-cross-jump,G-jump,jump2,cross-jump,call,void-cast | 2026-10-02 | 1.8/T9 | mmx6 W0
C0104 | Callee declaration is a lever: arity, return type, prototype vs unprototyped | lever,prototype,callee,arity,return-type,unprototyped,m2c,regalloc | 2026-10-02 | 1.8/T9 | mmx6 W0
C0105 | Typed struct/array global instead of M2C_FIELD byte offsets | idiom,sym-global-reload,global,struct,M2C_FIELD,m2c,cse,base-register | 2026-10-02 | 1.8/T9 | mmx6 W0
C0106 | Shared function-scope local across a repeated block raises its allocation priority | idiom,sym-sreg-swapped,regalloc,global-alloc,macro,priority | 2026-10-03 | 1.8/T10 | mmx6 W1
C0107 | If/else stores instead of a ternary end cse path-following so a field is reloaded | lever,ternary,if-else,cse,reload,byte-field | 2026-10-03 | 1.8/T10 | mmx6 W1
C0108 | Constant multiply spelled as shifted terms with a temp picks synth_mult's destination register | lever,synth_mult,multiply,shift,regalloc,jump2 | 2026-10-03 | 1.8/T10 | mmx6 W1
C0109 | Pointer to a global declared per branch block stops one address being reused across arms | lever,cse,global,pointer,block-scope,length | 2026-10-03 | 1.8/T11 | mmx6 W2
C0110 | Remainder as value minus quotient times divisor, then divide in place, reuses the quotient | lever,divide,remainder,quotient,regalloc,digits | 2026-10-03 | 1.8/T11 | mmx6 W2
C0111 | If/else arms each storing a field via a pinned block local cross-jump into one store | lever,if-else,cross-jump,jump2,delay-slot,clamp,register-pin | 2026-10-03 | 1.8/T12 | mmx6 W3
C0112 | Volatile read on a join test keeps the reload and stops jump threading | lever,volatile,cse,reload,jump-threading,join,flags | 2026-10-03 | 1.8/T12 | mmx6 W3
C0113 | Linear compare chain in retail is an if/else-if chain, not a switch | lever,switch,if-chain,dispatch,case-tree,block-order | 2026-10-03 | 1.8/T13 | mmx6 W4
C0114 | Unaligned 4-byte table copy is __builtin_memcpy with u8 pointers | lever,memcpy,unaligned,copy,builtin,length | 2026-10-03 | 1.8/T13 | mmx6 W4
C0115 | A goto to the body in one arm stops jump2 cross-jumping identical compare tails | lever,goto,cross-jump,jump2,arm-order,block-order | 2026-10-03 | 1.8/T13 | mmx6 W4
C0116 | Hold an index sub-expression in a local to stop constant reassociation | lever,reassociation,index,pseudo,local,lui-order | 2026-10-03 | 1.8/T13 | mmx6 W4
C0117 | A splat blob whose fields retail loads by fresh high-half is several globals: one extern per field | lever,splat,blob,extern,cse,hi-lo,global | 2026-10-03 | 1.8/T13 | mmx6 W4
C0118 | Struct-typed self/parent pointers let sched1 hoist global loads above self stores | lever,sched1,alias,struct,self,mem | 2026-10-04 | 1.8/T10 | mmx6 W1
C0119 | Assign an s16 to an s32 local before negating into a halfword to keep the sign extension | lever,sign-extension,negate,halfword,s16,local | 2026-10-04 | 1.8/T13 | mmx6 W4
C0120 | Predecrement-and-test on an s16 field without a temp keeps retail's lone zero test | lever,predecrement,s16,zero-test,field,temp | 2026-10-04 | 1.8/T13 | mmx6 W4
C0121 | A loop gcc reverses: up-count source puts the base register first, down-count the counter first | lever,loop,loop-reversal,register-order,regalloc | 2026-10-04 | 1.8/T13 | mmx6 W4
C0122 | One variable per arm: a function-scope temp shared by two arms can swap callee-saved registers | lever,regalloc,temp,callee-saved,arms,local | 2026-10-04 | 1.8/T13 | mmx6 W4
C0123 | m2c scaffolds: --valid-syntax with a #define-only prelude compiles far more bodies than a typedef prelude | m2c,scaffold,prelude,define,typedef,compile | 2026-10-04 | 1.8/T5 | mmx6 scaffold lane
C0124 | m2c guesses callee arity per body: call through an unprototyped cast; trust the TU's consensus declaration | m2c,prototype,arity,cast,declaration,scaffold | 2026-10-04 | 1.8/T5 | mmx6 scaffold lane, W4
C0125 | PSX overlays repeat function names across programs: key per-function scratch by program | psx,overlay,scratch,parallel,naming,race | 2026-10-04 | 1.8/T5 | mmx6 scaffold lane
C0126 | A family differing in one non-relocated immediate gates from one match by a macro-parameterised body | dedup,family,macro,parameterised,propagate,immediate | 2026-10-04 | 1.8/T6 | mmx6 W-fam
C0127 | Port a sibling game's matched C by aligning relocations word-by-word to rename symbols | prior-art,port,relocation,sibling,x4,symbols | 2026-10-04 | 1.8/T7 | mmx6 W-x4
C0128 | A sibling decomp's vendored SDK headers are not covered by its license: re-express API types yourself | license,sdk,psyq,headers,prior-art,firewall | 2026-10-04 | 1.8/T7 | mmx6 W-x4
C0129 | Lib boundaries: tile Ghidra-seeded gaps with a full signature scan; placed objects prune candidates | lib,psyq,signature,boundaries,link,vendor | 2026-10-04 | 1.8/T8 | mmx6 lib lane
C0130 | Propagation registry 'refused' rows go stale when the TU changes; a registry-aware dry run finds them | dedup,registry,propagate,stale,health,refused | 2026-10-04 | 1.8/T14 | mmx6 1.8 close
C0131 | A wipe-then-untar volume refresh has a window with no tree: concurrent compiles need a snapshot | docker,volume,snapshot,concurrency,sync,hardlink | 2026-10-04 | 1.8/T2 | mmx6 campaign
C0132 | Plant a missing input for a self-test by planting it whole, proving the hash, then removing it | self-test,control,plant,index,missing-input | 2026-10-04 | 1.8/T3 | mmx6 campaign
C0133 | An inert control edit must reach the compiler: a code rider, never a comment | control,inert,self-test,preprocessor,lever-credit | 2026-10-04 | 1.8/T4 | mmx6 harvest
C0134 | Gate-tool-safe body spellings: #define for absolute addresses, prototyped params, numeric register pins | typecheck,declsync,verbatim,register-pin,k-and-r,regex | 2026-10-04 | 1.8/T10 | mmx6 W1-W2
C0135 | Sweep statement order for L07 store-order and register-name residuals; retail's order is not the answer | lever,L07,sched,store-order,permutation,sweep,regalloc | 2026-10-04 | 1.8.1/T5 | mmx6 W5
C0136 | do { call(); } while (0) is a haifa-sched barrier that keeps a call's arg move in its delay slot | lever,sched,delay-slot,call,barrier,do-while | 2026-10-04 | 1.8.1/T5 | mmx6 W5
C0137 | Signed-byte spellings: s32 temp + (s8) test, s8 view decrement, (s8) of u8 element, s8 switch, u16 via ori | lever,s8,u8,sign-extension,byte,decrement,switch | 2026-10-04 | 1.8.1/T5 | mmx6 W5
C0138 | A value-in-register shared tail across arms = per-arm constant stores merged by cross-jump, not a shared local | lever,cross-jump,jump2,if-else,tail,store,constant | 2026-10-04 | 1.8.1/T5 | mmx6 W5
C0139 | Load/store order across bases: dead-store deletion, char aliasing, symbol bases decide what the scheduler moves | lever,dead-store,flow,alias,char,sched,store-order | 2026-10-04 | 1.8.1/T5 | mmx6 W5
C0140 | An 8-byte-larger frame with no stack use: an unused s32 pad[2] local | lever,frame,stack,pad,unused-local | 2026-10-04 | 1.8.1/T5 | mmx6 W5
C0141 | Numeric register pins on constants decide which constant loads early when order sweeps cannot | lever,register-pin,regalloc,constant,store-order | 2026-10-05 | 1.8.1/T6 | mmx6 W6
C0142 | One reused s32 local carrying two values orders loads and stores and shares their register | lever,local-reuse,sched,regalloc,global-alloc | 2026-10-05 | 1.8.1/T6 | mmx6 W6
C0143 | Clamp by storing the compare result in the clamp variable and branching on it | lever,clamp,compare,jump,regalloc | 2026-10-05 | 1.8.1/T6 | mmx6 W6
C0144 | An abs() ternary in a range test folds to a negate: nested ifs with a goto to a shared label | lever,abs,ternary,goto,negate,range-test | 2026-10-05 | 1.8.1/T7 | mmx6 W7 rock_08 EAC90
C0145 | Store a computed byte to its field, then re-read the field at each later use instead of a local | lever,reload,field,local,cse,mask | 2026-10-05 | 1.8.1/T7 | mmx6 W7 rock_22 EF5B8
C0146 | Operand order of an add follows the source spelling: e -= -x, (x << 3) not * 8 | lever,operand-order,add,index,shift | 2026-10-05 | 1.8.1/T8 | mmx6 W8 SLUS 32DF0, rock_40 FB378
C0147 | A shared block-scope u8* scratchpad pointer fixes a callee-saved register swap | lever,regalloc,callee-saved,pointer,scratchpad | 2026-10-05 | 1.8.1/T8 | mmx6 W8 rock_21 E9864
C0148 | Read two globals into locals before either adjacent store | lever,alias,order,global,store | 2026-10-05 | 1.8.1/T8 | mmx6 W8 rock_03 F3BE4
C0149 | Pin both values of two adjacent field copies to close a register swap | lever,regalloc,pin,field,copy | 2026-10-06 | 1.8.1/T9 | mmx6 W9 rock_02 F2438
C0150 | Split two stores of one table address around the constant stores; drop the pin | lever,order,store,table,pin,sched | 2026-10-06 | 1.8.1/T9 | mmx6 W9 rock_22 F461C
C0151 | Compare operand order follows the spelling: write x > tbl[i], not tbl[i] < x | lever,operand-order,compare,sched | 2026-10-06 | 1.8.1/T9 | mmx6 W9 rock_02 F612C
C0152 | A divide by a constant compiled as a real divide: put the divisor in a local, the second one late | lever,divide,constant,local,reciprocal,trap | 2026-10-06 | 1.8.1/T10 | mmx6 W10 SLUS 4BB5C
C0153 | A joined value stored to a narrow field lives in an s32 local; a u8/u16 local adds a mask | lever,local,s32,zero-extend,mask,join,byte | 2026-10-06 | 1.8.1/T10 | mmx6 W10 rock_09 ECC10
C0154 | Copy loops: base pointers and offset local declared inside each loop body; aligned tail via __builtin_memcpy | lever,loop,preheader,gcse,hoist,base-pointer,block-scope,memcpy | 2026-10-06 | 1.8.1/T11 | mmx6 W11 SLUS 1BA1C
C0155 | Range-test register swap: inner difference as x = a; x -= b; in a block local | lever,range-test,regalloc,local,difference | 2026-10-06 | 1.8.1/T11 | mmx6 W11 rock_04 F1B50
C0156 | Small switch with equality-only case tests: switch on a u32 index | lever,switch,unsigned,compare-tree,case | 2026-10-09 | 1.8.1/T12 | mmx6 W12 SLUS 2E1A0
C0157 | Small switch compare tree: case bodies in the target's block order | lever,switch,block-order,case-order | 2026-10-09 | 1.8.1/T12 | mmx6 W12 rock_09 EBBD4
C0158 | Pinned copy of a parameter: arg = 0 right after the pin as a cse barrier | lever,register-pin,cse,parameter,callee-saved | 2026-10-09 | 1.8.1/T12 | mmx6 W12 rock_18 EAAC0
C0159 | Field load before an unrelated store: read into an s32 local before that store | lever,load-order,local,store,sched | 2026-10-09 | 1.8.1/T12 | mmx6 W12 rock_15 EC478
C0160 | Loop invariant callee-saved swap: copies through an s32 local raise loop insn_count | lever,loop,invariant,callee-saved,regalloc,hoist,combine | 2026-10-09 | 1.8.1/T12 | mmx6 W12 SLUS 274A0
C0161 | Delay slot holds a call-arg constant: pinned arg-register local set before the test | lever,delay-slot,reorg,register-pin,call,argument | 2026-10-09 | 1.8.1/T12 | mmx6 W12 rock_02 F87FC
C0162 | Callee-saved swap between close pseudos: wrap one use of the winner in do-while(0) | lever,do-while,loop-note,global-alloc,callee-saved,regalloc | 2026-10-09 | 1.8.1/T13 | mmx6 W13 rock_18 EA0E8
C0163 | Abs distance: both differences in s32 locals before the ternary | lever,abs,ternary,local,regalloc | 2026-10-09 | 1.8.1/T13 | mmx6 W13 rock_02 EB924
C0164 | Constant dividend before an abs branch: ABS ternary inside the divide | lever,abs,divide,constant,sched | 2026-10-09 | 1.8.1/T13 | mmx6 W13 rock_08 F2814
C0165 | Multiply by 48 of a call result: m = f()*0x10; x = m*2 + m | lever,multiply,shift,constant,sched | 2026-10-09 | 1.8.1/T14 | mmx6 W14 rock_08 F15E8, rock_03 ED2F4, rock_11 EA84C
C0166 | Real divide with swapped args: dividend in an s32 local set just before the divisor local | lever,divide,local,regalloc,sched | 2026-10-09 | 1.8.1/T14 | mmx6 W14 rock_07 F2D98
C0167 | Switch case-tree pivot: an empty case 0: break; reshapes gcc's compare tree | lever,switch,case-tree,length | 2026-10-09 | 1.8.1/T14 | mmx6 W14 rock_15 F0A78
C0168 | Drop a twin's pin on a zero-initialised flag: its known zero feeds the loop counter | lever,pin,twin,cse,regalloc | 2026-10-09 | 1.8.1/T14 | mmx6 W14 rock_20 EBB30
C0169 | Nested subtract with a constant: hold (b - K) in a numerically pinned local | lever,reassociation,combine,register-pin,subtract | 2026-10-09 | 1.8.1/T15 | mmx6 W15 rock_02 F33C0
C0170 | One dst pointer local reused across both branches keeps one global pseudo | lever,local-reuse,pointer,global-alloc,callee-saved | 2026-10-09 | 1.8.1/T15 | mmx6 W15 rock_09 ED18C
C0171 | Parameter copied to a plain local closes a callee-saved swap with the counter | lever,parameter,local,callee-saved,regalloc | 2026-10-09 | 1.8.1/T15 | mmx6 W15 SLUS 1EE7C, W14 SLUS 1F320
C0172 | First statement after a do-while(0) loop-end note is a barrier: make it the store | lever,do-while,loop-note,sched,barrier | 2026-10-09 | 1.8.1/T15 | mmx6 W15 rock_24 F4790
C0173 | Range-test block order: inverted test goto the shared block, then goto the call | lever,goto,block-order,range-test,if-else | 2026-10-09 | 1.8.1/T16 | mmx6 W16 SLUS 4CD3C, rock_02 EDBB4
C0174 | Table base into a pointer local before a call keeps it callee-saved | lever,callee-saved,regalloc,pointer,table,call | 2026-10-09 | 1.8.1/T16 | mmx6 W16 SLUS 4CD3C, rock_03 F1A3C
C0175 | Fold the load into the compare: if (g < (t = tbl[i])), if (++field == 50) | lever,compare,assignment,load-order,pre-increment,zero-extend | 2026-10-09 | 1.8.1/T16 | mmx6 W16 rock_11 F95C4, rock_09 F45C0
C0176 | Empty case 1 plus goto into an if (0) block sets which case cross-jumps | lever,switch,case-tree,cross-jump,goto,block-order | 2026-10-10 | 1.8.1/T17 | mmx6 W17 rock_07 F50EC
C0177 | Signed /16 with the shift before the sign branch: q = v >> 4; if (v < 0) q = (v + 15) >> 4 | lever,division,shift,rounding,signed | 2026-10-10 | 1.8.1/T17 | mmx6 W17 rock_08 EB098
C0178 | Explicit byte offset, not a cast view, keeps an offset shared across same-shape arrays | lever,array,offset,cse,cast,view-macro | 2026-10-10 | 1.8.1/T17 | mmx6 W17 SLUS 26ECC
C0179 | Byte-field increment temp in the wrong register: pinned s32 block local = f + 1 | lever,increment,register-pin,regalloc,byte | 2026-10-10 | 1.8.1/T17 | mmx6 W17 rock_02 F7570, rock_15 ECC78
C0180 | sym+K row base kept split by an s32 offset local; loop body as a macro argument per arm | lever,loop,hoist,offset-local,macro,sym-plus-k | 2026-10-10 | 1.8.1/T18 | mmx6 W18 SLUS 2BCCC
C0181 | Byte equality chains: one early return per value keeps the beq chain | lever,equality,range-test,switch,beq-chain | 2026-10-10 | 1.8.1/T18 | mmx6 W18 SLUS 3DD6C
C0182 | Pin the compare result via a comma form when the pinned value dies at the compare | lever,register-pin,compare,slti,regalloc,plateau | 2026-10-10 | 1.8.1/T18 | mmx6 W18 rock_08 F2E10, EF7B4
C0183 | Word 0 j-to-hook with stack adjust in its delay slot is a runtime hook site, not a lever | classification,hook,runtime-patch,probe,plateau,word0 | 2026-10-10 | 1.8.1/T18 | mmx6 W18 rock_40 FA15C
C0184 | One-set constant store: write the literal per arm, not via a shared local (sched1 boost) | lever,sched,L07,constant,one-set,store-order | 2026-10-11 | 1.8.1/T19 | mmx6 W19 rock_07 EB114
C0185 | Retail void return: int return keeps v0 live at the exit join and blocks the delay-slot fill | lever,void,return,delay-slot,tusync,R2 | 2026-10-11 | 1.8.1/T19 | mmx6 W19 rock_11 F9F7C, rock_07 F4144
C0186 | Constant stored after several calls: block local set before the first call (callee-saved) | lever,callee-saved,constant,rematerialise,block-local | 2026-10-11 | 1.8.1/T19 | mmx6 W19 rock_20 EB78C
C0187 | Three inlined copies of a routine: one static inline helper called three times | lever,inline,static-inline,helper,R2-risk | 2026-10-11 | 1.8.1/T19 | mmx6 W19 SLUS 1C1AC
C0188 | Decimal digit split: plain / and % let gcc share quotients (counter-case to C0110) | lever,divide,remainder,quotient,digits,callee-saved | 2026-10-11 | 1.8.1/T20 | mmx6 W20 SLUS 190FC
C0189 | Same constant address read across calls: spell the second read through a different base | lever,cse,global,scratchpad,extern,callee-saved,length | 2026-10-11 | 1.8.1/T20 | mmx6 W20 SLUS 3C4EC, rock_09 EC6C4, rock_43 FBB70
C0190 | One call per arm instead of a shared argument local before one call; cross-jump merges | lever,cross-jump,jump2,call,arms,tail | 2026-10-11 | 1.8.1/T20 | mmx6 W20 SLUS 4EA78, rock_04 F351C
C0191 | Retail narrows a parameter at entry: narrow parameter type, TU prototype via tusync | lever,parameter,prototype,tusync,u8,return-type,R2 | 2026-10-11 | 1.8.1/T20 | mmx6 W20 rock_07 F6B94, SLUS 18290
C0192 | Call with no arguments where retail sets no argument register; unprototyped cast if the callee takes one | lever,call,argument,implicit,cast,reconcile,R3 | 2026-10-11 | 1.8.1/T21 | mmx6 W21 rock_09 F32B0, rock_07 F6180
C0193 | Function-table dispatch as (idx << 2) + base cast to a function pointer, not array indexing | lever,dispatch,table,fn-ptr,operand-order,regalloc | 2026-10-11 | 1.8.1/T21 | mmx6 W21 rock_11 F8064
C0194 | Epilogue restores interleaved with the tail: empty barrier before the previous store, tail unbarriered | lever,epilogue,sched,do-while,barrier,tail | 2026-10-11 | 1.8.1/T22 | mmx6 W22 rock_11 F8130
C0195 | Global passed to an unprototyped call: s32 local numerically pinned to the argument register | lever,register-pin,argument,call,global,regalloc | 2026-10-11 | 1.8.1/T22 | mmx6 W22 rock_05 F1788
