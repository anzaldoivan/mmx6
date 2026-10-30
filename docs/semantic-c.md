# Semantic C: the standard for a finished file

This page says what a finished source file looks like.
Matching is the floor. A matched file builds byte-identical, and a finished file also reads as plain, named, documented C.
Each clause below names the check that enforces it. No clause rests on review alone.
The motto is "preserve the archeology of the code".

## The two states

A file is matched when the build is byte-identical with every function of the file in C.
It is finished when it is matched, has no readability debt and carries the documentation layer.
Until then we call it matched and name its debt.
The rule is FIN1 (`rules/FIN1.md`).

## FIN1's six conditions

`python3 tools/psxd_floor.py debt` counts the debt kinds against `config/debt-baseline.txt`.
Its `--files` mode prints the state of each file.

1. Matched. The hash check of the build passes with the file in C. Check: `make fleet` and the build hash.
2. No forced code. Kinds `pin`, `goto` and `barrier`, and their `-unmarked` forms. Check: `psxd_floor.py debt`.
3. Typed. Kinds `offset`, `address`, `cast`, `field`, `struct` and `extern`. Check: `psxd_floor.py debt`.
4. Named. Kinds `placeholder`, `placeholder-use` and `filename`. Check: `psxd_floor.py debt` and `renamecov.py --all`.
5. Plain C. Kind `asm`, each with a row in `config/asm-evidence.tsv`. Check: `psxd_floor.py debt`.
6. Formatted. The formatter makes no change. Check: `make format-check`.

A pin, `goto` or barrier that the match needs carries a `// !FAKE: <reason>` comment.
The floor counts it as marked debt, and rule DC8 below checks its reason.

## Names

Names stay compatible with sozud/mmx4, so code and names can travel both ways.
They are snake_case, and a function name starts with its verb.
Placeholders are `func_XXXXXXXX` for code and `D_XXXXXXXX` for data, with the address in eight hex digits.
An object's per-frame function is `update_<object>`, and an unknown field is `unkXX` at its hex offset.

M14 decides when an mmx4 name becomes our symbol, and M15 says how such names are credited.
The full rules are in `docs/naming.md`, and game terms map to stems in `docs/glossary.md`.

Check: `renamecov.py --all` refuses a name without a basis row.

## The documentation layer

The layer is our own proposal, after bio2-ds (address-first headers, usage notes) and parasite-eve-decomp (the checklist).
The check is `python3 tools/mmx6/docconv.py check`.
It applies to each file listed in `config/docconv.txt`, and a file joins that list when it is documented.
Each rule below has an id that the check prints with each refusal.
Comments never move a byte, because the compile rule strips them before the compiler runs.
`.clang-format` keeps comments as written, so the layout below survives `make format-check`.

### The file banner (DC1, DC2)

DC1: the leading comment lines of the file hold one banner line.
It names the program, the system and the address range, in this form.

`// prog SLUS_013.95 | system player | range 0x80037838-0x8003787C`

The program has a symbol file `config/symbols.<prog>.txt`.
The range runs from the lowest to the highest address the file covers.
Its `hi` is the address of the last instruction word, not the end-exclusive bound.
A header file writes `range -`, since it holds no code.
A licence line, such as the mmx4 adaptation notice, may come before the banner.

DC2: no comment holds a build path, such as a drive letter path, a home folder or a `Source:` line.
Our paths say nothing about the game, and a leaked path ties the text to one machine.

A file under `src/shared/` also carries one line naming where it is included, in this form.

`// Shared file: included by src/SLUS_013.95/32208.c, between player_ladder_let_go and func_80037880.`

The TU is the including file, and A and B are the functions on either side of the include.
The check refuses a shared file without the line, or whose TU is missing or does not include it.

### The function header (DC3 to DC6)

Each function definition has a block of `//` lines directly above it.
DC3: the first line gives the address first, then the name and its purpose in our own words.
The address is the symbol's address, and the purpose has at least three words.
A `static inline` helper with no symbol address (none in `config/symbols.<P>.txt`, no `func_` name) is exempt from DC3 to DC6.
It may carry a short header `// <name>: <purpose>` with no address, checked for the name and a three-word purpose, or none.

DC4: a `basis:` line names the basis kind and a ref found in that row of `config/symbols/basis.tsv`.
A placeholder name writes `basis: none` until it is renamed.
DC5: a `callers:` line lists notable callers by name, or says `none known`.
An optional `reads:` line notes a field of a generated struct that the function reads (DC7).

DC6: when the function uses a game string, a `str` line quotes it in a form of `docs/strings.md`.
The list of such functions is `config/oracle.strnames.tsv`, and `gamestr.py check` checks the form itself.

An example, with invented text:

```c
// 0x80037838 player_hurt: starts the hurt state the player's hurt type selects.
// basis: x4 94a81587fc1f
// callers: none known
// reads: X4_PlayerObj.hurt_type (+0x63, s8), the index into D_80073C30.
void player_hurt(struct X4_PlayerObj* self) {
```

### Usage notes for structures and fields (DC7)

A structure definition has a comment line above it that says which functions read or use it.
Each field ends with a comment that names a reader, as `read by <function>`, or says `unreferenced`.
A field whose meaning is still unknown keeps its `unkXX` name, and its note still says who reads it.

A generated struct, such as those in `include/mmx6/x4.h`, takes no hand-written field notes.
Its reader notes the field instead, with an optional line in the function header.

`// reads: Struct.field (+0xNN, type), role`

The check accepts the line in this form and refuses a malformed one.
Emitting such notes from `x4port.py` waits until the structs leave `x4.h`.

### The codegen why (DC8)

Each `// !FAKE:` comment gives its reason on the same line, in at least three words.
The reason says what the compiler needed, for example the register the pin keeps.

DC6 and DC8 rest on the self-test controls of `docconv.py`, since the pilot file has no string and no marker.
The first campaign file with a `!FAKE` marker or a game string is reviewed when it lands.

## The finished-file checklist

A file is finished only when every line below is true.
Each line names its check, and all of them run from the tree.

- The build hash is green from a clean rebuild with the file in C (`make fleet`).
- `psxd_floor.py debt --files` lists the file as finished.
- `renamecov.py --all` passes, so every name has a basis row.
- `make format-check` passes.
- The file is listed in `config/docconv.txt`, and `docconv.py check` passes.
- `gamestr.py check` passes, so each quoted string is short and glossed.

The published progress number counts matched code only.
Only the tool's README block counts finished files.
