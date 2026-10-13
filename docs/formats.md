# Formats — the medium and its containers

This document gives facts about the retail medium (SLUS-01395 v1.1). We established them from our own
dump with the project's tools (`tools/mmx6/`). The document holds prose and own pseudocode only: no game
bytes, no disassembly listings. Addresses are KSEG0 virtual addresses in `SLUS_013.95`
(file offset = vaddr − 0x80010000 + 0x800). Evidence: phase 1.1 T1 (extractor) and T2 (this document,
log `phase-ends/current/logs/T2.md`). Web survey R1.1-001 is evidence too (no public format or
compression document for `ROCK_X6.BIN` exists, and tool licences).

## Medium
- The medium is one BIN/CUE image, one MODE2/2352 data track. The bin sha1 is `d4f7e083…` (Redump match).
  It is pinned in `config/medium.sha1`. `tools/mmx6/extract.py` refuses any other medium (G28).
- 9 files: `SYSTEM.CNF` (boots `SLUS_013.95`), `SLUS_013.95`, `ROCK_X6.BIN`, `ROCK_X6.DAT`, `ZNULL.DAT`,
  `STR/CAPLOGO.STR`, `STR/X6OP.STR`, `XA/BGM.XA`, `XA/DEMO.XA`. There are 254,921 sectors across them.
- The exe has entry 0x80054AD8, load 0x80010000, text size 0x7F000.

## ISO9660
- A raw sector is 2352 B: sync 12, header 4 (MSF + mode), subheader 8 (file, channel, submode, coding, ×2).
- Form 1 has 2048 B user data per sector. A file is `ceil(size/2048)` sectors, written truncated to `size`.
- Form 2 (XA audio, STR video) has 2324 B user data. It is written at 2336 B/sector (subheader + data + EDC
  area) × sectors, the dumpsxiso convention (cookbook C0007). Compare such files by sector count.
- Form detection (binding, T1): the directory record's XA system-use attribute is big-endian.
  Bit 0x1000 = Form 2, bit 0x2000 = interleaved. The attribute is cross-checked against the first
  sector's subheader submode bit 5 (Form 2). Both agree on all 9 files.
- The Form 2 files are `STR/CAPLOGO.STR`, `STR/X6OP.STR`, `XA/BGM.XA`, `XA/DEMO.XA`. All others are Form 1.
- The reference is dumpsxiso 54fb164 (mkpsxiso v2.30), 9/9 files, 0 differences (T4: 254921 sectors, bytes
  identical).

## ROCK_X6.BIN
The file is a code-overlay archive: 813 Form-1 sectors (1,665,024 B), a 2-sector header, then 59 members.

### TOC
- The header is sectors 0–1 (4096 B). An array of `{u32 sector, u32 size}` little-endian descriptors is at
  offset 0. The header holds 59 descriptors, then one zero pair (offset 472), then zero to the end of the
  header.
- The unit of `sector` is 2048-B sectors relative to the file's first sector. The unit of `size` is bytes.
- The loader does not scan for the terminator. Init routine 0x80016780 finds the file by name
  (`\ROCK_X6.BIN;1`, the string at 0x80010014) and reads exactly 2 sectors of header into a fixed buffer.
  Then it copies a fixed 59 descriptors (loop count at 0x80016818) into a RAM table at 0x800E0B58.
  The copy rebases each `sector` to an absolute disc sector (file start + `sector`), and `size` is copied
  unchanged. The terminator is therefore our check, not the game's.
- The member index is the position in the TOC, 0..58. Selector 0x80016858 (`BinSeek`, arg 0 = index,
  arg 1 = destination address) indexes the RAM table by `index × 8`.
- Layout facts (all 59): member 0 starts at sector 2. Members are contiguous with no gaps
  (`sector[i+1] = sector[i] + ceil(size[i]/2048)`). The last member ends at sector 813 = file end. Sizes
  are 4..82,472 B, total 1,606,492 B, and 8 sizes are not multiples of 4. Every member's last-sector
  padding is zero. Members 41 and 42 are 4 B each (the leading word only: empty overlays).
- Leading word: every member starts with a small u32 that is not a length. It runs index+2 for
  members 2–12 and index+1 for 14–58. Members 0, 1, 13 carry 60, 61, 21 (21 also appears on member 20).
  It reads as an overlay id. Its meaning is for phase 1.2 (not settled by T6 captures). Code (stack-frame
  prologues) or pointer tables follow it directly.

