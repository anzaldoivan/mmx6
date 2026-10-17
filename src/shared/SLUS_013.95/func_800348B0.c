#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80026028();
extern void (*D_800739B0[])(s8*);
extern u16 D_800C4570;

void func_800348B0(s8* arg0) {
    s8 st;
    s8 t;

    if ((D_800C4570 & 0x100) && ((t = arg0[5]) < 3 || t == 8)) {
        *(s32*)(arg0 + 0x30) = t;
        arg0[5] = 6;
        arg0[6] = 0;
    }
    st = arg0[5];
    D_800739B0[st](arg0);
    if (st != 7) {
        if (arg0[5] < 5) {
            func_80026028();
        }
        if (arg0[5] == 7) {
            func_80026028();
        }
    }
    if (arg0[5] >= 8) {
        func_80026028();
    }
}
