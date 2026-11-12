#include "common.h"
#include "mmx6/state.h"

extern u16 D_800F1100[][2];

void func_800F05C4(u8* arg0) {
    arg0[3] = 1;
    *(u16*)(arg0 + 0xA) = D_800F1100[D_80097420.transition.selection][0];
    *(s16*)(arg0 + 0xE) = D_800F1100[D_80097420.transition.selection][1] - 3;
}
