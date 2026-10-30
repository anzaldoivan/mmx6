#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
extern s32 D_800F90C0;
extern s32 D_800F90C4;

#define F(T, p, o) (*(T*)((u8*)(p) + (o)))

void func_800F61D4(void* arg0) {
    set_animation(arg0, 0x13);
    {
        // !FAKE: depin: dropping it breaks the match (15/19)
        register s32* a asm("$2") = &D_800F90C0;
        F(s32*, arg0, 0x50) = a;
    }
    {
        // !FAKE: depin: dropping it breaks the match (12/19)
        register s32* b asm("$3") = &D_800F90C4;
        F(s32*, arg0, 0x54) = b;
    }
    F(u8, arg0, 6)++;
}
