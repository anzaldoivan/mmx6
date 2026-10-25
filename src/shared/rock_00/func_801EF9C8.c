#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern s32 D_801F3954;
extern s32 D_801F395C;
M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_8002F288(M2C_UNK*);
M2C_UNK func_80049E50(void*);
s32 func_801EE34C();

void func_801EF9C8(struct X4_WeaponObj* arg0) {
    arg0->unk15 = g_Player.unk15;
    func_801EE34C(arg0, &g_Player, arg0->id);
    if (arg0->animation_step.fields.event == 1) {
        func_800179A4(arg0, 1);
        arg0->unk88.half = 3;
        if (arg0->unk15 != 0) {
            arg0->x_vel.val = 0x40000;
            arg0->x_pos.i.hi += 8;
        } else {
            arg0->x_vel.val = 0xFFFC0000;
            arg0->x_pos.i.hi -= 8;
        }
        arg0->unk50 = &D_801F3954;
        arg0->unk68 = (struct X4_Unk_unk68*)&D_801F395C;
        arg0->unk28.val = 0;
        arg0->y_vel.val = 0;
        arg0->unk2C = 0x2800;
        arg0->unk5 = 1;
        func_8002F288((M2C_UNK*)arg0);
        if (arg0->unk70 & 7) {
            func_80049E50(arg0);
            arg0->on_screen = 0;
            arg0->state = 3;
        }
    }
}
#undef g_Player
