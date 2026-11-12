#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

M2C_UNK set_animation(void*, M2C_UNK);
extern void (*D_800761A8[])();
extern struct X4_PlayerObj g_Player;

#define F_S8(p, o) (*(s8*)((u8*)(p) + (o)))

void func_800456D4(struct X4_WeaponObj* arg0) {
    struct X4_PlayerObj* player;
    s8 idx;

    if (arg0->unk2 != 0 && arg0->id == 7) {
        player = &g_Player;
        if (player->facing != 0) {
            arg0->x_pos.i.hi =
                player->x_pos.i.hi - (s8)D_80076194[arg0->unk2 - 1][0];
        } else {
            arg0->x_pos.i.hi =
                player->x_pos.i.hi + (s8)D_80076194[arg0->unk2 - 1][0];
        }
        idx = arg0->unk2;
        arg0->y_pos.i.hi = player->y_pos.i.hi + (s8)D_80076194[idx - 1][1];
        if (F_S8(arg0->owner, 0x8D) != 0) {
            if (idx < 3) {
                ((void (*)(void*, s32))set_animation)(arg0, 4);
            } else {
                ((void (*)(void*, s32))set_animation)(arg0, 5);
            }
            arg0->unk50 = 0;
            arg0->state = 2;
            return;
        }
    }
    D_800761A8[arg0->unk5](arg0);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK clear_object_slot();
s32 get_weapon_energy_cost(void* arg0, s32 arg1);
void use_weapon_energy(void*, s32);
extern struct X4_PlayerObj g_Player;

void func_80045810(u8* arg0) {
    u8* p;
    u8* q;
    s8 idx;
    s16 v;

    if (*(s8*)(arg0 + 2) == 0) {
        if (*(s8*)(arg0 + 0x8C) != 0) {
            return;
        }
        {
            u8* r = (u8*)&g_Player;
            r[0x98]--;
            r[0x99]--;
        }
    } else {
        q = *(u8**)(arg0 + 0x7C);
        if (*(s8*)(q + 0x8C) != 0) {
            q[0x8C]--;
        }
        if (*(s8*)(arg0 + 0x8F) != 0) {
            p = (u8*)&g_Player;
            idx = 4;
            if (*(s8*)(p + 2) == 0) {
                idx = *(s8*)(p + 0x93);
            }
            v = *(s16*)((u8*)&g_Player + (idx << 1) + 0xA8);
            if (v >= get_weapon_energy_cost(p, idx)) {
                if (*(s8*)(p + 2) != 0) {
                    *(s8*)(p + 0x93) = 4;
                    use_weapon_energy(p, 4);
                } else {
                    use_weapon_energy(p, *(s8*)(arg0 + 1));
                }
            }
        }
    }
    clear_object_slot(arg0);
}

#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

s32 play_sound(s32 a0, s32 a1, void* arg2);
#define play_sound ((void (*)(s32, s32, void*))play_sound)
M2C_UNK set_animation(void*, M2C_UNK);
#define set_animation ((void (*)(void*, s32))set_animation)
void load_buffered_palette(s32, s32, s32);
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
        load_buffered_palette(0x1E, 1, 1);
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

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object(); /* extern */
extern s16 D_800761FC[];
extern u8 D_8007620C[];

void func_80045C14(void* arg0) {
    s16 a;
    s16 b;
    s32 i;
    u16 x;
    u16 y;
    s8 t;
    void* p;

    p = M2C_FIELD(arg0, void**, 0x7C);
    if (M2C_FIELD(p, s8*, 0x91) != 0) {
        M2C_FIELD(arg0, u8*, 4) = 3;
        return;
    }
    ((void (*)())animate_object)(arg0);
    i = (M2C_FIELD(arg0, s8*, 2) - 1) * 4;
    a = *(s16*)(i + (u8*)D_800761FC);
    b = *(s16*)((u8*)D_800761FC + i + 2);
    t = ++M2C_FIELD(arg0, u8*, 0x8E);
    if (t >= 20) {
        {
            u8 v;
            M2C_FIELD(p, u8*, 0x8C)++;
            M2C_FIELD(arg0, s16*, 0xA) = a;
            M2C_FIELD(arg0, s16*, 0xE) = b;
            v = D_8007620C[M2C_FIELD(arg0, s8*, 2) - 1];
            M2C_FIELD(arg0, u8*, 5)++;
            M2C_FIELD(arg0, u8*, 0x47) = v;
        }
        return;
    }
    x = M2C_FIELD(arg0, u16*, 0x92);
    y = M2C_FIELD(arg0, u16*, 0x94);
    M2C_FIELD(arg0, s16*, 0xA) = x + (t * (s16)(a - x)) / 20;
    M2C_FIELD(arg0, s16*, 0xE) = y + (t * (s16)(b - y)) / 20;
}

#include "common.h"
#include "mmx6/x4.h"

extern struct X4_PlayerObj g_Player;
extern void (*D_800761BC[])(void*);

#define PL_S8(p, o) (*(s8*)((u8*)(p) + (o)))

void func_80045D68(struct ObjectHeader* arg0) {
    struct X4_PlayerObj* p;
    s32 var_a1;

    p = &g_Player;
    var_a1 = PL_S8(p, 0xD3) != 0;
    if (PL_S8(p, 0xD4) != 0) {
        var_a1 = 1;
    }
    if ((p->character == 1) && (p->stock_charge != 2)) {
        var_a1 = 1;
    }
    if (((u8)p->character == 0) && (p->weapon != 7)) {
        var_a1 = 1;
    }
    if (PL_S8(p, 0xD5) != 0) {
        var_a1 = 1;
    }
    if (((u8)p->character == 0) && (p->shot_type == 0x10)) {
        var_a1 = 1;
    }
    if (p->hp == 0) {
        var_a1 = 1;
    }
    if (var_a1 != 0) {
        arg0->state = 3;
    }
    D_800761BC[arg0->state](arg0);
}

#undef PL_S8

#include "common.h"
#include "mmx6/x4.h"

extern struct X4_PlayerObj g_Player;
extern void (*D_8007622C[])(s8*);

void func_80045E58(s8* arg0) {
    s8* p;
    s32 flag;

    p = (s8*)&g_Player;
    flag = p[0xD3] != 0;
    if (p[0xD4] != 0) {
        flag = 1;
    }
    if (p[0x93] != 7) {
        flag = 1;
    }
    if (flag != 0) {
        arg0[4] = 3;
    }
    D_8007622C[arg0[4]](arg0);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

void func_80045ED4(struct X4_WeaponObj* arg0, struct X4_PlayerObj* arg1) {
    if (arg1->facing != 0) {
        arg0->x_pos.i.hi = arg1->x_pos.i.hi - (s8)D_80076194[arg0->unk2 - 1][0];
    } else {
        arg0->x_pos.i.hi = arg1->x_pos.i.hi + (s8)D_80076194[arg0->unk2 - 1][0];
    }
    arg0->y_pos.i.hi = arg1->y_pos.i.hi + (s8)D_80076194[arg0->unk2 - 1][1];
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

s32 play_sound(s32 a0, s32 a1, void* arg2);
s32 get_weapon_energy_cost(void* arg0, s32 arg1);
extern struct X4_PlayerObj g_Player;

#define F5F78(p, t, o) (*(t*)((u8*)(p) + (o)))

void func_80045F78(void* arg0) {
    struct X4_PlayerObj* p = &g_Player;
    s32 hit = 0;
    s32 v;

    if (p->character != 0) {
        s16 w = F5F78(p, s16, 0xB0);

        hit = w < get_weapon_energy_cost(p, 4);
    } else {
        v = ((s16*)((u8*)&g_Player + 0xA8))[p->weapon];
        v = v < get_weapon_energy_cost(p, p->weapon);
        if (v) {
            hit = 1;
        }
    }
    if (p->character == 0 && (F5F78(p, u16, 0x80) & 0x10)) {
        hit = 1;
    }
    if (hit != 0) {
        play_sound(1, 0x1D, arg0);
        F5F78(arg0, u8, 0x8D) = 1;
        F5F78(arg0, u8, 0x4) = 3;
    }
}

#undef F5F78

#include "common.h"
#define M2C_UNK s32

M2C_UNK animate_object();
extern s32 D_8007618C;
extern s32 D_80076190;

void func_8004605C(u8* arg0) {
    s32* var_v0;

    ((void (*)())animate_object)();
    if (*(s8*)(arg0 + 0x45) != 0) {
        if (*(s8*)(arg0 + 2) < 3) {
            var_v0 = &D_8007618C;
        } else {
            var_v0 = &D_80076190;
        }
        *(s32**)(arg0 + 0x50) = var_v0;
        do {
        } while (0);
        arg0[5]++;
    }
}

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();

void func_800460C8(void* arg0) {
    ((void (*)())animate_object)();
    if (M2C_FIELD(arg0, u8*, 0x9C) & 2) {
        M2C_FIELD(arg0, s8*, 0x8F) = 1;
        if (M2C_FIELD(arg0, s8*, 0x2) < 3) {
            set_animation(arg0, 2);
        } else {
            set_animation(arg0, 3);
        }
        M2C_FIELD(arg0, s8*, 0x8E) = 0x14;
        M2C_FIELD(arg0, u8*, 0x5) = M2C_FIELD(arg0, u8*, 0x5) + 1;
    }
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK animate_object();
s32 is_off_screen(struct X4_AnimatedObj* arg0, s32 arg1, s32 arg2);
M2C_UNK move_object(void*);
M2C_UNK func_8002EE10(struct X4_PlayerObj* arg0);
void func_80049D90(void*);

void func_80046148(u8* arg0) {
    if (is_off_screen(arg0, 0x20, 0x20) == 0) {
        arg0[3] = 1;
        animate_object(arg0);
        move_object(arg0);
        {
            // !FAKE: depin: dropping it breaks the match (36/38)
            register s32 t asm("$2") = *(s8*)(arg0 + 0x98);
            if (t != 0) {
                // !FAKE: goto skips to the shared state store; nesting the tail under t == 0 added an epilogue
                goto block_5;
            }
        }
        if (arg0[0x70] == 0) {
            func_8002EE10(arg0);
            if (arg0[0x70] == 0) {
                return;
            }
        }
        func_80049D90(arg0);
    }
block_5:
    arg0[3] = 0;
    arg0[4] = 3;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

M2C_UNK animate_object();
extern struct X4_PlayerObj g_Player;

#define F_S8(p, o) (*(s8*)((u8*)(p) + (o)))

void func_800461E0(struct X4_WeaponObj* arg0) {
    struct X4_PlayerObj* player;

    player = &g_Player;
    if (player->facing != 0) {
        arg0->x_pos.i.hi =
            player->x_pos.i.hi - (s8)D_80076194[arg0->unk2 - 1][0];
    } else {
        arg0->x_pos.i.hi =
            player->x_pos.i.hi + (s8)D_80076194[arg0->unk2 - 1][0];
    }
    arg0->y_pos.i.hi = player->y_pos.i.hi + (s8)D_80076194[arg0->unk2 - 1][1];
    ((void (*)())animate_object)(arg0);
    if (F_S8(arg0, 0x46) == 0) {
        arg0->on_screen = 0;
        arg0->state = 3;
    }
}

#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern struct X4_PlayerObj g_Player;

void func_800462C0(void* arg0) {
    struct X4_PlayerObj* p = &g_Player;

    if (p->action != 0x2A) {
        M2C_FIELD(arg0, s8*, 0x91) = 1;
        M2C_FIELD(arg0, s8*, 0x4) = 3;
        return;
    }
    if (M2C_FIELD(arg0, s8*, 0x8C) == 4) {
        p->action_phase = 1;
        M2C_FIELD(arg0, u8*, 0x5) += 1;
    }
}

#include "common.h"
#include "mmx6/globals.h"

void func_80046318(s8* arg0) {
    if (arg0[0x90] == 0 || --arg0[0x90] == 0) {
        if (D_80097120 & 0x10) {
            arg0[0x90] = 0x32;
            arg0[0x8F] = 1;
            if (++arg0[0x8E] >= 8) {
                arg0[0x8D] = 1;
                arg0[4] = 3;
            }
        }
    } else {
        arg0[0x8F] = 0;
    }
}

#include "common.h"

#define NULL ((void*)0)
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* func_8003D480(s8 arg0, s8 arg1, s8 arg2, s32 arg3); /* extern */

void func_80046394(void* arg0) {
    void* temp_s0;
    void* temp_v0;

    temp_s0 = M2C_FIELD(arg0, void**, 0x7C);
    if (M2C_FIELD(temp_s0, s8*, 0x91) != 0) {
        M2C_FIELD(arg0, s8*, 4) = 3;
        return;
    }
    if (M2C_FIELD(temp_s0, s8*, 0x8F) != 0) {
        temp_v0 = func_8003D480(1, M2C_FIELD(arg0, s8*, 1),
                                (s8)(M2C_FIELD(arg0, u8*, 2) + 4), arg0);
        if (temp_v0 != NULL) {
            M2C_FIELD(temp_s0, u8*, 7) = (u8)(M2C_FIELD(temp_s0, u8*, 7) + 1);
            M2C_FIELD(temp_v0, void**, 0x7C) = temp_s0;
        }
    } else if (M2C_FIELD(temp_s0, s8*, 0x8D) != 0) {
        M2C_FIELD(arg0, s8*, 0x8E) = 0;
        M2C_FIELD(arg0, u8*, 5) = (u8)(M2C_FIELD(arg0, u8*, 5) + 1);
    }
}

#include "common.h"

void func_80046440(u8* arg0) {
    s32 v;

    v = arg0[0x8E] + 1;
    arg0[0x8E] = v;
    arg0[3] = v & 1;
    if ((s8)v >= 0x14) {
        arg0[4] = 3;
    }
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK animate_object();
extern s32 D_800761A4;

void func_80046478(u8* arg0) {
    ((void (*)())animate_object)();
    if (*(s8*)(arg0 + 0x45) & 0x80) {
        *(s32**)(arg0 + 0x50) = &D_800761A4;
        arg0[5] = arg0[5] + 1;
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();              /* extern */
s32 func_8002CB50(struct X4_BaseObj*); /* extern */
#define func_8002CB50 func_8002CB50
s32 is_off_screen(struct X4_AnimatedObj* arg0, s32 arg1, s32 arg2); /* extern */
M2C_UNK move_object(void*);                                         /* extern */

void func_800464C4(struct ObjectHeader* arg0) {
    ((M2C_UNK(*)())animate_object)();
    move_object(arg0);
    if (is_off_screen(arg0, 0x10, 0x10) != 0) {
        arg0->state = 3;
    }
    func_8002CB50(arg0);
}
#undef func_8002CB50

#define func_80041AB8 func_80046514
#define D_80075FD8 D_80076210
#define FAMILY_FIELD 5
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK clear_object_slot();
extern struct X4_PlayerObj g_Player;

void func_80046550(s8* arg0) {
    s8* p;
    s8* var_a1;

    if (arg0[2] == 0) {
        if (arg0[0x8F] != 0) {
            arg0[0x8F] = 0;
        }
        if (arg0[7] != 0) {
            return;
        }
        var_a1 = (s8*)&g_Player;
        if (var_a1[0xA6] == 2) {
            var_a1[0xA6] = 0;
        }
        ((u8*)var_a1)[0x98] = ((u8*)var_a1)[0x98] - 1;
        ((u8*)var_a1)[0x99] = ((u8*)var_a1)[0x99] - 1;
    } else {
        p = *(s8**)(arg0 + 0x7C);
        var_a1 = (s8*)(u32)(u8)p[7];
        if (p[7] != 0) {
            p[7] = (s32)var_a1 - 1;
        }
    }
    ((void (*)())clear_object_slot)(arg0, var_a1);
}

#define func_80041AB8 func_800465F4
#define D_80075FD8 D_80076248
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s32 D_8007623C;
extern s32 D_80076240;
extern s32 D_80076244;

void func_80046630(void* arg0) {
    s8 temp_v1;
    void* temp_a2;
    u16 e;

    M2C_FIELD(arg0, s8*, 0x4) = 1;
    temp_v1 = M2C_FIELD(arg0, s8*, 0x2);
    temp_a2 = M2C_FIELD(arg0, void**, 0x7C);
    M2C_FIELD(arg0, s8*, 0x3) = 0;
    M2C_FIELD(arg0, s8*, 0x16) = 0;
    M2C_FIELD(arg0, s32*, 0x68) = 0;
    M2C_FIELD(arg0, s32*, 0x54) = 0;
    M2C_FIELD(arg0, s32**, 0x50) = &D_8007623C;
    switch (temp_v1) {
    case 0:
        M2C_FIELD(arg0, s32**, 0x50) = &D_8007623C;
        break;
    case 1:
        M2C_FIELD(arg0, s32**, 0x50) = &D_80076240;
        break;
    case 2:
        M2C_FIELD(arg0, s32**, 0x50) = &D_80076244;
        break;
    }
    M2C_FIELD(arg0, u16*, 0xA) = M2C_FIELD(temp_a2, u16*, 0xA);
    e = M2C_FIELD(temp_a2, u16*, 0xE);
    M2C_FIELD(arg0, s8*, 0x5C) = 0;
    M2C_FIELD(arg0, s8*, 0x60) = 0;
    M2C_FIELD(arg0, u16*, 0xE) = e;
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800466C4(void* arg0) {
    void* temp_a1;

    temp_a1 = M2C_FIELD(arg0, void**, 0x7C);
    if (M2C_FIELD(temp_a1, s8*, 4) == 1) {
        M2C_FIELD(arg0, u16*, 0xA) = (u16)M2C_FIELD(temp_a1, u16*, 0xA);
        M2C_FIELD(arg0, u16*, 0xE) = (u16)M2C_FIELD(temp_a1, u16*, 0xE);
        if (M2C_FIELD(arg0, s8*, 2) != 0) {
            // !FAKE: goto shares the state store with the else arm; duplicating the store moved bytes
            goto block_3;
        }
    } else {
    block_3:
        M2C_FIELD(arg0, s8*, 4) = 2;
    }
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_8004670C(void) {
    clear_object_slot();
}

/* Adapted from sozud/mmx4 @4e16dfc src/main/weapons/weapon_61_ride_armor_punch.c:ride_armor_punch_main, AGPL-3.0; proven shared with X6 by exact signature e7d22a6ee35c (see THIRD_PARTY.md). */
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
extern u8 D_80076254[][4];
extern u8 D_80076270[8];
extern u8 D_80076278[8];
M2C_UNK clear_object_slot();

void func_8004672C(struct X4_WeaponObj* self) {
    s8 index;
    s8 event;
    u16 timer;
    struct X4_PlayerObj* owner;

    owner = self->owner;
    self->x_pos.i.hi = (s16)(u16)owner->x_pos.i.hi;
    self->y_pos.i.hi = (s16)(u16)owner->y_pos.i.hi;
    self->animation_step.fields.event =
        (owner->animation_step.fields.event >> 4) & 0xF;
    if (self->unk2 != 0) {
        timer = --self->unk88.half;
        if ((timer << 16) == 0) {
            self->unk88.half = 6;
            self->unk64 = (u8)self->unk64 + 1;
        }
    }
    index = self->unk2;
    if ((D_80076270[index] == owner->unk17) &&
        (D_80076278[index] == owner->action) && (owner->state == 1)) {
        event = self->animation_step.fields.event;
        if (event == 0) {
            self->unk50 = NULL;
            return;
        }
        self->unk50 = &D_80076254[event];
        return;
    }
    clear_object_slot(OBJECT_HEADER(self));
}

#define func_80041AB8 func_80046830
#define D_80075FD8 D_80076280
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

/* Adapted from sozud/mmx4 @4e16dfc src/main/weapons/weapon_61_ride_armor_punch.c:ride_armor_punch_init, AGPL-3.0; proven shared with X6 by exact signature ef5dce611697 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
void func_8004672C(struct X4_WeaponObj*);

void func_8004686C(struct X4_WeaponObj* arg0) {
    arg0->state = 1;
    arg0->on_screen = 0;
    arg0->bg_offset = 0;
    arg0->unk68 = NULL;
    arg0->unk54 = 0;
    arg0->unk50 = 0;
    arg0->unk64 = 1;
    arg0->unk5C = 1;
    arg0->unk60 = 3;
    arg0->unk88.half = 6;
    func_8004672C(arg0);
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800468BC(void) {
    clear_object_slot();
}

#include "common.h"
#define M2C_UNK s32

s32 func_8002CB50(struct X4_BaseObj*); /* extern */
#include "mmx6/state.h"

#define F8(p, o) (*(s8*)((u8*)(p) + (o)))
#define U8F(p, o) (*(u8*)((u8*)(p) + (o)))
#define F16(p, o) (*(s16*)((u8*)(p) + (o)))
#define F32(p, o) (*(s32*)((u8*)(p) + (o)))
#define SCRATCH_3C (*(u8**)0x1F80003C)

void func_800468DC(void* arg0) {
    s32 v;
    u8 raw;
    u8* p;

    v = F8(arg0, 2);
    raw = U8F(arg0, 2);
    if (v < 0) {
        F8(arg0, 0x14) = -1;
        F8(arg0, 0x16) = 0;
        F8(arg0, 0x15) = 0;
        if (v == -1) {
            s32 t;
            u8* q;
            F16(arg0, 0x40) = 0x1E00;
            q = SCRATCH_3C;
            t = *(s32*)q;
            F16(arg0, 0x42) = 0x7E11;
            q += t;
            F32(arg0, 0x3C) = (s32)q;
            F16(arg0, 0xE) = *(u8*)(D_80097420.transition.selection * 2 +
                                    *(u8**)((u8*)arg0 + 0x50));
            v = D_80097420.transition.selection;
            F8(arg0, 0x47) = 0x47;
            F8(arg0, 0x54) = v;
        } else {
            F16(arg0, 0x40) = 0x1F00;
            p = SCRATCH_3C;
            v = *(s32*)(p + 4);
            F16(arg0, 0x42) = 0x7C10;
            F16(arg0, 0xA) = 0xA0;
            F16(arg0, 0xE) = 0xD0;
            F8(arg0, 0x47) = 0x2B;
            p += v;
            F32(arg0, 0x3C) = (s32)p;
        }
        F8(arg0, 4) = 1;
    } else {
        s32 t;
        u8* q;
        F16(arg0, 0x40) = 0x1F00;
        q = SCRATCH_3C;
        t = *(s32*)(q + 4);
        F8(arg0, 0x14) = -1;
        F8(arg0, 0x15) = 0;
        F16(arg0, 0xA) = 0xA0;
        F8(arg0, 0x16) = 0;
        q += t;
        F32(arg0, 0x3C) = (s32)q;
        if (v == 0x20) {
            F16(arg0, 0x42) = 0x7C11;
            F8(arg0, 4) = 1;
        } else {
            F16(arg0, 0x42) = 0x7C10;
            if (v < 7) {
                F16(arg0, 0xA) = 0x20;
                F8(arg0, 4) = 3;
            } else if (v < 0x10) {
                F16(arg0, 0xA) = 0x110;
                F8(arg0, 2) = raw - 7;
                F8(arg0, 4) = 4;
            } else {
                F8(arg0, 4) = 2;
            }
        }
    }
    ((s32(*)())func_8002CB50)(arg0);
}

#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002CB50(struct X4_BaseObj*);

void func_80046A60(void* self, s32 arg1, u8* p) {
    if (M2C_FIELD(self, s8*, 0x2) == -1) {
        p = (u8*)&D_80097420;
        if (M2C_FIELD(self, u8*, 0x54) != D_80097420.transition.selection) {
            M2C_FIELD(self, s16*, 0xE) = M2C_FIELD(
                self, u8**, 0x50)[D_80097420.transition.selection * 2];
            M2C_FIELD(self, u8*, 0x54) = D_80097420.transition.selection;
        }
    }
    ((s32(*)())func_8002CB50)(self, self, p);
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_80046AD0(void* arg0) {
    s16 var_v0;

    var_v0 = 0x7C10;
    if (M2C_FIELD(arg0, s8*, 7) == D_80097420.transition.selection) {
        var_v0 = 0x7C12;
    }
    M2C_FIELD(arg0, s16*, 0x42) = var_v0;
    M2C_FIELD(arg0, s8*, 3) = 1;
}

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

s32 func_8002CB50(struct X4_BaseObj*);
extern u8 D_80076298[];

void func_80046B00(struct X4_BaseObj* arg0) {
    u8 i;
    s32 sel;
    u16 btn;
    // !FAKE: depin: dropping it breaks the match (61/67)
    register s32 one asm("$6") = 1;

    i = 0;
    if (D_80073610[arg0->unk2] == one) {
        sel = 0;
    } else {
    next:
        i++;
        if (i < 16) {
            // !FAKE: depin: dropping it breaks the match (61/67)
            register s32 b asm("$5") = 1;

            if ((b << i) == D_80073610[arg0->unk2]) {
                do {
                    sel = i;
                } while (0);
            } else {
                // !FAKE: goto: rotated loop shape of twin rock_18 func_800EA0E8 (block order)
                goto next;
            }
        }
    }
    btn = button_map[sel];
    for (i = 0; i < 8; i++) {
        if (btn == D_80073620[i]) {
            ((u8*)arg0)[0x47] = D_80076298[i];
            break;
        }
    }
    ((s32(*)())func_8002CB50)(arg0, btn, one, i);
}

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

extern u8 option_values[];
s32 func_8002CB50(struct X4_BaseObj*);

#define F8(p, o) (*(s8*)((u8*)(p) + (o)))

void func_80046C0C(struct X4_MainObj* arg0) {
    if (g_temp_options & option_values[arg0->unk2]) {
        F8(arg0, 0x47) = 0xA;
    } else {
        F8(arg0, 0x47) = 0xB;
    }
    func_8002CB50((struct X4_BaseObj*)arg0);
}

#include "../shared/d1000/func_80046C64.c"

#include "common.h"
#define M2C_UNK s32

s32 func_8002CB50(struct X4_BaseObj*); /* extern */

#define F8(p, o) (*(s8*)((u8*)(p) + (o)))
#define U8F(p, o) (*(u8*)((u8*)(p) + (o)))
#define F16(p, o) (*(s16*)((u8*)(p) + (o)))
#define F32(p, o) (*(s32*)((u8*)(p) + (o)))
#define SCRATCH_3C (*(u8**)0x1F80003C)

void func_80046CA4(void* arg0) {
    u8* q;
    s32 t;

    F8(arg0, 0x14) = -1;
    if (F8(arg0, 2) == -1) {
        F16(arg0, 0x40) = 0x1E00;
        q = SCRATCH_3C;
        t = *(s32*)q;
        F16(arg0, 0x42) = 0x7E10;
        F8(arg0, 0x16) = 7;
        F8(arg0, 3) = 1;
        F8(arg0, 4) = 2;
        q += t;
        F32(arg0, 0x3C) = (s32)q;
    } else {
        u8* p;
        F16(arg0, 0x40) = 0x1F00;
        p = SCRATCH_3C;
        F32(arg0, 0x3C) = (s32)(p + *(s32*)(p + 4));
        if (F16(arg0, 0xE) == 0x10) {
            F16(arg0, 0x42) = 0x7C11;
        } else {
            F16(arg0, 0x42) = 0x7C10;
        }
        F16(arg0, 0xA) = 0xA0;
        F8(arg0, 0x16) = 0;
        F8(arg0, 0x47) = F8(arg0, 2);
        F8(arg0, 4) = F8(arg0, 4) + 1;
        func_8002CB50(arg0);
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002CB50(struct X4_BaseObj*); /* extern */

void func_80046D78(void* arg0) {
    s16 var_v0;

    if (M2C_FIELD(arg0, s16*, 0xE) != 0x10) {
        var_v0 = 0x7C10;
        if (M2C_FIELD(arg0, s8*, 7) == D_80097420.transition.selection) {
            var_v0 = 0x7C12;
        }
        M2C_FIELD(arg0, s16*, 0x42) = var_v0;
    }
    ((s32(*)())func_8002CB50)(arg0, arg0);
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_80046DC8(struct ObjectHeader* arg0) {
    arg0->on_screen = 1;
}

#define func_80046C64 func_80046DD4
#define D_800762A0 D_800762B4
#include "../shared/d1000/func_80046C64.c"
#undef func_80046C64
#undef D_800762A0
