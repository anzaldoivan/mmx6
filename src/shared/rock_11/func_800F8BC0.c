#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
s32 func_8002D2D4();
void func_800F9E00(u8* arg0, u8 arg1);

void func_800F8BC0(u8* arg0) {
    s8 state = arg0[0x45];

    if (state == 1) {
        if (func_8002D2D4() & 1) {
            func_80016C48(2, 0x22, arg0);
        } else {
            func_80016C48(2, 0x23, arg0);
        }
        func_80016C48(2, 0x4B, arg0);
        func_800F9E00(arg0, 0x10);
        func_800F9E00(arg0, 0x11);
    } else if (state == 2) {
        arg0[6]++;
    } else if (state == 3) {
        func_80016C48(2, 0x4A, arg0);
    }
}
