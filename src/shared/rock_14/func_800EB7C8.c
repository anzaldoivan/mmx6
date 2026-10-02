#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();                        /* extern */
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);     /* extern */
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_8002D2B0(void*);                   /* extern */
M2C_UNK func_8002EE10(void*);                   /* extern */
M2C_UNK func_80030ECC(void*);                   /* extern */
M2C_UNK func_80049D90(void*);                   /* extern */

void func_800EB7C8(void* arg0) {
    func_80017A04();
    func_8002D2B0(arg0);
    func_80030ECC(arg0);
    if ((M2C_FIELD(arg0, u8*, 0x70) != 0) ||
        (func_8002EE10(arg0), (M2C_FIELD(arg0, u8*, 0x70) != 0))) {
        func_80049D90(arg0);
        M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
        return;
    }
    if (func_8002CBFC(arg0, 0x18, 0x18) == 0) {
        func_8002CCB0(arg0, 0x10, 0x10);
        return;
    }
    M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
}
