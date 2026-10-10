#include "common.h"

#define M2C_UNK s32

s32 func_8003A0E8();        /* extern */
M2C_UNK func_8003AFF4(s32); /* extern */

void func_801EC908(s32 arg0) {
    if (func_8003A0E8() != 0) {
        func_8003AFF4(arg0);
    }
}
