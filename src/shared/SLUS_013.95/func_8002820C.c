#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern struct X4_EngineObj g_playthrough_state;
extern s8 D_800CCEDF;

void func_8002820C(struct X4_BackgroundObj* arg0) {
    s16 lim;

    if (arg0->unk1C < arg0->x_pos.i.hi) {
        arg0->x_pos.i.hi = arg0->unk1C;
        lim = (s16)(arg0->x_pos.i.hi + 0x140);
        if (g_Player.x_pos.i.hi + 8 >= lim) {
            g_Player.x_pos.i.hi = arg0->x_pos.i.hi + 0x138;
        }
    }
    if (arg0->unk1E >= arg0->x_pos.i.hi) {
        arg0->x_pos.i.hi = arg0->unk1E;
        if (g_Player.x_pos.i.hi - 8 < arg0->x_pos.i.hi) {
            g_Player.x_pos.i.hi = arg0->x_pos.i.hi + 8;
        }
    }
    if (g_Player.y_pos.i.hi < 0 && D_800CCEDF == 0) {
        g_Player.y_pos.i.hi = 0;
    }
    if (arg0->unk20 < arg0->y_pos.i.hi) {
        arg0->y_pos.i.hi = arg0->unk20;
        lim = (s16)(arg0->y_pos.i.hi + 0x100);
        if (lim <= g_Player.y_pos.i.hi - 8) {
            u8 hp = g_Player.hp;
            u8* e = (u8*)&g_playthrough_state;
            g_Player.hp = -0x80;
            *(s32*)(e + 0x98) += hp & 0x7F;
        }
    } else if (arg0->unk22 >= arg0->y_pos.i.hi) {
        arg0->y_pos.i.hi = arg0->unk22;
    }
}
#undef g_Player
