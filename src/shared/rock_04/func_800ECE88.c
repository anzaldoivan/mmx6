#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_8002D2B0(void*);                     /* extern */

void func_800ECE88(void* arg0) {
    void* temp_s0;

    temp_s0 = M2C_FIELD(arg0, void**, 0x7C);
    if (M2C_FIELD(temp_s0, s16*, 0xE) != M2C_FIELD(arg0, s16*, 0xE)) {
        M2C_FIELD(temp_s0, s16*, 0xE) = (s16)(u16)M2C_FIELD(arg0, s16*, 0xE);
    }
    func_8002D2B0(arg0);
    if (M2C_FIELD(temp_s0, s8*, 7) == 1) {
        M2C_FIELD(arg0, s8*, 6) = 2;
        M2C_FIELD(arg0, s16*, 0xC) = 0;
        M2C_FIELD(arg0, s16*, 8) = 0;
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s16*, 0xE) =
            (s16)(((u16)M2C_FIELD(arg0, s16*, 0xE) & 0xFFF0) | 8);
        if (M2C_FIELD(arg0, s8*, 3) != 0) {
            func_8002943C(0x10, 3, 1);
        }
    }
}
