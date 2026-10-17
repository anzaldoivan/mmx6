#include "common.h"

void func_800EF80C(u8* arg0) {
    if (--*(s16*)(arg0 + 0x88) == 0) {
        *(s16*)(arg0 + 0x88) = 0x3C;
        arg0[6]++;
    }
}
