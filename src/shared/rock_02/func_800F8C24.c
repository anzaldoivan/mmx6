#include "common.h"
#define M2C_UNK s32

M2C_UNK animate_object();

void func_800F8C24(u8* arg0) {
    ((void (*)())animate_object)();
    if (arg0[0x8D]++ >= 0x3D) {
        *(s32*)(arg0 + 0x54) = 0;
        *(s32*)(arg0 + 0x50) = 0;
        arg0[0x8D] = 0x28;
        arg0[6]++;
    }
}
