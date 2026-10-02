#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();                        /* extern */
s32 func_8002CAB4(void*);                       /* extern */
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK); /* extern */

void func_800ED2F4(void* arg0) {
    func_80017A04();
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        if (M2C_FIELD(arg0, s8*, 6) != 0) {
            M2C_FIELD(arg0, s8*, 6) = (s8)((u8)M2C_FIELD(arg0, s8*, 6) - 1);
        } else {
            M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
        }
    }
    if (func_8002CAB4(arg0) == 0) {
        func_8002CCB0(arg0, 0x30, 0x10);
        return;
    }
    M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
}
