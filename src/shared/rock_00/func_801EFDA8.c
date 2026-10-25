#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern void (*D_801F39C0[])(struct X4_PlayerObj*);

#define F_S8(p, o) (*(s8*)((u8*)(p) + (o)))

void func_801EFDA8(struct X4_PlayerObj* arg0) {
    struct X4_PlayerObj* player = &g_Player;
    s32 var_a1;

    *(s32*)&arg0->unk18 = *(s32*)&arg0->x_pos;
    *(s32*)&arg0->unk1C = *(s32*)&arg0->y_pos;
    var_a1 = F_S8(player, 0xD3) != 0;
    if (F_S8(player, 0xD4) != 0) {
        var_a1 = 1;
    }
    if (player->weapon != 2) {
        var_a1 = 1;
    }
    if (var_a1 != 0) {
        arg0->state = 3;
    }
    D_801F39C0[arg0->state](arg0);
}
#undef g_Player
