#include "common.h"

extern void* D_800EA9C4[];

s32 func_800EA480(s8* arg0) {
    // !FAKE: retail holds the handler in the second argument register
    register void* f asm("$5") = *(void**)((arg0[3] << 2) + (s32)D_800EA9C4);

    ((void (*)())f)();
    if (*(s16*)(arg0 + 0xA) == 0) {
        arg0[3] = 0;
        return 1;
    }
    return 0;
}
