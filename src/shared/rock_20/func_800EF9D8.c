#include "common.h"

extern s8 D_80097424[];
#define D_80097424 (*(s8*)&D_80097424)

void func_800EF9D8(u8* arg0) {
    if (D_80097424 == 0) {
        arg0[2] = arg0[2] + 1;
    }
}
#undef D_80097424
