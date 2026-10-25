#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002F288(M2C_UNK*);
M2C_UNK func_80031DA8();
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
M2C_UNK func_80049EBC(void*, M2C_UNK, M2C_UNK, M2C_UNK);
s32 func_800ECAB8(struct X4_PlayerObj*, s16, s16);
extern M2C_UNK g_Player;
extern M2C_UNK D_800F3A0C;
extern M2C_UNK D_800F3A10;
extern M2C_UNK D_800F3A1C;

#define F_2(p) M2C_FIELD(p, u8*, 0x2)
#define F_4(p) M2C_FIELD(p, u8*, 0x4)
#define F_6(p) M2C_FIELD(p, u8*, 0x6)
#define F_A(p) M2C_FIELD(p, s16*, 0xA)
#define F_E(p) M2C_FIELD(p, s16*, 0xE)
#define F_20(p) M2C_FIELD(p, s32*, 0x20)
#define F_24(p) M2C_FIELD(p, s32*, 0x24)
#define F_28(p) M2C_FIELD(p, s32*, 0x28)
#define F_2C(p) M2C_FIELD(p, s32*, 0x2C)
#define F_50(p) M2C_FIELD(p, void**, 0x50)
#define F_70(p) M2C_FIELD(p, u8*, 0x70)
#define F_7C(p) M2C_FIELD(p, s16*, 0x7C)
#define F_80(p) M2C_FIELD(p, s8*, 0x80)
#define F_81(p) M2C_FIELD(p, s8*, 0x81)
#define F_82(p) M2C_FIELD(p, u8*, 0x82)
#define F_83(p) M2C_FIELD(p, u8*, 0x83)
#define F_84(p) M2C_FIELD(p, u8*, 0x84)
#define F_85(p) M2C_FIELD(p, u8*, 0x85)

#define PL_2(p) M2C_FIELD(p, s8*, 0x2)
#define PL_4(p) M2C_FIELD(p, s32*, 0x4)
#define PL_5(p) M2C_FIELD(p, s8*, 0x5)
#define PL_15(p) M2C_FIELD(p, u8*, 0x15)
#define PL_71(p) M2C_FIELD(p, u8*, 0x71)
#define PL_E5(p) M2C_FIELD(p, u8*, 0xE5)

#define ABS(x) ((x) < 0 ? -(x) : (x))
#define RX(p) (F_A(p) + F_80(p) + F_82(p))
#define LX(p) (F_A(p) + F_80(p) - F_82(p))
#define FY(p) (F_E(p) + F_81(p) + F_83(p))
#define CHECK(p)                                                               \
    {                                                                          \
        void* pl_ = &g_Player;                                                 \
        if (PL_E5(pl_) == 0 && ABS(F_A(pl_) - F_A(p)) < 0x30) {                \
            func_80031DA8(p);                                                  \
        }                                                                      \
    }

void func_800EDC9C(void* arg0) {
    void* pl;
    s32 b;
    s32 c;
    s32 f;
    s8 k;
    s16 t;

    pl = &g_Player;
    ((void (*)(void*))func_8002F288)(arg0);
    b = func_800ECAB8(arg0, (t = RX(arg0), t - 1), FY(arg0));
    c = func_800ECAB8(arg0, LX(arg0), FY(arg0));
    if (!(F_70(arg0) & 8) && b == 0 && c == 0) {
        F_2C(arg0) = 0xD00;
        F_6(arg0) = 1;
        F_85(arg0) = 0;
        CHECK(arg0);
        return;
    }
    F_84(arg0) = PL_71(pl);
    CHECK(arg0);
    F_84(arg0) ^= PL_71(pl);
    f = 0;
    if (PL_2(pl) != 0) {
        f = PL_5(pl) == 0x39;
    } else if ((PL_4(pl) & 0xFFFF00) == 0x22C00) {
        f = 1;
    }
    if (f == 0) {
        return;
    }
    if (F_2(arg0) < 2) {
        if ((F_84(arg0) & 2) && PL_15(pl) == 0) {
            F_20(arg0) = -0x40000;
            if ((s8)F_2(arg0) == 1) {
                F_28(arg0) = 0x2400;
            } else {
                F_28(arg0) = -0x2400;
            }
        } else if ((F_84(arg0) & 1) && PL_15(pl) == 0x40) {
            F_20(arg0) = 0x40000;
            if ((s8)F_2(arg0) == 1) {
                F_28(arg0) = -0x2400;
            } else {
                F_28(arg0) = 0x2400;
            }
        } else {
            return;
        }
        F_24(arg0) = 0;
        F_2C(arg0) = 0;
        F_6(arg0) = 0;
        F_7C(arg0) = F_A(arg0);
    }
    f = 0;
    if ((F_84(arg0) & 2) && PL_15(pl) == 0) {
        f = 1;
    } else if ((F_84(arg0) & 1) && PL_15(pl) == 0x40) {
        f = 1;
    }
    if (f != 0 && PL_2(pl) == 0) {
        k = F_2(arg0);
        if (k == 3) {
            F_85(arg0) = 0x1E;
            F_50(arg0) = &D_800F3A1C;
            func_800477E4(3, &D_800F3A10, arg0);
            F_4(arg0) = 2;
        } else if (k == 2) {
            func_800477E4(3, &D_800F3A0C, arg0);
            func_80049EBC(arg0, 1, 0x1F, 0xF);
            F_4(arg0) = k;
        }
    }
}
