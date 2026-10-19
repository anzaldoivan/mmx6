#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800139F4(M2C_UNK);
extern u16 D_800C4570;

void func_800EC918(u8* arg0) {
    if (D_800C4570 != 0) {
        ((void (*)(s32))func_800139F4)(8);
        arg0[1]++;
    }
}
