#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
#define set_animation ((void (*)(void*, s32))set_animation)

#define F8(p, o) (*(s8*)((u8*)(p) + (o)))
#define FU8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F16(p, o) (*(u16*)((u8*)(p) + (o)))
#define F32(p, o) (*(s32*)((u8*)(p) + (o)))

void func_80051FE8(void* arg0, void* arg1) {
    s8 v;
    s32 one = 1;

    FU8(arg0, 3) = one;
    F32(arg0, 0x3C) = F32(arg1, 0x3C);
    F32(arg0, 0x30) = F32(arg1, 0x30);
    F16(arg0, 0x40) = F16(arg1, 0x40);
    F16(arg0, 0x42) = F16(arg1, 0x42);
    FU8(arg0, 0x15) = 0;
    F32(arg0, 8) = F32(arg1, 8);
    F32(arg0, 0xC) = F32(arg1, 0xC);
    switch (F8(arg0, 1)) {
    case 35:
        FU8(arg0, 0x16) = 3;
        set_animation(arg0, F8(arg0, 2));
        break;
    case 36:
        FU8(arg0, 0x16) = one;
        set_animation(arg0, 7);
        break;
    case 37:
        v = F8(arg0, 2);
        FU8(arg0, 0x16) = 0;
        if (v == 0) {
            set_animation(arg0, 8);
        } else if (v == 3) {
            set_animation(arg0, 0xE);
        } else {
            set_animation(arg0, 9);
        }
        break;
    }
    FU8(arg0, 5) = 0;
    FU8(arg0, 4) = FU8(arg0, 4) + 1;
}

#undef set_animation
