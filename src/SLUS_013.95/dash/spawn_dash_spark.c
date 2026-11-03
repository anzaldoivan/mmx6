// prog SLUS_013.95 | system dash | range 0x8003C6A4-0x8003C7D4
#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"
#include "addr.h" /* g_sp_sprite_frames */
#include "mmx6/collision.h"
#include "mmx6/dash.h"
#include "mmx6/effect.h"
#include "mmx6/movement.h"

// 0x8003C6A4 player_spawn_dash_spark: spawns the spark visual offset from dash_spark_offsets by variant, or calls spawn_dash_tile24_visual when the tile below is 0x24.
// basis: x4 5698b541d539
// callers: none known
void player_spawn_dash_spark(void* arg0) {
    struct X4_VisualObj* self = arg0;
    struct X4_VisualObj* obj;
    u8 f;
    s32* t;
    s32 o;

    if (get_tile_attr_bottom() == 0x24) {
        spawn_dash_tile24_visual(self);
        return;
    }
    obj = find_free_visual_obj();
    if (obj != 0) {
        obj->active = 0x21;
        obj->id = 3;
        obj->unk2 = 2;
        obj->state = 0;
        obj->unk5 = 0;
        obj->unk6 = 0;
        obj->bg_offset = self->bg_offset;
        obj->unk38 = 0;
        t = g_sp_sprite_frames;
        o = t[1];
        obj->animation_table = g_visual_animation_tables;
        obj->unk40 = 0;
        obj->unk42 = 0x7804;
        obj->unk16 = 1;
        obj->unk3C = (void*)((s8*)t + o);
        f = self->unk15;
        obj->unk15 = f;
        if (f == 0) {
            obj->x_pos.i.hi =
                self->x_pos.i.hi + dash_spark_offsets[self->unk2].x;
        } else {
            obj->x_pos.i.hi =
                self->x_pos.i.hi - dash_spark_offsets[self->unk2].x;
        }
        obj->y_pos.i.hi = self->y_pos.i.hi + dash_spark_offsets[self->unk2].y;
    }
}
