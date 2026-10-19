#include "common.h"
#define M2C_UNK s32

void func_80017A04(struct X4_AnimatedObj*);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);

void func_801F1DD0(s8* arg0) {
    ((void (*)())func_80017A04)();
    if (arg0[0x46] == 0) {
        arg0[4] = 2;
    }
    ((void (*)(void*, s32, s32))func_8002CCB0)(arg0, 0x20, 0x20);
    if ((arg0[3] == 0) && (arg0[0x8C] == 0)) {
        arg0[4] = 2;
    }
}
