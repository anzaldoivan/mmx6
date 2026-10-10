#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800133A0(); /* extern */
M2C_UNK func_8001D25C(); /* extern */
extern s8 D_80097424[];
#define D_80097424 (*(s8*)&D_80097424)

void func_800F08D0(void* arg0) {
    s32 var_v0;
    s8* var_a0;
    u8 temp_v1;

    if (D_80097424 == 0) {
        if (M2C_FIELD(arg0, s8*, 3) == 0) {
            temp_v1 = M2C_FIELD(arg0, u8*, 0x158);
            if (temp_v1 == 0xFF) {
                M2C_FIELD(arg0, s8*, 0) = 3;
            } else {
                M2C_FIELD(arg0, s8*, 0) = 0x13;
                M2C_FIELD(arg0, u8*, 0x1D) = temp_v1;
            }
            M2C_FIELD(arg0, s8*, 1) = 0;
            M2C_FIELD(arg0, s8*, 2) = 0;
            M2C_FIELD(arg0, s8*, 3) = 0;
        } else {
            func_8001D25C();
            func_800133A0();
        }
        var_v0 = 0xF;
        var_a0 = arg0 + 0x35;
        do {
            *var_a0 = 0;
            var_v0 -= 1;
            var_a0 -= 1;
        } while (var_v0 >= 0);
    }
}
#undef D_80097424
