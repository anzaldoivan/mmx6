#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern u8 D_8008EAFC;
extern s8 D_800CCEF8;

void func_800EF0C0(void* arg0) {
    if (D_8008EAFC == 0) {
        func_80016C48(0, 0x22, 0);
        D_800CCEF8 = 0x5F;
        M2C_FIELD(arg0, u8*, 2) = (u8)(M2C_FIELD(arg0, u8*, 2) + 1);
    }
}
