# diff_settings.py — asm-differ project settings (asm-differ convention: read from the cwd by /opt/asm-differ/diff.py).
# Run through tools/mmx6/diff.sh in the container from /work. Binary mode: baseimg expected/<v>/<bin> (`make
# expected`, container-only, never pulled: P1.3-1) vs myimg build/<v>/<bin>, function located through the ld map
# build/<v>/<b>.map (paths from tools/mmx6/paths.py: VERSION, BUILD_ROOT). Program: env MX6_PROG (default
# main: build/<v>/<MAIN_EXE> with map build/<v>/main.map); an overlay rock_NN diffs build/<v>/rock/NN.bin with map build/<v>/rock_NN.map. asm-differ never
# runs make here (no -m).
import os
import sys

sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), "tools", "mmx6"))
from paths import BUILD, EXPECTED, MAIN_EXE  # noqa: E402  (the version axis, 3.3 T37)


def apply(config, args):
    prog = os.environ.get("MX6_PROG", "main")
    rel = f"rock/{prog[5:]}.bin" if prog.startswith("rock_") else MAIN_EXE
    img = f"{BUILD}/{rel}"
    config["arch"] = "mipsel"  # PSX R3000A, little-endian (asm-differ "mips" is big-endian)
    config["baseimg"] = f"{EXPECTED}/{rel}"
    config["myimg"] = img
    config["mapfile"] = f"{BUILD}/{prog}.map"
    config["map_format"] = "gnu"
    config["objdump_executable"] = "mipsel-linux-gnu-objdump"
    config["source_directories"] = ["src", "include"]
