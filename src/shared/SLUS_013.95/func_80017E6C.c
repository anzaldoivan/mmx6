#include "common.h"
#include "psyq/libgpu.h"

#define M2C_UNK s32

extern M2C_UNK D_8006E368;
extern M2C_UNK D_8006E584;

void func_80017E6C(void) {
    LoadImage(&D_8006E584, &D_8006E368);
}
