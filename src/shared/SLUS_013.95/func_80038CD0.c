#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04(void*);              /* extern */
M2C_UNK func_8002D5D0(void*);              /* extern */
s32 func_8002FE30(void*);                  /* extern */
s32 func_80038594(void*);                  /* extern */
s32 func_800397F8(void*, s32);             /* extern */
s32 func_8003A814(void*, s32);             /* extern */
M2C_UNK func_8003BA04(void*, M2C_UNK);     /* extern */
M2C_UNK func_8003BB94(void*, M2C_UNK, s8); /* extern */

void func_80038CD0(void* arg0) {
    s32 var_s2;
    register s32 var_s0 asm("$16");
    s32 temp_s3;
    s32 temp_v0;
    u16 temp_v1;

    if (M2C_FIELD(arg0, s8*, 0x84) != 0) {
        var_s2 = func_80038594(arg0);
    } else {
        temp_v1 = M2C_FIELD(arg0, u16*, 0x7C);
        var_s0 = 0;
        if (temp_v1 & 3) {
            var_s0 = 1;
            if (temp_v1 & 2) {
                M2C_FIELD(arg0, s32*, 0x20) = -M2C_FIELD(arg0, s32*, 0x124);
            } else {
                var_s0 = 2;
                M2C_FIELD(arg0, s32*, 0x20) = M2C_FIELD(arg0, s32*, 0x124);
            }
            func_8002D5D0(arg0);
            temp_v0 = (u8)(func_8002FE30(arg0) - 0x25) >= 0xB;
            M2C_FIELD(arg0, s32*, 8) = M2C_FIELD(arg0, s32*, 0x18);
            if (temp_v0) {
                var_s0 = 0;
            } else {
                func_8002D5D0(arg0);
            }
        }
        var_s2 = var_s0;
    }
    if (var_s2 != 0) {
        func_800397F8(arg0, func_8002FE30(arg0));
    }
    temp_s3 = func_8002FE30(arg0);
    if (M2C_FIELD(arg0, s8*, 2) == 0) {
        if (M2C_FIELD(arg0, s8*, 0x8F) != 0) {
            func_8003BA04(arg0, func_8003A814(arg0, temp_s3) + 0x97);
            return;
        }
        if (M2C_FIELD(arg0, s8*, 0x8E) != 0) {
            var_s0 = 0x97;
            if (var_s2 != 0) {
                var_s0 = 0x9A;
            }
            var_s0 = (var_s0 + func_8003A814(arg0, temp_s3)) & 0xFF;
            goto block_27;
        }
        if (var_s2 != 0) {
            var_s0 = (func_8003A814(arg0, temp_s3) - 0x5A) & 0xFF;
            goto block_27;
        }
        var_s0 = (func_8003A814(arg0, temp_s3) - 0x69) & 0xFF;
        if (M2C_FIELD(arg0, u8*, 0x17) == var_s0) {
            goto block_27;
        }
        goto block_25;
    }
    if (var_s2 != 0) {
        var_s0 = (func_8003A814(arg0, temp_s3) - 0x5A) & 0xFF;
    } else {
    block_25:
        var_s0 = (func_8003A814(arg0, temp_s3) - 0x5D) & 0xFF;
    }
block_27:
    if (var_s0 != M2C_FIELD(arg0, u8*, 0x17)) {
        if ((u8)(var_s0 + 0x5D) < 3U) {
            if (M2C_FIELD(arg0, s8*, 2) == 0) {
                func_8003BB94(arg0, var_s0, 2);
            } else {
                func_8003BB94(arg0, var_s0, 3);
            }
        } else {
            func_8003BA04(arg0, var_s0);
        }
    } else {
        func_80017A04(arg0);
    }
    if ((M2C_FIELD(arg0, s8*, 0x46) == 0) &&
        (M2C_FIELD(arg0, s8*, 0x8E) == 0)) {
        var_s0 = (func_8003A814(arg0, temp_s3) - 0x5D) & 0xFF;
        if (M2C_FIELD(arg0, s8*, 2) == 0) {
            func_8003BB94(arg0, var_s0, 2);
        } else {
            func_8003BB94(arg0, var_s0, 3);
        }
    }
}
