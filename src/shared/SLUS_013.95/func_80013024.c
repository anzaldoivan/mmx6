#include "common.h"

#define M2C_UNK s32

M2C_UNK func_80012D9C(); /* extern */
extern s32 D_8006D894;
extern s8 D_80097426;

void func_80013024(void) {
    if ((D_80097426 == 0) && (D_8006D894 == 0)) {
        func_80012D9C();
    }
}
