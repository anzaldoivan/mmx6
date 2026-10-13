#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8003FA00(void*);
extern s8 D_80073E40[];
extern u8 D_800CCF99;

void func_8003E9E8(void* arg0) {
    s8 v;

    if ((M2C_FIELD(arg0, u16*, 0x80) & 0x10) ||
        ((M2C_FIELD(arg0, u16*, 0x7C) & 0x10) && (D_800CCF99 & 2))) {
        if ((M2C_FIELD(arg0, s8*, 0x93) == 0) || (func_8003FA00(arg0) != 0)) {
            if ((M2C_FIELD(arg0, s8*, 0x94) != 0x32) ||
                ((v = M2C_FIELD(arg0, s8*, 0x5)) != 0x1F && v != 0x1A)) {
                M2C_FIELD(arg0, u8*, 0x96) = M2C_FIELD(arg0, u8*, 0x94);
            }
        }
    } else if ((M2C_FIELD(arg0, s32*, 0x7C) & 0x100010) == 0x100000) {
        v = M2C_FIELD(arg0, s8*, 0x94);
        if ((v != 0) && (v != 0x32) && (D_80073E40[v] == 0) &&
            ((M2C_FIELD(arg0, s8*, 0x93) == 0) || (func_8003FA00(arg0) != 0))) {
            M2C_FIELD(arg0, u8*, 0x96) = M2C_FIELD(arg0, u8*, 0x94);
        }
    }
}
