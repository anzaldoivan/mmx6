#include "common.h"

#define NULL ((void*)0)
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* func_8002C3F8();                   /* extern */
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK); /* extern */
extern s8 D_800970A5;
extern s8 D_800CCEDF;
extern void* D_800F70E0;

void func_800EEA3C(void* arg0) {
    s8 temp_s1;
    void* temp_v0;

    if (D_800CCEDF == 0) {
        temp_s1 = D_800970A5;
        if (temp_s1 == 0x14) {
            func_8003D308(0x1D, 0x40);
            temp_v0 = func_8002C3F8();
            if (temp_v0 != NULL) {
                M2C_FIELD(temp_v0, s8*, 0) = 1;
                M2C_FIELD(temp_v0, s8*, 1) = 0x18;
                D_800F70E0 = temp_v0;
            }
            M2C_FIELD(arg0, s16*, 0x7C) = (s16)temp_s1;
            M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
        }
    }
}
