#include "common.h"

void func_800EA58C(u8* arg0) {
    if ((*(u16*)(arg0 + 0x16))++ >= 0x12D) {
        *(u16*)(arg0 + 0x16) = 8;
        arg0[5]++;
    }
}
