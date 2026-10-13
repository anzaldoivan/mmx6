#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK func_8002D5D0(void*);                   /* extern */
s32 func_8002FE30(void*);                       /* extern */

s32 func_80038BA8(void* arg0) {
    s32 var_a0;

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
    if (M2C_FIELD(arg0, u16*, 0x7C) & 4) {
        M2C_FIELD(arg0, s32*, 0x24) = M2C_FIELD(arg0, s32*, 0x130);
    } else {
        M2C_FIELD(arg0, s32*, 0x24) = -M2C_FIELD(arg0, s32*, 0x130);
    }
    func_8002D5D0(arg0);
    var_a0 = func_8002FE30(arg0) != 0x2E;
    if (M2C_FIELD(arg0, s32*, 0x24) < 0 && (M2C_FIELD(arg0, u8*, 0x89) & 8)) {
        var_a0 = 1;
    }
    M2C_FIELD(arg0, s32*, 0xC) = M2C_FIELD(arg0, s32*, 0x1C);
    if (var_a0 != 0) {
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
