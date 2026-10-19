#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8003CCBC();
extern s16 D_80090D5C;
extern s16 D_80097430;
extern u8 D_800C4560;
extern s8 D_800CCEEC;
extern s16 D_800CF854;

void func_801EABB4(u8* arg0) {
    u16* q0 = (u16*)&D_800CF854;
    u16 t = q0[1];
    u16* q3;
    if (t != 0) {
        u16* q1;
        u16* q2;
        q0[1] = t - 8;
        q1 = (u16*)&D_80097430;
        q2 = (u16*)&D_80090D5C;
        q1[1] -= 0x100;
        q2[1] -= 0x2000;
        if ((u16)(t - 8) < 8) {
            q2[1] = 0;
            q1[1] = 0;
            q0[1] = 0;
            arg0[0xE4] &= 0xFE;
            D_800C4560 |= 1;
        }
    }
    if (((s8*)arg0)[0x46] != 0) {
        return;
    }
    q3 = (u16*)&D_800CF854;
    if (q3[1] == 0) {
        arg0[0x93] = 0;
        arg0[0x8E] = 0;
        arg0[0xE0] = 0;
        if (((s8*)arg0)[0xD3] == 0) {
            D_800CCEEC = 0;
            arg0[0x7A] = 0;
        }
        func_8003CCBC(arg0);
        arg0[6]++;
    }
}
