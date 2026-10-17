#include "common.h"

void func_800F53CC(void*);
extern void (*D_800F6FC0[])(void*);

void func_800F38D0(s8* arg0) {
    if (arg0[0x92] != 0) {
        func_800F53CC(arg0);
        return;
    }
    D_800F6FC0[arg0[6]](arg0);
}
