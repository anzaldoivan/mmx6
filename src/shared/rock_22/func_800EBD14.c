#include "common.h"

#define M2C_UNK s32

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
extern s8 D_8009724F;

void func_800EBD14(u8* arg0) {
    s16 t;

    t = (*(s16*)(arg0 + 0x7C))++;
    if (t >= 0x65) {
        D_8009724F = 1;
        *(u16*)(arg0 + 0x7C) = 0;
        *(u16*)(arg0 + 0x7E) = 1;
        ((void (*)(s32, s32, void*))play_sound)(5, 1, arg0);
        ((void (*)(s32))func_80012D9C)(4);
        arg0[6]++;
    }
}
