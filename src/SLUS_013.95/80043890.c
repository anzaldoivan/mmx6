#include "common.h"
#include "mmx6/x4.h"

extern struct X4_PlayerObj g_Player;
s32 get_weapon_energy_cost(void* arg0, s32 arg1);
void use_weapon_energy(void*, s32);

#define SB(o) (*(s8*)((u8*)self + (o)))
#define UB(o) (*(u8*)((u8*)self + (o)))
#define SH(o) (*(s16*)((u8*)self + (o)))
#define UH(o) (*(u16*)((u8*)self + (o)))
#define ENERGY(p, i) (*(s16*)((u8*)(p) + ((i) << 1) + 0xA8))

void func_80043890(struct X4_MainObj* self) {
    struct X4_PlayerObj* player;
    s32 flag;
    s32 i;
    s32 arg;
    s32 b;
    s32 t;
    s32 v;
    u8 f;

    if (SH(0x94) != 0x1000) {
        SH(0x94) = (UH(0x94) + 0x22) & 0xFFF;
    }
    f = UB(0x93) & 0xFE;
    player = &g_Player;
    UB(0x93) = f;
    if (f & 2) {
        if ((s16)(++SH(0x88) % 20) == 0) {
            UB(0x93) = f | 1;
        }
        if (SH(0x88) >= 0x1E1) {
            SH(0x88) = 0;
            UB(0x93) = UB(0x93) & 0xFD;
        }
    } else {
        flag = 0;
        if (player->character != 0) {
            if (player->input.buttons.held & 4) {
                if (player->pressed_input & 0x20) {
                    player->weapon = 3;
                    flag = 1;
                }
            }
        } else if (player->pressed_input & 0x10) {
            flag = 1;
        }
        if (flag == 1 && UB(0x8D) != 7) {
            i = 0;
            b = 1;
            do {
                if (!((UB(0x8D) >> i) & 1)) {
                    if (player->character != 0) {
                        if (ENERGY(player, 3) >=
                            get_weapon_energy_cost(player, 3)) {
                            arg = player->weapon;
                            // !FAKE: goto shares give; copied call+pin moved
                            goto give;
                        }
                    } else {
                        if (ENERGY(player, player->weapon) >=
                            get_weapon_energy_cost(player, player->weapon)) {
                            arg = self->id;
                        give:
                            use_weapon_energy(player, arg);
                            {
                                // !FAKE: depin: dropping it breaks the match (186/192)
                                register s32 m asm("$3") = UB(0x8D);
                                m |= b << i;
                                UB(0x8D) = m;
                            }
                        }
                    }
                }
                i++;
            } while (i < 3);
        }
        if (UH(0x8C) == 3) {
            self->state = 2;
            SB(0x8F) = 1;
            return;
        }
        if (SH(0x94) != 0x1000) {
            if (self->id == 0xA && UB(0x8D) == 7) {
                self->id = 1;
                UB(0x93) = 2;
                return;
            }
            if (player->shot_type == 0xA) {
                if (ENERGY(player, player->weapon) >=
                    get_weapon_energy_cost(player, player->weapon)) {
                    use_weapon_energy(player, self->id);
                    {
                        // !FAKE: depin: dropping it breaks the match (88/192)
                        register s32 s asm("$3") = 7;
                        UB(0x8D) = s;
                    }
                    v = 2;
                    UB(0x93) = v;
                    return;
                }
            }
            if (player->character != 0) {
                t = player->pressed_input & 0x30;
            } else {
                t = player->pressed_input & 0x10;
            }
            if (t != 0) {
                v = 1;
                UB(0x93) = v;
            }
        }
    }
}

#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32

s32 play_sound(s32 a0, s32 a1, void* arg2);
M2C_UNK set_animation(void*, M2C_UNK);
#define set_animation ((void (*)(void*, s32))set_animation)
s8* func_8002BEC4(s8* p, s32 dir);
extern s32 D_8007610C;
extern s32 D_80076110;
extern s32 D_80076114;

