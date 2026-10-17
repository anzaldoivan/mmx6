#include "common.h"
#define M2C_UNK s32

extern u8 D_8008EAFC;
M2C_UNK func_800F82C0();

void func_800F64FC(u8* arg0) {
    ((void (*)(u8*))func_800F82C0)(arg0);
    if (D_8008EAFC == 0) {
        *(s32*)(arg0 + 0x20) = 0;
        *(s32*)(arg0 + 0x24) = 0x20000;
        arg0[6]++;
    }
}
