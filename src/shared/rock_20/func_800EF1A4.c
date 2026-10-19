#include "common.h"

extern u16 D_800C4570;
extern s8 D_800CCEF8;
extern u8 D_800F48F2;
#define D_800F48F2 (*(s8*)&D_800F48F2)
extern u8 D_800F48F3;
extern u8 D_800F48F5;
#define D_800F48F5 (*(s8*)&D_800F48F5)

void func_800EF1A4(u8* arg0) {
    if (D_800F48F5 != 0) {
        if (D_800C4570 & 0x8FF) {
            if (D_800F48F2 >= 0) {
                D_800CCEF8 = 0x5F;
                D_800F48F5 = 0;
                D_800F48F3 = (D_800F48F3 + 1) & 3;
                arg0[2] = 1;
                return;
            }
            // !FAKE: m2c control flow, jump to the shared tail
            goto block_5;
        }
    } else {
    block_5:
        D_800CCEF8 = 0x6F;
        arg0[2] = arg0[2] + 1;
    }
}
#undef D_800F48F2
#undef D_800F48F5
