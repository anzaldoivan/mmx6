#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CFB0(); /* extern */

void func_8003D18C(void* arg0) {
    s32 var_v0;
    u16 temp_v1;

    if (M2C_FIELD(arg0, s8*, 0xD3) != 0) {
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        ((M2C_UNK(*)())func_8002CFB0)();
        return;
    }
    temp_v1 = M2C_FIELD(arg0, u16*, 0x7C);
    if (temp_v1 & 3) {
        if (temp_v1 & 1) {
            M2C_FIELD(arg0, s8*, 0x15) = 0x40;
            if (!(M2C_FIELD(arg0, u8*, 0x89) & 1)) {
                if (M2C_FIELD(arg0, s8*, 0x84) != 0) {
                    M2C_FIELD(arg0, s32*, 0x20) =
                        (s32)M2C_FIELD(arg0, s32*, 0x108);
                } else {
                    M2C_FIELD(arg0, s32*, 0x20) =
                        (s32)M2C_FIELD(arg0, s32*, 0xF4);
                }
            } else {
                goto block_13;
            }
        } else {
            M2C_FIELD(arg0, s8*, 0x15) = 0;
            if (!(M2C_FIELD(arg0, u8*, 0x89) & 2)) {
                if (M2C_FIELD(arg0, s8*, 0x84) != 0) {
                    var_v0 = -M2C_FIELD(arg0, s32*, 0x108);
                } else {
                    var_v0 = -M2C_FIELD(arg0, s32*, 0xF4);
                }
                M2C_FIELD(arg0, s32*, 0x20) = var_v0;
            } else {
                goto block_13;
            }
        }
    } else {
    block_13:
        M2C_FIELD(arg0, s32*, 0x20) = 0;
    }
    ((M2C_UNK(*)())func_8002CFB0)();
}
