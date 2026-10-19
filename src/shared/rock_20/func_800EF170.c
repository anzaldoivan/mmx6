#include "common.h"

extern u8 D_800F48F2;
extern u8 D_800F48F3;
extern u8 D_800F48F5;
extern u8 D_800F48F7;

void func_800EF170(u8* arg0) {
    D_800F48F2 = 0;
    D_800F48F3 = 0;
    D_800F48F5 = 0;
    D_800F48F7 = 0;
    arg0[2]++;
}
