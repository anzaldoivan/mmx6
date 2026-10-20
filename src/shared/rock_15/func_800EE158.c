#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800179A4(void*, M2C_UNK);
void func_800EF164();

void func_800EE158(void* arg0) {
    if (((s8*)arg0)[0x45] == 1) {
        ((void (*)(void*, s32))func_800179A4)(arg0, 0xC);
        func_800EF164(arg0, 0x10);
        ((u8*)arg0)[5] = ((u8*)arg0)[5] + 1;
    }
}
