#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
#include "mmx6/state.h"
extern s32 D_801F3838;
M2C_UNK set_animation(void*, M2C_UNK);
void animate_object(struct X4_AnimatedObj*);
M2C_UNK clear_object_slot();
#define set_animation ((void (*)(void*, s32))set_animation)
#define SCRATCH_14 (*(u8**)0x1F800014)
#define SCRATCH_1C (*(u8**)0x1F80001C)

void func_801ED898(struct X4_WeaponObj* arg0) {
    struct X4_PlayerObj* player;
    u8* temp_v0;
    u8* temp_a0;
    s32 temp_a2;
    s32 kill;
    s16 dx;
    s8 idx;

    player = &g_Player;
    kill = player->hp == 0;
    if (M2C_FIELD(player, s8*, 0xD3) != 0) {
        kill = 1;
    }
    if (M2C_FIELD(player, s8*, 0xCF) != 0) {
        kill = 1;
    }
    if (M2C_FIELD(arg0, s32*, 0x84) != player->unk17) {
        kill = 1;
    }
    if (kill != 0) {
        clear_object_slot(arg0);
        return;
    }
    if (arg0->state == 0) {
        arg0->state++;
        arg0->active = 1;
        arg0->on_screen = 1;
        temp_v0 = SCRATCH_14;
        arg0->unk38 = temp_v0 + *(s32*)(temp_v0 + 0xC);
        temp_a0 = SCRATCH_1C;
        temp_a2 = *(s32*)(temp_a0 + 0x1C);
        arg0->animation_table = (u32**)&D_80077A8C;
        arg0->unk40 = 0x540;
        arg0->unk42 = 0x7848;
        arg0->unk16 = 0;
        M2C_FIELD(arg0, s8*, 0x9C) = 1;
        arg0->unk3C = temp_a0 + temp_a2;
        arg0->x_pos.val = player->x_pos.val;
        arg0->y_pos.val = player->y_pos.val;
        arg0->unk15 = player->facing;
        dx = -0x20;
        if (player->action_timer == 0) {
            dx = -0x40;
        }
        if (arg0->unk15 != 0) {
            dx = -dx;
        }
        M2C_FIELD(arg0, s16*, 0xA) += dx;
        set_animation(arg0, 1);
    } else {
        animate_object((struct X4_AnimatedObj*)arg0);
        if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
            clear_object_slot(arg0);
            return;
        }
    }
    idx = M2C_FIELD(arg0, s8*, 0x45);
    if (idx == 0) {
        arg0->unk50 = 0;
    } else {
        arg0->unk50 = &(&D_801F3838)[idx];
    }
    if (!(D_80097420.frame_counter & 7)) {
        arg0->unk64++;
    }
}
#undef g_Player
#undef set_animation

#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern s32 D_801F3848;
M2C_UNK set_animation(void*, M2C_UNK);
void animate_object(struct X4_AnimatedObj*);
M2C_UNK clear_object_slot();
#define set_animation ((void (*)(void*, s32))set_animation)
#define SCRATCH_14 (*(u8**)0x1F800014)
#define SCRATCH_1C (*(u8**)0x1F80001C)

void func_801EDA64(struct X4_WeaponObj* arg0) {
    struct X4_PlayerObj* player;
    u8* temp_v0;
    u8* temp_a0;
    s32 temp_a2;
    s32 angle;
    u8 dir;

    player = &g_Player;
    if (player->action != 0x25) {
        clear_object_slot(arg0);
        return;
    }
    if (arg0->state == 0) {
        arg0->state++;
        arg0->active = 1;
        arg0->on_screen = 1;
        temp_v0 = SCRATCH_14;
        arg0->unk38 = temp_v0 + *(s32*)(temp_v0 + 0xC);
        temp_a0 = SCRATCH_1C;
        temp_a2 = *(s32*)(temp_a0 + 0x20);
        arg0->animation_table = (u32**)&D_80077A8C;
        arg0->unk40 = 0x540;
        arg0->unk42 = 0x7848;
        arg0->unk16 = 0;
        M2C_FIELD(arg0, s8*, 0x9C) = 1;
        arg0->unk3C = temp_a0 + temp_a2;
        dir = player->facing;
        M2C_FIELD(arg0, s16*, 0x92) = 0;
        M2C_FIELD(arg0, s16*, 0x8C) = -0x30;
        arg0->unk15 = dir;
        if (dir != 0) {
            M2C_FIELD(arg0, s16*, 0x8C) = 0x30;
        }
        M2C_FIELD(arg0, s16*, 0x8E) = -0x30;
        if (arg0->unk2 != 0) {
            M2C_FIELD(arg0, s16*, 0x8E) = 0x30;
        }
        set_animation(arg0, 2);
        arg0->unk50 = &D_801F3848;
    } else {
        animate_object((struct X4_AnimatedObj*)arg0);
        if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
            clear_object_slot(arg0);
            return;
        }
    }
    if (M2C_FIELD(arg0, s8*, 0x45) != 0) {
        M2C_FIELD(arg0, s16*, 0x92) =
            (s16)(M2C_FIELD(arg0, s16*, 0x92) + 1) % 66;
    } else {
        M2C_FIELD(arg0, s16*, 0x92) = 0;
    }
    angle = (M2C_FIELD(arg0, s16*, 0x92) << 12) / 66;
    M2C_FIELD(arg0, s16*, 0x90) = angle;
    arg0->x_pos.u.hi = player->x_pos.u.hi +
                       rcos((s16)angle) * M2C_FIELD(arg0, s16*, 0x8C) / 4096;
    M2C_FIELD(arg0, s16*, 0xE) =
        player->y_pos.u.hi +
        rsin(M2C_FIELD(arg0, s16*, 0x90)) * M2C_FIELD(arg0, s16*, 0x8E) / 4096;
    if (!(D_80097420.frame_counter & 7)) {
        arg0->unk64++;
    }
}
#undef g_Player
#undef set_animation
#undef SCRATCH_14
#undef SCRATCH_1C
