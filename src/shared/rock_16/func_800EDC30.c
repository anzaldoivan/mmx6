#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_8002CB50();
extern struct X4_EngineObj g_playthrough_state;
extern u16 D_800F10F8[][2];

void func_800EDC30(struct X4_AnimatedObj* self) {
    self->x_pos.i.hi =
        D_800F10F8[g_playthrough_state.character_state.bytes[1]][0];
    self->y_pos.i.hi =
        D_800F10F8[g_playthrough_state.character_state.bytes[1]][1];
    if (g_playthrough_state.character_state.bytes[0] != 0) {
        set_animation(self, 4);
        self->unk6++;
    }
    func_8002CB50(self);
}
