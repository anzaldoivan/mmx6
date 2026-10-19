#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80021760(M2C_UNK, M2C_UNK, M2C_UNK);
extern u8 D_800F0964[];
extern u8 func_800F095C[];

void func_800ED648(void* arg0) {
    u8 v;

    func_800F095C[0] = D_800F0964[0];
    func_800F095C[1] = D_800F0964[1];
    func_800F095C[2] = D_800F0964[2];
    func_800F095C[3] = v = D_800F0964[3];
    ((void (*)(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK))func_80021760)(1, 0xFF, 0,
                                                                  v);
    M2C_FIELD(arg0, u8*, 2) = M2C_FIELD(arg0, u8*, 2) + 1;
}
