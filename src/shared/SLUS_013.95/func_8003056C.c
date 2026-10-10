#include "common.h"

#define M2C_UNK s32

s32 func_8002FBEC(s32);     /* extern */
M2C_UNK func_800305F4(s32); /* extern */
s32 func_8003091C();        /* extern */

void func_8003056C(s32 arg0) {
    if ((func_8003091C() != 0) && (func_8002FBEC(arg0) != 0)) {
        func_800305F4(arg0);
    }
}
