#include "common.h"

#define O6 (*(u8*)(arg0 + 6))
#define O7C (*(u16*)(arg0 + 0x7C))

s32 func_800179A4(void*, s32);
void func_80017A04();
void func_800F6FC8();

void func_800F4400(u8* arg0) {
    s32 t;

    func_80017A04();
    func_800F6FC8(arg0);
    t = O7C;
    O7C = t + 1;
    if ((s16)t >= 0x3C) {
        func_800179A4(arg0, 9);
        t = O6;
        O6 = t + 1;
    }
}
#undef O6
#undef O7C
