#include "common.h"

#define M2C_UNK s32

#include "mmx6/x4.h"

M2C_UNK func_8002C9D4();
s32 func_8002CBFC(struct X4_AnimatedObj* arg0, s32 arg1, s32 arg2);

void func_80051FA8(struct X4_AnimatedObj* arg0) {
    if (func_8002CBFC(arg0, 0x88, 0x88) == 1) {
        func_8002C9D4(arg0);
    }
}
