#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_8002D2B0(void*);
M2C_UNK func_8002EE10(void*);
void func_800F59D8(struct X4_AnimatedObj* arg0, u8 arg1);

void func_800F570C(u8* arg0) {
    if (--*(s16*)(arg0 + 0x88) == 0) {
        *(s16*)(arg0 + 0x88) = 8;
        func_800F59D8((struct X4_AnimatedObj*)arg0, 0x11);
        func_8002D2B0(arg0);
    }
    if (arg0[0x70] != 0 || (func_8002EE10(arg0), arg0[0x70] != 0)) {
        arg0[4] = 2;
    }
}
