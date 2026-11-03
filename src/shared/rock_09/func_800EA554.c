#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();
s32 random_byte();

#define B(p, o) (*(s8*)((u8*)(p) + (o)))
#define UH(p, o) (*(u16*)((u8*)(p) + (o)))

void func_800EA554(void* arg0) {
    u16 t;

    ((void (*)())animate_object)(arg0);
    t = UH(arg0, 0x7C);
    UH(arg0, 0x7C) = t + 1;
    if ((s16)t >= 0x3D) {
        if (random_byte() & 1) {
            if (D_800970A2 == 0) {
                ((void (*)(void*, s32))set_animation)(arg0, 3);
                B(arg0, 6) = 1;
            } else {
                ((void (*)(void*, s32))set_animation)(arg0, 2);
                B(arg0, 6) = 2;
            }
        } else {
            ((void (*)(void*, s32))set_animation)(arg0, 4);
            B(arg0, 6) = 0;
        }
        B(arg0, 5) = 2;
    }
}

#undef B
#undef UH
