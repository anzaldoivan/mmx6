#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern u8 D_800FB26C[];

void func_800F38C4(s8* self) {
    s32 y;

    M2C_FIELD(self, u8**, 0x50) = D_800FB26C + 0x104C;
    M2C_FIELD(self, s16*, 0x7C) = 0xA00;
    M2C_FIELD(self, u8*, 0x3) = 0;
    M2C_FIELD(self, s16*, 0x7E) = 0;
    y = M2C_FIELD(self, u16*, 0xE) - 0xE;
    M2C_FIELD(self, u16*, 0xE) = y;
    M2C_FIELD(self, u16*, 0x84) = M2C_FIELD(self, u16*, 0xA);
    M2C_FIELD(self, u16*, 0x86) = y;
    M2C_FIELD(self, u8*, 0x6) = M2C_FIELD(self, u8*, 0x6) + 1;
}
