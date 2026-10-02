#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002B36C(M2C_UNK); /* extern */
extern s8 D_80090D56;
extern s16 D_80090D5C;
extern s8 D_8009742C;
extern s16 D_80097430;
extern u8 D_800C4560;
extern s8 D_800CF850;
extern s16 D_800CF854;
extern s8 D_800EAACC;

void func_800E9D38(void* arg0) {
    func_8002B36C(0);
    D_80090D56 = 0;
    D_8009742C = 0;
    D_800CF850 = 0;
    D_800CF854 = 0x1F;
    D_80097430 = 0x3E0;
    D_80090D5C = 0x7C00;
    D_800EAACC = 0;
    D_800C4560 |= 1;
    M2C_FIELD(arg0, s16*, 4) = 4;
    M2C_FIELD(arg0, u8*, 1) = (u8)(M2C_FIELD(arg0, u8*, 1) + 1);
}
