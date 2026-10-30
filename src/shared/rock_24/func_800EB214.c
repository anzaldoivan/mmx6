#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80017A04();
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_80030ECC(void*, s16);
#define func_80030ECC ((M2C_UNK(*)(void*))func_80030ECC)
s32 check_enemy_hits(void*);
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
M2C_UNK func_80049E50(void*);
void func_8004E654(struct X4_BaseObj* arg0, s8 arg1);
extern M2C_UNK D_800F6744;
extern void (*D_800F675C[])(s8*);

void func_800EB214(s8* arg0) {
    ((s32*)arg0)[6] = ((s32*)arg0)[2];
    ((s32*)arg0)[7] = ((s32*)arg0)[3];
    func_80017A04();
    D_800F675C[arg0[5]](arg0);
    if (check_enemy_hits(arg0) < 0) {
        func_800477E4(3, &D_800F6744, arg0);
        func_80049E50(arg0);
        func_8004E654((struct X4_BaseObj*)arg0, 0x12);
        if (arg0[2] != 0) {
            arg0[4] = 4;
        } else {
            arg0[4] = 2;
        }
        return;
    }
    func_80030ECC(arg0);
    if (func_8002CBFC(arg0, 0xA0, 0xA0) == 0) {
        func_8002CCB0(arg0, 0x30, 0x30);
        return;
    }
    if (arg0[2] != 0) {
        arg0[4] = 4;
    } else {
        arg0[4] = 3;
    }
}
#undef func_80030ECC
