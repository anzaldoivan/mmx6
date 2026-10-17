#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*); /* extern */
extern s8 D_800970A2;
extern u8 D_800CCF38;

void func_800EC000(void* arg0) {
    s32 temp_v0;

    if (M2C_FIELD(arg0, s8*, 7) == 0) {
        if (D_800970A2 == 0) {
            if (D_800CCF38 >= 2) {
                temp_v0 = M2C_FIELD(arg0, u16*, 0x7E) + 1;
                M2C_FIELD(arg0, u16*, 0x7E) = temp_v0;
                temp_v0 = (s16)temp_v0 < 3;
            } else {
                temp_v0 = M2C_FIELD(arg0, u16*, 0x7E) + 1;
                M2C_FIELD(arg0, u16*, 0x7E) = temp_v0;
                temp_v0 = (s16)temp_v0 < 2;
            }
        } else {
            temp_v0 = M2C_FIELD(arg0, u16*, 0x7E) + 1;
            M2C_FIELD(arg0, u16*, 0x7E) = temp_v0;
            temp_v0 = (s16)temp_v0 < 4;
        }
        if (temp_v0 != 0) {
            M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) - 1);
            return;
        }
        M2C_FIELD(arg0, u8*, 0x91) = 1;
        func_80016C48(2, 0x45, arg0);
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}
