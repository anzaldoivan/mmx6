#include "common.h"

void func_800E99A4(u8* arg0);
extern s8 D_800F1CEA;

void func_800ED114(u8* arg0) {
    s16 t;

    t = ++*(s16*)(arg0 + 8);
    if (t >= 8) {
        D_800F1CEA = 0;
        ((void (*)())func_800E99A4)();
        *(s16*)(arg0 + 8) = 0;
        arg0[2]--;
    }
}