#define F_S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define F_U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F_U16(p, o) (*(u16*)((u8*)(p) + (o)))
#define F_S32(p, o) (*(s32*)((u8*)(p) + (o)))
#define F_PTR(p, o) (*(void**)((u8*)(p) + (o)))

void func_80043B90(s8* arg0, s16 arg1) {
    u8* parent;
    s8* child;
    u8 flags;

    parent = F_PTR(arg0, 0x7C);
    flags = parent[0x93];
    if (!(flags & 1)) {
        return;
    }
    if ((s8)flags == 1) {
        if (F_U8(arg0, 0x8E) != 0) {
            return;
        }
        if (*(s8*)(arg0[2] + (s32)parent + 0x8F) > 0) {
            return;
        }
    }
    child = func_8002BEC4(arg0, 0);
    if (child == 0) {
        return;
    }
    play_sound(1, 0x13, arg0);
    parent[0x8C]++;
    child[0] = 1;
    F_PTR(child, 0x7C) = parent;
    F_S32(child, 0x38) = F_S32(arg0, 0x38);
    F_S32(child, 0x3C) = F_S32(arg0, 0x3C);
    F_S32(child, 0x30) = F_S32(arg0, 0x30);
    F_U16(child, 0x40) = F_U16(arg0, 0x40);
    F_U16(child, 0x42) = F_U16(arg0, 0x42);
    F_U8(child, 0x16) = F_U8(arg0, 0x16);
    F_U16(child, 0xA) = F_U16(arg0, 0xA);
    F_U16(child, 0xE) = F_U16(arg0, 0xE);
    child[4] = 1;
    child[5] = 8;
    F_S32(child, 0x20) = rcos(arg1) * 0x10;
    F_S32(child, 0x24) = -rsin(arg1) * 0x10;
    if (parent[0x93] & 2) {
        child[1] = 0xA;
        child[2] = 7;
        F_PTR(child, 0x50) = &D_80076114;
        F_S32(child, 0x24) *= 8;
        F_S32(child, 0x20) *= 8;
        set_animation(child, 4);
        return;
    }
    child[2] = (u8)arg0[2] + 3;
    F_S32(child, 0x24) *= 6;
    F_PTR(child, 0x50) = &D_8007610C;
    F_PTR(child, 0x68) = &D_80076110;
    child[1] = 0x36;
    F_S32(child, 0x20) *= 6;
    F_U8(arg0, 0x8E) = 6;
    {
        u8* p = (u8*)(arg0[2] + (s32)parent);
        p += 0x8F;
        (*p)++;
    }
    set_animation(child, 3);
}
#undef play_sound
#undef set_animation

#include "common.h"
#include "psyq/libgte.h"
#include "mmx6/x4.h"

extern s32 D_80076124;
extern struct X4_PlayerObj g_Player;
#include "mmx6/state.h"

#define F_U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F_S16(p, o) (*(s16*)((u8*)(p) + (o)))
#define F_U16(p, o) (*(u16*)((u8*)(p) + (o)))
#define F_S32(p, o) (*(s32*)((u8*)(p) + (o)))
#define F_PTR(p, o) (*(void**)((u8*)(p) + (o)))

