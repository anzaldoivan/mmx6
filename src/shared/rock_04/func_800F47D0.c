#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_8002D2B0(void*);

void func_800F47D0(void* arg0) {
    s32 var_v0;
    u8 temp_v1;

    temp_v1 = M2C_FIELD(arg0, u8*, 0x70);
    if (temp_v1 & 8) {
        func_80016C48(2, 0x12, arg0);
        func_80012D9C(8);
        func_800179A4(arg0, 9);
        {
            register s32 t asm("$2") = M2C_FIELD(arg0, u8*, 6) + 1;
            M2C_FIELD(arg0, s16*, 0x7C) = 0x1E;
            M2C_FIELD(arg0, u8*, 6) = t;
        }
        return;
    }
    if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
        var_v0 = temp_v1 & 1;
    } else {
        var_v0 = temp_v1 & 2;
    }
    if (var_v0 != 0) {
        func_80016C48(2, 0x12, arg0);
        func_80012D9C(8);
        func_800179A4(arg0, 0xB);
        {
            register s32 t asm("$2") = M2C_FIELD(arg0, u8*, 6) - 1;
            M2C_FIELD(arg0, s16*, 0x7C) = 0x1E;
            M2C_FIELD(arg0, u8*, 6) = t;
        }
        return;
    }
    func_8002D2B0(arg0);
}
