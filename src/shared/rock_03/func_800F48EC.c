#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
extern u8 D_800F7BA0[][6];

void func_800F48EC(u8* arg0) {
    s32 t;
    u8 i;
    u8 v;

    if (*(s16*)(arg0 + 0x7C) == 0x78) {
        func_80016C48(2, 0x26, arg0);
    }
    t = *(u16*)(arg0 + 0x7C) + 1;
    *(s16*)(arg0 + 0x7C) = t;
    if ((s16)t == 0x1F4) {
        i = arg0[0x87]++;
        v = D_800F7BA0[arg0[0x86]][i];
        arg0[6] = 0;
        arg0[5] = v;
    }
}
