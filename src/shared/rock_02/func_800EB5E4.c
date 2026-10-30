#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
M2C_UNK func_80049EBC(void*, M2C_UNK, M2C_UNK, M2C_UNK);
void func_8004E654(void*, s8);
void func_800EBF28(void* arg0);
extern M2C_UNK D_800FAD00;
extern void (*D_800FAD14[])(void*);

void func_800EB5E4(void* arg0) {
    s32 i;
    s32 lim;
    s32 over;

    M2C_FIELD(arg0, s32*, 0x80) = M2C_FIELD(arg0, u8*, 0x47);
    func_800EBF28(arg0);
    D_800FAD14[M2C_FIELD(arg0, s8*, 5)](arg0);
    if (M2C_FIELD(arg0, s8*, 7) == 0) {
        lim = 0xC000;
        over = M2C_FIELD(arg0, s32*, 0x20) > lim;
    } else {
        lim = -0xC000;
        over = M2C_FIELD(arg0, s32*, 0x20) < lim;
    }
    if (over) {
        M2C_FIELD(arg0, s32*, 0x20) = lim;
    }
    if (check_enemy_hits(arg0) < 0) {
        for (i = 0; i < 5; i++) {
            func_80049EBC(arg0, 1, 0x10, 0x10);
        }
        goto block_13;
    }
    if ((M2C_FIELD(arg0, u8*, 0x70) & 0xC) == 0xC) {
        for (i = 0; i < 5; i++) {
            func_80049EBC(arg0, 1, 0x10, 0x10);
        }
    block_13:
        func_800477E4(3, &D_800FAD00, arg0);
        func_8004E654(arg0, 0x14);
        M2C_FIELD(arg0, s8*, 4) = 2;
        return;
    }
    func_80030ECC(arg0);
    if (func_8002CBFC(arg0, 0x80, 0x80) == 0) {
        func_8002CCB0(arg0, 0x60, 0x60);
    } else {
        M2C_FIELD(arg0, s8*, 4) = 3;
    }
    if (M2C_FIELD(arg0, u8*, 0x70) & 8) {
        M2C_FIELD(arg0, s8*, 0x67) = 0;
        return;
    }
    if (M2C_FIELD(arg0, s32*, 0x24) < 0) {
        M2C_FIELD(arg0, s8*, 0x67) = -1;
    } else {
        M2C_FIELD(arg0, s8*, 0x67) = 1;
    }
}
