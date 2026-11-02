#include "common.h"

#define HIT(p) (*(u8**)((u8*)(p) + 0x68))
#define F8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F16(p, o) (*(s16*)((u8*)(p) + (o)))

s32 func_8002DCF4(void* arg0, void* arg1) {
    u8* hb;
    s16 xa;
    s16 xb;
    s16 d;

    if (HIT(arg0) == 0) {
        return 0;
    }
    hb = HIT(arg1);
    if (hb == 0) {
        return 0;
    }
    if (F8(arg0, 0x15) == 0x40) {
        xa = F16(arg0, 0xA) - (s8)HIT(arg0)[0];
    } else {
        xa = F16(arg0, 0xA) + (s8)HIT(arg0)[0];
    }
    if (F8(arg1, 0x15) == 0x40) {
        xb = F16(arg1, 0xA) - (s8)hb[0];
    } else {
        xb = F16(arg1, 0xA) + (s8)hb[0];
    }
    d = (xa - xb >= 0) ? xa - xb : xb - xa;
    if (d >= HIT(arg0)[2] + hb[2]) {
        return 0;
    }
    xa = F16(arg0, 0xE) + (s8)HIT(arg0)[1];
    xb = F16(arg1, 0xE) + (s8)hb[1];
    d = (xa - xb >= 0) ? xa - xb : xb - xa;
    return d < HIT(arg0)[3] + hb[3];
}

#include "common.h"

#define HB(o) (*(u8**)((u8*)(o) + 0x68))
#define DIR(o) (*(u8*)((u8*)(o) + 0x15))
#define PX(o) (*(s16*)((u8*)(o) + 0xA))
#define PY(o) (*(s16*)((u8*)(o) + 0xE))

s32 func_8002DE54(void* arg0, void* arg1) {
    u8* a;
    u8* b;
    s16 x0;
    s16 x1;
    s16 d;

    a = HB(arg0);
    if (a == 0) {
        return 0;
    }
    b = HB(arg1);
    if (b == 0) {
        return 0;
    }
    if (DIR(arg0) == 0x40) {
        x0 = PX(arg0) - (s8)a[0];
    } else {
        x0 = PX(arg0) + (s8)a[0];
    }
    if (DIR(arg1) == 0x40) {
        x1 = PX(arg1) - (s8)b[0];
    } else {
        x1 = PX(arg1) + (s8)b[0];
    }
    d = (x0 - x1 >= 0) ? x0 - x1 : x1 - x0;
    if (d >= HB(arg0)[2]) {
        return 0;
    }
    x0 = PY(arg0) + (s8)HB(arg0)[1];
    x1 = PY(arg1) + (s8)b[1];
    d = (x0 - x1 >= 0) ? x0 - x1 : x1 - x0;
    return d < HB(arg0)[3];
}

#include "common.h"

#define F15(o) (*(u8*)((u8*)(o) + 0x15))
#define FA(o) (*(s16*)((u8*)(o) + 0xA))
#define F68(o) (*(u8**)((u8*)(o) + 0x68))
#define F66(o) (*(s8*)((u8*)(o) + 0x66))
#define F6C(o) (*(s16*)((u8*)(o) + 0x6C))

void func_8002DFA0(void* arg0, void* arg1) {
    s16 var_a3;
    s16 var_a2;
    s8 temp_a0;

    if (F15(arg0) == 0x40) {
        var_a3 = FA(arg0) - (s8)*F68(arg0);
    } else {
        var_a3 = FA(arg0) + (s8)*F68(arg0);
    }
    if (F15(arg1) == 0x40) {
        var_a2 = FA(arg1) - (s8)*F68(arg1);
    } else {
        var_a2 = FA(arg1) + (s8)*F68(arg1);
    }
    temp_a0 = F66(arg0);
    if (temp_a0 == 2) {
        var_a3 = var_a3 - F68(arg0)[2];
        var_a2 = F68(arg1)[2] + var_a2;
    } else if ((temp_a0 != 3) && (var_a2 < var_a3)) {
        var_a3 = var_a3 - F68(arg0)[2];
        var_a2 = F68(arg1)[2] + var_a2;
    } else {
        var_a3 = F68(arg0)[2] + var_a3;
        var_a2 = var_a2 - F68(arg1)[2];
    }
    F6C(arg1) = var_a3 - var_a2;
}

#undef F15
#undef FA
#undef F68
#undef F66
#undef F6C

#include "common.h"

#define FE(o) (*(s16*)((u8*)(o) + 0xE))
#define F68(o) (*(u8**)((u8*)(o) + 0x68))
#define F66(o) (*(s8*)((u8*)(o) + 0x66))
#define F6E(o) (*(s16*)((u8*)(o) + 0x6E))

void func_8002E0DC(void* arg0, void* arg1) {
    u8* t0;
    u8* t1;
    s16 var_a3;
    s16 var_a2;
    s8 temp_a0;

    t0 = F68(arg0);
    t1 = F68(arg1);
    var_a3 = FE(arg0) + (s8)t0[1];
    var_a2 = FE(arg1) + (s8)t1[1];
    temp_a0 = F66(arg0);
    if (temp_a0 == -2) {
        var_a3 = var_a3 - t0[3];
        var_a2 = t1[3] + var_a2;
    } else if ((temp_a0 != -3) && (var_a2 < var_a3)) {
        var_a3 = var_a3 - t0[3];
        var_a2 = t1[3] + var_a2;
    } else {
        var_a3 = t0[3] + var_a3;
        var_a2 = var_a2 - t1[3];
    }
    F6E(arg1) = var_a3 - var_a2;
}

#undef FE
#undef F68
#undef F66
#undef F6E
