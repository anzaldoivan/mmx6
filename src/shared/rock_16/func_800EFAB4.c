#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
s32 func_8004FF4C(s32);
extern struct X4_BackgroundObj D_800971F8[3];
extern struct X4_EngineObj D_800CCED0;
extern u16 D_800F1688[][2];

void func_800EFAB4(struct X4_AnimatedObj* self) {
    u16 x;

    x = D_800F1688[self->unk2][0];
    self->x_pos.i.hi = x;
    self->y_pos.i.hi = D_800F1688[self->unk2][1];
    if (D_800971F8[self->bg_offset].x_pos.i.hi < 0x400) {
        self->x_pos.i.hi = x - 0x600;
    }
    func_8002CCB0(self, 0x40, 0x10);
    if (func_8004FF4C(D_800CCED0.character_state.bytes[5] * 16 + self->unk2) >=
        2) {
        self->animation_step.fields.frame_index =
            self->unk2 + D_800CCED0.character_state.bytes[5] * 16;
        return;
    }
    self->on_screen = 0;
}
