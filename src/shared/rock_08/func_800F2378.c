#include "common.h"
#define M2C_UNK s32

#define OUB(p, o) (*(u8*)((u8*)(p) + (o)))
#define OH(p, o) (*(u16*)((u8*)(p) + (o)))

s32 func_800179A4(void*, s32);
M2C_UNK func_80017A04();
extern u8 D_800CCF5F;

void func_800F2378(void* arg0) {
    register s32 t asm("$2");

    func_80017A04();
    t = OH(arg0, 0x7C) - 1;
    OH(arg0, 0x7C) = t;
    if ((s16)t == 0) {
        if (D_800CCF5F < 2) {
            OUB(arg0, 0x89) = 0;
        } else if (D_800CCF5F == 2) {
            OUB(arg0, 0x89) = 1;
        } else {
            OUB(arg0, 0x89) = 2;
        }
        func_800179A4(arg0, 2);
        t = OUB(arg0, 6) + 1;
        OUB(arg0, 6) = t;
    }
}
