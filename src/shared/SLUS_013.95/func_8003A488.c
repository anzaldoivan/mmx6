#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8003015C();                   /* extern */
M2C_UNK func_8003B7B4(void*);          /* extern */
M2C_UNK func_8003BA04(void*, M2C_UNK); /* extern */
void func_801EB6E8(void* arg0);        /* extern */

s32 func_8003A488(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0xD3) != 0) {
        return 0;
    }
    if (!(M2C_FIELD(arg0, u16*, 0x7C) & 4)) {
        return 0;
    }
    if (func_8003015C(arg0) != 0x20) {
        return 0;
    }
    if (M2C_FIELD(arg0, s8*, 0x8E) == 0) {
        func_8003BA04(arg0, 0x1F);
        func_8003B7B4(arg0);
        return 1;
    }
    func_801EB6E8(arg0);
    return 1;
}
