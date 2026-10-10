"""rock.py — ROCK_X6.BIN member archive (docs/formats.md "ROCK_X6.BIN").

Header = 2 sectors: 59 `{u32 sector, u32 size}` LE descriptors, a zero pair, zero to the end.
No member is compressed: `decompress` is the identity with a length check. `members` asserts every
"Length cross-check" fact; any failure raises ValueError naming the member index.
"""

from __future__ import annotations

import struct
from typing import NamedTuple

SECTOR = 2048
HEADER = 2 * SECTOR
COUNT = 59


class Member(NamedTuple):
    index: int
    sector: int
    size: int


def read_toc(buf: bytes) -> list[Member]:
    """Parse and check the TOC against the file `buf` (sector[0]=2, contiguity, end = file, size >= 4, terminator)."""
    if len(buf) < HEADER or len(buf) % SECTOR:
        raise ValueError(f"ROCK_X6.BIN: size {len(buf)} is not a whole number of sectors >= {HEADER}")
    toc = [Member(i, *struct.unpack_from("<II", buf, i * 8)) for i in range(COUNT)]
    if any(buf[COUNT * 8 : HEADER]):
        raise ValueError(f"member {COUNT}: terminator pair / header tail not zero")
    nsec = len(buf) // SECTOR
    want = HEADER // SECTOR
    for m in toc:
        if m.sector != want:
            raise ValueError(f"member {m.index}: sector {m.sector} != expected {want} (contiguity)")
        if m.size < 4:
            raise ValueError(f"member {m.index}: size {m.size} < 4")
        want = m.sector + -(-m.size // SECTOR)
        if want > nsec:
            raise ValueError(f"member {m.index}: extent ends at sector {want} > file {nsec}")
    if want != nsec:
        raise ValueError(f"member {COUNT - 1}: last end sector {want} != file sectors {nsec}")
    return toc


def decompress(stored: bytes, size: int, index: int | None = None) -> bytes:
    """Identity (no compression on this medium); refuses a stored length that is not `size`."""
    if len(stored) != size:
        raise ValueError(f"member {index}: stored length {len(stored)} != size {size}")
    return stored


def members(buf: bytes) -> list[tuple[Member, bytes]]:
    """Every member's bytes, cross-checked: exact length and zero last-sector padding."""
    out = []
    for m in read_toc(buf):
        start = m.sector * SECTOR
        end = start + -(-m.size // SECTOR) * SECTOR
        data = decompress(buf[start : start + m.size], m.size, m.index)
        if any(buf[start + m.size : end]):
            raise ValueError(f"member {m.index}: last-sector padding not zero")
        out.append((m, data))
    return out
