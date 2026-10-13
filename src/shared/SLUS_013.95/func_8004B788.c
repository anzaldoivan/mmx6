#include "common.h"

#define FU8(p, o) (*(u8*)((u8*)(p) + (o)))
#define FU16(p, o) (*(u16*)((u8*)(p) + (o)))
#define F16(p, o) (*(s16*)((u8*)(p) + (o)))

void func_8004B788(void* arg0) {
    s16 a;
    s16 b;
    u16 step;
    s32 t;

    t = FU16(arg0, 0x42) + (step = FU16(arg0, 0x40));
    FU16(arg0, 0x42) = t;
    if ((s16)t >= 0x100) {
        FU16(arg0, 0x26) = FU16(arg0, 0x3C);
        FU16(arg0, 0x2A) = FU16(arg0, 0x3E);
        FU8(arg0, 5) = FU8(arg0, 5) + 1;
        return;
    }
    a = F16(arg0, 0x2E);
    b = F16(arg0, 0x32);
    FU16(arg0, 0x40) = step + 1;
    FU16(arg0, 0x26) = a + (((F16(arg0, 0x3C) - a) * (s16)t) >> 8);
    FU16(arg0, 0x2A) = b + (((F16(arg0, 0x3E) - b) * (s16)t) >> 8);
}
