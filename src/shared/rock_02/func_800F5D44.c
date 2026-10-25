#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD4C_800F5D44 (*(u8**)0x1F80004C)

M2C_UNK func_800F82C0();
extern u8 D_800FB810[];

void func_800F5D44(void* self) {
    s32 n;
    // !FAKE: depin: dropping it breaks the match (29/36)
    register s32 t asm("$2");
    s32 v;

    func_800F82C0();
    t = M2C_FIELD(self, u16*, 0x7C);
    M2C_FIELD(self, u16*, 0x7C) = t + 1;
    if ((s16)t >= 0x29) {
        M2C_FIELD(self, u16*, 0x7C) = 0;
        n = ++SPAD4C_800F5D44[0x85];
        v = D_800FB810[(n & 3) + SPAD4C_800F5D44[0x84] * 4];
        M2C_FIELD(self, u8*, 0x6) = 0;
        M2C_FIELD(self, u8*, 0x5) = v;
    }
}

#undef SPAD4C_800F5D44
