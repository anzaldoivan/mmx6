#include "common.h"

extern s8 D_800CCEF8;

void func_800EF230(u8* arg0) {
    D_800CCEF8 = 0x6F;
    arg0[1] = 0xA;
    arg0[2] = 0;
}
