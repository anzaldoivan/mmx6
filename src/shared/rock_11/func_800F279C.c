#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002D2D4();
void func_800F3E10(void* arg0, s32 arg1);

void func_800F279C(void* arg0) {
    M2C_FIELD(arg0, s8*, 7) = 6;
    func_800F3E10(arg0, 0x20);
    func_800F3E10(arg0, 0x21);
    func_800F3E10(arg0, 0x22);
    func_800F3E10(arg0, 0x23);
    func_800F3E10(arg0, 0x24);
    M2C_FIELD(arg0, s16*, 0x7C) = 0xB4;
    M2C_FIELD(arg0, s16*, 0x7E) = func_8002D2D4() % 3 + 3;
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}
