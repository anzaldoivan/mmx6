#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

s32 play_sound(s32 a0, s32 a1, void* arg2);
#define play_sound ((void (*)(s32, s32, void*))play_sound)
M2C_UNK set_animation(void*, M2C_UNK);
#define set_animation ((void (*)(void*, s32))set_animation)
void func_8002CCB0(struct X4_BaseObj* arg0, s32 arg1, s32 arg2);
#define func_8002CCB0 func_8002CCB0
void func_8003CF24(s32, s32, s32);
M2C_UNK player_spawn_visual(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2,
                            M2C_UNK arg3);
#define player_spawn_visual player_spawn_visual
s32 func_801EE34C();
extern s32 D_8007615C[];
extern s32 D_80076164[];
extern s32 D_80077A0C[];
extern struct X4_PlayerObj g_Player;

#define SCRATCH_14 (*(u8**)0x1F800014)
#define SCRATCH_1C (*(u8**)0x1F80001C)
#define F_S8(p, o) (*(s8*)((u8*)(p) + (o)))

void func_800445A8(struct X4_WeaponObj* arg0) {
    struct X4_PlayerObj* player;

    arg0->unk50 = D_8007615C;
    arg0->unk68 = (struct X4_Unk_unk68*)D_80076164;
    arg0->unk64 = 1;
    arg0->animation_table = (u32**)D_80077A0C;
    player = &g_Player;
    if (player->unk2 != 0) {
        arg0->unk38 = SCRATCH_14 + *(s32*)(SCRATCH_14 + 0xC);
        arg0->unk3C = SCRATCH_1C + *(s32*)(SCRATCH_1C + 0x20);
        arg0->unk42 = 0x7848;
        func_8003CF24(0x50, 0x18, 1);
    } else {
        arg0->unk38 = SCRATCH_14 + *(s32*)(SCRATCH_14 + 0x14);
        arg0->unk3C = SCRATCH_1C + *(s32*)(SCRATCH_1C + 0x34);
        arg0->unk42 = 0x7801;
        func_8003CF24(0xF, 1, 1);
    }
    arg0->unk40 = 0x520;
    arg0->unk16 = 1;
    arg0->unk15 = player->unk15;
    arg0->unk67 = 1;
    F_S8(arg0, 0x9C) = 1;
    F_S8(arg0, 0x9D) = 1;
    if (arg0->unk2 == 0) {
        if (player->unk2 != 0) {
            if (arg0->unk15 != 0) {
                arg0->x_pos.i.hi = player->x_pos.i.hi + 0xF;
            } else {
                arg0->x_pos.i.hi = player->x_pos.i.hi - 0xF;
            }
            arg0->y_pos.i.hi = player->y_pos.i.hi + 0xE;
        } else {
            func_801EE34C(arg0, player, arg0->id);
        }
        if (arg0->unk15 != 0) {
            arg0->x_vel.val = 0x18000;
        } else {
            arg0->x_vel.val = -0x18000;
        }
        arg0->unk28.val = 0;
        if (player->unk2 != 0) {
            arg0->y_vel.val = 0x30000;
            arg0->unk2C = 0x2000;
        } else {
            arg0->y_vel.val = 0x60000;
            arg0->unk2C = 0x4000;
        }
        set_animation(arg0, 0);
        play_sound(1, 0x19, arg0);
        arg0->unk5 = 0;
    } else {
        arg0->unk5 = 2;
    }
    arg0->state++;
    func_8002CCB0(arg0, 0x20, 0x20);
    F_S8(arg0, 0x90) = 0;
    F_S8(arg0, 0x8E) = 0;
    player_spawn_visual(1, 0x1B, 2, 0);
}
#undef play_sound
#undef set_animation
#undef func_8002CCB0
#undef player_spawn_visual
