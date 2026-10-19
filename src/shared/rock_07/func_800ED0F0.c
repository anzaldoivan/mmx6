#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8002D2B0();

void func_800ED0F0(u8* arg0) {
    ((void (*)(void*))func_8002D2B0)(arg0);
    arg0[7] = arg0[7] + 1;
}
