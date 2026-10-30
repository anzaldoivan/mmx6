#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void set_boss_level();

extern struct X4_EngineObj g_playthrough_state;

void func_800ED904(struct X4_MainObj* self) {
    g_playthrough_state.enable_boss = 1;
    M2C_FIELD(&g_playthrough_state, u8*, 0x8C) = 0x7F;
    set_boss_level(0);
    g_playthrough_state.unk25 = 0;
    g_playthrough_state.boss_ptr = self;
    self->unk7E = 3;
    self->unk6++;
}
