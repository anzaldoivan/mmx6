#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8004E78C(M2C_UNK);
extern struct X4_PlayerObj D_800970A0;
extern struct X4_EngineObj D_800CCED0;

void func_8004E0A8(u8* arg0, u8 arg1, s32 arg2) {
    u8 n;
    u8 hi;
    s32 b;
    s32 x;
    s8 i;
    s8 v;
    u8* p;
    u8* pl;
    u8* e;

    {
        u8* pl0 = (u8*)&D_800970A0;
        u8* e0;
        n = arg2;
        e0 = (u8*)&D_800CCED0;
        hi = pl0[0x5C] & 0x80;
        x = (s8)pl0[2];
        b = (pl0[0x5C] & 0x7F) < ((s8*)(e0 - -x))[0x5B];
    }
    if (b) {
        func_8004E78C(1);
        arg0[0x83] = arg1;
        arg0[0x84] = 2;
        arg0[4] = 2;
        arg0[5] = 0;
        arg0[6] = 0;
        arg0[0] |= 8;
    } else {
        arg0[4] = 3;
    }
    pl = (u8*)&D_800970A0;
    e = (u8*)&D_800CCED0;
    {
        s32 y = (s8)pl[2];
        if ((pl[0x5C] & 0x7F) >= ((s8*)(e - -y))[0x5B]) {
            pl[0x5C] = hi | (e - -y)[0x5B];
        }
    }
    *(u16*)(pl + 0xA8) += arg1 * 6;
    if (*(s16*)(pl + 0x14A) < *(s16*)(pl + 0xA8)) {
        *(u16*)(pl + 0xA8) = *(s16*)(pl + 0x14A);
    }
    for (i = 0; i < 2; i++) {
        p = &e[i + 0x63];
        if (*(volatile u16*)(e + 0x6A) & (0x1000 << i)) {
            v = *p & 0x7F;
            if (v < 0x20) {
                v = v + n * 2;
                if (v >= 0x20) {
                    v = 0x20;
                    func_80016C48(0, 0x18, 0);
                } else {
                    func_80016C48(0, 0x17, 0);
                }
                *p = v | 0x80;
                return;
            }
        }
    }
}
