#include "common.h"

extern u16 D_80078470[][4];

#define F8(o) (*(s8*)((u8*)self + (o)))
#define F16(o) (*(s16*)((u8*)self + (o)))

void func_8004D204(u8* self) {
    s32 t;
    u16 w;
    u16 h;

    F8(0x37) = -1;
    F8(0) = -0x6D;
    F8(0x36) = 0x22;
    F16(0x34) = 0x11;
    t = F8(2);
    F16(0xA) = D_80078470[t][0];
    F16(0xE) = D_80078470[t][1];
    w = D_80078470[t][2];
    F16(0x38) = w;
    h = D_80078470[t][3];
    F16(0x1E) = w;
    F16(0x26) = w;
    F16(0x16) = -w;
    F16(0x2E) = -w;
    F8(4)++;
    F16(0x3A) = h;
    F16(0x1A) = -h;
    F16(0x22) = -h;
    F16(0x2A) = h;
    F16(0x32) = h;
}

#undef F8
#undef F16
