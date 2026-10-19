#include "common.h"

extern void (*D_800FCC18[])(void*);
extern s8 D_800FD51D;
extern s8 D_800FD51E;

void func_800F4CBC(u8* arg0) {
    if ((D_800FD51D != 0) || (D_800FD51E != 0)) {
        arg0[3] = 0;
        arg0[4] = arg0[4] + 1;
        return;
    }
    D_800FCC18[((s8*)arg0)[5]](arg0);
}
