#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_80030ECC(void*);
s32 func_80031474(void*);
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
M2C_UNK func_80049E50(void*);
void func_8004E654(void*, s8);
void func_800EB1F4(void*);
extern s32 D_800970A8;
extern M2C_UNK D_800FAB44;
extern void (*D_800FAB58[])(void*);

void func_800EAC8C(void* arg0) {
    u8 temp_a0;

    M2C_FIELD(arg0, s32*, 0x18) = M2C_FIELD(arg0, s32*, 0x8);
    M2C_FIELD(arg0, s32*, 0x1C) = M2C_FIELD(arg0, s32*, 0xC);
    D_800FAB58[M2C_FIELD(arg0, s8*, 5)](arg0);
    if (M2C_FIELD(arg0, s8*, 2) != 0 && M2C_FIELD(arg0, u8*, 0x47) == 0) {
        if (M2C_FIELD(arg0, s32*, 8) > D_800970A8) {
            M2C_FIELD(arg0, u8*, 0x15) = 0;
        } else {
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        }
    }
    func_800EB1F4(arg0);
    if (func_80031474(arg0) < 0) {
        func_8004E654(arg0, 0x15);
        func_80049E50(arg0);
        func_800477E4(4, &D_800FAB44, arg0);
        func_8004E654(arg0, 0xE);
        goto block_10;
    }
    temp_a0 = M2C_FIELD(arg0, u8*, 0x70);
    if ((temp_a0 & 0xC) == 0xC || (temp_a0 & 3) == 3) {
        func_8004E654(arg0, 0x15);
        func_80049E50(arg0);
        func_800477E4(4, &D_800FAB44, arg0);
    block_10:
        M2C_FIELD(arg0, s8*, 4) = 2;
        return;
    }
    func_80030ECC(arg0);
    if (func_8002CBFC(arg0, 0x40, 0x40) == 0) {
        func_8002CCB0(arg0, 0x20, 0x20);
        return;
    }
    M2C_FIELD(arg0, s8*, 4) = 3;
}
