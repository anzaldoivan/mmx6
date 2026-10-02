#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern M2C_UNK D_8007433C;
extern M2C_UNK D_800FC734;
extern M2C_UNK D_800FC738;

void func_800F9078(void* arg0) {
    s8 temp_v1;

    temp_v1 = M2C_FIELD(arg0, s8*, 0x45);
    if (temp_v1 == 1) {
        M2C_FIELD(arg0, s8*, 0x8E) = temp_v1;
        M2C_FIELD(arg0, M2C_UNK**, 0x58) = &D_8007433C;
        M2C_FIELD(arg0, s8*, 0x60) = 0xA;
        M2C_FIELD(arg0, M2C_UNK**, 0x50) = &D_800FC734;
        M2C_FIELD(arg0, M2C_UNK**, 0x54) = &D_800FC738;
        M2C_FIELD(arg0, s16*, 0x7C) = 0x1E;
        M2C_FIELD(arg0, s8*, 6) = 9;
    }
}
