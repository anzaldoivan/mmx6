#include "common.h"

extern u16 D_80097798[];
extern u16 D_8009E1B0[];

#define SPAD28 (*(s32*)0x1F800028)

void func_80017CD8(void) {
    __builtin_memcpy(D_80097798, (void*)SPAD28, 0x4000);
    __builtin_memcpy(D_8009E1B0, (void*)SPAD28, 0x4000);
}
