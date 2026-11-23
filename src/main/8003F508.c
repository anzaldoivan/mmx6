#include "common.h"
#define M2C_UNK s32

M2C_UNK player_set_animation_frame(void*, M2C_UNK, s8);

M2C_UNK func_8003F508(void* arg0, M2C_UNK arg1) {
    u8* p = arg0;
    s32 var_a1;
    s8 temp_s0;

    if (*(s8*)(p + 2) == 0) {
        var_a1 = arg1 + 0x70;
        if (*(s8*)(p + 0x90) != 0) {
            temp_s0 = *(s8*)(p + 0x44);
            player_set_animation_frame(arg0, arg1, p[0x45] & 0x3F);
            *(s8*)(p + 0x44) = temp_s0;
        } else if (*(s8*)(p + 0x8E) != 0 && p[0x17] != var_a1) {
            temp_s0 = *(s8*)(p + 0x44);
            player_set_animation_frame(p, var_a1, p[0x45] & 0x3F);
            *(s8*)(p + 0x44) = temp_s0;
        }
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

void silence_sound(u8, u8);
void player_load_weapon_palette(struct X4_PlayerObj* self);
void clear_flash_palette(void* arg0);
extern struct X4_PlayerObj g_Player;

M2C_UNK func_8003F58C(void) {
    struct X4_PlayerObj* pl = &g_Player;

    if (!(D_800CCF99 & 1) || (pl->weapon != 0)) {
        if (!(pl->input.buttons.held & 0x10)) {
            pl->charge_state[0] = 0;
            pl->charge_timer = 0;
        }
        if (!(pl->input.buttons.held & 0x20)) {
            pl->charge_state[1] = 0;
            pl->special_charge_timer = 0;
        }
        if (!(*(s32*)&pl->charge_state[1] & 0xFFFF00)) {
            silence_sound(1, 7);
            clear_flash_palette(pl);
            pl->charge_state[0] = 0;
            pl->charge_state[1] = 0;
            pl->charge_timer = 0;
            pl->special_charge_timer = 0;
            player_load_weapon_palette(pl);
        }
    }
}
