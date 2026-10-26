#include "common.h"
#include "psyq/libpad.h"

extern u8 D_8006D898[];
extern u8 D_8006D8A0[];
extern s32 D_8006D8A4;

void func_80013064(void) {
    s32 w;
    s32 v;
    // !FAKE: regalloc pin, constant one kept in the second callee-saved register
    register s32 one asm("$17");

    w = PadInfoMode(0, 2, 0);
    v = PadGetState(0);
    one = 1;
    if (v == one) {
        D_8006D8A4 = 0;
    }
    if (D_8006D8A4 == 0) {
        PadSetAct(0, D_8006D8A0, 2);
        if (v == 2 || (v == 6 && (w == 4 || w == 7) &&
                       PadSetActAlign(0, D_8006D898) != 0)) {
            D_8006D8A4 = one;
        }
    }
}
