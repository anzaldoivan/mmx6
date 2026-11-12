<!-- Cookbook index. One line per entry, appended by tools/cookbook_add.sh. Grep this file by tag or title; never read it whole; never read an entry you did not find here. -->
<!-- C<nnnn> | <title> | <tags> | <date> | <phase>/<task> | origin: <source section or report id> -->
C0001 | The decomp idiom entry shape: residual, mechanism, lever, byte proof | cookbook-format,idiom-shape,residual,mechanism,lever,byte-proof | 2026-10-01 | - | decomp-architect
C0002 | The triage table: diff tell to mechanism to lever family | triage,symptom,tell,spill,register-pressure,aliasing,callee-saved,branch-polarity,cross-jump | 2026-10-01 | - | decomp-architect
C0003 | Offline tooling first: every computable step becomes a zero-token deterministic tool | strategy,deterministic,recovery,permuter,economics,tooling | 2026-10-01 | - | decomp-architect
C0004 | A slow gate is a bug: parallel worktrees, a per-binary lock, the parallel flag on every build | gate,parallel,worktree,lock,build,throughput | 2026-10-01 | - | decomp-architect
C0005 | Breadth is isolated agents: per-item agents cost about linearly, one serial loop about quadratically | breadth,agents,drafting,fan-out,cost | 2026-10-01 | - | decomp-architect
C0006 | Route drafters by a difficulty cliff measured on your own corpus | routing,model-tier,drafting,cliff,escalation,cost | 2026-10-01 | - | decomp-architect
C0007 | dumpsxiso writes XA/STR at 2336 B/sector: compare by sectors, not ISO size | psx,iso9660,xa,str,dumpsxiso,extract | 2026-10-01 | - | carried from dino-crisis-2-decomp C0007
C0008 | dumpsxiso -x dir holds license_data.dat (and DA .WAV): move out before diffing | psx,dumpsxiso,extract,diff,reference | 2026-10-01 | - | carried from dino-crisis-2-decomp C0008
C0009 | fnmatch **/X misses root-level X: add a sibling root glob | firewall,glob,fnmatch,audit | 2026-10-01 | 1.0/T1 | mmx6 T1
C0010 | Pin docker images by config digest, not image Id, under buildx | docker,pin,buildx,reproducibility | 2026-10-01 | 1.0/T2 | mmx6 T2
C0011 | ISO9660 dir-record XA attribute is big-endian. Form 2 = 0x1000, cross-check submode bit 5 | psx,iso9660,xa,form2,extract | 2026-10-01 | 1.1/T1 | mmx6 T1
C0012 | objdump a PS-X EXE as raw binary with --adjust-vma=load-0x800. Keep the listing in .run | psx,mips,objdump,exe,disassembly | 2026-10-01 | 1.1/T2 | mmx6 T2
C0013 | dumpsxiso also writes an XML project into its cwd. Move it out before a diff | psx,dumpsxiso,extract,diff,reference | 2026-10-01 | 1.1/T4 | mmx6 T4
C0014 | Ghidra headless: preScript setAnalysisOption does not disable a psx_ldr analyzer. Use -noanalysis as the control | ghidra,psx_ldr,headless,analysis,negative-control | 2026-10-01 | 1.2/T1 | mmx6 T1
C0015 | GhidrAssistMCP headless: stop via completion_file so the project saves. A kill of the JVM skips the save | ghidra,mcp,ghidrassistmcp,headless,save | 2026-10-01 | 1.2/T2 | mmx6 T2
C0016 | Ghidra headless refuses project paths with a dot-leading element. Reach the .run/ scratch via a symlink | ghidra,headless,project,path | 2026-10-01 | 1.2/T3 | mmx6 T3
C0017 | analyzeHeadless exits 0 when a script prints an error and returns. Grep the script's error marker | ghidra,headless,exit-code,wrapper | 2026-10-01 | 1.2/T3 | mmx6 T3
C0018 | PCSX-Redux on macOS arm64 crashes under the dynarec headless. Run with -interpreter | pcsx-redux,macos,arm64,headless,interpreter | 2026-10-01 | 1.2/T4 | mmx6 T4
C0019 | PCSX-Redux Lua Exec breakpoints never fire without -debugger | pcsx-redux,lua,breakpoint,debugger | 2026-10-01 | 1.2/T4 | mmx6 T4
C0020 | PCSX-Redux -portable keeps config in the run dir. With spu.Speed = 0, the emulator runs unthrottled | pcsx-redux,portable,speed,headless | 2026-10-01 | 1.2/T4 | mmx6 T4
C0021 | Ghidra function starts without extents over-include data tails. Trim to the last jr ra + delay slot | ghidra,export,function-extent,mips,compare | 2026-10-01 | 1.2/T4 | mmx6 T4
C0022 | PCSX-Redux Lua pad input: SIO0.slots[1].pads[1].setOverride/clearOverride | pcsx-redux,lua,pad,input | 2026-10-01 | 1.2/T5 | mmx6 T5
C0023 | The macOS host has no MIPS objdump. Disassemble in the build container or decode words in the tool | macos,mips,objdump,disassembly,container | 2026-10-01 | 1.2/T6 | mmx6 T6
C0024 | Ghidra BinaryLoader headless -loader-baseAddr can leave image_base 0. Import at 0 and setImageBase in a preScript | ghidra,binaryloader,image-base,headless,overlay | 2026-10-01 | 1.2/T7 | mmx6 T7
C0025 | Ghidra multi-import JVM: the per-program analysis summary is missing from the log. Check the per-program artifacts | ghidra,headless,batch,log,verification | 2026-10-01 | 1.2/T7 | mmx6 T7
C0026 | Ghidra may emit switchdataD_ labels every 8 B inside one switch table. Merge the labels within a bounded table | ghidra,switch,jump-table,labels,boundaries | 2026-10-01 | 1.2/T8 | mmx6 T8
C0027 | make target failure rc is 2, not 1 | make,gates | 2026-10-01 | 1.3/T1 | -
C0028 | splat symbol_addrs parses trailing // comments | splat,symbols | 2026-10-01 | 1.3/T2 | -
C0029 | .DELETE_ON_ERROR for rules ending in a hash check | make,hash,gates | 2026-10-01 | 1.3/T2 | -
C0030 | Count TUs from forced edges before editing yaml | segmentation,splat | 2026-10-01 | 1.3/T3 | -
C0031 | splat psx many asm subsegments: subalign 4 | splat,psx,linker,hash | 2026-10-01 | 1.3/T4 | -
C0032 | mipsel as inserts sync before ll: -mno-fix-loongson3-llsc | binutils,mips,asm | 2026-10-01 | 1.3/T5 | -
C0033 | All-asm overlays: data words through gas need -march=r4000 | binutils,mips,overlays | 2026-10-01 | 1.3/T5 | -
C0034 | A gate that must re-hash needs a clean step | make,hash,gates | 2026-10-01 | 1.3/T6 | -
C0035 | A cpp|cc1|maspsx|as pipe returns only as's rc. A dead cc1 still exits 0 | make,pipefail,toolchain,psx | 2026-10-01 | 1.4/T1 | mmx6 T1
C0036 | Ubuntu make recipes run under dash (no pipefail). Set SHELL bash + .SHELLFLAGS per target | make,pipefail,dash,ubuntu | 2026-10-01 | 1.4/T2 | mmx6 T2
C0037 | cpp 12 -nostdinc drops the stdc-predef.h pre-include that old gcc 2.x cc1 warns on | cpp,old-gcc,cc1,psx | 2026-10-01 | 1.4/T2 | mmx6 T2
C0038 | An INCLUDE_ASM probe control is triple-independent. Pair it with a planted one-word mutation | probe,control,compare,masking | 2026-10-01 | 1.4/T3 | mmx6 T3
C0039 | asm-differ arch mips is big-endian. PSX needs mipsel (m2c target mipsel-gcc-c) | asm-differ,m2c,mips,endianness,psx | 2026-10-01 | 1.4/T4 | mmx6 T4
C0040 | make -j extract build races. Run extract as its own make call first | make,parallel,extract,race | 2026-10-01 | 1.4/T4 | mmx6 T4
C0041 | splat's instruction comment word is in file byte order. Decode as little-endian before field extraction | splat,mips,decode,endianness | 2026-10-01 | 1.4/T5 | mmx6 T5
C0042 | A splat asm subsegment can come out as dlabel + .word with 0 glabel. Per-function tools must detect it | splat,spimdisasm,census,functions | 2026-10-01 | 1.4/T5 | mmx6 T5
C0043 | A break 7 near a div is not an expanded-div test. Classify by break 6 presence and mflo position | mips,division,maspsx,expand-div,fingerprint | 2026-10-01 | 1.4/T6 | mmx6 T6
C0044 | maspsx aspsx-version rungs >= 2.60 are byte-identical under -G0 with no $gp access | maspsx,aspsx,pin,ladder,psx | 2026-10-01 | 1.4/T6 | mmx6 T6
C0045 | A trailing # comment on a make VAR ?= value line keeps the space before # in the value | make,variables,comments | 2026-10-01 | 1.4/T6.1 | mmx6 T6.1
C0046 | splat 0.50 c-mode writes a jr ra + nop function as empty C. Measure the stub-only baseline before banking | splat,c-mode,count,baseline | 2026-10-01 | 1.4/T8 | mmx6 T8
C0047 | Once a function is C, splat writes no nonmatchings .s for it. Extent tools must fall back to symbol order | splat,nonmatchings,extent,probe | 2026-10-01 | 1.4/T8 | mmx6 T8
C0048 | spimdisasm farthestBranch survives function ends. Declare sized func symbols | splat,spimdisasm,overlay,boundaries | 2026-10-01 | 1.5/T1 | T1 overlay 0-glabel fix
C0049 | jr ra count overcounts functions (multi-return) | boundaries,census,mips | 2026-10-01 | 1.5/T1 | T1
C0050 | Coverage oracle: closed set of uncovered-byte kinds with precedence | oracle,coverage,corpus | 2026-10-01 | 1.5/T2 | T2 corpus spans
C0051 | Narrowing control from the real population (hide one input dir) | self-test,control,scanner | 2026-10-01 | 1.5/T3 | T3 optscan
C0052 | Post-return start rule chains through data. Scope it | boundaries,bound2,data | 2026-10-01 | 1.5/T4 | T4 bound2
C0053 | spimdisasm ends sized symbols only at size >= 8 | splat,spimdisasm,symbols | 2026-10-01 | 1.5/T5 | T5 symbols
C0054 | Self-test controls inject disagreements, never borrow real ones | self-test,control | 2026-10-01 | 1.5/T5 | T5 bound2 ledger
C0055 | Dup census: load-bearing-mask control (twin must split unmasked) | census,duplicates,control | 2026-10-01 | 1.5/T6 | T6 census
C0056 | Report over a census: currency guard plus planted mutation | report,census,control | 2026-10-01 | 1.5/T7 | T7 report
C0057 | Harness pair whose instrument never ran is NOT-RUN, counted as disagreement | harness,differential,control | 2026-10-01 | 1.5/T8 | T8 harness P3
C0058 | Splat can fuse dozens of real functions into one, so check B2 starts strictly inside each function | boundaries,splat,spimdisasm,merge,bound2 | 2026-10-01 | 1.6/T1 | mmx6 T1
C0059 | Code after an interior jr ra reached by no edge is its own function, and splitting is byte-neutral | boundaries,mips,multi-return,merge | 2026-10-01 | 1.6/T1 | mmx6 T1
C0060 | Near-duplicate band: lossless prefilter by length and opcode-histogram bounds | twins,near-dup,edit-distance,census | 2026-10-01 | 1.6/T2 | mmx6 T2
C0061 | Moving a type to a shared header: remove its copies from probe sources too | types,header,probe,common.h | 2026-10-01 | 1.6/T3 | mmx6 T3
C0062 | A masked standalone match can name the wrong symbol, and only the whole-binary hash catches it | probe,masking,relocation,bank | 2026-10-01 | 1.6/T4 | mmx6 T4
C0063 | Format a body before the first probe, because clang-format changes its sha1 afterwards | clang-format,bank,sha1 | 2026-10-01 | 1.6/T4 | mmx6 T4
C0064 | Verify c-unit conversions from a clean sync, because splat skips .s for functions only named D_<addr> | splat,c-unit,nonmatchings,overlay | 2026-10-01 | 1.6/T5 | mmx6 T5
C0065 | Parameterise a shared body per member with name #defines, then gate with an unmasked linked compare | dedup,propagate,define,relocation | 2026-10-01 | 1.6/T5 | mmx6 T5
C0066 | Plant a self-test precondition that real progress consumed, then prove the plant by the binary hash | self-test,control,plant | 2026-10-01 | 1.6/T6.1 | mmx6 T6.1
C0067 | A corpus regeneration rewrites several outputs together, so scratch runs save and restore all of them | corpus,scratch,self-test | 2026-10-01 | 1.6/T6.1 | mmx6 T6.1
C0068 | A planted .word .s must span the corpus extent to its end, or the link shifts | plant,probe,extent,link | 2026-10-01 | 1.6/T6.1 | mmx6 T6.1
C0069 | splat pairs rodata with a c unit only as type .rodata. Derive the dispatcher from %hi | splat,rodata,jtbl,carve | 2026-10-01 | 1.6/T6 | mmx6 T6
C0070 | Splitting a c unit must rewrite the moved INCLUDE_ASM folders to the new unit | splat,carve,include_asm,nonmatchings | 2026-10-01 | 1.6/T6 | mmx6 T6
C0071 | Family-only siblings differ in a non-relocated field. Relocation remap gates few | family,remap,dedup,relocation | 2026-10-01 | 1.6/T7 | mmx6 T7
C0072 | #define A B with #define B A collapses under cpp rescanning. Refuse such mappings | cpp,define,remap | 2026-10-01 | 1.6/T7 | mmx6 T7
C0073 | Test sibling-game sharing under the target's compiler pin. Vary only the compiler as the control | prior-art,sibling-game,pin,control | 2026-10-01 | 1.6/T8 | mmx6 T8
C0074 | Draw filter over a twin graph: at most one member per connected component per wave | draw,twins,wave,routing | 2026-10-01 | 1.6/T9 | mmx6 T9
C0075 | Global reloaded after *p= but kept after p[k]=/p->f= (cse /s aliasing) | idiom,sym-global-reload,G-expr,cse,aliasing,reload | 2026-10-01 | 1.7/T4 | mmx6 repro
C0076 | &local cached in $s0 via a named pointer vs per-site addiu (call args) | idiom,sym-phantom-callee-saved,G-expr,rtl,callee-saved,address | 2026-10-01 | 1.7/T4 | mmx6 repro
C0077 | Up-count loop reversed to bgez. Write the down-count for bgtz/bne | idiom,sym-loop-reversed,G-loop,loop,dbra,branch | 2026-10-01 | 1.7/T4 | mmx6 repro
C0078 | lw+andi 0xff vs lbu: combine merges the mask only if the word dies | idiom,sym-narrow-load,G-combine,combine,lbu,mask | 2026-10-01 | 1.7/T4 | mmx6 repro
C0079 | $16/$17 swapped at equal priority: declaration order breaks the global-alloc tie | idiom,sym-sreg-swapped,G-alloc,greg,regalloc,decl-order | 2026-10-02 | 1.7/T5 | mmx6 repro
C0080 | $16/$17 swapped by ref count: global-alloc density floor_log2(refs)*refs/live | idiom,sym-sreg-swapped,G-alloc,greg,regalloc,refs | 2026-10-02 | 1.7/T5 | mmx6 repro
C0081 | Load held below *p= but hoisted above p->f= (sched /s aliasing) | idiom,sym-load-below-store,G-sched,sched,aliasing,order | 2026-10-02 | 1.7/T5 | mmx6 repro
C0082 | beqz vs bnez: the if arm falls through. Invert the condition and swap the arms | idiom,sym-branch-arms-swapped,G-jump,jump,polarity,branch | 2026-10-02 | 1.7/T5 | mmx6 repro
C0083 | Cross-jump: a fall-through arm ending in a call never merges. A store tail merges the call | idiom,sym-cross-jump,G-jump,jump2,cross-jump,call | 2026-10-02 | 1.7/T5 | mmx6 repro
C0084 | Index sll 2 vs none: p[i] on int * scales, a char * byte offset does not | idiom,sym-shift-x4,G-expr,rtl,pointer,shift | 2026-10-02 | 1.7/T5 | mmx6 repro
C0085 | Spill slots swapped: reload assigns slots in pseudo (declaration) order | idiom,sym-spill-slot,G-alloc,greg,spill,decl-order | 2026-10-02 | 1.7/T5 | mmx6 repro
C0086 | Struct base reloaded per member store: name the pointer-derived base in a local | idiom,sym-global-reload,G-expr,cse,alias,struct | 2026-10-02 | 1.7/T6 | BFM §193-H re-proven
C0087 | Loop guard: while copies its exit test as the guard. A written guard + do-while keeps yours | idiom,sym-loop-reversed,G-jump,jump,loop,guard | 2026-10-02 | 1.7/T6 | BFM §279 re-proven
C0088 | lhu vs lh on a masked short: & in the expression is shortened. An int temp keeps lh | idiom,sym-narrow-load,G-expr,rtl,shorten,short | 2026-10-02 | 1.7/T6 | BFM §329 re-proven
C0089 | Volatile short read: lhu + sll/sra instead of lh (combine skips volatile) | idiom,sym-narrow-load,G-combine,combine,volatile,short | 2026-10-02 | 1.7/T6 | BFM §345 re-proven
C0090 | A release archive's sha256 is not its binary's. Prove a binary by the extracted file | pin,hash,toolchain,provenance | 2026-10-02 | 1.7/T1 | mmx6 T1
C0091 | decompals/old-gcc releases rebuild bit-identical from the tag's Dockerfile on a pinned focal base | toolchain,provenance,gcc,docker,pin | 2026-10-02 | 1.7/T1 | mmx6 T1
C0092 | Target-specific make vars are invisible to other targets: splice make -n -B's recipe line | make,toolchain,flags,dumps | 2026-10-02 | 1.7/T2 | mmx6 T2
C0093 | Prove an instrumented compile matches the build by diffing .text bytes, not RTL insn counts | toolchain,dumps,control,gcc | 2026-10-02 | 1.7/T2 | mmx6 T2
C0094 | Line-numbered citations into C sources: split on \n only, never str.splitlines() | python,citations,gcc,self-test | 2026-10-02 | 1.7/T3 | mmx6 T3
C0095 | Allocation-order reproducers must keep values live across a block boundary | gcc,greg,regalloc,reproducer | 2026-10-02 | 1.7/T3 | mmx6 T3
C0096 | Pipe-delimited rows break on citation fragments containing a pipe | docs,format,citations | 2026-10-02 | 1.7/T4 | mmx6 T4
C0097 | The same C idiom can move pass between gcc versions: re-prove, never port the citation | gcc,G67,citations,porting | 2026-10-02 | 1.7/T4 | mmx6 T4
C0098 | A spill-slot swap lever cannot be a pure order diff: declare a length 0 diff | reproducer,spill,G-alloc,diff | 2026-10-02 | 1.7/T5 | mmx6 T5
C0099 | Inherited gcc 2.7.2 idioms often go byte-identical under 2.95.2: reproduce before entering | gcc,porting,BFM,reproducer | 2026-10-02 | 1.7/T6 | mmx6 T6
C0100 | decomp-permuter --seed random-walks one candidate, and seed 0 means unseeded | permuter,seed,random | 2026-10-02 | 1.7/T7 | mmx6 T7
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
C0124 | m2c guesses callee arity per body: call through an unprototyped cast. Trust the TU's consensus declaration | m2c,prototype,arity,cast,declaration,scaffold | 2026-10-04 | 1.8/T5 | mmx6 scaffold lane, W4
C0125 | PSX overlays repeat function names across programs: key per-function scratch by program | psx,overlay,scratch,parallel,naming,race | 2026-10-04 | 1.8/T5 | mmx6 scaffold lane
C0126 | A family differing in one non-relocated immediate gates from one match by a macro-parameterised body | dedup,family,macro,parameterised,propagate,immediate | 2026-10-04 | 1.8/T6 | mmx6 W-fam
C0127 | Port a sibling game's matched C by aligning relocations word-by-word to rename symbols | prior-art,port,relocation,sibling,x4,symbols | 2026-10-04 | 1.8/T7 | mmx6 W-x4
C0128 | A sibling decomp's vendored SDK headers are not covered by its license: re-express API types yourself | license,sdk,psyq,headers,prior-art,firewall | 2026-10-04 | 1.8/T7 | mmx6 W-x4
C0129 | Lib boundaries: tile Ghidra-seeded gaps with a full signature scan. Placed objects prune candidates | lib,psyq,signature,boundaries,link,vendor | 2026-10-04 | 1.8/T8 | mmx6 lib lane
C0130 | Propagation registry 'refused' rows go stale when the TU changes. A registry-aware dry run finds them | dedup,registry,propagate,stale,health,refused | 2026-10-04 | 1.8/T14 | mmx6 1.8 close
C0131 | A wipe-then-untar volume refresh has a window with no tree: concurrent compiles need a snapshot | docker,volume,snapshot,concurrency,sync,hardlink | 2026-10-04 | 1.8/T2 | mmx6 campaign
C0132 | Plant a missing input for a self-test by planting it whole, proving the hash, then removing it | self-test,control,plant,index,missing-input | 2026-10-04 | 1.8/T3 | mmx6 campaign
C0133 | An inert control edit must reach the compiler: a code rider, never a comment | control,inert,self-test,preprocessor,lever-credit | 2026-10-04 | 1.8/T4 | mmx6 harvest
C0134 | Gate-tool-safe body spellings: #define for absolute addresses, prototyped params, numeric register pins | typecheck,declsync,verbatim,register-pin,k-and-r,regex | 2026-10-04 | 1.8/T10 | mmx6 W1-W2
C0135 | Sweep statement order for L07 store-order and register-name residuals. Retail's order is not the answer | lever,L07,sched,store-order,permutation,sweep,regalloc | 2026-10-04 | 1.8.1/T5 | mmx6 W5
C0136 | `do { call(); } while (0)` is a haifa-sched barrier that keeps a call's arg move in its delay slot | lever,sched,delay-slot,call,barrier,do-while | 2026-10-04 | 1.8.1/T5 | mmx6 W5
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
C0150 | Split two stores of one table address around the constant stores, and drop the pin | lever,order,store,table,pin,sched | 2026-10-06 | 1.8.1/T9 | mmx6 W9 rock_22 F461C
C0151 | Compare operand order follows the spelling: write x > tbl[i], not tbl[i] < x | lever,operand-order,compare,sched | 2026-10-06 | 1.8.1/T9 | mmx6 W9 rock_02 F612C
C0152 | A divide by a constant compiled as a real divide: put the divisor in a local, the second one late | lever,divide,constant,local,reciprocal,trap | 2026-10-06 | 1.8.1/T10 | mmx6 W10 SLUS 4BB5C
C0153 | A joined value stored to a narrow field lives in an s32 local. A u8/u16 local adds a mask | lever,local,s32,zero-extend,mask,join,byte | 2026-10-06 | 1.8.1/T10 | mmx6 W10 rock_09 ECC10
C0154 | Copy loops: base pointers and offset local declared inside each loop body, and an aligned tail via __builtin_memcpy | lever,loop,preheader,gcse,hoist,base-pointer,block-scope,memcpy | 2026-10-06 | 1.8.1/T11 | mmx6 W11 SLUS 1BA1C
C0155 | Range-test register swap: inner difference as x = a then x -= b in a block local | lever,range-test,regalloc,local,difference | 2026-10-06 | 1.8.1/T11 | mmx6 W11 rock_04 F1B50
C0156 | Small switch with equality-only case tests: switch on a u32 index | lever,switch,unsigned,compare-tree,case | 2026-10-09 | 1.8.1/T12 | mmx6 W12 SLUS 2E1A0
C0157 | Small switch compare tree: case bodies in the target's block order | lever,switch,block-order,case-order | 2026-10-09 | 1.8.1/T12 | mmx6 W12 rock_09 EBBD4
C0158 | Pinned copy of a parameter: arg = 0 right after the pin as a cse barrier | lever,register-pin,cse,parameter,callee-saved | 2026-10-09 | 1.8.1/T12 | mmx6 W12 rock_18 EAAC0
C0159 | Field load before an unrelated store: read into an s32 local before that store | lever,load-order,local,store,sched | 2026-10-09 | 1.8.1/T12 | mmx6 W12 rock_15 EC478
C0160 | Loop invariant callee-saved swap: copies through an s32 local raise loop insn_count | lever,loop,invariant,callee-saved,regalloc,hoist,combine | 2026-10-09 | 1.8.1/T12 | mmx6 W12 SLUS 274A0
C0161 | Delay slot holds a call-arg constant: pinned arg-register local set before the test | lever,delay-slot,reorg,register-pin,call,argument | 2026-10-09 | 1.8.1/T12 | mmx6 W12 rock_02 F87FC
C0162 | Callee-saved swap between close pseudos: wrap one use of the winner in do-while(0) | lever,do-while,loop-note,global-alloc,callee-saved,regalloc | 2026-10-09 | 1.8.1/T13 | mmx6 W13 rock_18 EA0E8
C0163 | Abs distance: both differences in s32 locals before the ternary | lever,abs,ternary,local,regalloc | 2026-10-09 | 1.8.1/T13 | mmx6 W13 rock_02 EB924
C0164 | Constant dividend before an abs branch: ABS ternary inside the divide | lever,abs,divide,constant,sched | 2026-10-09 | 1.8.1/T13 | mmx6 W13 rock_08 F2814
C0165 | Multiply by 48 of a call result: `m = f()*0x10; x = m*2 + m` | lever,multiply,shift,constant,sched | 2026-10-09 | 1.8.1/T14 | mmx6 W14 rock_08 F15E8, rock_03 ED2F4, rock_11 EA84C
C0166 | Real divide with swapped args: dividend in an s32 local set just before the divisor local | lever,divide,local,regalloc,sched | 2026-10-09 | 1.8.1/T14 | mmx6 W14 rock_07 F2D98
C0167 | Switch case-tree pivot: an empty `case 0: break;` reshapes gcc's compare tree | lever,switch,case-tree,length | 2026-10-09 | 1.8.1/T14 | mmx6 W14 rock_15 F0A78
C0168 | Drop a twin's pin on a zero-initialised flag: its known zero feeds the loop counter | lever,pin,twin,cse,regalloc | 2026-10-09 | 1.8.1/T14 | mmx6 W14 rock_20 EBB30
C0169 | Nested subtract with a constant: hold (b - K) in a numerically pinned local | lever,reassociation,combine,register-pin,subtract | 2026-10-09 | 1.8.1/T15 | mmx6 W15 rock_02 F33C0
C0170 | One dst pointer local reused across both branches keeps one global pseudo | lever,local-reuse,pointer,global-alloc,callee-saved | 2026-10-09 | 1.8.1/T15 | mmx6 W15 rock_09 ED18C
C0171 | Parameter copied to a plain local closes a callee-saved swap with the counter | lever,parameter,local,callee-saved,regalloc | 2026-10-09 | 1.8.1/T15 | mmx6 W15 SLUS 1EE7C, W14 SLUS 1F320
C0172 | First statement after a do-while(0) loop-end note is a barrier: make it the store | lever,do-while,loop-note,sched,barrier | 2026-10-09 | 1.8.1/T15 | mmx6 W15 rock_24 F4790
C0173 | Range-test block order: inverted test goto the shared block, then goto the call | lever,goto,block-order,range-test,if-else | 2026-10-09 | 1.8.1/T16 | mmx6 W16 SLUS 4CD3C, rock_02 EDBB4
C0174 | Table base into a pointer local before a call keeps it callee-saved | lever,callee-saved,regalloc,pointer,table,call | 2026-10-09 | 1.8.1/T16 | mmx6 W16 SLUS 4CD3C, rock_03 F1A3C
C0175 | Fold the load into the compare: if (g < (t = tbl[i])), if (++field == 50) | lever,compare,assignment,load-order,pre-increment,zero-extend | 2026-10-09 | 1.8.1/T16 | mmx6 W16 rock_11 F95C4, rock_09 F45C0
C0176 | Empty case 1 plus goto into an if (0) block sets which case cross-jumps | lever,switch,case-tree,cross-jump,goto,block-order | 2026-10-10 | 1.8.1/T17 | mmx6 W17 rock_07 F50EC
C0177 | Signed /16 with the shift before the sign branch: `q = v >> 4; if (v < 0) q = (v + 15) >> 4` | lever,division,shift,rounding,signed | 2026-10-10 | 1.8.1/T17 | mmx6 W17 rock_08 EB098
C0178 | Explicit byte offset, not a cast view, keeps an offset shared across same-shape arrays | lever,array,offset,cse,cast,view-macro | 2026-10-10 | 1.8.1/T17 | mmx6 W17 SLUS 26ECC
C0179 | Byte-field increment temp in the wrong register: pinned s32 block local = f + 1 | lever,increment,register-pin,regalloc,byte | 2026-10-10 | 1.8.1/T17 | mmx6 W17 rock_02 F7570, rock_15 ECC78
C0180 | sym+K row base kept split by an s32 offset local, and the loop body as a macro argument per arm | lever,loop,hoist,offset-local,macro,sym-plus-k | 2026-10-10 | 1.8.1/T18 | mmx6 W18 SLUS 2BCCC
C0181 | Byte equality chains: one early return per value keeps the beq chain | lever,equality,range-test,switch,beq-chain | 2026-10-10 | 1.8.1/T18 | mmx6 W18 SLUS 3DD6C
C0182 | Pin the compare result via a comma form when the pinned value dies at the compare | lever,register-pin,compare,slti,regalloc,plateau | 2026-10-10 | 1.8.1/T18 | mmx6 W18 rock_08 F2E10, EF7B4
C0183 | Word 0 j-to-hook with stack adjust in its delay slot is a runtime hook site, not a lever | classification,hook,runtime-patch,probe,plateau,word0 | 2026-10-10 | 1.8.1/T18 | mmx6 W18 rock_40 FA15C
C0184 | One-set constant store: write the literal per arm, not via a shared local (sched1 boost) | lever,sched,L07,constant,one-set,store-order | 2026-10-11 | 1.8.1/T19 | mmx6 W19 rock_07 EB114
C0185 | Retail void return: int return keeps v0 live at the exit join and blocks the delay-slot fill | lever,void,return,delay-slot,tusync,R2 | 2026-10-11 | 1.8.1/T19 | mmx6 W19 rock_11 F9F7C, rock_07 F4144
C0186 | Constant stored after several calls: block local set before the first call (callee-saved) | lever,callee-saved,constant,rematerialise,block-local | 2026-10-11 | 1.8.1/T19 | mmx6 W19 rock_20 EB78C
C0187 | Three inlined copies of a routine: one static inline helper called three times | lever,inline,static-inline,helper,R2-risk | 2026-10-11 | 1.8.1/T19 | mmx6 W19 SLUS 1C1AC
C0188 | Decimal digit split: plain / and % let gcc share quotients (counter-case to C0110) | lever,divide,remainder,quotient,digits,callee-saved | 2026-10-11 | 1.8.1/T20 | mmx6 W20 SLUS 190FC
C0189 | Same constant address read across calls: spell the second read through a different base | lever,cse,global,scratchpad,extern,callee-saved,length | 2026-10-11 | 1.8.1/T20 | mmx6 W20 SLUS 3C4EC, rock_09 EC6C4, rock_43 FBB70
C0190 | One call per arm instead of a shared argument local before one call (cross-jump merges) | lever,cross-jump,jump2,call,arms,tail | 2026-10-11 | 1.8.1/T20 | mmx6 W20 SLUS 4EA78, rock_04 F351C
C0191 | Retail narrows a parameter at entry: narrow parameter type, TU prototype via tusync | lever,parameter,prototype,tusync,u8,return-type,R2 | 2026-10-11 | 1.8.1/T20 | mmx6 W20 rock_07 F6B94, SLUS 18290
C0192 | Call with no arguments where retail sets no argument register (unprototyped cast if the callee takes one) | lever,call,argument,implicit,cast,reconcile,R3 | 2026-10-11 | 1.8.1/T21 | mmx6 W21 rock_09 F32B0, rock_07 F6180
C0193 | Function-table dispatch as (idx << 2) + base cast to a function pointer, not array indexing | lever,dispatch,table,fn-ptr,operand-order,regalloc | 2026-10-11 | 1.8.1/T21 | mmx6 W21 rock_11 F8064
C0194 | Epilogue restores interleaved with the tail: empty barrier before the previous store, tail unbarriered | lever,epilogue,sched,do-while,barrier,tail | 2026-10-11 | 1.8.1/T22 | mmx6 W22 rock_11 F8130
C0195 | Global passed to an unprototyped call: s32 local numerically pinned to the argument register | lever,register-pin,argument,call,global,regalloc | 2026-10-11 | 1.8.1/T22 | mmx6 W22 rock_05 F1788
C0196 | Abs as a ternary inside the range compare when the constant lands in the branch delay slot | lever,abs,ternary,compare,sched,delay-slot | 2026-10-12 | 1.8.1/T23 | mmx6 W23 rock_10 F990C
C0197 | Negative constant to a u16 field: store through an s16 view for a sign-extended load | lever,s16,u16,constant,sign-extend,view-macro | 2026-10-12 | 1.8.1/T23 | mmx6 W23 rock_22 EB104
C0198 | Fixed-count loop as an explicit down-counter to -1, not while (k--) | lever,loop,down-count,counter,regalloc | 2026-10-12 | 1.8.1/T23 | mmx6 W23 SLUS 2C530
C0199 | Zero test of a decremented s16 global as !(g & 0xFFFF) for the zero-extend form | lever,s16,zero-test,mask,zero-extend,counter | 2026-10-12 | 1.8.1/T24 | mmx6 W24 rock_04 F4C68
C0200 | Early return on the zero case then a flat body: per-arm returns, no frame | lever,early-return,epilogue,frame,join,sched | 2026-10-12 | 1.8.1/T24 | mmx6 W24 SLUS 3EB0C, 1FD10
C0201 | Static inline helper for constant stores plus a final call gives early argument setup | lever,static-inline,sched,call-args,store-order | 2026-10-12 | 1.8.1/T25 | mmx6 W25 rock_02 F5208
C0202 | Dead store to the original keeps a loop base copy gcse would propagate | lever,gcse,loop,copy,dead-store,regalloc | 2026-10-12 | 1.8.1/T25 | mmx6 W25 rock_16 E99A4
C0203 | Assign the working pointer from the parameter on each path, not one entry copy | lever,parameter,callee-saved,copy,regalloc | 2026-10-12 | 1.8.1/T25 | mmx6 W25 rock_09 F49C8
C0204 | Plain while loop where m2c's if + do-while builds a global's high base twice | lever,loop,while,do-while,hi-lo,global,length | 2026-10-13 | 1.8.1/T26 | mmx6 W26 SLUS 15C5C
C0205 | Loop end bound spelled as the pool base plus its size, not an end symbol | lever,loop,bound,global,hi-lo,reloc,twin | 2026-10-13 | 1.8.1/T26 | mmx6 W26 SLUS 2C32C
C0206 | Read globals and fields into s32 block locals before the call or store that fixes load order | lever,load-order,local,s32,call,sched,regalloc | 2026-10-13 | 1.8.1/T27 | mmx6 W27 SLUS 41290
C0207 | Assign a call-free local after the call's early-return test, not at function entry | lever,callee-saved,regalloc,constant,pointer,call,sched | 2026-10-13 | 1.8.1/T27 | mmx6 W27 rock_07 F036C
C0208 | Constant-address view macro at each access, not an extern symbol or cached pointer local | lever,view-macro,global,cse,hi-lo,reload,constant-address,registry-drift | 2026-10-13 | 1.8.1/T27 | mmx6 W27 SLUS 21500
C0209 | Byte or field read for a test: block local numerically pinned to the first return register | lever,register-pin,regalloc,load,byte,field,compare | 2026-10-13 | 1.8.1/T28 | mmx6 W28 rock_22 F259C
C0210 | sym+K row base: scaled index into an s32 local after the base copy, +K add last | lever,sym-plus-k,sched,hi-lo,offset-local,statement-order | 2026-10-18 | 1.8.1/T40.5 | mmx6 W45 SLUS 80016704
C0211 | Three-temp register rotation that will not close: a 4th coalescing block local | lever,regalloc,local-alloc,block-local,rotation,byte | 2026-10-18 | 1.8.1/T40.5 | mmx6 W45 SLUS 8001B984
C0212 | Pinned pointer base added index-first: write b -= -i | lever,cse,pointer,operand-order,negated-subtract,regalloc | 2026-10-18 | 1.8.1/T40.6 | mmx6 W46 SLUS 8001A4FC
C0213 | Descending row clear, counter init too early: forward counter plus separate descending index | lever,loop,loop-reversal,sched,hoist,biv,giv | 2026-10-18 | 1.8.1/T40.6 | mmx6 W46 SLUS 8002B2F8
C0214 | Table+index sum: fresh pointer local p = i + t, empty do-while(0) after base copy, mask last | lever,pointer,table,regalloc,do-while,statement-order,sched | 2026-10-18 | 1.8.1/T40.10 | mmx6 W50 SLUS 800533F4
C0215 | Rodata carve or banking moves a census dup key: re-key the registry row | registry,rodata,carve,dedup,census,propagate | 2026-10-24 | 1.8.1/T10 | 1.8.1 wave gotchas T10,T13,T15,T5,T40.9-T44
C0216 | Gate R2 conflict: read the conflicting-types line, fix the TU prototype | gate,declaration,r2,declsync,prototype,triage | 2026-10-24 | 1.8.1/T14 | 1.8.1 wave gotchas T14,T3,T34,T37,T40.9,T40.20
C0217 | Near-member chains: re-head per bank, draft the head with its members | draw,near-member,wave,chain,routing,campaign | 2026-10-24 | 1.8.1/T40.15.1.1 | 1.8.1 wave gotchas T40.15-T40.25
C0218 | Gate clang-format reflows debt markers and bare macro bodies | clang-format,debt-marker,fake,gate,macro,format | 2026-10-24 | 1.8.1/T27 | 1.8.1 wave gotchas T27,T30,T31,T40.21
C0219 | Draw ledger and wave draw must share one pick function | ledger,draw,routing,member-of,undrawn,campaign | 2026-10-24 | 1.8.1/T2 | 1.8.1 wave gotchas T2,T40.12,T40.21
C0220 | Gate rodata recovery writes several carve files: pull all before sync | gate,rodata,carve,recovery,sync,registry | 2026-10-24 | 1.8.1/T35 | 1.8.1 wave gotchas T35,T40.17
C0221 | Recovery and reconcile passes: re-declare what earlier steps dropped | recovery,declaration,reconcile,gate,cast,prelude | 2026-10-24 | 1.8.1/T3 | 1.8.1 wave gotchas T3,T40.12
C0222 | Probe and plateau scores are not the gate verdict | probe,plateau,gate,scoring,length,order | 2026-10-24 | 1.8.1/T25 | 1.8.1 wave gotchas T25,T26,T38
C0223 | Rung scheduling: the largest group is the wall-time floor | campaign,scheduling,wall-time,self-test,rungs,sampling | 2026-10-24 | 1.8.1/T41.1.1 | 1.8.1 wave gotchas T41.1,T41.1.1
C0224 | Harvest drops inert-wave records before the live-set compare | harvest,inert,lever-credit,regate | 2026-10-24 | 1.8.1/T31 | 1.8.1 wave gotchas T31
C0225 | Overlay-local symbol refused on a member: alias it around the include | alias,symbol,extern,propagate,overlay | 2026-10-24 | 1.8.1/T33 | 1.8.1 wave gotchas T33,T40.3,T40.4
C0226 | Carved jump table overruns its bank by an alignment pad | rodata,jtbl,alignment,bank,overrun,carve | 2026-10-24 | 1.8.1/T4 | 1.8.1 wave gotchas T4,T44
C0227 | Rodata-first overlay: cut rodata into gaps so splat pairs the table | splat,rodata,overlay,symbols,pairing | 2026-10-24 | 1.8.1/T4 | 1.8.1 wave gotchas T4
C0228 | Pack scoring 0/n with no return is a data table carved as a function | boundaries,data-table,probe,noretry,census | 2026-10-24 | 1.8.1/T40.16 | 1.8.1 wave gotchas T40.16
C0229 | Per-program scanners: zero asm functions is complete, not an error | scanner,campaign,all-tools,completion | 2026-10-24 | 1.8.1/T40.18.1 | 1.8.1 wave gotchas T40.18
C0230 | Undrawn zero needs leftover asm rows made include_asm or ledgered | ledger,undrawn,include-asm,corpus-state,campaign | 2026-10-24 | 1.8.1/T40.12 | 1.8.1 wave gotchas T40.12
C0231 | Make recipe loop over a generated list hits ARG_MAX: stream it | make,recipe,argument-list,linux,shell | 2026-10-24 | 1.8.1/T41 | 1.8.1 wave gotchas T41
C0232 | Makefile has no header deps: touch the TU when a shared include changes | make,dependencies,include,rebuild | 2026-10-24 | 1.8.1/T20 | 1.8.1 wave gotchas T20
C0233 | One-sided volatile is not a scheduling barrier | volatile,barrier,sched,do-while | 2026-10-24 | 1.8.1/T22 | 1.8.1 wave gotchas T22
C0234 | Block-scope extern before file-scope extern: gcc 2.95 order rule | extern,declaration,gcc-2.95,order,conflicting-types | 2026-10-24 | 1.8.1/T40.6 | 1.8.1 wave gotchas T40.6
C0235 | Chained assignment reuses a loaded byte as a call argument | lever,assignment,load-reuse,call-arg,byte | 2026-10-24 | 1.8.1/T40.7 | 1.8.1 wave gotchas T40.7
C0236 | Draft view macros: #undef at body end or later TUs fail to parse | macro,view-macro,cpp,hygiene | 2026-10-24 | 1.8.1/T14 | 1.8.1 wave gotchas T14
C0237 | Three-valued result through one shared label block, no if-conversion | lever,shared-label,return-value,barrier | 2026-10-24 | 1.8.1/T32 | 1.8.1 wave gotchas T32
C0238 | Self-test failing control prints its evidence on the case line | self-test,control,diagnostics,evidence | 2026-10-24 | 1.8.1/T48 | 1.8.1 wave gotchas T48
C0239 | Shared registry row format extended: grep every positional reader | registry,row-format,readers,schema | 2026-10-24 | 1.8.1/T40.21.1 | 1.8.1 wave gotchas T40.21
C0240 | PsyQ LIB split with psy-k (built in rust:slim), OBJ to ELF via psyq-obj-parser on amd64, masked compare | psyq,sdk,lib,obj,psy-k,psyq-obj-parser,docker,vendor | 2026-10-24 | 1.9/T2 | mmx6 T2
C0241 | Substituting PsyQ objects for splat asm TUs: ld rewrite, XBSS per-symbol, jlabel PROVIDE, stub identity by reloc | psyq,sdk,splat,ld,vendor,link,xbss,jlabel | 2026-10-24 | 1.9/T4 | mmx6 T4.c1
C0242 | Generated public doc must pass the commit style gate before the long run | commit-gate,style,generated-doc,contract | 2026-10-24 | 1.9/T7 | T7.c1 doc commit refused after 1 h run
C0243 | A public-projection proof checks build and hash only. Health rungs read unpublished inputs | split-mode,public,projection,fresh-clone,health,contract | 2026-10-24 | 1.9/T8 | mmx6 contract
C0244 | depin.py throughput: ~1.2 s/pin serial, 6 workers saturate 8 CPUs at 2.5x, ~70 MiB each | depin,parallel,throughput,docker,workers,xargs | 2026-10-24 | 1.10/T2 | mmx6 T2.c1
C0245 | Check a depin sweep with debt --files, because depin counts differ from the floor | depin,pin-unmarked,debt,fake,clang-format | 2026-10-24 | 1.10/T2 | mmx6 T2 remark
C0246 | Pin inside a macro body: depin nocompile, floor counts per use, mark each use line | depin,pin-unmarked,macro,fake,floor | 2026-10-24 | 1.10/T3 | mmx6 T3.c1 rock_02
C0247 | Re-port an upstream lane at a new pin: compare definitions only, hold the shared header | port,x4,pin,upstream,repin,mmx4 | 2026-10-25 | 1.10/T4 | 1.10 T4.c1
C0248 | Symbol address from symbols file / corpus / asm row, never name spelling | symbols,resolver,self-test,spelling,probe | 2026-10-25 | 1.10/T5 | mmx6 T5.c1
C0249 | A vote-derived alias cannot corroborate the votes that made it | x4,names,evidence,corroborator,circular,promote | 2026-10-25 | 1.10/T6 | 1.10 T6 review of T6.c1
C0250 | x4share --partners in a fresh container needs corpus, census and sig first | x4,x4share,container,partners,widen,sequence | 2026-10-25 | 1.10/T6 | 1.10 T6.c1
C0251 | Overlays see exe symbols only by func_/D_<addr> name: renaming an exe symbol overlays call breaks their link | rename,overlay,link,provide,symbols,x4 | 2026-10-25 | 1.10/T8 | mmx6 T8.c1
C0252 | Ghidra: mirror external names as a delta JSONL through the existing importer, then re-export | ghidra,import,rename,jsonl,roundtrip | 2026-10-25 | 1.10/T10 | mmx6 T10.c1
C0253 | campaign/ is never public. check-public DIR needs its own git repo | split-mode,public,projection,check-public,style | 2026-10-25 | 1.10/T12 | mmx6 T12
C0254 | Import a script without a __main__ guard via ast (drop top-level calls) | python,import,tools | 2026-10-25 | 2.0/T5 | T5 badges.py
C0255 | Mark debt constructs on clang-formatted text: InsertBraces splits if-goto | clang-format,debt-marker,fake,goto,insertbraces,propagate | 2026-10-25 | 2.1/T1 | T1.c1 self-test control
C0256 | Regenerating x4.h needs a port pass over every adapted file, since the packs are gone | x4,x4.h,repin,port,stub,header | 2026-10-25 | 2.1/T3 | 2.1 T3.c1
C0257 | Repin swaps only the body: a changed upstream preamble fails cc1, hold or hand-port | x4,repin,port,preamble,clang-format,hold | 2026-10-25 | 2.1/T4 | 2.1 T4.c1
C0258 | Repin keeps a stale callee prototype: it compiles, the hash fails, so cast the call | x4,repin,port,preamble,prototype,diff,regalloc | 2026-10-25 | 2.1/T5 | 2.1 T5.c1
C0259 | In-body #ifdef sends a port to preprocessed text: resolve conditionals, keep macros | x4,port,macro,ifdef,repin,raw-body,debt | 2026-10-25 | 2.1/T6 | 2.1 T6.c1
C0260 | Struct field offsets via an offsetof table compiled by the pinned cc1 | struct,offset,layout,cc1,x4,compare | 2026-10-25 | 2.1/T9 | 2.1 T9.c1
C0261 | Key overlay strings: own range, then exe, then other bases | strings,overlay,xref,lui,base | 2026-10-25 | 2.2/T2 | mmx6 2.2 T2.c1
C0262 | imgadapter strings --check: proto order, census, proto exe names | strings,proto,check,census,iso9660 | 2026-10-25 | 2.2/T2 | mmx6 2.2 T2.c1
C0263 | Repin drops hand comments in adapted files unless they are // ! mark lines | x4,repin,port,comment,gamestr,hold | 2026-10-25 | 2.2/T3 | 2.2 T3 retriever
C0264 | ROCK_X6.DAT slot joins: three readers of D_800E0398, packed records, byte-checked sheet offsets | mmx6,rock_x6.dat,loader,asset-map,redux,vab | 2026-10-25 | 2.2/T4 | T4.c1
C0265 | Per-stage object dispatch tables: locate via the scratchpad setter, prove with table[id]==fn at runtime | object,dispatch,scratchpad,overlay,redux,breakpoint,table | 2026-10-25 | 2.2/T5 | mmx6 T5.c1
C0266 | Proto-only functions: census the build side, pair in order between held anchors, mask-ratio 0.6 | proto,census,pairing,oracle,debug,anchors,difflib | 2026-10-25 | 2.2/T6 | mmx6 T6.c1
C0267 | Check a community address list against the function census (strict starts, overlay group by base) | address,census,leads,overlay,control | 2026-10-26 | 2.2/T7 | mmx6 T7.c1
C0269 | Host function-start census from tracked files: Ghidra JSONL + src func_ definitions | census,function-start,ghidra,jsonl,host,regex | 2026-10-26 | 2.2/T11 | mmx6 T11.c2
C0270 | Upstream retyped global clashing with sibling decls: local self-alias macro | x4,repin,port,preamble,extern,alias | 2026-10-26 | 2.3/T1 | 2.3 T1.c1
C0271 | x4port --repin/--self-test after sync: rerun extract, build, corpus, census, sig, x4share | x4,repin,port,sync,corpus,container | 2026-10-26 | 2.3/T1 | 2.3 T1.c1
C0272 | Classify a refused name lead (object start, inside object, out of image) before adding a symbol | names,leads,symbols,splat,dlabel | 2026-10-26 | 2.3/T2 | mmx6 T2.c2
C0273 | Naming PsyQ lib functions from placed objects: reloc cross-check, trivial objects, no statics | psyq,lib,names,reloc,stub,vendor | 2026-10-26 | 2.3/T3 | mmx6 T3.c1
C0274 | Batch rename: name asm-only starts, rebuild the ledger, make boundaries after a Ghidra refresh | rename,ledger,boundaries,psyq,asm-only,builtin | 2026-10-26 | 2.3/T4 | mmx6 T4.c1
C0275 | Ghidra round-trip src diff: importer must set the row's source when analysis already holds the name | ghidra,roundtrip,import,source,psx_ldr | 2026-10-26 | 2.3/T4 | mmx6 T4
C0276 | Header adoption across shared-include TUs: adopt per (TU component, library), check by .o compare | header,include,prototype,conflicting-types,object-compare | 2026-10-26 | 2.3/T4 | mmx6 T4.c2
C0277 | Cross-unit masked twin: assign only a unique hit, count the ambiguous ones | twins,masked,protodiff,proto,census | 2026-10-26 | 2.3/T5 | mmx6 T5.c1
C0278 | git add a moved source before make badges / debt --update (they skip untracked files) | rename,badges,debt,git | 2026-10-30 | 2.3/T8 | T8.c1 log
C0279 | Fix a community-sheet code address to an overlay member by matching its instruction word | overlay,member,tweaks,workbook,stage,objects,names | 2026-10-30 | 2.3/T9 | mmx6 T9 boss-id narrowing
C0280 | Overlay-local data names do not link in a rename batch. Rebuild ledger and debt after | rename,overlay,link,provide,ledger,debt | 2026-10-30 | 2.3/T10 | mmx6 T10.c2
C0281 | make format splits a long INCLUDE_ASM line and carve then drops its asm | clang-format,include_asm,carve,format | 2026-10-30 | 2.3/T10 | mmx6 T10.c2
C0282 | Tie a boss update function to its stage: type-id link, state-table reach, health word | names,boss,objects,basis,code,via,overlay | 2026-10-30 | 2.3/T18 | mmx6 T18 v2 re-judge
C0283 | Share one expensive gather between a checker's self-test and its run | self-test,harness,cache,health,fleet | 2026-10-30 | 2.3/T19 | mmx6 T19.c1
C0284 | Judge a community RAM-map row: code corroborator, superseded sweep, struct-head cast test | names,community,ram,data,struct,basis,code | 2026-10-30 | 2.3/T11 | mmx6 T11 B8
C0285 | Call graph from corpus function bounds plus jal decode, not Ghidra or asm/ | callgraph,xref,jal,corpus,naming,namesqueue | 2026-10-30 | 2.3/T12 | mmx6 2.3 T12.c1
C0286 | Apply a names-verdict batch: refresh code refs after header inserts and renames | names,verdicts,basis,docconv,rename,refs | 2026-10-30 | 2.3/T12 | mmx6 2.3 T12.c1/c2
C0287 | Overlay-local data names link via PROVIDE. Inside an INCLUDE_ASM blob add // ignore:True | rename,overlay,link,provide,splat,ignore,symbols | 2026-10-30 | 2.4/T2 | mmx6 T2.c1
C0288 | Open draft stuck at R2/R4 in a shared unit: carve it into its own unit, then bank | layout,carve,bank,r2,r4,rodata,unit | 2026-10-30 | 2.4/T3 | 2.4 T3.c1
C0289 | Re-split after plant or carve: delete asm/<prog> and the split stamp, run corpus --all | split,stamp,plant,carve,corpus,stale | 2026-10-30 | 2.4/T3 | 2.4 T3.c1
C0290 | Units carry cpp -MMD deps. A make -n recipe splice must drop -MMD/-MP/-MT/-MF | make,dependencies,include,rebuild,dumps,cpp | 2026-10-31 | 2.4/T4 | mmx6 T4, T4.c1
C0291 | Token check a regroup: Makefile cpp output, linemarker and blank lines dropped, equal | cpp,layout,regroup,token-check,host | 2026-10-31 | 2.4/T4 | mmx6 T4.c1
C0292 | Self-test a role-file layout before any file moves: the role_tree plant (unit -> wrapper + subdir role) | layout,role,self-test,plant,bank,include | 2026-10-31 | 2.4/T5 | mmx6 T5.c1
C0293 | Bank-path locator calls from a snapshot or tree copy pass root=os.getcwd(), not layout.ROOT | layout,locator,snapshot,cwd,bank,gate,propagate | 2026-10-31 | 2.4/T5 | mmx6 T5.c1
C0294 | Rename never moves files, so its token rewrite must skip #include lines (func_X.c matches) | rename,include,layout,role,token | 2026-10-31 | 2.4/T6 | mmx6 T6.c1
C0295 | A file's program comes from all its including units (layout.includers), not the first or the path | layout,includers,program,namesqueue,renamecov,role | 2026-10-31 | 2.4/T6 | mmx6 T6.c2
C0296 | TU boundary moving a compiled 8-aligned jtbl off retail alignment is red | carve,rodata,jtbl,alignment,split | 2026-10-31 | 2.4/T23 | mmx6 T23.c1 rock_04
C0297 | splat writes text-section data .s only at a spimdisasm boundary in its segment | splat,spimdisasm,carve,include_asm,dlabel | 2026-10-31 | 2.4/T23 | mmx6 T23.c1 rock_22
C0298 | Split tail unit needs file-scope decls made inside earlier member bodies | carve,split,extern,preamble,include | 2026-10-31 | 2.4/T23 | mmx6 T23.c1 rock_39
C0299 | layout apply in the container: mirror its deletions on the host (pull never deletes) | layout,apply,mx.sh,pull,delete,container,comm | 2026-10-31 | 2.4/T15 | mmx6 T15 expert
C0300 | splat emits nonmatchings asm only for INCLUDE_ASM in the unit file: scan the include closure | splat,include_asm,layout,role,nonmatchings,build | 2026-10-31 | 2.4/T15 | mmx6 T15.c1
C0301 | Find a C definition by regex: require the brace, because L-B role files carry prototypes | layout,regex,prototype,probe,locate,role | 2026-10-31 | 2.4/T15 | mmx6 T15.c2
C0302 | Compile a role file through its including unit, never as a unit (harness P2, dedup rows) | layout,role,harness,includers,dedup,compile | 2026-10-31 | 2.4/T15 | mmx6 T15.c3
C0303 | Split runs: static-only entries join the next run, and a closing #undef stays with the previous role | layout,split,static,undef,role,runs | 2026-10-31 | 2.4/T15.1 | mmx6 T15.1.c1
C0304 | Re-apply a layout on a split program: flatten L-B units (origin map), reuse names, marker-idempotent repoint | layout,reapply,flat,repoint,moves,idempotent | 2026-10-31 | 2.4/T15.1 | mmx6 T15.1.c1
C0305 | Repoint a bare cite split across files: choose the file holding prog:0x<vram> on the same line | layout,repoint,cite,vram,dedup,bare | 2026-10-31 | 2.4/T15.1 | mmx6 T15.1.c1
C0306 | Repoint per-overlay symbols/ghidra and THIRD_PARTY.md: explicit-file run before the default (marker) run | layout,repoint,cite,symbols,ghidra,third_party | 2026-10-31 | 2.4/T16 | mmx6 T16.c2
C0307 | Self-test split/plant targets: pick via the layout, never fixed vrams or unit paths | self-test,layout,carve,role,health,control | 2026-10-31 | 2.4/T16 | mmx6 T16.c4
C0308 | Pull config/layout-moves.tsv before a host repoint, since pull src leaves it stale | layout,repoint,apply,mx.sh,pull,moves | 2026-10-31 | 2.4/T24 | mmx6 T24.c1
C0309 | Whole-name stem rule: only for stems a fixed system list holds | layout,propose,stem,glossary,system,slus | 2026-10-31 | 2.4/T24 | mmx6 T24.c1
C0310 | Repoint a cite to a long-renamed file from the cite line's blame commit | layout,repoint,cite,git-blame,stale,ghidra,mirror | 2026-10-31 | 2.4/T17 | mmx6 T17.c1
C0311 | Ledger files keep their lines, so cite checkers and repoint skip them | layout,repoint,cite,ledger,protected,gate,psxdecomp.toml | 2026-10-31 | 2.4/T17 | mmx6 T17.c2
C0312 | New body under L-B: staged at layout.new_body, the next layout apply folds it into its role file | layout,bank,new_body,role,apply,stage | 2026-10-31 | 2.4/T19 | mmx6 T19 expert
C0313 | Unbank a body in an L-B self-test: cut its role-file chunk (common.h head to brace), never delete the file | layout,role,self-test,gate,bank,unbank,fixture | 2026-10-31 | 2.4/T21.1 | mmx6 T21.1.c1
C0314 | Self-tests outside the full chain need th-sig prep (bank and gate read census, x4share and x4port read sig) | selftest,health,bank,gate,census,sig,container | 2026-11-01 | 2.5/T2 | 2.5 T2
C0315 | SDK header prototype vs retail call: retail's spelling in the header, RETAIL override in psyqnames | psyq,header,prototype,arity,signed-char,psyqnames,retail-call | 2026-11-01 | 2.5/T4 | mmx6 T4.c1
C0316 | Field-watch control: bp at entry and on jr ra of a gate-proven leaf, the delay-slot store read from the register | pcsx-redux,lua,breakpoint,delay-slot,oracle,field,control | 2026-11-01 | 2.5/T5 | 2.5 T5.c1
C0317 | Homing a struct out of a generated header: emit its alias before every use | x4,x4port,homed,alias,incomplete-tag,struct,generated-header | 2026-11-01 | 2.5/T5 | 2.5 T5.c3
C0318 | Member widths via sizeof in the cc1 offsetof table | struct,sizeof,width,cc1,offset,layout,fields | 2026-11-01 | 2.5/T5 | 2.5 T5.c4
C0319 | Scratch script on container-only build state: python3 -c inline, never pull build/ | mx.sh,container,scratch,pull,firewall,build,sync | 2026-11-01 | 2.5/T5 | 2.5 T5.c4
C0320 | Struct grown past its source-game size: rewrite (&g)[1].m strides as tail members | struct,sizeof,stride,homed,tail,player | 2026-11-01 | 2.5/T6 | 2.5 T6.c1
C0321 | Census a pool entry type through pool-only pointers and sibling pools | census,pool,stride,objfields,evidence,projectile | 2026-11-01 | 2.5/T6 | 2.5 T6.c2
C0322 | Prove a data block's extent from the asm: loads off one symbol's %lo base are its members | struct,extent,bss,data,asm,base-register,members,homed | 2026-11-01 | 2.5/T7 | 2.5 T7 expert
C0323 | Raw views of a homed struct global to member access: what is safe, what moves bytes | struct,homed,view,member,sign,divide,pointer,lbu | 2026-11-01 | 2.5/T7 | 2.5 T7.c1
C0324 | Lift offset reads into field reads with lift.py, dry-run first | tool,lift,M2C_FIELD,offset,fields.tsv,struct,retype | 2026-11-01 | 2.5/T8 | T8.c1 dry run
C0325 | lift.py traps: built tree first, shared fragments need their struct header | tool,lift,harness,src/shared,include,fleet-quick | 2026-11-02 | 2.5/T9 | T9 attempt 2
C0326 | Width/sign view *(u8*)&p->m when lifting to a differently typed field | lift,field,view,width,sign,offset,M2C_FIELD | 2026-11-02 | 2.5/T9 | T9.c1
C0327 | Lift a void* param via a typed local, and a constant-first width view dodges the floor | lift,void-star,typed-local,conflicting-types,unit,view,floor,offset | 2026-11-02 | 2.5/T9 | T9.c2 weapon/
C0328 | Byte baseline vs HEAD without git stash: waves base copy, basebuild, diff.sh | harness,baseline,diff,stash,waves,expected | 2026-11-02 | 2.5/T9 | T9.c2
C0329 | Hoisting a C0117 neighbour extern strips a conflict's view tag | extern,header,hoist,globtypes,view,C0117 | 2026-11-02 | 2.5/T10 | mmx6 T10.c1
C0330 | New include in concatenated units goes before the first use, not after the first x4.h | include,header,preamble,unit,role-file,hoist | 2026-11-02 | 2.5/T10 | mmx6 T10.c1
C0331 | Struct headers ride on x4.h: fleet-inconsistent prototypes need a header x4.h does not include | header,prototype,extern,hoist,x4,unit | 2026-11-02 | 2.5/T10 | mmx6 T10.c2
C0332 | Hoisted externs: every role-file chunk includes the header itself, not once per file | extern,header,hoist,role-file,chunk,self-test,gate | 2026-11-02 | 2.5/T10 | mmx6 T10.c4
C0333 | Byte evidence for a global's access width: objdump -dr the built objects, read the LO16 reloc insns | globtypes,conflict,objdump,reloc,width,evidence | 2026-11-02 | 2.5/T10 | mmx6 T10.c5
C0334 | A sign-split range test as one ternary compare removes the C0144 goto | lever,goto,ternary,range-test,goto-removal | 2026-11-02 | 2.5/T11 | T11.c4 rock_11 EF0EC
C0335 | Copy a short shared tail instead of a goto: jump2 cross-jumps the copies back | lever,goto,cross-jump,jump2,tail,goto-removal | 2026-11-02 | 2.5/T11 | T11.c4 rock_22 EC670
C0336 | A goto into the then-arm folds into one || condition, assignments inside the test | lever,goto,short-circuit,condition,goto-removal | 2026-11-02 | 2.5/T11 | T11.c2 shared F25F0
C0337 | A goto inside a macro is marked at each use site of the macro | goto,debt-marker,fake,macro | 2026-11-02 | 2.5/T11 | T11.c1 shared EEC50
C0338 | Per-function trial loop in a coder volume: keep the baselines across sync | harness,diff,volume,sync,expected,trial | 2026-11-02 | 2.5/T11 | T11.c1 c2 c4
C0339 | An Agent worktree starts at an older ref: merge a coder branch 3-way, never by whole-file checkout | workflow,worktree,merge,parallel,coder | 2026-11-02 | 2.5/T11 | T11 merge repair 9d42d5072
C0340 | A switch default arm that repeats the fall-through store becomes break | lever,goto,switch,default,goto-removal | 2026-11-02 | 2.5/T11 | T11.c9 rock_07 E9C98
C0341 | Address debt on a lui/ori-built literal: macro in include/addr.h, not a linked symbol | address,debt,psxd_floor,lui-ori,symbol,addr.h | 2026-11-02 | 2.5/T12 | T12.c1 task_yield/task_slot
C0342 | Cite-anchor drift: map each cited line through git, then rewrite only the digits | layout,cite,cite-anchor,drift,git,repoint | 2026-11-02 | 2.5/T12 | T12.c2 c9209314b
C0343 | s8[N] member read as s16 per index: retype it s16[N/2], cast forms swap the addu | lever,retype,member,operand-order,cast,array,lift | 2026-11-02 | 2.5/T13 | T13.c1 yammar_option
C0344 | Container /work has no .git: git ls-files tools need a walk fallback | container,git,ls-files,sync,fleet,namesqueue,rung | 2026-11-02 | 2.6/T1 | mmx6 2.6 T1
C0345 | Bulk clang-format shifts code: line anchors, so repoint basis, verdicts, doc headers | clang-format,format,code-ref,namesqueue,docconv | 2026-11-02 | 2.6/T2 | mmx6 T2.c1
C0346 | System membership: call-graph reach plus all-callers-inside fixpoint, host-side | callgraph,membership,system,jal,dispatch-table,corpus,shared-helper | 2026-11-02 | 2.6/T3 | mmx6 2.6 T3.c1
C0347 | Compile a stray waves/ draft against today's headers via make build/<path>.o | draft,compile,headers,stalled,waves,container | 2026-11-02 | 2.6/T4 | 2.6 T4.c1
C0348 | Tree-wide member rename: error-driven, by declared type, re-check code refs after format | rename,member,field,struct,clang-format,coderef,fields.tsv | 2026-11-02 | 2.6/T5 | T5.c1 family action rename
C0349 | Typing player-state bases in batch: one unit, one fleet-quick, diff.sh only on red | lift,typed-local,batch,unit,fleet-quick,diff,view | 2026-11-02 | 2.6/T5 | T5.c2 movement folder
C0350 | Runtime watch on short pad schedules: control tail, dispatch arg from the source register | pcsx-redux,lua,breakpoint,control,pad,dispatch,camera | 2026-11-02 | 2.6/T6 | 2.6 T6.c1
C0351 | Labelled RAM poke as pad-schedule stimulus. A mode-id poke does not load its overlay | pcsx-redux,lua,poke,stimulus,overlay,oracle | 2026-11-02 | 2.6/T6 | 2.6 T6.c1
C0352 | Reach a mode through its source global, held across the init frame | pcsx-redux,lua,poke,stimulus,overlay,init,oracle | 2026-11-02 | 2.6/T6 | 2.6 T6.c2
C0353 | PC probes for a return value or a store, opt-in per schedule | pcsx-redux,lua,breakpoint,probe,return-value,datapoint-id | 2026-11-02 | 2.6/T6 | 2.6 T6.c2
C0354 | Documenting files for docconv: DC4 needs the banner, DC5 takes symbol names only | docconv,header,dc4,dc5,banner,code-ref | 2026-11-02 | 2.6/T7 | mmx6 T7.c1-c4
C0355 | Naming batch: comment holds for unqueueable tokens, queue built before check | namesqueue,verdicts,hold,placeholder-tier,naming | 2026-11-02 | 2.6/T7 | T7.c7 apply batch
C0356 | ledger.py --build needs a fleet run after the last mx.sh sync | ledger,sync,mx.sh,fleet,health | 2026-11-02 | 2.6/T7 | T7.c7 fleet health rc 2
C0357 | Insert DC1 banners before layout repoint, else shift path:N cites by one | layout,repoint,banner,dc1,cite,line-shift | 2026-11-02 | 2.6/T8 | mmx6 T8.c1
C0358 | Banking a func_<vram> body raises the placeholder debt floor: name first or raise | debt,placeholder,floor,bank,commit,naming | 2026-11-02 | 2.6/T9 | mmx6 T9.c1/c2
C0359 | Gate MISSING census classes.jsonl means post-build scanners not run | gate,census,scanners,missing,build | 2026-11-02 | 2.6/T9 | mmx6 T9.c1/c2
C0360 | carve.py refuses a mid-file role-split: cut only at role-file starts, else bank in place | carve,role-split,layout,bank,unit | 2026-11-02 | 2.6/T9 | mmx6 T9.c1/c2
C0361 | Gate declsync is program-wide: carving does not dodge a sibling M2C_UNK prototype | gate,declsync,prototype,r2,carve,clang-format | 2026-11-02 | 2.6/T9 | mmx6 T9.c1/c2
C0362 | A placeholder raise is written and committed by the developer outside Claude Code | debt,placeholder,raise,floor,commit,claudecode | 2026-11-02 | 2.6/T9 | T9.c3 log
C0363 | A container pull overwrites host-only edits to config/ files: sync or commit first | mx.sh,pull,sync,config,container,debt,raise | 2026-11-02 | 2.6/T9 | T9 raise resets 21:17, 21:37
C0364 | Hoisting a struct global's extern hides its v.m reads from objfields census: keep it | extern,header,objfields,census,hoist,g_Player | 2026-11-02 | 2.6/T10 | mmx6 T10.c1 bf13822b8
C0365 | Retry depin after every goto rewrite: a structural rewrite can free a pin | depin,pin,goto,goto-removal,lever,order | 2026-11-03 | 2.6/T10 | mmx6 T10.c2 1887d723c
C0366 | goto end: nest the arm rest under the guard, or hoist one early-return guard | lever,goto,goto-removal,nest,guard,block-order | 2026-11-03 | 2.6/T10 | mmx6 T10.c2 player_to_ceiling, 8003ED98
C0367 | depin misjudges pins in #included or multi-function files: verify by build hash | depin,probe,include,wrapper,build-hash,harness | 2026-11-03 | 2.6/T10 | mmx6 T10.c2
C0368 | Parallel naming drafts: read-only drafters, one proposal TSV each, one merged checker | naming,drafting,parallel,proposals,rename,coderef | 2026-11-03 | 2.6/T14 | mmx6 T14.c1-c5
C0369 | Never name a shared-body exemplar (src/shared) from one member's use | naming,shared,exemplar,define,template,hold | 2026-11-03 | 2.6/T14 | mmx6 T14.c3
C0370 | A new x4 struct home fails th-types: typecheck rejects x4 unions and fixes the shape count | x4,home,homed,typecheck,self-test,struct,lift,wall | 2026-11-03 | 2.6/T14 | mmx6 T14.c8
C0371 | Scope a layout propose to a task's files: merge rows, add refused stems first | layout,propose,merge,scope,stem,filename,debt,banner | 2026-11-03 | 2.6/T14 | mmx6 T14.c9
C0372 | permute.py target overshoots in a one-function C file: run the pinned original as a 0 control first | permuter,probe,extent,control,find_extent | 2026-11-03 | 2.6/T15 | mmx6 T15.c1
C0373 | A seeded permute.py walk dies to inf within ~70 iterations: split the cap into short multi-seed runs | permuter,seed,random,inf,cap | 2026-11-03 | 2.6/T15 | mmx6 T15.c2
C0374 | permute.py reuses its run dir: in a seed loop, save best.c on the first score 0 | permuter,seed,best,overwrite | 2026-11-03 | 2.6/T15 | mmx6 T15.c3
C0375 | A recorded 'pin cannot drop' goes stale: score the unpinned draft first, base 0 means drop it | pin,depin,stale,permuter,names-verdicts,anchor | 2026-11-03 | 2.6/T15 | mmx6 T15.c3
C0376 | Overlay bps armed only while the member is resident (BinSeek + ready callback) | pcsx-redux,lua,breakpoint,overlay,residency,binseek,oracle | 2026-11-03 | 2.6/T19 | 2.6 T19.c1
C0377 | Prototype unification reddens callers: one int prototype + void casts at call sites | prototype,declsync,tusync,return-type,caller,regalloc,M2C_UNK | 2026-11-03 | 2.6/T20 | mmx6 T20.c1
C0378 | Two-global %hi reload after a join: first-reloaded takes first %hi reg, ladder inert | regalloc,plateau,hi-lo,permuter,wall | 2026-11-03 | 2.6/T21 | mmx6 T21
C0380 | Loop-invariant masks hoist in first-use order: operand order of (a&M1)|(b&M2) picks the lui order | lever,loop,invariant,hoist,mask,sched,order | 2026-11-06 | 2.6/T23 | mmx6 T23.c2
C0381 | Splitting a fused asm symbol at a callback start trips th-bound2 phantom and th-ledger missing row | split,boundaries,bound2,ledger,symbols,fleet,asm | 2026-11-06 | 2.6/T23 | mmx6 T23.c2
C0382 | Repin to a new mmx4 pin: refetch the clone by hand, and expect homed member names to hold most files | x4,repin,mmx4,clone,homed,hold,hash | 2026-11-06 | 2.6/T31 | 2.6 T31.c1
C0383 | x4port types a base from body declarations only, and a repin line shift breaks code anchors | x4,x4port,repin,homed,anchor,namesqueue | 2026-11-06 | 2.6/T31 | 2.6 T31.c2
C0384 | An Exec bp on a dispatch jalr hides the entry bp at its overlay target. Count from the jalr | pcsx-redux,lua,breakpoint,jalr,dispatch,overlay,oracle | 2026-11-06 | 2.6/T25 | 2.6 T25.c1
C0385 | Carving in SLUS unit 120A0 ahead of 0x8001E78C reddens five tool self-test controls | carve,self-test,control,120A0,x4share,bank | 2026-11-06 | 2.6/T26 | mmx6 T26.c1
C0386 | declsync compares return width only: a width-compatible call-site cast clears R3 | declsync,cast,r3,prototype,width,M2C_UNK | 2026-11-06 | 2.6/T26 | mmx6 T26.c1
C0387 | Mid-file R4 foreign-rodata: carve the whole role file into its own unit, then re-key drifted rows | carve,rodata,r4,foreign-rodata,role,unit,registry | 2026-11-06 | 2.6/T26 | mmx6 T26.c2
C0388 | Probe MATCH but gate R5: probe masks address halves, so diagnose with asm-differ in place | probe,r5,hash,mask,asm-differ,regalloc,macro | 2026-11-06 | 2.6/T26 | mmx6 T26.c2
C0389 | A jtbl-uncarved verdict can be stale: check the table words against the function span first | jtbl,boundaries,carve,ledger,verdict,m2c,rodata | 2026-11-06 | 2.6/T26 | mmx6 T26.c3
C0390 | Regalloc cues: a leftover arg register means a shorter call, a hoisted %hi means in-loop code | regalloc,call,cast,pin,hoist,loop,m2c | 2026-11-06 | 2.6/T26 | mmx6 T26.c3/c4
C0391 | Callers disagree on arity (2-param prototypes vs a 3-param cast): every definition refused R2/R3 | declsync,cast,arity,prototype,r3,r2,gate | 2026-11-06 | 2.6/T27 | mmx6 T27.c1
C0392 | mx.sh sync wipes container drafts/: th-ledger red until the ledger is rebuilt from restored drafts | ledger,th-ledger,sync,drafts,fleet,workflow | 2026-11-06 | 2.6/T27 | mmx6 T27.c1
C0394 | s-reg swap against a block-0 %hi pseudo: move that global's first-use store in the block. Then fix zero-store order in place | regalloc,local-alloc,priority,hi,store-position,sw-zero,probe-mask | 2026-11-07 | 2.6/T27 | mmx6 T27.c3 func_8001AE44
C0395 | Replace pins in a constant block: hill-climb store order by probe score, then sweep position pairs of the swapped two | pin,constant-block,sched1,store-order,sweep,registry,harvest | 2026-11-07 | 2.6/T27 | mmx6 T27.c3 func_8003BD24
C0396 | 120A0 jtbl function first in its role file: opt cut, rebuild, then jtbl carve. Reload spill reg follows liveness | carve,jtbl,opt,120A0,reload,spill,regalloc,liveness | 2026-11-07 | 2.6/T27 | mmx6 T27.c4
C0397 | Same-unit const data between a unit's tables: carve.py data + INCLUDE_RODATA, then jtbl | carve,jtbl,rodata,data,INCLUDE_RODATA,120A0,non-contiguous | 2026-11-07 | 2.6/T28 | mmx6 T28.c1 func_80014F70
C0398 | Bank under a caller-fixed M2C_UNK prototype: u8 param andi via a local initialised at declaration | prototype,M2C_UNK,u8,andi,prologue,declsync,store-order | 2026-11-07 | 2.6/T28 | mmx6 T28.c2 func_80014F70
C0399 | OT link words: P_TAG bitfield setaddr fixes the 0xFFFFFF/0xFF000000 hoist order | lever,bitfield,setaddr,P_TAG,ordering-table,mask,hoist,loop | 2026-11-07 | 2.6/T29 | mmx6 T29.c1
C0400 | Two hoisted %hi pseudos tie in greg: symbol names order them via the gcse hash | regalloc,gcse,greg,hi-lo,hash,names,lever,dumps | 2026-11-07 | 2.6/T30 | mmx6 T30 func_80013DE8
C0401 | Standalone match, red hash in unit: chained-assignment store order, diff the planted exe | bank,hash,store-order,chained-assignment,plant,R5 | 2026-11-07 | 2.6/T30 | mmx6 T30.c1 func_80013DE8
C0402 | Stale cite with no unique old text: exact, reflow-join, nearest dup, scoped anchor (repoint R1-R4) | layout,repoint,cite,cite-anchor,clang-format,stale | 2026-11-07 | 2.6/T17 | mmx6 T17.c2 290d209e
C0403 | A $2 pin after a call: call through a void cast to free v0 | lever,pin,depin,call,cast,void,v0,return | 2026-11-07 | 2.6/T32 | mmx6 T32.c2 wait_for_file_load
C0404 | local-alloc stretches lifetimes by one insn: read sched1 order, not source order | regalloc,lreg,local-alloc,sched1,dumps,asm-differ,r5,in-place | 2026-11-07 | 2.6/T32 | mmx6 T32.c1-c2 func_800144DC, wait_for_file_load
C0405 | sched1 hazard tie: stores beat arg copies, so call args need pins | regalloc,sched1,sched,hazard,call,argument,pin,dumps | 2026-11-07 | 2.6/T32 | mmx6 T32.c3 func_8001494C
C0406 | Pair a PSX function with its x86 port twin: const-table search, then call graph | pc-port,x86,ghidra,pairing,prior-art,shape | 2026-11-07 | 2.6/T33 | mmx6 T33.c1
C0407 | A C0400 %hi name tie broken without renames: store one global via an inline out-pointer helper | regalloc,greg,hi-lo,tie,inline,out-pointer,lever,pc-port | 2026-11-07 | 2.7/T1 | mmx6 T1.c1 wait_for_file_load
C0408 | OR operand order picks the expansion order: write the clut's % 16 term first | lever,operand-order,or,clut,psyq,sprite,order | 2026-11-07 | 2.7/T1 | mmx6 T1.c3 func_800144DC
C0409 | Ghidra misses function starts: find them as jr ra then a jal target or addiu sp,sp,-N | ghidra,boundaries,jtbl,function-start,prologue | 2026-11-07 | 2.7/T2 | mmx6 T2.c1
C0410 | A dead global read in retail: an if/else on it with equal arms, and an untyped store keeps order | lever,dead-read,if-else,equal-arms,volatile,pc-port,union,store-order,sched | 2026-11-07 | 2.7/T9 | mmx6 T9.c4 func_8002234C
C0411 | sched1 tie on a table address: assign the index locals in a comma expression inside the first index | lever,sched1,tie,comma,index,table,order | 2026-11-08 | 2.7/T9 | mmx6 T9.c5 func_80052F64
C0412 | Retail reloads a pointer field after an if/else: write the field path at every use, no local | lever,reload,pointer,field,cse,length,index-loop,pc-port | 2026-11-08 | 2.7/T9 | mmx6 T9.c6 func_8002E84C
C0413 | PC switch shape scores low: enumerate case 0, group order, tail calls and division form | lever,switch,jtbl,case-0,cross-jump,division,pc-port,generator | 2026-11-08 | 2.7/T9 | mmx6 T9.c9 func_8002F9DC
C0414 | Calibrate grouped propagate cost on a full-size group: small key samples underestimate 3x | propagate,shard,health,timing,calibration,tools-health-full | 2026-11-08 | 2.7/T4 | mmx6 T4 shard-1 run
C0415 | Jtbl carve non-contiguous because of a gap of same-TU tables: carve.py jtbl bridges it | carve,jtbl,rodata,non-contiguous,bridge,gap,120A0,21BF4 | 2026-11-08 | 2.7/T11 | mmx6 T11.c1
C0416 | Hoist loop-invariant prim constants with more literal sites, never variables (loop.c threshold, REG_EQUIV) | lever,loop,hoist,constant,prim,psyq,macro,regalloc,reg_equiv | 2026-11-08 | 2.7/T11 | mmx6 T11.c5 func_800232D4
C0417 | Redundant andi 0xff after lbu in retail: a local set twice | lever,combine,andi,lbu,mask,nonzero_bits,local | 2026-11-08 | 2.7/T11 | mmx6 T11.c5 func_800232D4
gen2 | Generation 2 entries | see cookbook/gen2/INDEX.md
C0418 | Bisect a red grouped propagate R5 instead of isolating every unit. Cross-key declsync edits trip it | propagate,group,bisect,R5,declsync,tools-health-full,shard | 2026-11-08 | 3.0/T4 | mmx6 T4.c1 SLUS group lever
C0419 | Make $(file >path) in a recipe expands before any recipe line: mkdir via $(shell) first | make,recipe,file,mkdir,expansion,argv,mk | 2026-11-09 | 3.0/T5 | mmx6 T5.c1 th-propagate-since
C0420 | Parallel make check chain: per-rung stamps, a marker goal, -j exposes undeclared deps | make,parallel,tools-health,timing,wall,dependency | 2026-11-09 | 3.0/T6 | mmx6 T6.c1
C0421 | Refit shard cost on one timed shard after a lever, and cap group size at the calibration | propagate,shard,thshard,calibration,timing,tools-health-full | 2026-11-09 | 3.0/T6 | mmx6 T6 shard 1
C0422 | Shard wall variance comes from SLUS group R5 bisect rounds. Budget the estimate x1.3 | propagate,shard,thshard,R5,bisect,tools-health-full,timing | 2026-11-09 | 3.0/T7 | mmx6 T7.c1 shards 0..10
C0423 | Rank pin-free scores first by scanning the journal draft for register pins | ledger,pins,journal,pick,closeness,verbatim | 2026-11-09 | 3.0/T8 | mmx6 T8.c1 ledger.py
C0424 | gcc 2.95 compile errors have no error: tag, so classify path:line non-warning lines | gcc,cc1,compile,log,classify,refusal | 2026-11-09 | 3.0/T10 | 3.0 T10.c1
C0425 | Diff a hash-red link only after the map confirms the member sits at its retail vram | link,map,placement,diff,hash,refusal,propagate | 2026-11-09 | 3.0/T10 | 3.0 T10.c3
C0426 | Sibling prior-art C state: read the sibling repo at HEAD, not a mirrored twins state column | prior-art,x5,x4,twins,stale,mmx5-dev,join | 2026-11-09 | 3.0/T11 | mmx6 T11.c1
C0427 | Freeze a derived sample against input blob ids, and let --check rebuild via git cat-file | sample,holdout,frozen,determinism,blob,check,stratum | 2026-11-09 | 3.0/T12 | mmx6 T12 methodsample.py
C0428 | Loop pass 1 hoists an invariant too early: dead sets lift insn count, rerun pass hoists in order | lever,loop,hoist,threshold,insn-count,dead-store,preheader,magic,sched | 2026-11-09 | 3.0/T13 | mmx6 T13.c43 func_800239CC
C0429 | diff.sh under mx.sh run needs --no-pager (no less in image) | diff,asm-differ,mx.sh,pager | 2026-11-09 | 3.0/T17 | T17.c1
C0430 | A probe-matched wave draft goes stale after member renames: respell, re-probe, unify TU externs | bank,draft,stale,rename,unkNN,prototype,unity,R1 | 2026-11-08 | 3.0/T2 | mmx6 T2.c1
C0431 | Time make rungs as sub-make goals, because interleaved prerequisites ran out of order (make 4.3) | make,timing,tools-health,fleet,wall,order | 2026-11-08 | 3.0/T3 | mmx6 T3 rung walls
C0432 | An equivalence sample needs members of each verdict, not exemplar-only keys | propagate,equiv,sample,stratum,exemplar,verification | 2026-11-08 | 3.0/T3 | mmx6 T3.c1 vacuous gated stratum
C0433 | After a second mx.sh sync, rerun the split stamp to regenerate include/ (labels.inc) | sync,split,stamp,include,labels.inc,link,mx.sh | 2026-11-09 | 3.1/T2 | mmx6 T2.c1
C0434 | Declaration unify: go toward the specific type, since a loose shared body breaks other includers | declsync,declunify,prototype,extern,M2C_UNK,xkey,r2,unify | 2026-11-10 | 3.1/T3 | mmx6 T3.c1
C0435 | Alias an undefined link symbol with a top-level asm assignment, never .set on MIPS | link,undefined-reference,alias,gas,mips,asm,declunify,r5 | 2026-11-10 | 3.1/T3 | mmx6 T3.c2
C0436 | Feed a twin whose shared path is a multi-function role file or unit: extract the body, probe via the unit | rolefeed,role,propagate,bank,repair,includers,path | 2026-11-10 | 3.1/T4 | mmx6 T4.c1
C0437 | Pair a table lui with the %lo that uses its own register, never the next addiu | propagate,table_addr,defines,lui,reloc,dedup | 2026-11-10 | 3.1/T4 | mmx6 T4.c2
C0438 | Rename a twin member's callees and globals by aligning the exemplar object's relocations with retail | propagate,relocation,defines,dedup,twin,relocdef | 2026-11-10 | 3.1/T5 | mmx6 3.1 T5.c1
C0439 | Feed a twin member only the exemplar's own range when the shared path is a split-unit file | propagate,placement,address,dedup,twin,unitcut,map | 2026-11-10 | 3.1/T6 | mmx6 3.1 T6.c1
C0440 | Sum a wave's debt rises before staging: scratch index copy + debt --staged | bank,debt,placeholder,git-index,bank_close | 2026-11-10 | 3.1/T7 | 3.1 T7 bank_close --rises
C0441 | mmx5-dev dedup members are stubs: apply the stub's defines to its src/shared body | x5,mmx5-dev,dedup,seed,prior-art,stub | 2026-11-10 | 3.1/T10 | mmx6 T10.c1
C0442 | Move an in-place restoring self-test off the serial chain: scratch tree plus sha1 guard of the real one | self-test,scratch,parallel,tools-health,guard,make | 2026-11-10 | 3.1/T11 | mmx6 T11.c1
C0443 | x4port self-test red after 6 fleets: shared waves/.probes counter hits the probe cap | x4port,self-test,probe-cap,probes,fleet,th-selftests-cheap | 2026-11-10 | 3.1/T12 | mmx6 T12.c1 fleet.log
C0444 | Unmerged table-address adds: type the byte table as a struct array, index via s32 temp | lever,regalloc,table,struct,array,index,operand-order | 2026-11-10 | 3.1/T14 | mmx6 T14.c5 rock_08 func_800EA328
C0445 | Loop counter loses a callee-saved register swap: top-tested loop, no if guard | lever,regalloc,loop,guard,for,while,pin,swap | 2026-11-10 | 3.1/T14 | mmx6 T14.c11/c10 SLUS func_80027BA0
C0446 | Per-row repair dry run: refusecause.py --prog with switches, not propagate --dry-run --keys-from | repair,dry-run,refusecause,propagate,switch,route | 2026-11-11 | 3.1/T14 | mmx6 T14.c1 pilot refusal rows
C0447 | gate.py -j 3 restore-rebuild stops and worker FileNotFoundError: re-gate -j 1 from a sub-root | gate,bank,wave,parallel | 2026-11-11 | 3.1/T15 | T15.c1
C0448 | A repair-gated member is pin-free only if its exemplar is: check the exemplar for asm( pins | repair,propagate,pins,exemplar | 2026-11-11 | 3.1/T15 | T15.c1
