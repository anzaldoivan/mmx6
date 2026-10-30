#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80025F34(); /* extern */
M2C_UNK func_800280F4(); /* extern */
M2C_UNK init_checkpoint_positions(); /* extern */
M2C_UNK reset_level();   /* extern */
M2C_UNK func_8002C2B8(); /* extern */
extern s8 D_800EAACC;

void func_800E9B0C(void* arg0) {
    reset_level();
    func_8002C2B8();
    init_checkpoint_positions();
    func_800280F4();
    func_80025F34();
    D_800EAACC = 1;
    M2C_FIELD(arg0, u8*, 1) = (u8)(M2C_FIELD(arg0, u8*, 1) + 1);
}
