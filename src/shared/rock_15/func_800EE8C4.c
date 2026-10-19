#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_8002D2D4();
void func_800EF2E8(struct X4_MainObj* self);

void func_800EE8C4(void* arg0) {
    u32 v;

    func_800EF2E8(arg0);
    func_800179A4(arg0, 3);
    v = func_8002D2D4();
    M2C_FIELD(arg0, u8*, 6) += 1;
    M2C_FIELD(arg0, s16*, 0x7C) = (u8)(v % 3) + 3;
}
