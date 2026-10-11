#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_80030ECC(void*);
M2C_UNK func_80049E50(void*);
extern s32 D_800F7DE4;
extern s32 D_800F7DE8;
extern s32 D_800F7E30;

void func_800F59A8(u8* arg0) {
    if (D_800F7DE4 != 0) {
        goto set2;
    }
    if (D_800F7DE8 != 0 || D_800F7E30 != 0) {
        goto set2;
    }
    switch (*(s8*)(arg0 + 5)) {
    case 0:
        if ((--arg0[7] << 24) == 0) {
            func_80049E50(arg0);
            arg0[5]++;
        }
        break;
    case 1:
        if ((s8)++arg0[7] != 0x1E) {
            goto call;
        }
    set2:
        arg0[4] = 2;
        break;
    call:
        func_80030ECC(arg0);
        func_8002CCB0(arg0, 0x10, 0x10);
        break;
    }
}
