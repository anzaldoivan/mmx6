"""extract.py — extract the retail medium into extracted/retail/ and write the hash manifest (`make extract`).

  extract.py --cue <cue> --out extracted/retail --manifest manifest/retail.jsonl [--medium config/medium.sha1]

Refuses a bin whose sha1 is not the --medium hash (G28) and an --out outside extracted/; recreates --out; writes
every ISO file to <out>/iso/<ISO path> and every ROCK_X6.BIN member to <out>/rock/<NN>.bin; checks
the SLUS header; prints denominators and the manifest sha1.
rc 0 only when every cross-check passes.
"""

from __future__ import annotations

import argparse
import hashlib
import re
import shutil
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "tools"))

from mmx6 import iso9660, manifest, rock  # noqa: E402

EXE = "SLUS_013.95"
EXE_PC0 = 0x80054AD8
EXE_TADDR = 0x80010000
ROCK = "ROCK_X6.BIN"


def fail(msg: str) -> int:
    print(f"extract: FAIL: {msg}")
    return 1


def parse_cue(cue: Path) -> Path:
    text = cue.read_text()
    m = re.search(r'^\s*FILE\s+"([^"]+)"\s+BINARY', text, re.M)
    if not m or not re.search(r"^\s*TRACK\s+01\s+MODE2/2352", text, re.M):
        raise ValueError(f"{cue}: expected FILE \"...\" BINARY with TRACK 01 MODE2/2352")
    return cue.parent / m.group(1)


def sha1_file(p: Path) -> str:
    h = hashlib.sha1()
    with p.open("rb") as f:
        while chunk := f.read(1 << 22):
            h.update(chunk)
    return h.hexdigest()


def rock_members(data: bytes) -> list[tuple[str, bytes, dict]]:
    """ROCK_X6.BIN members as (path, data, fields); raises ValueError naming the member on any cross-check failure."""
    return [
        (f"rock/{m.index:02d}.bin", d, {"index": m.index, "sector": m.sector, "stored_size": m.size, "compressed": False})
        for m, d in rock.members(data)
    ]


def main(argv: list[str] | None = None) -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--cue", required=True, type=Path)
    ap.add_argument("--out", required=True, type=Path)
    ap.add_argument("--manifest", required=True, type=Path)
    ap.add_argument("--medium", type=Path, default=ROOT / "config" / "medium.sha1")
    a = ap.parse_args(argv)

    out = a.out.resolve()
    if not out.is_relative_to(ROOT / "extracted") or out == ROOT / "extracted":
        return fail(f"--out {a.out} is not inside extracted/")

    want = a.medium.read_text().split()[0].lower()
    bin_path = parse_cue(a.cue)
    got = sha1_file(bin_path)
    if got != want:
        return fail(f"medium sha1 {got} != {want} ({a.medium}): unknown medium refused")
    print(f"medium: {bin_path.name} sha1 {got} OK")

    if out.exists():
        shutil.rmtree(out)
    out.mkdir(parents=True)

    records: list[dict] = []
    members = 0
    sectors = 0
    with bin_path.open("rb") as f:
        entries = iso9660.walk(f)
        for e in entries:
            data = iso9660.extract_file(f, e)
            rel = f"iso/{e.path}"
            dest = out / rel
            dest.parent.mkdir(parents=True, exist_ok=True)
            dest.write_bytes(data)
            records.append(manifest.record("iso", rel, data, lba=e.lba, sectors=e.sectors, form=2 if e.form2 else 1))
            sectors += e.sectors
            if e.path == EXE:
                magic = data[:8]
                pc0, taddr = struct.unpack_from("<I", data, 0x10)[0], struct.unpack_from("<I", data, 0x18)[0]
                if magic != b"PS-X EXE" or pc0 != EXE_PC0 or taddr != EXE_TADDR:
                    return fail(f"{EXE} header: magic {magic!r} pc0 {pc0:#x} t_addr {taddr:#x}")
                print(f"{EXE}: PS-X EXE pc0 {pc0:#x} t_addr {taddr:#x} OK")
            if e.path == ROCK:
                try:
                    rock_recs = rock_members(data)
                except ValueError as err:
                    return fail(f"{ROCK}: {err}")
                for rel, mdata, fields in rock_recs:
                    (out / rel).parent.mkdir(parents=True, exist_ok=True)
                    (out / rel).write_bytes(mdata)
                    records.append(manifest.record("rock", rel, mdata, **fields))
                    members += 1
    if EXE not in {e.path for e in entries}:
        return fail(f"{EXE} not on the medium")

    msha = manifest.write(records, a.manifest)
    nbytes = sum(r["size"] for r in records)
    print(f"denominators: files {len(entries)} sectors {sectors} bytes {nbytes} members {members}")
    for r in records:
        print(f"  {r['path']} size {r['size']} sectors {r.get('sectors', '-')} form {r.get('form', '-')}")
    print(f"manifest: {a.manifest} records {len(records)} sha1 {msha}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
