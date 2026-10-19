#include "common.h"

s32 func_800EA480(s8* arg0);
extern s8 D_8009724F;

void func_800FA688(s8* arg0) {
    if (func_800EA480(arg0) != 0) {
        D_8009724F = 1;
        arg0[1]++;
    }
}
