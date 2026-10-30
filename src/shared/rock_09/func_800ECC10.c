#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
M2C_UNK func_8002EE10(void*);
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
M2C_UNK func_80049E50(void*);

void func_800ECC10(void* arg0) {
    s32 var_v0;

    ((M2C_UNK(*)())func_80017A04)();
    func_8002D230(arg0);
    if (check_enemy_hits(arg0) < 0) {
        func_80049E50(arg0);
        goto block_9;
    }
    if (func_80030ECC(arg0) != 0) {
        func_80049E50(arg0);
        var_v0 = 2;
        goto block_10;
    }
    if (M2C_FIELD(arg0, u8*, 0x70) != 0 ||
        (func_8002EE10(arg0), M2C_FIELD(arg0, u8*, 0x70) != 0)) {
        M2C_FIELD(arg0, u16*, 0xE) += 0x20;
        func_80049E50(arg0);
        goto block_9;
    }
    if (func_8002CBFC(arg0, 0x20, 0x20) == 0) {
        func_8002CCB0(arg0, 0x10, 0x10);
        return;
    }
block_9:
    var_v0 = M2C_FIELD(arg0, u8*, 4) + 1;
block_10:
    M2C_FIELD(arg0, u8*, 4) = var_v0;
}
