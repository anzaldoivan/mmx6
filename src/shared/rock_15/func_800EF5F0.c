#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002D2D4();
extern s16 D_80097222;

void func_800EF5F0(void* arg0) {
    u8 r;

    if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
        M2C_FIELD(arg0, s16*, 0xA) = M2C_FIELD(arg0, s16*, 0xA) - 0x26;
    } else {
        M2C_FIELD(arg0, s16*, 0xA) = M2C_FIELD(arg0, s16*, 0xA) + 0x26;
    }
    r = (u32)func_8002D2D4() % 3;
    switch (r) {
    case 0:
        M2C_FIELD(arg0, s16*, 0xE) = D_80097222 + 0x50;
        break;
    case 1:
        M2C_FIELD(arg0, s16*, 0xE) = D_80097222 + 0x70;
        break;
    case 2:
        M2C_FIELD(arg0, s16*, 0xE) = D_80097222 + 0x80;
        break;
    }
    M2C_FIELD(arg0, u8*, 0x6)++;
}
