#include "common.h"

void func_8002C9B0(void* arg0);
extern s8 D_800CCED1;
extern void (*D_80070C7C[])(s8*);

void func_8001A674(s8* arg0) {
    if (D_800CCED1 == 0) {
        ((void (*)())func_8002C9B0)();
    } else {
        D_80070C7C[arg0[4]](arg0);
    }
}
