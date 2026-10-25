#include "common.h"
#define M2C_UNK s32

M2C_UNK move_object();

void func_800ED0F0(u8* arg0) {
    ((void (*)(void*))move_object)(arg0);
    arg0[7] = arg0[7] + 1;
}
