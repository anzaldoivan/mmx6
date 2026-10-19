#include "common.h"

void func_8001C8C4(u8* arg0) {
    s32 i;
    s32 j;
    s32 sum;
    u8* p;
    u8* e;
    s32 n;

    i = 0;
    do {
        if (arg0[0] != 0xFF) {
            p = arg0;
            sum = 0;
            e = arg0 + 0x3B8;
            n = e - p;
            for (j = 0; j < n; j++) {
                sum = (sum + *p++) & 0xFFFF;
            }
            sum = (sum + 0x55) & 0xFFFF;
            if (*(u16*)(arg0 + 0x3B8) != sum) {
                arg0[0] = 0xFF;
            }
        }
        i++;
        arg0 += 0x3BC;
    } while (i < 8);
}
