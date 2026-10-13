#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800179A4(void*, M2C_UNK);
void func_800FA150(void*, s32);
extern s16 D_800970AA;
extern u8 D_800E9B8C[];

void func_800F97BC(void* arg0) {
    s8 buf[4];

    __builtin_memcpy(buf, D_800E9B8C, 4);
    func_800179A4(arg0, 8);
    func_800FA150(arg0, 1);
    if (*(s16*)((u8*)arg0 + 0xA) < D_800970AA) {
        *((u8*)arg0 + 0x15) = 0x40;
        *(s32*)((u8*)arg0 + 0x20) = 0xFFFB0000;
        *(s32*)((u8*)arg0 + 0x28) = -0x4000;
    } else {
        *((u8*)arg0 + 0x15) = 0;
        *(s32*)((u8*)arg0 + 0x20) = 0x50000;
        *(s32*)((u8*)arg0 + 0x28) = -0x4000;
    }
    *(s32*)((u8*)arg0 + 0x24) = 0;
    *(s32*)((u8*)arg0 + 0x2C) = 0;
    *((u8*)arg0 + 6) = 1;
}
