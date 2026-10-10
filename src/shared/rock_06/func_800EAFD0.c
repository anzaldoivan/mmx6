#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
s32 func_80030CCC(void*, s16, s16);
extern M2C_UNK D_800F369C;
extern M2C_UNK D_800F36A4;

void func_800EAFD0(void* arg0) {
    if (!(func_80030CCC(arg0, M2C_FIELD(arg0, s16*, 0xA),
                        M2C_FIELD(arg0, s16*, 0xE)) &
          0xFF)) {
        M2C_FIELD(arg0, u8*, 4) = 1;
        M2C_FIELD(arg0, u8*, 5) = 1;
        M2C_FIELD(arg0, s8*, 2) = 0;
        M2C_FIELD(arg0, M2C_UNK**, 0x54) = &D_800F36A4;
        M2C_FIELD(arg0, M2C_UNK**, 0x50) = &D_800F369C;
    }
    if (func_8002CBFC(arg0, 0x40, 0x40) == 0) {
        if (M2C_FIELD(arg0, s8*, 2) == 2) {
            func_8002CCB0(arg0, 0x25, 0x25);
        }
    } else {
        M2C_FIELD(arg0, u8*, 4) = 2;
    }
}
