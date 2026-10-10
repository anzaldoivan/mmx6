#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F02A0(u8, s8, s32, s16);                           /* extern */
M2C_UNK func_800F03B8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);      /* extern */
M2C_UNK func_800F0438(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
extern u8 D_80097427;

void func_800EF8C4(void* arg0) {
    D_80097427 = 0;
    func_800F03B8(0x22, 1, 0x130, 0x30);
    func_800F0438(0x21, 1, 0xF4, 0x7A, 0);
    func_800F0438(0x29, 1, 0x1EC, 0x7A, 0);
    func_800F0438(0x23, 1, 0xF4, 0xAC, 1);
    func_800F02A0(0xBD, 1, 0, 0);
    M2C_FIELD(arg0, s8*, 2) = 3;
}
