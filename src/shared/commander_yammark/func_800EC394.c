#include "common.h"

#define M2C_UNK s32

M2C_UNK apply_object_motion();
extern void (*D_800EFA9C[])(void*);

void func_800EC394(void* arg0) {
    apply_object_motion(arg0);
    D_800EFA9C[((s8*)arg0)[7]](arg0);
}
