# Build host for a PlayStation / PsyQ matching decompilation (x86-64 Linux, Ubuntu 24.04).
# Use it when the host is not x86-64 Linux, for example an arm64 Mac.
# Keep the source tree in a named volume. Do not build on a host bind mount.
FROM ubuntu:24.04@sha256:008173c23f95b170204355c12626cb5a965d779a7e1283b09e9cffbb1bf33ca3
ENV DEBIAN_FRONTEND=noninteractive LANG=C.UTF-8
RUN apt-get update && apt-get install -y --no-install-recommends \
      bchunk binutils-mipsel-linux-gnu bsdmainutils clang-format coreutils curl gcc-mipsel-linux-gnu \
      cpp-mipsel-linux-gnu git libelf-dev make ninja-build p7zip-full python3 python3-pip python3-venv \
      python3-dev build-essential unzip wget file xxd ca-certificates time cmake \
    && rm -rf /var/lib/apt/lists/*
# Splitter: splat64 pinned with its resolved disassembler deps (pip freeze of the first build), in a venv on PATH.
RUN python3 -m venv /opt/splat-venv \
    && /opt/splat-venv/bin/pip install --no-cache-dir "splat64[mips]==0.50.0" "spimdisasm==1.42.4" "rabbitizer==1.16.2"
ENV PATH=/opt/splat-venv/bin:$PATH
# Reference ISO extractor: mkpsxiso (Lameguy64, GPL-2.0) v2.30, pinned by commit; only dumpsxiso is installed.
RUN git clone https://github.com/Lameguy64/mkpsxiso.git /tmp/mkpsxiso \
    && cd /tmp/mkpsxiso && git checkout 54fb1644ed8741223583e2dcda358b75a205e214 \
    && git submodule update --init --recursive \
    && cmake -S . -B build -DCMAKE_BUILD_TYPE=Release && cmake --build build -j"$(nproc)" \
    && install -m 0755 "$(find build -type f -name dumpsxiso -perm -u+x | head -n1)" /usr/local/bin/dumpsxiso \
    && cd / && rm -rf /tmp/mkpsxiso
RUN git config --global --add safe.directory '*'
WORKDIR /work
# Build:  bash tools/docker/mx.sh build   (docker build --platform linux/amd64 -t mmx6-build -f tools/docker/Dockerfile tools/docker)
# Candidate cc1 set (phase 1.4, R1.4-001): decompals/old-gcc release 0.17 (psx/cdk builds) + 0.9 (plain gcc-2.7.2),
# sha256-pinned; only cc1 is kept, at /opt/cc/<name>/cc1. Every cc1 is a statically linked i386 ELF (`file`), so no
# i386 multiarch packages are needed.
RUN set -e; base=https://github.com/decompals/old-gcc/releases/download; mkdir -p /tmp/cc; \
    for spec in \
      2.7.2:0.9:e4699e65e65027cc28b99e216793b530a3d82dbc8c83cc6b27b255929361cd80 \
      2.7.2-psx:0.17:500a459b3485e885a8d302cac23c2a4632f3900e03a09153f6190699fd723571 \
      2.7.2-cdk:0.17:42bb0df96db11a9b5d2e23d78bdc962791f40046280d3d360da93fe5eef6f0bb \
      2.6.3-psx:0.17:01e6e8c4933414ea3f8d8e3bc766a1f5fafd4fc0110e0b75d1f691bd791989b1 \
      2.8.0-psx:0.17:1a3c956fe8aea5ebdb251749d95de2c84f023530584d7bd663744b5ec24050b7 \
      2.8.1-psx:0.17:f6f6e883942d4d3289d048236c672e71ed410e546aaae8ff655952f1567e1be0 \
      2.91.66-psx:0.17:f773a0a9659fa4ff74313ac4363d939312e8125675cd09ad9f8c1202f587f1fd \
      2.95.2-psx:0.17:932ed3669710a82b12570c29c46ff42989b6505b2af10db84d4551d55dfc0b1c; do \
      name=${spec%%:*}; rest=${spec#*:}; tag=${rest%%:*}; sha=${rest#*:}; \
      curl -fsSL -o /tmp/cc/a.tar.gz "$base/$tag/gcc-$name.tar.gz"; \
      echo "$sha  /tmp/cc/a.tar.gz" | sha256sum -c -; \
      mkdir -p "/opt/cc/$name"; tar -xzf /tmp/cc/a.tar.gz -C "/opt/cc/$name" cc1; chmod 0755 "/opt/cc/$name/cc1"; \
      file "/opt/cc/$name/cc1"; \
    done; rm -rf /tmp/cc
# Assembly post-processor: maspsx (mkst), pinned by commit; python3 stdlib only.
RUN git clone https://github.com/mkst/maspsx.git /opt/maspsx \
    && git -C /opt/maspsx checkout 7686f845a181700534c83c0419183e38aeb3e49c \
    && printf '#!/bin/sh\nexec python3 /opt/maspsx/maspsx.py "$@"\n' > /usr/local/bin/maspsx \
    && chmod 0755 /usr/local/bin/maspsx
# Decompile scaffold (m2c) and differ (asm-differ), pinned by commit (upstream HEAD at phase 1.3 T4); runtime deps at
# the versions of their poetry.lock files, in the splat venv (python3 there sees them).
RUN git clone https://github.com/matt-kempster/m2c.git /opt/m2c \
    && git -C /opt/m2c checkout 708d2d2cb2698f091a92492b328f73b24209f72d \
    && git clone https://github.com/simonlindholm/asm-differ.git /opt/asm-differ \
    && git -C /opt/asm-differ checkout 0dd09af8f8008f1f880327cf0aca3b26d2562ea2 \
    && /opt/splat-venv/bin/pip install --no-cache-dir "graphviz==0.20.3" "colorama==0.4.6" "watchdog==6.0.0" \
       "levenshtein==0.27.1" "rapidfuzz==3.13.0" "cxxfilt==0.3.0"
