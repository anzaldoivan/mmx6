#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
s32 func_8002D2D4();
extern s32 D_80097420;

void func_800F999C(void* arg0) {
    s32 temp_a0;
    u16 temp_v0;

    func_80017A04();
    temp_a0 = func_8002D2D4() & 3;
    if (D_80097420 & 1) {
        M2C_FIELD(arg0, u16*, 0xA) = M2C_FIELD(arg0, u16*, 0x94);
        M2C_FIELD(arg0, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0x96);
    } else if (temp_a0 == 0) {
        M2C_FIELD(arg0, u16*, 0xA) = M2C_FIELD(arg0, u16*, 0xA) + 1;
    } else if (temp_a0 == 1) {
        M2C_FIELD(arg0, u16*, 0xA) = M2C_FIELD(arg0, u16*, 0xA) - 1;
    } else if (temp_a0 == 2) {
        M2C_FIELD(arg0, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0xE) + 1;
    } else if (temp_a0 == 3) {
        M2C_FIELD(arg0, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0xE) - 1;
    }
    temp_v0 = M2C_FIELD(arg0, u16*, 0x7C);
    M2C_FIELD(arg0, u16*, 0x7C) = temp_v0 + 1;
    if ((s16)temp_v0 >= 0x29) {
        M2C_FIELD(arg0, u16*, 0x7C) = 0;
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    }
}
