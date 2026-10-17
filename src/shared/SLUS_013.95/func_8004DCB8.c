#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

s32 func_80016C48(s32 a0, s32 a1, void* arg2);
M2C_UNK func_8004E78C(M2C_UNK);
extern struct X4_PlayerObj D_800970A0;
extern struct X4_EngineObj D_800CCED0;

void func_8004DCB8(u8* arg0) {
    u8* p = arg0 + 0x80;
    u8* q;
    u8 t;

    if (((s8*)arg0)[6] == 0) {
        p[4] = t = arg0[0x84] - 1;
        q = p;
        if (t == 0) {
            u8* pl;
            register u8* e asm("$3");
            register s8* tbl asm("$8");
            s8 sign;
            register s32 x asm("$4");

            pl = (u8*)&D_800970A0;
            e = (u8*)&D_800CCED0;
            tbl = (s8*)(e + 0x5B);
            arg0[0x84] = 2;
            sign = pl[0x5C] & 0x80;
            x = (s8)pl[2];
            if ((pl[0x5C] & 0x7F) >= tbl[x]) {
                arg0[6] = 1;
                pl[0x5C] = sign | tbl[(s8)pl[2]];
            } else {
                pl[0x5C] = sign | (pl[0x5C] + 1);
            }
            func_80016C48(0, 0xD, 0);
            p = 0;
            if ((u8)(q[3] = arg0[0x83] - 1) == 0) {
                arg0[6] = 1;
                arg0[3] = 0;
            }
        }
    } else {
        func_8004E78C(0);
        arg0[4] = 3;
        arg0[5] = 0;
        arg0[0] &= 0xF7;
    }
}
