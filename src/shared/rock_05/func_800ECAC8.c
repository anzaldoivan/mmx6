#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);

void func_800ECAC8(void* arg0) {
    if (M2C_FIELD(arg0, s16*, 0x7C) != 0) {
        M2C_FIELD(arg0, s16*, 0x7C) = M2C_FIELD(arg0, u16*, 0x7C) - 1;
        return;
    }
    if (M2C_FIELD(arg0, s32*, 0x20) <= -0x20000) {
        M2C_FIELD(arg0, s32*, 0x20) = -0x20000;
    }
    ((void (*)(void*))func_8002D230)(arg0);
    if (M2C_FIELD(arg0, u8*, 0x70) & 2) {
        play_sound(2, 0x18, arg0);
        func_80012D9C(3);
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0xFFFF0000;
        M2C_FIELD(arg0, s32*, 0x2C) = 0x1000;
        M2C_FIELD(arg0, s16*, 0x7C) = 0x3C;
        func_8002943C(0x3C, 2, 1);
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    }
}
