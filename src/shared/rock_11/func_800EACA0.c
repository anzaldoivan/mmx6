#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD (*(u8**)0x1F80004C)

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_800EC728();
extern s32 D_800741FC[];
extern u8 D_800970B4;
extern u8 D_800FB26C[];
extern u8 D_800FBEF8[];
extern u8 D_800FBF2C[];
extern u8 D_800FBF34[];

void func_800EACA0(void* self) {
    M2C_FIELD(self, u8*, 0x3) = 0;
    if (func_800EC728() != 0) {
        M2C_FIELD(self, u8*, 0x4) = 3;
        return;
    }
    M2C_FIELD(SPAD, s16*, 0x84) = 0;
    if ((M2C_FIELD(self, s8*, 0x2) & 0xF0) == 0x10) {
        M2C_FIELD(SPAD, s16*, 0x84) = 0x3C;
    }
    M2C_FIELD(self, void**, 0x30) = D_800FBEF8;
    M2C_FIELD(self, u8*, 0x14) = D_800970B4;
    M2C_FIELD(self, u8*, 0x5C) = 8;
    M2C_FIELD(self, u8*, 0x60) = 4;
    M2C_FIELD(self, void**, 0x50) = D_800FBF2C;
    M2C_FIELD(self, s32*, 0x54) = 0;
    M2C_FIELD(self, void**, 0x68) = SPAD + 0x86;
    __builtin_memcpy(SPAD + 0x86, D_800FBF34, 4);
    SPAD[0x8A] = 0;
    M2C_FIELD(self, void**, 0x58) = D_800741FC;
    M2C_FIELD(self, u8*, 0x70) = 0;
    M2C_FIELD(self, u8*, 0x16) = 5;
    func_800179A4(self, 0);
    M2C_FIELD(self, s32*, 0x24) = 0xFFFE0000;
    M2C_FIELD(self, s32*, 0x28) = 0;
    M2C_FIELD(self, s32*, 0x2C) = 0;
    M2C_FIELD(self, u8*, 0x67) = 1;
    M2C_FIELD(self, u8*, 0x4) = 1;
    func_80016C48(2, 0x3C, self);
    M2C_FIELD(self, u8*, 0x5) = 2;
    M2C_FIELD(self, u8*, 0x6) = 0;
}
