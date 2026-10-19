#include "common.h"
#define M2C_UNK s32

#define B(p, o) (*(u8*)((u8*)(p) + (o)))
#define SB(p, o) (*(s8*)((u8*)(p) + (o)))

void func_801EAA24(u8* arg0, s8 arg1);

void func_801ED198(u8* arg0) {
    u8 t;
    if (SB(arg0, 7) >= 0xB) {
        B(arg0, 0xE1) = 0;
        B(arg0, 6)++;
        return;
    }
    B(arg0, 0xE1)++;
    t = B(arg0, 0xE1);
    if (t % 10 == 1) {
        func_801EAA24(arg0, t / 10);
    }
}
