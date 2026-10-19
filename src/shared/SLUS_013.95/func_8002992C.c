#include "common.h"

#define M2C_UNK s32

void func_80029A2C();    /* extern */
M2C_UNK func_80029A4C();    /* extern */

void func_8002992C(s32 arg0) {
    func_80029A4C();
    func_80029A2C(arg0);
}
