#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();               /* extern */
s32 func_8002CB50(struct X4_BaseObj*); /* extern */
#define func_8002CB50 func_8002CB50
s32 func_8002CBFC(struct X4_AnimatedObj* arg0, s32 arg1, s32 arg2); /* extern */
M2C_UNK move_object(void*);                                         /* extern */

void func_800464C4(void* arg0) {
    ((M2C_UNK(*)())func_80017A04)();
    move_object(arg0);
    if (func_8002CBFC(arg0, 0x10, 0x10) != 0) {
        M2C_FIELD(arg0, s8*, 4) = 3;
    }
    func_8002CB50(arg0);
}
#undef func_8002CB50
