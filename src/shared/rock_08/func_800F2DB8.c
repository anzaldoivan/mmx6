#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
extern M2C_UNK D_8007433C;

#define B(p, o) (*(u8*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))

void func_800F2DB8(void* arg0) {
    // !FAKE: pins the constant temp to the first return register
    register s32 t asm("$2");

    W(arg0, 0x58) = (s32)&D_8007433C;
    set_animation(arg0, 5);
    t = 0x40000;
    W(arg0, 0x24) = t;
    W(arg0, 0x20) = 0;
    W(arg0, 0x28) = 0;
    t = 0x2000;
    W(arg0, 0x2C) = t;
    B(arg0, 6)++;
}
