// prog SLUS_013.95 | system movement | range 0x8003DD6C-0x8003DF54
#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"
#include "mmx6/sound.h"
#include "mmx6/weapon.h"
#define M2C_UNK s32

// 0x8003DD6C func_8003DD6C: character 0 weapon switch: both shoulder buttons clear it, one steps the nine slots.
// basis: none
// callers: update_weapon_switch
void func_8003DD6C(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    s32 a;
    s32 m;
    s8 i;
    s8 k;

    if (self->move_lock != 0) {
        return;
    }
    if (self->special_shot_count != 0) {
        return;
    }
    if (*(s8*)&self->hover_timer != 0) {
        return;
    }
    if (self->nova_strike_active != 0) {
        return;
    }
    if (D_800CCEEC != 0) {
        return;
    }
    k = self->action;
    if (k == 0x2D) {
        return;
    }
    if (k == 0x2E) {
        return;
    }
    if (k == 0x2F) {
        return;
    }
    if (k == 0x4C) {
        return;
    }
    a = self->input.buttons.held & 0x600;
    m = self->pressed_input & 0x600;
    if (a == 0x600 || m == 0x600) {
        if (self->weapon != 0) {
            self->weapon = 0;
            player_reset_charge(self);
            play_sound(0, 0xC, 0);
        }
    } else if (m != 0) {
        i = D_80073EF0[self->weapon];
        if (m & 0x200) {
            do {
                i++;
                if (i == 9) {
                    i = 0;
                    break;
                }
            } while (!(D_80073ED8[i] & self->beaten_stages));
        } else {
            do {
                i--;
                if (i < 0) {
                    i = 8;
                }
                if (i == 0) {
                    break;
                }
            } while (!(D_80073ED8[i] & self->beaten_stages));
        }
        i = D_80073EE4[i];
        if (self->weapon != i) {
            self->weapon = i;
            player_reset_charge(self);
            play_sound(0, 0xC, 0);
        }
    }
}
