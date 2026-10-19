#include "common.h"

extern s8 D_80097180;
extern void (*D_800F86FC[])(s8*);

void func_800EBB14(s8* arg0) {
    if (D_80097180 != 2 || arg0[6] < 2) {
        D_800F86FC[arg0[6]](arg0);
    }
}
