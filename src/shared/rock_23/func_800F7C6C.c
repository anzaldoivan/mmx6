#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();                    /* extern */
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_8002D2B0(void*);               /* extern */
extern M2C_UNK D_800752DC;
extern M2C_UNK D_8007537C;
extern u8 D_80097187;

void func_800F7C6C(void* arg0) {
    M2C_UNK* var_v0;
    u8 temp_v0;

    ((M2C_UNK(*)())func_80017A04)();
    temp_v0 = M2C_FIELD(arg0, u8*, 0x8D);
    if (temp_v0 != 0) {
        M2C_FIELD(arg0, u8*, 0x8D) = (u8)(temp_v0 - 1);
        return;
    }
    if (D_80097187 == 2) {
        var_v0 = &D_8007537C;
    } else {
        var_v0 = &D_800752DC;
    }
    M2C_FIELD(arg0, M2C_UNK**, 0x58) = var_v0;
    func_8002D2B0(arg0);
    if (func_8002CBFC(arg0, 0x30, 0x30) == 1) {
        M2C_FIELD(arg0, s8*, 4) = 2;
    }
}
