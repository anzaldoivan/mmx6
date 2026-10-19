#include "common.h"

extern s8 D_800FD51A;

void func_800F4D68(s8* arg0) {
    s8* p = arg0;
    s32 t = p[6];
    u8 u = ((u8*)p)[6];
    if (t == 0) {
        p[3] = D_800FD51A;
        ((u8*)p)[6] = u + 1;
        return;
    }
    p[3] = D_800FD51A;
    ((u8*)p)[4]++;
}
