# diff_settings.py — asm-differ project settings (asm-differ convention: read from the cwd by /opt/asm-differ/diff.py).
# Run through tools/mmx6/diff.sh in the container from /work. Binary mode: baseimg expected/build/<bin> (`make
# expected`, container-only, never pulled: P1.3-1) vs myimg build/<bin>, function located through the ld map
# build/<b>.map. Program: env MX6_PROG (default SLUS_013.95); an overlay rock_NN diffs build/rock/NN.bin with map
# build/rock_NN.map. asm-differ never runs make here (no -m).
import os


def apply(config, args):
    prog = os.environ.get("MX6_PROG", "SLUS_013.95")
    img = f"build/rock/{prog[5:]}.bin" if prog.startswith("rock_") else f"build/{prog}"
    config["arch"] = "mipsel"  # PSX R3000A, little-endian (asm-differ "mips" is big-endian)
    config["baseimg"] = f"expected/{img}"
    config["myimg"] = img
    config["mapfile"] = f"build/{prog}.map"
    config["map_format"] = "gnu"
    config["objdump_executable"] = "mipsel-linux-gnu-objdump"
    config["source_directories"] = ["src", "include"]
