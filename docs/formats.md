# Formats — the medium and its containers

Facts about the retail medium (SLUS-01395 v1.1), established from our own dump with the project's
tools (`tools/mmx6/`). Prose and own pseudocode only: no game bytes, no disassembly listings.
Addresses are KSEG0 virtual addresses in `SLUS_013.95` (file offset = vaddr − 0x80010000 + 0x800).
Evidence: phase 1.1 T1 (extractor), T2 (this document; log `phase-ends/current/logs/T2.md`); web
survey R1.1-001 (no public format or compression document for `ROCK_X6.BIN` exists; tool licences).

## Medium
- One BIN/CUE image, one MODE2/2352 data track. Bin sha1 `d4f7e083…` (Redump match), pinned in
  `config/medium.sha1`; `tools/mmx6/extract.py` refuses any other medium (G28).
- 9 files: `SYSTEM.CNF` (boots `SLUS_013.95`), `SLUS_013.95`, `ROCK_X6.BIN`, `ROCK_X6.DAT`, `ZNULL.DAT`,
  `STR/CAPLOGO.STR`, `STR/X6OP.STR`, `XA/BGM.XA`, `XA/DEMO.XA`. 254,921 sectors across them.
- Exe: entry 0x80054AD8, load 0x80010000, text size 0x7F000.

## ISO9660
- Raw sector = 2352 B: sync 12, header 4 (MSF + mode), subheader 8 (file, channel, submode, coding, ×2).
- Form 1: 2048 B user data per sector; a file is `ceil(size/2048)` sectors, written truncated to `size`.
- Form 2 (XA audio, STR video): 2324 B user data; written at 2336 B/sector (subheader + data + EDC
  area) × sectors, the dumpsxiso convention (cookbook C0007); compare such files by sector count.
- Form detection (binding, T1): the directory record's XA system-use attribute is big-endian;
  bit 0x1000 = Form 2, bit 0x2000 = interleaved; cross-checked against the first sector's subheader
  submode bit 5 (Form 2). Both agree on all 9 files.
- Form 2 files: `STR/CAPLOGO.STR`, `STR/X6OP.STR`, `XA/BGM.XA`, `XA/DEMO.XA`. All others Form 1.

## ROCK_X6.BIN
A code-overlay archive: 813 Form-1 sectors (1,665,024 B), a 2-sector header, then 59 members.

### TOC
- Header = sectors 0–1 (4096 B). Array of `{u32 sector, u32 size}` little-endian descriptors at
  offset 0; 59 descriptors, then one zero pair (offset 472), then zero to the end of the header.
- Units: `sector` = 2048-B sectors relative to the file's first sector; `size` = bytes.
- The loader does not scan for the terminator: init routine 0x80016780 finds the file by name
  (`\ROCK_X6.BIN;1`, the string at 0x80010014), reads exactly 2 sectors of header into a fixed buffer,
  and copies a fixed 59 descriptors (loop count at 0x80016818) into a RAM table at 0x800E0B58,
  rebasing each `sector` to an absolute disc sector (file start + `sector`); `size` is copied unchanged.
  The terminator is therefore our check, not the game's.
- Member index = position in the TOC, 0..58. Selector 0x80016858 (`BinSeek`, arg 0 = index,
  arg 1 = destination address) indexes the RAM table by `index × 8`.
- Layout facts (all 59): member 0 starts at sector 2; members are contiguous with no gaps
  (`sector[i+1] = sector[i] + ceil(size[i]/2048)`); the last ends at sector 813 = file end; sizes
  4..82,472 B, total 1,606,492 B; 8 sizes are not multiples of 4; every member's last-sector padding
  is zero. Members 41 and 42 are 4 B each (the leading word only: empty overlays).
- Leading word: every member starts with a small u32 that is not a length. It runs index+2 for
  members 2–12 and index+1 for 14–58; members 0, 1, 13 carry 60, 61, 21 (21 also appears on member 20).
  Reads as an overlay id; its meaning is for phase 1.2. Code (stack-frame prologues) or pointer tables
  follow it directly.

