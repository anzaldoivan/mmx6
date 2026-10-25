#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_80016C48(s32 a0, s32 a1, void* arg2); /* extern */
M2C_UNK func_8002D5D0(void*);                  /* extern */
s32 func_8002FE30(void*);                      /* extern */

s32 func_80038F64(void* arg0) {
    s32 temp_v0;

    if (M2C_FIELD(arg0, s8*, 0xD3) != 0) {
        return 0;
    }
    if (M2C_FIELD(arg0, s8*, 0x84) != 0) {
        return 0;
    }
    if (M2C_FIELD(arg0, s8*, 0x87) == 0 &&
        !(M2C_FIELD(arg0, u16*, 0x80) & 0x100)) {
        return 0;
    }
    if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
        M2C_FIELD(arg0, s32*, 0x20) = M2C_FIELD(arg0, s32*, 0x12C);
    } else {
        M2C_FIELD(arg0, s32*, 0x20) = -M2C_FIELD(arg0, s32*, 0x12C);
    }
    func_8002D5D0(arg0);
    temp_v0 = (u8)(func_8002FE30(arg0) - 0x25) >= 0xB;
    M2C_FIELD(arg0, s32*, 8) = M2C_FIELD(arg0, s32*, 0x18);
    if (temp_v0) {
        return 0;
    }
    M2C_FIELD(arg0, s8*, 0x84) = 1;
    M2C_FIELD(arg0, s8*, 0x86) = 1;
    if (M2C_FIELD(arg0, s32*, 0xEC) & 0x10) {
        M2C_FIELD(arg0, s8*, 0x85) = 0xF;
    } else {
        M2C_FIELD(arg0, s8*, 0x85) = 0x1E;
    }
    M2C_FIELD(arg0, s8*, 0x8C) = 1;
    func_80016C48(1, 5, arg0);
    return 1;
}
