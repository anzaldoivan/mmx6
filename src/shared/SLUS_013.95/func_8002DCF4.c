#include "common.h"

#define HIT(p) (*(u8**)((u8*)(p) + 0x68))
#define F8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F16(p, o) (*(s16*)((u8*)(p) + (o)))

s32 func_8002DCF4(void* arg0, void* arg1) {
    u8* hb;
    s16 xa;
    s16 xb;
    s16 d;

    if (HIT(arg0) == 0) {
        return 0;
    }
    hb = HIT(arg1);
    if (hb == 0) {
        return 0;
    }
    if (F8(arg0, 0x15) == 0x40) {
        xa = F16(arg0, 0xA) - (s8)HIT(arg0)[0];
    } else {
        xa = F16(arg0, 0xA) + (s8)HIT(arg0)[0];
    }
    if (F8(arg1, 0x15) == 0x40) {
        xb = F16(arg1, 0xA) - (s8)hb[0];
    } else {
        xb = F16(arg1, 0xA) + (s8)hb[0];
    }
    d = (xa - xb >= 0) ? xa - xb : xb - xa;
    if (d >= HIT(arg0)[2] + hb[2]) {
        return 0;
    }
    xa = F16(arg0, 0xE) + (s8)HIT(arg0)[1];
    xb = F16(arg1, 0xE) + (s8)hb[1];
    d = (xa - xb >= 0) ? xa - xb : xb - xa;
    return d < HIT(arg0)[3] + hb[3];
}
