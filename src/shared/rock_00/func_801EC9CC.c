#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002B2F8(s32);
M2C_UNK func_8002B36C(M2C_UNK);
M2C_UNK func_8002C9B0();
extern s8 D_80090D56;
extern s16 D_80090D5C;
extern s8 D_8009742C;
extern s16 D_80097430;
extern s8 D_800CF850;
extern s16 D_800CF854;

void func_801EC9CC(void* arg0) {
    u8 temp_v0;

    if (M2C_FIELD(arg0, s8*, 4) == 0) {
        func_8002B36C(0);
        D_80090D56 = 0;
        D_8009742C = 0;
        D_800CF850 = 0;
        D_800CF854 = 0x1F;
        D_80097430 = 0x3E0;
        D_80090D5C = 0x7C00;
        M2C_FIELD(arg0, u8*, 4) = M2C_FIELD(arg0, u8*, 4) + 1;
        return;
    }
    temp_v0 = M2C_FIELD(arg0, u8*, 0x47);
    if (temp_v0 == 0 || (M2C_FIELD(arg0, u8*, 0x47) = --temp_v0) == 0) {
        func_8002B2F8(0);
        func_8002C9B0(arg0);
    }
}
