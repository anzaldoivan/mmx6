#include "common.h"

#ifndef M2C_FIELD
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#endif

extern s16 D_800E4192;
extern s16 D_800E4194;
extern s16 D_800E4196;
extern s16 D_800E4198;
extern s16 D_800E419A;
extern s16 D_800E419C;
extern s16 D_800E419E;
extern s16 D_800E41A0;

void func_800304D8(u8* arg0) {
    u8* p;
    u8 b;
    u16 x;

    p = M2C_FIELD(arg0, u8**, 0x68);
    b = p[0];
    D_800E4196 = (s8)b;
    x = M2C_FIELD(arg0, u16*, 0xA);
    D_800E4198 = (s8)p[1];
    D_800E4192 = p[2];
    {
        s32 c = p[3];
        s32 e = M2C_FIELD(arg0, u16*, 0xE);
        D_800E419A = x;
        D_800E419C = e;
        D_800E4194 = c;
    }
    if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
        D_800E419E = x + D_800E4196;
    } else {
        D_800E419E = x - D_800E4196;
    }
    D_800E41A0 = D_800E419C + D_800E4198;
}
