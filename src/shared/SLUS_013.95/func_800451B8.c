#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

s32 play_sound(s32 a0, s32 a1, void* arg2);
#define play_sound ((void (*)(s32, s32, void*))play_sound)
M2C_UNK set_animation(void*, M2C_UNK);
#define set_animation ((void (*)(void*, s32))set_animation)
void func_80017B04(u8*, s16, s16);
#define func_80017B04 func_80017B04
s8* func_8002BEC4(s8* p, s32 dir);
void func_8003CF24(s32, s32, s32);
M2C_UNK player_spawn_visual(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2,
                            M2C_UNK arg3);
#define player_spawn_visual player_spawn_visual
extern u8 D_80076194[][2];
extern s32 D_80077A40[];
extern struct X4_PlayerObj g_Player;

#define SCRATCH_14 (*(u8**)0x1F800014)
#define SCRATCH_1C (*(u8**)0x1F80001C)
#define F_S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define F_U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F_PTR(p, o) (*(void**)((u8*)(p) + (o)))

void func_800451B8(struct X4_WeaponObj* arg0) {
    struct X4_PlayerObj* player;
    s8 kind;
    s8* child;

    player = &g_Player;
    if (arg0->unk2 == 0) {
        play_sound(1, 0x1D, arg0);
        kind = 3;
        {
            // !FAKE: depin: dropping it breaks the match (179/181)
            register s32 t asm("$3") = player->unk2;
            if (t == 0) {
                kind = 1;
                if (!(player->input.buttons.held & 4)) {
                    kind = 3;
                    if (player->input.buttons.held & 8) {
                        kind = 2;
                    }
                }
            }
        }
        child = func_8002BEC4((s8*)arg0, 0);
        if (child != 0) {
            child[0] = 1;
            child[1] = arg0->id;
            child[2] = kind;
            F_PTR(child, 0x7C) = arg0;
            F_U8(arg0, 0x8C)++;
        }
        arg0->state++;
        if (player->unk2 != 0) {
            F_U8(arg0, 0x48) = 0xFF;
            F_S8(arg0, 0x47) = 0;
            arg0->unk49 = 1;
            {
                u8* q = SCRATCH_14;
                arg0->unk38 = q + *(s32*)(q + 0x14);
            }
            func_80017B04(arg0, 0x140, 0x40);
            func_8003CF24(0x52, 0x19, 1);
        }
        return;
    }
    if (player->unk2 != 0) {
        u8* a = SCRATCH_14;
        u8* b;
        arg0->unk38 = a + *(s32*)(a + 0x14);
        b = SCRATCH_1C;
        arg0->unk3C = b + *(s32*)(b + 0x28);
        arg0->unk40 = 0x540;
        arg0->unk42 = 0x7849;
    } else {
        u8* a = SCRATCH_14;
        u8* b;
        arg0->unk38 = a + *(s32*)(a + 0x20);
        b = SCRATCH_1C;
        arg0->unk3C = b + *(s32*)(b + 0x40);
        arg0->unk40 = 0x520;
        arg0->unk42 = 0x7801;
        player_spawn_visual(1, 0x1B, 4, 0);
        func_8003CF24(0x1B, 1, 1);
    }
    arg0->animation_table = (u32**)D_80077A40;
    arg0->unk16 = 1;
    F_S8(arg0, 0x9C) = 1;
    arg0->on_screen = 1;
    arg0->unk15 = 0;
    if (player->unk15 != 0) {
        arg0->x_pos.i.hi =
            player->x_pos.i.hi - (s8)D_80076194[arg0->unk2 - 1][0];
    } else {
        arg0->x_pos.i.hi =
            player->x_pos.i.hi + (s8)D_80076194[arg0->unk2 - 1][0];
    }
    arg0->y_pos.i.hi = player->y_pos.i.hi + (s8)D_80076194[arg0->unk2 - 1][1];
    if (arg0->unk2 < 3) {
        set_animation(arg0, 0);
    } else {
        set_animation(arg0, 1);
    }
    arg0->unk5 = 1;
    arg0->state++;
}
#undef play_sound
#undef set_animation
#undef func_80017B04
#undef player_spawn_visual
