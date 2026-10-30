#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
extern M2C_UNK D_8007433C;
extern s32 D_80075A5C;
extern s8 D_8009711A;
extern s32 D_800FCA84;

#define TBL(off) ((s32*)((s32) & D_800FCA84 + (off)))

void func_800FA23C(void* arg0) {
    s32 r;
    u8 t;
    u8 k;
    s32* a;

    if ((u32)(M2C_FIELD(arg0, u8*, 0x47) - 0x2D) < 0xB) {
        a = TBL(0x14);
    } else {
        a = TBL(0x10);
    }
    M2C_FIELD(arg0, s32**, 0x54) = a;
    r = check_enemy_hits(arg0);
    if (r < 0) {
        *TBL(0x3D4) = 1;
        M2C_FIELD(arg0, s8*, 4) = 2;
        M2C_FIELD(arg0, s8*, 5) = 0;
        M2C_FIELD(arg0, s8*, 6) = 0;
        M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
        D_8009711A = 1;
        func_8002CCB0(arg0, 0x40, 0x40);
        return;
    }
    k = M2C_FIELD(arg0, u8*, 0x47);
    if ((u32)(k - 0x2D) < 0xB) {
        if (k == 0x34) {
            a = TBL(0xC);
        } else {
            a = TBL(8);
        }
    } else {
        a = TBL(4);
    }
    M2C_FIELD(arg0, s32**, 0x50) = a;
    func_80030ECC(arg0);
    if (r > 0 && r != 0x7F) {
        M2C_FIELD(arg0, u8*, 0x88) = ((u32)(r - 0x19) < 2) ? 2 : 0x1E;
        M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
        if (M2C_FIELD(arg0, s8*, 5) == 9) {
            M2C_FIELD(arg0, s32*, 0x84) = 1;
        }
    }
    if (M2C_FIELD(arg0, s8*, 5) != 9) {
        if (r == 7 || r == 0x10 || r == 0x2B || r == 0x2F) {
            M2C_FIELD(arg0, s32*, 0x84) = 0;
            *TBL(0x3D8) = 1;
            M2C_FIELD(arg0, s8*, 5) = 9;
            M2C_FIELD(arg0, s8*, 6) = 0;
            M2C_FIELD(arg0, u8*, 0x88) = 0x14;
        }
    }
    t = M2C_FIELD(arg0, u8*, 0x88);
    if (t != 0) {
        M2C_FIELD(arg0, u8*, 0x88) = t + 0xFF;
        if (t & 2) {
            M2C_FIELD(arg0, u16*, 0x42) |= 0x8000;
        } else {
            M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
        }
        if (M2C_FIELD(arg0, u8*, 0x88) == 0) {
            M2C_FIELD(arg0, void**, 0x58) = &D_80075A5C;
            M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
        }
    }
    ((void (**)(void*))TBL(0x2F8))[M2C_FIELD(arg0, s8*, 5)](arg0);
}
