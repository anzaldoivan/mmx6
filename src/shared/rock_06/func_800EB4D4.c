#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();
s32 is_off_screen(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK move_object(void*);
M2C_UNK func_8002EE10(void*);
s32 func_80030ECC();
s32 check_enemy_hits(void*);
M2C_UNK func_80049D90(void*);

void func_800EB4D4(void* arg0) {
    s32 st;

    ((M2C_UNK(*)())animate_object)();
    move_object(arg0);
    if (func_80030ECC(arg0) != 0) {
        M2C_FIELD(arg0, u8*, 4) = 2;
        return;
    }
    if (check_enemy_hits(arg0) < 0) {
        M2C_FIELD(arg0, u8*, 4) = 2;
        return;
    }
    if (M2C_FIELD(arg0, u8*, 0x70) != 0 ||
        (func_8002EE10(arg0), M2C_FIELD(arg0, u8*, 0x70) != 0)) {
        func_80049D90(arg0);
        M2C_FIELD(arg0, u8*, 4) = M2C_FIELD(arg0, u8*, 4) + 1;
        return;
    }
    if (is_off_screen(arg0, 0x20, 0x20) == 0) {
        func_8002CCB0(arg0, 0x10, 0x10);
        return;
    }
    st = M2C_FIELD(arg0, u8*, 4) + 1;
    M2C_FIELD(arg0, u8*, 4) = st;
}
