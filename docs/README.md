# `docs/` — what goes where

*Installed by decomp-architect (install.py S3) on 2026-10-01 for mmx6. This folder holds the records and references the
project's wiki summarises and links. Knowledge has a home by KIND, not by the session that produced it. A note written
for one session is scratch (`.run/`). The durable result it produced goes into one of the files below, and the note is
archived.*

| Kind of knowledge | Where it goes | The rule behind it |
|---|---|---|
| A compiler idiom proven on the bytes (the residual, the mechanism, the lever, the byte proof) | one `cookbook/C<nnnn>.md` entry written by `tools/cookbook_add.sh`, tagged by symptom in `cookbook/INDEX.md` (grepped, never read whole) | the flywheel: consult before a match, feed back after |
| A norm of conduct the project adopts (a "never X" / "always Y when Z") | one `rules/<id>.md` written by `tools/rules_add.py`, proposed as a `Rule candidate:` and adjudicated by the phase planner | Rules accumulate. A rule is never added unilaterally. |
| A strategic pivot: what was believed, what failed, the measurement, the hindsight | an entry in `docs/decision-log.md`, written while fresh | capture the why while it hurts |
| A late discovery that would have sped up an earlier phase. The entry states what it is, when it was found, when it *could* have been found and what it would have saved. | `docs/accelerators.md` | the ledger a future project starts from |
| A procedure people run (the wave, the publication) | a runbook under `docs/`. A superseded runbook carries a banner at the top and is then archived. | one runbook is the procedure |
| An environment or tool fact (a version, a flag, a hook, a row per tool) | a topic under `docs/ops/` (the decomp facts: `docs/ops/decomp-environment.md`), in the same change as the tool. A standing decision goes to `HOW_WE_WORK.md` only through PA3's routing. | keep the ops reference current |
| An address, with its source and its verification status | `docs/memory-map.md` | address provenance and region tags |
| A file or container format | `docs/formats.md` (the medium's layout: One MODE2/2352 ISO9660 track. SYSTEM.CNF boots SLUS_013.95. Code overlays are packed uncompressed as 59 sector-extent members of the ROCK_X6.BIN archive. XA/STR streams are alongside.) | — |
| The state of the open phase. Then the phase's synthesis. | `phase-ends/current/` (the plan written only by `tools/plan_edit.py`, the task summaries and logs, and a `TASK_PROGRESS.md` at a hand-off) → `phase-ends/PhaseEnd_Phase<N>.md`, assembled by PA3's scripts | the hand-off is written to be replayed (G59) |
| How the project is used: building, verifying, contributing, its layout and conventions | the wiki (`docs/wiki/`), the source of truth for documentation | — |
| A design note, a frontier analysis, a triage ladder, a worklist for one session | `.run/<session>/` while live. Once its result is in the record above, the note moves to the archive. It is never a reference. | see the archive |

**Not created here (2026-10-12).** This repository has no `docs/wiki/`, no `docs/decision-log.md`, no
`docs/accelerators.md` and no `docs/sunset/`. A row or a rule below that names one says where that knowledge goes when
the file exists. Until then, link the `docs/` file itself. The archive in use is `docs/retired/`.

**Authored versus generated.** Numbers are generated, never typed. Every progress figure, badge, timeline row and census
in a published document is produced by a tool from the tree. The tool asserts the published copy is fresh. A generated
file says so on its first line. Edits go to the generator.

A number that has to appear in prose is a dated snapshot with the command that produced it. Snapshots of a state that no
longer exists are frozen, not regenerated.

**Placeholders.** A tracked document never pastes a literal double-brace placeholder token. It names the placeholder in
prose. The install-time placeholder audit cannot tell a quotation from an unfilled placeholder, and it must stay a true
signal.

**Links.** A document links the wiki page for a topic, not the `docs/` file behind it. A wiki page links into `docs/`
only through its Reference index. Nothing links into the archive (`docs/sunset/`). The archive index names files as
backticked paths with the version they were archived at.

A backticked path is a citation, not a link. A link checker classifies cited paths as TRACKED or UNTRACKED by asking
git, never the disk.

**The archive.** A document leaves `docs/` when its purpose is fulfilled and its information lives elsewhere. The move is
a `git mv` into `docs/sunset/` under the same relative path. The move includes one row in the archive index and a review
row for the owner. The row in the archive index says what the document was, what came of it and where it lives now.

Deletion is the owner's decision, never part of the move. Every referrer is re-pointed first (a `git grep` over the tree
must return only the two index files).
