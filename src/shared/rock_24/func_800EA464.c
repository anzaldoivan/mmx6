#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_80017A04();
extern s32 D_8009719C;

void func_800EA464(void* arg0) {
    s32 temp_v0;
    s32 var_v0;

    M2C_FIELD(arg0, s32*, 0x8) += M2C_FIELD(arg0, s32*, 0x20);
    M2C_FIELD(arg0, s32*, 0xC) =
        M2C_FIELD(arg0, s32*, 0xC) - M2C_FIELD(arg0, s32*, 0x24);
    if (M2C_FIELD(arg0, s8*, 7) != 0) {
        M2C_FIELD(arg0, s32*, 0x20) += M2C_FIELD(arg0, s32*, 0x28);
    } else {
        M2C_FIELD(arg0, s32*, 0x20) -= M2C_FIELD(arg0, s32*, 0x28);
    }
    temp_v0 = M2C_FIELD(arg0, s32*, 0x24) - M2C_FIELD(arg0, s32*, 0x2C);
    M2C_FIELD(arg0, s32*, 0x24) = temp_v0;
    if (temp_v0 < D_8009719C) {
        M2C_FIELD(arg0, s32*, 0x24) = D_8009719C;
    }
    func_80017A04(arg0);
    var_v0 = M2C_FIELD(arg0, s8*, 7);
    if (var_v0 == 0) {
        var_v0 = M2C_FIELD(arg0, u8*, 0x70) & 1;
    } else {
        var_v0 = M2C_FIELD(arg0, u8*, 0x70) & 2;
    }
    if (var_v0 != 0) {
        func_80016C48(2, 4, arg0);
        M2C_FIELD(arg0, s16*, 0x8) = 0;
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        M2C_FIELD(arg0, u8*, 5) = 3;
        M2C_FIELD(arg0, u8*, 6) = 0;
    }
}
