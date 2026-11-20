#include "common.h"
#define M2C_UNK s32

#define F(type, off) (*(type*)((u8*)arg0 + (off)))

s32 func_80030ECC();
extern void (*D_800FD534[])(void*);

void func_800FA1EC(void* arg0) {
    F(u16, 0x42) &= 0x7FFF;
    func_80030ECC(arg0);
    D_800FD534[F(s8, 6)](arg0);
    F(u8, 3) = 1;
}
#undef F
