#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();                        /* extern */
s32 func_8002CBFC(struct X4_AnimatedObj* arg0, s32 arg1, s32 arg2);     /* extern */
void func_8002CCB0(struct X4_BaseObj* arg0, s32 arg1, s32 arg2); /* extern */
M2C_UNK func_8002D2B0(void*);                   /* extern */
M2C_UNK func_80030ECC(void*);                   /* extern */

void func_80042FA8(void* arg0) {
    ((M2C_UNK(*)())func_80017A04)();
    func_8002D2B0(arg0);
    func_80030ECC(arg0);
    if (func_8002CBFC(arg0, 0x20, 0x20) == 0) {
        func_8002CCB0(arg0, 0x10, 0x10);
        return;
    }
    M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
}
