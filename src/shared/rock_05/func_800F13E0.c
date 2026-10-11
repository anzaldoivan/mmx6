#include "common.h"

#define SCRATCH_4C (*(u8**)0x1F80004C)

void* func_8002C3F8();

void func_800F13E0(u8* arg0) {
    u8* o;

    if (--*(s16*)(arg0 + 0x7C) == 0) {
        arg0[5] = 2;
        o = func_8002C3F8();
        if (o != 0) {
            o[0] = 1;
            o[1] = 0x1A;
            *(u16*)(o + 0xA) = *(u16*)(arg0 + 0xA);
            *(u16*)(o + 0xE) = *(u16*)(arg0 + 0xE);
            *(u8**)(SCRATCH_4C + 0x80) = o;
        }
    }
    if ((s16)-- * (u16*)(arg0 + 0x7E) == -1) {
        *(u16*)(arg0 + 0x42) ^= 0x8000;
        arg0[0x61] -= 5;
        if ((s8)arg0[0x61] >= 0x1A) {
            arg0[0x61] = 0;
        }
        *(u16*)(arg0 + 0x7E) =
            (*(s8*)(arg0 + 0x61) < 6) ? 5 : *(s8*)(arg0 + 0x61);
    }
    arg0[3] = 1;
}
