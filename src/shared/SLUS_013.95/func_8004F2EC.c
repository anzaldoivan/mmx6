#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);      /* extern */
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK); /* extern */
extern u8 D_80011674[8][4];
extern s32 D_80078CC0;
extern s32 D_80078CC4;
extern s32 D_80078CC8;
extern s16 D_800970AA;
extern u8 D_800CCF38;

void func_8004F2EC(void* arg0) {
    u8 tbl[8][4];
    s8 state;
    u32 idx;
    s16 a;

    __builtin_memcpy(tbl, D_80011674, sizeof(tbl));
    M2C_FIELD(arg0, u8*, 0x60) = 4;
    state = M2C_FIELD(arg0, s8*, 2);
    M2C_FIELD(arg0, u8*, 0x5C) = 1;
    M2C_FIELD(arg0, s32*, 0x58) = 0;
    M2C_FIELD(arg0, u8*, 0x67) = 1;
    M2C_FIELD(arg0, u8*, 3) = 0;
    M2C_FIELD(arg0, void**, 0x68) = 0;
    M2C_FIELD(arg0, void**, 0x50) = 0;
    M2C_FIELD(arg0, void**, 0x54) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    idx = M2C_FIELD(arg0, u8*, 0x88) >> 4;
    if (state == 0) {
        M2C_FIELD(arg0, u8*, 0x16) = 1;
        ((void (*)(void*, s32))func_800179A4)(arg0, 3);
        if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
            M2C_FIELD(arg0, s16*, 0xA) += (s8)tbl[idx][0];
            M2C_FIELD(arg0, s16*, 0xE) += (s8)tbl[idx][1];
        } else {
            M2C_FIELD(arg0, s16*, 0xA) += (s8)tbl[idx][2];
            M2C_FIELD(arg0, s16*, 0xE) += (s8)tbl[idx][3];
        }
    } else if (state == 1) {
        M2C_FIELD(arg0, u8*, 0x16) = state;
        ((void (*)(void*, s32))func_800179A4)(arg0, 4);
        if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
            M2C_FIELD(arg0, s32*, 0x20) = -0x40000;
            a = M2C_FIELD(arg0, s16*, 0xA) + (s8)tbl[idx][0] - 0x14;
            M2C_FIELD(arg0, s16*, 0xE) =
                M2C_FIELD(arg0, s16*, 0xE) + (s8)tbl[idx][1];
            M2C_FIELD(arg0, s16*, 0xA) = a;
        } else {
            M2C_FIELD(arg0, s32*, 0x20) = 0x40000;
            a = M2C_FIELD(arg0, s16*, 0xA) + (s8)tbl[idx][2] + 0x14;
            M2C_FIELD(arg0, s16*, 0xE) =
                M2C_FIELD(arg0, s16*, 0xE) + (s8)tbl[idx][3];
            M2C_FIELD(arg0, s16*, 0xA) = a;
        }
        if (D_800CCF38 >= 2) {
            M2C_FIELD(arg0, s32*, 0x20) *= 2;
        }
        M2C_FIELD(arg0, s16*, 0x88) = 6;
    } else {
        ((void (*)(void*, s32))func_800179A4)(arg0, 0x1B);
        M2C_FIELD(arg0, void**, 0x68) = &D_80078CC0;
        M2C_FIELD(arg0, void**, 0x50) = &D_80078CC4;
        M2C_FIELD(arg0, void**, 0x54) = &D_80078CC8;
        if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
            M2C_FIELD(arg0, s16*, 0xA) -= 0x1C;
            M2C_FIELD(arg0, s16*, 0xE) -= 0x18;
        } else {
            M2C_FIELD(arg0, s16*, 0xA) += 0x1C;
            M2C_FIELD(arg0, s16*, 0xE) -= 0x18;
        }
        M2C_FIELD(arg0, s32*, 0x20) =
            ((D_800970AA - M2C_FIELD(arg0, s16*, 0xA)) << 16) / 70;
        M2C_FIELD(arg0, s32*, 0x24) = 0x30000;
        M2C_FIELD(arg0, s32*, 0x2C) = 0x1800;
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        M2C_FIELD(arg0, u8*, 0x5C) = 2;
        M2C_FIELD(arg0, u8*, 0x60) = 3;
    }
    M2C_FIELD(arg0, u8*, 4) = 1;
    M2C_FIELD(arg0, u8*, 5) = 0;
    M2C_FIELD(arg0, u8*, 6) = 0;
    M2C_FIELD(arg0, u8*, 7) = 0;
    if (func_8002CBFC(arg0, 0x20, 0x20) == 1) {
        M2C_FIELD(arg0, u8*, 4)++;
    }
}
