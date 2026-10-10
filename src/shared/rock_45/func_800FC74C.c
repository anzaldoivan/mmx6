#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK func_80017A04(void*);                   /* extern */
M2C_UNK func_8002C9B0();                        /* extern */
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_8002D2B0(void*);                   /* extern */
extern s8 D_800CCEDF;

void func_800FC74C(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        D_800CCEDF = 0x10;
        func_8002C9B0();
        return;
    }
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        func_80016C48(2, 0x48, arg0);
        M2C_FIELD(arg0, s32*, 0x24) = 0x80000;
    }
    func_8002CCB0(arg0, 0x40, 0x40);
    func_80017A04(arg0);
    func_8002D2B0(arg0);
}
