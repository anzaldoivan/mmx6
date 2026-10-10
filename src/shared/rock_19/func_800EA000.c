#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04(); /* extern */
extern s8 D_800CCF08;

void func_800EA000(void* arg0) {
    if (D_800CCF08 == 0) {
        M2C_FIELD(arg0, s8*, 3) = 1;
    } else {
        M2C_FIELD(arg0, s8*, 3) = 0;
    }
    func_80017A04();
}
