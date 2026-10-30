#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
extern struct X4_EngineObj g_playthrough_state;
extern u16 D_800F128C[][2];

void func_800EE744(struct X4_AnimatedObj* self) {
    func_80017A04();
    if (g_playthrough_state.character_state.bytes[3] != self->unk7) {
        self->x_pos.i.hi =
            D_800F128C[g_playthrough_state.character_state.bytes[3]][0] + 0x600;
        self->y_pos.i.hi =
            D_800F128C[g_playthrough_state.character_state.bytes[3]][1];
        set_animation(self, g_playthrough_state.character_state.bytes[3]);
        self->unk7 = g_playthrough_state.character_state.bytes[3];
    }
    func_8002CCB0(self, 0xA0, 0x10);
}
