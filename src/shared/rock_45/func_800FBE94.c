#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK func_80017A04(void*);                   /* extern */
M2C_UNK func_8002D230(void*);                   /* extern */

void func_800FBE94(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x45) == 2) {
        func_80016C48(2, 0x38, arg0);
        func_80016C48(2, 0x5C, arg0);
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
    func_80017A04(arg0);
    func_8002D230(arg0);
}
