#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void set_boss_level();
s32 func_80027BA0(s32 arg0, s32 arg1, s32 arg2, u8* arg3);

extern struct X4_PlayerObj g_Player;
extern s8 D_8009724F;
extern struct X4_EngineObj g_playthrough_state;
extern u8 D_800F3F14;

void func_800ED610(struct X4_MainObj* self) {
    if (self->unk2 == 4) {
        if (g_Player.y_pos.i.hi >= 0xA11) {
            D_8009724F = 1;
        }
    }
    if (g_Player.unk5 == 0x14) {
        g_playthrough_state.gameplay_locked = 1;
        if (self->unk2 == 4) {
            func_80027BA0(0, 0x4C0, 0x930, &D_800F3F14);
        }
        g_playthrough_state.enable_boss = 1;
        M2C_FIELD(&g_playthrough_state, u8*, 0x8C) = 0x7F;
        set_boss_level();
        g_playthrough_state.unk25 = 0;
        g_playthrough_state.boss_ptr = self;
        self->unk7E = 3;
        self->unk6++;
    }
}
