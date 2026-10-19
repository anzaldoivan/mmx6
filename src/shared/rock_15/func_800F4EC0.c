#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();

void func_800F4EC0(u8* arg0) {
    u8* temp_s1;

    temp_s1 = *(u8**)(arg0 + 0x7C);
    ((void (*)(u8*))func_80017A04)(arg0);
    if (--*(s16*)(arg0 + 0x8C) == 0x78) {
        arg0[6]++;
        temp_s1[7]--;
    }
}
