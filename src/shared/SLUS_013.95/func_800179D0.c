#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800179D0(void* arg0, M2C_UNK arg1, s32 arg2) {
    u8* p = arg0;
    s32* temp_a3;

    temp_a3 = (*(s32***)(p + 0x30))[arg1];
    p[0x48] = 0xFF;
    p[0x17] = arg1;
    temp_a3 += arg2;
    *(s32**)(p + 0x34) = temp_a3;
    *(s32*)(p + 0x44) = *temp_a3;
}
