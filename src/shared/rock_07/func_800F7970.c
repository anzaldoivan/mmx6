#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80049EBC(void*, M2C_UNK, M2C_UNK, M2C_UNK);

#define F(T, p, o) (*(T*)((u8*)(p) + (o)))

void func_800F7970(void* arg0) {
    if (!(F(u16, arg0, 0x88) & 7)) {
        func_80049EBC(arg0, 1, 0x10, 0x10);
    }
    if (--F(s16, arg0, 0x88) == 0) {
        F(u8, arg0, 4) = 2;
    }
}
