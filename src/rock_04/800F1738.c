#include "common.h"
#include "mmx6/globals.h"
#include "mmx6/rock_04.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
void func_800F4FD8(void*);
extern M2C_UNK D_8007433C;
extern void (*D_800F7518[])(void*);

void func_800F1738(void* arg0) {
    s32 r;
    u16 t;

    animate_object();
    D_800F7518[M2C_FIELD(arg0, s8*, 5)](arg0);
    func_800F4FD8(arg0);
    if (M2C_FIELD(arg0, s8*, 5) != 2 && M2C_FIELD(arg0, s8*, 2) == 0) {
        D_800F7840++;
    }
    M2C_FIELD(arg0, s8*, 0x8D) = 0;
    r = check_enemy_hits(arg0);
    if (r < 0) {
        D_8009711A = 1;
        M2C_FIELD(arg0, s8*, 4) = 2;
        M2C_FIELD(arg0, s8*, 5) = 0;
        return;
    }
    if (r > 0) {
        if (r != 0x7F) {
            M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
            if ((u32)(r - 0x19) < 2) {
                M2C_FIELD(arg0, s16*, 0x88) = 2;
            } else {
                M2C_FIELD(arg0, s16*, 0x88) = 0x1E;
            }
            if (r == 4 || r == 0xD || r == 0x23) {
                M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
                M2C_FIELD(arg0, s16*, 0x88) = 0x2710;
                M2C_FIELD(arg0, s8*, 5) = 3;
                M2C_FIELD(arg0, s8*, 6) = 0;
            }
        } else {
            M2C_FIELD(arg0, s8*, 0x8D) = 1;
        }
    }
    t = M2C_FIELD(arg0, u16*, 0x88);
    if (M2C_FIELD(arg0, s16*, 0x88) != 0) {
        M2C_FIELD(arg0, s16*, 0x88) = t - 1;
        if (t & 2) {
            M2C_FIELD(arg0, u16*, 0x42) |= 0x8000;
        } else {
            M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
        }
        if (M2C_FIELD(arg0, s16*, 0x88) == 0) {
            M2C_FIELD(arg0, void**, 0x58) = &D_8007519C;
            M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
        }
    }
    func_80030ECC(arg0);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/rock_04.h"

M2C_UNK clear_object_slot();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
void func_800F54B8(s32, void*);
extern struct X4_EngineObj g_playthrough_state;

#define SB(p, o) (*(s8*)((u8*)(p) + (o)))
#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define UH(p, o) (*(u16*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))
#define P(p, o) (*(void**)((u8*)(p) + (o)))

void func_800F18C4(void* arg0) {
    void* parent;

    parent = P(arg0, 0x80);
    UB(arg0, 3) = 0;
    if (SB(parent, 0) != 0) {
        if (SB(parent, 7) == 0) {
            if ((s16)--UH(arg0, 0x7E) == -1) {
                UH(arg0, 0x7E) = 5;
                UH(arg0, 0x42) ^= 0x8000;
            }
            func_8002CCB0(arg0, 0x60, 0x60);
        }
    } else {
        P(arg0, 0x80) = NULL;
        W(arg0, 0x84) = 0;
        W(arg0, 0x88) = 0;
        W(arg0, 0x8C) = 0;
        W(arg0, 0x90) = 0;
        W(arg0, 0x94) = 0;
        g_playthrough_state.enable_boss = 0;
        g_playthrough_state.boss_ptr = NULL;
        if (g_playthrough_state.stage != 0xC) {
            if (D_800F7840 < 0x1519) {
                func_800F54B8(0x10, &g_playthrough_state);
            } else {
                func_800F54B8(0x11, &g_playthrough_state);
            }
        } else {
            g_playthrough_state.unkF = -0x80;
            g_playthrough_state.character_state
                .bytes[g_playthrough_state.checkpoint + 6] = 1;
            g_playthrough_state.checkpoint += 8;
        }
        clear_object_slot(arg0);
    }
}

#include "../shared/rock_04/func_800F19EC.c"

#include "../shared/rock_04/func_800F1B50.c"

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK move_object(void*);
s32 random_byte();
void func_800F513C(struct X4_AnimatedObj* arg0, u8 arg1);
void func_800F5360(void*, s32);
extern struct X4_PlayerObj g_Player;

#define SB(p, o) (*(s8*)((u8*)(p) + (o)))
#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define SH(p, o) (*(s16*)((u8*)(p) + (o)))
#define UH(p, o) (*(u16*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))

void func_800F1CF0(void* arg0) {
    move_object(arg0);
    {
        // !FAKE: depin: dropping it breaks the match (110/112)
        register s32 f asm("$2") = UB(arg0, 0x15);
        if (f == 0) {
            if (g_Player.x_pos.i.hi >= SH(arg0, 0xA) || (UB(arg0, 0x70) & 2)) {
                set_animation(arg0, 0x17);
                {
                    // !FAKE: depin: dropping it breaks the match (24/112)
                    register s32 k asm("$2") = 0xFFFA0000;
                    W(arg0, 0x20) = k;
                }
                UH(arg0, 0x7C) = 8;
                {
                    // !FAKE: depin: dropping it breaks the match (26/112)
                    register s32 c asm("$3") = UB(arg0, 6);
                    UB(arg0, 6) = c + 1;
                }
                return;
            }
            if (SH(arg0, 0x84) >= SH(arg0, 0xA)) {
                SH(arg0, 0x84) =
                    UH(arg0, 0xA) - ((random_byte() & 0x1F) | 0x20);
                func_800F513C(arg0, 0x10);
            }
        } else {
            if (g_Player.x_pos.i.hi <= SH(arg0, 0xA) || (UB(arg0, 0x70) & 1)) {
                set_animation(arg0, 0x17);
                {
                    // !FAKE: depin: dropping it breaks the match (25/112)
                    register s32 k asm("$2") = 0x60000;
                    W(arg0, 0x20) = k;
                }
                UH(arg0, 0x7C) = 8;
                {
                    // !FAKE: depin: dropping it breaks the match (27/112)
                    register s32 c asm("$3") = UB(arg0, 6);
                    UB(arg0, 6) = c + 1;
                }
                return;
            }
            if (SH(arg0, 0xA) >= SH(arg0, 0x84)) {
                SH(arg0, 0x84) =
                    UH(arg0, 0xA) + ((random_byte() & 0x1F) | 0x20);
                func_800F513C(arg0, 0x10);
            }
        }
    }
    if (g_Player.action == 9 || g_Player.action == 0xB ||
        g_Player.action == 0x34) {
        SB(arg0, 5) = 9;
        SB(arg0, 6) = 0;
        return;
    }
    if (--SH(arg0, 0x7C) == 0) {
        UH(arg0, 0x7C) = 8;
        func_800F5360(arg0, 1);
    }
}

#include "../shared/rock_04/func_800F1EB0.c"

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK start_pad_vibration(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK move_object(void*);
void func_800F5088(struct X4_AnimatedObj* arg0, u8 arg1);

void func_800F1FE0(void* arg0) {
    s32 var_v0;
    u8 temp_v1;

    temp_v1 = M2C_FIELD(arg0, u8*, 0x70);
    if (temp_v1 & 8) {
        play_sound(2, 0x12, arg0);
        start_pad_vibration(8);
        set_animation(arg0, 9);
        {
            // !FAKE: depin: dropping it breaks the match (51/56)
            register s32 t asm("$2") = M2C_FIELD(arg0, u8*, 6) + 1;
            M2C_FIELD(arg0, s16*, 0x7C) = 0x1E;
            M2C_FIELD(arg0, u8*, 6) = t;
        }
        return;
    }
    if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
        var_v0 = temp_v1 & 1;
    } else {
        var_v0 = temp_v1 & 2;
    }
    if (var_v0 != 0) {
        play_sound(2, 0x12, arg0);
        start_pad_vibration(8);
        set_animation(arg0, 0xB);
        func_800F5088(arg0, 0x20);
        func_800F5088(arg0, 0x21);
        M2C_FIELD(arg0, s16*, 0x7C) = 0x1E;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) - 1);
        return;
    }
    move_object(arg0);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define F(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
void func_800F5088(struct X4_AnimatedObj* arg0, u8 arg1);
void func_800F52AC(void* arg0, u8 arg1);
extern u8 D_800F75F8[][2];

void func_800F20C0(void* arg0) {
    switch (F(arg0, s8*, 0x45)) {
    case 1:
        play_sound(2, 0x15, arg0);
        func_800F52AC(arg0, D_800970A2);
        break;
    case 2:
        play_sound(2, 0x18, arg0);
        func_800F5088(arg0, D_800970A2);
        break;
    case 3: {
        if (--F(arg0, s16*, 0x7E) != 0) {
            u8 v = D_800F75F8[D_800970A2][0];
            F(arg0, u8*, 6) += 1;
            F(arg0, s16*, 0x7C) = v;
        } else {
            u8 v;
            set_animation(arg0, 0);
            v = D_800F75F8[D_800970A2][1];
            F(arg0, u8*, 6) += 2;
            F(arg0, s16*, 0x7C) = v;
        }
    } break;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK start_pad_vibration(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK move_object(void*);
s32 random_byte();
void func_800F513C(struct X4_AnimatedObj* arg0, u8 arg1);
void func_800F5360(void*, s32);

#define SB(p, o) (*(s8*)((u8*)(p) + (o)))
#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define SH(p, o) (*(s16*)((u8*)(p) + (o)))
#define UH(p, o) (*(u16*)((u8*)(p) + (o)))

void func_800F21E8(void* arg0) {
    move_object(arg0);
    {
        // !FAKE: depin: dropping it breaks the match (79/81)
        register s32 f asm("$2") = UB(arg0, 0x15);
        if (f == 0) {
            if (UB(arg0, 0x70) & 2) {
                // !FAKE: goto shares the hit block holding the pinned increment; duplicating it needs a second pin
                goto hit;
            }
            if (SH(arg0, 0xA) <= SH(arg0, 0x84)) {
                SH(arg0, 0x84) =
                    UH(arg0, 0xA) - ((random_byte() & 0x1F) | 0x20);
                func_800F513C(arg0, 0x12);
            }
        } else {
            if (UB(arg0, 0x70) & 1) {
            hit:
                play_sound(2, 0x12, arg0);
                start_pad_vibration(8);
                set_animation(arg0, 0xB);
                {
                    // !FAKE: depin: dropping it breaks the match (78/81)
                    register s32 c asm("$2") = UB(arg0, 6);
                    UB(arg0, 6) = c + 1;
                }
                return;
            }
            if (SH(arg0, 0xA) >= SH(arg0, 0x84)) {
                SH(arg0, 0x84) =
                    UH(arg0, 0xA) + ((random_byte() & 0x1F) | 0x20);
                func_800F513C(arg0, 0x12);
            }
        }
    }
    if (--SH(arg0, 0x7C) == 0) {
        UH(arg0, 0x7C) = 8;
        func_800F5360(arg0, 1);
    }
}

#include "../shared/rock_04/func_800F232C.c"

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 random_byte();
M2C_UNK func_80049D90(void*);
void func_800F51F0(struct X4_AnimatedObj* arg0, u8 arg1);
extern s16 D_800970AA;
extern u16 D_800F70DC;

void func_800F2464(void* arg0) {
    s8 a;
    s16 y;
    s32 d;

    a = M2C_FIELD(M2C_FIELD(arg0, s8**, 0x80), s8*, 5);
    if (M2C_FIELD(arg0, s8*, 0x84) != a && a == 3 && (random_byte() & 1)) {
        if (M2C_FIELD(arg0, s8*, 2) == 0x12) {
            M2C_FIELD(arg0, u16**, 0x68) = &D_800F70DC;
            M2C_FIELD(arg0, s32*, 0x20) = 0;
            M2C_FIELD(arg0, s32*, 0x28) = 0;
            M2C_FIELD(arg0, s32*, 0x24) = 0;
            M2C_FIELD(arg0, s32*, 0x2C) = 0x4CCC;
            M2C_FIELD(arg0, u8*, 5) += 1;
        } else {
            func_80049D90(arg0);
            func_800F51F0(arg0, 0x10);
            func_800F51F0(arg0, 0x11);
            func_800F51F0(arg0, 0x12);
            M2C_FIELD(arg0, u8*, 4) = 5;
        }
        return;
    }
    if (M2C_FIELD(arg0, s8*, 2) == 0x12) {
        y = M2C_FIELD(arg0, s16*, 0xA);
        d = y - D_800970AA;
        if (d < 0) {
            d = D_800970AA - y;
        }
        if (d < 0x21 || --M2C_FIELD(arg0, s16*, 0x7C) == 0) {
            M2C_FIELD(arg0, u16**, 0x68) = &D_800F70DC;
            M2C_FIELD(arg0, s32*, 0x20) = 0;
            M2C_FIELD(arg0, s32*, 0x28) = 0;
            M2C_FIELD(arg0, s32*, 0x24) = 0;
            M2C_FIELD(arg0, s32*, 0x2C) = 0x4CCC;
            M2C_FIELD(arg0, u8*, 5) += 1;
        }
    } else if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        func_80049D90(arg0);
        func_800F51F0(arg0, 0x10);
        func_800F51F0(arg0, 0x11);
        func_800F51F0(arg0, 0x12);
        M2C_FIELD(arg0, u8*, 4) = 5;
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_04/nonmatchings/E9860", func_800F25A0);
// clang-format on

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
extern s32 D_800741FC[];
extern M2C_UNK D_8007433C;
extern s32 D_800F769C;

void func_800F2750(struct X4_MainObj* self) {
    s8 one;
    s32 kind;

    one = M2C_FIELD(self, struct X4_MainObj**, 0x7C)->state;
    if (one != 1) {
        self->state = 2;
        self->on_screen = 0;
        return;
    }
    kind = self->unk2 & 0xF0;
    self->contact_damage = 0;
    self->hp = one;
    self->unk16 = 4;
    self->air_state = one;
    self->collision_data = &D_8007433C;
    self->terrain_box = 0;
    self->attack_box = 0;
    self->hurt_box = 0;
    self->on_screen = 0;
    self->state = one;
    self->action = 0;
    self->action_phase = 0;
    self->unk7 = 0;
    self->x_speed = 0;
    self->y_speed = 0;
    self->x_accel = 0;
    self->gravity = 0;
    if (kind == 0) {
        ((void (*)(void*, s32))set_animation)(self, 0x1B);
        self->collision_data = D_800741FC;
        self->hurt_box = 0;
        self->attack_box = 0;
        self->terrain_box = 0;
        self->contact_damage = 4;
        self->hp = 2;
        self->unk16 = 4;
        if (self->unk2 == 0) {
            if (self->unk15 == 0) {
                self->x_pos.u.hi -= 0x18;
            } else {
                self->x_pos.u.hi += 0x18;
            }
            self->y_pos.u.hi -= 8;
        } else if (self->unk2 == one) {
            if (self->unk15 == 0) {
                self->x_pos.u.hi -= 0x1E;
            } else {
                self->x_pos.u.hi += 0x1E;
            }
            self->y_pos.u.hi += 8;
        } else if (self->unk2 == 2) {
            if (self->unk15 == 0) {
                self->x_pos.u.hi -= 0x18;
            } else {
                self->x_pos.u.hi += 0x18;
            }
            self->y_pos.u.hi += 8;
        }
        self->action = 2;
    } else if (kind == 0x10) {
        self->collision_data = D_800741FC;
        self->hurt_box = 0;
        self->attack_box = 0;
        self->terrain_box = 0;
        self->contact_damage = 2;
        self->hp = one;
        self->unk16 = 4;
        self->unk15 = 0;
        self->action = 0;
    } else if (kind == 0x20) {
        self->hurt_box = 0;
        self->attack_box = 0;
        self->terrain_box = (void*)&D_800F769C;
        self->unk15 = 0;
        self->action = one;
    }
}

#include "../shared/rock_04/func_800F2954.c"

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
s32 random_byte();
#include "mmx6/state.h"
#include "mmx6/globals.h"
extern s32 D_800F7694;
extern s32 D_800F7698;

void func_800F2AD4(struct X4_MainObj* self) {
    s32 a;
    s32 b;
    s32 c;
    s32 q;

    set_animation(self,
                  ((u32)(D_80097420.frame_counter + self->unk2) % 3) + 0x1C);
    if (D_800CCF38 >= 2) {
        self->hurt_box = &D_800F7694;
        self->attack_box = &D_800F7698;
    }
    self->terrain_box = 0;
    a = ((u32)random_byte() % 40 & 0xFF) + 10;
    b = ((u32)random_byte() % 30 & 0xFF) + 30;
    c = ((u32)random_byte() % 10 & 0xFF) + 15;
    q = (b << 16) / ((c * c) >> 1);
    self->y_speed = q * c;
    self->gravity = q;
    self->x_accel = 0;
    switch (self->unk2) {
    case 16:
        self->x_speed = (-a << 16) / c;
        break;
    case 18:
        if (random_byte() & 1) {
            self->x_speed = (-a << 16) / c;
            break;
        }
    case 17:
        self->x_speed = (a << 16) / c;
        break;
    }
    self->action_phase++;
}

#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
extern struct X4_PlayerObj g_Player;
extern s16 D_800970AA;
extern s32 D_800F76A0;
extern s32 D_800F76A4[];
extern s32 D_800F76A8[];

void func_800F2CC4(void* arg0) {
    struct X4_PlayerObj* p;
    s32 ang;
    s32 num;
    s32 den;
    s32 dx;
    s32 v;
    s32 t;
    // !FAKE: depin: dropping it breaks the match (110/114)
    register s32 py asm("$3");
    s32 px;
    s32 den2;
    s8 type;

    if (M2C_FIELD(M2C_FIELD(arg0, void**, 0x7C), s8*, 0x5) == 3) {
        M2C_FIELD(arg0, s8*, 0x4) = 2;
        M2C_FIELD(arg0, s8*, 0x5) = 0;
        M2C_FIELD(arg0, s8*, 0x3) = 0;
        return;
    }
    if (M2C_FIELD(arg0, s8*, 0x45) != 0) {
        play_sound(2, 0x16, arg0);
        M2C_FIELD(arg0, void**, 0x54) = &D_800F76A0;
        M2C_FIELD(arg0, void**, 0x50) = D_800F76A4;
        M2C_FIELD(arg0, void**, 0x68) = D_800F76A8;
        type = M2C_FIELD(arg0, s8*, 0x2);
        if (type == 0) {
            dx = D_800970AA - M2C_FIELD(arg0, s16*, 0xA);
            num = 0x600000;
            den = 264;
            M2C_FIELD(arg0, s32*, 0x2C) = num / den;
            M2C_FIELD(arg0, s32*, 0x24) = 0x85D11;
            M2C_FIELD(arg0, s32*, 0x28) = 0;
            dx <<= 16;
            den2 = 46;
            M2C_FIELD(arg0, s32*, 0x20) = dx / den2;
        } else if (type == 1) {
            p = &g_Player;
            px = p->x_pos.i.hi;
            py = p->y_pos.i.hi;
            ang = ratan2(M2C_FIELD(arg0, s16*, 0xE) - py,
                         px - M2C_FIELD(arg0, s16*, 0xA));
            M2C_FIELD(arg0, s32*, 0x20) = rcos(ang) << 6;
            M2C_FIELD(arg0, s32*, 0x24) = rsin(ang) << 6;
            M2C_FIELD(arg0, s32*, 0x28) = 0;
            M2C_FIELD(arg0, s32*, 0x2C) = 0;
        } else if (type == 2) {
            p = &g_Player;
            px = p->x_pos.i.hi;
            py = p->y_pos.i.hi;
            ang = ratan2(M2C_FIELD(arg0, s16*, 0xE) - py,
                         px - M2C_FIELD(arg0, s16*, 0xA));
            v = rcos(ang);
            M2C_FIELD(arg0, s32*, 0x20) = -(v << 4) + (v << 7);
            v = rsin(ang);
            t = v << 4;
            M2C_FIELD(arg0, s32*, 0x24) = (v << 7) - t;
            M2C_FIELD(arg0, s32*, 0x28) = 0;
            M2C_FIELD(arg0, s32*, 0x2C) = 0;
        }
        M2C_FIELD(arg0, u8*, 0x6)++;
    }
}
