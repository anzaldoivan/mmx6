#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern u16 D_800F171C[];

void func_800F0694(void* arg0) {
    M2C_FIELD(arg0, u16*, 0xA) = 0x10;
    M2C_FIELD(arg0, u16*, 0xE) = 0x10;
    if (M2C_FIELD(arg0, s8*, 2) == 0) {
        M2C_FIELD(arg0, u16*, 0x16) = M2C_FIELD(arg0, u16*, 0x1E) =
            D_800F171C[0];
        M2C_FIELD(arg0, u16*, 0x1A) = M2C_FIELD(arg0, u16*, 0x22) =
            D_800F171C[1];
        M2C_FIELD(arg0, u16*, 0x26) = M2C_FIELD(arg0, u16*, 0x2E) =
            D_800F171C[2];
        M2C_FIELD(arg0, u16*, 0x2A) = M2C_FIELD(arg0, u16*, 0x32) =
            D_800F171C[3];
    } else {
        M2C_FIELD(arg0, u16*, 0x16) = M2C_FIELD(arg0, u16*, 0x1E) =
            D_800F171C[4];
        M2C_FIELD(arg0, u16*, 0x1A) = M2C_FIELD(arg0, u16*, 0x22) =
            D_800F171C[5];
        M2C_FIELD(arg0, u16*, 0x26) = M2C_FIELD(arg0, u16*, 0x2E) =
            D_800F171C[6];
        M2C_FIELD(arg0, u16*, 0x2A) = M2C_FIELD(arg0, u16*, 0x32) =
            D_800F171C[7];
    }
    M2C_FIELD(arg0, u16*, 0x38) = 0;
    M2C_FIELD(arg0, u8*, 4) = M2C_FIELD(arg0, u8*, 4) + 1;
}
