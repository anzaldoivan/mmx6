#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s32 func_80016C48(s32, s32, void*);
extern s32 func_800179A4(void*, s32);
extern s32 D_800743DC;
extern s16 D_800970AA;
extern s32 D_800FBB40;
extern s32 D_800FBB44;
extern s32 D_800FBB48;

void func_800EDF08(void* self) {
    void* p;
    void* q;
    s32 d;
    u8 t;

    p = M2C_FIELD(self, void**, 0x7C);
    M2C_FIELD(self, s32*, 0x30) = M2C_FIELD(p, s32*, 0x30);
    M2C_FIELD(self, u16*, 0x40) = M2C_FIELD(p, u16*, 0x40);
    M2C_FIELD(self, s32*, 0x3C) = M2C_FIELD(p, s32*, 0x3C);
    M2C_FIELD(self, s16*, 0x42) = M2C_FIELD(p, u16*, 0x42) & 0x7FFF;
    t = M2C_FIELD(p, u8*, 0x14);
    M2C_FIELD(self, void**, 0x50) = &D_800FBB44;
    M2C_FIELD(self, u8*, 0x16) = 4;
    M2C_FIELD(self, u8*, 0x67) = 0;
    M2C_FIELD(self, void**, 0x68) = &D_800FBB40;
    M2C_FIELD(self, u8*, 3) = 0;
    M2C_FIELD(self, void**, 0x54) = &D_800FBB48;
    M2C_FIELD(self, void**, 0x58) = &D_800743DC;
    M2C_FIELD(self, u8*, 0x14) = t;
    func_800179A4(self, 0x12);
    q = M2C_FIELD(self, void**, 0x7C);
    M2C_FIELD(self, u8*, 0x15) = M2C_FIELD(q, u8*, 0x15);
    if (M2C_FIELD(self, u8*, 0x15) == 0) {
        if (M2C_FIELD(q, s8*, 5) == 3) {
            M2C_FIELD(self, s16*, 0xA) = M2C_FIELD(q, u16*, 0xA) - 0xC;
            M2C_FIELD(self, s16*, 0xE) = M2C_FIELD(q, u16*, 0xE) - 0xC;
        } else if (M2C_FIELD(q, s8*, 5) == 6) {
            M2C_FIELD(self, s16*, 0xA) = M2C_FIELD(q, u16*, 0xA) - 0x10;
            M2C_FIELD(self, s16*, 0xE) = M2C_FIELD(q, u16*, 0xE) - 0xC;
        } else {
            M2C_FIELD(self, s16*, 0xA) = M2C_FIELD(q, u16*, 0xA);
            M2C_FIELD(self, s16*, 0xE) = M2C_FIELD(q, u16*, 0xE) - 0xE;
        }
    } else {
        if (M2C_FIELD(q, s8*, 5) == 3) {
            M2C_FIELD(self, s16*, 0xA) = M2C_FIELD(q, u16*, 0xA) + 0xC;
            M2C_FIELD(self, s16*, 0xE) = M2C_FIELD(q, u16*, 0xE) - 0xC;
        } else if (M2C_FIELD(q, s8*, 5) == 6) {
            M2C_FIELD(self, s16*, 0xA) = M2C_FIELD(q, u16*, 0xA);
            M2C_FIELD(self, s16*, 0xE) = M2C_FIELD(q, u16*, 0xE) - 0xE;
        } else {
            M2C_FIELD(self, s16*, 0xA) = M2C_FIELD(q, u16*, 0xA) + 0x10;
            M2C_FIELD(self, s16*, 0xE) = M2C_FIELD(q, u16*, 0xE) - 0xC;
        }
    }
    d = D_800970AA - M2C_FIELD(self, s16*, 0xA);
    M2C_FIELD(self, s32*, 0x24) = 0x30000;
    M2C_FIELD(self, s32*, 0x2C) = 0x1800;
    M2C_FIELD(self, s32*, 0x28) = 0;
    M2C_FIELD(self, u8*, 0x5C) = 2;
    M2C_FIELD(self, u8*, 0x60) = 3;
    M2C_FIELD(self, s32*, 0x20) = (d << 16) / 70;
    func_80016C48(2, 0xF, self);
    M2C_FIELD(self, u8*, 6) = 0;
    M2C_FIELD(self, u8*, 5) = 0;
    M2C_FIELD(self, u8*, 4)++;
}
