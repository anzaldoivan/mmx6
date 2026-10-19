#include "common.h"

extern void (*D_80070C6C[])(s8*);
extern u16 D_80070C44[][2];

void func_8001A604(s8* arg0) {
    D_80070C6C[arg0[5]](arg0);
    *(u16*)(arg0 + 0xA) = D_80070C44[arg0[2]][0];
    *(u16*)(arg0 + 0xE) = D_80070C44[arg0[2]][1];
}
