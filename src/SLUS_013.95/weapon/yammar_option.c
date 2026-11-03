#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#include "mmx6/globals.h"
#include "mmx6/graphics.h"
#include "mmx6/weapon.h"
#define set_animation ((void (*)(void*, s32))set_animation)
#define func_80017B04 func_80017B04
#include "mmx6/pilot_globals.h"

#define SCRATCH_14_TBL (*(s32**)0x1F800014)

// 0x80043638 init_yammar_option: Yammar Option fireflies; ammo.
// basis: community tweaks-index.tsv:223
// callers: none known
void init_yammar_option(struct X4_WeaponObj* arg0) {
    struct X4_PlayerObj* player;
    struct ProjectileObj* child;
    s32 i;
    s32 next;
    s32 hp;
    s32* q;

    player = &g_Player;
    if (arg0->unk2 == 0) {
        i = 0;
        *(s16*)&arg0->unk94 = 0x1000;
        arg0->ext.raw[1] = 1;
        arg0->ext.raw[0] = 3;
        do {
            child = (struct ProjectileObj*)func_8002BEC4((s8*)arg0, 0);
            next = i + 1;
            if (child != 0) {
                child->active = 1;
                child->id = arg0->id;
                child->unk2 = next;
                child->unk7C = arg0;
            }
            if (i != 0) {
                if (arg0->id != 10) {
                    hp = player->weapon_energy[player->weapon];
                    if (hp >= get_weapon_energy_cost(player, player->weapon)) {
                        use_weapon_energy(player, arg0->id);
                    }
                }
                arg0->ext.raw[1] |= 1 << i;
            }
            i = next;
        } while (i < 3);
        arg0->state++;
        if (player->character != 0) {
            arg0->previous_animation_index = 0xFF;
            arg0->animation_step.fields.frame_index = 0;
            arg0->unk49 = 1;
            q = SCRATCH_14_TBL;
            arg0->unk38 = (u8*)q + q[4];
            func_80017B04(arg0, 0x140, 0x40);
            load_buffered_palette(0x51, 0x19, 1);
        }
        return;
    }
    arg0->on_screen = 1;
    if (player->character != 0) {
        s32* p = SCRATCH_14_TBL;
        s32* q;
        s32 off;
        arg0->unk38 = (u8*)p + p[4];
        q = SP_SPRITE_FRAMES;
        off = q[9];
        arg0->unk40 = 0x540;
        arg0->unk42 = 0x7849;
        arg0->unk3C = (u8*)q + off;
    } else {
        s32* p = SCRATCH_14_TBL;
        s32* q;
        s32 off;
        arg0->unk38 = (u8*)p + p[2];
        q = SP_SPRITE_FRAMES;
        off = q[10];
        arg0->unk40 = 0x520;
        arg0->unk42 = 0x7801;
        arg0->unk3C = (u8*)q + off;
    }
    arg0->animation_table = (u32**)D_800779C0;
    arg0->unk16 = 0;
    arg0->unk15 = player->facing;
    arg0->unk64 = 1;
    arg0->x_pos.i.hi = player->x_pos.i.hi;
    arg0->y_pos.i.hi = player->y_pos.i.hi;
    set_animation(arg0, 0);
    arg0->unk5 = 1;
    arg0->state++;
}
#undef set_animation
#undef func_80017B04
#undef SCRATCH_14_TBL
