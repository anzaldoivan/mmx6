#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8003BA04(void*, M2C_UNK);
void func_801EB324(s8* p);
s32 func_801ECCD4(void*);

s32 func_801EBF94(void* arg0) {
    s8* p = arg0;
    // !FAKE: pin the arm value to the register retail uses at the join
    register s32 v asm("$3");

    if (func_801ECCD4(p) == 0) {
        return 0;
    }
    if (p[0x86] == 6) {
        func_8003BA04(p, 0x60);
        play_sound(1, 7, p);
        v = 0x35;
    } else {
        func_8003BA04(p, 0x5B);
        play_sound(1, 8, p);
        v = 0x31;
    }
    p[5] = v;
    p[6] = 0;
    do {
        func_801EB324(p);
    } while (0);
    return 1;
}
