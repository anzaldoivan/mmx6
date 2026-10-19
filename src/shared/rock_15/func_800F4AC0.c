#include "common.h"

#define M2C_UNK s32

M2C_UNK func_80017A04();
extern s32 D_800F6F60[];
extern M2C_UNK D_800F6F64;

void func_800F4AC0(u8* arg0) {
    s8 st;

    func_80017A04();
    st = arg0[0x45];
    if (st == 2) {
        *(s32**)(arg0 + 0x50) = D_800F6F60;
        *(s32*)(arg0 + 0x24) = 0;
        *(s32*)(arg0 + 0x2C) = -0x1000;
        *(s32*)(arg0 + 0x20) = 0;
        *(s32*)(arg0 + 0x28) = 0;
        arg0[6]++;
    } else if (st == 1) {
        *(s32**)(arg0 + 0x50) = &D_800F6F64;
        *(s32*)(arg0 + 0x24) = 0;
        *(s32*)(arg0 + 0x2C) = 0x1000;
        *(s32*)(arg0 + 0x20) = 0;
        *(s32*)(arg0 + 0x28) = 0;
        arg0[6]++;
    }
}
