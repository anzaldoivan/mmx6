#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s16 D_800970AA;
extern s16 D_80097206;

void func_800428D8(void* arg0) {
    u16 y = D_80097206;
    u16 x;
    // !FAKE: pin the field-6 byte to the first return register (regalloc swap)
    register s32 b asm("$2");

    M2C_FIELD(arg0, u8*, 0x3) = 1;
    M2C_FIELD(arg0, s16*, 0xE) = y - 0x20;
    x = D_800970AA;
    {
        // !FAKE: pin the 0x7E constant to the first return register (regalloc swap)
        register s32 k asm("$2") = 0x5A;
        M2C_FIELD(arg0, s16*, 0x7E) = k;
    }
    b = M2C_FIELD(arg0, u8*, 0x6);
    M2C_FIELD(arg0, s16*, 0x7C) = 1;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0xFFFF0000;
    M2C_FIELD(arg0, u8*, 0x7) = 0;
    M2C_FIELD(arg0, u8*, 0x6) = b + 1;
    M2C_FIELD(arg0, s16*, 0xA) = x;
}
