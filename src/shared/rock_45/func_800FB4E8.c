#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_80040488(M2C_UNK);                 /* extern */
extern u8 D_8008EAFC;
extern s8 D_800CCEF4;

void func_800FB4E8(void* arg0) {
    if (D_8008EAFC == 0) {
        ((void (*)(M2C_UNK))func_80040488)(0);
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
        D_800CCEF4 = 1;
        M2C_FIELD(arg0, s16*, 0x7C) = 1;
    }
    func_8002CCB0(arg0, 0x40, 0x40);
}
