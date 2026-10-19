#include "common.h"

s32 func_80016C48(s32 a0, s32 a1, void* arg2);

void func_800427E0(s8* arg0) {
    if (--*(s16*)(arg0 + 0x7C) == 0) {
        func_80016C48(2, 0x40, arg0);
        *(u16*)(arg0 + 0x7C) = 0x5A;
        arg0[6]++;
    }
}
