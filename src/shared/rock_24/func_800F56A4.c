#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
M2C_UNK func_80030ECC(void*, s16);
#define func_80030ECC ((M2C_UNK(*)(void*))func_80030ECC)
s32 func_80031474(void*);
M2C_UNK func_80049E50(void*);
extern s32 D_800F77D8;
extern s32 D_800F77DC;

void func_800F56A4(s8* arg0) {
    if (D_800F77D8 != 0 || D_800F77DC != 0) {
        arg0[4]++;
        return;
    }
    if (func_80031474(arg0) < 0) {
        func_80049E50(arg0);
        arg0[4]++;
        return;
    }
    if (++((s32*)arg0)[0x23] == 0x96) {
        arg0[4]++;
        return;
    }
    if (func_80030ECC(arg0) != 0) {
        func_80049E50(arg0);
        arg0[4]++;
        return;
    }
    func_8002CCB0(arg0, 0x10, 0x10);
    func_80017A04(arg0);
    func_8002D230(arg0);
}
#undef func_80030ECC
