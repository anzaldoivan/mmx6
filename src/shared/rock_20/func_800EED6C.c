#include "common.h"

s32 func_800F054C(void);

void func_800EED6C(u8* arg0) {
    if (func_800F054C() != 0) {
        arg0[2]++;
    } else {
        arg0[2] = 0xB;
    }
}
