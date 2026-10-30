#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_8002D230(void*);
void func_800F6E48(struct X4_MainObj*);

void func_800F5094(void* arg0) {
    ((void (*)(void*))func_8002D230)(arg0);
    if (M2C_FIELD(arg0, s32*, 0x24) <= 0) {
        func_800F6E48(arg0);
        ((void (*)(void*, M2C_UNK))set_animation)(arg0, 8);
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}
