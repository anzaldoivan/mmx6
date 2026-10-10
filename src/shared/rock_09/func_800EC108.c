#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
s32 func_80030ECC(void*);
s32 func_80031474(void*);
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
M2C_UNK func_80049E50(void*);
void func_8004E654(struct X4_BaseObj* arg0, s8 arg1);
void func_800ECAA0(struct X4_MainObj*);
extern u8 D_800F4BF0[];

void func_800EC108(void* arg0) {
    u8 i;
    s32 r;
    u8 t;
    s32 v;

    M2C_FIELD(arg0, s32*, 0x18) = M2C_FIELD(arg0, s32*, 8);
    M2C_FIELD(arg0, s32*, 0x1C) = M2C_FIELD(arg0, s32*, 0xC);
    ((void (**)(void*))(D_800F4BF0 + 0x13D8))[M2C_FIELD(arg0, s8*, 5)](arg0);
    t = func_80030ECC(arg0);
    if (M2C_FIELD(arg0, s8*, 2) == 4 && t == 1) {
        M2C_FIELD(arg0, s8*, 5) = 8;
        M2C_FIELD(arg0, s8*, 6) = 0;
    }
    if (M2C_FIELD(arg0, s8*, 5) != 0) {
        M2C_FIELD(arg0, s32*, 0x94) = M2C_FIELD(arg0, s8*, 5);
    }
    for (i = 0; i < 2 - M2C_FIELD(arg0, s32*, 0x88); i++) {
        M2C_FIELD(arg0, s32*, 0x54) = ((s32*)(D_800F4BF0 + 0x13D0))[i];
        r = func_80031474(arg0);
        if (r < 0) {
            if (i == 0 && M2C_FIELD(arg0, s32*, 0x88) == 0) {
                func_800ECAA0((struct X4_MainObj*)arg0);
            }
            func_80049E50(arg0);
            func_800477E4(4, (M2C_UNK*)(D_800F4BF0 + 0x13BC), arg0);
            func_8004E654((struct X4_BaseObj*)arg0, 0x14);
            v = M2C_FIELD(arg0, u8*, 4) + 1;
            goto store;
        }
        if (r != 0) {
            break;
        }
    }
    if (func_8002CBFC(arg0, 0x20, 0x20) == 0) {
        func_8002CCB0(arg0, 0x20, 0x20);
        return;
    }
    v = 3;
store:
    M2C_FIELD(arg0, u8*, 4) = v;
}
