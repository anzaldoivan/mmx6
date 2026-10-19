#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern s16 D_80090D5C;
extern struct X4_BackgroundObj D_800971F8[3];
extern s16 D_80097430;
extern s8 D_800CCF08;
extern s16 D_800CF854;

void func_800FA57C(u8* arg0) {
    u8* q;

    D_800CF854++;
    D_80097430 += 0x20;
    D_80090D5C += 0x400;
    if ((u16)D_800CF854 == 0x1F) {
        q = (u8*)D_800971F8;
        *(s16*)(q + 0xB2) = 1;
        *(s16*)(q + 0xB6) = 0x200;
        q[0xF4] = 1;
        if (D_800CCF08 != 0) {
            *(s16*)(q + 0xB6) = 0x400;
        }
        q[0x57] = 1;
        *(s16*)(q + 0x5E) = 0x120;
        *(s16*)(q + 0x62) = 0;
        q[0xA0] = 1;
        arg0[1]++;
    }
}
