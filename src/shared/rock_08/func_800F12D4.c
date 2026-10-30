#include "common.h"
#define M2C_UNK s32

#define FLD(p, type, off) (*(type*)((u8*)(p) + (off)))

M2C_UNK func_80017A04();
s32 random_byte();
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
extern u8 D_800F6288[];

void func_800F12D4(void* arg0) {
    void* parent;
    s8 t;
    s32 r;

    parent = FLD(arg0, void*, 0x7C);
    FLD(arg0, s32, 0x8C) = check_enemy_hits(arg0);
    if (FLD(arg0, s32, 0x8C) < 0) {
        FLD(arg0, u8, 0x5) = 2;
        FLD(arg0, s16, 0x90) = 0x3C;
        FLD(parent, u8, 0x7) = 1;
        return;
    }
    func_80030ECC(arg0);
    if (FLD(parent, s8, 0x5) != 8) {
        if (FLD(parent, u8, 0x15) != 0) {
            FLD(arg0, s16, 0xA) =
                FLD(parent, s16, 0xA) + (s8)D_800F6288[FLD(arg0, s8, 0x2) * 4];
        } else {
            FLD(arg0, s16, 0xA) =
                FLD(parent, s16, 0xA) - (s8)D_800F6288[FLD(arg0, s8, 0x2) * 4];
        }
    }
    if (FLD(parent, s8, 0x5) != 0xA && FLD(parent, s8, 0x4) != 2) {
        {
            u8* p = D_800F6288;
            p -= -(FLD(arg0, s8, 0x2) * 4);
            FLD(arg0, s16, 0xE) = FLD(parent, s16, 0xE) - (s8)p[3];
        }
    }
    FLD(arg0, u8, 0x15) = FLD(parent, u8, 0x15);
    if (FLD(parent, s8, 0x5) == 3) {
        FLD(arg0, u8, 0x4) = 2;
        return;
    }
    t = FLD(parent, s8, 0x45);
    if (t == 1) {
        func_80017A04(arg0);
    } else if (t == 2) {
        r = random_byte();
        FLD(arg0, u8, 0x6) = 0;
        FLD(arg0, u8, 0x5) = (u32)r % 3 + 3;
    }
}
