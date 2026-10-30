#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();
extern M2C_UNK D_800743DC;

void func_800F53CC(void* arg0) {
    s32 t;

    ((void (*)())func_80017A04)();
    if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
        M2C_FIELD(arg0, s32*, 8) = M2C_FIELD(arg0, s32*, 8) - 0x8000;
    } else {
        M2C_FIELD(arg0, s32*, 8) = M2C_FIELD(arg0, s32*, 8) + 0x8000;
    }
    t = M2C_FIELD(arg0, u8*, 0x92) - 1;
    M2C_FIELD(arg0, u8*, 0x92) = t;
    if ((s8)t == 0) {
        M2C_FIELD(arg0, void**, 0x58) = &D_800743DC;
        M2C_FIELD(arg0, u8*, 5) = 2;
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        M2C_FIELD(arg0, s16*, 0x8C) = 0;
        if (M2C_FIELD(arg0, s8*, 0x67) != 0) {
            M2C_FIELD(arg0, s32*, 0x24) = 0xFFFE0000;
            M2C_FIELD(arg0, s32*, 0x2C) = 0x2000;
            M2C_FIELD(arg0, u8*, 6) = 0;
            return;
        }
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
        ((void (*)(void*, s32))set_animation)(arg0, 5);
        M2C_FIELD(arg0, u8*, 6) = 1;
    }
}
