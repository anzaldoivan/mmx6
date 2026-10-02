#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800ED524(); /* extern */
extern s8 D_800972A4;

void func_800ED4E8(void* arg0) {
    M2C_FIELD(arg0, s8*, 0x15) = 0;
    M2C_FIELD(arg0, s8*, 0x14) = 0;
    M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
    D_800972A4 = 5;
    func_800ED524();
}
