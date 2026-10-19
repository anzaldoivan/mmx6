#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8002CB50();
extern void (*D_80077BDC[])();

void func_80048FD4(s8* arg0) {
    D_80077BDC[arg0[5]](arg0);
    if (arg0[4] == 1) {
        ((void (*)())func_8002CB50)(arg0);
    }
}
