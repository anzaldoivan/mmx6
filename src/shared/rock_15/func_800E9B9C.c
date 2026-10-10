#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CA14(void*, void*); /* extern */
M2C_UNK func_8002CA54(void*, void*); /* extern */
extern u16 D_800CCEDC;

void func_800E9B9C(void* arg0) {
    if ((D_800CCEDC == 2) || (M2C_FIELD(arg0, s8*, 4) == 3)) {
        func_8002CA54(arg0, arg0);
        return;
    }
    func_8002CA14(arg0, arg0);
}
