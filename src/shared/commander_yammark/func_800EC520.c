#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();

void func_800EC520(u8* arg0) {
    ((void (*)(void*))func_80017A04)(arg0);
    if (*(s8*)(arg0 + 0x45) != 0) {
        arg0[0x80] = 0x28;
        arg0[7] = arg0[7] + 1;
    }
}
