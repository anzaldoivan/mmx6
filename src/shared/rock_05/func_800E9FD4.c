#include "common.h"

#define SCRATCH_4C (*(u8**)0x1F80004C)

extern u8 D_800F3CD0[];

void func_800E9FD4(u8* arg0) {
    if (*(s8*)(arg0 + 0x45) == 1) {
        arg0[6]++;
        return;
    }
    if (!(*(s8*)(arg0 + 2) & 0xF0)) {
        SCRATCH_4C[0x81] = -D_800F3CD0[arg0[0x47]];
        SCRATCH_4C[0x83] = D_800F3CD0[arg0[0x47]];
        return;
    }
    SCRATCH_4C[0x81] = 0;
    SCRATCH_4C[0x83] = D_800F3CD0[arg0[0x47]];
}
