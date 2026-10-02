#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();                        /* extern */
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);     /* extern */
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_8002D2B0(void*);                   /* extern */
s32 func_80031474(void*);                       /* extern */
M2C_UNK func_80049D90(void*);                   /* extern */

void func_800F2BE0(void* arg0) {
    ((M2C_UNK(*)())func_80017A04)();
    func_8002D2B0(arg0);
    if (func_80031474(arg0) < 0) {
        func_80049D90(arg0);
        M2C_FIELD(arg0, s8*, 4) = 2;
        return;
    }
    if (func_8002CBFC(arg0, 0x60, 0x60) == 0) {
        func_8002CCB0(arg0, 0x30, 0x30);
        return;
    }
    M2C_FIELD(arg0, s8*, 4) = 2;
}
