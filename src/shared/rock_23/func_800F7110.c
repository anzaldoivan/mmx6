#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04(); /* extern */
extern M2C_UNK D_800F9414;
extern M2C_UNK D_800F9420;
extern M2C_UNK D_800F942C;

void func_800F7110(void* arg0) {
    ((M2C_UNK(*)())func_80017A04)();
    M2C_FIELD(arg0, s32*, 0x24) = 0xFFFD0000;
    M2C_FIELD(arg0, M2C_UNK**, 0x54) = &D_800F9414;
    M2C_FIELD(arg0, M2C_UNK**, 0x50) = &D_800F9420;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, M2C_UNK**, 0x68) = &D_800F942C;
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}
