#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);

extern u8 D_800F4BF0[];

void func_800EC600(void* self) {
    s32 v;
    u8* t;

    func_800179A4(self, 3);
    t = D_800F4BF0 + 0x1324;
    v = *(s32*)(((M2C_FIELD(self, u8*, 0x15) >> 4) & 4) + t);
    M2C_FIELD(self, s32*, 0x24) = 0x5000;
    M2C_FIELD(self, u8*, 6) = M2C_FIELD(self, u8*, 6) + 1;
    M2C_FIELD(self, s32*, 0x20) = v;
}
