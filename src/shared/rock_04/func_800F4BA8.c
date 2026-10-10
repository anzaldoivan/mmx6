#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80040488(M2C_UNK);
extern u8 D_8008EAFC;

void func_800F4BA8(void* arg0) {
    if (D_8008EAFC == 0) {
        func_80040488(0);
        {
            register s32 v asm("$2") = ((u8*)arg0)[6] + 1;
            ((u8*)arg0)[6] = v;
        }
    }
}
