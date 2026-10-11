#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
s32 func_8002D2D4();
void func_800F67D0(void*, s32);
extern s8 D_800970A2;
extern u8 D_800CCF38;

void func_800F5AA8(u8* arg0) {
    s8 state = *(s8*)(arg0 + 0x45);

    if (state == 1) {
        if (D_800CCF38 >= 2 && (func_8002D2D4() & 1)) {
            func_80016C48(2, 0x29, arg0);
            func_800F67D0(arg0, 3);
        } else if (D_800970A2 == 0) {
            func_80016C48(2, 0x28, arg0);
            func_800F67D0(arg0, 2);
        } else {
            func_80016C48(2, 0x27, arg0);
            func_800F67D0(arg0, 1);
        }
        arg0[7] = 1;
        arg0[6]++;
    } else if (state == 2) {
        func_80016C48(2, 0x60, arg0);
    }
}
