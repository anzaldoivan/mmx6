#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002D230(void*);
extern s16 D_80097222;

void func_800ED424(void* arg0) {
    if (M2C_FIELD(arg0, s16*, 0x7C) != 0) {
        M2C_FIELD(arg0, u8*, 0x8D) = 1;
        M2C_FIELD(arg0, s16*, 0x7C) -= 1;
        return;
    }
    M2C_FIELD(arg0, u8*, 0x8D) = 0;
    if (M2C_FIELD(arg0, s32*, 0x24) <= -0x20000) {
        M2C_FIELD(arg0, s32*, 0x24) = -0x20000;
    }
    ((void (*)(void*))func_8002D230)(arg0);
    if ((D_80097222 + 0x160) < M2C_FIELD(arg0, s16*, 0xE)) {
        M2C_FIELD(arg0, u8*, 0x6) = 0;
    }
}
