#include "common.h"

#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();

#define SPAD4C (*(u8**)0x1F80004C)

void func_800F7C64(u8* arg0) {
    ((M2C_UNK(*)())func_80017A04)();
    if ((s8)arg0[0x45] == 1) {
        s32 t;
        play_sound(2, 0x1E, arg0);
        t = arg0[6];
        *(s16*)(arg0 + 0x7C) = 0;
        t++;
        arg0[6] = t;
        return;
    }
    if (SPAD4C[0x8A] != 0x11) {
        play_sound(2, 0x3D, arg0);
        set_animation(arg0, 9);
        {
            // !FAKE: depin: dropping it breaks the match (36/38)
            register s32 t asm("$2") = 5;
            arg0[6] = t;
        }
        *(s16*)(arg0 + 0x7C) = 0;
    }
}

#undef SPAD4C
