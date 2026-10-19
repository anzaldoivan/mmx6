#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04();
M2C_UNK func_8002D2B0(s32);
extern M2C_UNK D_800F6F40;
extern M2C_UNK D_800F6F50;

void func_800F39B0(void* arg0) {
    func_80017A04();
    ((void (*)(void*))func_8002D2B0)(arg0);
    if (--M2C_FIELD(arg0, s16*, 0x8C) == 0) {
        func_800179A4(arg0, 1);
        func_80016C48(2, 0x74, arg0);
        M2C_FIELD(arg0, void**, 0x50) = &D_800F6F50;
        M2C_FIELD(arg0, void**, 0x54) = &D_800F6F40;
        M2C_FIELD(arg0, s8*, 7) = -1;
        M2C_FIELD(arg0, u8*, 6)++;
    }
}
