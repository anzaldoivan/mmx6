// prog SLUS_013.95 | system weapon | range 0x8003DBDC-0x8003DD68
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"
#include "mmx6/sound.h"

// 0x8003DBDC switch_weapon: weapon menu-select input.
// basis: community tweaks-index.tsv:221
// callers: update_weapon_switch
void switch_weapon(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    s32 a;
    s32 m;
    u16 h;
    s8 i;

    if (self->move_lock != 0) {
        return;
    }
    if (*(s8*)&self->hover_timer != 0) {
        return;
    }
    if (D_800CCEEC != 0) {
        return;
    }
    h = self->pressed_input;
    m = h & 0x600;
    if (m == 0) {
        return;
    }
    a = self->input.buttons.held & 0x600;
    if (a == 0x600 || m == 0x600) {
        if (self->weapon != 0) {
            self->weapon = 0;
            play_sound(0, 0xC, 0);
        }
    } else {
        i = switch_weapon_weapon_slots[self->weapon];
        if (h & 0x200) {
            do {
                i++;
                if (i == 6) {
                    i = 0;
                    break;
                }
            } while (!(switch_weapon_stage_masks[i] & self->beaten_stages));
        } else {
            do {
                i--;
                if (i < 0) {
                    i = 5;
                }
                if (i == 0) {
                    break;
                }
            } while (!(switch_weapon_stage_masks[i] & self->beaten_stages));
        }
        i = switch_weapon_slot_weapons[i];
        if (i != self->weapon) {
            self->weapon = i;
            play_sound(0, 0xC, 0);
        }
    }
}
