"""extract_protos.py -- extract each prototype build's SYSTEM.CNF, boot executable and ROCK_X6.BIN (stdlib, host).

    extract_protos.py BUILDS_DIR
        BUILDS_DIR holds the developer's prototype images (`Rockman X6 (Sep 21, 2001 prototype)/X6_PROTOTYPE.bin`,
        `Mega Man X6 (Oct 30, 2001 prototype)/*.img`; raw 2352-byte sectors, read by iso9660.py). Writes
        extracted/<id>/ (ignored, game bytes; `make clean` never touches it), the --build folder of
        `imgadapter.py strings --proto` and `protodiff.py build`. Prints one line per file written.
"""
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "tools/mmx6"))
import iso9660  # noqa: E402

IMAGES = {"proto-2001-09-21": ("Rockman X6 (Sep 21, 2001 prototype)", "X6_PROTOTYPE.bin"),
          "proto-2001-10-30": ("Mega Man X6 (Oct 30, 2001 prototype)", "*.img")}


def main(builds):
    for bid, (folder, pat) in IMAGES.items():
        img = next((Path(builds) / folder).glob(pat))
        out = ROOT / "extracted" / bid
        out.mkdir(parents=True, exist_ok=True)
        with open(img, "rb") as f:
            es = iso9660.walk(f)
            cnf = next(e for e in es if e.path == "SYSTEM.CNF")
            boot = iso9660.extract_file(f, cnf).decode("ascii", "replace")
            exe = boot.split("cdrom:")[1].split(";")[0].lstrip("\\").strip()
            for e in es:
                if e.path in ("SYSTEM.CNF", exe, "ROCK_X6.BIN"):
                    (out / e.path).write_bytes(iso9660.extract_file(f, e))
                    print(bid, e.path, e.size)


if __name__ == "__main__":
    if len(sys.argv) != 2:
        sys.exit(__doc__)
    main(sys.argv[1])
