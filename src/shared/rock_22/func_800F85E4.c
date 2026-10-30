#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define F32(p, o) (*(s32*)((u8*)(p) + (o)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();
void* func_8002C458();
M2C_UNK move_object(s32);
extern s16 D_800970AA;
extern s16 D_800970AE;

void func_800F85E4(struct X4_MainObj* self) {
    struct X4_MainObj* o;
    u8 f;

    func_80017A04();
    move_object((s32)self);
    {
        // !FAKE: depin: dropping it breaks the match (146/148)
        register s32 t asm("$2") = self->collision_flags;
        if (t == 0) {
            return;
        }
    }
    {
        o = func_8002C458();
        if (o != 0) {
            o->active = 0x41;
            o->id = 0x1E;
            o->unk2 = 4;
            o->unk42 = self->unk42 & 0x7FFF;
            o->animation_table = self->animation_table;
            o->sprite_frames = self->sprite_frames;
            o->unk40 = self->unk40;
            o->bg_offset = self->bg_offset;
            o->x_pos.i.hi = self->x_pos.i.hi;
            o->y_pos.i.hi = self->y_pos.i.hi;
            o->unk15 = self->unk15;
            F32(o, 0x7C) = F32(self, 0x7C);
        }
        f = self->collision_flags;
        if (f & 8) {
            if (D_800970AA > self->x_pos.i.hi) {
                self->unk15 = 0x40;
                self->x_speed = 0x40000;
            } else {
                self->unk15 = 0;
                self->x_speed = -0x40000;
            }
            self->y_speed = 0;
            set_animation(self, 0x20);
        } else if (f & 4) {
            if (D_800970AA > self->x_pos.i.hi) {
                self->unk15 = 0x40;
                self->x_speed = 0x40000;
            } else {
                self->unk15 = 0;
                self->x_speed = -0x40000;
            }
            self->y_speed = 0;
            set_animation(self, 0x27);
        } else {
            if (f & 2) {
                if (D_800970AE > self->y_pos.i.hi) {
                    self->y_speed = -0x40000;
                    set_animation(self, 0x25);
                } else {
                    self->y_speed = 0x40000;
                    set_animation(self, 0x21);
                }
                self->unk15 = 0;
            } else {
                if (D_800970AE > self->y_pos.i.hi) {
                    self->y_speed = -0x40000;
                    set_animation(self, 0x25);
                } else {
                    self->y_speed = 0x40000;
                    set_animation(self, 0x21);
                }
                self->unk15 = 0x40;
            }
            self->x_speed = 0;
        }
        self->unk6++;
        play_sound(2, 0x6E, self);
    }
}
