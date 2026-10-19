#include "common.h"

#define SCRATCH_1C (*(s32*)0x1F80001C)
#define F8(p, o) (*(s8*)((u8*)(p) + (o)))
#define F16(p, o) (*(s16*)((u8*)(p) + (o)))
#define F32(p, o) (*(s32*)((u8*)(p) + (o)))

void func_800485BC(u8* arg0) {
    s32 u;

    if (F8(arg0, 4) == 0) {
        s32 t;

        F8(arg0, 3) = 1;
        F8(arg0, 0x14) = -1;
        F32(arg0, 0x38) = 0;
        u = F8(arg0, 2);
        t = SCRATCH_1C;
        F32(arg0, 0x30) = 0;
        F16(arg0, 0x40) = 0x1880;
        F32(arg0, 0x3C) = t;
        F16(arg0, 0x42) = (u == 0) ? 0x7804 : 0x7807;
        F8(arg0, 0x15) = 0;
        F8(arg0, 0x16) = 0;
        arg0[4]++;
    }
}
