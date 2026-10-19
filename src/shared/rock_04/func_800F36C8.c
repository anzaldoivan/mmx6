#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_8002D230();

void func_800F36C8(void* arg0) {
    if (--*(s16*)((u8*)arg0 + 0x7C) == 0) {
        ((void (*)(void*, s32))func_800179A4)(arg0, 6);
        *(u16*)((u8*)arg0 + 0x7C) = 0xB;
        ((u8*)arg0)[6]++;
        return;
    }
    func_8002D230(arg0);
}
