#include "common.h"

void func_80044058(u8* arg0) {
    s32 temp_v0;

    temp_v0 = *(u16*)(arg0 + 0x88) + 8;
    *(u16*)(arg0 + 0x88) = temp_v0;
    if ((s16)temp_v0 >= 0x20) {
        *(u16*)(arg0 + 0x88) = 0x20;
        arg0[5]++;
    }
}
