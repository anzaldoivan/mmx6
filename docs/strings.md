# Game strings in comments

A comment may quote a short game string next to the code that uses it.
Longer text, such as dialogue, never enters the repository.
It lives in an ignored sidecar file that each developer builds from their own disc.
The check is `make strings-check`, and the contract run includes it.

## The two forms

Each form is one comment on one line.
It is a `//` comment, or a `/* */` comment closed on the same line.

The verbatim form quotes the text after the string's address.
Its pattern is `str 0x<8 HEX> "<game text>" = "<English gloss>"` inside the comment.
An example with invented text:

`// str 0x80012345 "HELLO" = "a greeting"`

The game text may use the escapes `\"` and `\\`.
It holds at most 64 bytes of UTF-8.
A kana example holds invented text as well:

`// str 0x80012350 "テスト" = "test"`

The key form names the text by its hash instead of quoting it.
Its pattern is `str 0x<8 HEX> sha1=<40 hex> = "<English gloss>"` inside the comment.
The sha1 is taken over the original Shift-JIS bytes.
An example:

`// str 0x80012360 sha1=0123456789abcdef0123456789abcdef01234567 = "a long line"`

Both forms need a gloss.
The gloss is printable ASCII and never empty.

## What the check refuses

- A verbatim text over 64 bytes of UTF-8.
- A text quote that is not closed on its line.
- A missing gloss, an empty gloss, or a gloss with non-ASCII characters.
- Verbatim comments on consecutive lines, which would form a dialogue block.
- A verbatim address whose sidecar class is dialogue, story or table.
- In `src/` and `include/`, any non-ASCII byte outside a verbatim text.
- In `docs/`, any Japanese script outside a verbatim text.

The class check runs only when a sidecar exists.
Without the game data it is skipped, so CI needs no game bytes.
Japanese script means the CJK, kana and full-width blocks.
Typography such as dashes and arrows stays legal in `docs/`.

## The allowlist

The check skips `src/NOTICE.md` and `src/README.md`.
In `docs/glossary.md`, a table column headed `Japanese` may hold Japanese text.
Each cell of that column holds at most 64 bytes.

## The sidecar

The sidecar is `refs/leads/strings/<prog>.tsv`, one file per retail program that holds a string.
A prototype's sidecar is `<build>.<prog>.tsv`. The check and render read retail sidecars only.
The folder is ignored by git.
Its header line names five tab-separated columns.

- `vram`: the string's address, as `0x%08X` (`+0x%X`, an offset, in a member that is no code).
- `sha1`: the full hex sha1 of the raw bytes.
- `bytes`: the length of the raw bytes.
- `class`: `short`, `dialogue`, `story` or `table`, by the rule in `tools/mmx6/imgadapter.py`.
- `text`: the text decoded from Shift-JIS, with tabs and newlines escaped.

Rows are sorted by address, with one row per string address.

## Commands

- `python3 tools/mmx6/gamestr.py check [paths]` scans the tracked text files under `src/`, `include/` and `docs/`.
- `python3 tools/mmx6/gamestr.py sidecar [--prog P]` writes the sidecar from the retail files.
- `python3 tools/mmx6/imgadapter.py strings [--proto ID:DIR:EXE]...` writes the same sidecars, the prototypes'
  too, and the keys-only table `docs/leads/strings.tsv`.
- `python3 tools/mmx6/gamestr.py render <src>...` writes `build/strings/<path>` with key comments expanded.
- `python3 tools/mmx6/gamestr.py --self-test` runs the planted controls.

The check ends with `GAMESTR OK` or `GAMESTR FAIL`.
Render refuses an unknown key, and it refuses to run without a sidecar.
Its output folder is ignored by git as well.
