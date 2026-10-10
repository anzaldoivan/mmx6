#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD (*(u8**)0x1F80004C)

M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D2B0(s32);
s32 func_80065944(s32);
s32 func_80065A14(s32);
s32 func_80065B74(s32, s32);

#define NEAR3(d, a, b) ((d) = (a) - (b), (d) >= 0 ? (d) < 3 : ((b) - (a)) < 3)

void func_800EB170(void* arg0) {
    s32 angle;
    s32 d;
    s32 e;
    s32 px;

    px = M2C_FIELD(SPAD, s16*, 0x8A);
    {
        register s32 py asm("$3") = M2C_FIELD(SPAD, s16*, 0x8C);
        angle = func_80065B74(M2C_FIELD(arg0, s16*, 0xE) - py,
                              px - M2C_FIELD(arg0, s16*, 0xA));
    }
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    {
        register s32 m asm("$2");
        s32 lo;
        m = func_80065A14(angle);
        lo = m << 4;
        m = (m << 6) + lo;
        M2C_FIELD(arg0, s32*, 0x20) = (m << 1) / 8;
        m = func_80065944(angle);
        lo = m << 4;
        m = (m << 6) + lo;
        M2C_FIELD(arg0, s32*, 0x24) = (m << 1) / 8;
    }
    func_8002D2B0((s32)arg0);
    func_8002CCB0(arg0, 0x30, 0x40);
    {
        register u8* sp asm("$2") = SPAD;
        s32 ax;
        do {
            ax = M2C_FIELD(arg0, s16*, 0xA);
        } while (0);
        if (!NEAR3(d, M2C_FIELD(sp, s16*, 0x8A), ax)) {
            return;
        }
    }
    if (!NEAR3(d, M2C_FIELD(SPAD, s16*, 0x8C), M2C_FIELD(arg0, s16*, 0xE))) {
        return;
    }
    M2C_FIELD(arg0, s16*, 0xA) = M2C_FIELD(SPAD, s16*, 0x8A);
    e = M2C_FIELD(SPAD, u16*, 0x8C);
    M2C_FIELD(arg0, u8*, 0x5) = 2;
    M2C_FIELD(arg0, u8*, 0x6) = 0;
    M2C_FIELD(arg0, s16*, 0xE) = e;
}
