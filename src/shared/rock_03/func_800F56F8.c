// rolefeed (3.1 T4): func_800F56F8 of src/rock_03/E9860.c

#include "common.h"
extern s32 D_800F7DE4;
extern s32 D_800F7DE8;
extern s32 D_800F7E30;
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK apply_object_motion(void*);
s32 func_80030ECC();
s32 check_enemy_hits(void*);
M2C_UNK func_80049E50(void*);

void func_800F56F8(void* arg0) {
    if (D_800F7DE4 != 0 || D_800F7DE8 != 0 || D_800F7E30 != 0) {
        M2C_FIELD(arg0, u8*, 4) = 2;
    } else if (M2C_FIELD(arg0, u8*, 0x70) != 0 || check_enemy_hits(arg0) < 0 ||
               func_80030ECC(arg0) != 0) {
        func_80049E50(arg0);
        M2C_FIELD(arg0, u8*, 4) = 2;
    } else {
        animate_object(arg0);
        apply_object_motion(arg0);
        func_8002CCB0(arg0, 0x10, 0x10);
    }
}
