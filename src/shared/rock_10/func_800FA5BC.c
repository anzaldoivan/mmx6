#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK move_object();
M2C_UNK func_8002EE10(void*);
M2C_UNK func_80049D90(void*);

void func_800FA5BC(void* arg0) {
    ((void (*)(s32))move_object)((s32)arg0);
    if (M2C_FIELD(arg0, u8*, 0x70) != 0 ||
        (func_8002EE10(arg0), M2C_FIELD(arg0, u8*, 0x70) != 0)) {
        func_80049D90(arg0);
        M2C_FIELD(arg0, u8*, 3) = 0;
        M2C_FIELD(arg0, u8*, 4) = 3;
    }
}
