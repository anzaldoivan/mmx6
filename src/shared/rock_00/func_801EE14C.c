/* Adapted from sozud/mmx4 @807a01b src/main/weapons/weapon_22_nova_strike_hitbox.c:nova_strike_hitbox_update, AGPL-3.0; proven shared with X6 by exact signature ab318e028ab5 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern struct X4_Unk_unk68 D_801F37AC[];
M2C_UNK func_8002C9B0();
#define func_8002C9B0 ((void (*)(struct X4_ObjectHeader * arg0)) func_8002C9B0)

void func_801EE14C(struct X4_WeaponObj* arg0) {
    struct X4_PlayerObj* player = &g_Player;
    u8 temp_v0;

    if (g_Player.unk17 != 0x6A) {
        func_8002C9B0(OBJECT_HEADER(arg0));
        return;
    }
    if (arg0->state == 0) {
        arg0->unk50 = &D_801F37AC;
        arg0->unk64 = 1U;
        arg0->ext.raw[0] = 4U;
        arg0->state++;
    } else {
        temp_v0 = arg0->ext.raw[0];
        if (temp_v0 == 0) {
            arg0->ext.raw[0] = 4U;
            arg0->unk64++;
        } else {
            arg0->ext.raw[0] = temp_v0 - 1;
        }
    }
    arg0->x_pos.val = player->x_pos.val;
    arg0->y_pos.val = player->y_pos.val;
    arg0->unk15 = player->unk15;
}
#undef g_Player
#undef func_8002C9B0
