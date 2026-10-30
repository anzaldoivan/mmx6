#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

struct X4_VisualObj* func_8002C398(void);
s32 random_byte();

extern s32 D_80077D58[];
extern s32 D_80077D78[];

#define U8(o) M2C_FIELD(v, u8*, o)
#define S16(o) M2C_FIELD(v, s16*, o)
#define S32(o) M2C_FIELD(v, s32*, o)

void func_8004A998(u8 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5) {
    struct X4_VisualObj* v;
    s16 i;
    u32 kind;
    s32 t;
    s32 u;
    s32 rx;
    s32 ry;
    s16 d;

    i = 0;
    kind = arg0;
    for (; i < arg5; i++) {
        v = func_8002C398();
        if (v != 0) {
            U8(0x0) = 0x21;
            U8(0x1) = 9;
            U8(0x2) = 0;
            t = random_byte();
            u = random_byte();
            t <<= 8;
            t += u;
            t += 1;
            rx = t & 0xFFFF;
            do {
                t = random_byte();
            } while (0);
            u = random_byte();
            t <<= 8;
            t += u;
            t += 1;
            t &= 0xFFFF;
            {
                // !FAKE: depin: dropping it breaks the match (140/185)
                register s32 a asm("$4") = arg3;
                // !FAKE: depin: dropping it breaks the match (179/185)
                register s32 e asm("$3") = (s16)(a - arg1);
                if (e == 0) {
                    S16(0xA) = arg1;
                } else {
                    S16(0xA) = arg1 + rx % e;
                }
            }
            d = arg4 - arg2;
            if (d == 0) {
                S16(0xE) = arg2;
            } else {
                S16(0xE) = arg2 + t % d;
            }
            S16(0x8) = 0;
            S16(0xC) = 0;
            switch ((s32)(kind & 0xF)) {
            case 1:
                S32(0x20) = D_80077D78[random_byte() & 7] * 4;
                S32(0x24) = D_80077D58[random_byte() & 3] * 4;
                break;
            case 2:
                S32(0x20) = -(D_80077D78[random_byte() & 7] * 4);
                S32(0x24) = D_80077D58[random_byte() & 3] * 4;
                break;
            case 4:
                S32(0x20) = -(D_80077D78[random_byte() & 7] * 4);
                S32(0x24) = -(D_80077D58[random_byte() & 3] * 4);
                break;
            case 8:
                S32(0x20) = D_80077D78[random_byte() & 7] * 4;
                S32(0x24) = -(D_80077D58[random_byte() & 3] * 4);
                break;
            default:
                S32(0x20) = 0;
                S32(0x24) = 0;
                break;
            }
            U8(0x15) = 0;
            U8(0x5C) = kind >> 4;
            U8(0x4) = 0;
            U8(0x5) = 0;
            U8(0x6) = 0;
        }
    }
}
