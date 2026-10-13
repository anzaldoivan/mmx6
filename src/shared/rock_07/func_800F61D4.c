#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800179A4(void*, M2C_UNK);
extern s32 D_800F90C0;
extern s32 D_800F90C4;

#define F(T, p, o) (*(T*)((u8*)(p) + (o)))

void func_800F61D4(void* arg0) {
    func_800179A4(arg0, 0x13);
    {
        register s32* a asm("$2") = &D_800F90C0;
        F(s32*, arg0, 0x50) = a;
    }
    {
        register s32* b asm("$3") = &D_800F90C4;
        F(s32*, arg0, 0x54) = b;
    }
    F(u8, arg0, 6)++;
}
