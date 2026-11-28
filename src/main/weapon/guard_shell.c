#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#include "mmx6/globals.h"
#include "mmx6/sound.h"
#include "mmx6/graphics.h"
#include "mmx6/weapon.h"
#define play_sound ((void (*)(s32, s32, void*))play_sound)
#include "mmx6/pilot_globals.h"

// 0x8004548C update_guard_shell: Guard Shell activation and ammo use.
// basis: community tweaks-index.tsv:228
// callers: none known
void update_guard_shell(struct ProjectileObj* arg0) {
    struct X4_PlayerObj* player;
    struct ProjectileObj* child;
    struct X4_WeaponObj* parent;
    s8 kind;
    s32 hp;
    u16 y;
    s32 v;

    ((void (*)())animate_object)();
    if (--*(s8*)&arg0->unk8C.bytes[2] == 0) {
        player = &g_Player;
        kind = 4;
        if (player->character == 0) {
            kind = player->weapon;
        }
        hp = ((s16*)g_Player.weapon_energy)[kind];
        if (hp >= get_weapon_energy_cost(player, kind)) {
            if (player->character != 0) {
                player->weapon = 4;
                use_weapon_energy(player, 4);
            } else {
                use_weapon_energy(player, arg0->id);
            }
            parent = arg0->unk7C;
            arg0->unk8C.bytes[3] = 0;
            child = (struct ProjectileObj*)func_8002BEC4((s8*)parent, 0);
            if (child != 0) {
                play_sound(1, 0x1F, arg0);
                {
                    // !FAKE: depin: dropping it breaks the match (24/146)
                    register s32 one asm("$6") = 1;
                    child->active = one;
                    child->id = 0x35;
                    child->unk2 = 5;
                    child->unk7C = parent;
                    child->unk38 = arg0->unk38;
                    child->unk3C = arg0->unk3C;
                    child->animation_table = arg0->animation_table;
                    child->unk40 = arg0->unk40;
                    child->unk42 = arg0->unk42;
                    child->unk16 = arg0->unk16;
                    child->x_pos.i.hi = arg0->x_pos.i.hi;
                    y = arg0->y_pos.i.hi;
                    child->unk68 = (struct X4_Unk_unk68*)&D_800761A0;
                    child->unk50.data = (const u8*)&D_8007619C;
                    child->on_screen = one;
                    child->state = one;
                    child->action = 4;
                    child->y_pos.i.hi = y;
                    ((void (*)())set_animation)(child, 6, 1, y);
                    if (arg0->unk2 == 1) {
                        v = 0x30000;
                        // !FAKE: goto shares the velocity store tail; duplicating the tail grew the function
                        goto set;
                    }
                    if (arg0->unk2 == 2) {
                        v = -0x30000;
                    set:
                        child->x_vel.val = 0;
                        child->y_vel.val = v;
                    } else if (arg0->unk2 == 3) {
                        child->x_vel.val = -0x30000;
                        child->y_vel.val = 0;
                        // !FAKE: goto shares the velocity store tail; duplicating the tail grew the function
                        goto neg;
                    } else {
                        child->x_vel.val = -0x30000;
                        child->y_vel.val = 0;
                    neg:
                        if (player->facing != 0) {
                            child->x_vel.val = -child->x_vel.val;
                        }
                    }
                }
                parent->ext.raw[0]++;
            }
        }
        if (arg0->unk2 < 3) {
            ((void (*)(void*, s32))set_animation)(arg0, 0);
        } else {
            ((void (*)(void*, s32))set_animation)(arg0, 1);
        }
        *(u8*)&arg0->unk9C &= 0xFD;
        arg0->action--;
    }
}
#undef play_sound
