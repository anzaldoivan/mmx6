#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define B(p, o) M2C_FIELD(p, u8*, o)
#define SB(p, o) M2C_FIELD(p, s8*, o)

s32 func_8002D2D4();
extern s8 D_800CCF5C;
extern u8 D_800F87B0[];
extern u8 D_800F87F8[];

M2C_UNK func_800EA860(void* arg0) {
    u8 v;
    s8 n;
    u8 c;
    register u8* t asm("$4");
    u8* p;

    B(arg0, 0x6) = 0;
    if (SB(arg0, 0x8C) == 0 && (s8)D_800CCF5C / 2 >= SB(arg0, 0x5C)) {
        n = func_8002D2D4() & 7;
        B(arg0, 0x8D) = n;
        B(arg0, 0x8E) = 0;
        B(arg0, 0x8C) = 1;
        B(arg0, 0x5) = D_800F87F8[n * 8];
        B(arg0, 0x8E)++;
        return;
    }
    switch (SB(arg0, 0x8C)) {
    case 0:
        t = D_800F87B0;
        p = t + (SB(arg0, 0x8E) + SB(arg0, 0x8D) * 8);
        v = *p;
        if (v == 0xFF) {
            c = B(arg0, 0x92);
            B(arg0, 0x92) = c + 1;
            if ((s8)c >= 3) {
                B(arg0, 0x92) = 0;
                B(arg0, 0x8D) = 8;
            } else {
                B(arg0, 0x8D) = func_8002D2D4() & 7;
            }
            t = D_800F87B0;
            B(arg0, 0x8E) = 0;
            v = t[SB(arg0, 0x8D) * 8];
        }
        break;
    case 1:
        t = D_800F87F8;
        p = t + (SB(arg0, 0x8E) + SB(arg0, 0x8D) * 8);
        v = *p;
        if (v == 0xFF) {
            c = B(arg0, 0x92);
            B(arg0, 0x92) = c + 1;
            if ((s8)c >= 3) {
                B(arg0, 0x92) = 0;
                B(arg0, 0x8D) = 8;
            } else {
                B(arg0, 0x8D) = func_8002D2D4() & 7;
            }
            t = D_800F87F8;
            B(arg0, 0x8E) = 0;
            v = t[SB(arg0, 0x8D) * 8];
        }
        break;
    default:
        return;
    }
    do {
        B(arg0, 0x5) = v;
    } while (0);
    B(arg0, 0x8E)++;
}
