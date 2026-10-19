#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002EE10(void*);
M2C_UNK func_80049D90(void*);
extern void (*D_800F888C[])(void*);

void func_800ED064(void* arg0) {
    D_800F888C[M2C_FIELD(arg0, s8*, 7)](arg0);
    if (M2C_FIELD(arg0, u8*, 0x70) == 0) {
        func_8002EE10(arg0);
        if (M2C_FIELD(arg0, u8*, 0x70) == 0) {
            return;
        }
    }
    if (M2C_FIELD(arg0, s32*, 0x24) < 0) {
        func_80049D90(arg0);
    }
    M2C_FIELD(arg0, u8*, 4) = 2;
}
