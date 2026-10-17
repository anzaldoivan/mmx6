#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_8002CB50(struct X4_BaseObj*);
s32 func_8002D2D4();
extern u8 D_800970B4;
extern s32 D_80077AE0[];
extern s32 D_80077B00[];

void func_80047B34(void* arg0) {
    void* parent;
    s32 t;
    // !FAKE: pin the flag byte in the first argument register
    register s32 b asm("$4");

    M2C_FIELD(arg0, s8*, 0x3) = 1;
    if (M2C_FIELD(arg0, s8*, 0x2) == 0) {
        parent = M2C_FIELD(arg0, void**, 0x54);
        M2C_FIELD(arg0, s32*, 0x3C) = M2C_FIELD(parent, s32*, 0x3C);
        M2C_FIELD(arg0, s32*, 0x30) = M2C_FIELD(parent, s32*, 0x30);
        M2C_FIELD(arg0, u16*, 0x40) = M2C_FIELD(parent, u16*, 0x40);
        M2C_FIELD(arg0, u16*, 0x42) = M2C_FIELD(parent, u16*, 0x42) & 0x7FFF;
    }
    M2C_FIELD(arg0, u8*, 0x16) = 1;
    b = D_800970B4;
    M2C_FIELD(arg0, s32*, 0x2C) = 0x5000;
    M2C_FIELD(arg0, u8*, 0x14) = b;
    M2C_FIELD(arg0, s32*, 0x20) =
        D_80077AE0[func_8002D2D4(b) & 7] +
        M2C_FIELD(M2C_FIELD(arg0, void**, 0x54), s32*, 0x20) / 2;
    t = func_8002D2D4();
    t = D_80077B00[t & 7];
    M2C_FIELD(arg0, s32*, 0x24) = t;
    ((void (*)(void*, s32, s32))func_800179A4)(arg0, M2C_FIELD(arg0, u8*, 0x58),
                                               t);
    M2C_FIELD(arg0, u8*, 0x4) += 1;
    func_8002CB50(arg0);
}
