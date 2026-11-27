// rolefeed (3.1 T4): func_800FC8BC of src/rock_43/FA000.c
#include "common.h"

#include "common.h"
extern s32 D_800FDE30;

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object(void*);                  /* extern */
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK apply_object_motion(void*);             /* extern */

void func_800FC8BC(void* arg0) {
    ((void (**)(void*))((u8*)&D_800FDE30 + 0x374))[M2C_FIELD(arg0, s8*, 6)](
        arg0);
    func_8002CCB0(arg0, 0x40, 0x40);
    animate_object(arg0);
    apply_object_motion(arg0);
}
