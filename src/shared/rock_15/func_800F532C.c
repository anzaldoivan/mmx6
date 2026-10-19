#include "common.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F532C(void* arg0, void* arg1) {
    void* temp_v1;

    if (M2C_FIELD(arg1, s8*, 7) > 0) {
        s32 y;
        M2C_FIELD(arg0, s16*, 0x54) = 3;
        M2C_FIELD(arg0, s16*, 0x56) = 8;
        M2C_FIELD(arg0, s16*, 0x58) = 0xA;
        M2C_FIELD(arg0, s32*, 8) = M2C_FIELD(arg1, s32*, 8);
        y = M2C_FIELD(arg1, s32*, 0xC);
        M2C_FIELD(arg0, s8*, 4) = 1;
        M2C_FIELD(arg0, s8*, 5) = 0;
        M2C_FIELD(arg0, s32*, 0xC) = y;
        return;
    }
    if (M2C_FIELD(arg0, s16*, 0x58) != 0) {
        s32 y;
        temp_v1 = M2C_FIELD(arg0, void**, 0x5C);
        M2C_FIELD(arg0, s32*, 8) = M2C_FIELD(temp_v1, s32*, 0x18);
        y = M2C_FIELD(temp_v1, s32*, 0x1C);
        M2C_FIELD(arg0, s16*, 0x58) = M2C_FIELD(arg0, s16*, 0x58) - 1;
        M2C_FIELD(arg0, s32*, 0xC) = y;
        return;
    }
    M2C_FIELD(arg0, s8*, 3) = 0;
    M2C_FIELD(arg0, s8*, 4) = 0;
    if (M2C_FIELD(arg0, s8*, 2) == 7) {
        M2C_FIELD(arg1, s8*, 7) = 0;
    }
}
