#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();
s32 random_byte();

#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define H(p, o) (*(s16*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))

void func_800F2324(void* arg0) {
    ((void (*)())func_80017A04)(arg0);
    if (H(arg0, 0x7C) != 0) {
        H(arg0, 0x7C)--;
        return;
    }
    W(arg0, 0x68) = 0;
    if (!(random_byte() & 1)) {
        W(arg0, 0x20) = 0xFFFA0000;
        UB(arg0, 0x15) = 0;
    } else {
        W(arg0, 0x20) = 0x60000;
        UB(arg0, 0x15) = 0x40;
    }
    W(arg0, 0x24) = 0;
    set_animation(arg0, 2);
    {
        // !FAKE: depin: dropping it breaks the match (32/35)
        register s32 c asm("$2") = UB(arg0, 6) + 1;
        UB(arg0, 6) = c;
    }
}
