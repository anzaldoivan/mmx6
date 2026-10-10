#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04();
s32 func_8002D2D4();
extern s8 D_800970A2;

#define B(p, o) (*(s8*)((u8*)(p) + (o)))
#define UH(p, o) (*(u16*)((u8*)(p) + (o)))

void func_800EA554(void* arg0) {
    u16 t;

    ((void (*)())func_80017A04)(arg0);
    t = UH(arg0, 0x7C);
    UH(arg0, 0x7C) = t + 1;
    if ((s16)t >= 0x3D) {
        if (func_8002D2D4() & 1) {
            if (D_800970A2 == 0) {
                ((void (*)(void*, s32))func_800179A4)(arg0, 3);
                B(arg0, 6) = 1;
            } else {
                ((void (*)(void*, s32))func_800179A4)(arg0, 2);
                B(arg0, 6) = 2;
            }
        } else {
            ((void (*)(void*, s32))func_800179A4)(arg0, 4);
            B(arg0, 6) = 0;
        }
        B(arg0, 5) = 2;
    }
}

#undef B
#undef UH
