#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK); /* extern */
M2C_UNK animate_object();              /* extern */
M2C_UNK apply_object_motion(void*);    /* extern */

void func_800EC738(void* arg0) {
    ((void (*)())animate_object)();
    ((void (*)(void*))apply_object_motion)(arg0);
    if (--M2C_FIELD(arg0, u8*, 0x80) == 0) {
        M2C_FIELD(arg0, s32*, 0x28) = -0x200;
        ((void (*)(void*, s32))set_animation)(arg0, 5);
        M2C_FIELD(arg0, u8*, 0x80) = 0x5A;
        M2C_FIELD(arg0, u8*, 7) = (u8)(M2C_FIELD(arg0, u8*, 7) + 1);
    }
}
