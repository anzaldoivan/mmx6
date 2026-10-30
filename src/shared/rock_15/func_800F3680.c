#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8003D330();
extern s8 D_800CCF5C;

void func_800F3680(u8* arg0) {
    s8 n;

    if (--*(s16*)(arg0 + 0x7C) == 0) {
        play_sound(0, 0xE, 0);
        *(u16*)(arg0 + 0x7C) = 2;
    }
    if (++*(s8*)(arg0 + 0x5C) >= (n = D_800CCF5C)) {
        *(u16*)(arg0 + 0x7C) = 0;
        *(u16*)(arg0 + 0x7E) = 0;
        func_8003D330(n);
        arg0[5] = 9;
        arg0[6] = 0;
    }
}
