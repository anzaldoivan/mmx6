#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);
void func_800F9E04(struct X4_AnimatedObj*);
extern M2C_UNK D_800FC734;
extern M2C_UNK D_800FC738;

void func_800F8C74(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        func_800179A4(arg0, 6);
        func_800F9E04(arg0);
        M2C_FIELD(arg0, M2C_UNK**, 0x50) = &D_800FC734;
        M2C_FIELD(arg0, M2C_UNK**, 0x54) = &D_800FC738;
        M2C_FIELD(arg0, s16*, 0x7C) = 0x14;
        M2C_FIELD(arg0, u8*, 6)++;
    }
}
