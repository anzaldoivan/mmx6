#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();

void func_800F9498(u8* arg0) {
    u8* s1;

    s1 = *(u8**)(arg0 + 0x84);
    ((void (*)())func_80017A04)();
    if ((*(s16*)(arg0 + 0x7C))++ >= 0x78) {
        s1[7]++;
        arg0[6]++;
    }
}
