#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();

#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define SB(p, o) (*(s8*)((u8*)(p) + (o)))

void func_800EE880(void* arg0) {
    ((void (*)())func_80017A04)();
    if (SB(arg0, 0x46) == 0) {
        ((void (*)(void*, s32))set_animation)(arg0, 5);
        UB(arg0, 0x0) |= 0x10;
        UB(arg0, 0x5) += 1;
    }
}
