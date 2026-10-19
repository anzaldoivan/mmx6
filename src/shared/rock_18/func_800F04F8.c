#include "common.h"

extern s8 D_800CC869;
#define D_800CC869 (*(u8*)&D_800CC869)

void func_800F04F8(u8* arg0) {
    arg0[3] = 1;
    if (D_800CC869 != 0) {
        arg0[0x47] = 0xA;
        return;
    }
    arg0[0x47] = 0xB;
}
#undef D_800CC869
