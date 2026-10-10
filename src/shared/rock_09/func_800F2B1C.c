#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80017A04();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
s32 func_80030ECC(void*);
s32 func_80031474(void*);
void func_800F14D4(void*, s32);
extern s32 D_800F6AD0;
extern s32 D_800F6AD4;
extern s16 D_800F6BEA;
extern s16 D_800F6BF0;
extern s32 D_800F6BF8;
extern s32 D_800F6BFC;

void func_800F2B1C(void* arg0) {
    if (D_800F6BF8 != 0 || D_800F6BFC != 0) {
        M2C_FIELD(arg0, u8*, 4)++;
        return;
    }
    if (func_80031474(arg0) < 0 ||
        D_800F6BEA + 0x40 < M2C_FIELD(arg0, s16*, 0xE) ||
        func_80030ECC(arg0) != 0) {
        M2C_FIELD(arg0, u8*, 4)++;
        return;
    }
    switch (M2C_FIELD(arg0, s8*, 5)) {
    case 0:
        if (M2C_FIELD(arg0, s16*, 0xE) < D_800F6BF0 - 0x28) {
            M2C_FIELD(arg0, s32*, 0x24) = 0;
            M2C_FIELD(arg0, s32*, 0x8C) = 0;
            M2C_FIELD(arg0, u8*, 5)++;
        }
        break;
    case 1:
        if (++M2C_FIELD(arg0, s32*, 0x8C) == 0x32) {
            func_800F14D4(arg0, 0x1B);
            func_80016C48(2, 0x3B, arg0);
            M2C_FIELD(arg0, void**, 0x50) = &D_800F6AD0;
            M2C_FIELD(arg0, void**, 0x54) = &D_800F6AD4;
            if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
                M2C_FIELD(arg0, s32*, 0x20) = -0x20000;
            } else {
                M2C_FIELD(arg0, s32*, 0x20) = 0x20000;
            }
            M2C_FIELD(arg0, s32*, 0x24) = -0x20000;
            M2C_FIELD(arg0, u8*, 5)++;
        }
        break;
    case 2:
        break;
    }
    func_8002CCB0(arg0, 0x20, 0x20);
    func_80017A04(arg0);
    func_8002D230(arg0);
}
