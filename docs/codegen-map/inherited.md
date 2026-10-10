# Inherited — BFM symptom index mapped onto our tells (gcc 2.7.2 → cc1 2.95.2)
Source: R1.7-005 (BFM cookbook index titles only; BFM targets gcc 2.7.2, not our pin gcc2.95.2-psx-aspsx2.86). A title is a lead, never a fact, until re-proven here by a repro pair + map lever row.
Columns: symptom and our slug `sym-<slug>` | BFM section (idx = BFM index line) | BFM pass | our group | status.
Group: by the first BFM pass (expand/fold-const/cse → G-expr; combine → G-combine; loop → G-loop; global-alloc/local-alloc/reload → G-alloc; sched/reorg/delay → G-sched; jump/jump2/cross-jump → G-jump); a re-proven row takes its lever's group (the pass the dump shows).
Status: `re-proven C<nnnn>` = same idiom as a byte-proven lever (L01..L11 = C0075..C0085; T6: L12 §193-H C0086, L13 §279 C0087, L14 §329 C0088, L15 §345 C0089); `lead` = unverified under our pin (adjacent matches stay leads).

## Table
symptom sym-<slug> | BFM section | BFM pass | our group | status
--- | --- | --- | --- | ---
wrong branch sense, arms swapped sym-branch-arms-swapped | §3-T4, §32.2 (idx:39,14) | jump/expand | G-jump | re-proven C0082
two branches to one label means negated source cond sym-branch-arms-swapped | §247 (idx:67) | jump | G-jump | lead
ternary c?0:X canonicalised, arm order inert sym-branch-arms-swapped | §195-F (idx:52) | fold-const | G-expr | lead
c?X:-X singleton path vs if/else two-arm sym-branch-arms-swapped | §346 (idx:101) | expand | G-expr | lead
inverted range test (u32)(x-lo)>=N, trailing else sym-branch-arms-swapped | ADD-5 §1/I1 (idx:71) | expand/jump | G-expr | lead
mirror row: value-return in taken arm, trailing return 0 sym-branch-arms-swapped | ADD-4 §225 (idx:70) | jump | G-jump | lead
two guards sequential ifs, not if/else-if sym-branch-arms-swapped | §204-A (idx:60) | jump | G-jump | lead
guard ladder rungs must stay symmetric sym-branch-arms-swapped | §396g (idx:103) | reorg | G-sched | lead
tail merged that original kept separate sym-cross-jump | §5a (idx:40) | cross-jump | G-jump | re-proven C0083
cross-jump runs after sched; no C barrier steers sym-cross-jump | §186 (idx:47) | jump2 | G-jump | re-proven C0083
surviving copy is the later one; backward j = goto sym-cross-jump | §162 (idx:43) | jump2 | G-jump | lead
cross-jump count law, not call law sym-cross-jump | §162 CALL veto (idx:44) | jump2 | G-jump | lead
cross-jump merges suffix only, no head merge sym-cross-jump | §193-C (idx:133) | jump2 | G-jump | re-proven C0083
shared delay slot is the merge signature; write duplicate sym-cross-jump | §224 + addenda (idx:64,68,73) | jump2 | G-jump | re-proven C0083
barrier at bottom of twin (find_cross_jump walks backward) sym-cross-jump | §336 (idx:99) | jump2 | G-jump | lead
zero-byte barrier: advance pointer inside each switch arm sym-cross-jump | §428 (idx:104) | jump2 | G-jump | lead
two arms same callee merge unless each consumes result sym-cross-jump | §195-G (idx:53) | jump2 | G-jump | lead
N duplicated return v tails fold; goto done join restores sym-cross-jump | §319 (idx:322) | combine/jump | G-combine | lead
load hoisted above store; missing WAR dep sym-load-below-store | Start-here §76 (idx:27) | sched2 | G-sched | lead
store-to-load hoist blocked by compiler barrier not volatile sym-load-below-store | ADDENDUM §244 (idx:155) | sched1 | G-sched | lead
second SET of ptr pseudo blinds sched1 alias oracle sym-load-below-store | §194-K (idx:139,363) | sched1 | G-sched | lead
WAR fence at sched2 on hard regs; v&=K before branch sym-load-below-store | §194-H (idx:138) | sched2 | G-sched | lead
zero-byte fence after defining stmt emits it first sym-load-below-store | §194-A (idx:136) | sched1 | G-sched | lead
statement order around call (sched/delay/length +-1) sym-load-below-store | §176-A (idx:130) | sched1 | G-sched | lead
chained assignment *b=*a=v moves arg copy sym-load-below-store | §205 (idx:144) | sched1 | G-sched | lead
copy-then-RMW group by op kind, not field sym-load-below-store | §281 (idx:156) | sched1 | G-sched | lead
independent trailing stmt before div-consuming stmt (hazard nop) sym-load-below-store | §306 (idx:86) | sched | G-sched | lead
every small edit moves many insns (whole-fn quantity budget) sym-register-pressure | §83d (idx:355) | cse | G-expr | lead
global-alloc ties break on declaration order sym-register-pressure | §467 (idx:342) | global-alloc | G-alloc | re-proven C0079
allocno class local vs global via decl scope/var reuse sym-register-pressure | §76 (idx:233) | local/global-alloc | G-alloc | lead
zero-byte ref raises biv global_alloc priority (no pin) sym-register-pressure | §344 (idx:330,441) | global-alloc | G-alloc | re-proven C0080
live-length slider/priority tie split by zero-byte asm sym-register-pressure | §47, §3-C. (idx:222,246) | global-alloc | G-alloc | re-proven C0080
loop reg assignment: decl order + live range, 5 levers sym-register-pressure | §347 (idx:331,443) | global-alloc/loop | G-alloc | re-proven C0079
pre-init shared const before branch: arms reuse dest reg sym-sreg-swapped | §285 (idx:307) | local-alloc | G-alloc | lead
call-crossing $s0/$s1 swap forced by pins sym-sreg-swapped | Register-allocation ORDER L1407 (idx:213) | global-alloc | G-alloc | re-proven C0079
rotation across symmetric blocks = variable identity sym-sreg-swapped | §150 (idx:247) | global-alloc | G-alloc | lead
two named locals for one reloaded expr buy two allocnos sym-sreg-swapped | §208 (idx:280) | global-alloc | G-alloc | lead
counter on stack decremented in place sym-sreg-swapped | §204-B (idx:421) | loop/alloc | G-loop | lead
param used directly; prefer s32 to void*; save-copy after 1st call sym-phantom-callee-saved | §220 (idx:283) | global-alloc | G-alloc | lead
split load from arithmetic: fused g+K denies $s home sym-phantom-callee-saved | §248 (idx:287) | local/global-alloc | G-alloc | lead
void* param cast in local costs extra $s when later param needs one sym-phantom-callee-saved | §342 (idx:329) | global-alloc | G-alloc | lead
phantom $s from call-crossing pin (pin honoured iff no call) sym-phantom-callee-saved | §268, §72 (idx:294,231) | global-alloc | G-alloc | lead
loop-walked ptr param hands arg reg to giv sym-phantom-callee-saved | §179-A (idx:256,417) | loop | G-loop | lead
reload spill slot rounded to 8B; one spill grows frame 16 sym-spill-slot | §334, §463 (idx:328,346) | reload | G-alloc | lead
?: on MEMORY operands costs ~16B invisible frame sym-spill-slot | §3-B. (idx:244) | reload/expand | G-alloc | lead
struct copies member-wise to match spill-slot save sym-spill-slot | ADDENDUM to §82 (idx:297) | expand | G-expr | lead
lone $t8/$t9 is reload scratch; reproduce spill sym-spill-slot | §3-D. (idx:245) | reload | G-alloc | lead
loop pointer top-of-body addu not folded addiu sym-loop-reversed | §3-T1 (idx:407) | loop/cse | G-loop | lead
write up-count loop; gcc reversal puts init after movables sym-loop-reversed | §282 (idx:158,432) | loop check_dbra | G-loop | re-proven C0077
do/while(p<end) under guard: guard decides compare sym-loop-reversed | §279 (idx:429) | loop | G-jump | re-proven C0087
do-while guard+latch repeat bound expr, not shared local sym-loop-reversed | §NNN (idx:378,430) | cse/loop | G-expr | lead
cursor C type pointer vs int picks sltu vs slt sym-loop-reversed | §NNN (idx:431) | expand | G-expr | lead
hoist threshold arithmetic (29 with call in loop) sym-loop-reversed | §148, §472 (idx:124,455) | loop move_movables | G-loop | lead
loop init above dominating guard fills slot, flips regs sym-loop-reversed | §211 (idx:145) | loop/reorg | G-loop | lead
mask forces andi even after lbu sym-narrow-load | §3-I2 (idx:557) | combine | G-combine | lead
andi folded away, target keeps it; hold in u16 local sym-narrow-load | Start-here §1/I2+§12 (idx:19) | combine | G-combine | re-proven C0078
slti vs sltiu; narrow unsigned ordered compare width dial sym-narrow-load | §35, §199-D (idx:20,603) | expand | G-expr | lead
(int)s16 & 0xFFF narrowed onto raw HImode pseudo; widening temp sym-narrow-load | §329 (idx:327) | fold-const | G-expr | re-proven C0088
narrow signed read feeding const >> loses lh; asm re-tie sym-narrow-load | §197-A (idx:367) | cse/combine | G-expr | lead
byte load on biv base born in combine; spell shift-mask sym-narrow-load | §386 (idx:451) | combine | G-combine | lead
volatile load degrades lh to lhu+sll+sra sym-narrow-load | §345 (idx:390) | combine | G-combine | re-proven C0089
HImode range test; s32 + (u16) cast drops andi sym-narrow-load | §327 (idx:388) | cse | G-expr | lead
narrow cast of wide param costs +1 after intervening jal sym-narrow-load | §193-B (idx:265,594) | combine | G-combine | lead
sll16+sra vs lhu: liveness decides, not spelling sym-narrow-load | §194-G (idx:599) | combine | G-combine | lead
pointer-derived base load uncacheable across store/call sym-global-reload | §193-H (idx:360,596) | cse | G-expr | re-proven C0086
varying-address load re-emitted per CSE-live interval sym-global-reload | §193-E (idx:358) | cse | G-expr | lead
fixed-symbol global: extern T D[]; D[0] is reload dial sym-global-reload | §195-H (idx:364) | cse | G-expr | lead
volatile-qualified global reload; memory clobber vs volatile sym-global-reload | ADDENDUM §22 (idx:77,379) | cse | G-expr | lead
"memory" fence as cse invalidator sym-global-reload | §475 (idx:403) | cse | G-expr | lead
pointer var to the global, index off p (one base reg) sym-global-reload | §20 (idx:17) | cse | G-expr | lead
reassigned pointer as cse barrier sym-global-reload | §243 (idx:150,372) | cse | G-expr | lead
cse store re-seed does not cross join label sym-global-reload | §195-L (idx:366) | cse | G-expr | lead
repeated compare deleted by qty_comparison_code sym-global-reload | §197-B (idx:56,368) | cse | G-expr | lead
index scaling x*4 / b*3<<3 vs b*24 sym-shift-x4 | §475 (idx:403) | expand | G-expr | lead
base spelling picks addressing mode: symbol 3-insn vs ptr 2-insn sym-shift-x4 | §348 (idx:444) | expand | G-expr | lead
type selects addressing mode sym-shift-x4 | §3-C. TYPE-DRIVEN (idx:570) | expand | G-expr | re-proven C0084
giv worth-while test: re-associate addend into index sym-shift-x4 | §354 (idx:446) | loop strength_reduce | G-loop | lead

Unmapped: 9 of 15 BFM index buckets fit none of our tells (structs/memcpy 93, decl/K&R 122, jump tables 72, opt-level 26, family propagation 123, integration 89, build/splat/harness 219, process/doctrine 144, unbucketed 338 = 1226 of 1788 bucket entries; entries repeat across buckets). Fitting buckets: delay-slots 66, sched 100, regalloc 140, cse 50, loops 50, types 98.

## DC2 and mmx4
No inherited codegen idioms from either (measured 2026-10-02, T6). DC2 `/Users/ThinkPad/orca/workspaces/dino-crisis-2-decomp/bootstrap/cookbook/INDEX.md`: 50 entries; tagged `idiom` 1 (C0001, the entry-shape doc); codegen-map/`sym-` rows 6 (C0045..C0050), all phase/task 1.7/T3..T5, i.e. copied from mmx6, plus C0002 the triage table (origin decomp-architect); DC2-original codegen idioms 0. mmx4: no cookbook under /Users/ThinkPad/orca (no `*mmx4*` path with a `*cookbook*` file to depth 7); the only mmx4 tree is `.run/prior-art/mmx4/` (build/replay scripts, no idioms).
