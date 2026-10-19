#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();
M2C_UNK func_8002CB50();

void func_800ECB14(s8* arg0) {
    if (arg0[7] < 0xA) {
        ((void (*)())func_80017A04)();
        if (arg0[0x45] & 0x80) {
            ((u8*)arg0)[0x45] &= 0x7F;
            ((u8*)arg0)[7]++;
        }
    }
    func_8002CB50(arg0);
}
