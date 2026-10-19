#include "common.h"

extern s32 D_80090C90[][16];

void func_8002B63C(s32 arg0, s32 arg1) {
    D_80090C90[arg0][arg1 >> 5] |= 0x80000000U >> (arg1 & 0x1F);
}
