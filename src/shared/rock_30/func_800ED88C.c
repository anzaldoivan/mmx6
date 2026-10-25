#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK move_object(s32);

#define F(type, off) M2C_FIELD(self, type*, off)

void func_800ED88C(void* self) {
    ((void (*)(void*))move_object)(self);
    if (F(s16, 0xE) <= F(s16, 0x7E)) {
        F(s32, 0x24) = 0xFFFC0000;
        F(s16, 0xE) = F(s16, 0x7E);
        F(s8, 5) = 0;
    }
}

#undef F
