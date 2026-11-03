#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();

void func_800F20D8(u8* arg0) {
    ((void (*)())animate_object)();
    {
        // !FAKE: first call argument set before the counter test fills the branch delay slot
        register u8* a asm("$4") = arg0;
        if (--*(s16*)(arg0 + 0x7C) == 0) {
            *(s32*)(arg0 + 0x20) = 0xFFFA0000;
            *(s32*)(arg0 + 0x24) = 0;
            ((void (*)(void*, s32))set_animation)(a, 2);
            arg0[6]++;
        }
    }
}
