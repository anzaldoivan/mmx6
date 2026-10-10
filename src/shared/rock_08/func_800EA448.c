#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002B3D4(M2C_UNK, M2C_UNK*, M2C_UNK);       /* extern */
M2C_UNK func_8002B54C(M2C_UNK*, M2C_UNK*, M2C_UNK, u16); /* extern */
extern s32 D_80097420;
extern M2C_UNK D_800F62F0;
extern M2C_UNK D_800F66F0;

void func_800EA448(void* arg0) {
    if (!(D_80097420 & 1)) {
        func_8002B54C(&D_800F66F0, &D_800F62F0, 0x200,
                      M2C_FIELD(arg0, u16*, 0x14));
        func_8002B3D4(0x93, &D_800F66F0, 0x20);
        M2C_FIELD(arg0, u16*, 0x14) = (u16)(M2C_FIELD(arg0, u16*, 0x14) - 1);
    }
    if (M2C_FIELD(arg0, u16*, 0x14) == 0) {
        M2C_FIELD(arg0, s16*, 0x16) = 8;
        M2C_FIELD(arg0, u8*, 5) = (u8)(M2C_FIELD(arg0, u8*, 5) + 1);
    }
}
