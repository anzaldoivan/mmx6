#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800179A4(void*, M2C_UNK);

#define B(p, o) (*(u8*)((u8*)(p) + (o)))
#define SB(p, o) (*(s8*)((u8*)(p) + (o)))
#define H(p, o) (*(s16*)((u8*)(p) + (o)))

void func_800F06B8(void* arg0) {
    s32 t;

    if (SB(arg0, 0x45) != 0) {
        B(arg0, 0x15) ^= 0x40;
        func_800179A4(arg0, 1);
        t = 0x14;
        H(arg0, 0x7C) = t;
        {
            // !FAKE: pins the incremented state byte to the first return register
            register s32 u asm("$2") = B(arg0, 6) + 1;
            B(arg0, 6) = u;
        }
    }
}
