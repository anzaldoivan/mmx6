#include "common.h"

s32 func_8002D30C();

void func_8004C330(u8* arg0) {
    *(s16*)(arg0 + 0x34) = 2;
    arg0[0x36] = 0;
    arg0[0x37] = 0;
    arg0[0] |= 0x82;
    *(u16*)(arg0 + 0x38) = *(u16*)(arg0 + 8);
    {
        s32 r = func_8002D30C();
        *(s32*)(arg0 + 0x14) = 0;
        *(s32*)(arg0 + 0x18) = 0;
        arg0[4]++;
        arg0[0x3A] = r % 3;
    }
}
