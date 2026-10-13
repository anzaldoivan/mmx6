#include "common.h"

#define HB(o) (*(u8**)((u8*)(o) + 0x68))
#define DIR(o) (*(u8*)((u8*)(o) + 0x15))
#define PX(o) (*(s16*)((u8*)(o) + 0xA))
#define PY(o) (*(s16*)((u8*)(o) + 0xE))

s32 func_8002DE54(void* arg0, void* arg1) {
    u8* a;
    u8* b;
    s16 x0;
    s16 x1;
    s16 d;

    a = HB(arg0);
    if (a == 0) {
        return 0;
    }
    b = HB(arg1);
    if (b == 0) {
        return 0;
    }
    if (DIR(arg0) == 0x40) {
        x0 = PX(arg0) - (s8)a[0];
    } else {
        x0 = PX(arg0) + (s8)a[0];
    }
    if (DIR(arg1) == 0x40) {
        x1 = PX(arg1) - (s8)b[0];
    } else {
        x1 = PX(arg1) + (s8)b[0];
    }
    d = (x0 - x1 >= 0) ? x0 - x1 : x1 - x0;
    if (d >= HB(arg0)[2]) {
        return 0;
    }
    x0 = PY(arg0) + (s8)HB(arg0)[1];
    x1 = PY(arg1) + (s8)b[1];
    d = (x0 - x1 >= 0) ? x0 - x1 : x1 - x0;
    return d < HB(arg0)[3];
}
