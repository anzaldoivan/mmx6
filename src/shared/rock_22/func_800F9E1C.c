#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();

void func_800F9E1C(u8* arg0) {
    u8* temp_s0;

    temp_s0 = *(u8**)(arg0 + 0x84);
    ((void (*)())func_80017A04)(arg0);
    if (*(s8*)(temp_s0 + 0x9A) >= 2) {
        arg0[6] = arg0[6] + 1;
    }
}
