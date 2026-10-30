#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation_frame(void*, M2C_UNK, s8);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
s32 get_reploid_status(s32);
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj g_playthrough_state;
extern u16 D_800F1688[][2];

void func_800EFB94(struct X4_AnimatedObj* self) {
    s32 x;
    // !FAKE: depin: dropping it breaks the match (60/75)
    register s32 t asm("$3");

    ((void (*)(void*, s32, s32))set_animation_frame)(
        self, 2,
        get_reploid_status(g_playthrough_state.character_state.bytes[5] * 16 +
                      self->unk2));
    t = D_800F1688[self->unk2][0];
    x = t + 0x59;
    self->x_pos.i.hi = x;
    self->y_pos.i.hi = D_800F1688[self->unk2][1];
    t = self->bg_offset;
    if (background_objects[t].x_pos.i.hi < 0x400) {
        self->x_pos.i.hi = x - 0x600;
    }
    switch (get_reploid_status(g_playthrough_state.character_state.bytes[5] * 16 +
                          self->unk2)) {
    case 0:
    case 1:
        self->unk42 = 0x7905;
        break;
    case 2:
        self->unk42 = 0x788E;
        break;
    case 3:
        self->unk42 = 0x7904;
        break;
    case 4:
        self->unk42 = 0x7906;
        break;
    }
    func_8002CCB0(self, 0x20, 0x10);
}
