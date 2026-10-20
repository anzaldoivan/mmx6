#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F4254(void* arg0, u8 arg1);

void func_800F2CA8(void* arg0) {
    M2C_FIELD(arg0, u8*, 7) = 0;
    func_800F4254(arg0, 0x40);
    M2C_FIELD(arg0, s16*, 0x7C) = 0xB4;
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}
