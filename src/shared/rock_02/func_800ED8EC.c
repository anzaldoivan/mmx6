#include "common.h"

extern void (*D_800FAEB0[])(void*);

#define SPAD (*(u8**)0x1F80004C)

void func_800ED8EC(u8* arg0) {
    D_800FAEB0[(s8)arg0[6]](arg0);
    SPAD[0x8A] = arg0[6];
    SPAD[0x8B] = arg0[0x7C];
    *(u16*)(SPAD + 0x8E) = *(u16*)(arg0 + 0xE);
    *(s32*)(SPAD + 0x90) = *(s32*)(arg0 + 0x24);
    *(s32*)(SPAD + 0x94) = *(s32*)(arg0 + 0x2C);
}
