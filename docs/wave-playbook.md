# The wave playbook — the operating procedure for the matching campaign

> ONE document is the procedure. Read it before every run. Keep it current in the same change as any tool that it
> names. A superseded procedure gets a banner.
>
> The table pairs each guard below with the MEASUREMENT that earned it. Fill the measurement column from your own
> waves. The source project's measurements are in the kit's methodology (the calibration fences).
> Created by decomp-architect on 2026-10-01.

This game keeps its measurements in the campaign manual, `docs/ops/campaign.md`, and in `campaign/ledger.tsv`. The
last column names the section that holds each one (2026-10-12). Both files are in the development repository. A
release does not publish them.

| # | Step | The guard | The measurement that earned it |
|---|---|---|---|
| 0 | Preconditions | The tree must be clean. The last clean fleet run must be green. | Recorded in `docs/ops/campaign.md`, "Wave procedure". |
| 0b | Wave tasks (3.1 T20) | A wave is plan tasks: its drafting task, then its bank task. Every bank task names its deps explicitly: its own drafting task and the previous wave's bank. The loop promotes the lowest-numbered queued task, so a bank with no deps can run before its drafts (R68). The next wave's drafting task depends on the previous drafting task, never on the bank, so it can run while the bank waits (step 7). | 2.7: the loop promoted T3 ahead of the added PC-port retry T9, which had no dependency on it (R68, 2026-11-07). |
| 1 | Draw | Exclude what cannot bank. Audit the exclude list first (it records what the TOOLING could not do). Rank by open templatable instructions. Know face mass vs delivered mass. A one-program wave (3.2, SLUS) is a targets file, not a draw: `validate.py --targets <file>`, then `cards.py --wave W<n> --targets <file>`, after `mx.sh push waves/W<n>` (sync does not carry waves/). | Recorded in `docs/ops/campaign.md`, "Routing" and "Yield". |
| 1a | Repair lane before drafting (3.1 T19, 3.3 T4, T6) | Run `refusecause.py --prog <p> --repair relocdef --repair unitcut` over the refused `plumbing` rows, one program per step, after a fresh fleet. A row it gates gets no card and no coder. It banks through its key's live run, `propagate.py <key> --repair relocdef --repair unitcut` (C0488). Never run `bank.py <row>` for a gated member. A member of a pinned exemplar gets the ledger blocker `member-of:<exemplar>` (C0448). The section "Repair-lane waves" below gives the full route. | Holdout, n 20 refusal rows: the dry run gated 14, and 11 of them banked with 0 coder runs. They cost 8-15k context per bank, against 28-103k per pin-free match before. Over the 909 refused rows left, the lane gates 552 (`campaign/refusecause.after.tsv`, `docs/ops/methods-gen3.md` "Verdicts, repair reach and the end-state number"). W309 banked 17 rows by 7 live key runs (3.3 T4). At HEAD the lane gates 650 of 881 rows, 136 of them behind a pinned exemplar (3.3 T6). |
| 1b | Wave shape (3.3 T6, was wave size 3.1 T20) | A wave is the gated rows of one or more programs, banked in steps. It has one fleet, one propagate check, one th-equiv and one stop. A step is a set of live key runs in one background shell, under 50 minutes. Price a step at 3 times the sum of its keys' single-key `thshard.py` estimates, under 2,500 s. The 35-row cap is gone. The section "Repair-lane waves" below gives the pricing and the lists. | W309's 7 live keys ran 25-476 s, 978 s in all. Their single-key estimates sum to 395 s, a ratio of 2.48. With thshard's 20% margin, that gives the factor 3 (R3.3-008, 3.3 T6). Before: W301 84 s and W303 66 s a bank (3.1 T19). |
| 2 | Cards | The banked twin found over the WHOLE world goes on the card. A card names only levers that the base contains. | Recorded in `docs/ops/campaign.md`, "Packs". |
| 3 | Packs | Make one pack per target + the shared laws file, at the paths that the drafting prompt reads. | Recorded in `docs/ops/campaign.md`, "Packs". |
| 4 | Validate | Never hand-type a target. Assert that every target is still open at draw time. Send near-misses to the permuter first. | Recorded in `docs/ops/campaign.md`, "Validator". |
| 4b | Prior art before a plateau | Before a function is called a plateau, check four sources, which `campaign/priorart.tsv` (`tools/mmx6/priorart.py`, 3.0 T11) lists per residue row. The X5 twin is in mmx5-dev `docs/oracle/x6-twins.tsv` (copy `campaign/x4/x5-twins.tsv`, seeds `campaign/x4/x5-leads.tsv`). The mmx4 partner is in `campaign/x4/partners.tsv` and `docs/leads/x4.tsv`. The prototype tables are `config/oracle.proto-*.functions.tsv` and `docs/leads/proto.tsv`, and `docs/leads/pc-port.md` gives the method for the PC port x86 twin. `draw.py --order class` writes each plateau pick's four sources to `build/draw/W<n>.plateau.txt` (3.1 T9): check them before the attempt and write what each gave in the Blockers row. `docs/prior-art.md` L5, L5b, L5c, L8, L13, L14 and L18 give each source and its status. | 2.6 T32: three boot functions were called plateaus before anyone checked the four sources (R54, 2026-11-07). |
| 5 | Draft | Use one agent per target, the model by measured size, streaming not batched. The wave's difficulty is a draw-time knob. The tool enforces the probe cap: `cards.py --probe-pack` refuses past the routing cap and shows the draft's asm and diff (3.1 T8). `cards.py --outside` lists compiles made elsewhere, read per attempt. Draw with `--order class` (3.1 T9): cheap classes first, by the `order` row of `config/routing.txt`. Dropped (3.1 T19, item 4): the plateau attempt cap (`plateau 1`, removed by T25), so a plateau pick gets its band's attempts. | Probe cap: no attempt went over its band cap (max 24 of 25). The 10 drafted holdout rows cost 73k per pin-free match, against 76.5k before. Plateau cap, n 5: 342k for 1 match against 232k for 2 before, so it was dropped (`docs/ops/methods-gen3.md` Verdicts 3-4). |
| 5b | Seeded arm (3.1 T10, adopted diagnostic-grade) | A row whose prior-art lead carries C (`campaign/priorart.tsv` x5 or x4 `c:`) is drafted from a seeded pack. Build it with host `cards.py --x5-fetch W<n>`, then `cards.py --wave W<n> --arm <file>`, the file in `config/methods-arm.tsv`'s format. Its record row says `arm seeded`, so 3.3's wave-metrics rows re-judge it. | Holdout, n 7 C-lead rows: both arms matched 7 of 7 pin-free. Seeded cost 30.3k per match against fresh 34.7k, and 11 compiles against 28 (`docs/ops/methods-gen3.md` Verdict 5). |
| 5c | Bankable drafts (3.2 T4, T6) | A bankable draft is a match with 0 pins and 0 gotos. Brief coders goto-free, and check gotos before recording a match. Port an old draft to current names and prototypes before trusting its ledger score (C0479). A pinned best's attempt 1 is the pin pass (depin, C0450, C0451). Count compiles as probes plus dumps runs, since `--probe-count` counts probes only. | W307: two goto-bearing matches had to be rewritten. The ledger gave 8004DDD4 9/181, and its ported draft scored 170/181 (`docs/ops/methods-gen3.md` "The 3.2 waves"). |
| 6 | Gate | Gate everything in parallel (worktrees, and the executable by a clean rebuild). Gate the DIRECTORY, never the verdict list. Assert banked + failed + no-verdict == drafts. | Recorded in `docs/ops/campaign.md`, "Gate". |
| 6b | Reconcile | Make one deterministic pass over each gate group's slate BEFORE the rebuild. | Recorded in `docs/ops/campaign.md`, "Recovery" and "Yield" (the column Recovered). |
| 7 | After ANY bank | Run `mx.sh run make format` and pull the touched files, then the twin rescan, then the fleet. With no `mx.sh sync` between, run host `propsince.py select` and run the propagate check that it calls for. The section "Repair-lane waves" below gives the check for each select result, the tool freeze and the full-recheck schedule (rule M28). Never run one unsharded `KEYS=ALL` step. A format break stops the fleet at once (`FLEET 0 of 57`, rule M25). A bank that moves debt counts stops for the developer once per wave (R109). | Recorded in `docs/ops/campaign.md`, "Gate" and "Yield" (the column with the propagated instructions). The 12 shards at W309 took 22,785 s in all, max 2,675 s (3.3 T4). |
| 7a | One stop per wave | The expert writes the wave's path list and runs `bash tools/mmx6/bank_close.sh --rises --paths-from <list>`. Its `BANK-RISES placeholder <n>` is the wave's one raise, so fix any other rising `down` kind first. The paste is the output of `bank_close.sh --dry-run <TaskId> "<line>" [placeholder <n>] --paths-from <list>`, in R61 order. The bank task ends `review` at the paste, and the bank keeps its own volume (`MX6_VOLUME`, C0004). A repair wave pastes once after all its bank steps, its fleet and its checks. On a checkpoint wave, Claude stamps after the paste (step 7c). | 3.1 T19, item 2: 2 stops for 39 pin-free banks and their gated twins, against 50 under R61. W309: 1 stop for 17 banks (3.3 T4). |
| 7b | Ledger after a bank | After the bank and `corpus.py --all`, and before the fleet, run `mx.sh run python3 tools/mmx6/ledger.py --drop-banked` (3.2 T5, T7). It drops exactly the rows that `--check` flags `c-function` and keeps every other line byte-identical. Then run `mx.sh run cat campaign/ledger.tsv` or `mx.sh pull campaign/ledger.tsv` to the host. Put `campaign/ledger.tsv` in the `bank_close.sh` paths. Nobody edits `ledger.tsv` by hand. `ledger.py --build` is a separate reviewed refresh (R115): it does not read the existing ledger, so curated blockers would be lost. | 3.1 T12. Both after-run banks (W302, W305) kept the ledger this way, with no hand edit: `LEDGER OK 1593 rows`, `RECONCILE A 106 B 0` (3.1 T19, item 7). 3.2: run before `corpus.py --all`, it dropped 0 rows (T7). The fleet's th-ledger fails while banked rows are listed (T5). |
| 7c | SLUS banks (3.2 T5, T7) | Bank SLUS drafts from `src/shared`, hoist their types to `include/mmx6`, and bump typecheck's self-test count (C0469). A link that fails after `mx.sh sync` needs a clean re-split, since sync restores the tracked `include/macro.inc` (C0452). A row that does not bank gets a ledger blocker of grammar tokens (`plumbing:R3`, `plateau:<sub>`). Its Blockers row gives the four sources and the capped attempt (R229). After the paste, Claude syncs the bank volume, copies `green.json` out and runs `propsince.py stamp`. | W306 banked 12 of 19 and W307 8 of 16, each with one paste (`docs/ops/methods-gen3.md` "The 3.2 waves"). |
| 7d | Commits that only move debt rows (3.2 T3) | A pin or goto removal lowers a debt row, and the pre-commit gate fails on the stale row. Only the developer's `debt --update` lowers it (R61). So each removal is one green patch, `.run/<phase>/series/NN-<name>.patch`. The paste is one line per patch, chained with `&&`: `git apply <patch> && bash tools/mmx6/bank_close.sh <T> "<line>" <paths>`, with no placeholder. Each line makes one commit. | T3: 7 commits in one paste, pin 820 to 813 (R3.2-009). |
| 8 | Harvest — a hard gate | Put every idiom into the cookbook + index. Put every mechanical idiom into a sweep that banks the free functions. Do the widening review. Rerun `census.py --all` after `harvest.py --start` and before `--widen` (C0453, 3.2 T5). | Recorded in `docs/ops/campaign.md`, "Harvest". |
| 9 | Verify the fleet | Do a clean rebuild of everything. Read the exit code. | The gate is `make fleet`. Its last line is `FLEET 57 of 57` (snapshot 2026-10-24, `make fleet`). |
| 10 | Hand off | The task summary carries the exact state and the next step, or `TASK_PROGRESS.md` does at a context handoff. Stale is worse than absent. Each wave writes its rows and its `# wave W<n> split W<n> fleet_wall_s <n> since_wall_s <n>` line in `campaign/wave-rows.tsv`. It then runs `PY tools/mmx6/wavemetrics.py --build` and `--check` (rc 0) and commits `campaign/wave-metrics.tsv`. A key row's bank_wall_s is its key's live wall split over the key's banked rows, and since_wall_s sums the since steps and shards. The rows carry dev_stops 1 on the first banked row, and the bank task's coder runs and context (3.3 T2). | `campaign/wave-metrics.tsv` has rows W301 and W303 beside W300-pilot and W300-holdout (3.1 T19, item 8). On the holdout, coder runs went from 35 to 15 and context from 1701k to 739k. W309's bank_wall_s are key splits (3.3 T4). |

