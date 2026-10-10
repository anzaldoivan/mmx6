#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F02A0(u8, s8, s32, s16);                           /* extern */
M2C_UNK func_800F0324(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
extern u8 D_80097427;

void func_800F0840(void* arg0) {
    func_800F02A0(0x94, 0, 0x11C, 0x38);
    func_800F0324(0xBC, 1, 0x16C, 0x80, 0);
    func_800F0324(0xC1, 1, 0x16C, 0xA0, 1);
    func_800F02A0(0xB9, 1, 0, 0);
    D_80097427 = 0;
    M2C_FIELD(arg0, u8*, 2) = (u8)(M2C_FIELD(arg0, u8*, 2) + 1);
}
