#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002C9B0(void*);    /* extern */
M2C_UNK func_8003C4EC(M2C_UNK*); /* extern */
extern M2C_UNK D_800970A0;

void func_801EFCF4(void* arg0) {
    void* temp_v1;

    if (M2C_FIELD(arg0, s8*, 2) == 0) {
        if (M2C_FIELD(arg0, s8*, 6) == 0) {
            func_8003C4EC(&D_800970A0);
            M2C_FIELD(&D_800970A0, u8*, 0x98) =
                (u8)(M2C_FIELD(&D_800970A0, u8*, 0x98) - 1);
            M2C_FIELD(&D_800970A0, u8*, 0x99) =
                (u8)(M2C_FIELD(&D_800970A0, u8*, 0x99) - 1);
            if (M2C_FIELD(&D_800970A0, s8*, 0xA6) == 1) {
                M2C_FIELD(&D_800970A0, s8*, 0xA6) = 0;
            }
            func_8002C9B0(arg0);
        }
    } else {
        temp_v1 = M2C_FIELD(arg0, void**, 0x7C);
        if (M2C_FIELD(temp_v1, s8*, 6) != 0) {
            M2C_FIELD(temp_v1, s8*, 6) =
                (s8)((u8)M2C_FIELD(temp_v1, s8*, 6) - 1);
        }
        func_8002C9B0(arg0);
    }
}
