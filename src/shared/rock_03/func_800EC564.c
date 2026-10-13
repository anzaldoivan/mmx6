#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800179A4(void*, M2C_UNK); /* extern */
extern s32 D_800970A8;

void func_800EC564(u8* arg0) {
    if (--arg0[0x80] == 0) {
        ((void (*)(void*, s32))func_800179A4)(arg0, 3);
        if (*(s32*)(arg0 + 8) > D_800970A8) {
            arg0[0x15] = 0;
            *(s32*)(arg0 + 0x20) = 0xFFFF0000;
        } else {
            arg0[0x15] = 0x40;
            *(s32*)(arg0 + 0x20) = 0x10000;
        }
        arg0[0x80] = 0x80;
        arg0[6] = 4;
        arg0[7] = 0;
    }
}
