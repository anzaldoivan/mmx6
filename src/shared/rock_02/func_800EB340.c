#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
M2C_UNK move_object(s32);
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002EE10(void*);
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
M2C_UNK func_80049E50(void*);

void func_800EB340(void* arg0) {
    func_80017A04();
    ((void (*)(void*))move_object)(arg0);
    if (func_80030ECC(arg0) != 0) {
    block_1:
        func_80049E50(arg0);
    } else {
        if (check_enemy_hits(arg0) < 0) {
            goto block_1;
        }
        if (M2C_FIELD(arg0, u8*, 0x70) != 0) {
            goto block_1;
        }
        func_8002EE10(arg0);
        if (M2C_FIELD(arg0, u8*, 0x70) != 0) {
            goto block_1;
        }
        if (func_8002CBFC(arg0, 0x20, 0x20) == 0) {
            func_8002CCB0(arg0, 0x10, 0x10);
            return;
        }
    }
    M2C_FIELD(arg0, u8*, 4) = 2;
}
