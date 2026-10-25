#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define FLD_F3CA0(expr, type, offset) (*(type*)((u8*)(expr) + (offset)))

s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
s32 func_8002DCF4(void*, void*);
s32 func_80031474(void*);

extern struct X4_PlayerObj g_Player;
extern struct X4_RideArmorObj D_800CD340;

void func_800F3CA0(void* arg0) {
    struct X4_PlayerObj* pl;
    void* tgt;
    s32 r;
    s32 q;
    s32 t;
    s32 c;

    pl = &g_Player;
    if (FLD_F3CA0(pl, s8, 0xD5) == 0) {
        tgt = pl;
    } else {
        tgt = &D_800CD340;
        if (FLD_F3CA0(tgt, s8, 0x5) == 0) {
            tgt = (u8*)tgt + 0xB0;
        }
    }
    do {
        FLD_F3CA0(arg0, u8, 0x5C) = 0x7F;
        FLD_F3CA0(arg0, s32, 0x18) = FLD_F3CA0(arg0, s32, 0x8);
        FLD_F3CA0(arg0, s32, 0x1C) = FLD_F3CA0(arg0, s32, 0xC);
        q = func_80031474(arg0);
        FLD_F3CA0(arg0, u16, 0x42) &= 0x7FFF;
    } while (0);
    r = q;
    c = FLD_F3CA0(arg0, s16, 0x7C);
    t = FLD_F3CA0(arg0, u16, 0x7C);
    if (c == 0) {
        if (r > 0) {
            r -= 1;
            if (r == 0x2C) {
                FLD_F3CA0(arg0, u8, 0x3) = 1;
                FLD_F3CA0(arg0, s16, 0x7C) = 0x96;
                return;
            }
        }
        if (func_8002DCF4(arg0, tgt) != 0) {
            FLD_F3CA0(arg0, u8, 0x3) = 1;
            FLD_F3CA0(arg0, s16, 0x7C) = 0x96;
            FLD_F3CA0(arg0, s16, 0x7E) = 1;
            return;
        }
    } else {
        FLD_F3CA0(arg0, s16, 0x7C) = t - 1;
        if (FLD_F3CA0(arg0, s16, 0x7C) >= 0x1F) {
            if (FLD_F3CA0(arg0, s16, 0x7E) == 1 &&
                func_8002DCF4(arg0, tgt) == 0) {
                FLD_F3CA0(arg0, s16, 0x7C) = 0x3C;
                FLD_F3CA0(arg0, s16, 0x7E) = 0;
            }
        } else if (FLD_F3CA0(arg0, s16, 0x7C) & 1) {
            FLD_F3CA0(arg0, u8, 0x3) = 1;
        } else {
            FLD_F3CA0(arg0, u8, 0x3) = 0;
        }
        if (FLD_F3CA0(arg0, s16, 0x7C) == 0) {
            FLD_F3CA0(arg0, u8, 0x3) = 0;
            FLD_F3CA0(arg0, s16, 0x7E) = 0;
        }
    }
    if (func_8002CBFC(arg0, 0x50, 0xA0) == 1) {
        FLD_F3CA0(arg0, u8, 0x4) = 2;
    }
}
#undef FLD_F3CA0
