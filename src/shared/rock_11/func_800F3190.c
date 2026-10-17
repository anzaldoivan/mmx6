#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern s16 D_80090D5C;
extern s32 D_80097420;
extern s16 D_80097430;
extern u8 D_800C4560;
extern s16 D_800CF854;

void func_800F3190(void* arg0) {
    if (--M2C_FIELD(arg0, s16*, 0x7C) == -1) {
        M2C_FIELD(arg0, s16*, 0x7C) = 3;
        D_800CF854 += 1;
        D_80097430 += 0x20;
        D_80090D5C += 0x400;
        D_800C4560 |= 1;
        if ((u16)D_800CF854 >= 0x1F) {
            M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
        }
    }
    if (D_80097420 & 3) {
        func_8002943C(2, 5, 2);
    }
}
