#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04();

void func_800F97A4(void* arg0) {
    func_80017A04(arg0);
    if (((s8*)arg0)[0x45] == 4) {
        ((void (*)(void*, s32))func_800179A4)(arg0, 0xB);
        ((u8*)arg0)[6] = ((u8*)arg0)[6] + 1;
    }
}
