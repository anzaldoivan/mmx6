#include "common.h"

#define M2C_UNK s32

s32 func_8002FBEC();        /* extern */
M2C_UNK func_800305F4(s32); /* extern */
s32 func_8003091C(s32);     /* extern */

void func_800305B0(s32 arg0) {
    if ((((s32(*)())func_8002FBEC)() != 0) && (func_8003091C(arg0) != 0)) {
        func_800305F4(arg0);
    }
}
