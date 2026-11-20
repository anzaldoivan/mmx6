// rolefeed (3.1 T4): func_800F5764 of src/rock_07/E9860.c
#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

#include "mmx6/x4.h"

M2C_UNK start_pad_vibration(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
extern struct X4_BackgroundObj background_objects[3];

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
void func_800F6880(void* arg0, u8 arg1, s16 arg2, s16 arg3);
void func_800F9084();

void func_800F5764(struct X4_MainObj* self) {
    s8 t;
    s32 v;
    s32 w;

    if (!(D_80097420.frame_counter & 3)) {
        func_800F6880(self, 0x10, self->x_pos.i.hi, self->y_pos.u.hi + 0x30);
    }
    t = self->animation_step.fields.event;
    if (t == 1) {
        set_animation(self, 0x21);
        v = 4;
        self->contact_damage = v;
        v = 0xB4;
        self->unk7E = v;
        v = (s32)func_800F9084;
        self->terrain_box = (void*)v;
        v = self->y_pos.u.hi;
        w = 0x5A;
        self->unk7C = w;
        w = (u8)self->action_phase;
        self->on_screen = 0;
        *((u8*)self + 0x8D) = t;
        self->y_pos.u.hi = v + 0x20;
        self->action_phase = w + 1;
    }
}
