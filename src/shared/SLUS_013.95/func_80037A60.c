#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CFB0(void*); /* extern */

void func_80037A60(void* arg0) {
    s32 temp_v0;
    s32 var_v1;

    if (M2C_FIELD(arg0, s8*, 0xD4) == 0) {
        temp_v0 = M2C_FIELD(arg0, s32*, 0x20);
        if (temp_v0 != 0) {
            var_v1 = 2;
            if (temp_v0 > 0) {
                var_v1 = 1;
            }
            if (M2C_FIELD(arg0, u8*, 0x89) & var_v1) {
                M2C_FIELD(arg0, s32*, 0x20) = 0;
                M2C_FIELD(arg0, s32*, 0x28) = 0;
            }
        }
        func_8002CFB0(arg0);
        if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
            if (M2C_FIELD(arg0, s32*, 0x20) > 0) {
                M2C_FIELD(arg0, s32*, 0x20) = 0;
                goto block_11;
            }
        } else if (M2C_FIELD(arg0, s32*, 0x20) < 0) {
            M2C_FIELD(arg0, s32*, 0x20) = 0;
        block_11:
            M2C_FIELD(arg0, s32*, 0x28) = 0;
        }
    }
}
