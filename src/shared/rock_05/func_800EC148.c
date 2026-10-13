#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80017A04();

extern s32 D_80097420;
extern u8 D_800E9860[];

void func_800EC148(void* self) {
    s16 offs[4][2];
    void* parent;
    s8 idx;

    __builtin_memcpy(offs, D_800E9860 + 0x2C, 0x10);
    parent = M2C_FIELD(self, void**, 0x7C);
    func_80017A04(self);
    idx = M2C_FIELD(self, s8*, 2);
    M2C_FIELD(self, s16*, 0xA) = M2C_FIELD(parent, s16*, 0xA) + offs[idx][0];
    M2C_FIELD(self, s16*, 0xE) = M2C_FIELD(parent, s16*, 0xE) + offs[idx][1];
    M2C_FIELD(self, u8*, 3) = 0;
    if ((idx == 0 && M2C_FIELD(parent, s8*, 6) == 1) ||
        (idx == 1 && M2C_FIELD(parent, s8*, 6) == 3) ||
        (idx == 2 && M2C_FIELD(parent, s8*, 6) == idx) ||
        (idx == 3 && M2C_FIELD(parent, s8*, 6) == 4)) {
        M2C_FIELD(self, u8*, 3) = 1;
    }
    if (M2C_FIELD(parent, s8*, 5) >= 8 || M2C_FIELD(parent, s16*, 0x7C) != 0) {
        M2C_FIELD(self, u8*, 3) = 0;
    }
    if (!(D_80097420 & 0x1F) && M2C_FIELD(self, s8*, 3) != 0) {
        func_80016C48(2, 3, self);
    }
}
