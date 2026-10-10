"""iso9660.py — read a MODE2/2352 raw image: sectors, the ISO9660 directory tree, file bodies.

Raw sector (2352 B): sync 12 + header 4 + subheader 8 + user data. Form 1 user data is 2048 B; Form 2 is 2324 B,
and a Form 2 file is written whole at 2336 B/sector (subheader..EDC), the dumpsxiso convention (cookbook C0007).
Form is taken from the XA attribute in the directory record's system-use area and cross-checked against the
subheader submode bit 5 (Form 2) of every sector of the file.
"""

from __future__ import annotations

import struct
from dataclasses import dataclass
from typing import BinaryIO

RAW = 2352
USER = 2048
FORM2_RAW = 2336  # subheader (8) + 2324 data + EDC (4)
SYNC = b"\x00" + b"\xff" * 10 + b"\x00"
SUBMODE_FORM2 = 0x20
XA_FORM2 = 0x1000  # XA attribute (big-endian): mode 2 form 2
XA_INTERLEAVED = 0x2000
XA_DIR = 0x8000


@dataclass(frozen=True)
class Entry:
    path: str  # ISO path, '/'-separated, ';1' stripped
    lba: int
    size: int  # ISO directory-record size
    form2: bool

    @property
    def sectors(self) -> int:
        return (self.size + USER - 1) // USER


def read_sector(f: BinaryIO, lba: int) -> bytes:
    """The 2352-B raw sector `lba`; asserts the sync pattern and MODE2."""
    f.seek(lba * RAW)
    raw = f.read(RAW)
    if len(raw) != RAW or raw[:12] != SYNC or raw[15] != 2:
        raise ValueError(f"lba {lba}: not a MODE2/2352 sector")
    return raw


def _user(f: BinaryIO, lba: int) -> bytes:
    return read_sector(f, lba)[24 : 24 + USER]


def _records(f: BinaryIO, lba: int, size: int):
    for i in range((size + USER - 1) // USER):
        sec = _user(f, lba + i)
        off = 0
        while off < USER and sec[off]:
            n = sec[off]
            yield sec[off : off + n]
            off += n


def _xa_attr(rec: bytes) -> int | None:
    nlen = rec[32]
    su = 33 + nlen + (1 - nlen % 2)  # name padded to an even offset
    xa = rec[su : su + 14]
    if len(xa) == 14 and xa[6:8] == b"XA":
        return struct.unpack(">H", xa[4:6])[0]
    return None


def _submode_form2(f: BinaryIO, lba: int, sectors: int) -> set[bool]:
    return {bool(read_sector(f, lba + i)[18] & SUBMODE_FORM2) for i in range(sectors)}


def walk(f: BinaryIO) -> list[Entry]:
    """Every file under the root directory, sorted by path. Raises on a form disagreement."""
    pvd = _user(f, 16)
    if pvd[0] != 1 or pvd[1:6] != b"CD001":
        raise ValueError("no primary volume descriptor at lba 16")
    root = pvd[156:190]
    out: list[Entry] = []
    stack = [("", struct.unpack_from("<I", root, 2)[0], struct.unpack_from("<I", root, 10)[0])]
    seen = set()
    while stack:
        prefix, lba, size = stack.pop()
        if lba in seen:
            continue
        seen.add(lba)
        for rec in _records(f, lba, size):
            nlen = rec[32]
            name = rec[33 : 33 + nlen]
            if name in (b"\x00", b"\x01"):
                continue
            name = name.decode("ascii").split(";")[0]
            rlba = struct.unpack_from("<I", rec, 2)[0]
            rsize = struct.unpack_from("<I", rec, 10)[0]
            path = f"{prefix}{name}"
            if rec[25] & 0x02:
                stack.append((path + "/", rlba, rsize))
                continue
            attr = _xa_attr(rec)
            form2 = attr is not None and bool(attr & (XA_FORM2 | XA_INTERLEAVED))
            e = Entry(path, rlba, rsize, form2)
            sub = _submode_form2(f, rlba, e.sectors)
            if form2 and True not in sub or not form2 and sub != {False}:
                raise ValueError(f"{path}: XA attribute {attr!r} disagrees with sector submode {sub}")
            out.append(e)
    return sorted(out, key=lambda e: e.path)


def extract_file(f: BinaryIO, entry: Entry) -> bytes:
    """Form 1: 2048 B/sector truncated to size. Form 2: 2336 B/sector x sectors (C0007)."""
    if entry.form2:
        return b"".join(read_sector(f, entry.lba + i)[16:] for i in range(entry.sectors))
    data = b"".join(_user(f, entry.lba + i) for i in range(entry.sectors))
    return data[: entry.size]
