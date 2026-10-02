# T7.c1 progress (coder handoff 1)

## Done (committed in this handoff commit, not yet gate-verified)
- x4share.py `--partners`: `write_partners()` + PARTNERS/OPEN consts + docstring; line `X4SHARE partners …`. Not yet run.
- ledger.py: input `partners` (required), class `x4` between twin and unique; self-test plant has partners rows (v0 dup wins, v7 → x4). Not yet run.
- Lane regex `W-[a-z0-9]+` in cards.py:529, journal.py:53, gate.py:712, harvest.py:64.
- mk/tools-health.mk th-selftests: `x4port.py --self-test` after x4share's.
- tools/mmx6/x4port.py new (lane + port + self-test). `--self-test` → `X4PORT CONTROL OK` (run via dev copy in container: positive match 13/13, flip → not exact, addend shift → other symbol).

## In flight / next 5 steps
1. Sample: `mx.sh push waves/x4dev` (dev copies of x4port/x4share/ledger; run with `PYTHONPATH=/work/tools/mmx6 python3 waves/x4dev/<t>.py`, avoids sync+rebuild) → `x4share.py --triple gcc2.95.2-psx-aspsx2.86 --partners` (writes /work/campaign/x4/partners.tsv), then `x4port.py --wave W-x4 --root waves/x4try --limit 40`, then loop `cards.py --probe-pack` over waves/x4try/W-x4/*/; fix porter causes; record a/b/c + named causes.
2. Full BUILD/TEST chain of the brief (sync wipes build/), `mx.sh pull campaign/x4/partners.tsv campaign/ledger.tsv`.
3. Docs: campaign.md `## X4 lane`, Lanes x4 line, ## Ledger x4 text (line ~281); decomp-environment.md Tooling inventory row.
4. Delete waves/x4try and waves/x4dev (Mac + /work); `PY tools/audit_public.py`; `mx.sh run make format-check`.
5. Commit T7.c1, write phase-ends/current/logs/T7.c1.md, return coder contract.

## Gotchas / findings to carry
- typecheck.py (bank R3) refuses any typedef/struct definition outside include/mmx6/ (`outside`): x4 drafts carrying X4_ struct/typedef defs will STOP R3 in c2 unless types move to include/mmx6 or typecheck exempts them. Flag to expert.
- X6 references read from the X6 TU object relocations (same splat names; lets the self-test use banked C), not the asm text: note as deviation.
- mmx4 objects: gas emits R_MIPS_26 against `.text` (section-relative) even for global callees; HI16 table order does not precede its LO16 → pairing by nearest HI16 at lower offset (Elf.refs).
- config/symbols.<prog>.txt not touched (names absent from the X6 ELF go to verdict.json notes `new …`).
- representative = lowest (prog,vram) open member per brief, even when state `asm` (bank preflight needs include_asm in a c unit): count them in the log.
