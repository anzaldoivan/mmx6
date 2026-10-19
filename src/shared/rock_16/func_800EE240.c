#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SB(p, o) M2C_FIELD(p, s8*, o)

M2C_UNK func_800179D0(void*, M2C_UNK, s8);
extern u8 D_800F1CC4[];

void func_800EE240(void* arg0) {
    s8 idx;

    idx = SB(arg0, 0x2);
    func_800179D0(arg0, idx, D_800F1CC4[idx]);
}
