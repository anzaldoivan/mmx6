#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

struct X4_VisualObj* find_free_visual_obj(void);
s32 random_byte();

#define U8(o) M2C_FIELD(v, u8*, o)
#define S16(o) M2C_FIELD(v, s16*, o)
#define S32(o) M2C_FIELD(v, s32*, o)

void func_8004A768(u8 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5) {
    struct X4_VisualObj* v;
    s16 i;
    u32 kind;
    s32 t;
    s32 u;
    s32 rx;
    s32 mid;
    s16 e;

    i = 0;
    kind = arg0;
    mid = (s16)(arg1 + (arg3 - arg1) / 2);
    for (; i < arg5; i++) {
        v = find_free_visual_obj();
        if (v != 0) {
            U8(0x0) = 0x21;
            U8(0x1) = 9;
            U8(0x2) = 0;
            t = random_byte();
            u = random_byte();
            t <<= 8;
            t += u;
            t += 1;
            do {
                rx = t & 0xFFFF;
            } while (0);
            t = random_byte();
            u = random_byte();
            e = arg3 - arg1;
            t <<= 8;
            t += u;
            t += 1;
            t &= 0xFFFF;
            if (e == 0) {
                S16(0xA) = arg1;
            } else {
                S16(0xA) = arg1 + rx % e;
            }
            e = arg4 - arg2;
            if (e == 0) {
                S16(0xE) = arg2;
            } else {
                S16(0xE) = arg2 + t % e;
            }
            S16(0x8) = 0;
            S16(0xC) = 0;
            switch ((s32)(kind & 3)) {
            case 1:
                S32(0x20) = 0;
                S32(0x24) = 0x10000;
                break;
            case 2:
                if (S16(0xA) < mid) {
                    S32(0x20) = -0x18000;
                    S32(0x24) = 0;
                } else {
                    S32(0x20) = 0x18000;
                    S32(0x24) = 0;
                }
                break;
            case 3:
                S32(0x20) = 0;
                S32(0x24) = 0x4000;
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
