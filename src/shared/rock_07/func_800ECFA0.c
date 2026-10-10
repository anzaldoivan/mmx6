#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002D2B0();

void func_800ECFA0(void* arg0) {
    ((void (*)(void*))func_8002D2B0)(arg0);
    if (--M2C_FIELD(arg0, s16*, 0x88) == 0) {
        M2C_FIELD(arg0, u8*, 7) += 1;
    }
}
