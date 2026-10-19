#include "common.h"
#define M2C_UNK s32

s32 func_80016C48(s32 a0, s32 a1, void* arg2); /* extern */

M2C_UNK func_8003CFE0(void* arg0, M2C_UNK arg1) {
    arg1 &= 0xFF;
    if (((s8*)arg0)[0x8D] <= 0) {
        func_80016C48(3, arg1, arg0);
    }
}
