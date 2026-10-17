#include "common.h"

extern s32 func_8006AA54();
extern s32 func_8006A984();
extern void func_8006A7D4();
extern s32 func_8006A814();
extern u8 D_8006D898[];
extern u8 D_8006D8A0[];
extern s32 D_8006D8A4;

void func_80013064(void) {
    s32 w;
    s32 v;
    // !FAKE: regalloc pin, constant one kept in the second callee-saved register
    register s32 one asm("$17");

    w = func_8006AA54(0, 2, 0);
    v = func_8006A984(0);
    one = 1;
    if (v == one) {
        D_8006D8A4 = 0;
    }
    if (D_8006D8A4 == 0) {
        func_8006A7D4(0, D_8006D8A0, 2);
        if (v == 2 || (v == 6 && (w == 4 || w == 7) &&
                       func_8006A814(0, D_8006D898) != 0)) {
            D_8006D8A4 = one;
        }
    }
}
