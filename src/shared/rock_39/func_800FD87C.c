#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_8002D230(void*);               /* extern */

void func_800FD87C(void* arg0) {
    u16 temp_v0;

    if (M2C_FIELD(arg0, s8*, 5) == 0) {
        M2C_FIELD(arg0, s8*, 5) = (s8)((u8)M2C_FIELD(arg0, s8*, 5) + 1);
        M2C_FIELD(arg0, u16*, 0x7C) = 0U;
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0x4200;
    }
    func_8002D230(arg0);
    if (func_8002CBFC(arg0, 0x40, 0x40) == 0) {
        temp_v0 = M2C_FIELD(arg0, u16*, 0x7C);
        M2C_FIELD(arg0, u16*, 0x7C) = (u16)(temp_v0 + 1);
        if (temp_v0 & 1) {
            M2C_FIELD(arg0, s8*, 3) = 1;
            return;
        }
        M2C_FIELD(arg0, s8*, 3) = 0;
        return;
    }
    M2C_FIELD(arg0, s8*, 4) = 7;
}
