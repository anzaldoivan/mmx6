#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);
extern s32 D_800741FC[];
extern s32 D_800FAEC0[];
extern s32 D_800FAEC8[];
extern s8 D_800FAECC[];

void func_800ECA60(void* self) {
    void* parent;

    M2C_FIELD(self, s8*, 3) = 1;
    M2C_FIELD(self, void**, 0x68) = D_800FAEC8;
    M2C_FIELD(self, void**, 0x54) = D_800FAEC0;
    M2C_FIELD(self, void**, 0x50) = D_800FAEC0;
    M2C_FIELD(self, s32*, 0x28) = 0;
    M2C_FIELD(self, s32*, 0x2C) = 0;
    M2C_FIELD(self, s8*, 0x67) = 0;
    M2C_FIELD(self, s8*, 0x16) = 1;
    M2C_FIELD(self, void**, 0x58) = D_800741FC;
    M2C_FIELD(self, u8*, 4)++;
    parent = M2C_FIELD(self, void**, 0x7C);
    M2C_FIELD(self, u16*, 0x40) = M2C_FIELD(parent, u16*, 0x40);
    M2C_FIELD(self, u16*, 0x42) = M2C_FIELD(parent, u16*, 0x42) & 0x7FFF;
    M2C_FIELD(self, s32*, 0x30) = M2C_FIELD(parent, s32*, 0x30);
    M2C_FIELD(self, s32*, 0x3C) = M2C_FIELD(parent, s32*, 0x3C);
    M2C_FIELD(self, u8*, 0x15) = M2C_FIELD(parent, u8*, 0x15);
    M2C_FIELD(self, u8*, 0x14) = M2C_FIELD(parent, u8*, 0x14);
    M2C_FIELD(self, s8*, 0x60) = 3;
    M2C_FIELD(self, s8*, 0x5C) = 1;
    M2C_FIELD(self, s32*, 0x20) *= 2;
    M2C_FIELD(self, s32*, 0x24) *= 2;
    switch (M2C_FIELD(self, s8*, 2) & 0xFE) {
    case 2:
    case 4:
    case 6:
        M2C_FIELD(self, s16*, 0xA) += D_800FAECC[6];
        M2C_FIELD(self, s16*, 0xE) += D_800FAECC[7];
        break;
    case 10:
    case 12:
    case 14:
        M2C_FIELD(self, s16*, 0xA) += D_800FAECC[4];
        M2C_FIELD(self, s16*, 0xE) += D_800FAECC[5];
        break;
    case 8:
        M2C_FIELD(self, s16*, 0xA) += D_800FAECC[8];
        M2C_FIELD(self, s16*, 0xE) += D_800FAECC[9];
        break;
    case 18:
    case 20:
    case 22:
        M2C_FIELD(self, s16*, 0xA) += D_800FAECC[12];
        M2C_FIELD(self, s16*, 0xE) += D_800FAECC[13];
        break;
    case 26:
    case 28:
    case 30:
        M2C_FIELD(self, s16*, 0xA) += D_800FAECC[14];
        M2C_FIELD(self, s16*, 0xE) += D_800FAECC[15];
        break;
    case 24:
        M2C_FIELD(self, s16*, 0xA) += D_800FAECC[10];
        M2C_FIELD(self, s16*, 0xE) += D_800FAECC[11];
        break;
    default:
        if (M2C_FIELD(self, u8*, 0x15) & 0x40) {
            M2C_FIELD(self, s16*, 0xA) += D_800FAECC[2];
            M2C_FIELD(self, s16*, 0xE) += D_800FAECC[3];
        } else {
            M2C_FIELD(self, s16*, 0xA) += D_800FAECC[0];
            M2C_FIELD(self, s16*, 0xE) += D_800FAECC[1];
        }
        break;
    }
    func_800179A4(self, 6);
}
