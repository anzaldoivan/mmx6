#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

M2C_UNK animate_object();
extern s16 D_800F6AF0;

void func_800F2604(u8* arg0) {
    s32 temp_v0;

    ((void (*)())animate_object)();
    temp_v0 = *(u16*)(arg0 + 0x7C) - 1;
    *(u16*)(arg0 + 0x7C) = temp_v0;
    if ((temp_v0 << 0x10) == 0) {
        D_800F6AF0 = 0;
        *(s32**)(arg0 + 0x58) = &D_80074C9C;
        arg0[5] = 2;
        arg0[6] = 0;
    }
}
