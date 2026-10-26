#include "common.h"
#define M2C_UNK s32

s32 SsIsEos(s32, s32);
void SsSeqPlay(s32, s32, s16);
M2C_UNK SsSepPlay(s8, M2C_UNK, M2C_UNK, M2C_UNK);
void SsSeqStop(s32, u8);
void SsSepStop(s32, s32);
extern s16 D_8006E358[];
extern u8* D_800E155C;
extern u8 D_800E25F8[];

s32 func_80017008(u8 arg0) {
    u8 a, b;
    u32 flag;
    u32 pri;
    s32 row;
    u32 col;
    u8* p;
    s32 slot;
    u8 t;

    b = D_800E155C[1];
    a = D_800E155C[2];
    flag = b >> 7;
    pri = a & 0xF;
    row = b & 0x7F;
    col = a >> 4;
    p = &D_800E25F8[col];
    if (*p != 0xFF) {
        if (SsIsEos(row, *p & 0x1F) != 0) {
            t = *p;
            if (pri < (t >> 5)) {
                return -1;
            }
            if ((t & 0x1F) == 0x1F) {
                SsSeqStop(row, t);
            } else {
                SsSepStop(row, t & 0xF);
            }
        }
    }
    if (arg0 == 2) {
        slot = D_800E155C[3] & 0x1F;
        ((void (*)(s8, s32, s32, s32))SsSepPlay)(row, slot, 1,
                                                     D_8006E358[flag]);
        D_800E25F8[col] = slot | (pri << 5);
    } else {
        SsSeqPlay(row, 1, D_8006E358[flag]);
        D_800E25F8[col] = (pri << 5) | 0x1F;
    }
    return 0;
}
