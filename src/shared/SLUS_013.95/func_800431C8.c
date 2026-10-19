#include "common.h"

#define SCRATCH_OBJ (*(u8**)0x1F800064)

void func_800431C8(u8* arg0) {
    *(u16*)(SCRATCH_OBJ + 0x54) = *(u16*)(arg0 + 0xA);
    if (!(arg0[2] & 0xF)) {
        *(s32*)(arg0 + 0x20) = 0x40000;
        *(u16*)(arg0 + 0xA) -= 0x20;
    } else {
        *(s32*)(arg0 + 0x20) = -0x40000;
        *(u16*)(arg0 + 0xA) += 0x20;
    }
    arg0[6]++;
}
