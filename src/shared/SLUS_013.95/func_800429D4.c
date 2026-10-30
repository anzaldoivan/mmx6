#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
void func_80042D98(s8* arg0);
extern u8 D_80075EBC[][8];

M2C_UNK func_800429D4(s8* arg0) {
    arg0[6] = 0;
    if ((arg0[2] & 0xF0) == 0x20) {
        func_80042D98(arg0);
        if (*(s32*)(arg0 + 0x80) != 0) {
            ((void (*)(void*, s32))set_animation)(arg0, 1);
            arg0[5] = 6;
            arg0[6] = 3;
            return;
        }
    }
    if (D_80075EBC[(u8)arg0[2] & 0xF][(u8)arg0[0x8F]] == 8) {
        arg0[0x8F] = 0;
    }
    arg0[5] = D_80075EBC[(u8)arg0[2] & 0xF][(u8)arg0[0x8F]];
    arg0[0x8F]++;
}