void func_80043DBC(s8* arg0) {
    u8* parent;
    s32 ang;
    s32 v;
    s32 q;
    struct X4_PlayerObj* pl;

    if (arg0[2] != 0) {
        parent = F_PTR(arg0, 0x7C);
        if (parent[0x8F] != 0) {
            F_S32(arg0, 0x50) = 0;
            F_S32(arg0, 0x68) = 0;
            arg0[4] = 2;
            return;
        }
        if ((u8)(arg0[2] - 1) < 3) {
            if (arg0[5] == 7) {
                if ((u32)D_80097420.frame_counter % 21 == 0) {
                    F_U8(arg0, 0x64)++;
                }
            } else if (!(D_80097420.frame_counter & 7)) {
                F_U8(arg0, 0x64)++;
            }
            pl = &g_Player;
            F_U8(arg0, 0x15) = pl->facing;
            {
                s32 off = (arg0[2] - 1) * 0x555 + 0xE00;
                ang = (F_U16(parent, 0x94) + off) & 0xFFF;
            }
            v = rcos(ang) * F_S16(arg0, 0x88);
            if (v < 0) {
                v += 0xFFF;
            }
            F_S16(arg0, 0xA) = pl->x_pos.i.hi + (v >> 12);
            q = rsin(ang) * F_S16(arg0, 0x88);
            v = q >> 12;
            if (q < 0) {
                v = (q + 0xFFF) >> 12;
            }
            F_S16(arg0, 0xE) = pl->y_pos.i.hi + v;
            if (F_U8(arg0, 0x8E) != 0) {
                F_U8(arg0, 0x8E)--;
            }
        }
    }
    ((void (**)(s8*)) & D_80076124)[arg0[5]](arg0);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern struct X4_PlayerObj g_Player;
M2C_UNK clear_object_slot();

void func_80043F8C(s8* arg0) {
    struct X4_PlayerObj* parent;
    struct X4_PlayerObj* player;
    s8* p;
    s32 t;

    if (arg0[2] == 0) {
        if (arg0[0x8C] != 0) {
            return;
        }
        player = &g_Player;
        player->shot_count--;
        player->special_shot_count--;
        if (player->character != 0 && player->stock_charge == 1) {
            player->stock_charge = 0;
        }
        p = (s8*)player;
    } else {
        parent = *(struct X4_PlayerObj**)(arg0 + 0x7C);
        parent->afterimage--;
        p = (s8*)(u8)arg0[2];
        if ((u32)((s32)p - 4) < 3) {
            t = (s8)(s32)p + (s32)parent;
            p = (s8*)t + 0x8C;
            t = 0;
            if (*p != 0) {
                (*p)--;
            }
        }
    }
    clear_object_slot(arg0, p);
}

#include "common.h"

void func_80044058(u8* arg0) {
    s32 temp_v0;

    temp_v0 = *(u16*)(arg0 + 0x88) + 8;
    *(u16*)(arg0 + 0x88) = temp_v0;
    if ((s16)temp_v0 >= 0x20) {
        *(u16*)(arg0 + 0x88) = 0x20;
        arg0[5]++;
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK); /* extern */
M2C_UNK animate_object();              /* extern */
extern s32 D_80076108;

void func_80044094(void* arg0) {
    void* temp_a0;

    ((void (*)())animate_object)();
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        temp_a0 = M2C_FIELD(arg0, void**, 0x7C);
        if (M2C_FIELD(temp_a0, s16*, 0x94) == 0x1000) {
            M2C_FIELD(temp_a0, s16*, 0x94) = 0;
        }
        set_animation(arg0, 1);
        M2C_FIELD(arg0, u8*, 0x98) = 0;
        M2C_FIELD(arg0, s32**, 0x50) = &D_80076108;
        M2C_FIELD(arg0, s16*, 0x8A) = 0;
        M2C_FIELD(arg0, u8*, 0x64) = 1;
        M2C_FIELD(arg0, u8*, 5) = (u8)(M2C_FIELD(arg0, u8*, 5) + 1);
    }
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();
void func_80043B90(s8* arg0, s16 arg1);

void func_80044118(s8* arg0) {
    s16 t;

    if ((*(u8**)(arg0 + 0x7C))[0x93] & 2) {
        ((void (*)(void*, s32))set_animation)(arg0, 2);
        arg0[5] = 7;
        return;
    }
    ((void (*)())animate_object)(arg0);
    if (arg0[0x98] != 0) {
        arg0[0x98] = 0;
        t = ++*(u16*)(arg0 + 0x8A);
        if (t >= 3) {
            ((void (*)(void*, s32))set_animation)(arg0, 5);
            *(s32*)(arg0 + 0x50) = 0;
            arg0[5]++;
            return;
        }
    }
    func_80043B90(arg0, (*(u8*)(arg0 + 0x15) == 0) << 11);
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();

void func_800441D4(void* arg0) {
    u8* temp_a1;

    ((void (*)())animate_object)(arg0);
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        temp_a1 = M2C_FIELD(arg0, u8**, 0x7C);
        temp_a1[0x8D] &= ~(1 << (M2C_FIELD(arg0, s8*, 2) - 1));
        M2C_FIELD(arg0, u8*, 3) = 0;
        M2C_FIELD(arg0, u8*, 5) += 1;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

M2C_UNK set_animation(void*, M2C_UNK);

#define F_U8(p, o) (*(u8*)((u8*)(p) + (o)))

void func_80044238(struct X4_WeaponObj* arg0) {
    if ((F_U8(arg0->owner, 0x8D) >> (arg0->unk2 - 1)) & 1) {
        ((void (*)(void*, s32))set_animation)(arg0, 5);
        arg0->on_screen = 1;
        arg0->unk5++;
    }
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();
extern s32 D_80076108;

void func_80044294(s8* arg0) {
    ((void (*)())animate_object)();
    if (arg0[0x46] == 0) {
        *(s32**)(arg0 + 0x50) = &D_80076108;
        arg0[0x98] = 0;
        *(s16*)(arg0 + 0x8A) = 0;
        arg0[0x64] = 1;
        if (!(*(*(u8**)(arg0 + 0x7C) + 0x93) & 2)) {
            ((void (*)(void*, s32))set_animation)(arg0, 1);
            arg0[5] = (u8)arg0[5] - 3;
        } else {
            ((void (*)(void*, s32))set_animation)(arg0, 2);
            arg0[5] = 7;
        }
    }
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();
void func_80043B90(s8* arg0, s16 arg1);
extern s32 D_80076108;

void func_8004431C(s8* arg0) {
    u8* t;
    s32 v;

    ((void (*)())animate_object)(arg0);
    t = *(u8**)(arg0 + 0x7C);
    if (!(t[0x93] & 2)) {
        ((void (*)(void*, s32))set_animation)(arg0, 1);
        *(s32**)(arg0 + 0x50) = &D_80076108;
        arg0[0x98] = 0;
        arg0[0x64] = 1;
        arg0[5] = 3;
    }
    v = (arg0[2] - 1) * 0x555 + 0xE00;
    func_80043B90(arg0, (*(u16*)(t + 0x94) + v) & 0xFFF);
}

#include "common.h"
#include "mmx6/globals.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();                                           /* extern */
s32 is_off_screen(struct X4_AnimatedObj* arg0, s32 arg1, s32 arg2); /* extern */
void func_8002CCB0(struct X4_BaseObj* arg0, s32 arg1, s32 arg2);    /* extern */
M2C_UNK move_object(void*);                                         /* extern */
M2C_UNK func_8002EE10(struct X4_PlayerObj* arg0);                   /* extern */
void func_800383F8(void*);                                          /* extern */
void func_80044590(void* arg0);                                     /* extern */

void func_800443C4(void* arg0) {
    s8 temp_s0;

    if (is_off_screen(arg0, 0x20, 0x20) == 0) {
        if (M2C_FIELD(arg0, s8*, 0x98) != 0) {
            func_80044590(arg0);
            return;
        }
        animate_object(arg0);
        move_object(arg0);
        {
            // !FAKE: first flag read lands in the first return register
            register s32 flag asm("$2") = M2C_FIELD(arg0, u8*, 0x70);
            if ((flag != 0) ||
                (func_8002EE10(arg0), (M2C_FIELD(arg0, u8*, 0x70) != 0))) {
                if (D_800970A2 != 0) {
                    temp_s0 = M2C_FIELD(arg0, s8*, 1);
                    M2C_FIELD(arg0, s8*, 1) = 0x3A;
                    func_800383F8(arg0);
                    M2C_FIELD(arg0, s8*, 1) = temp_s0;
                } else {
                    func_800383F8(arg0);
                }
                func_80044590(arg0);
            }
        }
        func_8002CCB0(arg0, 0x20, 0x20);
        return;
    }
    func_80044590(arg0);
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern M2C_UNK D_80076148;

void func_800444B0(void* arg0) {
    M2C_FIELD(arg0, s8*, 0x60) = 0;
    M2C_FIELD(arg0, s8*, 0x5C) = 0;
    M2C_FIELD(arg0, s8*, 0x67) = 1;
    M2C_FIELD(arg0, s8*, 3) = 0;
    M2C_FIELD(arg0, s32*, 0x68) = 0;
    M2C_FIELD(arg0, M2C_UNK**, 0x50) = &D_80076148;
    M2C_FIELD(arg0, s32*, 0x54) = 0;
    M2C_FIELD(arg0, s8*, 4) = 1;
    M2C_FIELD(arg0, s8*, 5) = 0;
    M2C_FIELD(arg0, s8*, 6) = 0;
    M2C_FIELD(arg0, s8*, 7) = 0;
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800444EC(void* arg0) {
    void* temp_a1;

    temp_a1 = M2C_FIELD(arg0, void**, 0x7C);
    if (M2C_FIELD(temp_a1, s8*, 4) != 1) {
        M2C_FIELD(arg0, s32*, 0x50) = 0;
        M2C_FIELD(arg0, s8*, 0x98) = 0;
        M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
        return;
    }
    M2C_FIELD(arg0, u16*, 0xA) = (u16)M2C_FIELD(temp_a1, u16*, 0xA);
    M2C_FIELD(arg0, u16*, 0xE) = (u16)M2C_FIELD(temp_a1, u16*, 0xE);
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_80044534(void) {
    clear_object_slot();
}

#define func_80041AB8 func_80044554
#define D_80075FD8 D_8007614C
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_80044590(void* arg0) {
    M2C_FIELD(arg0, s8*, 3) = 0;
    M2C_FIELD(arg0, s8*, 4) = 2;
    M2C_FIELD(arg0, s32*, 0x50) = 0;
    M2C_FIELD(arg0, s32*, 0x68) = 0;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

s32 play_sound(s32 a0, s32 a1, void* arg2);
#define play_sound ((void (*)(s32, s32, void*))play_sound)
M2C_UNK set_animation(void*, M2C_UNK);
#define set_animation ((void (*)(void*, s32))set_animation)
void func_8002CCB0(struct X4_BaseObj* arg0, s32 arg1, s32 arg2);
#define func_8002CCB0 func_8002CCB0
void load_buffered_palette(s32, s32, s32);
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
    if (player->character != 0) {
        arg0->unk38 = SCRATCH_14 + *(s32*)(SCRATCH_14 + 0xC);
        arg0->unk3C = SCRATCH_1C + *(s32*)(SCRATCH_1C + 0x20);
        arg0->unk42 = 0x7848;
        load_buffered_palette(0x50, 0x18, 1);
    } else {
        arg0->unk38 = SCRATCH_14 + *(s32*)(SCRATCH_14 + 0x14);
        arg0->unk3C = SCRATCH_1C + *(s32*)(SCRATCH_1C + 0x34);
        arg0->unk42 = 0x7801;
        load_buffered_palette(0xF, 1, 1);
    }
    arg0->unk40 = 0x520;
    arg0->unk16 = 1;
    arg0->unk15 = player->facing;
    arg0->unk67 = 1;
    F_S8(arg0, 0x9C) = 1;
    F_S8(arg0, 0x9D) = 1;
    if (arg0->unk2 == 0) {
        if (player->character != 0) {
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
        if (player->character != 0) {
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

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

M2C_UNK apply_object_motion();
extern struct X4_PlayerObj g_Player;

#define U8F(p, o) (*(u8*)((u8*)(p) + (o)))
#define S8F(p, o) (*(s8*)((u8*)(p) + (o)))
#define S32F(p, o) (*(s32*)((u8*)(p) + (o)))

void func_800447CC(void* arg0) {
    s32 var_v0;
    s32 var_v1;
    u8 t;
    u8 flags;

    apply_object_motion(arg0);
    flags = U8F(arg0, 0x8F);
    if (flags != 0) {
        if (flags & 4) {
            S32F(arg0, 0x24) = 0xFFFD0000;
        } else if (flags & 8) {
            if (g_Player.character != 0) {
                S32F(arg0, 0x24) = 0x30000;
                S32F(arg0, 0x2C) = 0x2000;
            } else {
                S32F(arg0, 0x24) = 0x60000;
                S32F(arg0, 0x2C) = 0x4000;
            }
        } else if (flags & 2) {
            S32F(arg0, 0x20) = 0x18000;
            U8F(arg0, 0x15) = 0x40;
        } else if (flags & 1) {
            S32F(arg0, 0x20) = 0xFFFE8000;
            U8F(arg0, 0x15) = 0;
        }
        S32F(arg0, 0x8) = S32F(arg0, 0x18);
        S32F(arg0, 0xC) = S32F(arg0, 0x1C);
        apply_object_motion(arg0);
        {
            // !FAKE: depin: dropping it breaks the match (52/82)
            register s32 t asm("$2") = U8F(arg0, 0x90);
            U8F(arg0, 0x90) = t + 1;
            if (g_Player.character != 0) {
                U8F(arg0, 0x90)++;
            }
        }
    }
    if (S8F(arg0, 0x98) != 0) {
        S8F(arg0, 0x98) = 0;
        U8F(arg0, 0x90)++;
        if (D_800970A2 != 0) {
            U8F(arg0, 0x90) += 8;
        }
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

M2C_UNK set_animation(void*, M2C_UNK);
#define set_animation ((void (*)(void*, s32))set_animation)
void func_8002CCB0(struct X4_BaseObj* arg0, s32 arg1, s32 arg2);
#define func_8002CCB0 func_8002CCB0
s32 random_byte();
void load_buffered_palette(s32, s32, s32);
M2C_UNK player_spawn_visual(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2,
                            M2C_UNK arg3);
#define player_spawn_visual player_spawn_visual
extern s32 D_8007616C[];
extern s32 D_80077A0C[];
extern struct X4_PlayerObj g_Player;
extern struct X4_BackgroundObj background_objects[3];

#define SCRATCH_14 (*(u8**)0x1F800014)
#define SCRATCH_1C (*(u8**)0x1F80001C)
#define F_S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define BG (background_objects[player->bg_offset])

void func_80044914(struct X4_WeaponObj* arg0) {
    struct X4_PlayerObj* player;
    s16 a;
    s16 b;
    u8* p;

    if (arg0->unk2 == 0) {
        F_S8(arg0, 0x8D) = 0;
        F_S8(arg0, 0x8C) = 0;
        arg0->unk15 = D_800970B5;
        arg0->state++;
        return;
    }
    player = &g_Player;
    a = player->x_pos.i.hi - BG.x_pos.i.hi;
    b = player->y_pos.i.hi - BG.y_pos.i.hi;
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
    arg0->bg_offset = player->bg_offset;
    arg0->x_vel.val = 0x43E18;
    arg0->y_vel.val = -0x43E18;
    if (arg0->unk15 == 0) {
        arg0->x_vel.val = -0x43E18;
    }
    arg0->unk50 = D_8007616C;
    arg0->unk64 = 1;
    arg0->unk40 = 0x520;
    arg0->unk42 = 0x7801;
    arg0->unk16 = 0x12;
    arg0->unk38 = SCRATCH_14 + *(s32*)(SCRATCH_14 + 0x44);
    p = SCRATCH_1C + *(s32*)(SCRATCH_1C + 0x78);
    arg0->animation_table = (u32**)D_80077A0C;
    arg0->unk3C = p;
    set_animation(arg0, 4);
    player_spawn_visual(1, 0x1B, 3, 0);
    load_buffered_palette(0x12, 1, 1);
    arg0->state++;
    func_8002CCB0(arg0, 0x30, 0x40);
}
#undef set_animation
#undef func_8002CCB0
#undef player_spawn_visual

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define UB(p, off) (*(u8*)((u8*)(p) + (off)))
#define F32(p, off) (*(s32*)((u8*)(p) + (off)))
#define PTR(p, off) (*(void**)((u8*)(p) + (off)))

extern struct X4_BackgroundObj background_objects[3];
M2C_UNK animate_object();
s8* func_8002BEC4(s8* p, s32 dir);
void func_8002CCB0(struct X4_BaseObj* arg0, s32 arg1, s32 arg2);
M2C_UNK move_object(void*);

void func_80044D04(struct X4_BaseObj* self) {
    s8* child;
    s16 dx;
    s16 dy;
    s32 out;
    s32 n;
    u8 t;

    if (self->unk2 == 0) {
        UB(self, 0x8D) += 1;
        t = UB(self, 0x8D);
        if (!(t & 7)) {
            child = func_8002BEC4((s8*)self, 0);
            if (child != 0) {
                child[0] = self->active;
                child[1] = self->id;
                child[2] = 1;
                PTR(child, 0x7C) = self;
                child[0x15] = self->unk15;
                UB(self, 0x8C)++;
            }
            if ((UB(self, 0x8D) >> 3) == 8) {
                self->state = 2;
            }
        }
    } else {
        if (!(D_80097420.frame_counter & 3)) {
            UB(self, 0x64)++;
        }
        animate_object(self);
        move_object(self);
        out = 0;
        dx = self->x_pos.i.hi - background_objects[self->bg_offset].x_pos.i.hi;
        dy = self->y_pos.i.hi - background_objects[self->bg_offset].y_pos.i.hi;
        if (self->unk15 != 0) {
            n = dx - 0x20;
            out = n >= 0x141;
        } else if ((dx + 0x20) < 0) {
            out = 1;
        }
        if ((dy - 0x38) >= 0xF1) {
            out = 1;
        }
        if (out != 0) {
            F32(self, 0x50) = 0;
            self->on_screen = 0;
            self->state = 2;
        }
        func_8002CCB0(self, 0x20, 0x20);
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_8002F288(struct X4_PlayerObj*);
extern void (*D_80076170[])(struct X4_PlayerObj*);
extern struct X4_PlayerObj g_Player;

void func_80044EA0(struct X4_PlayerObj* self) {
    struct X4_PlayerObj* p = &g_Player;
    s32 flag;

    self->unk18.val = self->x_pos.val;
    self->unk1C.val = self->y_pos.val;
    flag = ((s8*)p)[0xD3] != 0;
    if (p->ride_animation != 0) {
        flag = 1;
    }
    if (p->character == 0) {
        if (p->weapon != 4) {
            flag = 1;
        }
        if (p->shot_type == 0xD) {
            flag = 1;
        }
    }
    if (flag != 0) {
        self->state = 2;
    }
    self->shot_fired = self->collision_flags | self->unk71;
    D_80076170[self->state](self);
    func_8002F288((M2C_UNK*)self);
    self->unk71 = 0;
}

#include "common.h"
#include "mmx6/x4.h"

extern struct X4_PlayerObj g_Player;
extern void (*D_80076180[])(struct X4_PlayerObj*);

void func_80044F78(struct X4_PlayerObj* arg0) {
    struct X4_PlayerObj* p;
    s32 var_a1;

    arg0->unk18 = arg0->x_pos;
    arg0->unk1C = arg0->y_pos;
    p = &g_Player;
    var_a1 = ((s8*)p)[0xD3] != 0;
    if (p->ride_animation != 0) {
        var_a1 = 1;
    }
    if (p->weapon != 4) {
        var_a1 = 1;
    }
    if (p->action != 0x28) {
        var_a1 = 1;
    }
    if (var_a1 != 0) {
        arg0->state = 2;
    }
    D_80076180[arg0->state](arg0);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();
s32 is_off_screen(struct X4_AnimatedObj* arg0, s32 arg1, s32 arg2);
void func_80049E50(struct X4_MainObj* self);
extern s32 D_80076160;
extern void (*D_8007617C[])(void*);

void func_80045018(void* arg0) {
    u8 temp_a0;

    if (is_off_screen(arg0, 0x20, 0x20) == 0) {
        animate_object(arg0);
        if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
            M2C_FIELD(arg0, void**, 0x50) = &D_80076160;
        }
        D_8007617C[M2C_FIELD(arg0, s8*, 5)](arg0);
        temp_a0 = M2C_FIELD(arg0, u8*, 0x8F);
        if (((temp_a0 & 0xC) == 0xC) || ((temp_a0 & 3) == 3) ||
            (M2C_FIELD(arg0, u8*, 0x90) >= 8U)) {
            ((s32(*)(void*))func_80049E50)(arg0);
            M2C_FIELD(arg0, s8*, 4) = 2;
        }
    } else {
        M2C_FIELD(arg0, s8*, 3) = 0;
        M2C_FIELD(arg0, s8*, 4) = 2;
    }
}

#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK clear_object_slot();
extern struct X4_PlayerObj g_Player;

void func_800450E0(void* arg0) {
    struct X4_PlayerObj* p = &g_Player;

    M2C_FIELD(arg0, s32*, 0x50) = 0;
    M2C_FIELD(arg0, s32*, 0x68) = 0;
    if (p->character == 0) {
        M2C_FIELD(p, u8*, 0x98) -= 1;
        M2C_FIELD(p, u8*, 0x99) -= 1;
    }
    clear_object_slot(arg0);
}

#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK clear_object_slot();
extern struct X4_PlayerObj g_Player;

void func_80045138(void* arg0) {
    u8 temp_v0;
    void* temp_v1;

    if (M2C_FIELD(arg0, s8*, 0x2) == 0) {
        if (M2C_FIELD(arg0, u8*, 0x8C) == 0) {
            struct X4_PlayerObj* p = &g_Player;
            M2C_FIELD(p, u8*, 0x98) -= 1;
            M2C_FIELD(p, u8*, 0x99) -= 1;
            // !FAKE: retail shares the call block with the else arm
            goto block_5;
        }
    } else {
        temp_v1 = M2C_FIELD(arg0, void**, 0x7C);
        temp_v0 = M2C_FIELD(temp_v1, u8*, 0x8C);
        if (temp_v0 != 0) {
            M2C_FIELD(temp_v1, u8*, 0x8C) = temp_v0 - 1;
        }
    block_5:
        clear_object_slot(arg0, arg0);
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

s32 play_sound(s32 a0, s32 a1, void* arg2);
#define play_sound ((void (*)(s32, s32, void*))play_sound)
M2C_UNK set_animation(void*, M2C_UNK);
#define set_animation ((void (*)(void*, s32))set_animation)
void func_80017B04(u8*, s16, s16);
#define func_80017B04 func_80017B04
s8* func_8002BEC4(s8* p, s32 dir);
void load_buffered_palette(s32, s32, s32);
M2C_UNK player_spawn_visual(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2,
                            M2C_UNK arg3);
#define player_spawn_visual player_spawn_visual
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
            register s32 t asm("$3") = player->character;
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
        if (player->character != 0) {
            F_U8(arg0, 0x48) = 0xFF;
            F_S8(arg0, 0x47) = 0;
            arg0->unk49 = 1;
            {
                u8* q = SCRATCH_14;
                arg0->unk38 = q + *(s32*)(q + 0x14);
            }
            func_80017B04(arg0, 0x140, 0x40);
            load_buffered_palette(0x52, 0x19, 1);
        }
        return;
    }
    if (player->character != 0) {
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
        load_buffered_palette(0x1B, 1, 1);
    }
    arg0->animation_table = (u32**)D_80077A40;
    arg0->unk16 = 1;
    F_S8(arg0, 0x9C) = 1;
    arg0->on_screen = 1;
    arg0->unk15 = 0;
    if (player->facing != 0) {
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
