// clang-format off
INCLUDE_ASM("asm/rock_43/nonmatchings/FA000", D_800FA000);

INCLUDE_ASM("asm/rock_43/nonmatchings/FA000", D_800FA00C);
// clang-format on

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"
#include "mmx6/rock_43.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32**)0x1F800020)

void set_boss_level();
s32 func_8002A47C(s32);
struct X4_VisualObj* find_free_visual_obj(void);
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern s32 D_800750FC;
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj g_playthrough_state;
extern u8 D_800FA000[];
extern s32 D_800FDE34;
extern s32 D_800FDE38;
extern s32 D_800FE070;
extern s16 D_800FE284;
extern s16 D_800FE286;
extern s16 D_800FE288;
extern u16 D_800FE28A;
extern u16 D_800FE28C;
extern s16 D_800FE28E;
extern void* D_800FE298;

void func_800FA054(struct X4_MainObj* self) {
    u8 tbl[4];
    u8 bg;
    // !FAKE: depin: dropping it breaks the match (157/168)
    register s32 k asm("$22");
    struct X4_MainObj* child;
    struct X4_MainObj* prev;
    s32 i;

    i = 0;
    __builtin_memcpy(tbl, D_800FA000 + 4, 4);
    self->unk40 = 0x140;
    self->unk42 = 0x7948;
    self->sprite_frames = (u8*)SPAD20 + SPAD20[func_8002A47C(self->id)];
    D_800FE284 = background_objects[0].unk26 + 0x10;
    D_800FE286 = background_objects[0].unk26 + 0x130;
    D_800FE288 = background_objects[0].unk2A + 0xC0;
    D_800FE28A = background_objects[0].unk26 + 0xE0;
    D_800FE28C = background_objects[0].unk2A + 0xA0;
    D_800FE28E = background_objects[0].unk2A - 0x20;
    self->animation_table = (void*)&D_800FE070;
    bg = D_800970B4;
    self->unk16 = 5;
    self->unk15 = 0;
    self->air_state = 0;
    self->on_screen = 0;
    self->terrain_box = (void*)&D_800FDE30;
    self->attack_box = &D_800FDE34;
    self->hurt_box = &D_800FDE38;
    self->unk62 = 0;
    self->invincibility_timer = 0;
    self->bg_offset = bg;
    self->collision_data = &D_800750FC;
    self->x_speed = 0;
    self->y_speed = 0;
    self->x_accel = 0;
    self->gravity = 0;
    self->x_pos.i.hi = D_800FE28A;
    self->y_pos.i.hi = D_800FE28C;
    self->hp = 0;
    self->contact_damage = 0xA;
    g_playthrough_state.unk25 = 0;
    g_playthrough_state.boss_ptr = self;
    M2C_FIELD(&g_playthrough_state, u8*, 0x8C) = 0x30;
    set_boss_level(0);
    k = 0x794C;
    M2C_FIELD(&g_playthrough_state, u8*, 0x8C) +=
        tbl[M2C_FIELD(&g_playthrough_state, u8*, 0x8F)];
    M2C_FIELD(self, u8*, 0x87) = 0;
    M2C_FIELD(self, u8*, 0x86) = 0;
    M2C_FIELD(self, u8*, 0x84) = 0;
    func_8003D308(0x14, 0x40);
    D_800FE290 = 0;
    D_800FE294 = 0;
    D_800FE298 = self;
    M2C_FIELD(self, s16*, 0x8A) = 0;
    M2C_FIELD(self, u8*, 0x9A) = 0;
    do {
        child = (struct X4_MainObj*)find_free_visual_obj();
        if (child != 0) {
            child->active = 0x51;
            child->id = 6;
            child->unk2 = i;
            child->bg_offset = self->bg_offset;
            M2C_FIELD(child, s32*, 0x38) = M2C_FIELD(self, s32*, 0x38);
            child->sprite_frames = self->sprite_frames;
            child->unk40 = self->unk40;
            child->unk42 = k;
            child->unk16 = 6;
            child->attack_box = self;
            if (i != 0) {
                M2C_FIELD(child, void**, 0x5C) = prev;
            } else {
                M2C_FIELD(child, void**, 0x5C) = self;
            }
            prev = child;
        }
        i++;
    } while (i < 3);
    self->action = 2;
    self->state++;
}

#include "common.h"
#include "mmx6/globals.h"
#include "mmx6/rock_43.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
extern M2C_UNK D_8007433C;
extern s32 D_800750FC;
extern s32 D_800FDE34;
extern s32 D_800FDE38;
extern s32 D_800FDE3C;
extern s32 D_800FDE40;
extern s32 D_800FDE44;
extern s32 D_800FDE48;
extern s32 D_800FDE4C;
extern void (*D_800FE140[])(void*);

