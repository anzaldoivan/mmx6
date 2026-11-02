#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002D230();
extern void (*D_800EFA9C[])(void*);

void func_800EC394(void* arg0) {
    func_8002D230(arg0);
    D_800EFA9C[((s8*)arg0)[7]](arg0);
}