Then **recover** before re-drawing. Triage the gate's failures into body and plumbing. Bank the plumbing rejects through
the reconcile ladder without a redraft. The gate number is not the close rate until recovery has run.

## Repair-lane waves (3.3 T6)

The repair lane banks gated rows with no card and no coder. A row is gated when `refusecause.py --repair relocdef
--repair unitcut` gates it dry (cause `stale`, R5 green). The dry run tests one member alone in a fresh tree, so only
the key's live run decides a bank. Run `mx.sh run python3 tools/mmx6/propagate.py <key> --repair relocdef --repair
unitcut` once per key. It banks every gated member of the key in every program, and it writes their registry rows
(C0488).

Never run `bank.py <row>` for a gated member. It skips unitcut and writes no registry row. A draft banks with
`bank.py <row> --src src/shared/<path>`. A member that the live run refuses gets a ledger blocker of grammar tokens
that names its stage. Its cause goes in its Blockers source (R229). A member of a pinned exemplar cannot bank
pin-free, so its blocker is `member-of:<exemplar prog:vram>` (C0448).

Each wave's list is `waves/W<n>/targets.tsv`, with the columns prog vram func key step cause. The port-demo rows go
first (R258). Then the programs follow by gated rows, most first, with ties by name. A key goes to the wave of its
first program, because its live run banks all its gated members. A wave whose list is empty closes done.

`thshard.py` prices a shard of the dry run, where 8 workers share the keys. A live bank step runs its keys one after
another. So price each key alone: pipe the key to `thshard.py check` and take its estimate minus the 300 s base. A
step costs 3 times the sum of its keys' prices and stays under 2,500 s. Time every step, and keep each under 50
minutes.

After the fleet, with no sync between, run host `PY tools/mmx6/propsince.py select`. If it prints keys, pipe them to
`thshard.py check`. Then run them as one `mx.sh run make th-propagate-since KEYS="<keys>"` step, or one step per
`thshard.py keys K` slice. If it prints ALL with only `config:` triggers, run `propagate.py --check` (`REGISTRY OK <n>
rows`). Then run a since step on the wave's own keys, the key column of its banked rows. The 12 shards wait for the
next full recheck (rule M28).

The tool freeze runs from the freeze stamp to the last repair wave's paste. In that span, no commit changes a tool
trigger. If select marks a `tool:` trigger, the freeze is broken and the wave returns `blocked`. A wave does not fix a
defect in a frozen file. Its rows get ledger blockers that name the cause, and the wave's summary names the fix. Claude
then adds one tool-fix task after that wave, which ends with the 12 shards and a stamp.

A full recheck is the 12 shards and a stamp. It runs after a tool change, at every 4th repair wave from W310 (W313,
then W317), and at the milestone. A wave may also run it when `thshard.py check` prices its selection at or above the
last 12-shard sum (22,785 s at W309). That run does not move the W313 checkpoint. On the wave's volume, run `mx.sh run
make tools-health-shards-check`, then `make tools-health-shard SHARD=k` for k = 1..12 as separate steps. After the
paste, Claude copies `build/propagate/green.json` out and runs `MX6_VOLUME=<volume> PY tools/mmx6/propsince.py stamp`
(R276).
