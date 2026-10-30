#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
s32 func_80030ECC(void*);
s32 check_enemy_hits(void*);
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
M2C_UNK func_80049E50(void*);
void func_8004E654(struct X4_BaseObj* arg0, s8 arg1);
void func_800EA7CC(void*);
extern M2C_UNK D_8007433C;
extern M2C_UNK D_800743DC;
extern s32 D_800970A8;
extern u8 D_800F4BF0[];

void func_800E9D64(void* arg0) {
    s32 r;

    if (M2C_FIELD(arg0, u8*, 0x47) == 0) {
        M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
    } else {
        M2C_FIELD(arg0, void**, 0x58) = &D_800743DC;
    }
    M2C_FIELD(arg0, s32*, 0x18) = M2C_FIELD(arg0, s32*, 8);
    M2C_FIELD(arg0, s32*, 0x1C) = M2C_FIELD(arg0, s32*, 0xC);
    ((void (**)(void*))(D_800F4BF0 + 0xF64))[M2C_FIELD(arg0, s8*, 5)](arg0);
    if ((u32)(M2C_FIELD(arg0, u8*, 5) - 2) >= 2U) {
        if (M2C_FIELD(arg0, s32*, 8) > D_800970A8) {
            M2C_FIELD(arg0, u8*, 0x15) = 0;
        } else {
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        }
    }
    func_800EA7CC(arg0);
    r = check_enemy_hits(arg0);
    if (r < 0) {
        func_80049E50(arg0);
        func_800477E4(4, (M2C_UNK*)(D_800F4BF0 + 0xF50), arg0);
        func_8004E654((struct X4_BaseObj*)arg0, 0x15);
        M2C_FIELD(arg0, u8*, 4) = 2;
        return;
    }
    if (r == 0x7F) {
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
    }
    if ((M2C_FIELD(arg0, u8*, 0x70) & 0xC) == 0xC) {
        func_80049E50(arg0);
        func_800477E4(4, (M2C_UNK*)(D_800F4BF0 + 0xF50), arg0);
        func_8004E654((struct X4_BaseObj*)arg0, 0x15);
        M2C_FIELD(arg0, u8*, 4) = 2;
    } else {
        func_80030ECC(arg0);
        if (func_8002CBFC(arg0, 0x40, 0x40) == 0) {
            func_8002CCB0(arg0, 0x20, 0x20);
            return;
        }
        M2C_FIELD(arg0, u8*, 4) = 3;
    }
}
