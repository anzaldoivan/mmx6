#include "common.h"
#define M2C_UNK s32

#define FLD(p, type, off) (*(type*)((u8*)(p) + (off)))

M2C_UNK func_80017A04();
M2C_UNK move_object(void*);
M2C_UNK func_80030ECC(void*);
s32 func_80031474(void*);
extern s16 D_800F6AF8;
extern s16 D_800F6AFA;

void func_800F1728(void* arg0) {
    void* parent;
    s32 r;
    s16 x;
    s16 y;
    s32 a, b, c, d;
    s16 dx;
    s16 dy;

    parent = FLD(arg0, void*, 0x7C);
    func_80017A04();
    move_object(arg0);
    FLD(arg0, s32, 0x8C) = func_80031474(arg0);
    if (FLD(arg0, s32, 0x8C) < 0) {
        FLD(arg0, u8, 0x5) = 2;
        FLD(arg0, s16, 0x90) = 0x1E;
        FLD(parent, u8, 0x7) = 2;
        return;
    }
    func_80030ECC(arg0);
    x = FLD(arg0, s16, 0xA);
    dx = D_800F6AF8;
    r = FLD(arg0, s8, 0x2) * 16;
    if ((a = r + 0x7E0, dx + a < x) || (b = r - 0x620, x < dx - b) ||
        (dy = D_800F6AFA, c = r + 0x580, dy + c < (y = FLD(arg0, s16, 0xE))) ||
        (d = r - 0x450, y < dy - d)) {
        FLD(parent, u8, 0x7) = 2;
        FLD(arg0, u8, 0x4) = 2;
    }
}
