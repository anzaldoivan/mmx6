// prog SLUS_013.95 | system weapon | range 0x8003EC78-0x8003ED94
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/graphics.h"
#include "mmx6/weapon.h"

// 0x8003EC78 update_player_charge: per-frame charge step: on fire input resets the charge, else charges.
// basis: xref derived.tsv:21; xref:caller=charge_special_weapon
// callers: update_player
void update_player_charge(struct X4_PlayerObj* p) {
    s8 t;

    if (p->character != 0) {
        return;
    }
    if (p->nova_strike_active != 0 && p->armor == 4) {
        return;
    }
    t = p->action;
    if (t == 0) {
        return;
    }
    if (t == 1) {
        return;
    }
    if (t == 0x19) {
        return;
    }
    if (t == 0x18) {
        return;
    }
    if (*(s8*)&p->hover_timer != 0) {
        return;
    }
    if (func_8003ED98(p) != 0) {
        player_reset_charge(p);
        {
            s32 a = p->shot_palette_timer;
            if (a != 0) {
                load_player_palette(p, 0x32);
            } else {
                player_load_weapon_palette(p);
            }
        }
        if (p->stock_charge == 1) {
            p->flash_palette = 0x29;
        }
    } else if (!(p->equipped_parts & 0x80000)) {
        charge_special_weapon(p);
        update_special_charge(p);
        if (player_set_charge_flash(p, 0) == 0) {
            player_set_charge_flash(p, 1);
        }
    }
}
