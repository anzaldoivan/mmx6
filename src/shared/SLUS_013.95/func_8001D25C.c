#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80013300(M2C_UNK, M2C_UNK*); /* extern */
extern M2C_UNK D_800CD3F8;
extern M2C_UNK func_8001D0E4;

void func_8001D25C(void) {
    M2C_FIELD(&D_800CD3F8, s8*, 0) = 1;
    M2C_FIELD(&D_800CD3F8, s8*, 1) = 0;
    M2C_FIELD(&D_800CD3F8, s8*, 2) = 0;
    M2C_FIELD(&D_800CD3F8, s8*, 3) = 0;
    func_80013300(0, &func_8001D0E4);
}
