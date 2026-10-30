#include "common.h"
#include "mmx6/x4.h"

s32 func_80016D34(u8 arg0, u8 arg1, struct X4_AnimatedObj* arg2);
s32 func_80017008(u8 arg0);
extern u8 D_8006E354[];
extern s8 D_80090D50[6];
extern u8* D_80097738[];
extern s32* D_80097778[];
extern u8* D_800E155C;

// 0x80016C48 play_sound: VAB play #1.
// basis: community tweaks-index.tsv:324
// callers: func_8001CD5C, func_8001CE68, func_8001CF78, func_8001D0E4 and others
s32 play_sound(s32 a0, s32 a1, void* arg2) {
    u8 arg0 = a0;
    u8 arg1 = a1;
    s32* base;
    s32* p;
    s32 ret;
    u8 b;
    u8 t;
    u8 s;
    u8 n;

    if (D_80090D50[arg0 & 0x7F] == -1) {
        ret = -1;
    } else {
        n = ((u32)D_80097738[arg0 & 0xF] - (u32)D_80097778[arg0 & 0xF]) >> 2;
        if (n - 1 < arg1) {
            ret = -2;
        } else {
            base = D_80097778[arg0 & 0xF];
            D_800E155C = (u8*)(p = base + arg1);
            ret = -5;
            if (*p != 0) {
                b = *(u8*)p;
                t = D_8006E354[b >> 6];
                s = b & 0x3F;
                if (t != 0) {
                    ret = func_80017008(t);
                } else {
                    ret = func_80016D34(arg0, s, arg2);
                }
            }
        }
    }
    return ret;
}
