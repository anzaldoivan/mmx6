#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();
M2C_UNK func_8002D2B0();

void func_800F8684(u8* arg0) {
    ((void (*)(void))func_80017A04)();
    ((void (*)(s32))func_8002D2B0)((s32)arg0);
    if (--arg0[0x8D] == 0) {
        arg0[0x5] = 3;
    }
}
