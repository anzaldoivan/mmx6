#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
extern M2C_UNK D_800F9080;

void func_800F4E4C(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    s32 v;

    if (M2C_FIELD(self, s8*, 0x45) != 0) {
        play_sound(2, 0x5F, arg0);
        v = 0x40000;
        if (self->unk15 == 0) {
            v = 0xFFFC0000;
        }
        self->x_vel.val = v;
        self->unk68 = (void*)&D_800F9080;
        {
            s32 t = 1;
            M2C_FIELD(self, s8*, 0x8E) = t;
            t = 0x32;
            self->input.buttons.held = t;
        }
        self->unk28 = 0;
        self->y_vel.val = 0;
        self->unk2C = 0;
        self->y_pos.u.hi += 0x1C;
        self->unk6 += 1;
    }
}
