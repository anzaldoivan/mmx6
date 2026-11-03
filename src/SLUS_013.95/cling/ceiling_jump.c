// prog SLUS_013.95 | system cling | range 0x8003649C-0x800365D0
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/movement.h"
#include "mmx6/pilot_globals.h"
#include "mmx6/sound.h"
#include "mmx6/weapon.h"

// 0x8003649C perform_ceiling_jump: ceiling jump execution; duration per character.
// basis: community tweaks-index.tsv:193
// callers: none known
void perform_ceiling_jump(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    struct X4_Unk_unk68* p;

    if (self->latched_collision_flags & 4) {
        if (self->collision_flags & 4) {
            p = self->terrain_box;
            if ((((s32(*)())func_80030304)(arg0, self->x_pos.i.hi,
                                           self->y_pos.i.hi + p->unk1 -
                                               p->unk3 - 8) &
                 0xFF) == 0x39) {
                func_8003AFF4((s32)arg0);
                return;
            }
        }
        play_sound(1, 4, arg0);
        player_set_animation(arg0, 0x53);
        self->action_phase = 2;
        if (self->character != 0) {
            self->action_timer = 0x78;
            return;
        }
        self->action_timer = -0x4C;
        return;
    }
    *(u8*)&self->action_timer += 1;
    move_by_velocity(arg0);
    animate_object(arg0);
    func_8003F508(arg0, 0xA);
    if (((self->y_vel.val * self->action_timer) >> 0x10) >= 0x90) {
        self->action_timer = 5;
        *(u8*)&self->action_phase += 1;
        player_set_animation(arg0, 0xB);
    }
}
