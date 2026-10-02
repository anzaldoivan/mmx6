/* func_80042F20 — stored draft (T7.c2): the m2c scaffold (tools/mmx6/decompile.py)
 * hand-made to compile under the pin; kept non-matching as the permuter's seed.
 * TU 32208. Never in a default build (G4). Our own C, no game bytes. */
#include "common.h"

extern u8 D_80075FE8[];
extern s8 D_800CCED0[];

u8 func_80042F20(void) {
    return *(D_800CCED0[0xD] + (D_800CCED0[0xC] * 2) + D_80075FE8);
}
