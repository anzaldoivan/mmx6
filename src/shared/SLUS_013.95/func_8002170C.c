#include "common.h"

extern u16 D_8009711C;
#define D_801F6000_VAL (*(s32*)0x801F6000)
#define D_801F68DC_ADDR 0x801F68DC

void func_8002170C(void) {
    if (D_801F6000_VAL != 0x9C4) {
        *(u16*)(D_801F6000_VAL * 2 + D_801F68DC_ADDR) = D_8009711C;
        D_801F6000_VAL += 1;
    }
}
