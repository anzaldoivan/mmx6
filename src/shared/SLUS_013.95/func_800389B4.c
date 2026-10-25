#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04(void*);              /* extern */
M2C_UNK func_8002D5D0(void*);              /* extern */
s32 func_8002FE30(void*);                  /* extern */
s32 func_80038788(void* arg0);             /* extern */
M2C_UNK func_8003BA04(void*, M2C_UNK);     /* extern */
M2C_UNK func_8003BB94(void*, M2C_UNK, s8); /* extern */

void func_800389B4(void* arg0) {
    s32 var_a2;
    s32 var_s1;
    s32 var_a0;
    s32 var_a1;
    s32 var_v1;
    // !FAKE: depin: dropping it breaks the match (68/125)
    register s32 var_v0 asm("$2");
    u16 temp_v1;

    if (M2C_FIELD(arg0, s8*, 0x84) != 0) {
        var_a2 = func_80038788(arg0);
    } else {
        temp_v1 = M2C_FIELD(arg0, u16*, 0x7C);
        var_s1 = 0;
        if (temp_v1 & 0xC) {
            var_s1 = 1;
            if (temp_v1 & 4) {
                M2C_FIELD(arg0, s32*, 0x24) = M2C_FIELD(arg0, s32*, 0x128);
            } else {
                var_s1 = 2;
                M2C_FIELD(arg0, s32*, 0x24) = -M2C_FIELD(arg0, s32*, 0x128);
            }
            func_8002D5D0(arg0);
            var_a0 = func_8002FE30(arg0) != 0x2E;
            if (M2C_FIELD(arg0, s32*, 0x24) < 0 &&
                (M2C_FIELD(arg0, u8*, 0x89) & 8)) {
                var_a0 = 1;
            }
            M2C_FIELD(arg0, s32*, 0xC) = M2C_FIELD(arg0, s32*, 0x1C);
            if (var_a0 != 0) {
                var_s1 = 0;
            } else {
                func_8002D5D0(arg0);
            }
        }
        var_a2 = var_s1;
    }
    if (M2C_FIELD(arg0, s8*, 2) == 0) {
        if (M2C_FIELD(arg0, s8*, 0x8F) != 0) {
            func_8003BA04(arg0, var_a2 + 0x91);
            return;
        }
        if (M2C_FIELD(arg0, s8*, 0x8E) != 0) {
            var_v0 = var_a2 - 0x6F;
            var_a1 = var_v0 & 0xFF;
            var_v1 = M2C_FIELD(arg0, u8*, 0x17);
        } else {
            var_v0 = M2C_FIELD(arg0, u8*, 0x17);
            var_a1 = 0x91;
            var_v1 = var_v0;
            if (var_v0 != var_a1) {
                var_v0 = var_a2 - 0x60;
                var_a1 = var_v0 & 0xFF;
            }
        }
    } else {
        var_v0 = var_a2 - 0x60;
        var_a1 = var_v0 & 0xFF;
        var_v1 = M2C_FIELD(arg0, u8*, 0x17);
    }
    if (var_a1 != var_v1) {
        if (var_a1 == 0xA0) {
            if (M2C_FIELD(arg0, s8*, 2) == 0) {
                func_8003BB94(arg0, 0xA0, 2);
            } else {
                func_8003BB94(arg0, 0xA0, 3);
            }
        } else {
            func_8003BA04(arg0, var_a1);
        }
    } else {
        func_80017A04(arg0);
    }
    if ((M2C_FIELD(arg0, s8*, 0x46) == 0) &&
        (M2C_FIELD(arg0, s8*, 0x8E) == 0)) {
        if (M2C_FIELD(arg0, s8*, 2) == 0) {
            func_8003BB94(arg0, 0xA0, 2);
        } else {
            func_8003BB94(arg0, 0xA0, 3);
        }
    }
}
