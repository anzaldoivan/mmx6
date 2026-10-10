#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK); /* extern */
extern s8 D_800CCEF8;
extern u8 D_800F7794;

void func_800EDACC(void* arg0) {
    if (D_800F7794 == 3) {
        D_800CCEF8 = 1;
    }
    M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
    func_8002CCB0(arg0, 0x28, 0x40);
}
