---
name: typecheck-fnptr-keyer-first
description: Before banking a body that needs a function-pointer typedef, extend typecheck.py's keyer; it refuses them as unkeyable
---

# Extend the type keyer before the first function-pointer type

Captured 2026-10-01 from phase 1.6 T3 (`workflow:` gotcha).

## When to use
a banking task needs a function-pointer typedef in include/mmx6/types.h

## Steps
- `tools/mmx6/typecheck.py` keys scalars by (width, signed) and structs by (size, ordered (offset, width)); a def it cannot key (a function-pointer typedef) is refused `unkeyable`, so th-types and the fleet go red.
- Workaround already in use (T4): declare tables as `extern void (*D_x[])(s8*)` in the body, no typedef; if that suffices, stop here.
- Otherwise extend the keyer first, as its own coder change: key a function pointer by (return width, ordered param widths); add a planted control (two fn-pointer typedefs with one shape under two names → duplicate refused); keep `TYPES CONTROL OK`.
- Then add the typedef to include/mmx6/types.h with its `// evidence:` line and bank the body.
