#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern u8 D_800CCF99;

void func_8003F954(void* arg0) {
    s8 v;

    if (M2C_FIELD(arg0, s8*, 0x96) == -1) {
        if ((M2C_FIELD(arg0, u16*, 0x80) & 0x20) ||
            ((M2C_FIELD(arg0, u16*, 0x7C) & 0x20) && (D_800CCF99 & 2))) {
            M2C_FIELD(arg0, u8*, 0x96) = M2C_FIELD(arg0, u8*, 0x95);
            return;
        }
        if ((M2C_FIELD(arg0, s32*, 0x7C) & 0x200020) == 0x200000) {
            v = M2C_FIELD(arg0, s8*, 0x95);
            if (v != 0 && (v != 0x2D || M2C_FIELD(arg0, s8*, 0x9C) != 0)) {
                M2C_FIELD(arg0, u8*, 0x96) = M2C_FIELD(arg0, u8*, 0x95);
            }
        }
    }
}
