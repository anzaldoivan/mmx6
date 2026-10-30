#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

s32 play_sound(s32 a0, s32 a1, void* arg2);
#define play_sound ((void (*)(s32, s32, void*))play_sound)
M2C_UNK set_animation(void*, M2C_UNK);
#define set_animation ((void (*)(void*, s32))set_animation)
void func_8003CF24(s32, s32, s32);
void* func_8003D480(s8 arg0, s8 arg1, s8 arg2, s32 arg3);
M2C_UNK player_spawn_visual(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2,
                            M2C_UNK arg3);
#define player_spawn_visual player_spawn_visual
extern s16 D_800761CC[][2];
extern s32 D_800761DC[][2];
extern s32 D_80077A5C[];
extern struct X4_PlayerObj g_Player;
extern struct X4_BackgroundObj background_objects[3];

#define SCRATCH_14 (*(u8**)0x1F800014)
#define SCRATCH_1C (*(u8**)0x1F80001C)
#define F_S16(p, o) (*(s16*)((u8*)(p) + (o)))

void func_80045928(struct X4_WeaponObj* arg0) {
    struct X4_PlayerObj* player;
    s32 i;
    s32 ang;
    s32 x;
    s32 y;
    u8* p;
    u8* q;

    player = &g_Player;
    if (arg0->unk2 == 0) {
        play_sound(1, 0x1E, arg0);
        if (func_8003D480(1, arg0->id, 1, arg0) != 0) {
            arg0->unk7++;
        }
        if (func_8003D480(1, arg0->id, 2, arg0) != 0) {
            arg0->unk7++;
        }
        if (func_8003D480(1, arg0->id, 3, arg0) != 0) {
            arg0->unk7++;
        }
        if (func_8003D480(1, arg0->id, 4, arg0) != 0) {
            arg0->unk7++;
        }
        player_spawn_visual(1, 0x1B, 0xB, 0);
        func_8003CF24(0x1E, 1, 1);
        {
            // !FAKE: depin: dropping it breaks the match (67/187)
            register s32 t asm("$3") = (u8)arg0->state + 1;
            arg0->state = t;
        }
        return;
    }
    p = SCRATCH_14;
    arg0->unk38 = p + *(s32*)(p + 0x2C);
    q = SCRATCH_1C;
    arg0->unk3C = q + *(s32*)(q + 0x60);
    arg0->animation_table = (u32**)D_80077A5C;
    arg0->unk40 = 0x520;
    arg0->unk42 = 0x7801;
    arg0->bg_offset = -1;
    if (arg0->unk2 < 5) {
        arg0->x_pos.i.hi = player->x_pos.i.hi -
                           background_objects[player->bg_offset].x_pos.i.hi;
        arg0->y_pos.i.hi = player->y_pos.i.hi -
                           background_objects[player->bg_offset].y_pos.i.hi;
        F_S16(arg0, 0x92) = arg0->x_pos.i.hi;
        arg0->unk16 = 0x11;
        F_S16(arg0, 0x94) = arg0->y_pos.i.hi;
        set_animation(arg0, 0);
        arg0->unk5 = 2;
    } else if (arg0->unk2 < 9) {
        if (arg0->unk2 == 8) {
            play_sound(1, 0x1F, arg0);
        }
        arg0->x_pos.i.hi = D_800761CC[arg0->unk2 - 5][0];
        arg0->y_pos.i.hi = D_800761CC[arg0->unk2 - 5][1];
        i = arg0->unk2 - 5;
        y = D_800761DC[i][1];
        ang = ratan2(arg0->y_pos.i.hi - y, D_800761DC[i][0] - arg0->x_pos.i.hi);
        arg0->x_vel.val = rcos(ang) << 6;
        arg0->y_vel.val = rsin(ang) << 6;
        arg0->unk16 = 0x10;
        arg0->unk64 = 1;
        set_animation(arg0, 1);
        arg0->unk5 = 5;
    }
    arg0->on_screen = 1;
    arg0->state++;
}
#undef play_sound
#undef set_animation
#undef player_spawn_visual
