#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002D230(void*);    /* extern */
M2C_UNK func_8002F288(M2C_UNK*); /* extern */
M2C_UNK func_80031DA8();         /* extern */
s32 func_800ECAB8(struct X4_PlayerObj*, s16, s16);
extern M2C_UNK g_Player;

#define F_2(p) M2C_FIELD(p, s8*, 0x2)
#define F_6(p) M2C_FIELD(p, u8*, 0x6)
#define F_8(p) M2C_FIELD(p, s16*, 0x8)
#define F_A(p) M2C_FIELD(p, s16*, 0xA)
#define F_E(p) M2C_FIELD(p, s16*, 0xE)
#define F_20(p) M2C_FIELD(p, s32*, 0x20)
#define F_24(p) M2C_FIELD(p, s32*, 0x24)
#define F_28(p) M2C_FIELD(p, s32*, 0x28)
#define F_2C(p) M2C_FIELD(p, s32*, 0x2C)
#define F_70(p) M2C_FIELD(p, u8*, 0x70)
#define F_7C(p) M2C_FIELD(p, s16*, 0x7C)
#define F_80(p) M2C_FIELD(p, s8*, 0x80)
#define F_81(p) M2C_FIELD(p, s8*, 0x81)
#define F_82(p) M2C_FIELD(p, u8*, 0x82)
#define F_83(p) M2C_FIELD(p, u8*, 0x83)
#define F_85(p) M2C_FIELD(p, u8*, 0x85)
#define F_E5(p) M2C_FIELD(p, u8*, 0xE5)

#define ABS(x) ((x) < 0 ? -(x) : (x))
#define RX(p) (F_A(p) + F_80(p) + F_82(p))
#define LX(p) (F_A(p) + F_80(p) - F_82(p))
#define FY(p) (F_E(p) + F_81(p) + F_83(p))
#define CHECK(p)                                                               \
    {                                                                          \
        void* pl = &g_Player;                                                  \
        if (F_E5(pl) == 0 && ABS(F_A(pl) - F_A(p)) < 0x30) {                   \
            func_80031DA8(p);                                                  \
        }                                                                      \
    }

void func_800ED09C(void* arg0) {
    s32 a;
    s32 b;
    s32 c;
    s16 i;
    s16 t;

    func_8002D230(arg0);
    ((void (*)(void*))func_8002F288)(arg0);
    if (F_20(arg0) > 0) {
        b = func_800ECAB8(arg0, (t = RX(arg0), t - 1), FY(arg0));
        c = func_800ECAB8(arg0, (t = LX(arg0), t - 1), FY(arg0));
        if (b == 0 && c == 0 && !(F_70(arg0) & 8)) {
            for (i = 0; i < 5; i++) {
                b = func_800ECAB8(arg0, (t = RX(arg0), t - 1), FY(arg0));
                c = func_800ECAB8(arg0, (t = LX(arg0), t - 1), FY(arg0));
                if (b == 0 && c == 0 && !(F_70(arg0) & 8)) {
                    F_A(arg0)--;
                }
                ((void (*)(void*))func_8002F288)(arg0);
            }
            if (F_70(arg0) & 8) {
                F_A(arg0)++;
            }
            F_20(arg0) = 0;
            F_28(arg0) = 0;
            F_2C(arg0) = 0xD00;
            F_6(arg0) = 1;
            F_85(arg0) = 0;
            CHECK(arg0);
            return;
        }
    }
    if (F_20(arg0) < 0) {
        b = func_800ECAB8(arg0, RX(arg0), FY(arg0));
        c = func_800ECAB8(arg0, LX(arg0), FY(arg0));
        if (b == 0 && c == 0 && !(F_70(arg0) & 8)) {
            for (i = 0; i < 5; i++) {
                b = func_800ECAB8(arg0, RX(arg0), FY(arg0));
                c = func_800ECAB8(arg0, LX(arg0), FY(arg0));
                if (b == 0 && c == 0 && !(F_70(arg0) & 8)) {
                    F_A(arg0)++;
                }
                ((void (*)(void*))func_8002F288)(arg0);
            }
            if (F_70(arg0) & 8) {
                F_A(arg0)--;
            }
            F_20(arg0) = 0;
            F_28(arg0) = 0;
            F_2C(arg0) = 0xD00;
            F_6(arg0) = 1;
            F_85(arg0) = 0;
            CHECK(arg0);
            return;
        }
    }
    a = func_800ECAB8(arg0, (t = RX(arg0), t - 1), F_E(arg0) + 0x10);
    b = func_800ECAB8(arg0, (t = RX(arg0), t - 1), F_E(arg0));
    c = func_800ECAB8(arg0, (t = RX(arg0), t - 1), F_E(arg0) - 0x10);
    if (F_20(arg0) > 0 && (a != 0 || b != 0 || c != 0 || (F_70(arg0) & 1))) {
        for (i = 0; i < 5; i++) {
            a = func_800ECAB8(arg0, (t = RX(arg0), t - 1), F_E(arg0) + 0x10);
            b = func_800ECAB8(arg0, (t = RX(arg0), t - 1), F_E(arg0));
            c = func_800ECAB8(arg0, (t = RX(arg0), t - 1), F_E(arg0) - 0x10);
            if (a != 0 || b != 0 || c != 0) {
                F_A(arg0)--;
            }
        }
        F_20(arg0) = 0;
        F_28(arg0) = 0;
        F_6(arg0) = 2;
        CHECK(arg0);
        return;
    }
    a = func_800ECAB8(arg0, LX(arg0), F_E(arg0) + 0x10);
    b = func_800ECAB8(arg0, LX(arg0), F_E(arg0));
    c = func_800ECAB8(arg0, LX(arg0), F_E(arg0) - 0x10);
    if (F_20(arg0) < 0 && (a != 0 || b != 0 || c != 0 || (F_70(arg0) & 2))) {
        for (i = 0; i < 5; i++) {
            a = func_800ECAB8(arg0, LX(arg0), F_E(arg0) + 0x10);
            b = func_800ECAB8(arg0, LX(arg0), F_E(arg0));
            c = func_800ECAB8(arg0, LX(arg0), F_E(arg0) - 0x10);
            if (a != 0 || b != 0 || c != 0) {
                F_A(arg0)++;
            }
        }
        F_20(arg0) = 0;
        F_28(arg0) = 0;
        F_6(arg0) = 2;
        CHECK(arg0);
        return;
    }
    if (F_20(arg0) > 0x42000) {
        F_20(arg0) = 0x42000;
    } else if (F_20(arg0) < -0x42000) {
        F_20(arg0) = -0x42000;
    }
    if (F_2(arg0) == 0 && ABS(F_7C(arg0) - F_A(arg0)) >= 0x30) {
        if (F_20(arg0) > 0) {
            F_A(arg0) = F_7C(arg0) + 0x30;
        } else {
            F_A(arg0) = F_7C(arg0) - 0x30;
        }
        F_8(arg0) = 0;
        F_20(arg0) = 0;
        F_28(arg0) = 0;
        F_24(arg0) = 0;
        F_2C(arg0) = 0;
        F_6(arg0) = 2;
    }
    CHECK(arg0);
}
