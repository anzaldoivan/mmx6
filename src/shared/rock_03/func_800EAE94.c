#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD (*(u8**)0x1F80004C)

M2C_UNK func_8002D2B0(s32);
s32 func_80065944(s32);
s32 func_80065A14(s32);
s32 func_80065B74(s32, s32);
extern struct X4_PlayerObj D_800970A0;

#define NEAR3(d, a, b) ((d) = (a) - (b), (d) >= 0 ? (d) < 3 : ((b) - (a)) < 3)

void func_800EAE94(void* arg0) {
    s32 dx;
    register s32 dy asm("$3");
    s32 y;
    s32 angle;
    s32 t;
    s32 d;

    dx = D_800970A0.x_pos.i.hi - M2C_FIELD(arg0, s16*, 0xA);
    if (D_800970A0.unk2 == 0) {
        y = M2C_FIELD(arg0, s16*, 0xE) + 0x30;
        dy = D_800970A0.y_pos.i.hi - y;
    } else {
        y = M2C_FIELD(arg0, s16*, 0xE) + 0x40;
        dy = D_800970A0.y_pos.i.hi - y;
    }
    angle = func_80065B74(-dy, dx);
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    {
        register s32 m asm("$2");
        s32 lo;
        m = func_80065A14(angle);
        lo = m << 4;
        m = (m << 6) + lo;
        M2C_FIELD(arg0, s32*, 0x20) = (m << 1) / 4;
        m = func_80065944(angle);
        lo = m << 4;
        m = (m << 6) + lo;
        M2C_FIELD(arg0, s32*, 0x24) = (m << 1) / 8;
    }
    func_8002D2B0((s32)arg0);
    if (D_800970A0.unk2 == 0) {
        if (!NEAR3(d, D_800970A0.x_pos.i.hi, M2C_FIELD(arg0, s16*, 0xA))) {
            return;
        }
        t = M2C_FIELD(arg0, s16*, 0xE) + 0x30;
        if (!NEAR3(d, D_800970A0.y_pos.i.hi, t)) {
            return;
        }
        M2C_FIELD(arg0, s16*, 0xA) = D_800970A0.x_pos.i.hi;
        M2C_FIELD(arg0, s16*, 0xE) = D_800970A0.y_pos.i.hi - 0x30;
    } else {
        if (!NEAR3(d, D_800970A0.x_pos.i.hi, M2C_FIELD(arg0, s16*, 0xA))) {
            return;
        }
        t = M2C_FIELD(arg0, s16*, 0xE) + 0x40;
        if (!NEAR3(d, D_800970A0.y_pos.i.hi, t)) {
            return;
        }
        M2C_FIELD(arg0, s16*, 0xA) = D_800970A0.x_pos.i.hi;
        M2C_FIELD(arg0, s16*, 0xE) = D_800970A0.y_pos.i.hi - 0x40;
    }
    if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
        *(s32*)(SPAD + 0x84) = -0x20;
    } else {
        *(s32*)(SPAD + 0x84) = 0x20;
    }
    M2C_FIELD(arg0, u8*, 0x5) = 4;
    M2C_FIELD(arg0, u8*, 0x6) = 0;
}
