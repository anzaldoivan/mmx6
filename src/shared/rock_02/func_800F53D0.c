#include "common.h"

#define M2C_UNK s32

M2C_UNK func_80040488(M2C_UNK);
M2C_UNK func_800F82C0();
extern u8 D_8008EAFC;

void func_800F53D0(void* arg0) {
    ((void (*)())func_800F82C0)();
    if (D_8008EAFC == 0) {
        func_80040488(0);
        {
            // !FAKE: depin: dropping it breaks the match (17/20)
            register s32 v asm("$2") = ((u8*)arg0)[6] + 1;
            ((u8*)arg0)[6] = v;
        }
    }
}