void func_800FA2F4(void* arg0) {
    s32 r;
    s32 v;
    u8 t;
    s32* a;

    v = M2C_FIELD(arg0, u8*, 0x47);
    switch (v) {
    case 0x1F:
    case 0x20:
    case 0x21:
    case 0x22:
    case 0x23:
    case 0x24:
    case 0x25:
    case 0x26:
    case 0x27:
        if ((u32)(v - 0x1F) < 3) {
            a = &D_800FDE40;
        } else {
            a = &D_800FDE3C;
        }
        M2C_FIELD(arg0, s32**, 0x50) = a;
        M2C_FIELD(arg0, s32**, 0x54) = &D_800FDE44;
        break;
    case 0x65:
    case 0x66:
    case 0x67:
    case 0x68:
    case 0x69:
    case 0x6A:
    case 0x6B:
    case 0x6C:
    case 0x6D:
        M2C_FIELD(arg0, s32**, 0x50) = &D_800FDE48;
        M2C_FIELD(arg0, s32**, 0x54) = &D_800FDE4C;
        break;
    default:
        M2C_FIELD(arg0, s32**, 0x50) = &D_800FDE34;
        M2C_FIELD(arg0, s32**, 0x54) = &D_800FDE38;
        break;
    }
next:
    r = 0;
    if (M2C_FIELD(arg0, s16*, 0x8A) == 0) {
        r = check_enemy_hits(arg0);
    }
    if (r < 0) {
        M2C_FIELD(arg0, s8*, 4) = 2;
        M2C_FIELD(arg0, s8*, 5) = 0;
        M2C_FIELD(arg0, s8*, 6) = 0;
        M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
        D_800FE290 = 1;
        D_8009711A = 1;
        func_8002CCB0(arg0, 0x40, 0x40);
        return;
    }
    if (M2C_FIELD(arg0, s16*, 0x8A) == 0) {
        func_80030ECC(arg0);
    }
    if (r > 0 && r != 0x7F) {
        M2C_FIELD(arg0, u8*, 0x84) = ((u32)(r - 0x19) < 2) ? 2 : 0x1E;
        M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
    }
    if (r == 0x33) {
        if (M2C_FIELD(arg0, s8*, 5) != 9 && M2C_FIELD(arg0, s8*, 5) != 0xB) {
            D_800FE294 = 1;
            M2C_FIELD(arg0, s8*, 5) = 0xC;
            M2C_FIELD(arg0, s8*, 6) = 0;
        }
    }
    t = M2C_FIELD(arg0, u8*, 0x84);
    if (t != 0) {
        M2C_FIELD(arg0, u8*, 0x84) = t + 0xFF;
        if (t & 2) {
            M2C_FIELD(arg0, u16*, 0x42) |= 0x8000;
        } else {
            M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
        }
        if (M2C_FIELD(arg0, u8*, 0x84) == 0) {
            M2C_FIELD(arg0, void**, 0x58) = &D_800750FC;
            M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
        }
    }
    M2C_FIELD(arg0, u8*, 0x9A) = 0;
    if (M2C_FIELD(arg0, s8*, 5) == 5) {
        M2C_FIELD(arg0, u8*, 0x9A) = 1;
    }
    D_800FE140[M2C_FIELD(arg0, s8*, 5)](arg0);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/rock_43.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object(void*);
M2C_UNK open_text_box(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK apply_object_motion(void*);
extern struct X4_EngineObj g_playthrough_state;

void func_800FA52C(struct X4_MainObj* self) {
    s16 t;

    if (self->collision_flags & 8) {
        self->y_speed = 0;
    }
    t = self->unk7C;
    if (t < 0x10) {
        // !FAKE: depin: dropping it breaks the match (21/73)
        register s32 a asm("$5") = M2C_FIELD(self, u16*, 0x88);
        // !FAKE: depin: dropping it breaks the match (71/73)
        register s32 w asm("$2") = *(u16*)((u8*)&D_800FDE30 + 0x2E4 + t * 2);
        a = a + w;
        M2C_FIELD(self, u16*, 0xA) = a;
        ((void (*)(void*, s32))animate_object)(self, a);
        apply_object_motion(self);
        func_8002CCB0(self, 0x40, 0x40);
    } else {
        set_animation(self, 0);
        {
            // !FAKE: depin: dropping it breaks the match (36/73)
            register s32 c asm("$2") = M2C_FIELD(self, u16*, 0x88);
            M2C_FIELD(self, u16*, 0xA) = c;
        }
        {
            s32 k = self->unk7C;
            if (k == 0x6E) {
                u8* e = (u8*)&g_playthrough_state;
                open_text_box(0, 0xFF, M2C_FIELD(e, s8*, 0x2E));
                M2C_FIELD(e, s8*, 0x2E) = 1;
                self->unk7C = 0;
                self->action_phase++;
            }
        }
        animate_object(self);
        apply_object_motion(self);
        {
            // !FAKE: depin: dropping it breaks the match (70/73)
            register s32 m asm("$2") = self->unk7C & 1;
            if (!m) {
                func_8002CCB0(self, 0x40, 0x40);
            }
        }
    }
    self->unk7C++;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/rock_43.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 random_byte();
M2C_UNK animate_object(void*);
M2C_UNK apply_object_motion(void*);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
extern struct X4_PlayerObj g_Player;
extern struct X4_EngineObj g_playthrough_state;
extern s8 D_800CCF5C;

void func_800FA650(void* arg0) {
    u32 r;
    s32 d;
    u8* e;
    u8 i;

    r = random_byte() & 0xF;
    M2C_FIELD(arg0, u8*, 0x87) = 0;
    if (g_Player.x_pos.i.hi - M2C_FIELD(arg0, s16*, 0xA) >= 0) {
        if (g_Player.x_pos.i.hi - M2C_FIELD(arg0, s16*, 0xA) < 0x41) {
            // !FAKE: range test needs per-sign compares jumping to one shared block (C0144); abs() form folds to a negate
            goto near;
        }
        // !FAKE: range test needs per-sign compares jumping to one shared block (C0144); abs() form folds to a negate
        goto far;
    }
    if (M2C_FIELD(arg0, s16*, 0xA) - g_Player.x_pos.i.hi < 0x41) {
    near:
        if (D_800CCF5C / 2 < M2C_FIELD(arg0, s8*, 0x5C)) {
            if (r < 0x10) {
                M2C_FIELD(arg0, u8*, 0x86) = 7;
            }
        } else if (r < 0x10) {
            M2C_FIELD(arg0, u8*, 0x86) = 8;
        }
    } else {
    far:
        d = g_Player.y_pos.i.hi - M2C_FIELD(arg0, s16*, 0xE);
        if (d >= 0) {
            if (d >= 0x30) {
                // !FAKE: range test needs per-sign compares jumping to one shared block (C0144); abs() form folds to a negate
                goto far2;
            }
            // !FAKE: range test needs per-sign compares jumping to one shared block (C0144); abs() form folds to a negate
            goto near2;
        }
        if (M2C_FIELD(arg0, s16*, 0xE) - g_Player.y_pos.i.hi >= 0x30) {
        far2:
            e = (u8*)&g_playthrough_state;
            if (M2C_FIELD(e, s8*, 0x8C) / 2 < M2C_FIELD(arg0, s8*, 0x5C)) {
                if (r < 0x10) {
                    if (e[0x68] == 2) {
                        M2C_FIELD(arg0, u8*, 0x86) = 0xA;
                    } else {
                        M2C_FIELD(arg0, u8*, 0x86) = 9;
                    }
                }
            } else if (r < 8) {
                if (e[0x68] == 2) {
                    M2C_FIELD(arg0, u8*, 0x86) = 0xA;
                } else {
                    M2C_FIELD(arg0, u8*, 0x86) = 9;
                }
            } else {
                M2C_FIELD(arg0, u8*, 0x86) = 0xB;
            }
        } else {
        near2:
            e = (u8*)&g_playthrough_state;
            if (M2C_FIELD(e, s8*, 0x8C) / 2 < M2C_FIELD(arg0, s8*, 0x5C)) {
                if (r < 6) {
                    M2C_FIELD(arg0, u8*, 0x86) = 0;
                } else if (r < 0xC) {
                    M2C_FIELD(arg0, u8*, 0x86) = 1;
                } else if (e[0x68] == 2) {
                    M2C_FIELD(arg0, u8*, 0x86) = 5;
                } else {
                    M2C_FIELD(arg0, u8*, 0x86) = 4;
                }
            } else if (r < 4) {
                M2C_FIELD(arg0, u8*, 0x86) = 2;
            } else if (r < 8) {
                M2C_FIELD(arg0, u8*, 0x86) = 3;
            } else if (r < 0xC) {
                if (e[0x68] == 2) {
                    M2C_FIELD(arg0, u8*, 0x86) = 5;
                } else {
                    M2C_FIELD(arg0, u8*, 0x86) = 4;
                }
            } else {
                M2C_FIELD(arg0, u8*, 0x86) = 6;
            }
        }
    }
    {
        u8* t = (u8*)&D_800FDE30 + 0x284;
        u8* q =
            t + (M2C_FIELD(arg0, u8*, 0x87)++ + M2C_FIELD(arg0, u8*, 0x86) * 6);
        M2C_FIELD(arg0, u8*, 5) = *q;
    }
    M2C_FIELD(arg0, s8*, 6) = 0;
    animate_object(arg0);
    apply_object_motion(arg0);
    func_8002CCB0(arg0, 0x40, 0x40);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/rock_43.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object(void*);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK apply_object_motion(void*);
extern struct X4_PlayerObj g_Player;

void func_800FA8B4(struct X4_MainObj* self) {
    s16 t;

    t = self->unk7C;
    if (t < 0x32) {
        if (!(self->unk7C & 1)) {
            func_8002CCB0(self, 0x40, 0x40);
        }
        apply_object_motion(self);
    } else if ((u16)(self->unk7C - 0x32) < 0x10) {
        if (t == 0x32) {
            set_animation(self, 2);
            play_sound(2, 0x99, self);
            M2C_FIELD(self, u16*, 0x88) = M2C_FIELD(self, u16*, 0xA);
        }
        {
            u8* b;
            s32 i;
            // !FAKE: depin: dropping it breaks the match (73/138)
            register s32 k asm("$3") = self->unk7C;
            b = (u8*)&D_800FDE30 + 0x2E4;
            i = 0x41 - k;
            {
                s32 u = M2C_FIELD(self, u16*, 0x88);
                s32 w = *(u16*)(b + i * 2);
                M2C_FIELD(self, u16*, 0xA) = u + w;
            }
        }
        func_8002CCB0(self, 0x40, 0x40);
        animate_object(self);
        apply_object_motion(self);
    } else if (t < 0x7E) {
    } else if ((u16)(self->unk7C - 0x7E) < 0x10) {
        if (t == 0x7E) {
            if (g_Player.x_pos.i.hi > M2C_FIELD(self, s16*, 0xA)) {
                self->unk15 = 0x40;
            } else {
                self->unk15 = 0;
            }
            play_sound(2, 0x99, self);
            M2C_FIELD(self, u16*, 0x88) = g_Player.x_pos.i.hi;
        }
        {
            u8* b;
            s32 i;
            i = self->unk7C - 0x7E;
            b = (u8*)&D_800FDE30 + 0x2E4;
            {
                // !FAKE: depin: dropping it breaks the match (38/138)
                register s32 u asm("$3") = M2C_FIELD(self, u16*, 0x88);
                s32 w = *(u16*)(b + i * 2);
                M2C_FIELD(self, u16*, 0xA) = u + w;
            }
        }
        func_8002CCB0(self, 0x40, 0x40);
        animate_object(self);
        apply_object_motion(self);
    } else if (t < 0xC0) {
        if (t == 0x8E) {
            set_animation(self, 0);
            {
                // !FAKE: depin: dropping it breaks the match (136/138)
                register s32 c asm("$2") = M2C_FIELD(self, u16*, 0x88);
                M2C_FIELD(self, u16*, 0xA) = c;
            }
        }
        if (!(self->unk7C & 1)) {
            func_8002CCB0(self, 0x40, 0x40);
        }
        apply_object_motion(self);
    } else {
        M2C_FIELD(self, s16*, 0x8A) = 0;
        {
            u8* tb = (u8*)&D_800FDE30 + 0x284;
            u8* q = tb + (M2C_FIELD(self, u8*, 0x87)++ +
                          M2C_FIELD(self, u8*, 0x86) * 6);
            self->action = *q;
        }
        self->action_phase = 0;
        func_8002CCB0(self, 0x40, 0x40);
        animate_object(self);
        apply_object_motion(self);
    }
    self->unk7C++;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/rock_43.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object(void*);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK apply_object_motion(void*);
extern s16 D_800970AA;
extern s16 D_800FE284;
extern s16 D_800FE286;

void func_800FAADC(struct X4_MainObj* self) {
    s16 t;

    t = self->unk7C;
    if (t < 0x32) {
        if (!(self->unk7C & 1)) {
            func_8002CCB0(self, 0x40, 0x40);
        }
        apply_object_motion(self);
    } else if ((u16)(self->unk7C - 0x32) < 0x10) {
        if (t == 0x32) {
            set_animation(self, 2);
            play_sound(2, 0x99, self);
            M2C_FIELD(self, u16*, 0x88) = M2C_FIELD(self, u16*, 0xA);
        }
        {
            u8* b;
            s32 i;
            // !FAKE: depin: dropping it breaks the match (78/136)
            register s32 k asm("$3") = self->unk7C;
            b = (u8*)&D_800FDE30 + 0x2E4;
            i = 0x41 - k;
            {
                s32 u = M2C_FIELD(self, u16*, 0x88);
                s32 w = *(u16*)(b + i * 2);
                M2C_FIELD(self, u16*, 0xA) = u + w;
            }
        }
        func_8002CCB0(self, 0x40, 0x40);
        animate_object(self);
        apply_object_motion(self);
    } else if (t < 0x7E) {
    } else if ((u16)(self->unk7C - 0x7E) < 0x10) {
        if (t == 0x7E) {
            play_sound(2, 0x99, self);
            if (D_800970AA > (D_800FE284 + D_800FE286) / 2) {
                self->unk15 = 0x40;
                M2C_FIELD(self, u16*, 0x88) = (u16)D_800FE284 + 0x20;
            } else {
                self->unk15 = 0;
                M2C_FIELD(self, u16*, 0x88) = (u16)D_800FE286 - 0x20;
            }
        }
        {
            u8* b;
            s32 i;
            i = self->unk7C - 0x7E;
            b = (u8*)&D_800FDE30 + 0x2E4;
            {
                // !FAKE: depin: dropping it breaks the match (37/136)
                register s32 u asm("$3") = M2C_FIELD(self, u16*, 0x88);
                s32 w = *(u16*)(b + i * 2);
                M2C_FIELD(self, u16*, 0xA) = u + w;
            }
        }
        func_8002CCB0(self, 0x40, 0x40);
        animate_object(self);
        apply_object_motion(self);
    } else if (t < 0xC0) {
        if (t == 0x8E) {
            set_animation(self, 0);
            {
                // !FAKE: depin: dropping it breaks the match (134/136)
                register s32 c asm("$2") = M2C_FIELD(self, u16*, 0x88);
                M2C_FIELD(self, u16*, 0xA) = c;
            }
        }
        if (!(self->unk7C & 1)) {
            func_8002CCB0(self, 0x40, 0x40);
        }
        apply_object_motion(self);
    } else {
        M2C_FIELD(self, s16*, 0x8A) = 0;
        set_animation(self, 7);
        self->unk7C = 0x3C;
        self->unk7E = 0;
        self->action_phase++;
        func_8002CCB0(self, 0x40, 0x40);
        animate_object(self);
        apply_object_motion(self);
    }
    self->unk7C++;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"
#include "mmx6/rock_43.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object(void*);
void* func_8002C458();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK apply_object_motion(void*);
extern u8 D_800FA000[];

void func_800FACFC(struct X4_MainObj* self) {
    u8 tbl[4];

    __builtin_memcpy(tbl, D_800FA000 + 8, 4);
    if (M2C_FIELD(self, s8*, 0x45) == 1) {
        struct X4_MainObj* o;
        M2C_FIELD(self, s8*, 0x45) = 0;
        o = func_8002C458();
        if (o != 0) {
            u8 a = self->active;
            o->id = 0x13;
            o->unk2 = 9;
            M2C_FIELD(o, void**, 0x7C) = self;
            o->active = a;
        }
    }
    if (M2C_FIELD(self, s8*, 0x45) == 2) {
        struct X4_MainObj* o;
        M2C_FIELD(self, s8*, 0x45) = 0;
        o = func_8002C458();
        if (o != 0) {
            u8 a = self->active;
            o->id = 0x13;
            o->unk2 = 8;
            M2C_FIELD(o, void**, 0x7C) = self;
            o->active = a;
        }
    }
    if (M2C_FIELD(self, s8*, 0x46) == 0) {
        set_animation(self, 0);
    }
    if (self->unk7C == 0) {
        if (++self->unk7E == tbl[D_800CCF5F]) {
            set_animation(self, 0);
            {
                u8* b = ((u8*)&D_800FDE30 + 0x284);
                u8 i = M2C_FIELD(self, u8*, 0x87)++;
                s32 m = M2C_FIELD(self, u8*, 0x86) * 6;
                u8 v = b[i + m];
                self->action_phase = 0;
                self->action = v;
            }
        } else {
            set_animation(self, 7);
            if (self->unk7E == 2) {
                self->unk7C = 0x78;
            } else {
                self->unk7C = 0x3C;
            }
        }
    }
    self->unk7C--;
    func_8002CCB0(self, 0x40, 0x40);
    animate_object(self);
    apply_object_motion(self);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/rock_43.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object(void*);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK apply_object_motion(void*);
s32 random_byte();
extern s16 D_800970AA;
extern s16 D_800FE284;
extern s16 D_800FE286;

void func_800FAE98(struct X4_MainObj* self) {
    s16 t;

    t = self->unk7C;
    if (t < 0x32) {
        if (!(self->unk7C & 1)) {
            func_8002CCB0(self, 0x40, 0x40);
        }
        apply_object_motion(self);
    } else if ((u16)(self->unk7C - 0x32) < 0x10) {
        if (t == 0x32) {
            set_animation(self, 2);
            play_sound(2, 0x99, self);
            M2C_FIELD(self, u16*, 0x88) = M2C_FIELD(self, u16*, 0xA);
        }
        {
            u8* b;
            s32 i;
            // !FAKE: depin: dropping it breaks the match (80/148)
            register s32 k asm("$3") = self->unk7C;
            b = (u8*)&D_800FDE30 + 0x2E4;
            i = 0x41 - k;
            {
                s32 u = M2C_FIELD(self, u16*, 0x88);
                s32 w = *(u16*)(b + i * 2);
                M2C_FIELD(self, u16*, 0xA) = u + w;
            }
        }
        func_8002CCB0(self, 0x40, 0x40);
        animate_object(self);
        apply_object_motion(self);
    } else if (t < 0x7E) {
    } else if ((u16)(self->unk7C - 0x7E) < 0x10) {
        if (t == 0x7E) {
            set_animation(self, 2);
            play_sound(2, 0x99, self);
            if (D_800970AA > (D_800FE284 + D_800FE286) / 2) {
                self->unk15 = 0x40;
                M2C_FIELD(self, u16*, 0x88) = (u16)D_800FE284 + 0x20;
            } else {
                self->unk15 = 0;
                M2C_FIELD(self, u16*, 0x88) = (u16)D_800FE286 - 0x20;
            }
        }
        {
            u8* b;
            s32 i;
            i = self->unk7C - 0x7E;
            b = (u8*)&D_800FDE30 + 0x2E4;
            {
                // !FAKE: depin: dropping it breaks the match (38/148)
                register s32 u asm("$3") = M2C_FIELD(self, u16*, 0x88);
                s32 w = *(u16*)(b + i * 2);
                M2C_FIELD(self, u16*, 0xA) = u + w;
            }
        }
        func_8002CCB0(self, 0x40, 0x40);
        animate_object(self);
        apply_object_motion(self);
    } else if (t < 0xC0) {
        if (t == 0x8E) {
            set_animation(self, 0);
            {
                // !FAKE: depin: dropping it breaks the match (146/148)
                register s32 c asm("$2") = M2C_FIELD(self, u16*, 0x88);
                M2C_FIELD(self, u16*, 0xA) = c;
            }
        }
        if (!(self->unk7C & 1)) {
            func_8002CCB0(self, 0x40, 0x40);
        }
        apply_object_motion(self);
    } else {
        M2C_FIELD(&D_800FDE30, s32*, 0x464) = 0;
        M2C_FIELD(self, s16*, 0x8A) = 0;
        if (random_byte() & 1) {
            self->action = 9;
            self->action_phase = 0;
        } else {
            set_animation(self, 7);
            {
                // !FAKE: depin: dropping it breaks the match (145/148)
                register s32 a asm("$2") = 0x3C;
                self->unk7C = a;
            }
            self->unk7E = 0;
            self->action = 0xB;
            self->action_phase = 2;
        }
        func_8002CCB0(self, 0x40, 0x40);
        animate_object(self);
        apply_object_motion(self);
    }
    self->unk7C++;
}

// clang-format off
INCLUDE_ASM("asm/rock_43/nonmatchings/FA000", func_800FB0E8);
// clang-format on

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/rock_43.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object(void*);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK move_object(void*);
extern void* D_800FE298;

#define PARENT ((struct X4_MainObj*)D_800FE298)

void func_800FB1F0(struct X4_MainObj* self) {
    s32 d;
    struct X4_MainObj* p;

    if (D_800FE290 != 0) {
        self->state++;
        return;
    }
    self->unk15 = PARENT->unk15;
    if (self->unk15 == 0) {
        self->x_pos.i.hi = PARENT->x_pos.i.hi + 0x1E;
    } else {
        self->x_pos.i.hi = PARENT->x_pos.i.hi - 0x1E;
    }
    p = PARENT;
    self->y_pos.i.hi = p->y_pos.i.hi + 8;
    switch (self->action) {
    case 0:
        if (M2C_FIELD(p, s8*, 0x45) == 9) {
            ((void (*)(void*, s32))set_animation)(self, 9);
            self->action++;
        }
        break;
    case 1:
        d = p->x_speed;
        if ((d < 0 ? -d : d) != 0x42000 || M2C_FIELD(self, s8*, 0x46) == 0) {
            self->action--;
        }
        func_8002CCB0(self, 0x20, 0x20);
        animate_object(self);
        move_object(self);
        break;
    }
}

#undef PARENT

// clang-format off
INCLUDE_ASM("asm/rock_43/nonmatchings/FA000", func_800FB328);
// clang-format on

#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/rock_43.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object(void*);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK move_object(void*);
s32 random_byte();
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
M2C_UNK func_80049E50(void*);
extern s32 D_800FE1F8;
extern s32 D_800FE1FC;

void func_800FB438(struct X4_MainObj* self) {
    if (D_800FE290 != 0 || D_800FE294 != 0) {
        self->state++;
        return;
    }
    if (check_enemy_hits(self) < 0) {
        func_80049E50(self);
        self->state++;
        return;
    }
    func_80030ECC(self);
    switch (self->action) {
    case 0:
        self->attack_box = (u8*)&D_800FDE30 + 0x3C4;
        if (++M2C_FIELD(self, s32*, 0x8C) == 3) {
            if (self->unk2 == 1) {
                if (self->unk15 == 0) {
                    self->x_speed = -0x40000;
                } else {
                    self->x_speed = 0x40000;
                }
            } else {
                s16 t;
                s16 a;
                t = random_byte() % 3 - 1;
                if (self->unk15 == 0) {
                    a = t * 128 + 0x800;
                } else {
                    a = t * 128;
                }
                self->x_speed = rcos(a) << 6;
                self->y_speed = -rsin(a) << 6;
            }
            self->action++;
        }
        break;
    case 1:
        if (++M2C_FIELD(self, s32*, 0x8C) == 0xC) {
            set_animation(self, 0xA);
            {
                // !FAKE: depin: dropping it breaks the match (137/141)
                register void* a asm("$2") = &D_800FE1F8;
                // !FAKE: depin: dropping it breaks the match (99/141)
                register void* b asm("$3") = &D_800FE1FC;
                self->attack_box = a;
                self->hurt_box = b;
            }
            M2C_FIELD(self, s32*, 0x8C) = 0;
            self->action++;
        }
        break;
    case 2:
        if (++M2C_FIELD(self, s32*, 0x8C) == 0x64) {
            self->state++;
        }
        func_8002CCB0(self, 0x30, 0x20);
        break;
    }
    animate_object(self);
    move_object(self);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/rock_43.h"

M2C_UNK set_animation(void*, M2C_UNK);

#define PARENT (*(struct X4_MainObj**)((u8*)&D_800FDE30 + 0x468))

void func_800FB66C(struct X4_MainObj* self) {
    struct X4_MainObj* p;
    struct X4_MainObj* q;
    const u8* frames;
    u8 dir;

    p = PARENT;
    self->unk40 = p->unk40;
    self->unk42 = p->unk42 & 0x7FFF;
    self->animation_table = p->animation_table;
    frames = p->sprite_frames;
    self->bg_offset = 0;
    self->unk16 = 3;
    q = PARENT;
    self->sprite_frames = frames;
    dir = q->unk15;
    self->air_state = 0;
    self->on_screen = 0;
    self->terrain_box = 0;
    self->attack_box = 0;
    self->hurt_box = 0;
    self->collision_data = 0;
    self->unk15 = dir;
    if (dir == 0) {
        self->x_pos.i.hi = PARENT->x_pos.i.hi - 0x1E;
    } else {
        self->x_pos.i.hi = PARENT->x_pos.i.hi + 0x1E;
    }
    self->y_pos.i.hi = PARENT->y_pos.i.hi - 0xA;
    self->x_speed = 0;
    self->y_speed = 0;
    self->x_accel = 0;
    self->gravity = 0;
    ((void (*)(void*, s32))set_animation)(self, 0xB);
    self->hp = 0;
    self->contact_damage = 0;
    self->action = 0;
    self->state++;
}

#undef PARENT

#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/rock_43.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
extern M2C_UNK D_8007433C;
extern struct X4_PlayerObj g_Player;

extern s32 D_800FE200;
extern s32 D_800FE204;
extern void* D_800FE298;

#define PARENT ((struct X4_MainObj*)D_800FE298)

void func_800FB764(struct X4_MainObj* self) {
    s32 x;
    s32 a;
    u16 y;
    u8 dir;
    // !FAKE: depin: dropping it breaks the match (113/128)
    register const u8* t asm("$6");
    struct X4_PlayerObj* pl;

    self->unk40 = PARENT->unk40;
    self->unk42 = PARENT->unk42 & 0x7FFF;
    self->animation_table = PARENT->animation_table;
    t = PARENT->sprite_frames;
    self->unk16 = 6;
    self->bg_offset = 0;
    self->sprite_frames = t;
    dir = PARENT->unk15;
    {
        // !FAKE: depin: dropping it breaks the match (115/128)
        register void* hb asm("$3") = &D_800FE204;
        self->attack_box = &D_800FE200;
        self->air_state = 0;
        self->on_screen = 0;
        self->terrain_box = 0;
        self->hurt_box = hb;
    }
    self->collision_data = &D_8007433C;
    self->unk15 = dir;
    if (dir == 0) {
        self->x_pos.i.hi = PARENT->x_pos.i.hi - 0x46;
    } else {
        self->x_pos.i.hi = PARENT->x_pos.i.hi + 0x46;
    }
    x = self->x_pos.i.hi;
    y = PARENT->y_pos.i.hi;
    self->y_pos.i.hi = y;
    pl = &g_Player;
    a = (pl->x_pos.i.hi >= x) << 6;
    if (self->unk15 == a) {
        x = pl->x_pos.i.hi - x;
    } else {
        x = x - pl->x_pos.i.hi;
    }
    a = (s16)ratan2(pl->y_pos.i.hi - (s16)y, x);
    if (a <= 0) {
        if (a >= -0x3FF) {
            if (a < -0x200) {
                a = -0x200;
            }
        } else if (a >= -0x5FF) {
            a = -0x600;
        }
    } else {
        if (a < 0x400) {
            a = 0;
        } else {
            a = -0x800;
        }
    }
    if (self->unk2 == 5) {
        a = (self->unk15 == 0) << 11;
    }
    self->x_speed = rcos(a) << 6;
    self->y_speed = -rsin(a) << 6;
    self->x_accel = 0;
    self->gravity = 0;
    self->hp = 1;
    self->contact_damage = 0x10;
    set_animation(self, 0xC);
    play_sound(2, 0x8F, self);
    M2C_FIELD(self, s32*, 0x8C) = 0;
    self->action = 0;
    self->state++;
}

#undef PARENT

// clang-format off
INCLUDE_ASM("asm/rock_43/nonmatchings/FA000", func_800FB964);
// clang-format on

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/rock_43.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object(void*);
void* func_8002C458();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK move_object(void*);
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
M2C_UNK func_80049E50(void*);
extern s32 D_800FE208;
extern s32 D_800FE20C;
extern s16 D_800FE28E;

void func_800FBB70(struct X4_MainObj* self) {
    if (D_800FE290 != 0 || D_800FE294 != 0) {
        self->state++;
        return;
    }
    if (check_enemy_hits(self) < 0) {
        func_80049E50(self);
        self->state++;
        return;
    }
    func_80030ECC(self);
    switch (self->action) {
    case 0:
        if (--M2C_FIELD(self, s32*, 0x90) == 0) {
            struct X4_MainObj* o = func_8002C458();
            if (o != 0) {
                u8 a = self->active;
                o->id = 0x13;
                o->unk2 = 7;
                o->active = a;
                M2C_FIELD(o, s32*, 0x7C) = M2C_FIELD(self, s32*, 0x7C);
                o->x_pos.i.hi = self->x_pos.i.hi;
                o->y_pos.i.hi = self->y_pos.i.hi + 0xC;
            }
            M2C_FIELD(self, s32*, 0x90) = 0;
            self->action++;
        }
        break;
    case 1:
        if (++M2C_FIELD(self, s32*, 0x90) == 4) {
            set_animation(self, 0xD);
            {
                // !FAKE: depin: dropping it breaks the match (110/114)
                register void* a asm("$2") = &D_800FE208;
                // !FAKE: depin: dropping it breaks the match (71/114)
                register void* b asm("$3") = &D_800FE20C;
                self->attack_box = a;
                self->hurt_box = b;
            }
            self->y_speed = 0x60000;
            self->action++;
        }
        break;
    case 2:
        if (self->y_pos.i.hi < D_800FE28E) {
            self->state++;
        }
        func_8002CCB0(self, 0x20, 0x30);
        break;
    }
    animate_object(self);
    move_object(self);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
s32 random_byte();
extern s32 D_800FE210;
extern s32 D_800FE214;
extern void* D_800FE298;

#define PARENT ((struct X4_MainObj*)D_800FE298)

void func_800FBD38(struct X4_MainObj* self) {
    // !FAKE: depin: dropping it breaks the match (88/96)
    register s32 t3c asm("$6");
    u8 dir;
    s32 v;
    struct X4_MainObj* p = PARENT;

    self->unk40 = p->unk40;
    self->unk42 = p->unk42 & 0x7FFF;
    M2C_FIELD(self, s32*, 0x30) = M2C_FIELD(p, s32*, 0x30);
    t3c = M2C_FIELD(p, s32*, 0x3C);
    self->unk16 = 4;
    self->bg_offset = 0;
    {
        struct X4_MainObj* q = PARENT;
        M2C_FIELD(self, s32*, 0x3C) = t3c;
        dir = q->unk15;
    }
    {
        void* a = &D_800FE210;
        // !FAKE: depin: dropping it breaks the match (83/96)
        register void* b asm("$3") = &D_800FE214;
        self->attack_box = a;
        self->air_state = 0;
        self->on_screen = 0;
        self->terrain_box = 0;
        self->hurt_box = b;
    }
    self->collision_data = &D_8007429C;
    self->unk15 = dir;
    if (dir == 0) {
        M2C_FIELD(self, u16*, 0xA) = M2C_FIELD(PARENT, u16*, 0xA) - 0x40;
    } else {
        M2C_FIELD(self, u16*, 0xA) = M2C_FIELD(PARENT, u16*, 0xA) + 0x40;
    }
    M2C_FIELD(self, u16*, 0xE) = M2C_FIELD(PARENT, u16*, 0xE) - 0x4C;
    if (random_byte() & 1) {
        if (self->unk15 == 0) {
            self->x_speed = 0xFFFE0000;
        } else {
            self->x_speed = 0x20000;
        }
    } else {
        if (self->unk15 == 0) {
            self->x_speed = 0xFFF80000;
        } else {
            self->x_speed = 0x80000;
        }
    }
    self->y_speed = 0;
    self->x_accel = 0;
    self->gravity = 0;
    self->hp = 1;
    self->contact_damage = 0xA;
    set_animation(self, 0xF);
    play_sound(2, 0x92, self);
    play_sound(2, 0x96, self);
    M2C_FIELD(self, s32*, 0x8C) = 0;
    self->action = 0;
    self->state++;
}
#undef PARENT

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/rock_43.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object(void*);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK move_object(void*);
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);

void func_800FBEB8(struct X4_MainObj* self) {
    if (D_800FE290 != 0 || D_800FE294 != 0) {
        self->state++;
        return;
    }
    switch (self->action) {
    case 0:
        if (M2C_FIELD(self, u32*, 0x8C) >= 7) {
            if (check_enemy_hits(self) < 0) {
                self->attack_box = 0;
                self->hurt_box = 0;
                M2C_FIELD(self, u32*, 0x8C) = 0xA;
                self->action++;
            } else {
                func_80030ECC(self);
            }
        }
        ((void (*)(void*, s32, s32))func_8002CCB0)(self, 0x20, 0x80);
        if (self->on_screen == 0) {
            self->state++;
        }
        ((void (*)(void*))animate_object)(self);
        if (++M2C_FIELD(self, u32*, 0x8C) >= 7) {
            move_object(self);
        }
        break;
    case 1:
        if (++M2C_FIELD(self, u32*, 0x8C) == 0x1E) {
            self->state++;
        }
        if (M2C_FIELD(self, u32*, 0x8C) & 1) {
            func_8002CCB0(self, 0x20, 0x80);
        }
        animate_object(self);
        move_object(self);
        break;
    }
}

#include "common.h"
#include "mmx6/rock_43.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);

#define PARENT (*(u8**)((u8*)&D_800FDE30 + 0x468))
#define B(p, o) (*(u8*)((u8*)(p) + (o)))
#define H(p, o) (*(u16*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))

void func_800FC02C(void* arg0) {
    u8* p;
    u8* q;
    u8 t;
    s32 x;

    p = PARENT;
    H(arg0, 0x40) = H(p, 0x40);
    H(arg0, 0x42) = H(p, 0x42) & 0x7FFF;
    W(arg0, 0x30) = W(p, 0x30);
    x = W(p, 0x3C);
    B(arg0, 0x14) = 0;
    B(arg0, 0x16) = 6;
    q = PARENT;
    W(arg0, 0x3C) = x;
    t = B(q, 0x15);
    B(arg0, 0x67) = 0;
    B(arg0, 3) = 0;
    W(arg0, 0x68) = 0;
    W(arg0, 0x50) = 0;
    W(arg0, 0x54) = 0;
    W(arg0, 0x58) = 0;
    B(arg0, 0x15) = t;
    if (t == 0) {
        H(arg0, 0xA) = H(PARENT, 0xA) - 0xD;
    } else {
        H(arg0, 0xA) = H(PARENT, 0xA) + 0xD;
    }
    H(arg0, 0xE) = H(PARENT, 0xE) - 0x32;
    W(arg0, 0x20) = 0;
    W(arg0, 0x24) = 0;
    W(arg0, 0x28) = 0;
    W(arg0, 0x2C) = 0;
    B(arg0, 0x5C) = 0;
    B(arg0, 0x60) = 0;
    W(arg0, 0x8C) = 0;
    set_animation(arg0, 0x10);
    t = B(arg0, 4);
    B(arg0, 5) = 0;
    B(arg0, 4) = t + 1;
}
#undef PARENT
#undef B
#undef H
#undef W
