#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32**)0x1F800020)
#define SPAD9C (*(s32**)0x1F80009C)

M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_8002A47C(s32);
extern u16 D_800CCEDC;
#define D_800CCEDC (*(s8*)&D_800CCEDC)

void func_800F0434(s8* self, u32 arg1) {
    if (arg1 < 0x1C) {
        M2C_FIELD(self, s16*, 0x40) = 0x140;
        M2C_FIELD(self, s16*, 0x42) =
            ((func_8002A47C(M2C_FIELD(self, s8*, 1)) * 4 + 0x20) % 16) |
            (((func_8002A47C(M2C_FIELD(self, s8*, 1)) + 8) / 4 + 0x1E0) << 6);
        M2C_FIELD(self, s32*, 0x3C) =
            (s32)SPAD20 + SPAD20[func_8002A47C(M2C_FIELD(self, s8*, 1))];
        if (D_800CCEDC == 0xC) {
            M2C_FIELD(self, s16*, 0x42) = 0x7948;
            M2C_FIELD(self, s32*, 0x3C) = (s32)SPAD9C + SPAD9C[0];
        }
    } else if (arg1 < 0x21) {
        M2C_FIELD(self, s16*, 0x40) = 0x140;
        M2C_FIELD(self, s16*, 0x42) =
            ((func_8002A47C(M2C_FIELD(self, s8*, 1)) * 4 + 0x20) % 16) |
            (((func_8002A47C(M2C_FIELD(self, s8*, 1)) + 8) / 4 + 0x1E0) << 6);
        M2C_FIELD(self, s32*, 0x3C) =
            (s32)SPAD20 + SPAD20[func_8002A47C(M2C_FIELD(self, s8*, 1)) + 1];
        if (D_800CCEDC == 0xC) {
            M2C_FIELD(self, s16*, 0x42) = 0x7948;
            M2C_FIELD(self, s32*, 0x3C) = (s32)SPAD9C + SPAD9C[1];
        }
    } else {
        M2C_FIELD(self, s16*, 0x40) = 0x540;
        M2C_FIELD(self, s16*, 0x42) =
            (((func_8002A47C(M2C_FIELD(self, s8*, 1)) + 1) * 4 + 0x20) % 16) |
            (((func_8002A47C(M2C_FIELD(self, s8*, 1)) + 9) / 4 + 0x1E0) << 6);
        M2C_FIELD(self, s32*, 0x3C) =
            (s32)SPAD20 + SPAD20[func_8002A47C(M2C_FIELD(self, s8*, 1)) + 2];
        if (D_800CCEDC == 0xC) {
            M2C_FIELD(self, s16*, 0x42) = 0x794C;
            M2C_FIELD(self, s32*, 0x3C) = (s32)SPAD9C + SPAD9C[2];
        }
    }
    func_800179A4(self, arg1);
}
#undef D_800CCEDC
