#include "common.h"
#define M2C_UNK s32

#define SCRATCH_4C (*(u8**)0x1F80004C)

M2C_UNK func_800179A4(void*, M2C_UNK);
extern u8 D_800F3CD0[];

void func_800E9A04(u8* arg0) {
    if (SCRATCH_4C[0x84] != 0) {
        if (!(*(s8*)(arg0 + 2) & 0xF0)) {
            func_800179A4(arg0, 1);
        } else {
            func_800179A4(arg0, 3);
        }
        SCRATCH_4C[0x85] = 1;
        *(s16*)(arg0 + 0x7E) = 0xC8;
        arg0[6]++;
    } else if (--*(s16*)(arg0 + 0x7C) == 0) {
        if (!(*(s8*)(arg0 + 2) & 0xF0)) {
            func_800179A4(arg0, 1);
        } else {
            func_800179A4(arg0, 3);
        }
        arg0[6]++;
    }
    if (!(*(s8*)(arg0 + 2) & 0xF0)) {
        SCRATCH_4C[0x81] = -D_800F3CD0[arg0[0x47]];
        SCRATCH_4C[0x83] = D_800F3CD0[arg0[0x47]];
        return;
    }
    SCRATCH_4C[0x81] = 0;
    SCRATCH_4C[0x83] = D_800F3CD0[arg0[0x47]];
}
