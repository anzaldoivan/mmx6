#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD4C (*(u8**)0x1F80004C)

extern M2C_UNK D_8007523C;
extern s32 D_800E9B48[];

void func_800F612C(void* arg0) {
    s32 tbl[18];
    u8 c;

    __builtin_memcpy(tbl, D_800E9B48, sizeof(tbl));
    if (!(SPAD4C[0x8B] & 7)) {
        M2C_FIELD(arg0, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) | 0x8000;
    } else {
        M2C_FIELD(arg0, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
    }
    c = SPAD4C[0x8B]++;
    if (c >= 0x79) {
        M2C_FIELD(arg0, void**, 0x58) = &D_8007523C;
        M2C_FIELD(arg0, u8*, 5) = SPAD4C[0x86];
        M2C_FIELD(arg0, u8*, 6) = SPAD4C[0x87];
        if (M2C_FIELD(arg0, s8*, 5) >= 0x12 ||
            M2C_FIELD(arg0, s8*, 6) > tbl[M2C_FIELD(arg0, s8*, 5)]) {
            M2C_FIELD(arg0, u8*, 5) = 7;
        }
        SPAD4C[0x8B] = 0;
    }
}
