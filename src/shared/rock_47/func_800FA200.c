#include "common.h"

extern s8 D_80097424;

void func_800FA200(u8* arg0) {
    if (D_80097424 == 0) {
        *(s16*)(arg0 + 8) = 0x17;
        *(s16*)(arg0 + 0xA) = 0xF;
        arg0[1]++;
    }
}
