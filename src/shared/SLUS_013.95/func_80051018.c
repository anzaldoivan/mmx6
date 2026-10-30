#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
extern s16 D_80090D5C;
extern s16 D_80097430;
extern u8 D_800C4560;
extern s16 D_800CF854;

void func_80051018(u8* arg0) {
    s32 two;
    s32 n;

    if ((s16)-- * (u16*)(arg0 + 0xA0) == -1) {
        two = 2;
        *(u16*)(arg0 + 0xA0) = two;
        D_800CF854++;
        D_80097430 += 0x20;
        D_80090D5C += 0x400;
        D_800C4560 |= 1;
        n = D_800CF854;
        if ((u16)n >= 0x1F) {
            play_sound(0, 0x10, arg0);
            arg0[5] = two;
        }
    }
}
