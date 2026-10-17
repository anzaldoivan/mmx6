#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
void func_800EBCD8(void* arg0);

#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define SB(p, o) (*(s8*)((u8*)(p) + (o)))

void func_800ED2B0(void* arg0) {
    if (SB(arg0, 0x2) == 1) {
        func_8002CCB0(arg0, 0x80, 0x80);
    } else {
        func_800EBCD8(arg0);
    }
    UB(arg0, 0x4) += 1;
}
