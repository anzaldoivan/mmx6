#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

s32 play_sound(s32 a0, s32 a1, void* arg2);
#define play_sound ((void (*)(s32, s32, void*))play_sound)
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();
s8* func_8002BEC4(s8* p, s32 dir);
s32 get_weapon_energy_cost(void* arg0, s32 arg1);
void use_weapon_energy(void*, s32);
extern s32 D_8007619C;
extern s32 D_800761A0;
extern struct X4_PlayerObj g_Player;

#define F_S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define F_U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F_S16(p, o) (*(s16*)((u8*)(p) + (o)))
#define F_PTR(p, o) (*(void**)((u8*)(p) + (o)))

// 0x8004548C update_guard_shell: Guard Shell activation and ammo use.
// basis: community tweaks-index.tsv:228
// callers: none known
void update_guard_shell(struct X4_WeaponObj* arg0) {
    struct X4_PlayerObj* player;
    struct X4_WeaponObj* child;
    u8* parent;
    s8 kind;
    s32 hp;
    u16 y;
    s32 v;

    ((void (*)())func_80017A04)();
    if (--F_S8(arg0, 0x8E) == 0) {
        player = &g_Player;
        kind = 4;
        if (player->unk2 == 0) {
            kind = F_S8(player, 0x93);
        }
        hp = F_S16((u8*)&g_Player + (kind << 1), 0xA8);
        if (hp >= get_weapon_energy_cost(player, kind)) {
            if (player->unk2 != 0) {
                F_S8(player, 0x93) = 4;
                use_weapon_energy(player, 4);
            } else {
                use_weapon_energy(player, arg0->id);
            }
            parent = F_PTR(arg0, 0x7C);
            F_U8(arg0, 0x8F) = 0;
            child = (struct X4_WeaponObj*)func_8002BEC4((s8*)parent, 0);
            if (child != 0) {
                play_sound(1, 0x1F, arg0);
                {
                    // !FAKE: depin: dropping it breaks the match (24/146)
                    register s32 one asm("$6") = 1;
                    child->active = one;
                    child->id = 0x35;
                    child->unk2 = 5;
                    F_PTR(child, 0x7C) = parent;
                    child->unk38 = arg0->unk38;
                    child->unk3C = arg0->unk3C;
                    child->animation_table = arg0->animation_table;
                    child->unk40 = arg0->unk40;
                    child->unk42 = arg0->unk42;
                    child->unk16 = arg0->unk16;
                    child->x_pos.i.hi = arg0->x_pos.i.hi;
                    y = arg0->y_pos.i.hi;
                    F_PTR(child, 0x68) = &D_800761A0;
                    F_PTR(child, 0x50) = &D_8007619C;
                    child->on_screen = one;
                    child->state = one;
                    child->unk5 = 4;
                    child->y_pos.i.hi = y;
                    ((void (*)())set_animation)(child, 6, 1, y);
                    if (arg0->unk2 == 1) {
                        v = 0x30000;
                        goto set;
                    }
                    if (arg0->unk2 == 2) {
                        v = -0x30000;
                    set:
                        child->x_vel.val = 0;
                        child->y_vel.val = v;
                    } else if (arg0->unk2 == 3) {
                        child->x_vel.val = -0x30000;
                        child->y_vel.val = 0;
                        goto neg;
                    } else {
                        child->x_vel.val = -0x30000;
                        child->y_vel.val = 0;
                    neg:
                        if (player->unk15 != 0) {
                            child->x_vel.val = -child->x_vel.val;
                        }
                    }
                }
                F_U8(parent, 0x8C)++;
            }
        }
        if (arg0->unk2 < 3) {
            ((void (*)(void*, s32))set_animation)(arg0, 0);
        } else {
            ((void (*)(void*, s32))set_animation)(arg0, 1);
        }
        F_U8(arg0, 0x9C) &= 0xFD;
        arg0->unk5--;
    }
}
#undef play_sound
