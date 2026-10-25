#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_80016C48(s32 a0, s32 a1, void* arg2);
s32 player_check_dash_jump_walk(struct X4_PlayerObj* self);
s32 func_8003A628(void*);
M2C_UNK func_8003CD9C();
s32 func_8003F13C(void*);
void player_set_animation_shooting(struct X4_PlayerObj* self, s32 animation);
s32 func_801EBE04(void*);
s32 func_801EBE54(void*);

M2C_UNK func_8003B054(void* arg0) {
    func_80016C48(1, 2, arg0);
    M2C_FIELD(arg0, u8*, 0x67) = 0;
    func_8003CD9C(arg0);
    if ((func_8003A628(arg0) == 0) && (func_8003F13C(arg0) == 0) &&
        ((M2C_FIELD(arg0, s8*, 2) == 0) || (func_801EBE04(arg0) == 0)) &&
        (player_check_dash_jump_walk(arg0) == 0) &&
        ((M2C_FIELD(arg0, s8*, 2) == 0) || (func_801EBE54(arg0) == 0))) {
        player_set_animation_shooting(arg0, 0xC);
        M2C_FIELD(arg0, u8*, 5) = 8;
        M2C_FIELD(arg0, u8*, 6) = 0;
    }
}
