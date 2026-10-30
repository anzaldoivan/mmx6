#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
s32 get_reploid_status(s32);
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj g_playthrough_state;
extern u16 D_800F1688[][2];

void func_800EFAB4(struct X4_AnimatedObj* self) {
    u16 x;

    x = D_800F1688[self->unk2][0];
    self->x_pos.i.hi = x;
    self->y_pos.i.hi = D_800F1688[self->unk2][1];
    if (background_objects[self->bg_offset].x_pos.i.hi < 0x400) {
        self->x_pos.i.hi = x - 0x600;
    }
    func_8002CCB0(self, 0x40, 0x10);
    if (get_reploid_status(g_playthrough_state.character_state.bytes[5] * 16 +
                      self->unk2) >= 2) {
        self->animation_step.fields.frame_index =
            self->unk2 + g_playthrough_state.character_state.bytes[5] * 16;
        return;
    }
    self->on_screen = 0;
}
