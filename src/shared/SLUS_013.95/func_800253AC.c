#include "common.h"
#include "mmx6/x4.h"

u32 func_80025248(u16);
extern u16 D_80071E48[][4];
extern struct X4_DrawInfo* D_8009B7A0;

#define PRIM_NEXT (*(u8**)SP(0x110))
#define PB(p, o) (*(u8*)((p) + (o)))
#define PH(p, o) (*(s16*)((p) + (o)))
#define PW(p, o) (*(u32*)((p) + (o)))

#define RGB15(o, k)                                                            \
    {                                                                          \
        u32 c, r, g, b, rr, gg, bb;                                            \
        c = func_80025248(D_80071E48[arg4][k]);                                \
        b = c >> 10;                                                           \
        do {                                                                   \
            r = c & 0x1F;                                                      \
            rr = r * 8 + (r >> 2);                                             \
            g = (c >> 5) & 0x1F;                                               \
            gg = g * 8 + (g >> 2);                                             \
        } while (0);                                                           \
        b &= 0xFF;                                                             \
        bb = b * 8 + (b >> 2);                                                 \
        PB(p, (o)) = rr;                                                       \
        PB(p, (o) + 1) = gg;                                                   \
        PB(p, (o) + 2) = bb;                                                   \
    }

#define BLEND(o, o2)                                                           \
    {                                                                          \
        u8 a, e;                                                               \
        u32 v;                                                                 \
        a = PB(p, (o));                                                        \
        e = PB(p, (o2));                                                       \
        if (a == e || arg5 == arg6) {                                          \
            v = a;                                                             \
        } else if (arg6 == 0) {                                                \
            v = e;                                                             \
        } else if (e < a) {                                                    \
            v = e + (a - e) * arg6 / arg5;                                     \
        } else {                                                               \
            v = a + (e - a) * (arg5 - arg6) / arg5;                            \
        }                                                                      \
        PB(p, (o)) = v;                                                        \
    }

void func_800253AC(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4, u32 arg5,
                   u32 arg6) {
    u8* p;
    u32* ot;

    p = PRIM_NEXT;
    PB(p, 3) = 8;
    PB(p, 7) = 0x38;
    PH(p, 8) = PH(p, 0x18) = arg0;
    PH(p, 0x10) = PH(p, 0x20) = arg1;
    PH(p, 0xA) = PH(p, 0x12) = arg2;
    PH(p, 0x1A) = PH(p, 0x22) = arg3;
    RGB15(4, 0);
    RGB15(0xC, 1);
    RGB15(0x14, 2);
    RGB15(0x1C, 3);
    BLEND(4, 0x14);
    BLEND(5, 0x15);
    BLEND(6, 0x16);
    BLEND(0xC, 0x1C);
    BLEND(0xD, 0x1D);
    BLEND(0xE, 0x1E);
    ot = &D_8009B7A0->ordering_table.unk5[0];
    PW(p, 0) = (PW(p, 0) & 0xFF000000) | (*ot & 0xFFFFFF);
    *ot = (*ot & 0xFF000000) | ((u32)p & 0xFFFFFF);
    PRIM_NEXT += 0x24;
}
