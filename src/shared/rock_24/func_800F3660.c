#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04(void*);                   /* extern */
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_8002D230(void*);                   /* extern */
M2C_UNK func_80030ECC(void*, s16);              /* extern */
s32 func_80031474(void*);                       /* extern */
M2C_UNK func_80049E50(void*);                   /* extern */
extern s32 D_800F77D8;
extern s32 D_800F77DC;
extern void* D_800F7800;

void func_800F3660(void* arg0) {
    s16 temp_a0;
    s16 temp_a0_2;
    s16 var_a1;
    s32 temp_v0;
    s32 temp_v0_2;
    s8 temp_v1;
    u32 temp_v0_3;
    u32 temp_v0_4;

    if ((D_800F77D8 != 0) || (D_800F77DC != 0)) {
        M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
        return;
    }
    if (((u32)M2C_FIELD(arg0, u32*, 0x8C) >= 5U) && (func_80031474(arg0) < 0)) {
        func_80049E50(arg0);
        M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
        return;
    }
    temp_a0 = M2C_FIELD(arg0, s16*, 0xA);
    var_a1 = M2C_FIELD(D_800F7800, s16*, 0xA);
    temp_v0 = var_a1 - temp_a0;
    if (temp_v0 >= 0) {
        if (temp_v0 >= 0x18) {

        } else {
            goto block_10;
        }
    } else if ((temp_a0 - var_a1) < 0x18) {
    block_10:
        temp_a0_2 = M2C_FIELD(arg0, s16*, 0xE);
        var_a1 = M2C_FIELD(D_800F7800, s16*, 0xE);
        temp_v0_2 = var_a1 - temp_a0_2;
        if (temp_v0_2 >= 0) {
            if (temp_v0_2 >= 0x20) {

            } else {
                goto block_14;
            }
        } else if ((temp_a0_2 - var_a1) < 0x20) {
        block_14:
            if (M2C_FIELD(D_800F7800, s8*, 5) != 7) {
                D_800F77DC = 1;
                M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
            }
        }
    }
    func_80030ECC(arg0, var_a1);
    temp_v1 = M2C_FIELD(arg0, s8*, 5);
    switch (temp_v1) { /* irregular */
    case 0:
        temp_v0_3 = M2C_FIELD(arg0, u32*, 0x8C) + 1;
        M2C_FIELD(arg0, u32*, 0x8C) = temp_v0_3;
        if (temp_v0_3 == 0x3C) {
            M2C_FIELD(arg0, s32*, 0x50) = 0;
            M2C_FIELD(arg0, s32*, 0x54) = 0;
            M2C_FIELD(arg0, s8*, 5) = (s8)((u8)M2C_FIELD(arg0, s8*, 5) + 1);
        }
        break;
    case 1:
        temp_v0_4 = M2C_FIELD(arg0, u32*, 0x8C) + 1;
        M2C_FIELD(arg0, u32*, 0x8C) = temp_v0_4;
        if (temp_v0_4 == 0x50) {
            M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
        }
        break;
    }
    if ((M2C_FIELD(arg0, s8*, 5) != 1) || (M2C_FIELD(arg0, u32*, 0x8C) & 1)) {
        func_8002CCB0(arg0, 0x20, 0x20);
    }
    func_80017A04(arg0);
    func_8002D230(arg0);
}
