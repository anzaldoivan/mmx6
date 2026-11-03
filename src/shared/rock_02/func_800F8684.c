#include "common.h"
#define M2C_UNK s32

M2C_UNK animate_object();
M2C_UNK move_object();

void func_800F8684(u8* arg0) {
    ((void (*)(void))animate_object)();
    ((void (*)(s32))move_object)((s32)arg0);
    if (--arg0[0x8D] == 0) {
        arg0[0x5] = 3;
    }
}
