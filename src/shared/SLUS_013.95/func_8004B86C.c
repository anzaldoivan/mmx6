#include "common.h"

void func_8004B86C(u8* arg0) {
    s16 temp_a1;
    s16 temp_a2;
    u16 temp_a0;
    u16 temp_v0;

    temp_v0 = *(u16*)(arg0 + 0x42);
    temp_a0 = *(u16*)(arg0 + 0x40);
    temp_v0 = *(u16*)(arg0 + 0x42) = temp_v0 + temp_a0;
    if ((s16)temp_v0 >= 0x100) {
        *(u16*)(arg0 + 0x26) = *(u16*)(arg0 + 0x2E);
        *(u16*)(arg0 + 0x2A) = *(u16*)(arg0 + 0x32);
        arg0[4]++;
        return;
    }
    temp_a2 = *(s16*)(arg0 + 0x3C);
    temp_a1 = *(s16*)(arg0 + 0x3E);
    *(u16*)(arg0 + 0x40) = temp_a0 + 1;
    *(u16*)(arg0 + 0x26) =
        temp_a2 + ((((*(s16*)(arg0 + 0x2E)) - temp_a2) * (s16)temp_v0) >> 8);
    *(u16*)(arg0 + 0x2A) =
        temp_a1 + ((((*(s16*)(arg0 + 0x32)) - temp_a1) * (s16)temp_v0) >> 8);
}
