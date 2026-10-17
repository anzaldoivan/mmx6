#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();
extern M2C_UNK D_80074C9C;
extern s16 D_800F6AF0;

void func_800F2604(u8* arg0) {
    s32 temp_v0;

    ((void (*)())func_80017A04)();
    temp_v0 = *(u16*)(arg0 + 0x7C) - 1;
    *(u16*)(arg0 + 0x7C) = temp_v0;
    if ((temp_v0 << 0x10) == 0) {
        D_800F6AF0 = 0;
        *(s32**)(arg0 + 0x58) = &D_80074C9C;
        arg0[5] = 2;
        arg0[6] = 0;
    }
}
