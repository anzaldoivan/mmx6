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
| 1 | Draw | Exclude what cannot bank. Audit the exclude list first (it records what the TOOLING could not do). Rank by open templatable instructions. Know face mass vs delivered mass. | Recorded in `docs/ops/campaign.md`, "Routing" and "Yield". |
| 2 | Cards | The banked twin found over the WHOLE world goes on the card. A card names only levers that the base contains. | Recorded in `docs/ops/campaign.md`, "Packs". |
| 3 | Packs | Make one pack per target + the shared laws file, at the paths that the drafting prompt reads. | Recorded in `docs/ops/campaign.md`, "Packs". |
| 4 | Validate | Never hand-type a target. Assert that every target is still open at draw time. Send near-misses to the permuter first. | Recorded in `docs/ops/campaign.md`, "Validator". |
| 4b | Prior art before a plateau | Before a function is called a plateau, check four sources, which `campaign/priorart.tsv` (`tools/mmx6/priorart.py`, 3.0 T11) lists per residue row. The X5 twin is in mmx5-dev `docs/oracle/x6-twins.tsv` (copy `campaign/x4/x5-twins.tsv`, seeds `campaign/x4/x5-leads.tsv`). The mmx4 partner is in `campaign/x4/partners.tsv` and `docs/leads/x4.tsv`. The prototype tables are `config/oracle.proto-*.functions.tsv` and `docs/leads/proto.tsv`, and `docs/leads/pc-port.md` gives the method for the PC port x86 twin. `draw.py --order class` writes each plateau pick's four sources to `build/draw/W<n>.plateau.txt` (3.1 T9): check them before the attempt and write what each gave in the Blockers row. `docs/prior-art.md` L5, L5b, L5c, L8, L13, L14 and L18 give each source and its status. | 2.6 T32: three boot functions were called plateaus before anyone checked the four sources (R54, 2026-11-07). |
| 5 | Draft | Use one agent per target, the model by measured size, streaming not batched. The wave's difficulty is a draw-time knob. The tool enforces the probe cap: `cards.py --probe-pack` refuses past the routing cap and shows the draft's asm and diff (3.1 T8). `cards.py --outside` lists compiles made elsewhere, read per attempt. Draw with `--order class` (3.1 T9): cheap classes first, by the `order` row of `config/routing.txt`. A plateau pick gets one capped attempt (`plateau 1`), then `ledger.py --build` marks it `plateau:<label>:lever` to wait for a lever. | Recorded in `docs/ops/campaign.md`, "Routing" and "Yield". |
| 6 | Gate | Gate everything in parallel (worktrees, and the executable by a clean rebuild). Gate the DIRECTORY, never the verdict list. Assert banked + failed + no-verdict == drafts. | Recorded in `docs/ops/campaign.md`, "Gate". |
| 6b | Reconcile | Make one deterministic pass over each gate group's slate BEFORE the rebuild. | Recorded in `docs/ops/campaign.md`, "Recovery" and "Yield" (the column Recovered). |
| 7 | After ANY bank | Run `mx.sh run make format` and `mx.sh pull` the touched files, run the twin rescan, then the fleet. With no `mx.sh sync` between, run `mx.sh run make th-propagate-since KEYS="$(PY tools/mmx6/propsince.py select)"` (exhaustive: the shards, 3.1 T11), then commit. A format break stops the fleet at once (`FLEET 0 of 57`, rule M25), and a bank moving debt counts stops for the developer once per wave (R109). The expert writes the wave's path list and runs `bash tools/mmx6/bank_close.sh --rises --paths-from <list>`, whose `BANK-RISES placeholder <n>` is the wave's one raise. Fix any other rising `down` kind first. The expert then hands over the output of `bank_close.sh --dry-run <TaskId> "<line>" [placeholder <n>] --paths-from <list>` as the one paste (R61 order, `docs/ops/campaign.md` "Bank close"). | Recorded in `docs/ops/campaign.md`, "Gate" and "Yield" (the column with the propagated instructions). |
| 7b | Ledger after a bank | After the bank's fleet, run `mx.sh run python3 tools/mmx6/ledger.py --drop-banked`. It drops exactly the rows that `--check` flags `c-function` and keeps every other line byte-identical. Then run `mx.sh run cat campaign/ledger.tsv` or `mx.sh pull campaign/ledger.tsv` to the host. Put `campaign/ledger.tsv` in the `bank_close.sh` paths. Nobody edits `ledger.tsv` by hand. `ledger.py --build` is a separate reviewed refresh (R115): it does not read the existing ledger, so curated blockers would be lost. | 3.1 T12. |
| 8 | Harvest — a hard gate | Put every idiom into the cookbook + index. Put every mechanical idiom into a sweep that banks the free functions. Do the widening review. | Recorded in `docs/ops/campaign.md`, "Harvest". |
| 9 | Verify the fleet | Do a clean rebuild of everything. Read the exit code. | The gate is `make fleet`. Its last line is `FLEET 57 of 57` (snapshot 2026-10-24, `make fleet`). |
| 10 | Hand off | The task summary carries the exact state and the next step. At a context handoff, `TASK_PROGRESS.md` does. Stale is worse than absent. The expert writes the wave's directive line in its records file (`# wave <name> split <pilot|holdout|all> fleet_wall_s <n|-> since_wall_s <n|->`), runs `PY tools/mmx6/wavemetrics.py --build` then `--check` (rc 0), and commits `campaign/wave-metrics.tsv` (`docs/ops/campaign.md` "Yield", 3.1 T13). | Not recorded (2026-10-12). |

Then **recover** before re-drawing. Triage the gate's failures into body and plumbing. Bank the plumbing rejects through
the reconcile ladder without a redraft. The gate number is not the close rate until recovery has run.
