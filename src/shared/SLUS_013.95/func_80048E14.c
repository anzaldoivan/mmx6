#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002C9B0(); /* extern */
M2C_UNK func_8002CB50(); /* extern */
extern u8 D_80097427;
extern s8 D_800CCED1;

void func_80048E14(void* arg0) {
    ((M2C_UNK(*)())func_8002CB50)();
    if (M2C_FIELD(arg0, s8*, 0x54) != D_800CCED1) {
        func_8002C9B0(arg0);
        return;
    }
    if (M2C_FIELD(arg0, s8*, 0x55) != D_80097427) {
        func_8002C9B0(arg0);
    }
}
