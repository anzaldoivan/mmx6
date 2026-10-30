#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();
M2C_UNK move_object(void*);

#define F(type, off) M2C_FIELD(self, type*, off)

void func_800F2284(void* self) {
    if (F(u8, 0x70) & 1) {
        set_animation(self, 0);
        F(u8, 0x15) = 0;
        F(s32, 0x20) = 0;
        F(u8, 5) = 7;
        F(u8, 6) = 0;
        return;
    }
    move_object(self);
    ((void (*)(void*))func_80017A04)(self);
}

#undef F
