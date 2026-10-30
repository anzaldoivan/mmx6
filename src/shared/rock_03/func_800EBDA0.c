#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);

#define BDA0_SP64 (*(u8**)(0x1F800064))
#define BDA0_UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define BDA0_UH(p, o) (*(u16*)((u8*)(p) + (o)))
#define BDA0_W(p, o) (*(s32*)((u8*)(p) + (o)))

void func_800EBDA0(u8* arg0) {
    BDA0_UB(BDA0_SP64, 0x54) = 0xFF;
    BDA0_UB(arg0, 0x15) = 0;
    BDA0_UH(BDA0_SP64, 0x56) = 0;
    BDA0_UB(arg0, 0x16) = 6;
    set_animation(arg0, 1);
    BDA0_UB(arg0, 3) = 0;
    BDA0_UB(arg0, 5) = 0;
    BDA0_W(arg0, 0x20) = 0;
    BDA0_W(arg0, 0x28) = 0;
    BDA0_W(arg0, 0x24) = 0;
    BDA0_W(arg0, 0x2C) = 0;
    BDA0_UB(arg0, 4) = 1;
}
