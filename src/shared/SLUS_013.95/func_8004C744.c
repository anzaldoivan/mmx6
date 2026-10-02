#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800328B0(); /* extern */

void func_8004C744(void* arg0) {
    M2C_FIELD(arg0, s16*, 0x34) = 3;
    M2C_FIELD(arg0, s32*, 0x38) = 0x40000;
    M2C_FIELD(arg0, s8*, 0x36) = 0;
    M2C_FIELD(arg0, s8*, 0x37) = 0;
    M2C_FIELD(arg0, s32*, 0x14) = 0;
    M2C_FIELD(arg0, s32*, 0x18) = 0;
    M2C_FIELD(arg0, s32*, 0x1C) = 0;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, s32*, 0x30) = 0;
    M2C_FIELD(arg0, u8*, 0) = (u8)(M2C_FIELD(arg0, u8*, 0) | 0x82);
    M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
    func_800328B0();
}
