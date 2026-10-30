#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK move_object(s32);
extern struct X4_BackgroundObj background_objects[3];

#define OFS_X(p) (((s16*)(p))[0x48])
#define OFS_Y(p) (((s16*)(p))[0x49])

void func_800F6D58(struct X4_AnimatedObj* self) {
    s32 angle;
    s32 d;
    s32 off;
    s32 st;
    s32 v;

    angle = ratan2(
        self->y_pos.i.hi - (background_objects[0].y_pos.i.hi + OFS_Y(self)),
        (background_objects[0].x_pos.i.hi + OFS_X(self)) - self->x_pos.i.hi);
    self->x_vel.val = (rcos(angle) << 4) * (self->unk7 / 2 + 6);
    self->y_vel.val = (rsin(angle) << 4) * (self->unk7 / 2 + 6);
    if (self->x_vel.val >= 0) {
        self->unk15 = 0x40;
    } else {
        self->unk15 = 0;
    }
    move_object(self);
    {
        // !FAKE: depin: dropping it breaks the match (120/123)
        register struct X4_BackgroundObj* bg asm("$2") = background_objects;
        d = self->x_pos.i.hi - bg->x_pos.i.hi;
    }
    off = OFS_X(self);
    v = off - d;
    if (v >= 0) {
        if (v < 6) {
            goto check_y;
        }
    } else if (d - off < 6) {
    check_y:
        off = OFS_Y(self);
        d = self->y_pos.i.hi - background_objects[0].y_pos.i.hi;
        v = off - d;
        if (v >= 0) {
            if (v < 6) {
                goto arrive;
            }
        } else if (d - off < 6) {
        arrive:
            self->x_pos.i.hi = background_objects[0].x_pos.i.hi + OFS_X(self);
            self->y_pos.i.hi = background_objects[0].y_pos.i.hi + OFS_Y(self);
            self->unk7++;
            if (self->unk7 >= 7) {
                self->unk7 = 0;
                st = (u8)self->unk6 + 1;
            } else {
                play_sound(2, 0x55, self);
                func_80012D9C(6);
                st = (u8)self->unk6;
                st--;
            }
            self->unk6 = st;
        }
    }
}

#undef OFS_X
#undef OFS_Y
