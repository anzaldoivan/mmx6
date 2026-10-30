#include "common.h"

#define M2C_UNK s32

M2C_UNK func_80017A04();
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230();
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
M2C_UNK func_80049E50(void*);
M2C_UNK func_8004A2B4(M2C_UNK, M2C_UNK, void*, M2C_UNK, M2C_UNK);

void func_800EB860(u8* arg0) {
    s32 temp_v0;

    temp_v0 = arg0[6] + 1;
    arg0[6] = temp_v0;
    if ((s8)temp_v0 == 8) {
        func_8004A2B4(0, 0, arg0, 0, 1);
        arg0[6] = 0;
    }
    if ((arg0[0x70] != 0) || (check_enemy_hits(arg0) < 0) ||
        (func_80030ECC(arg0) != 0)) {
        func_80049E50(arg0);
        arg0[4] = 2;
        return;
    }
    func_80017A04(arg0);
    func_8002D230(arg0);
    if (func_8002CBFC(arg0, 0x10, 0x10) == 0) {
        func_8002CCB0(arg0, 0x10, 0x10);
        return;
    }
    arg0[4]++;
}
