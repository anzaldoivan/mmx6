#include "common.h"

s32 func_800F09A0();

#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define H(p, o) (*(s16*)((u8*)(p) + (o)))
#define UH(p, o) (*(u16*)((u8*)(p) + (o)))

void func_800F0570(void* arg0) {
    if (!(UH(arg0, 0x7C) & 0x1F) && func_800F09A0() != 0) {
        UB(arg0, 5) = 4;
        UB(arg0, 6) = 0;
        return;
    }
    if (--H(arg0, 0x7C) == 0) {
        UB(arg0, 6)++;
    }
}
