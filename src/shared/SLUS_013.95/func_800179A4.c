#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800179A4(void* arg0, M2C_UNK arg1) {
    s32* temp_a2;

    temp_a2 = (*(s32***)((u8*)arg0 + 0x30))[arg1];
    *((u8*)arg0 + 0x48) = 0xFF;
    *((u8*)arg0 + 0x17) = arg1;
    *(s32**)((u8*)arg0 + 0x34) = temp_a2;
    *(s32*)((u8*)arg0 + 0x44) = *temp_a2;
}
