#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_80030CCC(void*, s32, s32, s16);

void func_800ECFE8(void* arg0) {
    M2C_FIELD(arg0, u8*, 0x3) = 0;
    if (!(((s32(*)())func_80030CCC)(arg0, M2C_FIELD(arg0, s16*, 0xA),
                                    M2C_FIELD(arg0, s16*, 0xE)) &
          0xFF)) {
        M2C_FIELD(arg0, u8*, 0x3) = 1;
        M2C_FIELD(arg0, u8*, 0x5C) = 0x20;
        M2C_FIELD(arg0, u8*, 0x6) = 5;
        return;
    }
    M2C_FIELD(arg0, u8*, 0x4) = 2;
}
