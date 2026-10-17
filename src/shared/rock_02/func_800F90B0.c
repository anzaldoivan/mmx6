#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8002C9B0();

void func_800F90B0(u8* arg0) {
    s8* p;
    s8 v;

    v = arg0[2];
    p = *(s8**)(arg0 + 0x7C);
    if (v == 1) {
        p[7] = v;
    }
    if ((s8)arg0[2] == 0xB) {
        p[7] = 0;
    }
    arg0[3] = 0;
    func_8002C9B0(arg0, p);
}
