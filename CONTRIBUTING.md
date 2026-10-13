# Contributing to mmx6

## Bring your own copy of the game

Every contributor extracts from their own legally obtained copy. Nothing derived from it is committed — no executable,
payloads, disassembly, assets, build output, memory images, database, vendor SDK, or notes that paste the target's
instructions. The `.gitignore` firewall stops the ordinary case. `tools/audit_public.py` refuses the rest and runs in CI
on every push. Review `git status` before every commit.

## What "done" means

A function is matched when **both** of these conditions are true:

- Its compiled output is instruction-identical to the original, register allocation included.
- The whole binary's hash check still passes with it linked.

"Functionally equivalent" is never done. Unmatched C lives under the non-matching guard with the assembly stub in the
default build. A match is verified from a clean rebuild, never an incremental one. A pull request states which
compilation each claim survived (standalone / the real translation unit / the whole binary).

## Names, types and formatting

A symbol is renamed only on recorded evidence. Such evidence is, for example, a string that the symbol prints, a
cross-reference chain, a debug menu, a live-memory datapoint, a community label with provenance. **If you are not sure
what something does, leave it unnamed rather than name it wrongly.** The address-named placeholder is honest and
greppable.

Keep one definition per structure. A duplicate type is a defect. Run `make format` before committing (`.clang-format`
is the community's style). Mark anything that exists only to force a match with `// !FAKE:` and its reason. Mark an
original bug with `//! @bug`.

## AI use — conduct

The README's [AI policy](README.md#description) applies to every contribution. Every change is justifiable from recorded
evidence. A person reviews each phase gate. Names come only from evidence. Outward text is written by a person. A tool
that wrote a meaningful part of a change is named in an `Assisted-by: <model> [<tool> …]` line.

Whoever submits a change answers for all of it: they understand it, have tested it and can defend it in review.
Maintainers may decline what they cannot.

The rules that keep that honest, for every contributor and every agent:

1. **The byte gate is the only claim of success.** Never report a match that the gate has not proven. The words "it
   compiled" and "looks equivalent" are not results. "Banked" is written from a tool's printed success line.
2. **Names and types are evidence-based, never guessed.** A model may propose a name. A person with recorded evidence
   asserts one. Hallucinated meaning is the specific way a model damages a decompilation without any test catching it.
3. **Outward text is written by a person.** Issues, pull requests, forum posts and outreach to other projects are written
   by their author. The author writes the way a developer writes — short, plain, from the facts. The text is never a
   model draft with the tells removed. Before contributing to another project, read and follow its own AI-contribution
   policy.
4. **No automated traffic against community infrastructure.** Shared services are used by a person in a browser.
   Anything repetitive is replicated locally.
5. **Agents assist. A person owns.** Every change is justifiable by a person from the record (the phase logs, the
   decision log, the cookbook's byte proofs).

## Submitting

A submission needs these items:

- Small, per-function or per-family pull requests.
- The hash check green on every binary the change touches.
- The clean fleet verification for anything that touches a shared body, a shared header or the executable.
- A commit message that names what was matched and how it was verified.

Add no AI sign-off or co-author trailers (`Assisted-by:` names a tool, not an author).

Pull requests from forks run CI only after the maintainer approves them, and again after every push. The build runs
with the game files present, so approval follows a review of the whole diff, including the Makefile, headers, `tools/`
and `.github/`.
