#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK move_object(void*);
M2C_UNK func_8002F288(M2C_UNK*);
s32 func_800EB96C(struct X4_PlayerObj*, s16, s16);

#define F_6(p) M2C_FIELD(p, u8*, 0x6)
#define F_8(p) M2C_FIELD(p, s16*, 0x8)
#define F_A(p) M2C_FIELD(p, s16*, 0xA)
#define F_E(p) M2C_FIELD(p, s16*, 0xE)
#define F_20(p) M2C_FIELD(p, s32*, 0x20)
#define F_24(p) M2C_FIELD(p, s32*, 0x24)
#define F_70(p) M2C_FIELD(p, u8*, 0x70)
#define F_80(p) M2C_FIELD(p, s8*, 0x80)
#define F_81(p) M2C_FIELD(p, s8*, 0x81)
#define F_82(p) M2C_FIELD(p, u8*, 0x82)
#define F_83(p) M2C_FIELD(p, u8*, 0x83)

#define RX(p) (F_A(p) + F_80(p) + F_82(p))
#define LX(p) (F_A(p) + F_80(p) - F_82(p))
#define FY(p) (F_E(p) + F_81(p) + F_83(p))

void func_800EC1DC(void* arg0) {
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    s32 e;
    s32 f;
    s32 vx;
    s16 t;

    ((void (*)(void))move_object)();
    ((void (*)(void*))func_8002F288)(arg0);
    a = func_800EB96C(arg0, (t = RX(arg0), t - 1), FY(arg0));
    b = func_800EB96C(arg0, (t = LX(arg0), t + 1), FY(arg0));
    c = func_800EB96C(arg0, RX(arg0), F_E(arg0) + 0x10);
    d = func_800EB96C(arg0, (t = LX(arg0), t - 1), F_E(arg0) + 0x10);
    e = func_800EB96C(arg0, RX(arg0), F_E(arg0));
    f = func_800EB96C(arg0, (t = LX(arg0), t - 1), F_E(arg0));
    vx = F_20(arg0);
    if ((vx > 0 && (c != 0 || (F_70(arg0) & 1))) ||
        (vx < 0 && (d != 0 || (F_70(arg0) & 2))) ||
        (vx > 0 && (e != 0 || (F_70(arg0) & 1))) ||
        (vx < 0 && (f != 0 || (F_70(arg0) & 2)))) {
        F_20(arg0) = 0;
        F_6(arg0) = 7;
        F_A(arg0) = (F_A(arg0) & 0xFFF0) | 8;
    } else if (a == 0 && b == 0 && !(F_70(arg0) & 8)) {
        F_8(arg0) = 0;
        F_20(arg0) = 0;
        F_24(arg0) = 0xFFFF0000;
        F_6(arg0) = 6;
        F_A(arg0) = (F_A(arg0) & 0xFFF0) | 8;
    }
}
