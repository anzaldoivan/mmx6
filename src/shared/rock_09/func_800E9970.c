#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32**)0x1F800020)

s32 func_8002A47C(s32);
extern u32* D_8007789C[];
extern u32* D_80095098;

void func_800E9970(s8* self, s8* parent) {
    u8 b = M2C_FIELD(parent, u8*, 0x14);

    M2C_FIELD(self, u8*, 0x16) = 0x11;
    M2C_FIELD(self, u32***, 0x30) = D_8007789C;
    M2C_FIELD(self, u8*, 0x14) = b;
    M2C_FIELD(self, s32*, 0x3C) = (s32)SPAD20 + SPAD20[func_8002A47C(0x8B)];
    M2C_FIELD(self, s16*, 0x40) = D_80095098[func_8002A47C(0x8B)] >> 7;
    M2C_FIELD(self, s16*, 0x42) =
        ((func_8002A47C(0x8B) * 4 + 0x20) % 16) |
        (((func_8002A47C(0x8B) + 8) / 4 + 0x1E0) << 6);
    M2C_FIELD(self, u8*, 4)++;
}
