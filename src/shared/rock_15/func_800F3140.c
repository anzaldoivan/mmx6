#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800179A4(void*, M2C_UNK);

void func_800F3140(void* arg0) {
    u16 t;

    t = *(u16*)((u8*)arg0 + 0x8E);
    *(u16*)((u8*)arg0 + 0x8E) = t + 1;
    if ((s16)t >= 0x1F) {
        ((void (*)(void*, s32))func_800179A4)(arg0, 6);
        *(u16*)((u8*)arg0 + 0x8E) = 0;
        ((u8*)arg0)[6]++;
    }
}
