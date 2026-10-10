#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern M2C_UNK D_800743DC;
extern struct X4_PlayerObj D_800970A0;
extern s32 D_800FB7A0;
extern s32 D_800FB7A4;
extern s32 D_800FB7A8;
extern s32 D_800FBA80;

void func_800EC670(void* self) {
    u8 t;
    s32 v;

    M2C_FIELD(self, void**, 0x30) = &D_800FBA80;
    t = D_800970A0.bg_offset;
    M2C_FIELD(self, u8*, 0x16) = 5;
    M2C_FIELD(self, void**, 0x68) = &D_800FB7A0;
    M2C_FIELD(self, void**, 0x50) = &D_800FB7A4;
    M2C_FIELD(self, void**, 0x54) = &D_800FB7A8;
    M2C_FIELD(self, void**, 0x58) = &D_800743DC;
    M2C_FIELD(self, u8*, 0x67) = 0;
    M2C_FIELD(self, s32*, 0x2C) = 0x40000;
    M2C_FIELD(self, u8*, 0x5C) = 12;
    M2C_FIELD(self, u8*, 3) = 0;
    M2C_FIELD(self, u8*, 0x61) = 0;
    M2C_FIELD(self, s32*, 0x20) = 0;
    M2C_FIELD(self, s32*, 0x24) = 0;
    M2C_FIELD(self, s32*, 0x28) = 0;
    M2C_FIELD(self, u8*, 0x60) = 4;
    M2C_FIELD(self, u8*, 0x14) = t;
    switch (M2C_FIELD(self, s8*, 2)) {
    case 0:
        if (D_800970A0.unk2 == 0) {
            M2C_FIELD(self, u8*, 5) = 6;
        } else {
            M2C_FIELD(self, u8*, 5) = 4;
        }
        break;
    case 1:
        if (D_800970A0.unk2 == 0) {
            M2C_FIELD(self, u8*, 5) = 7;
        } else {
            M2C_FIELD(self, u8*, 5) = 5;
        }
        break;
    case 2:
        M2C_FIELD(self, u8*, 5) = 2;
        break;
    case 3:
        M2C_FIELD(self, u8*, 5) = 3;
        break;
    case 4:
        v = 2;
        goto common;
    case 5:
        v = 3;
    common:
        M2C_FIELD(self, u8*, 5) = v;
        M2C_FIELD(self, u8*, 7) = 0;
        M2C_FIELD(self, s32*, 0x68) = 0;
        M2C_FIELD(self, s32*, 0x24) = 0;
        M2C_FIELD(self, s32*, 0x2C) = 0;
        break;
    }
    M2C_FIELD(self, u8*, 6) = 0;
    M2C_FIELD(self, u8*, 4)++;
}
