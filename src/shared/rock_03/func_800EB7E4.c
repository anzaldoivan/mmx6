#include "common.h"
#define M2C_UNK s32

#define SPAD (*(u8**)0x1F80004C)

M2C_UNK func_800179A4(void*, M2C_UNK);

void func_800EB7E4(u8* arg0) {
    *(u16*)(SPAD + 0x8A) = *(u16*)(arg0 + 0xA);
    *(s16*)(SPAD + 0x8C) = *(s16*)(arg0 + 0xE) - 0x10;
    *(s32*)(SPAD + 0x80) = 0xC00;
    func_800179A4(arg0, 6);
    *(u8*)(SPAD + 0x88) = 1;
    *(s16*)(arg0 + 0x7C) = 0x14;
    *(s16*)(arg0 + 0x7E) = 8;
    arg0[6]++;
}
