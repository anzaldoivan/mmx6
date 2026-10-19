#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();
M2C_UNK func_8003BA04(void*, M2C_UNK);

void func_800382C8(u8* arg0) {
    ((void (*)())func_80017A04)();
    if (*(s8*)(arg0 + 0x46) == 0) {
        arg0[6]++;
        func_8003BA04(arg0, 0x54);
    }
}
