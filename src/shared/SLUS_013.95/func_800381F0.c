#include "common.h"

#define M2C_UNK s32
M2C_UNK func_8003AFF4(s32);
extern void (*D_80073C58[])(void*);

void func_800381F0(void* arg0) {
    if (*((s8*)arg0 + 0xD3) != 0) {
        func_8003AFF4((s32)arg0);
        return;
    }
    D_80073C58[*((s8*)arg0 + 6)](arg0);
}
