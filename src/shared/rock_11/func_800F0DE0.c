#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002A47C(s32);

void func_800F0DE0(void* arg0) {
    void* p;

    p = M2C_FIELD(arg0, void**, 0x50);
    if (M2C_FIELD(p, u8*, 7) & 1) {
        M2C_FIELD(arg0, u8*, 3) = 0;
        M2C_FIELD(arg0, u8*, 4) += 1;
        return;
    }
    M2C_FIELD(arg0, s16*, 0xA) =
        M2C_FIELD(p, s16*, 0xA) + M2C_FIELD(arg0, s16*, 8);
    M2C_FIELD(arg0, s16*, 0xE) =
        M2C_FIELD(p, s16*, 0xE) + M2C_FIELD(arg0, s16*, 0xC);
    switch (M2C_FIELD(arg0, s8*, 0x45)) {
    case 1:
        M2C_FIELD(arg0, s16*, 0x42) =
            (((func_8002A47C(M2C_FIELD(p, s8*, 1)) + 2) * 4 + 0x20) % 16) |
            (((func_8002A47C(M2C_FIELD(p, s8*, 1)) + 10) / 4 + 0x1E0) << 6);
        break;
    case 2:
        M2C_FIELD(arg0, s16*, 0x42) =
            (((func_8002A47C(M2C_FIELD(p, s8*, 1)) + 3) * 4 + 0x20) % 16) |
            (((func_8002A47C(M2C_FIELD(p, s8*, 1)) + 11) / 4 + 0x1E0) << 6);
        break;
    }
}
