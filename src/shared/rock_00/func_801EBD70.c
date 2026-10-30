#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK end_dash(s32);
extern void (*D_801F3760[])(void*);

void func_801EBD70(void* arg0) {
    D_801F3760[M2C_FIELD(arg0, s8*, 6)](arg0);
    if (M2C_FIELD(arg0, s8*, 0x93) != 5) {
        end_dash((s32)arg0);
    }
}
