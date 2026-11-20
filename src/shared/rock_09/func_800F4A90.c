// rolefeed (3.1 T4): func_800F4A90 of src/rock_09/E9860.c

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object(void*);                  /* extern */
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK apply_object_motion(void*);             /* extern */
extern s32 D_800F6BF8;
extern s32 D_800F6BFC;

void func_800F4A90(void* arg0) {
    if ((D_800F6BF8 != 0) || (D_800F6BFC != 0) ||
        (M2C_FIELD(arg0, s8*, 0x46) == 0)) {
        M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
        return;
    }
    func_8002CCB0(arg0, 0x20, 0x20);
    animate_object(arg0);
    apply_object_motion(arg0);
}
