#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_800ED0AC(u8* arg0);
extern s16 D_800970AA;

void func_800ECC74(void* arg0) {
    s32 temp_a0;
    s32 temp_v1;
    s32 temp_v0;

    if (M2C_FIELD(arg0, u8*, 0x89) == 2) {
        M2C_FIELD(arg0, u8*, 0x89) = 0;
    }
    if (M2C_FIELD(arg0, u8*, 0x89) == 0) {
        temp_a0 = D_800970AA;
        temp_v1 = M2C_FIELD(arg0, s16*, 0xA);
        temp_v0 = temp_a0 - temp_v1;
        if (temp_v0 >= 0) {
            if (temp_v0 >= 0x91) {

            } else {
                goto block_7;
            }
        } else if ((temp_v1 - temp_a0) < 0x91) {
        block_7:
            M2C_FIELD(arg0, u8*, 0x88) = func_800ED0AC(arg0);
        }
        if ((M2C_FIELD(arg0, s8*, 2) & 0xF0) == 0x10) {
            func_800179A4(arg0, M2C_FIELD(arg0, u8*, 0x88) + 8);
        } else {
            func_800179A4(arg0, M2C_FIELD(arg0, u8*, 0x88));
        }
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}
