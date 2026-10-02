# Third-party components

Code or data adapted from other projects, with its upstream, the commit it was taken from, its license and the paths
it occupies. Only sources whose license allows it may appear here (G102): today that means
[sozud/mmx4](https://github.com/sozud/mmx4) (AGPL-3.0), and only for functions proven shared with Mega Man X6 by a
signature or byte comparison, each banked through the byte gate. Facts used without copying (addresses, names as
leads, formats) are credited in `README.md` and tracked in `docs/prior-art.md`, not here.

Toolchains the build downloads at run time (and never commits) are listed with the pinned version and the checksum the
build verifies, once their phase pins them.

| Component | Upstream | Commit / version | License | Paths here | Basis (proof it is shared) |
|---|---|---|---|---|---|

*(none yet)*

## Build-image tools (not distributed)
Built inside the `mmx6-build` image only; no source or binary of theirs is committed, shipped, or occupies a path here.
- mkpsxiso (`dumpsxiso`): https://github.com/Lameguy64/mkpsxiso, commit `54fb1644ed8741223583e2dcda358b75a205e214`
  (tag v2.30), GPL-2.0. Used as the reference ISO extractor to cross-check `make extract` (T4).
- decomp-permuter: https://github.com/simonlindholm/decomp-permuter, commit `059609d4aec73eb0650726772954e1ad575825f8`,
  MIT. At `/opt/decomp-permuter`, never edited; run through `tools/mmx6/permute.py` with our masked scorer (phase 1.7 T7).
