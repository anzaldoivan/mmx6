// prog SLUS_013.95 | system player | range 0x8003B054-0x8003B110
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 play_sound(s32 a0, s32 a1, void* arg2);
s32 player_check_dash_jump_walk(struct X4_PlayerObj* self);
s32 func_8003A628(void*);
void player_clear_dash();
s32 try_start_attack(void*);
void player_set_animation_shooting(struct X4_PlayerObj* self, s32 animation);
s32 func_801EBE04(void*);
s32 func_801EBE54(void*);

// 0x8003B054 player_land: touchdown: plays a sound, tries dash, jump or walk, else enters landing (action 8).
// basis: xref derived.tsv:109; xref:caller=player_check_dash_jump_walk
// callers: update_fall, update_wall_cling, update_slide_down_let_go, func_80037130, handle_slide_down, end_ceiling_dash, rock_00 update_air_dash, rock_01 func_801EC334
M2C_UNK player_land(void* arg0) {
    play_sound(1, 2, arg0);
    M2C_FIELD(arg0, u8*, 0x67) = 0;
    player_clear_dash(arg0);
    if ((func_8003A628(arg0) == 0) && (try_start_attack(arg0) == 0) &&
        ((M2C_FIELD(arg0, s8*, 2) == 0) || (func_801EBE04(arg0) == 0)) &&
        (player_check_dash_jump_walk(arg0) == 0) &&
        ((M2C_FIELD(arg0, s8*, 2) == 0) || (func_801EBE54(arg0) == 0))) {
        player_set_animation_shooting(arg0, 0xC);
        M2C_FIELD(arg0, u8*, 5) = 8;
        M2C_FIELD(arg0, u8*, 6) = 0;
    }
}
