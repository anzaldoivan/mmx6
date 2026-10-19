#include "common.h"
#define M2C_UNK s32

#define FX(p, type, off) (*(type*)((u8*)(p) + (off)))

M2C_UNK func_800139A0(s8);
void* func_8002C530();
extern u8 D_80071114[];

void func_8001DEB8(void* arg0) {
    u32 i;
    s8* o;

    for (i = 0; i < 1; i++) {
        o = func_8002C530();
        if (o != 0) {
            o[0] = 1;
            o[1] = 0x13;
            o[2] = D_80071114[i];
        }
    }
    FX(arg0, s16, 4) = 0x258;
    FX(arg0, u8, 0xD) = 0;
    FX(arg0, u8, 1)++;
    ((void (*)(s8))func_800139A0)(8);
}
