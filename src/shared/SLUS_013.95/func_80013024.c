#include "common.h"

#define M2C_UNK s32

void func_80012D9C(s32);
#define func_80012D9C ((void (*)())func_80012D9C)
extern s32 D_8006D894;
extern s8 D_80097426;

void func_80013024(void) {
    if ((D_80097426 == 0) && (D_8006D894 == 0)) {
        func_80012D9C();
    }
}
#undef func_80012D9C
