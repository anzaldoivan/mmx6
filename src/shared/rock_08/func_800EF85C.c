#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8002D230(s32);
s32 random_byte();
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
M2C_UNK func_80049E50(void*);

extern s32 D_80097420;
extern M2C_UNK D_800F5D40;
extern M2C_UNK D_800F5D44;

void func_800EF85C(struct X4_MainObj* self) {
    func_8002D230(self);
    if (!(D_80097420 & 0x1F)) {
        play_sound(2, 0x53, self);
    }
    if (!(self->collision_flags & 8)) {
        self->unk6 = 2;
        self->y_speed = 0;
        self->gravity = 0x2000;
    } else {
        self->y_speed = 0;
        self->gravity = 0;
    }
    if ((self->collision_flags & 1) || (self->collision_flags & 2)) {
        if (++*(s16*)&self->ext >= 0x3C) {
            func_80049E50(self);
            if (random_byte() & 1) {
                func_800477E4(2, &D_800F5D40, self);
            } else {
                func_800477E4(2, &D_800F5D44, self);
            }
            self->state = 2;
        }
    }
}
