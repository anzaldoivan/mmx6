#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_8002A47C(s32);
extern s32 D_80074B5C;
extern s32 D_800FAF0C;

#define F0E78_SP20 (*(s32*)(0x1F800020))

void func_800F0E78(void* arg0) {
    if (M2C_FIELD(arg0, s16*, 0xE) < 0x131) {
        M2C_FIELD(arg0, s16*, 0xE) = 0x130;
        M2C_FIELD(arg0, void**, 0x50) = &D_800FAF0C;
        M2C_FIELD(arg0, void**, 0x58) = &D_80074B5C;
        M2C_FIELD(arg0, u8*, 0x84) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x3C) =
            F0E78_SP20 +
            *(s32*)(func_8002A47C(M2C_FIELD(arg0, s8*, 1)) * 4 + F0E78_SP20);
        func_800179A4(arg0, 0);
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, s8*, 5) = 4;
        M2C_FIELD(arg0, s8*, 6) = 0;
    }
}