### Compression
- None. No member is compressed; the stored payload is the loaded image.
- Loader path (evidence): `BinSeek` 0x80016858 stores destination, `size` (as remaining count) and
  absolute sector in globals, clears the alternate-handler flag (0x800E01C0 := 0), and starts the read
  0x80014E60 (CdlSetloc, mode 0xA0 = double speed + 2340-B sectors, CdlReadN). With that flag clear the
  ready callback is 0x800165A4, which per sector calls 0x80014D50. 0x80014D50: read the 12-B sector
  header, require its position = previous sector + 1 (else retry), then copy user data straight into
  the destination with CdGetSector: 512 words while remaining > 2048 (remaining −= 2048, dest += 2048);
  on the last sector, `(remaining + 3) / 4` words, the rest of the sector to a scratch buffer, remaining
  := 0. When remaining reaches 0 the callback pauses the drive and marks the read done. The waiter
  0x8001494C (called after every `BinSeek`) only spins a frame at a time, restarting a read that
  stalls for 600 frames; it does not touch the data. No transform runs between disc and destination.
- Corroboration: per-member byte entropy 5.1–5.7 bits/byte for 53 members (lower: 13, 21, 46, 51;
  the 4-B members 41, 42 are not measurable), the
  range of uncompressed MIPS code and data, far from the ~7.9 of compressed streams; MIPS prologues
  sit at offset 4 of many members.
- Callers (6): 0x80013CDC / 0x80013CF0 load member 0 or 1 to 0x801EA000; 0x80013D54, 0x80013E40 and
  0x80052E94 load to 0x800FA000 (members from halfword tables at 0x8006D9EC, 0x8006DC50; 0x80052E94
  passes 43, 44 or 45 directly); 0x80013E7C loads to the address held in the word at 0x80010000
  (member from the halfword table at 0x8006DB78). The five 0x80013xxx calls are followed directly by the
  waiter; 0x80052E94 is one step of a state machine that returns while the read runs. In every case the
  bytes reach the destination only through the copy above.
- The alternate ready callback 0x8001531C (flag 0x800E01C0 non-zero) is not reachable from
  `BinSeek`; it is a lead for `ROCK_X6.DAT` (phase 1.2), not part of this archive's semantics.

### Decoder (own pseudocode)
```
read_member(bin, k):
    sector, size = toc[k]                 # toc = 59 pairs at offset 0, zero pair at 59
    return bin[sector*2048 : sector*2048 + size]   # identity: no decompression
```
- Declared decompressed length: none exists. The only length is the TOC `size`, which is both the
  stored and the loaded length. The game copies `ceil(size/4)` words, so RAM receives up to 3 bytes of
  the (zero) sector padding past `size`; the extracted member is exactly `size` bytes.

### Length cross-check (T3 asserts all)
- 59 descriptors then a zero pair; every byte after it in the header is zero.
- `sector[0] = 2` (header is 2 sectors); `sector[i+1] = sector[i] + ceil(size[i]/2048)`;
  `sector[58] + ceil(size[58]/2048) = 813 = file size / 2048`; `size[i] ≥ 4`.
- Each extracted member's length = its `size`; the bytes in its last sector past `size` are zero.
- Manifest: `compressed: false` for all 59; `stored_size = size`; no `rock/<NN>.stored` file is written.

## ROCK_X6.DAT
Unknown. 50,913,280 B, 24,860 Form-1 sectors. Extracted and hashed whole; structure is for phase 1.2.

## XA / STR
Raw Form-2 streams (XA audio: `XA/BGM.XA`, `XA/DEMO.XA`; MDEC video: `STR/CAPLOGO.STR`,
`STR/X6OP.STR`). Extracted at 2336 B/sector and hashed; never demuxed, never part of the build
(PROJECT_CONTEXT.md:85). `ZNULL.DAT` (18,088 Form-1 sectors) is likewise extracted and hashed only.

## Manifest schema
`manifest/retail.jsonl` (tracked; hashes only, never bytes): one JSON object per file under
`extracted/retail/`, sorted by `path`, keys sorted, `\n`-terminated.
- Common: `kind` (`iso` | `rock` | `rock-stored`), `path` (relative to `extracted/retail`),
  `sha1` (40-hex), `size` (bytes written).
- `iso`: `lba`, `sectors`, `form` (1 | 2); path `iso/<ISO path>`.
- `rock`: `index` (0..58), `sector`, `stored_size`, `compressed` (bool); path `rock/<NN>.bin`.
- `rock-stored`: the stored form, `rock/<NN>.stored`, only for a compressed member (none on this medium).
- The firewall reads it as a hash source (`config/firewall.txt`); `tools/audit_public.py` fails any
  tracked file whose sha1 matches a record.
