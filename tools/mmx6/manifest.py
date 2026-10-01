"""manifest.py — the hash manifest (JSONL): one record per file under extracted/retail/, hashes only, never bytes.

Deterministic: keys sorted, records sorted by `path`, '\\n' line ends. A `required:` firewall source.
"""

from __future__ import annotations

import hashlib
import json
from pathlib import Path


def record(kind: str, path: str, data: bytes, **fields) -> dict:
    return {"kind": kind, "path": path, "sha1": hashlib.sha1(data).hexdigest(), "size": len(data), **fields}


def write(records: list[dict], path: str | Path) -> str:
    """Write the manifest; return its sha1."""
    text = "".join(json.dumps(r, sort_keys=True) + "\n" for r in sorted(records, key=lambda r: r["path"]))
    p = Path(path)
    p.parent.mkdir(parents=True, exist_ok=True)
    p.write_bytes(text.encode("ascii"))
    return hashlib.sha1(text.encode("ascii")).hexdigest()
