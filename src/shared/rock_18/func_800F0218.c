#include "common.h"

void func_800F0218(u8* arg0) {
    u8* p = *(u8**)(arg0 + 0x50);

    arg0[3] = p[3];
    *(s16*)(arg0 + 0x42) = *(s16*)(p + 0x42);
    *(s16*)(arg0 + 0xA) = *(s16*)(p + 0xA) + 0xF8;
    *(s16*)(arg0 + 0xE) = *(s16*)(p + 0xE);
    switch (p[0x47]) {
    case 5:
        arg0[0x47] = 0x14;
        break;
    case 10:
        arg0[0x47] = 0x15;
        break;
    default:
        arg0[3] = 0;
        break;
    }
}
