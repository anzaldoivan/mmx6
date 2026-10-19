#include "common.h"

void func_800EA278(u8* arg0, s32 arg1);
extern u8 D_800CD40C;

void func_800E9BDC(u8* arg0) {
    if (D_800CD40C == 2) {
        func_800EA278(arg0, 0);
        arg0[1] = arg0[1] + 1;
    }
}
