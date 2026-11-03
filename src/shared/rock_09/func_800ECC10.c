#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();
s32 is_off_screen(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK apply_object_motion(void*);
M2C_UNK func_8002EE10(void*);
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
M2C_UNK func_80049E50(void*);

void func_800ECC10(void* arg0) {
    s32 var_v0;

    ((M2C_UNK(*)())animate_object)();
    apply_object_motion(arg0);
    if (check_enemy_hits(arg0) < 0) {
        func_80049E50(arg0);
        // !FAKE: goto keeps the shared tail block order; inlining or duplicating the tail moved bytes
        goto block_9;
    }
    if (func_80030ECC(arg0) != 0) {
        func_80049E50(arg0);
        var_v0 = 2;
        // !FAKE: goto keeps the shared tail block order; inlining or duplicating the tail moved bytes
        goto block_10;
    }
    if (M2C_FIELD(arg0, u8*, 0x70) != 0 ||
        (func_8002EE10(arg0), M2C_FIELD(arg0, u8*, 0x70) != 0)) {
        M2C_FIELD(arg0, u16*, 0xE) += 0x20;
        func_80049E50(arg0);
        // !FAKE: goto keeps the shared tail block order; inlining or duplicating the tail moved bytes
        goto block_9;
    }
    if (is_off_screen(arg0, 0x20, 0x20) == 0) {
        func_8002CCB0(arg0, 0x10, 0x10);
        return;
    }
block_9:
    var_v0 = M2C_FIELD(arg0, u8*, 4) + 1;
block_10:
    M2C_FIELD(arg0, u8*, 4) = var_v0;
}
