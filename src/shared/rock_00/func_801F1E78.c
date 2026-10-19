#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002C9B0();
extern M2C_UNK D_800970A0;
#define D_800970A0 (*(struct X4_PlayerObj*)&D_800970A0)

void func_801F1E78(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x8C) == 0) {
        struct X4_PlayerObj* p = &D_800970A0;
        M2C_FIELD(p, u8*, 0x98)--;
        M2C_FIELD(p, u8*, 0x99)--;
    }
    ((M2C_UNK(*)())func_8002C9B0)(arg0, arg0);
}
#undef D_800970A0