### Compression
- None. No member is compressed. The stored payload is the loaded image.
- Loader path (evidence): `BinSeek` 0x80016858 stores destination, `size` (as remaining count) and
  absolute sector in globals. Then it clears the alternate-handler flag (0x800E01C0 := 0) and starts the
  read 0x80014E60 (CdlSetloc, mode 0xA0 = double speed + 2340-B sectors, CdlReadN). With that flag clear,
  the ready callback is 0x800165A4, which per sector calls 0x80014D50.
  - 0x80014D50 reads the 12-B sector header and requires its position = previous sector + 1 (else retry).
    Then it copies user data straight into the destination with CdGetSector. It copies 512 words while
    remaining > 2048 (remaining −= 2048, dest += 2048). On the last sector, it copies
    `(remaining + 3) / 4` words, the rest of the sector goes to a scratch buffer, and remaining := 0.
    When remaining reaches 0, the callback pauses the drive and marks the read done.
  - The waiter 0x8001494C (called after every `BinSeek`) only spins a frame at a time and restarts a read
    that stalls for 600 frames. It does not touch the data.
  - No transform runs between disc and destination.
- Corroboration: per-member byte entropy is 5.1–5.7 bits/byte for 53 members. That is the range of
  uncompressed MIPS code and data, far from the ~7.9 of compressed streams. The entropy is lower for
  13, 21, 46, 51. The 4-B members 41, 42 are not measurable. MIPS prologues sit at offset 4 of many
  members.
- Callers (6): 0x80013CDC / 0x80013CF0 load member 0 or 1 to 0x801EA000. 0x80013D54, 0x80013E40 and
  0x80052E94 load to 0x800FA000 (members from halfword tables at 0x8006D9EC, 0x8006DC50). 0x80052E94
  passes 43, 44 or 45 directly. 0x80013E7C loads to the address held in the word at 0x80010000
  (member from the halfword table at 0x8006DB78).
  - The waiter directly follows the five 0x80013xxx calls. 0x80052E94 is one step of a state machine that
    returns while the read runs. In every case, the bytes reach the destination only through the copy
    above.
- The alternate ready callback 0x8001531C (flag 0x800E01C0 non-zero) is not reachable from
  `BinSeek`. It is a lead for `ROCK_X6.DAT` (phase 1.2), not part of this archive's semantics.

### Decoder (own pseudocode)
```
read_member(bin, k):
    sector, size = toc[k]                 # toc = 59 pairs at offset 0, zero pair at 59
    return bin[sector*2048 : sector*2048 + size]   # identity: no decompression
```
- Declared decompressed length: none exists. The only length is the TOC `size`, which is both the
  stored and the loaded length. The game copies `ceil(size/4)` words, so RAM receives up to 3 bytes of
  the (zero) sector padding past `size`. The extracted member is exactly `size` bytes.

### Length cross-check (T3 asserts all)
- 59 descriptors then a zero pair. Every byte after it in the header is zero.
- `sector[0] = 2` (header is 2 sectors). `sector[i+1] = sector[i] + ceil(size[i]/2048)`.
  `sector[58] + ceil(size[58]/2048) = 813 = file size / 2048`. `size[i] ≥ 4`.
- Each extracted member's length = its `size`. The bytes in its last sector past `size` are zero.
- Manifest: `compressed: false` for all 59. `stored_size = size`, and no `rock/<NN>.stored` file is written.

### Member table
Counts only, generated from `manifest/retail.jsonl` (`rock` records) by `make extract`.
Decompressed size = bytes written to `rock/<NN>.bin`.

