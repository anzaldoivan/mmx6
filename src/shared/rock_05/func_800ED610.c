#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_80025FD8();
s32 func_80027BA0(s32 arg0, s32 arg1, s32 arg2, u8* arg3);

extern struct X4_PlayerObj g_Player;
extern s8 D_8009724F;
extern struct X4_EngineObj D_800CCED0;
extern u8 D_800F3F14;

void func_800ED610(struct X4_MainObj* self) {
    if (self->unk2 == 4) {
        if (g_Player.y_pos.i.hi >= 0xA11) {
            D_8009724F = 1;
        }
    }
    if (g_Player.unk5 == 0x14) {
        D_800CCED0.gameplay_locked = 1;
        if (self->unk2 == 4) {
            func_80027BA0(0, 0x4C0, 0x930, &D_800F3F14);
        }
        D_800CCED0.enable_boss = 1;
        M2C_FIELD(&D_800CCED0, u8*, 0x8C) = 0x7F;
        func_80025FD8();
        D_800CCED0.unk25 = 0;
        D_800CCED0.boss_ptr = self;
        self->unk7E = 3;
        self->unk6++;
    }
}
