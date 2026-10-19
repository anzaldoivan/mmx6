#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();

void func_800F9410(void* arg0) {
    u8* s1;

    s1 = *(u8**)((u8*)arg0 + 0x84);
    ((void (*)())func_80017A04)();
    if (*(s8*)((u8*)arg0 + 2) == 1) {
        *(u8*)((u8*)arg0 + 6) += 1;
        return;
    }
    if (*(s8*)((u8*)arg0 + 0x45) == 1) {
        s1[6] += 1;
        *(u8*)((u8*)arg0 + 6) += 1;
    }
}
