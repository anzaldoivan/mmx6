#include "common.h"
#define M2C_UNK s32

#ifndef M2C_FIELD
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#endif

M2C_UNK func_80030ECC(void*);
extern void (*D_800FD558[])(void*);

void func_800FA848(u8* arg0) {
    M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
    func_80030ECC(arg0);
    D_800FD558[M2C_FIELD(arg0, s8*, 0x5)](arg0);
}
