#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80012D9C(M2C_UNK);                   /* extern */
M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_800F3E10(void*, M2C_UNK);            /* extern */
extern s8 D_800FD51D;

void func_800F3544(void* arg0) {
    func_80012D9C(7);
    D_800FD51D = 0;
    func_8002943C(8, 3, 2);
    M2C_FIELD(arg0, s8*, 7) = 6;
    func_800F3E10(arg0, 0x70);
    func_800F3E10(arg0, 0x71);
    func_800F3E10(arg0, 0x72);
    func_800F3E10(arg0, 0x73);
    M2C_FIELD(arg0, s16*, 0x7C) = 0x50;
    M2C_FIELD(arg0, s16*, 0x7E) = 0;
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}
