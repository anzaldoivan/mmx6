# REVIEW — Phase 1.3, T3

What ran: `PY .run/t3/segcount.py` on the Mac (log .run/logs/t3seg.log); verify grep
Results at: config/segmentation.md
What the expert saw: segmentation rules written; 57 programs, 302 TUs (exe 246 = 230 lib + 16 gap; 56 overlays x 1)

Decisions needed:
- Accept the six rules and the containment tie-break as written — Recommended: accept
- Exe text end vs PDRESRES span (open question 1): extend the yaml text subsegment to 0x8006D5D4 in the yaml task — Recommended: extend
- The 15 small inter-lib gaps stay one TU each until the PsyQ version is pinned — Recommended: accept

Plan edits proposed:
- none
