#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#include "mmx6/sound.h"
#include "mmx6/graphics.h"
#include "mmx6/weapon.h"
#include "mmx6/pilot_globals.h"

// 0x80049270 init_buster_shot_visual: buster shot sfx by shot type.
// basis: community tweaks-index.tsv:214
// callers: update_buster_shot_visual
void init_buster_shot_visual(struct X4_VisualObj* arg0) {
    s32 idx;
    s8 kind;

    kind = arg0->unk2;
    arg0->on_screen = 1;
    if (kind == 9) {
        idx = 0;
    } else if (kind == 18) {
        idx = 1;
    } else if (kind == 20) {
        idx = 2;
    } else if (kind == 0) {
        idx = 3;
    } else if (kind == 19) {
        idx = 2;
    } else if (kind == 45) {
        idx = 3;
    }
    arg0->unk3C =
        (void*)((s8*)SP_SPRITE_FRAMES + SP_SPRITE_FRAMES[D_80077C0C[idx][0]]);
    arg0->animation_table = g_visual_animation_tables;
    arg0->unk40 = 0;
    arg0->unk42 = 0x7802;
    if (idx == 3) {
        if (arg0->unk2 == 0) {
            arg0->unk42 = func_801EE434();
            {
                struct X4_PlayerObj* player = &g_Player;
                if (player->equipped_parts & 0x40000) {
                    arg0->unk42 = 0x7844;
                }
            }
        }
    }
    arg0->unk16 = 0;
    {
        struct X4_PlayerObj* player = &g_Player;
        arg0->unk15 = player->facing;
    }
    arg0->unk5C.value = 0;
    func_800499A0(arg0);
    arg0->x_pos.i.lo = 0;
    arg0->y_pos.i.lo = 0;
    set_animation(arg0, D_80077C0C[idx][1]);
    play_sound(1, D_80077C0C[idx][2], arg0);
    arg0->state++;
    func_8002CCB0(arg0, 0x40, 0x20);
}
