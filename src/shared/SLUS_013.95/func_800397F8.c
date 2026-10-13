#include "common.h"

#define F_U16(p, off) (*(u16*)((u8*)(p) + (off)))

s32 func_8002FE30(void*);

s32 func_800397F8(void* arg0, s32 arg1) {
    s32 v;
    s16 a;
    s16 r;

    v = arg1 & 0xFF;
    if (v == 0x2F) {
        F_U16(arg0, 0xE) -= 0x10;
        v = func_8002FE30(arg0);
        if (v == 0 || v == 0x38) {
            F_U16(arg0, 0xE) += 0x20;
            v = func_8002FE30(arg0);
        }
    }
    switch (v) {
    case 0x25 ... 0x2C:
        a = F_U16(arg0, 0xA) & 0xF;
        if (v == 0x26) {
            a |= 0x10;
        }
        if (v == 0x2A) {
            a += 0x10;
        }
        if (v == 0x27) {
            a += 0x20;
        }
        if (v == 0x2B) {
            a += 0x20;
        }
        if (v == 0x28) {
            a += 0x30;
        }
        if (v == 0x2C) {
            a += 0x30;
        }
        if ((u32)v >= 0x29) {
            r = a / 4;
        } else {
            r = 0xF - a / 4;
        }
        break;
    case 0x2D:
        r = 0;
        break;
    default:
        break;
    }
    F_U16(arg0, 0xC) = 0;
    F_U16(arg0, 0xE) = r + *(s16*)((u8*)arg0 + 0xE) - F_U16(arg0, 0x6E);
    return v;
}
#undef F_U16
