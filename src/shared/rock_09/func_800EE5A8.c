#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
s32 func_800EE330(void*, M2C_UNK*);
extern s32 g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern s8 D_800CCEF7;

void func_800EE5A8(struct X4_MainObj* self) {
    if (func_800EE330(self, (M2C_UNK*)&g_Player) != 0) {
        D_800CCEF7 = 1;
        g_Player.x_pos.i.hi = self->x_pos.i.hi;
        g_Player.y_pos.i.hi = self->y_pos.i.hi - g_Player.unk68->unk3;
        func_8003D308(0x14, g_Player.unk15);
        self->unk6++;
    }
}
#undef g_Player
