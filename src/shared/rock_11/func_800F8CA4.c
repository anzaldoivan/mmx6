#include "common.h"

void func_800F8CA4(s8* arg0) {
    s8 lvl = arg0[0x8B];

    if (lvl >= 6) {
        arg0[5] = 10;
    } else if (lvl >= 3) {
        arg0[5] = 9;
    } else {
        arg0[5] = 8;
    }
    arg0[6] = 0;
}
