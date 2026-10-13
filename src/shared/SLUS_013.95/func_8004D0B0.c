#include "common.h"
#define M2C_UNK s32

s32 func_8002D0D8(s32, s32);

void func_8004D0B0(u8* arg0, u8 arg1, u8 arg2, u16* arg3) {
    s32* p;
    s32 i;
    s32 n;
    s32 dx;
    s32 dy;
    s32 r;
    u8* a;
    u8* b;

    p = (s32*)(arg0 + 0x14);
    i = arg2;
    if (i != 0) {
        n = i;
        do {
            n--;
            p += 2;
        } while (n != 0);
    }
    dx = p[0] - (((s16*)arg3)[0] << 16);
    dy = p[1] - (((s16*)arg3)[1] << 16);
    r = func_8002D0D8(dx, dy);
    a = arg0 + 0x48;
    b = arg0 + 0x4C;
    if ((((r ^ a[i]) & 0x10) || b[i] != 0) && arg0[0x54] == 0) {
        *(s16*)(arg0 + 8) = 0;
        *(s16*)(arg0 + 0xC) = 0;
        b[i] = 1;
    } else {
        p[0] -= dx / *(u16*)(arg0 + 0x50);
        p[1] -= dy / *(u16*)(arg0 + 0x50);
        {
            u8* q = arg0 + 0x4C;
            q[i] = 0;
        }
        if (i == 3) {
            arg0[0x54] = 0;
        }
    }
    {
        u8* e = arg0 + 0x48;
        e[i] = r;
    }
}
