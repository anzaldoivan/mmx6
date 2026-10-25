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
| 5 | Draft | Use one agent per target, the model by measured size, streaming not batched. The wave's difficulty is a draw-time knob. | Recorded in `docs/ops/campaign.md`, "Routing" and "Yield". |
| 6 | Gate | Gate everything in parallel (worktrees, and the executable by a clean rebuild). Gate the DIRECTORY, never the verdict list. Assert banked + failed + no-verdict == drafts. | Recorded in `docs/ops/campaign.md`, "Gate". |
| 6b | Reconcile | Make one deterministic pass over each gate group's slate BEFORE the rebuild. | Recorded in `docs/ops/campaign.md`, "Recovery" and "Yield" (the column Recovered). |
| 7 | After ANY bank | Run the twin rescan, then commit. | Recorded in `docs/ops/campaign.md`, "Gate" and "Yield" (the column with the propagated instructions). |
| 8 | Harvest — a hard gate | Put every idiom into the cookbook + index. Put every mechanical idiom into a sweep that banks the free functions. Do the widening review. | Recorded in `docs/ops/campaign.md`, "Harvest". |
| 9 | Verify the fleet | Do a clean rebuild of everything. Read the exit code. | The gate is `make fleet`. Its last line is `FLEET 57 of 57` (snapshot 2026-10-24, `make fleet`). |
| 10 | Hand off | The task summary carries the exact state and the next step. At a context handoff, `TASK_PROGRESS.md` does. Stale is worse than absent. | Not recorded (2026-10-12). |

Then **recover** before re-drawing. Triage the gate's failures into body and plumbing. Bank the plumbing rejects through
the reconcile ladder without a redraft. The gate number is not the close rate until recovery has run.
