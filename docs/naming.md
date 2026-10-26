# Naming X6 symbols (phase 1.10)

Where a symbol name comes from, what proves it, and which tool records the proof. Decided in D1 (phase 1.8.1).

## Style
- Names that X6 alone has follow mmx4's style. They are snake_case, and a function name starts with its verb
  (`set_animation`, `get_layout_screen`, `player_set_animation_frame`, `bomb_bat_hover_start`). A global starts
  with `g_`, as mmx4 writes `g_Player`. A table is a plain noun (`background_objects`, `vram_rect_ptrs`).
  Library names (`DecDCTReset`) keep the SDK's spelling.
- These names stay compatible with sozud/mmx4. An unnamed function is `func_XXXXXXXX` and unnamed data is `D_XXXXXXXX`,
  with the address in eight hex digits. An object's per-frame function is `update_<object>`. An unknown field is
  `unkXX`, where XX is its hex offset. The standard for a finished file and its comments is `docs/semantic-c.md`.

## Tiers (D1)
1. A function with tier `gate`, scope `engine`, one mmx4 partner and at least one corroborator takes its mmx4 name
   verbatim.
2. Tier `bytes` with scope `engine` (exact signature, body still assembly) takes it once the function is banked in C.
3. Scope `object` (an mmx4 enemy, weapon, effect or the like): rename the role in X6 terms. The role comes from
   dispatch-table identity, three oracle datapoints, or a string. A function called from several objects gets a
   neutral name for its behaviour. Without any of these it stays `func_`.
4. The mmx4 name stays as an alias (`config/x4/names.tsv`, `docs/x4-names.md`). These rows are leads only:
   a `slot` row, a near match, a row without a corroborator. A lead is never a symbol on its own.

## Admission (`x4names.py --promote`)
- Func: tier gate, scope engine, a basis without a ` same-name <n>` / ` slot <n>` suffix, and a corroborator.
- Corroborator: one of three things. A caller: another anchor votes this address for this name. A callee:
  this function's own votes land on an address whose exact alias is the voted name. A slot row is no callee
  witness, because those same votes made it. A hand basis row: a string, xref, oracle, debug or community row at
  the same address. Any vote here for a different name holds the row (`vote conflict`).
- Data: tier slot, scope engine, votes `a/0` with a >= 3.
- Every other row goes to `config/x4/held.tsv` with each failing clause listed (`scope object`, `tier bytes`,
  `partners same-name 2`, `anchors 2`, `no corroborator`, ...). Admitted + held = names.tsv rows.
- The votes come from `--widen` (container). `--promote` keeps a copy in `campaign/x4/votes.tsv` (tracked), so the
  records can be rewritten with `--promote --votes campaign/x4/votes.tsv` without re-running widen.
- 245 of 246: `main_bss_state` (SLUS_013.95 0x80097420, data, slot) has scope `-`, because no single mmx4 object
  defines it. So the names count line shows engine + object = 245 of 246 rows. The scope comes from x4core.merge,
  and x4core.py is byte-shared with mmx5, so it is left as it is. The row is held as `scope -`.

## config/symbols/basis.tsv
- TAB-separated, one `#` header line: `prog vram name basis-kind basis-ref tier`, sorted by (prog, vram, basis-kind).
- Kinds: `x4` (an mmx4 partnership, basis-ref = the names.tsv basis plus `; corroborator ...`), `string`,
  `xref`, `oracle`, `debug`, `community`.
- Only `--promote` writes `x4` rows, and it rewrites them every run. Never copy one in by hand. Hand rows of the
  other kinds are written by people and kept verbatim by `--promote`.
- The rename tool (a later task) writes each symbol's `// basis:` line in `config/symbols.<prog>.txt` from this file.

## Upstream (`x4names.py --upstream`)
- `config/x4/upstream.tsv`: for each hand basis row whose X6 function has a single mmx4 partner under a different
  name, the line is `prog vram mmx4-path:function proposed-name basis-kind basis-ref`.
- Only the developer hands these to mmx4 (G63, G64). No agent contacts mmx4.

## Credit
Names are facts. They are credited in `docs/prior-art.md` and the README, not in THIRD_PARTY.md.
