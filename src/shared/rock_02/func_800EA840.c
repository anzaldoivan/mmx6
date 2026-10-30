#include "common.h"
#define M2C_UNK s32
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8002D230();

#define A840_SPAD (*(u8**)0x1F80004C)
#define A840_H(p, o) (*(s16*)((u8*)(p) + (o)))
#define A840_UH(p, o) (*(u16*)((u8*)(p) + (o)))
#define A840_UB(p, o) (*(u8*)((u8*)(p) + (o)))

void func_800EA840(void* arg0) {
    func_8002D230(arg0);
    if (A840_H(arg0, 0xE) <= A840_H(A840_SPAD, 0x80)) {
        A840_UH(arg0, 0xE) = A840_UH(A840_SPAD, 0x80);
        A840_UB(A840_SPAD, 0x83) = 0;
        A840_UB(arg0, 5) = 2;
        A840_UB(arg0, 6) = 0;
        return;
    }
    if (--A840_H(arg0, 0x7C) == 0) {
        A840_UH(arg0, 0x7C) = 0x3C;
        play_sound(2, 3, arg0);
    }
}

#undef A840_SPAD
#undef A840_H
#undef A840_UH
#undef A840_UB
