#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK); /* extern */
M2C_UNK func_80017A04();               /* extern */
M2C_UNK func_8002D230(void*);          /* extern */

void func_800EC738(void* arg0) {
    ((void (*)())func_80017A04)();
    ((void (*)(void*))func_8002D230)(arg0);
    if (--M2C_FIELD(arg0, u8*, 0x80) == 0) {
        M2C_FIELD(arg0, s32*, 0x28) = -0x200;
        ((void (*)(void*, s32))func_800179A4)(arg0, 5);
        M2C_FIELD(arg0, u8*, 0x80) = 0x5A;
        M2C_FIELD(arg0, u8*, 7) = (u8)(M2C_FIELD(arg0, u8*, 7) + 1);
    }
}
