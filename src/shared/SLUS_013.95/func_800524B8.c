#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8002CA14();
extern s8 D_80090D56;
extern s16 D_80090D5C;
extern s8 D_8009742C;
extern s16 D_80097430;
extern u8 D_800C4560;
extern s8 D_800CF850;
extern s16 D_800CF854;

void func_800524B8(u8* arg0) {
    u8* p;
    u8* q;
    u16 v;
    u8 t;

    if ((s8)--arg0[0x18] == -1) {
        q = *(u8**)(arg0 + 0x14) += 4;
        if (*(u16*)q == 0x8000) {
            t = q[3];
            if (t == 1) {
                func_8002CA14(arg0, q);
                D_800C4560 = t;
                return;
            }
            *(u8**)(arg0 + 0x14) = q + ((s8)q[2] << 2);
        }
        p = *(u8**)(arg0 + 0x14);
        v = *(u16*)p;
        arg0[0x18] = p[2];
        D_800CF854 = v & 0x1F;
        D_80097430 = v & 0x3E0;
        D_80090D5C = v & 0x7C00;
        D_800CF850 = (*(u8**)(arg0 + 0x14))[3] & 1;
        D_8009742C = (*(u8**)(arg0 + 0x14))[3] & 2;
        D_80090D56 = (*(u8**)(arg0 + 0x14))[3] & 4;
        D_800C4560 |= 5;
    }
}
