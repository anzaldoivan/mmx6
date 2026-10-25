#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK); /* extern */
M2C_UNK func_80017A04();               /* extern */
M2C_UNK move_object(void*);            /* extern */
extern M2C_UNK D_800743DC;
extern M2C_UNK D_800F369C;
extern M2C_UNK D_800F36A4;

void func_800EB2B8(void* arg0) {
    s32 var_v0;

    if (M2C_FIELD(arg0, s8*, 6) == 0) {
        M2C_FIELD(arg0, M2C_UNK**, 0x58) = &D_800743DC;
        M2C_FIELD(arg0, M2C_UNK**, 0x54) = &D_800F36A4;
        M2C_FIELD(arg0, M2C_UNK**, 0x50) = &D_800F369C;
        M2C_FIELD(arg0, s8*, 6) = (s8)((u8)M2C_FIELD(arg0, s8*, 6) + 1);
        func_800179A4(arg0, 1);
        var_v0 = -0x6000;
        if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
            var_v0 = 0x6000;
        }
        M2C_FIELD(arg0, s32*, 0x20) = var_v0;
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
    }
    func_80017A04(arg0);
    move_object(arg0);
    if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
        if (M2C_FIELD(arg0, u8*, 0x70) & 1) {
            M2C_FIELD(arg0, u8*, 0x15) = 0;
            M2C_FIELD(arg0, s32*, 0x20) = -M2C_FIELD(arg0, s32*, 0x20);
        }
    } else if (M2C_FIELD(arg0, u8*, 0x70) & 2) {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        M2C_FIELD(arg0, s32*, 0x20) = -M2C_FIELD(arg0, s32*, 0x20);
    }
}
