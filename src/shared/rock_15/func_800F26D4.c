#include "common.h"

s32 func_8002D2D4();
void func_800F1DA8(void* arg0, s32 arg1, s32 arg2);

void func_800F26D4(u8* arg0) {
    if (*(s16*)(arg0 + 0x86) != 0) {
        *(s16*)(arg0 + 0x86) = *(s16*)(arg0 + 0x86) - 1;
    }
    if (*(s16*)(arg0 + 0x7C) != 0) {
        *(s16*)(arg0 + 0x7C) = *(s16*)(arg0 + 0x7C) - 1;
        return;
    }
    if (*(s16*)(arg0 + 0x7E) != 0) {
        *(s16*)(arg0 + 0x7C) = 0x1E;
        *(s16*)(arg0 + 0x7E) = *(s16*)(arg0 + 0x7E) - 1;
        func_800F1DA8(arg0, func_8002D2D4() & 1, 0);
        arg0[0x8D] = arg0[0x8D] + 1;
        return;
    }
    arg0[6] = arg0[6] + 1;
}
