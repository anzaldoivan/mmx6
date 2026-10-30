#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
#define set_animation ((void (*)(void*, s32))set_animation)
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
#define func_8002CCB0 ((void (*)(void*, s32, s32))func_8002CCB0)
s32 random_byte();
s32 func_801EE34C();
extern s32 D_80077A28[];
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern struct X4_BackgroundObj background_objects[3];
extern s32 D_801F3A4C[];

#define SCRATCH_14 (*(u8**)0x1F800014)
#define SCRATCH_1C (*(u8**)0x1F80001C)
#define F_90(p) (((X4_f32*)((u8*)(p) + 0x90))->i)
#define F_S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define BG (background_objects[player->bg_offset])

void func_801F15B0(struct X4_WeaponObj* arg0) {
    struct X4_PlayerObj* player;
    struct X4_WeaponObj* parent;
    s16 a;
    s16 b;
    s32 c;

    arg0->unk38 = SCRATCH_14 + *(s32*)(SCRATCH_14 + 0x1C);
    arg0->unk3C = SCRATCH_1C + *(s32*)(SCRATCH_1C + 0x3C);
    arg0->animation_table = (u32**)D_80077A28;
    arg0->unk40 = 0x520;
    c = 0x7801;
    arg0->unk42 = c;
    arg0->on_screen = c;
    arg0->unk64 = c;
    arg0->unk16 = 2;
    player = &g_Player;
    if (arg0->unk2 == 0) {
        play_sound(1, 0x1B, arg0);
        arg0->unk15 = player->unk15;
        F_90(arg0).lo = player->x_pos.i.hi - BG.x_pos.i.hi;
        F_90(arg0).hi = player->y_pos.i.hi - BG.y_pos.i.hi;
        func_801EE34C(arg0, player, arg0->id);
        set_animation(arg0, 0);
        F_S8(player, 0xA6) = 3;
    } else if (arg0->unk2 == 1) {
        parent = (struct X4_WeaponObj*)arg0->owner;
        arg0->unk15 = parent->unk15;
        arg0->x_pos.i.hi = parent->x_pos.i.hi;
        arg0->y_pos.i.hi = parent->y_pos.i.hi - 8;
        F_90(arg0).lo = F_90(parent).lo;
        F_90(arg0).hi = F_90(parent).hi;
        arg0->y_vel.val = 0x40000;
        arg0->unk50 = D_801F3A4C;
        arg0->unk5 = parent->unk5 + 1;
        set_animation(arg0, 1);
    } else if (arg0->unk2 == 0x10) {
        play_sound(1, 0x1C, arg0);
        parent = (struct X4_WeaponObj*)arg0->owner;
        arg0->unk15 = parent->unk15;
        arg0->unk5 = 3;
        arg0->unk50 = D_801F3A4C;
        arg0->unk16 = 0x12;
        set_animation(arg0, 5);
        a = F_90(parent).lo;
        b = F_90(parent).hi;
        if (random_byte() & 4) {
            if (arg0->unk15 != 0) {
                a = (a * (random_byte() % 11)) / 10;
            } else {
                a = 0x140 - ((0x140 - a) * (random_byte() % 11)) / 10;
            }
            arg0->x_pos.i.hi = a + BG.x_pos.i.hi;
            arg0->y_pos.i.hi = BG.y_pos.i.hi - 0x20;
        } else {
            if (arg0->unk15 != 0) {
                arg0->x_pos.i.hi = BG.x_pos.i.hi - 0x24;
            } else {
                arg0->x_pos.i.hi = BG.x_pos.i.hi + 0x164;
            }
            b = (b * (random_byte() % 11)) / 10;
            arg0->y_pos.i.hi = b + BG.y_pos.i.hi;
        }
        arg0->x_vel.val = 0x54D9E;
        arg0->y_vel.val = -0x54D9E;
        if (arg0->unk15 == 0) {
            arg0->x_vel.val = -0x54D9E;
        }
    }
    func_8002CCB0(arg0, 0x20, 0x20);
    arg0->state++;
}
#undef g_Player
#undef set_animation
#undef func_8002CCB0
