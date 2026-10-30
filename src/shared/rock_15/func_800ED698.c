#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
extern s32 D_8007429C;
extern M2C_UNK D_8007433C;
extern void* D_800F70E4;

void func_800ED698(void* arg0) {
    s32 t;
    s8 one;
    s32 four;

    M2C_FIELD(arg0, s8*, 3) = 0;
    one = M2C_FIELD(D_800F70E4, s8*, 4);
    if (one != 1) {
        M2C_FIELD(arg0, s8*, 4) = 2;
        return;
    }
    four = 4;
    M2C_FIELD(arg0, s8*, 0x60) = 0;
    M2C_FIELD(arg0, s8*, 0x5C) = one;
    M2C_FIELD(arg0, s8*, 0x16) = four;
    M2C_FIELD(arg0, s8*, 0x67) = one;
    M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
    M2C_FIELD(arg0, s32*, 0x68) = 0;
    M2C_FIELD(arg0, s32*, 0x50) = 0;
    M2C_FIELD(arg0, s32*, 0x54) = 0;
    M2C_FIELD(arg0, s8*, 4) = one;
    M2C_FIELD(arg0, s8*, 5) = 0;
    M2C_FIELD(arg0, s8*, 6) = 0;
    M2C_FIELD(arg0, s8*, 7) = 0;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    t = M2C_FIELD(arg0, s8*, 2) & 0xF0;
    if (t == 0) {
        ((void (*)(void*, s32))set_animation)(arg0, 9);
        M2C_FIELD(arg0, s8*, 0x60) = 0xA;
        M2C_FIELD(arg0, s8*, 0x16) = four;
        M2C_FIELD(arg0, s8*, 5) = 0;
    } else if (t == 0x10) {
        ((void (*)(s32, s32, void*))play_sound)(2, 0x87, arg0);
        ((void (*)(void*, s32))set_animation)(arg0, 0xF);
        M2C_FIELD(arg0, s8*, 0x60) = 6;
        M2C_FIELD(arg0, s8*, 0x16) = four;
        M2C_FIELD(arg0, s8*, 5) = one;
    } else if (t == 0x20) {
        ((void (*)(void*, s32))set_animation)(arg0, 0x12);
        M2C_FIELD(arg0, s8*, 0x16) = four;
        M2C_FIELD(arg0, s8*, 5) = 2;
    } else if (t == 0x30) {
        ((void (*)(void*, s32))set_animation)(arg0, 0xE);
        M2C_FIELD(arg0, void**, 0x58) = &D_8007429C;
        M2C_FIELD(arg0, s8*, 0x60) = 6;
        M2C_FIELD(arg0, s8*, 0x16) = four;
        M2C_FIELD(arg0, s8*, 5) = 3;
        M2C_FIELD(arg0, s16*, 0x8C) = M2C_FIELD(arg0, s16*, 0xA);
        M2C_FIELD(arg0, s16*, 0x8E) = M2C_FIELD(arg0, s16*, 0xE);
    }
}
