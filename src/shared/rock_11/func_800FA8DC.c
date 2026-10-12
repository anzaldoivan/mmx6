#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
extern s16 D_800970AE;
extern u8 D_800FD470[];
extern u8 D_800FD474[];
extern u8 D_800FD47C[];
extern u8 D_800FD480[];

void func_800FA8DC(void* self) {
    func_80016C48(2, 0x46, self);
    if (M2C_FIELD(self, s16*, 0xE) > D_800970AE) {
        func_800179A4(self, 0xA);
        M2C_FIELD(self, void**, 0x50) = D_800FD470;
        M2C_FIELD(self, void**, 0x68) = D_800FD47C;
        M2C_FIELD(self, s32*, 0x24) = 0x18000;
        M2C_FIELD(self, u8*, 0x7) = 0;
        M2C_FIELD(self, u8*, 0x6)++;
    } else {
        func_800179A4(self, 0xB);
        M2C_FIELD(self, void**, 0x50) = D_800FD474;
        M2C_FIELD(self, void**, 0x68) = D_800FD480;
        M2C_FIELD(self, s32*, 0x24) = 0xFFFE8000;
        M2C_FIELD(self, u8*, 0x7) = 1;
        M2C_FIELD(self, u8*, 0x6)++;
    }
    M2C_FIELD(self, s32*, 0x20) = 0;
    if ((M2C_FIELD(self, u8*, 0x2) & 0xF) == 1) {
        M2C_FIELD(self, s32*, 0x24) *= 2;
    }
}
