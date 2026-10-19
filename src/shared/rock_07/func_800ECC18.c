#include "common.h"

void func_800ECC18(u8* arg0) {
    u8* p = *(u8**)(arg0 + 0x80);
    if (*(s8*)(arg0 + 0x45) == 1) {
        p[7] = 0;
        arg0[6] = 0;
    }
}
