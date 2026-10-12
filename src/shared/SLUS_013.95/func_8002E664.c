#include "common.h"

#define HB_U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define HB_S16(p, o) (*(s16*)((u8*)(p) + (o)))
#define HB_BOX(p) (*(s8**)((u8*)(p) + 0x68))
#define HB_X(p) (HB_BOX(p)[0])
#define HB_Y(p) (HB_BOX(p)[1])
#define HB_W(p) (((u8*)HB_BOX(p))[2])
#define HB_H(p) (((u8*)HB_BOX(p))[3])

s32 func_8002E664(void* arg0, void* arg1) {
    u8 res;
    s16 x0;
    s16 y0;
    s16 x1;
    s16 y1;
    s32 d;
    s16 sum;

    res = 0;
    if (HB_U8(arg0, 0x15) == 0x40) {
        x0 = HB_S16(arg0, 0xA) - HB_X(arg0);
    } else {
        x0 = HB_S16(arg0, 0xA) + HB_X(arg0);
    }
    y0 = HB_S16(arg0, 0xE) + HB_Y(arg0);
    if (HB_U8(arg1, 0x15) == 0x40) {
        x1 = HB_S16(arg1, 0xA) - HB_X(arg1);
    } else {
        x1 = HB_S16(arg1, 0xA) + HB_X(arg1);
    }
    y1 = HB_S16(arg1, 0xE) + HB_Y(arg1);
    d = (s16)((y0 - y1 < 0) ? y1 - y0 : y0 - y1);
    sum = HB_H(arg0) + HB_H(arg1);
    if (d == sum) {
        d = (s16)((x0 - x1 < 0) ? x1 - x0 : x0 - x1);
        sum = HB_W(arg0) + HB_W(arg1);
        if (d < sum) {
            res = 8;
            if (y0 < y1) {
                res = 4;
            }
        }
    }
    d = (s16)((x0 - x1 < 0) ? x1 - x0 : x0 - x1);
    sum = HB_W(arg0) + HB_W(arg1);
    if (d == sum) {
        d = (s16)((y0 - y1 < 0) ? y1 - y0 : y0 - y1);
        sum = HB_H(arg0) + HB_H(arg1);
        if (d < sum) {
            if (x0 < x1) {
                res |= 2;
            } else {
                res |= 1;
            }
        }
    }
    HB_U8(arg1, 0x70) = res | HB_U8(arg1, 0x70);
    return res;
}

#undef HB_U8
#undef HB_S16
#undef HB_BOX
#undef HB_X
#undef HB_Y
#undef HB_W
#undef HB_H
