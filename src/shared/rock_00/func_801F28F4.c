#include "common.h"

extern s8 D_80097131;
extern void (*D_801F3AC0[])(s8*);

void func_801F28F4(s8* arg0) {
    D_801F3AC0[arg0[5]](arg0);
    if (arg0[6] == 0) {
        D_80097131 = 5;
    }
}
