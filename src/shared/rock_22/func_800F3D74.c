#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD (*(u8**)0x1F80004C)

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04();
extern s32 D_800FC62C[];

void func_800F3D74(void* arg0) {
    s32 var_a2;
    u8* temp_v1;

    if (M2C_FIELD(arg0, s8*, 0x46) < 0) {
        temp_v1 = SPAD;
        var_a2 = 7;
        if (temp_v1[0x81] < 2U) {
            var_a2 = 9;
            if (temp_v1[0x80] == 0) {
                var_a2 = 8;
            }
            M2C_FIELD(arg0, s32*, 0x2C) = 0;
            M2C_FIELD(arg0, s32*, 0x20) = 0;
            M2C_FIELD(arg0, s32*, 0x28) = 0;
        } else {
            M2C_FIELD(arg0, s32*, 0x24) = 0;
            M2C_FIELD(arg0, s32*, 0x2C) = 0;
        }
        M2C_FIELD(arg0, s32*, 0x68) =
            D_800FC62C[(s8)M2C_FIELD(arg0, u8*, 2) >> 1];
        ((void (*)(void*, s32))func_800179A4)(arg0, var_a2);
        M2C_FIELD(arg0, u8*, 6) = 5;
        return;
    }
    func_80017A04(arg0);
}
