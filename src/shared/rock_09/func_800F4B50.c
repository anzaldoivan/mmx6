#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04(void*);                   /* extern */
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_8002D230(void*);                   /* extern */
extern s32 D_800F6BF8;
extern s32 D_800F6BFC;

void func_800F4B50(void* arg0) {
    if ((D_800F6BF8 != 0) || (D_800F6BFC != 0) ||
        (M2C_FIELD(arg0, s8*, 0x46) == 0)) {
        M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
        return;
    }
    func_8002CCB0(arg0, 0x20, 0x20);
    func_80017A04(arg0);
    func_8002D230(arg0);
}
