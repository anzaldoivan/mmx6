#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80018060(M2C_UNK, M2C_UNK); /* extern */
extern s8 D_80097424;

void func_800E9B9C(void* arg0) {
    if (D_80097424 == 0) {
        M2C_FIELD(arg0, s16*, 4) = 0;
        M2C_FIELD(arg0, u8*, 1) = (u8)(M2C_FIELD(arg0, u8*, 1) + 1);
        func_80018060(3, 0x7F);
    }
}
