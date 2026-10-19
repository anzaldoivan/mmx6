#include "common.h"

extern u8 D_800FB26C[];

void func_800F3A34(u8* arg0) {
    if (((s8*)arg0)[0x45] == 1) {
        *(u8**)(arg0 + 0x54) = D_800FB26C + 0x1060;
        arg0[6] = arg0[6] + 1;
    }
}
