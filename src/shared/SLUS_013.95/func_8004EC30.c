#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

s32 func_80016C48(s32 a0, s32 a1, void* arg2);
M2C_UNK func_80017A04();
#define func_80017A04 ((M2C_UNK(*)())func_80017A04)
void func_8004FE58(s32, s8);
extern struct X4_PlayerObj D_800970A0;
extern struct X4_EngineObj D_800CCED0;

void func_8004EC30(u8* arg0) {
    u8* p;
    u8* q;
    u8 t;
    // !FAKE: depin: dropping it breaks the match (66/71)
    register s32 f asm("$2");

    func_80017A04();
    p = arg0 + 0x7C;
    f = ((s8*)arg0)[6];
    if (f == 0) {
        p[4] = t = arg0[0x80] - 1;
        q = p;
        if (t == 0) {
            u8* pl;
            // !FAKE: depin: dropping it breaks the match (68/71)
            register u8* e asm("$3");
            s8* tbl;
            s8 sign;
            // !FAKE: depin: dropping it breaks the match (67/71)
            register s32 x asm("$4");

            pl = (u8*)&D_800970A0;
            e = (u8*)&D_800CCED0;
            tbl = (s8*)(e + 0x5B);
            arg0[0x80] = 4;
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
            if ((u8)(q[3] = arg0[0x7F] - 1) == 0) {
                arg0[6] = 1;
            }
        }
    } else {
        ((void (*)())func_8004FE58)(0);
        arg0[4] = 3;
        arg0[5] = 0;
        arg0[0] &= 0xF7;
    }
}
#undef func_80017A04
