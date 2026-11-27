// rolefeed (3.1 T4): func_800F01FC of src/rock_05/E9860.c
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK clear_object_slot();
extern struct X4_PlayerObj g_Player;

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK start_pad_vibration(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
s32 random_byte();
extern struct X4_BackgroundObj background_objects[3];
extern s16 D_800F4480;

void func_800F01FC(struct X4_MainObj* self) {
    if (self->unk7C != 0) {
        self->unk7C--;
        return;
    }
    if (!(D_80097420.frame_counter & 1)) {
        background_objects[0].y_pos.u.hi += 2;
    } else {
        background_objects[0].y_pos.u.hi -= 2;
    }
    if (self->unk7E != 0) {
        if (self->unk7E == 3) {
            play_sound(2, 0x24, self);
        }
        self->unk7E--;
        self->action_phase++;
        play_sound(2, 0xF, self);
        start_pad_vibration(3);
        if (random_byte() & 1) {
            self->y_pos.u.hi = D_800F4480 + 0x450;
            return;
        }
        self->y_pos.u.hi = D_800F4480 + 0x3F0;
        return;
    }
    self->action_phase = 5;
    func_80029478(1, 4, 2);
}