| index | sector | stored size | decompressed size | compressed |
|---|---|---|---|---|
| 0 | 2 | 44588 | 44588 | false |
| 1 | 24 | 22964 | 22964 | false |
| 2 | 36 | 74784 | 74784 | false |
| 3 | 73 | 60528 | 60528 | false |
| 4 | 103 | 57316 | 57316 | false |
| 5 | 131 | 44084 | 44084 | false |
| 6 | 153 | 42944 | 42944 | false |
| 7 | 174 | 65564 | 65564 | false |
| 8 | 207 | 53916 | 53916 | false |
| 9 | 234 | 54192 | 54192 | false |
| 10 | 261 | 79784 | 79784 | false |
| 11 | 300 | 82472 | 82472 | false |
| 12 | 341 | 5804 | 5804 | false |
| 13 | 344 | 1344 | 1344 | false |
| 14 | 345 | 16312 | 16312 | false |
| 15 | 353 | 55432 | 55432 | false |
| 16 | 381 | 33946 | 33946 | false |
| 17 | 398 | 4717 | 4717 | false |
| 18 | 401 | 32488 | 32488 | false |
| 19 | 417 | 3848 | 3848 | false |
| 20 | 419 | 45216 | 45216 | false |
| 21 | 442 | 35303 | 35303 | false |
| 22 | 460 | 81224 | 81224 | false |
| 23 | 500 | 66444 | 66444 | false |
| 24 | 533 | 57258 | 57258 | false |
| 25 | 561 | 26176 | 26176 | false |
| 26 | 574 | 25796 | 25796 | false |
| 27 | 587 | 7308 | 7308 | false |
| 28 | 591 | 40334 | 40334 | false |
| 29 | 611 | 12116 | 12116 | false |
| 30 | 617 | 26844 | 26844 | false |
| 31 | 631 | 41372 | 41372 | false |
| 32 | 652 | 18736 | 18736 | false |
| 33 | 662 | 29444 | 29444 | false |
| 34 | 677 | 19944 | 19944 | false |
| 35 | 687 | 18876 | 18876 | false |
| 36 | 697 | 25908 | 25908 | false |
| 37 | 710 | 15500 | 15500 | false |
| 38 | 718 | 20188 | 20188 | false |
| 39 | 728 | 28008 | 28008 | false |
| 40 | 742 | 24108 | 24108 | false |
| 41 | 754 | 4 | 4 | false |
| 42 | 755 | 4 | 4 | false |
| 43 | 756 | 17052 | 17052 | false |
| 44 | 765 | 33304 | 33304 | false |
| 45 | 782 | 11878 | 11878 | false |
| 46 | 788 | 12578 | 12578 | false |
| 47 | 795 | 1788 | 1788 | false |
| 48 | 796 | 1568 | 1568 | false |
| 49 | 797 | 1164 | 1164 | false |
| 50 | 798 | 2040 | 2040 | false |
| 51 | 799 | 11786 | 11786 | false |
| 52 | 805 | 1104 | 1104 | false |
| 53 | 806 | 944 | 944 | false |
| 54 | 807 | 1892 | 1892 | false |
| 55 | 808 | 2416 | 2416 | false |
| 56 | 810 | 1400 | 1400 | false |
| 57 | 811 | 1304 | 1304 | false |
| 58 | 812 | 1136 | 1136 | false |

59 members. Stored total 1606492 B, decompressed total 1606492 B.

## ROCK_X6.DAT
Unknown. 50,913,280 B, 24,860 Form-1 sectors. The file is extracted and hashed whole. Its structure is for
phase 1.2.

## XA / STR
Raw Form-2 streams. The XA audio streams are `XA/BGM.XA`, `XA/DEMO.XA`. The MDEC video streams are
`STR/CAPLOGO.STR`, `STR/X6OP.STR`. They are extracted at 2336 B/sector and hashed. They are never demuxed,
never part of the build (PROJECT_CONTEXT.md:85). `ZNULL.DAT` (18,088 Form-1 sectors) is likewise extracted
and hashed only.

## Manifest schema
`manifest/retail.jsonl` (tracked, hashes only, never bytes): one JSON object per file under
`extracted/retail/`, sorted by `path`, keys sorted, `\n`-terminated.
- Common: `kind` (`iso` | `rock` | `rock-stored`), `path` (relative to `extracted/retail`),
  `sha1` (40-hex), `size` (bytes written).
- `iso`: `lba`, `sectors`, `form` (1 | 2). The path is `iso/<ISO path>`.
- `rock`: `index` (0..58), `sector`, `stored_size`, `compressed` (bool). The path is `rock/<NN>.bin`.
- `rock-stored`: the stored form, `rock/<NN>.stored`, only for a compressed member (none on this medium).
- The firewall reads it as a hash source (`config/firewall.txt`). `tools/audit_public.py` fails any
  tracked file whose sha1 matches a record.
