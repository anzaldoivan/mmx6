#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
extern void (*D_801F3A34[])(void*);

void func_801F120C(void* arg0) {
    D_801F3A34[((s8*)arg0)[5]](arg0);
    func_8002CCB0(arg0, 0x28, 0x28);
}
