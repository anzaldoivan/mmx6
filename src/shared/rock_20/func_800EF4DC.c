#include "common.h"

extern s8 D_800CCEF8;

void func_800EF4DC(void* arg0) {
    D_800CCEF8 = 0x5F;
    ((u8*)arg0)[1] = 4;
    ((u8*)arg0)[2] = 0;
}
