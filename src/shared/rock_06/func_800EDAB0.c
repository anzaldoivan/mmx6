#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
M2C_UNK func_8002F288(M2C_UNK*);
M2C_UNK func_80031DA8();
s32 func_800ECAB8(struct X4_PlayerObj*, s16, s16);
extern M2C_UNK D_800970A0;

#define F_3(p) M2C_FIELD(p, s8*, 0x3)
#define F_6(p) M2C_FIELD(p, u8*, 0x6)
#define F_8(p) M2C_FIELD(p, s16*, 0x8)
#define F_A(p) M2C_FIELD(p, s16*, 0xA)
#define F_C(p) M2C_FIELD(p, s16*, 0xC)
#define F_E(p) M2C_FIELD(p, s16*, 0xE)
#define F_20(p) M2C_FIELD(p, s32*, 0x20)
#define F_24(p) M2C_FIELD(p, s32*, 0x24)
#define F_28(p) M2C_FIELD(p, s32*, 0x28)
#define F_2C(p) M2C_FIELD(p, s32*, 0x2C)
#define F_70(p) M2C_FIELD(p, u8*, 0x70)
#define F_80(p) M2C_FIELD(p, s8*, 0x80)
#define F_81(p) M2C_FIELD(p, s8*, 0x81)
#define F_82(p) M2C_FIELD(p, u8*, 0x82)
#define F_83(p) M2C_FIELD(p, u8*, 0x83)
#define F_85(p) M2C_FIELD(p, u8*, 0x85)

#define PL_E5(p) M2C_FIELD(p, u8*, 0xE5)

#define ABS(x) ((x) < 0 ? -(x) : (x))
#define RX(p) (F_A(p) + F_80(p) + F_82(p))
#define LX(p) (F_A(p) + F_80(p) - F_82(p))
#define FY(p) (F_E(p) + F_81(p) + F_83(p))
#define CHECK(p)                                                               \
    {                                                                          \
        void* pl_ = &D_800970A0;                                               \
        if (PL_E5(pl_) == 0 && ABS(F_A(pl_) - F_A(p)) < 0x30) {                \
            func_80031DA8(p);                                                  \
        }                                                                      \
    }

void func_800EDAB0(void* arg0) {
    s32 b;
    s32 c;
    s16 t;

    b = func_800ECAB8(arg0, (t = RX(arg0), t - 1), FY(arg0));
    c = func_800ECAB8(arg0, LX(arg0), FY(arg0));
    if ((F_70(arg0) & 8) || b != 0 || c != 0) {
        F_C(arg0) = 0;
        F_E(arg0) = (F_E(arg0) & 0xFFF0) | 8;
        func_80016C48(2, 0x52, 0);
        if (F_85(arg0) >= 0x11 && F_3(arg0) != 0) {
            func_8002943C(0x10, 2, 1);
        }
        F_8(arg0) = 0;
        F_20(arg0) = 0;
        F_28(arg0) = 0;
        F_24(arg0) = 0;
        F_2C(arg0) = 0;
        F_6(arg0) = 2;
    }
    if (F_24(arg0) <= -0x20000) {
        F_24(arg0) = -0x20000;
    }
    ((void (*)(void*))func_8002D230)(arg0);
    F_85(arg0)++;
    CHECK(arg0);
    ((void (*)(void*))func_8002F288)(arg0);
}
