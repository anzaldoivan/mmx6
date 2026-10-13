#include "common.h"
#include "mmx6/x4.h"
s32 func_80018BE0(s32, u8*);
extern struct X4_RectPtrPair* D_80097790;
extern u8 D_800C8868[];
extern u8 D_800C9868[];

void func_80017B04(u8* arg0, s16 arg1, s16 arg2) {
    struct X4_RectPtrPair* p;
    u8* buf;
    s16 n;
    s16 h;
    u32 w;
    s32 base;
    s8 bank;

    base = arg0[0x47];
    if (arg0[0x48] != base) {
        arg0[0x48] = base;
        {
            s32 off = (u8)base;
            base = *(s32*)(arg0 + 0x38);
            bank = arg0[0x49];
            w = *(u32*)(base + off * 4);
        }
        n = w >> 20;
        if (bank == 3) {
            buf = D_800C8868;
        } else {
            buf = D_800C9868 + (bank << 12);
        }
        func_80018BE0(base + (w & 0xFFFFF), buf);
        p = D_80097790;
        do {
            p->rect.x = arg1;
            p->rect.y = arg2;
            p->ptr = (X4_u_long*)buf;
            if (n < 16) {
                p->rect.w = n * 4;
                n = 0;
                p->rect.h = 16;
            } else {
                p->rect.w = 64;
                h = n / 16;
                h *= 16;
                p->rect.h = h;
                arg2 += h;
                n -= h;
                buf += 0x800;
            }
            p++;
        } while (n != 0);
        p->ptr = 0;
        D_80097790 = p;
    }
}
