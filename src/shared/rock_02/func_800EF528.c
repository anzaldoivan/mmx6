#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
s32 func_80065944(s32);
s32 func_80065A14(s32);
s32 func_80065B74(s32, s32);
extern s32 D_800FBC70;
extern s32 D_800FBC74;

void func_800EF528(void* arg0) {
    s32 ang;
    s32 dx;
    s32 dy;
    s32 t;
    s32 dist;
    s32 spd;
    void* p;

    if (D_800FBC70 != 0) {
        goto fail;
    }
    if (D_800FBC74 != 0) {
        goto fail;
    }
    {
        void* q = M2C_FIELD(arg0, void**, 0x7C);
        M2C_FIELD(arg0, s32*, 0x20) += 8;
        ang = (s16)func_80065B74(
            M2C_FIELD(q, s32*, 0x24) - M2C_FIELD(arg0, s16*, 0x2E),
            M2C_FIELD(q, s32*, 0x20) - M2C_FIELD(arg0, s16*, 0x2A));
        p = M2C_FIELD(arg0, void**, 0x7C);
        dx = M2C_FIELD(arg0, s16*, 0x2A) - M2C_FIELD(p, s32*, 0x20);
        t = M2C_FIELD(p, s32*, 0x20) - M2C_FIELD(arg0, s16*, 0x2A);
        if (t >= 0) {
            dx = t;
        }
        {
            s32 u;
            dy = M2C_FIELD(arg0, s16*, 0x2E) - M2C_FIELD(p, s32*, 0x24);
            u = M2C_FIELD(p, s32*, 0x24) - M2C_FIELD(arg0, s16*, 0x2E);
            if (u >= 0) {
                dy = u;
            }
        }
        dist = dx * dx + dy * dy;
        M2C_FIELD(arg0, s32*, 0x8) =
            M2C_FIELD(arg0, s32*, 0x28) +
            ((func_80065A14(ang) * M2C_FIELD(arg0, s32*, 0x20)) << 4);
        M2C_FIELD(arg0, s32*, 0xC) =
            M2C_FIELD(arg0, s32*, 0x2C) +
            ((func_80065944(ang) * M2C_FIELD(arg0, s32*, 0x20)) << 4);
        spd = M2C_FIELD(arg0, s32*, 0x20);
        if ((u32)(spd * spd) < (u32)(dist - 0x40)) {
            goto ok;
        }
    }
fail:
    M2C_FIELD(arg0, u8*, 0x4) = 2;
    return;
ok:
    if (++M2C_FIELD(arg0, s8*, 0x6) == 0x64) {
        M2C_FIELD(arg0, u8*, 0x4) = 2;
    }
    func_8002CCB0(arg0, 0x10, 0x10);
    ((void (*)(void*))func_80017A04)(arg0);
}
