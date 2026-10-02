#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, M2C_UNK);             /* extern */
M2C_UNK func_8002B3D4(s32, M2C_UNK*, M2C_UNK);                /* extern */
M2C_UNK func_8002B410(M2C_UNK*, M2C_UNK*, M2C_UNK, s32, s32); /* extern */
extern s8 D_800CCEF6;
extern M2C_UNK D_800F7798;
extern M2C_UNK D_800F77B8;

void func_800EE604(void* arg0) {
    u16 temp_v0;

    if (D_800CCEF6 != 0) {
        M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) - 2);
        return;
    }
    temp_v0 = M2C_FIELD(arg0, u16*, 0x1A);
    if (temp_v0 != 0) {
        M2C_FIELD(arg0, u16*, 0x1A) = (u16)(temp_v0 - 1);
    }
    func_8002B410(&D_800F77B8, &D_800F7798, 0x10,
                  0x3C - M2C_FIELD(arg0, u16*, 0x1A), 0x3C);
    func_8002B3D4(M2C_FIELD(arg0, u16*, 0x20) + 0x60, &D_800F77B8, 1);
    if (M2C_FIELD(arg0, u16*, 0x1A) == 0) {
        M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) - 3);
        func_80016C48(5, 3, 0);
    }
}
