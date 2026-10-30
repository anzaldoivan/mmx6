#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
#define set_animation ((void (*)(void*, s32))set_animation)
s32 func_801EE34C();
extern s32 D_80077A64[];
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)

#define SCRATCH_14 (*(u8**)0x1F800014)
#define SCRATCH_1C (*(u8**)0x1F80001C)

void func_801F226C(struct X4_WeaponObj* arg0) {
    struct X4_PlayerObj* player;
    struct X4_WeaponObj* parent;
    u8* temp_v0;
    u8* temp_a0;
    s32 var_a0;
    s8 sub;

    temp_v0 = SCRATCH_14;
    arg0->unk38 = temp_v0 + *(s32*)(temp_v0 + 0x24);
    temp_a0 = SCRATCH_1C;
    var_a0 = *(s32*)(temp_a0 + 0x44);
    arg0->animation_table = (u32**)D_80077A64;
    arg0->unk40 = 0x520;
    arg0->unk42 = 0x7801;
    player = &g_Player;
    arg0->unk16 = 1;
    arg0->unk3C = temp_a0 + var_a0;
    arg0->unk15 = player->unk15;
    sub = arg0->unk2;
    arg0->on_screen = 1;
    arg0->unk64 = 1;
    if (sub == 0) {
        play_sound(1, 0x24, arg0);
        arg0->x_vel.val = 0x6C000;
        func_801EE34C(arg0, player, arg0->id);
        set_animation(arg0, 0);
        arg0->state++;
        return;
    }
    parent = (struct X4_WeaponObj*)arg0->owner;
    arg0->x_pos.i.hi = parent->x_pos.i.hi;
    arg0->y_pos.i.hi = parent->y_pos.i.hi;
    arg0->state = 2;
    arg0->on_screen = 1;
    if (sub == 1) {
        set_animation(arg0, 4);
        return;
    }
    if (sub == 2) {
        set_animation(arg0, 5);
        arg0->y_pos.i.hi -= 8;
    } else {
        set_animation(arg0, 6);
        arg0->y_pos.i.hi += 8;
    }
}
#undef g_Player
#undef set_animation
