#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();

#define F(type, off) M2C_FIELD(self, type*, off)

void func_800F1C48(void* self) {
    ((void (*)(void*))animate_object)(self);
    if (F(s8, 7) != 0) {
        F(s8, 7) = 0;
        if (F(s16, 0x7E) != 0) {
            F(s16, 0x7E)--;
            F(u8, 6) = 1;
            return;
        }
        F(u8, 5) = 7;
        F(u8, 6) = 0;
    }
}

#undef F
