#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_80047E34(u8* arg0); /* extern */
M2C_UNK func_80047FB8(); /* extern */

void func_80047F78(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 4) == 0) {
        ((void (*)())func_80047E34)();
        return;
    }
    func_80047FB8();
}
