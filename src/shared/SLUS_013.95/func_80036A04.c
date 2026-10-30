#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
s32 player_check_dash_jump_walk(struct X4_PlayerObj* self);
s32 func_80039C9C(void*);
s32 func_8003A3DC(void*);
s32 func_8003A628(void*);
s32 check_ceiling_jump(void*);
void func_8003ADB4(void* arg0);
s32 func_8003F13C(void*);
M2C_UNK func_8003F508(void*, M2C_UNK);
s32 func_801EBE04(void*);
s32 func_801EBE54(void*);
s32 func_801EBEDC(void*);
s32 func_801EC86C(void*);

void func_80036A04(void* arg0) {
    if ((func_8003A628(arg0) == 0) && (func_8003A3DC(arg0) == 0) &&
        (check_ceiling_jump(arg0) == 0) && (func_8003F13C(arg0) == 0) &&
        ((M2C_FIELD(arg0, s8*, 2) == 0) ||
         ((func_801EC86C(arg0) == 0) && (func_801EBE04(arg0) == 0))) &&
        (player_check_dash_jump_walk(arg0) == 0) &&
        ((M2C_FIELD(arg0, s8*, 2) == 0) ||
         ((func_801EBE54(arg0) == 0) && (func_801EBEDC(arg0) == 0))) &&
        (func_80039C9C(arg0) == 0)) {
        ((void (*)())func_80017A04)(arg0);
        if (M2C_FIELD(arg0, s8*, 0x46) < 0) {
            func_8003ADB4(arg0);
            return;
        }
        func_8003F508(arg0, 0xC);
    }
}
