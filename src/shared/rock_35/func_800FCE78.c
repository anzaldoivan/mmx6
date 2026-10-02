#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK); /* extern */
M2C_UNK func_80017A04();               /* extern */
s32 func_80040498();                   /* extern */
extern s8 D_80097240;

void func_800FCE78(void* arg0) {
    func_80017A04();
    if (func_80040498() == 0) {
        func_800179A4(arg0, 1);
        D_80097240 = 2;
        M2C_FIELD(arg0, s16*, 0x7C) = 2;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}
