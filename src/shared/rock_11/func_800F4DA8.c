#include "common.h"

extern void (*D_800FCC28[])(s8*);

void func_800F4DA8(s8* arg0) {
    if ((*(s8**)(arg0 + 0x5C))[4] != 2) {
        arg0[3] = 0;
        ((u8*)arg0)[4]++;
        return;
    }
    D_800FCC28[arg0[6]](arg0);
}
