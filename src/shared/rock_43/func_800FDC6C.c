#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800FDC6C(void* arg0, void* arg1) {
    void* temp_a0;

    if (M2C_FIELD(arg0, s16*, 0x54) != 0) {
        M2C_FIELD(arg0, s16*, 0x54) =
            (s16)((u16)M2C_FIELD(arg0, s16*, 0x54) - 1);
    } else {
        temp_a0 = M2C_FIELD(arg0, void**, 0x5C);
        M2C_FIELD(arg0, s16*, 0x54) = 3;
        M2C_FIELD(arg0, s32*, 8) = (s32)M2C_FIELD(temp_a0, s32*, 0x18);
        M2C_FIELD(arg0, s32*, 0xC) = (s32)M2C_FIELD(temp_a0, s32*, 0x1C);
    }
    if (M2C_FIELD(arg1, s8*, 0x9A) < 0) {
        M2C_FIELD(arg0, u8*, 5) = (u8)(M2C_FIELD(arg0, u8*, 5) + 1);
    }
}
