#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_80030ECC();
s32 check_enemy_hits(void*);
M2C_UNK func_80049E50(void*);
extern void (*D_800F97B0[])(void*);

void func_800F37DC(void* arg0) {
    s8 st;
    s32 t;

    st = M2C_FIELD(M2C_FIELD(arg0, void**, 0x7C), s8*, 4);
    if (st != 1) {
        M2C_FIELD(arg0, s8*, 4) = 2;
        M2C_FIELD(arg0, s8*, 3) = 0;
        return;
    }
    M2C_FIELD(arg0, s32*, 0x18) = M2C_FIELD(arg0, s32*, 0x8);
    M2C_FIELD(arg0, s32*, 0x1C) = M2C_FIELD(arg0, s32*, 0xC);
    if (M2C_FIELD(arg0, s8*, 0x94) == 0) {
        func_80017A04(arg0);
    }
    D_800F97B0[M2C_FIELD(arg0, s8*, 5)](arg0);
    if (M2C_FIELD(arg0, s8*, 4) != st) {
        M2C_FIELD(arg0, s8*, 3) = 0;
        return;
    }
    if ((M2C_FIELD(arg0, s8*, 2) & 0xF0) != 0x30 &&
        check_enemy_hits(arg0) < 0) {
        goto kill;
    }
    if (func_80030ECC(arg0) != 0) {
        t = M2C_FIELD(arg0, s8*, 2) & 0xF0;
        if (t == 0 || t == 0x40) {
        kill:
            M2C_FIELD(arg0, s8*, 3) = 0;
            func_80049E50(arg0);
            M2C_FIELD(arg0, s8*, 4) = 2;
            return;
        }
    }
    switch (M2C_FIELD(arg0, s8*, 2) & 0xF0) {
    case 0x0:
    case 0x10:
        if (func_8002CBFC(arg0, 0x30, 0x30) != 0) {
            M2C_FIELD(arg0, s8*, 4) = 2;
            return;
        }
    case 0x20:
        func_8002CCB0(arg0, 0x10, 0x10);
        return;
    case 0x40:
    case 0x50:
        if (func_8002CBFC(arg0, 0x30, 0x30) == 1) {
            M2C_FIELD(arg0, s8*, 4) = 2;
        }
        break;
    }
}
