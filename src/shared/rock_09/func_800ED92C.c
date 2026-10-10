#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32**)0x1F800020)

s32 func_8002A47C(s32);
M2C_UNK func_8002CA14();
extern u32* D_80095098;
extern s8 D_800CCEED;

void func_800ED92C(s8* self) {
    if (D_800CCEED >= 4) {
        ((M2C_UNK(*)())func_8002CA14)();
        return;
    }
    M2C_FIELD(self, u8*, 0) = 0x41;
    M2C_FIELD(self, s16*, 0x40) = D_80095098[func_8002A47C(0x8C)] >> 7;
    M2C_FIELD(self, s16*, 0x42) =
        ((func_8002A47C(0x8C) * 4 + 0x20) % 16) |
        (((func_8002A47C(0x8C) + 8) / 4 + 0x1E0) << 6);
    M2C_FIELD(self, s32*, 0x3C) = (s32)SPAD20 + SPAD20[func_8002A47C(0x8C)];
    M2C_FIELD(self, u8*, 0x16) = 0x13;
    M2C_FIELD(self, u8*, 0x47) = 0;
    M2C_FIELD(self, u8*, 4)++;
}
