#include "common.h"

#define M2C_UNK s32

M2C_UNK func_80015C5C(); /* extern */
extern u8 D_8008EC08;

void func_8001651C(void) {
    if (D_8008EC08 != 0) {
        func_80015C5C();
    }
}
