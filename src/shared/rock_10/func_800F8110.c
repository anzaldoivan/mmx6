#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);
void func_800F9E04(struct X4_AnimatedObj*);

void func_800F8110(void* arg0) {
    func_800F9E04(arg0);
    ((void (*)(void*, s32))func_800179A4)(arg0, 0xD);
    M2C_FIELD(arg0, s32*, 0x50) = 0;
    M2C_FIELD(arg0, s32*, 0x54) = 0;
    M2C_FIELD(arg0, s16*, 0x7C) = 0;
    M2C_FIELD(arg0, s16*, 0x7E) = 0;
    M2C_FIELD(arg0, u8*, 6) += 1;
}
