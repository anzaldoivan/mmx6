#include "common.h"

#define M2C_UNK s32

s32 func_8002D2D4();                           /* extern */
M2C_UNK func_8004A0C0(M2C_UNK, s16, s16, s32); /* extern */

void func_800F4664(s16 arg0, s16 arg1) {
    func_8004A0C0(0, arg0, arg1, (func_8002D2D4() & 1) ^ 1);
}
