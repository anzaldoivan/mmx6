#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK); /* extern */
s32 func_8002D2D4();                   /* extern */
extern s16 D_800FE9A8;

void func_800FDD90(void* arg0) {
    s32 temp_v0;
    s32 temp_v1;

    M2C_FIELD(arg0, s16*, 0x7E) = (s16)((func_8002D2D4() & 1) + 1);
    temp_v1 = M2C_FIELD(arg0, s16*, 0xE) - 0x460;
    temp_v0 = temp_v1 - D_800FE9A8;
    if (temp_v0 >= 0) {
        if (temp_v0 < 0x11) {

        } else {
            goto block_4;
        }
    } else if ((D_800FE9A8 - temp_v1) >= 0x11) {
    block_4:
        func_800179A4(arg0, 4);
    }
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0xFFFB0000;
    M2C_FIELD(arg0, s32*, 0x68) = 0;
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}
