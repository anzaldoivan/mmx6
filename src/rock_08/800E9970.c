#define func_80041AB8 func_800E9970
#define D_80075FD8 D_800F4C34
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

/* Adapted from sozud/mmx4 @807a01b src/main/visuals/visual_13_ride_chaser_jet.c:ride_chaser_jet_init, AGPL-3.0; proven shared with X6 by exact signature 561f8a99cfb3 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
s32 set_animation(void*, s32);

void func_800E99AC(struct X4_VisualObj* arg0) {
    arg0->state = 1;
    arg0->on_screen = 1;
    arg0->unk54 = 0xFF;
    arg0->unk56 = 0xFF;
    arg0->unk16 = VISUAL_SATURN_LAYER(6);
    set_animation(arg0, 0x15);
}

/* Adapted from sozud/mmx4 @807a01b src/main/visuals/visual_13_ride_chaser_jet.c:ride_chaser_jet_main, AGPL-3.0; proven shared with X6 by exact signature ca898a8565aa (see THIRD_PARTY.md). */
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
extern u8 D_800F4C24[16];
void func_8002CCB0(struct X4_BaseObj*, s32, s32);
void set_animation_frame(struct X4_AnimatedObj*, s32, s32);
M2C_UNK animate_object();

void func_800E99EC(struct X4_VisualObj* arg0) {
    struct X4_PlayerObj* player;
    u8 animation;
    s16 previous_frame;
    u8 next_animation;

    player = arg0->unk50;
    if (player->state != 2) {
        previous_frame = arg0->unk56;
        next_animation = D_800F4C24[player->animation_step.fields.frame_index];
        if (player->animation_step.fields.frame_index != previous_frame &&
            (animation = next_animation & 0xFF) != arg0->unk54) {
            set_animation_frame(ANIMATED_OBJECT(arg0), animation,
                                arg0->animation_step.fields.event);
            arg0->unk56 = player->animation_step.fields.frame_index;
            arg0->unk54 = next_animation;
        }
        arg0->x_pos.i.hi = player->x_pos.i.hi;
        arg0->y_pos.i.hi = player->y_pos.i.hi;
        animate_object(ANIMATED_OBJECT(arg0));
        func_8002CCB0(BASE_OBJECT(arg0), 0x10, 0x10);
        return;
    }
    arg0->state = 2;
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800E9AB0(void) {
    clear_object_slot();
}

#define func_80041AB8 func_800E9AD0
#define D_80075FD8 D_800F4C40
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

/* Adapted from sozud/mmx4 @807a01b src/main/visuals/visual_15_ride_chaser_flash.c:ride_chaser_flash_init, AGPL-3.0; proven shared with X6 by exact signature 339a3fd19fc8 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
s32 set_animation(void*, s32);

void func_800E9B0C(struct X4_VisualObj* arg0) {
    arg0->state = 1;
    arg0->on_screen = 1;
    arg0->unk54 = 3;
    arg0->unk16 = VISUAL_SATURN_LAYER(2);
    set_animation(arg0, 0x19);
}

/* Adapted from sozud/mmx4 @807a01b src/main/visuals/visual_15_ride_chaser_flash.c:ride_chaser_flash_main, AGPL-3.0; proven shared with X6 by exact signature d83d6ae99f8d (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
void func_8002CCB0(struct X4_BaseObj*, s32, s32);

#define M2C_UNK s32
M2C_UNK animate_object();
void func_800E9B48(struct X4_VisualObj* arg0) {
    struct X4_BaseObj* temp_s1 = arg0->unk50;

    arg0->x_pos.i.hi = temp_s1->x_pos.i.hi;
    arg0->y_pos.i.hi = temp_s1->y_pos.i.hi;
    if (arg0->animation_step.fields.relative_step < 0) {
        arg0->unk54--;
    }
    ((void (*)())animate_object)(arg0);
    if (temp_s1->state == 2) {
        arg0->state = 2;
    } else {
        if (arg0->unk54 == 0) {
            arg0->state = 2;
        }
        func_8002CCB0(arg0, 0x10, 0x10);
    }
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800E9BE8(void) {
    clear_object_slot();
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

struct X4_QuadObj* alloc_class6_slot(void);
M2C_UNK clear_object_slot();
extern u8 D_800F4A4C[][8];
extern u8 D_800F4ACC[][8];
extern u8 D_800F4B4C[][8];
extern u8 D_800F4BCC[][8];

#define B(p, o) (*(u8*)((u8*)(p) + (o)))
#define SB(p, o) (*(s8*)((u8*)(p) + (o)))
#define H(p, o) (*(s16*)((u8*)(p) + (o)))
#define P(p, o) (*(void**)((u8*)(p) + (o)))

#define SPAWN(add)                                                             \
    q = alloc_class6_slot();                                                   \
    if (q != NULL) {                                                           \
        u8 a_ = B(self, 0);                                                    \
        q->id = 5;                                                             \
        q->active = a_;                                                        \
        q->unk2 = B(self, 2) + (add);                                          \
    }

void func_800E9C08(void* self) {
    struct X4_QuadObj* q;
    s32 i;

    if (D_800CD30A != 8) {
        clear_object_slot(self);
        return;
    }
    i = SB(self, 2);
    B(self, 0) = 0x51;
    SB(self, 0x37) = -1;
    H(self, 0x34) = 0;
    SB(self, 0x36) = 0x10;
    if (i >= 0x40) {
        P(self, 0x3C) = D_800F4A4C[i];
        H(self, 0x40) = 0x28;
        H(self, 0x42) = 1;
        H(self, 0xA) = 0xA0;
        H(self, 0xE) = 0xEF;
        B(self, 4)++;
        return;
    }
    if (i >= 0x30) {
        P(self, 0x3C) = D_800F4ACC[i];
        H(self, 0x40) = 0x28;
        H(self, 0x42) = 1;
        H(self, 0xA) = 0xA0;
        H(self, 0xE) = 0xEF;
        B(self, 4)++;
        return;
    }
    if (i >= 0x20) {
        P(self, 0x3C) = D_800F4B4C[i];
        H(self, 0x40) = -0x3C;
        H(self, 0x42) = -1;
        H(self, 0xA) = 0xA0;
        H(self, 0xE) = 0;
        B(self, 4)++;
        return;
    }
    if (i >= 0x10) {
        P(self, 0x3C) = D_800F4BCC[i];
        H(self, 0x40) = -0x3C;
        H(self, 0x42) = -1;
        H(self, 0xA) = 0xA0;
        H(self, 0xE) = 0;
        B(self, 4)++;
        return;
    }
    SPAWN(0x10);
    SPAWN(0x20);
    SPAWN(0x30);
    SPAWN(0x40);
    B(self, 4) += 2;
}

#include "common.h"
#include "mmx6/x4.h"

void func_800328B0();
extern struct X4_PlayerObj g_Player;
extern u16 D_800F4C7C[];

#define SB(p, o) (*(s8*)((u8*)(p) + (o)))
#define H(p, o) (*(s16*)((u8*)(p) + (o)))
#define UH(p, o) (*(u16*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))
#define P(p, o) (*(u16**)((u8*)(p) + (o)))

void func_800E9DF8(void* self) {
    u16* r = P(self, 0x3C);
    u16 a = UH(self, 0x40);
    u16 v = UH(self, 0x42);
    u16 x = r[0];
    u16 w = r[2];
    u16 y = r[1];
    u16 h = r[3];
    s16 x0, x1, y0, y1;
    s32 i;

    UH(self, 0x40) = a + v;
    x0 = x - w;
    x1 = x + w;
    y0 = y - h;
    y1 = y + h;
    if ((u16)(UH(self, 0x40) + 0x80) > 0x100) {
        s32 t = (s16)v;
        H(self, 0x42) = -t;
    }
    if (g_Player.x_pos.i.hi < x0 || x1 < g_Player.x_pos.i.hi ||
        g_Player.y_pos.i.hi < y0 || y1 < g_Player.y_pos.i.hi) {
        if (--W(self, 0x38) < 0) {
            W(self, 0x38) = 0;
            H(self, 0x34) = 0;
            return;
        }
    } else {
        if (++W(self, 0x38) >= 0x40) {
            W(self, 0x38) = 0x3F;
        }
    }
    i = SB(self, 2);
    if (i >= 0x40) {
        H(self, 0x1A) = -0xEF;
        H(self, 0x1E) = 0x100;
        H(self, 0x22) = -0xEF;
        H(self, 0x26) = 0x100;
        H(self, 0x2A) = 0;
        H(self, 0x2E) = 0;
        H(self, 0x32) = 0;
        H(self, 0x16) = UH(self, 0x40) + 0x78;
    } else if (i >= 0x30) {
        H(self, 0x16) = -0x100;
        H(self, 0x1A) = -0xEF;
        H(self, 0x22) = -0xEF;
        H(self, 0x26) = 0;
        H(self, 0x2A) = 0;
        H(self, 0x2E) = -0x100;
        H(self, 0x32) = 0;
        H(self, 0x1E) = UH(self, 0x40) - 0x78;
    } else if (i >= 0x20) {
        H(self, 0x16) = 0;
        H(self, 0x1A) = 0;
        H(self, 0x1E) = 0x100;
        H(self, 0x22) = 0;
        H(self, 0x26) = 0x100;
        H(self, 0x2A) = 0xEF;
        H(self, 0x2E) = UH(self, 0x40) + 0x78;
        H(self, 0x32) = 0xEF;
    } else if (i >= 0x10) {
        H(self, 0x16) = -0x100;
        H(self, 0x1A) = 0;
        H(self, 0x1E) = 0;
        H(self, 0x22) = 0;
        H(self, 0x2A) = 0xEF;
        H(self, 0x2E) = -0x100;
        H(self, 0x32) = 0xEF;
        H(self, 0x26) = UH(self, 0x40) - 0x78;
    }
    UH(self, 0x34) = D_800F4C7C[W(self, 0x38) / 4];
    func_800328B0(self);
}

#define func_80046C64 func_800EA02C
#define D_800762A0 D_800F4C9C
#include "../shared/d1000/func_80046C64.c"
#undef func_80046C64
#undef D_800762A0

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EA06C(void) {
    clear_object_slot();
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SCRATCH_BASE (*(u8**)0x1F800028)

M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);        /* extern */
M2C_UNK func_8002B54C(M2C_UNK*, M2C_UNK*, M2C_UNK, u16); /* extern */
extern struct X4_EngineObj g_playthrough_state;
extern u8* D_800F4E7C[];
extern u8 D_800F4E8C[];
extern M2C_UNK D_800F62F0;
extern M2C_UNK D_800F66F0;

void func_800EA08C(void* arg0) {
    u8 t;
    s32 i;
    u8* p;
    struct X4_EngineObj* e;

    t = M2C_FIELD(arg0, u8*, 2);
    if (M2C_FIELD(arg0, s8*, 2) == 4) {
        M2C_FIELD(arg0, u16*, 0x14) = 0x20;
        M2C_FIELD(arg0, s16*, 0x16) = 0;
        e = &g_playthrough_state;
        if (M2C_FIELD(e, s8*, 0x32) == 0) {
            M2C_FIELD(e, s8*, 0x32) = 1;
            __builtin_memcpy(SCRATCH_BASE + 0x3800, SCRATCH_BASE + 0x1260,
                             0x400);
        }
        __builtin_memcpy((u8*)&D_800F62F0, SCRATCH_BASE + 0x3800, 0x400);
        func_8002B54C(&D_800F66F0, &D_800F62F0, 0x200,
                      M2C_FIELD(arg0, u16*, 0x14));
        load_palette(0x93, &D_800F66F0, 0x20);
        M2C_FIELD(arg0, u8*, 4) = 2;
        M2C_FIELD(arg0, u8*, 5) = 0;
        return;
    }
    M2C_FIELD(arg0, u8*, 0x15) = t & 0x80;
    M2C_FIELD(arg0, u8*, 2) = t & 0x7F;
    i = M2C_FIELD(arg0, s8*, 2);
    M2C_FIELD(arg0, u8*, 0x14) = D_800F4E8C[i * 6];
    p = D_800F4E7C[i];
    M2C_FIELD(arg0, u8**, 0x1C) = p;
    M2C_FIELD(arg0, u8*, 0x18) = p[0];
    M2C_FIELD(arg0, u8*, 0x19) = p[1];
    M2C_FIELD(arg0, u8*, 0x1A) = p[2];
    M2C_FIELD(arg0, u8*, 0x1B) = p[3];
    M2C_FIELD(arg0, u8*, 4) = 1;
}

#define func_80041AB8 func_800EA2EC
#define D_80075FD8 D_800F4EA4
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

// clang-format off
INCLUDE_ASM("asm/rock_08/nonmatchings/E9860", func_800EA328);
// clang-format on

#include "common.h"
#include "mmx6/x4.h"

extern struct X4_PlayerObj g_Player;
extern void (*D_800F4EB4[])(s8*);

void func_800EA3D4(s8* arg0) {
    struct X4_PlayerObj* p = &g_Player;

    if ((u32)(p->x_pos.u.hi - 1) < 0x77F && p->y_pos.i.hi >= 0x5E1 &&
        p->y_pos.i.hi < 0xA30) {
        D_800F4EB4[arg0[5]](arg0);
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);        /* extern */
M2C_UNK func_8002B54C(M2C_UNK*, M2C_UNK*, M2C_UNK, u16); /* extern */
#include "mmx6/state.h"
extern M2C_UNK D_800F62F0;
extern M2C_UNK D_800F66F0;

void func_800EA448(void* arg0) {
    if (!(D_80097420.frame_counter & 1)) {
        func_8002B54C(&D_800F66F0, &D_800F62F0, 0x200,
                      M2C_FIELD(arg0, u16*, 0x14));
        load_palette(0x93, &D_800F66F0, 0x20);
        M2C_FIELD(arg0, u16*, 0x14) = (u16)(M2C_FIELD(arg0, u16*, 0x14) - 1);
    }
    if (M2C_FIELD(arg0, u16*, 0x14) == 0) {
        M2C_FIELD(arg0, s16*, 0x16) = 8;
        M2C_FIELD(arg0, u8*, 5) = (u8)(M2C_FIELD(arg0, u8*, 5) + 1);
    }
}

#include "../shared/rock_08/func_800EA4E0.c"

#include "common.h"

void func_800EA58C(u8* arg0) {
    if ((*(u16*)(arg0 + 0x16))++ >= 0x12D) {
        *(u16*)(arg0 + 0x16) = 8;
        arg0[5]++;
    }
}

#define func_800EA4E0 func_800EA5C4
#include "../shared/rock_08/func_800EA4E0.c"
#undef func_800EA4E0

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);        /* extern */
M2C_UNK func_8002B54C(M2C_UNK*, M2C_UNK*, M2C_UNK, u16); /* extern */
extern M2C_UNK D_800F62F0;
extern M2C_UNK D_800F66F0;

void func_800EA670(void* arg0) {
    if (!(D_80097420.frame_counter & 1)) {
        func_8002B54C(&D_800F66F0, &D_800F62F0, 0x200,
                      M2C_FIELD(arg0, u16*, 0x14));
        load_palette(0x93, &D_800F66F0, 0x20);
        M2C_FIELD(arg0, u16*, 0x14) = (u16)(M2C_FIELD(arg0, u16*, 0x14) + 1);
    }
    if ((u16)M2C_FIELD(arg0, u16*, 0x14) >= 0x21U) {
        M2C_FIELD(arg0, s16*, 0x16) = 0;
        M2C_FIELD(arg0, u8*, 5) = (u8)(M2C_FIELD(arg0, u8*, 5) + 1);
    }
}

#include "common.h"

void func_800EA70C(void* arg0) {
    if ((*(u16*)((u8*)arg0 + 0x16))++ >= 0x79) {
        *(u16*)((u8*)arg0 + 0x16) = 0;
        *((u8*)arg0 + 5) = 0;
    }
}

#include "common.h"

void func_800EA738(void) {
}

// clang-format off
INCLUDE_ASM("asm/rock_08/nonmatchings/E9860", func_800EA740);

INCLUDE_ASM("asm/rock_08/nonmatchings/E9860", func_800EA820);
// clang-format on

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define FX(p, type, off) (*(type*)((u8*)(p) + (off)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
s32 set_animation(void*, s32);
void func_8002CCB0(struct X4_BaseObj*, s32, s32);
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
M2C_UNK collide_solid_object();
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
M2C_UNK func_80049E50(void*);
extern M2C_UNK D_8007433C;
extern s32 D_800970A8;
extern s16 D_800970AA;
extern M2C_UNK D_800F55DC;
extern M2C_UNK D_800F55FC;
extern void (*D_800F5610[])(void*);

void func_800EAC90(void* arg0) {
    void* parent;
    s8 saved;
    s32 d;

    parent = FX(arg0, void*, 0x7C);
    saved = FX(arg0, s8, 0x5C);
    FX(arg0, u16, 0x42) &= 0x7FFF;
    if (FX(arg0, s8, 0x2) >= 10) {
        FX(arg0, u8, 0x15) = (FX(arg0, s32, 0x8) <= D_800970A8) << 6;
    }
    if (FX(arg0, s8, 0x45) & 0xF0) {
        FX(arg0, void*, 0x58) = &D_8007433C;
    } else {
        FX(arg0, void*, 0x58) = &D_800743DC;
    }
    if (check_enemy_hits(arg0) < 0 && FX(arg0, s8, 0x2) != 0) {
        FX(parent, u8, 0x5C)--;
        func_80049E50(arg0);
        func_800477E4(3, &D_800F55DC, arg0);
        FX(arg0, void*, 0x54) = &D_800F55FC;
        FX(arg0, s32, 0x50) = 0;
        FX(arg0, void*, 0x58) = &D_8007433C;
        FX(arg0, s8, 0x4) = 2;
        switch (FX(arg0, s8, 0x2)) {
        case 10:
            set_animation(arg0, 0x14);
            func_800477E4(3, &D_800F55DC, arg0);
            break;
        case 11:
            set_animation(arg0, 0x14);
            func_800477E4(3, &D_800F55DC, arg0);
            break;
        case 12:
            FX(arg0, s8, 0x3) = 0;
            FX(arg0, s8, 0x4) = 3;
            func_800477E4(5, &D_800F55DC, arg0);
            play_sound(2, 0x14, arg0);
            break;
        case 13:
            set_animation(arg0, 0x14);
            func_800477E4(3, &D_800F55DC, arg0);
            break;
        case 14:
            set_animation(arg0, 0x15);
            func_800477E4(3, &D_800F55DC, arg0);
            break;
        }
        return;
    }
    if (FX(arg0, s8, 0x5C) != saved) {
        FX(arg0, u16, 0x42) |= 0x8000;
    }
    D_800F5610[FX(arg0, s8, 0x6)](arg0);
    func_8002CCB0(arg0, 0x60, 0x80);
    d = D_800970AA - FX(arg0, s16, 0xA);
    if (d >= 0) {
        if (d < 0x30) {
            // !FAKE: per-sign range test needs the goto (C0144); a duplicated call moved bytes
            goto near;
        }
    } else if (FX(arg0, s16, 0xA) - D_800970AA < 0x30) {
    near:
        collide_solid_object(arg0);
    }
    if (FX(arg0, s8, 0x6) != 2) {
        func_80030ECC(arg0);
    }
}
#undef FX

#include "../shared/rock_08/func_800EAEF8.c"

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK animate_object();
M2C_UNK apply_object_motion(s32);

void func_800EB098(struct X4_MainObj* self) {
    s32 v;
    s32 q;

    animate_object();
    apply_object_motion(self);
    if (*(s16*)((u8*)self + 0x82) < self->x_pos.i.hi + 8 &&
        self->x_pos.i.hi - 8 < *(s16*)((u8*)self + 0x82)) {
        if (*(s16*)((u8*)self + 0x84) < self->y_pos.i.hi + 8 &&
            self->y_pos.i.hi - 8 < *(s16*)((u8*)self + 0x84)) {
            if (self->unk15 != 0) {
                v = -self->x_speed;
            } else {
                v = self->x_speed;
            }
            q = v >> 4;
            if (v < 0) {
                q = (v + 0xF) >> 4;
            }
            self->x_accel = q;
            self->gravity = self->y_speed / 16;
            *(s16*)((u8*)self + 0x80) = 0x10;
            self->unk7++;
        }
    }
    if (self->on_screen != 0 && !(D_80097420.frame_counter & 0x1F)) {
        play_sound(2, 0xD, self);
    }
}

#include "../shared/rock_08/func_800EB1A0.c"

#include "../shared/rock_08/func_800EB298.c"

// clang-format off
INCLUDE_ASM("asm/rock_08/nonmatchings/E9860", func_800EB398);
// clang-format on

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800139A0(M2C_UNK);              /* extern */
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
void func_80029F38();                        /* extern */
M2C_UNK func_8002B36C(M2C_UNK);              /* extern */
M2C_UNK func_8002B6B0();                     /* extern */
extern struct X4_PlayerObj g_Player;
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj g_playthrough_state;
extern u8 D_800F5644[];
extern s16 D_800F5754[][16];

#define IDX D_800F5644[M2C_FIELD(arg0, s8*, 2) + base]
#define IDX2 D_800F5644[M2C_FIELD(arg0, s8*, 2) + base2]

void func_800EBEA0(void* arg0) {
    s32 temp_a1;
    s32 temp_a0;
    s16 temp_v1;
    s16 temp_y;
    s32 base;
    s32 base2;

    temp_a1 = M2C_FIELD(arg0, u16*, 0x82) + 1;
    temp_a0 = M2C_FIELD(arg0, u16*, 0x84) - 1;
    M2C_FIELD(arg0, u16*, 0x82) = temp_a1;
    M2C_FIELD(arg0, u16*, 0x84) = temp_a0;
    if (!(D_80097420.frame_counter & 1)) {
        g_Player.x_pos.i.hi = temp_a1;
    } else {
        g_Player.x_pos.i.hi = temp_a0;
    }
    if (D_80097420.transition.active == 0) {
        temp_v1 = D_800F5754
            [D_800F5644[M2C_FIELD(arg0, s8*, 2) +
                        (base =
                             g_playthrough_state.character_state.bytes[10] * 4 -
                             1)]][0];
        temp_y = D_800F5754[IDX][1];
        g_Player.x_pos.i.hi = temp_v1;
        g_Player.y_pos.i.hi = temp_y;
        M2C_FIELD(arg0, u16*, 0x82) = temp_v1 + 0x40;
        M2C_FIELD(arg0, u16*, 0x84) = temp_v1 - 0x40;
        if (g_Player.character != 0) {
            g_Player.y_pos.i.hi--;
        }
        g_Player.spike_immune = 0;
        g_playthrough_state.gameplay_locked = 0;
        g_Player.nova_strike_active = 0;
        g_Player.unk18.val = g_Player.x_pos.val;
        g_Player.unk1C.val = g_Player.y_pos.val;
        func_8002B36C(0);
        D_800C4560 = 1;
        g_Player.unkE4 = 0;
        background_objects[0].unk44 = 1;
        background_objects[1].unk44 = 1;
        background_objects[2].unk44 = 1;
        base2 = g_playthrough_state.character_state.bytes[10] * 4 - 1;
        background_objects[0].x_pos.i.hi = D_800F5754[IDX2][2];
        background_objects[0].y_pos.i.hi = D_800F5754[IDX2][3];
        background_objects[1].x_pos.i.hi = D_800F5754[IDX2][4];
        background_objects[1].y_pos.i.hi = D_800F5754[IDX2][5];
        background_objects[2].x_pos.i.hi = D_800F5754[IDX2][6];
        background_objects[2].y_pos.i.hi = D_800F5754[IDX2][7];
        background_objects[0].unk1E = D_800F5754[IDX2][8];
        background_objects[0].unk1C = D_800F5754[IDX2][9];
        background_objects[0].unk22 = D_800F5754[IDX2][10];
        background_objects[0].unk20 = D_800F5754[IDX2][11];
        background_objects[0].unk26 = D_800F5754[IDX2][8];
        background_objects[0].unk24 = D_800F5754[IDX2][9];
        background_objects[0].unk2A = D_800F5754[IDX2][10];
        background_objects[0].unk28 = D_800F5754[IDX2][11];
        background_objects[0].unk4C = 1;
        background_objects[1].unk4C = 1;
        background_objects[2].unk4C = 1;
        g_Player.air_state = 0;
        func_8002B6B0();
        g_Player.unkE4 = 0;
        g_Player.hurt_phase = 0;
        g_Player.invincibility_timer = 0;
        func_80029F38(background_objects[0].x_pos.i.hi - 0x30,
                      background_objects[0].x_pos.i.hi + 0x170,
                      background_objects[0].y_pos.i.hi - 0x30,
                      background_objects[0].y_pos.i.hi + 0x120, 0);
        func_800139A0(8);
        background_objects[0].unk44 = 0;
        background_objects[1].unk44 = 0;
        play_sound(1, 1, arg0);
        M2C_FIELD(arg0, u8*, 7) = M2C_FIELD(arg0, u8*, 7) + 1;
    }
}

#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_8003AD18(void* arg0);
extern struct X4_PlayerObj g_Player;
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj g_playthrough_state;
extern u8 D_800F5644[];
extern s16 D_800F5754[][16];

void func_800EC2F0(void* arg0) {
    s32 a;
    s32 b;

    a = M2C_FIELD(arg0, u16*, 0x82) - 1;
    M2C_FIELD(arg0, u16*, 0x80) += 1;
    M2C_FIELD(arg0, u16*, 0x82) = a;
    b = M2C_FIELD(arg0, u16*, 0x84) + 1;
    M2C_FIELD(arg0, u16*, 0x84) = b;
    if (!(D_80097420.frame_counter & 1)) {
        struct X4_PlayerObj* p = &g_Player;
        M2C_FIELD(p, s16*, 0xA) = a;
    } else {
        struct X4_PlayerObj* p = &g_Player;
        M2C_FIELD(p, s16*, 0xA) = b;
    }
    if (M2C_FIELD(arg0, s16*, 0x80) >= 0x1D) {
        struct X4_PlayerObj* p;
        s32 base;
        background_objects[0].unk44 = 1;
        background_objects[1].unk44 = 1;
        p = &g_Player;
        M2C_FIELD(p, s16*, 0xA) = D_800F5754
            [D_800F5644[M2C_FIELD(arg0, s8*, 0x2) +
                        (base =
                             g_playthrough_state.character_state.bytes[10] * 4 -
                             1)]][0];
        M2C_FIELD(p, s32*, 0x68) = M2C_FIELD(arg0, s32*, 0x88);
        func_8003AD18(p);
        g_playthrough_state.unk10 = 0;
        g_playthrough_state.unk11 = 0;
        g_playthrough_state.unk12 = 0;
        g_playthrough_state.unk13 = 0;
        g_playthrough_state.unk14 = 0;
        g_playthrough_state.unk15 = 0;
        g_playthrough_state.unk17 = 0;
        g_playthrough_state.unk19 = 0;
        M2C_FIELD(arg0, u8*, 0x0) &= 0xF7;
        M2C_FIELD(arg0, u8*, 0x7) += 1;
    }
}

#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
extern struct X4_PlayerObj g_Player;
extern M2C_UNK D_800F586C;
extern M2C_UNK D_800F5870;
extern M2C_UNK D_800F5874;
extern M2C_UNK D_800F5878;

void func_800EC41C(void* arg0) {
    M2C_FIELD(arg0, u8*, 0x3) = 1;
    if (M2C_FIELD(arg0, s8*, 0x2) == 0) {
        struct X4_PlayerObj* pl = &g_Player;
        s32 angle;
        s32 x;
        s32 t;
        s32 t2;
        angle = ratan2(M2C_FIELD(pl, s16*, 0xE) - M2C_FIELD(arg0, s16*, 0xE),
                       M2C_FIELD(pl, s16*, 0xA) - M2C_FIELD(arg0, s16*, 0xA));
        t = rcos(angle) << 4;
        M2C_FIELD(arg0, s32*, 0x20) = (t * 2 + t) >> 1;
        t2 = -rsin(angle) << 4;
        M2C_FIELD(arg0, s32*, 0x24) = (t2 * 2 + t2) >> 1;
        x = M2C_FIELD(arg0, s16*, 0xA);
        M2C_FIELD(arg0, s16*, 0xA) =
            (M2C_FIELD(arg0, u8*, 0x15) != 0) ? x + 0x12 : x - 0x12;
        M2C_FIELD(arg0, void**, 0x68) = &D_800F5874;
        M2C_FIELD(arg0, void**, 0x54) = &D_800F586C;
        M2C_FIELD(arg0, void**, 0x50) = &D_800F586C;
        M2C_FIELD(arg0, u8*, 0x16) = 3;
        M2C_FIELD(arg0, s16*, 0xE) += 8;
        set_animation(arg0, 0x10);
    } else {
        u8 dir1;
        s32 x1;
        dir1 = M2C_FIELD(arg0, u8*, 0x15);
        x1 = -0x18000;
        if (dir1 != 0) {
            x1 = 0x18000;
        }
        M2C_FIELD(arg0, s32*, 0x20) = x1;
        x1 = M2C_FIELD(arg0, s16*, 0xA);
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        if (dir1 != 0) {
            x1 += 3;
        } else {
            x1 -= 3;
        }
        M2C_FIELD(arg0, s16*, 0xA) = x1;
        M2C_FIELD(arg0, void**, 0x68) = &D_800F5878;
        M2C_FIELD(arg0, void**, 0x54) = &D_800F5870;
        M2C_FIELD(arg0, void**, 0x50) = &D_800F5870;
        M2C_FIELD(arg0, u8*, 0x16) = 6;
        set_animation(arg0, 0xB);
    }
    M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, u8*, 0x61) = 0;
    M2C_FIELD(arg0, u8*, 0x60) = 4;
    M2C_FIELD(arg0, u8*, 0x4) += 1;
}

#include "../shared/rock_08/func_800EC5AC.c"

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define FX(p, type, off) (*(type*)((u8*)(p) + (off)))

M2C_UNK clear_object_slot();
void func_8002CCB0(struct X4_BaseObj*, s32, s32);
M2C_UNK func_8002F288(M2C_UNK*);
s32 check_enemy_hits(void*);
M2C_UNK collide_solid_object();
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
M2C_UNK func_80049EBC(void*, M2C_UNK, M2C_UNK, M2C_UNK);
extern M2C_UNK D_800F55DC;

void func_800EC614(void* arg0) {
    void* parent;
    s32 i;

    parent = FX(arg0, void*, 0x7C);
    FX(arg0, u16, 0x42) &= 0x7FFF;
    collide_solid_object();
    check_enemy_hits(arg0);
    func_8002F288(arg0);
    func_8002CCB0(arg0, 0x40, 0x20);
    if (FX(parent, s8, 0x4) == 3) {
        for (i = 4; i >= 0; i--) {
            func_80049EBC(arg0, 1, 0x10, 0x10);
        }
        func_800477E4(4, &D_800F55DC, arg0);
        FX(arg0, u8, 0x3) = 0;
        clear_object_slot(arg0);
    }
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EC6BC(void) {
    clear_object_slot();
}

#include "../shared/rock_08/func_800EC6DC.c"

#include "../shared/rock_08/func_800EC724.c"

#include "../shared/rock_08/func_800EC7F0.c"

#include "../shared/rock_08/func_800EC8BC.c"

#include "../shared/rock_08/func_800EC9B4.c"

#define func_80041AB8 func_800ECAB4
#define D_80075FD8 D_800F5854
#define FAMILY_FIELD 7
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#define func_80041AB8 func_800ECAF0
#define D_80075FD8 D_800F5630
#define FAMILY_FIELD 7
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#include "common.h"
#include "mmx6/globals.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */

void func_800ECB2C(void* arg0) {
    s32 var_a0;

    var_a0 = 0xFFFE0000;
    if ((M2C_FIELD(M2C_FIELD(arg0, void**, 0x7C), s8*, 0x5C) < 4) ||
        ((u8)D_800CCF38 >= 2U)) {
        M2C_FIELD(arg0, s16*, 0x80) = 0xA;
        if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
            var_a0 = 0x20000;
        }
        M2C_FIELD(arg0, s32*, 0x20) = var_a0;
        if (M2C_FIELD(arg0, s8*, 3) != 0) {
            play_sound(2, 0xC, arg0);
        }
        M2C_FIELD(arg0, u8*, 7) = (u8)(M2C_FIELD(arg0, u8*, 7) + 1);
    }
}

#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define OH(p, o) (*(s16*)((u8*)(p) + (o)))
#define OW(p, o) (*(s32*)((u8*)(p) + (o)))

s32 set_animation(void*, s32);
M2C_UNK animate_object();
M2C_UNK apply_object_motion(s32);
extern struct X4_PlayerObj g_Player;

void func_800ECBC4(struct X4_MainObj* self) {
    s32 a;

    animate_object();
    {
        // !FAKE: depin: dropping it breaks the match (51/55)
        register s32 t asm("$2") = OH(self, 0x80);
        if (t != 0) {
            OH(self, 0x80)--;
            apply_object_motion((s32)self);
            return;
        }
    }
    OH(self, 0x82) = g_Player.x_pos.i.hi;
    OH(self, 0x84) = g_Player.y_pos.i.hi;
    set_animation(self, 0x11);
    {
        u16 x = g_Player.x_pos.i.hi;
        u16 y;
        OH(self, 0x82) = x;
        y = g_Player.y_pos.i.hi;
        OH(self, 0x84) = y;
        a = ratan2((s16)y - self->y_pos.i.hi, (s16)x - self->x_pos.i.hi);
    }
    OW(self, 0x20) = rcos(a) << 5;
    OW(self, 0x24) = -rsin(a) << 5;
    self->unk7++;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK animate_object();
M2C_UNK apply_object_motion(s32);

void func_800ECCA0(struct X4_MainObj* arg0) {
    animate_object();
    ((void (*)(void*))apply_object_motion)(arg0);
    if (--M2C_FIELD(arg0, s16*, 0x80) == -1) {
        arg0->x_speed = 0;
        arg0->y_speed = 0;
        arg0->x_accel = 0;
        arg0->gravity = 0;
        M2C_FIELD(arg0, s16*, 0x80) = 0x28;
        arg0->unk7++;
    }
    if (arg0->on_screen != 0 && !(D_80097420.frame_counter & 0x1F)) {
        play_sound(2, 0xD, arg0);
    }
}

#include "../shared/rock_08/func_800ECD3C.c"

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800ECDA4(void) {
    clear_object_slot();
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK animate_object();
s32 is_off_screen(void*, M2C_UNK, M2C_UNK);
void func_8002CCB0(struct X4_BaseObj*, s32, s32);
M2C_UNK move_object(void*);
#define move_object ((void (*)(void*))move_object)
M2C_UNK func_8002EE10(void*);
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
M2C_UNK func_80049D90(void*);
M2C_UNK func_80049E50(void*);

void func_800ECDC4(struct X4_PlayerObj* self) {
    animate_object();
    move_object(self);
    self->unk42 &= 0x7FFF;

    if (func_80030ECC(self) != 0) {
        if (self->character != 0) {
            func_80049E50(self);
        } else {
            func_80049D90(self);
        }
        self->state = 2;
        return;
    }
    if (self->character != 0 && check_enemy_hits(self) < 0) {
        func_80049E50(self);
        self->state = 2;
        return;
    }
    if (self->collision_flags != 0 ||
        (func_8002EE10(self), self->collision_flags != 0)) {
        if (self->character != 0) {
            func_80049E50(self);
        } else {
            func_80049D90(self);
        }
        self->state = 2;
        return;
    }
    if (is_off_screen(self, 0x20, 0x20) == 0) {
        func_8002CCB0((struct X4_BaseObj*)self, 0x10, 0x10);
        return;
    }
    self->state = 2;
}
#undef move_object

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK clear_object_slot(); /* extern */

void func_800ECEE8(struct ObjectHeader* arg0) {
    arg0->on_screen = 0;
    clear_object_slot();
}

#define func_80041AB8 func_800ECF08
#define D_80075FD8 D_800F587C
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

struct X4_VisualObj* find_free_visual_obj(void);
s32 func_8002D30C();
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
extern M2C_UNK D_800F58EC;

#define SPAWN()                                                                \
    {                                                                          \
        o = find_free_visual_obj();                                            \
        if (o != 0) {                                                          \
            M2C_FIELD(o, u8*, 0) = 0x21;                                       \
            M2C_FIELD(o, u8*, 1) = 4;                                          \
            M2C_FIELD(o, u8*, 2) = 0;                                          \
            M2C_FIELD(o, u8*, 4) = 0;                                          \
            M2C_FIELD(o, u8*, 5) = 0;                                          \
            M2C_FIELD(o, u8*, 6) = 0;                                          \
            t = func_8002D30C() % 32 - 0x10;                                   \
            M2C_FIELD(o, s16*, 0xA) = M2C_FIELD(arg0, s16*, 0xA) + t;          \
            t = func_8002D30C() % 48 - 0x18;                                   \
            r = M2C_FIELD(arg0, u16*, 0xE);                                    \
            M2C_FIELD(o, u8*, 0x15) = 0;                                       \
            M2C_FIELD(o, u8*, 0x14) = 0;                                       \
            M2C_FIELD(o, u8*, 0x16) = 1;                                       \
            r += t;                                                            \
            M2C_FIELD(o, s16*, 0xE) = r;                                       \
        }                                                                      \
    }

void func_800ECF44(void* arg0) {
    void* o;
    s32 r;
    s32 t;

    M2C_FIELD(arg0, s32*, 0x54) = 0;
    M2C_FIELD(arg0, s32*, 0x50) = 0;
    if (M2C_FIELD(arg0, s16*, 0x7C) != 0) {
        M2C_FIELD(arg0, s16*, 0x7C)--;
        if (!(M2C_FIELD(arg0, u8*, 0x7C) & 7)) {
            SPAWN();
            if (!(M2C_FIELD(arg0, u8*, 0x7C) & 0x1F)) {
                func_800477E4(3, &D_800F58EC, arg0);
            }
        }
    } else {
        M2C_FIELD(arg0, u8*, 5) = 3;
        M2C_FIELD(arg0, s16*, 0x7C) = 0x1E;
        SPAWN();
        func_800477E4(3, &D_800F58EC, arg0);
    }
}

#include "../shared/rock_08/func_800ED148.c"

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800139A0(M2C_UNK);              /* extern */
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
void func_80029F38();                        /* extern */
M2C_UNK func_8002B36C(M2C_UNK);              /* extern */
M2C_UNK func_8002B6B0();                     /* extern */
extern struct X4_PlayerObj g_Player;
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj g_playthrough_state;
extern s16 D_800F5910[][16];

void func_800ED258(void* arg0) {
    s32 temp_a1;
    s32 temp_a0;
    s16 temp_v1;
    s16 temp_y;

    temp_a1 = M2C_FIELD(arg0, u16*, 0x80) + 1;
    temp_a0 = M2C_FIELD(arg0, u16*, 0x82) - 1;
    M2C_FIELD(arg0, u16*, 0x80) = temp_a1;
    M2C_FIELD(arg0, u16*, 0x82) = temp_a0;
    if (!(D_80097420.frame_counter & 1)) {
        g_Player.x_pos.i.hi = temp_a1;
    } else {
        g_Player.x_pos.i.hi = temp_a0;
    }
    if (D_80097420.transition.active == 0) {
        temp_v1 = D_800F5910[g_playthrough_state.character_state.bytes[9]][0];
        temp_y = D_800F5910[g_playthrough_state.character_state.bytes[9]][1];
        g_Player.x_pos.i.hi = temp_v1;
        g_Player.y_pos.i.hi = temp_y;
        M2C_FIELD(arg0, u16*, 0x80) = temp_v1 + 0x40;
        M2C_FIELD(arg0, u16*, 0x82) = temp_v1 - 0x40;
        if (g_Player.character != 0) {
            g_Player.y_pos.i.hi--;
        }
        g_Player.spike_immune = 0;
        g_playthrough_state.gameplay_locked = 0;
        g_Player.nova_strike_active = 0;
        g_Player.unk18.val = g_Player.x_pos.val;
        g_Player.unk1C.val = g_Player.y_pos.val;
        func_8002B36C(0);
        D_800C4560 = 1;
        g_Player.unkE4 = 0;
        background_objects[0].unk44 = 1;
        background_objects[1].unk44 = 1;
        background_objects[2].unk44 = 1;
        background_objects[0].unk4C = 1;
        background_objects[1].unk4C = 1;
        background_objects[2].unk4C = 1;
        background_objects[0].x_pos.i.hi =
            D_800F5910[g_playthrough_state.character_state.bytes[9]][2];
        background_objects[0].y_pos.i.hi =
            D_800F5910[g_playthrough_state.character_state.bytes[9]][3];
        background_objects[1].x_pos.i.hi =
            D_800F5910[g_playthrough_state.character_state.bytes[9]][4];
        background_objects[1].y_pos.i.hi =
            D_800F5910[g_playthrough_state.character_state.bytes[9]][5];
        background_objects[2].x_pos.i.hi =
            D_800F5910[g_playthrough_state.character_state.bytes[9]][6];
        background_objects[2].y_pos.i.hi =
            D_800F5910[g_playthrough_state.character_state.bytes[9]][7];
        background_objects[0].unk1E =
            D_800F5910[g_playthrough_state.character_state.bytes[9]][8];
        background_objects[0].unk1C =
            D_800F5910[g_playthrough_state.character_state.bytes[9]][9];
        background_objects[0].unk22 =
            D_800F5910[g_playthrough_state.character_state.bytes[9]][10];
        background_objects[0].unk20 =
            D_800F5910[g_playthrough_state.character_state.bytes[9]][11];
        background_objects[0].unk26 =
            D_800F5910[g_playthrough_state.character_state.bytes[9]][8];
        background_objects[0].unk24 =
            D_800F5910[g_playthrough_state.character_state.bytes[9]][9];
        background_objects[0].unk2A =
            D_800F5910[g_playthrough_state.character_state.bytes[9]][10];
        background_objects[0].unk28 =
            D_800F5910[g_playthrough_state.character_state.bytes[9]][11];
        g_Player.air_state = 0;
        func_8002B6B0();
        g_Player.unkE4 = 0;
        g_Player.hurt_phase = 0;
        g_Player.invincibility_timer = 0;
        func_80029F38(background_objects[0].x_pos.i.hi - 0x30,
                      background_objects[0].x_pos.i.hi + 0x170,
                      background_objects[0].y_pos.i.hi - 0x30,
                      background_objects[0].y_pos.i.hi + 0x120, 0);
        func_800139A0(8);
        background_objects[0].unk44 = 0;
        background_objects[1].unk44 = 0;
        background_objects[2].unk44 = 0;
        play_sound(1, 1, arg0);
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    }
}

#include "common.h"
#include "mmx6/x4.h"

void func_8003AD18(void* arg0);
extern struct X4_PlayerObj g_Player;
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj g_playthrough_state;
extern s16 D_800F5910[][16];

#define F16(p, o) (*(s16*)((u8*)(p) + (o)))
#define FU16(p, o) (*(u16*)((u8*)(p) + (o)))

void func_800ED4B0(u8* arg0) {
    s32 a;
    s32 b;
    u8* q;

    F16(arg0, 0x7C)++;
    a = FU16(arg0, 0x80) - 1;
    FU16(arg0, 0x80) = a;
    b = FU16(arg0, 0x82) + 1;
    FU16(arg0, 0x82) = b;
    if (!(D_80097420.frame_counter & 1)) {
        g_Player.x_pos.i.hi = a;
    } else {
        g_Player.x_pos.i.hi = b;
    }
    if (F16(arg0, 0x7C) >= 0x1D) {
        background_objects[0].unk44 = 1;
        background_objects[1].unk44 = 1;
        background_objects[2].unk44 = 1;
        g_Player.x_pos.i.hi =
            D_800F5910[g_playthrough_state.character_state.bytes[9]][0];
        g_Player.terrain_box = *(void**)(arg0 + 0x84);
        func_8003AD18(&g_Player);
        q = (u8*)&g_playthrough_state;
        q[0x10] = 0;
        q[0x11] = 0;
        q[0x12] = 0;
        q[0x13] = 0;
        q[0x14] = 0;
        q[0x15] = 0;
        q[0x16] = 0;
        q[0x17] = 0;
        q[0x19] = 0;
        arg0[0] &= 0xF7;
        arg0[6]++;
    }
}

#define func_800EA1D8 func_800ED5C4
#define D_800FAA64 D_800F58F0
#include "../shared/d1000/func_800EA1D8.c"
#undef func_800EA1D8
#undef D_800FAA64

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
extern struct X4_PlayerObj g_Player;
extern s32 D_800F5888;
extern s32 D_800F588C;
extern s32 D_800F5890;
extern s32 D_800F58D8;

void func_800ED610(struct X4_BaseObj* self) {
    struct X4_PlayerObj* pl = &g_Player;
    s32 x;
    s32 y;
    u8 b;

    M2C_FIELD(self, u8*, 0x5C) = 0x20;
    M2C_FIELD(self, u8*, 0x60) = 4;
    M2C_FIELD(self, u8*, 0x61) = 0;
    M2C_FIELD(self, void**, 0x58) = &D_800743DC;
    b = M2C_FIELD(pl, u8*, 0x14);
    x = self->x_pos.val;
    y = self->y_pos.val;
    M2C_FIELD(self, u8*, 0x67) = 0;
    M2C_FIELD(self, u8*, 0x70) = 0;
    M2C_FIELD(self, u8*, 0x14) = b;
    M2C_FIELD(self, s32*, 0x18) = x;
    M2C_FIELD(self, s32*, 0x1C) = y;
    if (pl->x_pos.val < x) {
        self->unk15 = 0;
    } else {
        self->unk15 = 0x40;
    }
    M2C_FIELD(self, s32*, 0x20) = 0;
    M2C_FIELD(self, s32*, 0x28) = 0;
    M2C_FIELD(self, s32*, 0x24) = 0;
    {
        // !FAKE: depin: dropping it breaks the match (50/61)
        register s32 c asm("$3") = 6;
        M2C_FIELD(self, void**, 0x30) = &D_800F58D8;
        self->unk16 = c;
    }
    M2C_FIELD(self, s32*, 0x2C) = 0x4200;
    M2C_FIELD(self, void**, 0x68) = &D_800F5888;
    M2C_FIELD(self, void**, 0x54) = &D_800F5890;
    M2C_FIELD(self, void**, 0x50) = &D_800F588C;
    ((void (*)(void*, s32))set_animation)(self, 1);
    self->action = 1;
    M2C_FIELD(self, s16*, 0x7C) = 0;
    self->state = 1;
    self->action_phase = 0;
}

#include "../shared/rock_08/func_800ED704.c"

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CA14(); /* extern */
M2C_UNK func_8002CA54(); /* extern */

void func_800ED7AC(struct ObjectHeader* arg0) {
    if (arg0->state == 2) {
        func_8002CA14();
        return;
    }
    func_8002CA54();
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK animate_object();         /* extern */
M2C_UNK apply_object_motion(s32); /* extern */

void func_800ED7EC(s32 arg0) {
    animate_object();
    apply_object_motion(arg0);
}

#define func_8003744C func_800ED818
#define D_80073C1C D_800F59A0
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800EF1E8 func_800ED854
#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800139F4(M2C_UNK);
extern s16 D_800970AA;

void func_800ED854(void* arg0) {
    s32 temp_a0;
    s32 temp_a1;

    M2C_FIELD(arg0, u16*, 0x7C) = M2C_FIELD(arg0, u16*, 0x7C) + 1;
    temp_a1 = M2C_FIELD(arg0, u16*, 0x80) + 1;
    M2C_FIELD(arg0, u16*, 0x80) = temp_a1;
    temp_a0 = M2C_FIELD(arg0, u16*, 0x82) - 1;
    M2C_FIELD(arg0, u16*, 0x82) = temp_a0;
    if (!(D_80097420.frame_counter & 1)) {
        D_800970AA = temp_a1;
    } else {
        D_800970AA = temp_a0;
    }
    if (M2C_FIELD(arg0, s16*, 0x7C) >= 0x1D) {
        func_800139F4(8);
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    }
}
#undef func_800EF1E8

#define func_800EF27C func_800ED8E8
#define D_80097420 D_80097420
#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#include "mmx6/x4.h"

extern s16 D_800970AA;

void func_800ED8E8(void* arg0) {
    s32 temp_a1;
    s32 temp_a2;

    temp_a2 = M2C_FIELD(arg0, u16*, 0x80) - 1;
    temp_a1 = M2C_FIELD(arg0, u16*, 0x82) + 1;
    M2C_FIELD(arg0, u16*, 0x80) = temp_a2;
    M2C_FIELD(arg0, u16*, 0x82) = temp_a1;
    if (!(D_80097420.frame_counter & 1)) {
        D_800970AA = temp_a2;
    } else {
        D_800970AA = temp_a1;
    }
    if (D_80097420.transition.active == 0) {
        M2C_FIELD(arg0, u16*, 0x7C) = 0;
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    }
}
#undef func_800EF27C
#undef D_80097420

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define B(p, o) M2C_FIELD(p, u8*, o)
#define H(p, o) M2C_FIELD(p, u16*, o)

void* alloc_class4_slot();
M2C_UNK clear_object_slot();
extern struct X4_EngineObj g_playthrough_state;
extern u8 D_800F5990[];

void func_800ED950(s32 arg0) {
    void* temp_v0;

    temp_v0 = alloc_class4_slot();
    if (temp_v0 != 0) {
        u8* t = D_800F5990;
        struct X4_EngineObj* e = &g_playthrough_state;
        B(temp_v0, 0) = 0x41;
        B(temp_v0, 1) = 3;
        B(temp_v0, 2) = 0;
        H(temp_v0, 0xA) = *(u16*)((M2C_FIELD(e, s8*, 0x2F) * 4) + t);
        H(temp_v0, 0xE) =
            *(u16*)(D_800F5990 + (M2C_FIELD(e, s8*, 0x2F) * 4) + 2);
    }
    clear_object_slot(arg0);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32**)0x1F800020)

s32 set_animation(void*, s32);
s32 func_8002A47C(s32);
M2C_UNK clear_object_slot();
s32 random_byte();

extern u32* D_80095098;
extern s32 D_800F5A20;
extern s32 D_800F5A70;
extern s32 D_800F5A74;
extern s32 D_800F5A78;
extern s32 D_800F5A8C[];

void func_800ED9DC(struct X4_PlayerObj* self) {
    s32 a;
    s32 b;
    s8 kind;
    s32* tbl;

    if (!(random_byte() & 1)) {
        clear_object_slot(self);
        return;
    }
    if (self->character == 0) {
        self->character = (u32)random_byte() % 3;
    }
    self->action = 2;
    self->active = 0x41;
    self->state++;
    self->bg_offset = D_800970B4;
    self->unk40 = D_80095098[func_8002A47C(0x85)] >> 7;
    self->unk3C = (u8*)SPAD20 + SPAD20[func_8002A47C(0x85)];
    a = func_8002A47C(0x85);
    b = func_8002A47C(0x85);
    self->unk42 = ((a * 4 + 0x20) % 16) | (((b + 8) / 4 + 0x1E0) << 6);
    tbl = D_800F5A8C;
    self->unk16 = 0x23;
    self->invincibility_timer = 0;
    self->terrain_box = (struct X4_Unk_unk68*)tbl;
    self->unk58 = &D_800743DC;
    self->hp = 8;
    kind = self->character;
    self->animation_table = (u32**)&D_800F5A20;
    self->facing = 0;
    self->unk65 = 0;
    self->unk54 = 0;
    self->unk50 = 0;
    self->unk60 = 2;
    M2C_FIELD(self, u8*, 0x84) = 0;
    M2C_FIELD(self, u8*, 0x85) = 0;
    self->x_vel.val = 0;
    self->x_accel = 0;
    self->y_vel.val = 0;
    self->gravity = 0;
    self->action_phase = 0;
    if (kind == 3 || kind == 6) {
        if (kind == 6) {
            self->unk16 = 0x22;
        }
        set_animation(self, 0xA);
        self->terrain_box = (struct X4_Unk_unk68*)(tbl + 1);
        self->unk54 = (u32*)&D_800F5A70;
        self->unk50 = 0;
    } else if (kind == 4) {
        set_animation(self, 0xB);
        self->terrain_box = (struct X4_Unk_unk68*)(tbl + 2);
        self->unk54 = (u32*)&D_800F5A74;
    } else {
        set_animation(self, 0xC);
        self->terrain_box = (struct X4_Unk_unk68*)(tbl + 3);
        self->unk54 = (u32*)&D_800F5A78;
    }
    self->unk75 = 1;
    M2C_FIELD(self, u8*, 0xA2) = 1;
    self->invincibility_timer = 0;
    self->unk50 = 0;
    self->unk60 = 0x7F;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK animate_object();
s32 is_off_screen(void*, M2C_UNK, M2C_UNK);
void func_8002CCB0(struct X4_BaseObj*, s32, s32);
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
M2C_UNK collide_solid_object();
void func_80031F4C(struct X4_PlayerObj*);
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
M2C_UNK func_80049EBC(void*, M2C_UNK, M2C_UNK, M2C_UNK);

extern M2C_UNK D_800F5AA4;
extern void (*D_800F5AB8[])(struct X4_PlayerObj*);

void func_800EDC3C(struct X4_PlayerObj* self) {
    s8 hp;
    s8 kind;

    hp = self->hp;
    if (check_enemy_hits(self) < 0) {
        kind = self->character;
        if (kind == 3 || kind == 6) {
            func_800477E4(6, &D_800F5AA4, self);
            func_80049EBC(self, 1, 0x20, 0x30);
            func_80049EBC(self, 1, 0x20, 0x30);
            func_80049EBC(self, 1, 0x20, 0x30);
        } else if (kind == 4) {
            func_800477E4(6, &D_800F5AA4, self);
            func_80049EBC(self, 1, 0x10, 0x20);
            func_80049EBC(self, 1, 0x10, 0x20);
            func_80049EBC(self, 1, 0x10, 0x20);
        } else {
            func_800477E4(6, &D_800F5AA4, self);
            func_80049EBC(self, 1, 0x20, 0x10);
            func_80049EBC(self, 1, 0x20, 0x10);
            func_80049EBC(self, 1, 0x20, 0x10);
        }
        self->state = 2;
        return;
    }
    func_80030ECC(self);
    if (self->hp != hp) {
        self->unk42 |= 0x8000;
    }
    D_800F5AB8[self->action_phase](self);
    animate_object(self);
    collide_solid_object(self);
    if (self->on_screen != 0) {
        func_80031F4C(self);
    }
    if (is_off_screen(self, 0x30, 0x30) == 0) {
        func_8002CCB0(self, 0x30, 0x30);
    }
}

#define func_80048DC8 func_800EDE30
#define D_80077BC0 D_800F5AAC
#include "../shared/d1000/func_80048DC8.c"
#undef func_80048DC8
#undef D_80077BC0

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK clear_object_slot(); /* extern */

void func_800EDE7C(struct ObjectHeader* arg0) {
    arg0->on_screen = 0;
    clear_object_slot();
}

#include "common.h"

void func_800EDE9C(void) {
}

// clang-format off
INCLUDE_ASM("asm/rock_08/nonmatchings/E9860", func_800EDEA4);

INCLUDE_ASM("asm/rock_08/nonmatchings/E9860", func_800EE02C);

INCLUDE_ASM("asm/rock_08/nonmatchings/E9860", func_800EE1C4);
// clang-format on

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002CA54(); /* extern */

void func_800EE240(void) {
    func_8002CA54();
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CA14(void*);                            /* extern */
M2C_UNK func_80049EBC(void*, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */

void func_800EE260(void* arg0) {
    s32 var_s0;
    u16 temp_v1;

    temp_v1 = M2C_FIELD(arg0, u16*, 0x7C);
    M2C_FIELD(arg0, u16*, 0x42) = (u16)(M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF);
    M2C_FIELD(arg0, u16*, 0x7C) = (u16)(temp_v1 + 1);
    if ((s16)temp_v1 < 0x3C) {
        M2C_FIELD(arg0, u8*, 3) = (u8)(M2C_FIELD(arg0, u8*, 3) ^ 1);
        return;
    }
    M2C_FIELD(arg0, u8*, 3) = 0U;
    var_s0 = 3;
    do {
        func_80049EBC(arg0, 1, 0x10, 0x10);
        var_s0 -= 1;
    } while (var_s0 >= 0);
    func_8002CA14(arg0);
}

#define func_800EAA18 func_800EE2F4
#include "../shared/rock_05/func_800EAA18.c"
#undef func_800EAA18

#define func_800EAAA4 func_800EE380
#include "../shared/rock_05/func_800EAAA4.c"
#undef func_800EAAA4

#define func_800EAADC func_800EE3B8
#include "../shared/rock_05/func_800EAADC.c"
#undef func_800EAADC

// clang-format off
INCLUDE_ASM("asm/rock_08/nonmatchings/E9860", func_800EE404);
// clang-format on

#define func_800EE70C func_800EE544
#define g_Player g_Player
#include "../shared/commander_yammark/func_800EE70C.c"
#undef func_800EE70C
#undef g_Player

#define func_800EE800 func_800EE638
#define D_80097420 D_80097420
#include "common.h"
#include "mmx6/x4.h"

extern struct X4_PlayerObj g_Player;
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj g_playthrough_state;

#define FU16(p, o) (*(u16*)((u8*)(p) + (o)))

void func_800EE638(u8* arg0) {
    s32 a;
    s32 b;
    void* t;

    a = FU16(arg0, 0x80) + 1;
    b = FU16(arg0, 0x82) - 1;
    FU16(arg0, 0x80) = a;
    FU16(arg0, 0x82) = b;
    if (!(D_80097420.frame_counter & 1)) {
        g_Player.x_pos.i.hi = a;
    } else {
        g_Player.x_pos.i.hi = b;
    }
    if (D_80097420.transition.active == 0) {
        background_objects[0].unk44 = 1;
        background_objects[1].unk44 = 1;
        background_objects[2].unk44 = 1;
        g_Player.x_pos.i.hi = FU16(arg0, 0x84);
        t = *(void**)(arg0 + 0x88);
        g_playthrough_state.unk10 = 0;
        g_playthrough_state.unk11 = 0;
        g_playthrough_state.unk12 = 0;
        g_playthrough_state.unk13 = 0;
        g_playthrough_state.unk14 = 0;
        g_playthrough_state.unk15 = 0;
        g_playthrough_state.unk16 = 0;
        g_playthrough_state.unk17 = 0;
        g_playthrough_state.unk19 = 0;
        g_Player.terrain_box = t;
    }
}
#undef func_800EE800
#undef D_80097420

#define func_800EE8C4 func_800EE6FC
#define background_objects background_objects
#include "../shared/commander_yammark/func_800EE8C4.c"
#undef func_800EE8C4
#undef background_objects

// clang-format off
INCLUDE_ASM("asm/rock_08/nonmatchings/E9860", func_800EE7FC);

INCLUDE_ASM("asm/rock_08/nonmatchings/E9860", func_800EEBF0);
// clang-format on

#define func_800EA1D8 func_800EECFC
#define D_800FAA64 D_800F5B78
#include "../shared/d1000/func_800EA1D8.c"
#undef func_800EA1D8
#undef D_800FAA64

#define func_800EEF10 func_800EED48
#define D_800F7808 D_800F5B88
#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();
void func_8002CCB0(struct X4_BaseObj*, s32, s32);
extern void (*D_800F5B88[])(void*);

void func_800EED48(void* arg0) {
    M2C_FIELD(arg0, s32*, 0x18) = M2C_FIELD(arg0, s32*, 0x8);
    M2C_FIELD(arg0, s32*, 0x1C) = M2C_FIELD(arg0, s32*, 0xC);
    animate_object();
    D_800F5B88[M2C_FIELD(arg0, s8*, 5)](arg0);
    if ((u32)(M2C_FIELD(arg0, u8*, 2) - 3) >= 2U) {
        func_8002CCB0(arg0, 0x40, 0x40);
    }
}
#undef func_800EEF10
#undef D_800F7808

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CA14(); /* extern */
M2C_UNK func_8002CA54(); /* extern */

void func_800EEDC4(struct ObjectHeader* arg0) {
    if (arg0->state == 2) {
        ((M2C_UNK(*)())func_8002CA14)();
        return;
    }
    func_8002CA54();
}

#define func_800EEFCC func_800EEE04
#define g_Player g_Player
#include "../shared/commander_yammark/func_800EEFCC.c"
#undef func_800EEFCC
#undef g_Player

#include "common.h"
#include "mmx6/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s16 D_800970AA;

void func_800EEE7C(void* arg0) {
    if ((D_800CCEF6 == 0) && (D_800970AA >= M2C_FIELD(arg0, s16*, 0xA))) {
        M2C_FIELD(arg0, u16*, 0x84) = (u16)D_800970AA;
        M2C_FIELD(arg0, s16*, 0x7C) = 0x5A;
        M2C_FIELD(arg0, s8*, 5) = 3;
        M2C_FIELD(arg0, s8*, 6) = 0;
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s16 D_800970AA;

void func_800EEEC8(void* arg0) {
    if (D_800970AA >= M2C_FIELD(arg0, s16*, 0xA)) {
        M2C_FIELD(arg0, u16*, 0x84) = (u16)D_800970AA;
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, s8*, 5) = 3;
        M2C_FIELD(arg0, s8*, 6) = 0;
    }
}

#define func_8003744C func_800EEF04
#define D_80073C1C D_800F5BA0
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_8003744C func_800EEF40
#define D_80073C1C D_800F5C3C
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800EF144 func_800EEF7C
#include "common.h"
#include "mmx6/globals.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800139F4(M2C_UNK);
extern s16 D_800970AA;

void func_800EEF7C(void* arg0) {
    s32 temp_a0;
    s32 temp_a1;

    M2C_FIELD(arg0, u16*, 0x7C) = M2C_FIELD(arg0, u16*, 0x7C) + 1;
    temp_a1 = M2C_FIELD(arg0, u16*, 0x80) + 1;
    M2C_FIELD(arg0, u16*, 0x80) = temp_a1;
    temp_a0 = M2C_FIELD(arg0, u16*, 0x82) - 1;
    M2C_FIELD(arg0, u16*, 0x82) = temp_a0;
    if (!(D_80097420.frame_counter & 1)) {
        D_800970AA = temp_a1;
    } else {
        D_800970AA = temp_a0;
    }
    if (M2C_FIELD(arg0, s16*, 0x7C) >= 0x1D) {
        func_800139F4(8);
        D_800CCEDF = M2C_FIELD(arg0, u8*, 2) | 0x40;
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    }
}
#undef func_800EF144

#define func_800EF1E8 func_800EF020
#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800139F4(M2C_UNK);
extern s16 D_800970AA;

void func_800EF020(void* arg0) {
    s32 temp_a0;
    s32 temp_a1;

    M2C_FIELD(arg0, u16*, 0x7C) = M2C_FIELD(arg0, u16*, 0x7C) + 1;
    temp_a1 = M2C_FIELD(arg0, u16*, 0x80) + 1;
    M2C_FIELD(arg0, u16*, 0x80) = temp_a1;
    temp_a0 = M2C_FIELD(arg0, u16*, 0x82) - 1;
    M2C_FIELD(arg0, u16*, 0x82) = temp_a0;
    if (!(D_80097420.frame_counter & 1)) {
        D_800970AA = temp_a1;
    } else {
        D_800970AA = temp_a0;
    }
    if (M2C_FIELD(arg0, s16*, 0x7C) >= 0x1D) {
        func_800139F4(8);
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    }
}
#undef func_800EF1E8

#define func_800EF27C func_800EF0B4
#define D_80097420 D_80097420
#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#include "mmx6/x4.h"

extern s16 D_800970AA;

void func_800EF0B4(void* arg0) {
    s32 temp_a1;
    s32 temp_a2;

    temp_a2 = M2C_FIELD(arg0, u16*, 0x80) - 1;
    temp_a1 = M2C_FIELD(arg0, u16*, 0x82) + 1;
    M2C_FIELD(arg0, u16*, 0x80) = temp_a2;
    M2C_FIELD(arg0, u16*, 0x82) = temp_a1;
    if (!(D_80097420.frame_counter & 1)) {
        D_800970AA = temp_a2;
    } else {
        D_800970AA = temp_a1;
    }
    if (D_80097420.transition.active == 0) {
        M2C_FIELD(arg0, u16*, 0x7C) = 0;
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    }
}
#undef func_800EF27C
#undef D_80097420

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EF11C(void) {
    clear_object_slot();
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32**)0x1F800020)

s32 set_animation(void*, s32);
s32 func_8002A47C(s32);
M2C_UNK clear_object_slot();
s32 random_byte();

extern u32* D_80095098;
extern s32 D_800F5CBC;
extern s32 D_800F5D28;

void func_800EF13C(struct X4_PlayerObj* self) {
    s32 a;
    s32 b;

    if (!(random_byte() & 1)) {
        clear_object_slot(self);
        return;
    }
    if (self->character == 0) {
        self->character = (u32)random_byte() % 3;
    }
    self->action = 2;
    self->active = 0x41;
    self->state++;
    self->bg_offset = D_800970B4;
    self->unk40 = D_80095098[func_8002A47C(0x85)] >> 7;
    self->unk3C = (u8*)SPAD20 + SPAD20[func_8002A47C(0x85)];
    a = func_8002A47C(0x85);
    b = func_8002A47C(0x85);
    self->unk42 = ((a * 4 + 0x20) % 16) | (((b + 8) / 4 + 0x1E0) << 6);
    self->unk16 = 0x21;
    self->terrain_box = (struct X4_Unk_unk68*)&D_800F5D28;
    self->invincibility_timer = 0;
    self->unk58 = &D_800743DC;
    self->hp = 8;
    self->facing = 0;
    self->unk65 = 0;
    self->unk54 = 0;
    self->unk50 = 0;
    self->unk60 = 2;
    self->animation_table = (u32**)&D_800F5CBC;
    M2C_FIELD(self, u8*, 0x88) = 0;
    M2C_FIELD(self, u8*, 0x89) = 0;
    self->x_vel.val = 0;
    self->x_accel = 0;
    self->y_vel.val = 0;
    self->gravity = 0;
    self->action_phase = 0;
    if (self->character == 0) {
        set_animation(self, 0);
    } else if (self->character == 1) {
        set_animation(self, 1);
    } else if (self->character == 2) {
        set_animation(self, 0);
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define FLD(p, type, off) (*(type*)((u8*)(p) + (off)))

M2C_UNK animate_object();
M2C_UNK func_8002CA54();
s32 is_off_screen(void*, M2C_UNK, M2C_UNK);
void func_8002CCB0(struct X4_BaseObj*, s32, s32);
s32 random_byte();
M2C_UNK func_8002F288(M2C_UNK*);
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
M2C_UNK func_80049E50(void*);
void func_8004E654(struct X4_BaseObj* arg0, s8 arg1);
extern M2C_UNK D_800F5D38;
extern M2C_UNK D_800F5D3C;
extern M2C_UNK D_800F5D40;
extern M2C_UNK D_800F5D44;
extern void (*D_800F5D54[])(void*);

void func_800EF340(void* arg0) {
    s8 old;

    old = FLD(arg0, s8, 0x5C);
    if (check_enemy_hits(arg0) < 0) {
        s8 t = FLD(arg0, s8, 0x2);
        if (t == 1) {
            if (random_byte() & 1) {
                func_800477E4(2, &D_800F5D40, arg0);
            } else {
                func_800477E4(2, &D_800F5D44, arg0);
            }
            func_80049E50(arg0);
        } else if (t == 2 || t == 0) {
            if (random_byte() & 1) {
                func_800477E4(2, &D_800F5D38, arg0);
            } else {
                func_800477E4(2, &D_800F5D3C, arg0);
            }
            func_80049E50(arg0);
        }
        func_8004E654(arg0, 0x12);
        t = 2;
        FLD(arg0, s8, 0x4) = t;
        return;
    }
    func_80030ECC(arg0);
    if (FLD(arg0, s8, 0x5C) != old) {
        FLD(arg0, u16, 0x42) |= 0x8000;
    }
    D_800F5D54[FLD(arg0, s8, 0x6)](arg0);
    animate_object(arg0);
    if (is_off_screen(arg0, 0x30, 0x30) == 0) {
        if (FLD(arg0, s8, 0x6) == 0) {
            FLD(arg0, u8, 0x3) ^= 1;
        } else {
            func_8002CCB0(arg0, 0x30, 0x30);
        }
    } else {
        func_8002CA54(arg0);
    }
    if (FLD(arg0, u8, 0x70) & 8) {
        FLD(arg0, s8, 0x67) = 0;
    } else {
        s32 d = FLD(arg0, s32, 0x24);
        if (d < 0) {
            d = -1;
        } else {
            d = 1;
        }
        FLD(arg0, s8, 0x67) = d;
    }
    func_8002F288(arg0);
}

// clang-format off
INCLUDE_ASM("asm/rock_08/nonmatchings/E9860", func_800EF534);
// clang-format on

#define func_80048DC8 func_800EF6B8
#define D_80077BC0 D_800F5D48
#include "../shared/d1000/func_80048DC8.c"
#undef func_80048DC8
#undef D_80077BC0

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK func_8002CA14(void*);                /* extern */

void func_800EF704(struct ObjectHeader* arg0) {
    play_sound(2, 0x54, arg0);
    arg0->on_screen = 0;
    func_8002CA14(arg0);
}

#include "common.h"

extern s32 D_800F5D08;
extern s32 D_800F5D18;

void func_800EF740(u8* arg0) {
    s8 t;
    s8 v;

    if ((u8)++arg0[0x88] >= 0x3D) {
        *(s32**)(arg0 + 0x54) = &D_800F5D08;
        *(s32**)(arg0 + 0x50) = &D_800F5D18;
        t = arg0[2];
        arg0[0x88] = 0;
        if (t == 0) {
            v = 1;
        common: {
            // !FAKE: depin: dropping it breaks the match (26/29)
            register s32 k asm("$3") = 0x2000;
            arg0[6] = v;
            *(s32*)(arg0 + 0x2C) = k;
        }
            return;
        }
        if (t == 1) {
            v = 2;
            // !FAKE: goto shares the common block holding the pinned constant; duplicating it needs a second pin
            goto common;
        }
        arg0[6] = 4;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK apply_object_motion(s32);
s32 random_byte();
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
M2C_UNK func_80049E50(void*);

extern M2C_UNK D_800F5D38;
extern M2C_UNK D_800F5D3C;

void func_800EF7B4(struct X4_MainObj* self) {
    apply_object_motion(self);
    {
        // !FAKE: depin: dropping it breaks the match (39/42)
        register s32 y asm("$2") = self->y_speed;
        s32 k = -0x20000;
        if (y < k) {
            self->y_speed = k;
        }
    }
    if (self->collision_flags & 8) {
        play_sound(2, 0x52, self);
        func_80049E50(self);
        if (random_byte() & 1) {
            func_800477E4(2, &D_800F5D38, self);
        } else {
            func_800477E4(2, &D_800F5D3C, self);
        }
        self->state = 2;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK apply_object_motion(s32);
s32 random_byte();
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
M2C_UNK func_80049E50(void*);

extern M2C_UNK D_800F5D40;
extern M2C_UNK D_800F5D44;

void func_800EF85C(struct X4_MainObj* self) {
    apply_object_motion(self);
    if (!(D_80097420.frame_counter & 0x1F)) {
        play_sound(2, 0x53, self);
    }
    if (!(self->collision_flags & 8)) {
        self->action_phase = 2;
        self->y_speed = 0;
        self->gravity = 0x2000;
    } else {
        self->y_speed = 0;
        self->gravity = 0;
    }
    if ((self->collision_flags & 1) || (self->collision_flags & 2)) {
        if (++*(s16*)&self->ext >= 0x3C) {
            func_80049E50(self);
            if (random_byte() & 1) {
                func_800477E4(2, &D_800F5D40, self);
            } else {
                func_800477E4(2, &D_800F5D44, self);
            }
            self->state = 2;
        }
    }
}

#include "../shared/rock_08/func_800EF960.c"

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK apply_object_motion(s32);
s32 random_byte();
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
M2C_UNK func_80049E50(void*);

extern M2C_UNK D_800F5D38;
extern M2C_UNK D_800F5D3C;

void func_800EFA10(void* self) {
    ((void (*)(s32))apply_object_motion)((s32)self);
    if (M2C_FIELD(self, u8*, 0x70) != 0) {
        func_80049E50(self);
        if (random_byte() & 1) {
            func_800477E4(2, &D_800F5D38, self);
        } else {
            func_800477E4(2, &D_800F5D3C, self);
        }
        M2C_FIELD(self, u8*, 0x4) = 2;
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_08/nonmatchings/E9860", func_800EFA90);

INCLUDE_ASM("asm/rock_08/nonmatchings/E9860", func_800EFC60);
// clang-format on

#define func_80048DC8 func_800EFD04
#define D_80077BC0 D_800F5D84
#include "../shared/d1000/func_80048DC8.c"
#undef func_80048DC8
#undef D_80077BC0

#define func_80041AB8 func_800EFD50
#define D_80075FD8 D_800F5D90
#define FAMILY_FIELD 5
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EFD8C(void) {
    clear_object_slot();
}

// clang-format off
INCLUDE_ASM("asm/rock_08/nonmatchings/E9860", func_800EFDAC);
// clang-format on

#define func_800EF6D4 func_800EFE60
#define background_objects background_objects
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();
s32 is_off_screen(void*, M2C_UNK, M2C_UNK);
void func_8002CCB0(struct X4_BaseObj*, s32, s32);
M2C_UNK move_object(void*);
extern struct X4_BackgroundObj background_objects[3];

void func_800EFE60(void* arg0) {
    animate_object();
    ((void (*)(s32))move_object)((s32)arg0);
    if (M2C_FIELD(arg0, s16*, 0xA) >= background_objects[0].x_pos.i.hi - 0x10 &&
        background_objects[0].y_pos.i.hi + 0x100 >=
            M2C_FIELD(arg0, s16*, 0xE) &&
        is_off_screen(arg0, 0x150, 0x30) == 0) {
        func_8002CCB0(arg0, 0x20, 0x20);
        return;
    }
    M2C_FIELD(arg0, s8*, 4) = 2;
}
#undef func_800EF6D4
#undef background_objects

#include "../shared/commander_yammark/func_800EFEF8.c"

// clang-format off
INCLUDE_ASM("asm/rock_08/nonmatchings/E9860", func_800EFF9C);
// clang-format on

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"
#include "mmx6/rock_08.h"

#define FLD(p, type, off) (*(type*)((u8*)(p) + (off)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
void func_8002CCB0(struct X4_BaseObj*, s32, s32);
s32 random_byte();
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
extern M2C_UNK D_8007433C;
extern void (*D_800F5F40[])(void*);
extern s32 D_800F6AF4;

void func_800F0200(void* arg0) {
    s32 r;
    s8 v;

    FLD(arg0, s32, 0x18) = FLD(arg0, s32, 0x8);
    FLD(arg0, s32, 0x1C) = FLD(arg0, s32, 0xC);
    FLD(arg0, s16, 0x82) = FLD(arg0, s8, 0x5C);
    if (D_800CCF38 >= 2) {
        v = FLD(arg0, s8, 0x87);
        if (v < 3) {
            FLD(arg0, s8, 0x88) = 1;
        } else if (v < 5) {
            FLD(arg0, s8, 0x88) = 2;
        } else if (v < 6) {
            FLD(arg0, s8, 0x88) = 3;
        } else {
            FLD(arg0, s8, 0x88) = 4;
        }
    } else {
        v = FLD(arg0, s8, 0x87);
        if (v < 4) {
            FLD(arg0, s8, 0x88) = 1;
        } else if (v < 7) {
            FLD(arg0, s8, 0x88) = 2;
        } else if (v < 9) {
            FLD(arg0, s8, 0x88) = 3;
        } else {
            FLD(arg0, s8, 0x88) = 4;
        }
    }
    v = FLD(arg0, s8, 0x5);
    if (v == 4 || v == 2 || (v == 11 && FLD(arg0, s8, 0x6) < 2)) {
        if (D_800F6AF0 == 0) {
            if (FLD(arg0, s8, 0x8B) == 1) {
                play_sound(2, 0x23, arg0);
                D_800F6AF0 = (random_byte() & 3) + 0x32;
            } else {
                switch (FLD(arg0, s8, 0x9A)) {
                case 1:
                    play_sound(2, 0x22, arg0);
                    D_800F6AF0 = (random_byte() & 3) | 0x28;
                    break;
                case 2:
                    play_sound(2, 0x23, arg0);
                    D_800F6AF0 = (random_byte() & 3) + 0x32;
                    break;
                case 3:
                    play_sound(2, 0x24, arg0);
                    D_800F6AF0 = (random_byte() & 3) + 0x5A;
                    break;
                case 4:
                    play_sound(2, 0x25, arg0);
                    D_800F6AF0 = (random_byte() & 3) | 0x64;
                    break;
                }
            }
        } else {
            D_800F6AF0--;
        }
        if ((s16)(D_800F6AF2 % 60) == 0) {
            play_sound(2, 0x34, arg0);
        }
        D_800F6AF2++;
    } else {
        D_800F6AF2 = 0;
    }
    if (FLD(arg0, s16, 0x80) == 0) {
        FLD(arg0, s8, 0x7A) = 0;
        func_80030ECC(arg0);
    }
    r = check_enemy_hits(arg0);
    if (r < 0) {
        play_sound(2, 0x20, arg0);
        D_8009711A = 1;
        FLD(arg0, s8, 0x4) = 2;
        FLD(arg0, s8, 0x5) = 0;
        return;
    }
    if (FLD(arg0, s16, 0x80) == 0) {
        if (r != 0 && r != 0x7F) {
            FLD(arg0, void*, 0x58) = &D_8007433C;
            FLD(arg0, u16, 0x42) |= 0x8000;
            if ((u32)(r - 0x19) < 2U) {
                FLD(arg0, s16, 0x80) = 2;
            } else {
                FLD(arg0, s16, 0x80) = 0x1E;
            }
            if (r == 2 || r == 0xB || r == 0x37) {
                v = FLD(arg0, s8, 0x5);
                if (v == 2 || v == 4 || v == 6) {
                    play_sound(2, 0x21, arg0);
                    FLD(arg0, s16, 0x80) = 0xB4;
                    FLD(arg0, s8, 0x5) = 0xA;
                    FLD(arg0, s8, 0x6) = 0;
                } else {
                    FLD(arg0, s16, 0x80) = 0x3C;
                }
            }
        }
    } else {
        if (--FLD(arg0, s16, 0x80) == 0) {
            FLD(arg0, void*, 0x58) = &D_80074C9C;
            FLD(arg0, u16, 0x42) &= 0x7FFF;
        } else if (!(FLD(arg0, s16, 0x80) & 1)) {
            FLD(arg0, u16, 0x42) |= 0x8000;
        } else {
            FLD(arg0, u16, 0x42) &= 0x7FFF;
        }
    }
    D_800F5F40[FLD(arg0, s8, 0x5)](arg0);
    if (FLD(arg0, s8, 0x5) != 9) {
        D_800F6AF4++;
    }
    func_8002CCB0(arg0, 0x60, 0x60);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define FLD(p, type, off) (*(type*)((u8*)(p) + (off)))

void* enemy_slot_alloc();
M2C_UNK clear_object_slot();
void func_8002CCB0(struct X4_BaseObj*, s32, s32);
extern struct X4_EngineObj g_playthrough_state;
extern s32 D_800F6AF4;

void func_800F063C(void* arg0) {
    s8* p;
    s8* t;

    t = FLD(arg0, s8*, 0x8C);
    FLD(arg0, s8, 0x3) = 0;
    if (t[0] != 0) {
        if (t[7] == 0) {
            if (--FLD(arg0, s16, 0x7E) == -1) {
                FLD(arg0, s16, 0x7E) = 5;
                FLD(arg0, u16, 0x42) ^= 0x8000;
            }
            func_8002CCB0(arg0, 0x60, 0x60);
        }
    } else {
        FLD(arg0, s32, 0x80) = 0;
        FLD(arg0, s32, 0x84) = 0;
        FLD(arg0, s32, 0x88) = 0;
        FLD(arg0, s32, 0x8C) = 0;
        FLD(arg0, s32, 0x90) = 0;
        FLD(arg0, s32, 0x94) = 0;
        g_playthrough_state.enable_boss = 0;
        g_playthrough_state.boss_ptr = 0;
        if (g_playthrough_state.stage != 0xC) {
            if ((u32)D_800F6AF4 < 0x1519) {
                p = enemy_slot_alloc();
                if (p != 0) {
                    p[0] = 0x41;
                    p[1] = 0xF;
                    p[2] = 0x10;
                }
            } else {
                p = enemy_slot_alloc();
                if (p != 0) {
                    p[0] = 0x41;
                    p[1] = 0xF;
                    p[2] = 0x11;
                }
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

#include "../shared/rock_08/func_800F0794.c"

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/rock_08.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
s32 set_animation(void*, s32);
M2C_UNK animate_object();
M2C_UNK open_text_box(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK move_object(void*);
s32 random_byte();
extern struct X4_EngineObj g_playthrough_state;

void func_800F09B4(void* arg0) {
    struct X4_EngineObj* e;
    u8 t;

    if (D_800F6AF0 == 0) {
        play_sound(2, 0x34, arg0);
        play_sound(2, 0x22, arg0);
        D_800F6AF0 = (random_byte() & 3) | 0x28;
    } else {
        D_800F6AF0 = D_800F6AF0 - 1;
    }
    animate_object(arg0);
    ((void (*)(void*))move_object)(arg0);
    if (M2C_FIELD(arg0, s16*, 0xA) < D_800F6AF8 + 0x760) {
        t = M2C_FIELD(arg0, u8*, 0x47);
        if (t == 4) {
            return;
        }
        if (t != 5) {
            e = &g_playthrough_state;
            if (M2C_FIELD(e, s8*, 0xC) != 0xC) {
                ((void (*)(s32, s32, s32))open_text_box)(
                    0, 0xFF, M2C_FIELD(e, u8*, 0x2E));
                M2C_FIELD(e, u8*, 0x2E) = 1;
            }
            ((void (*)(void*, s32))set_animation)(arg0, 0);
            M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
        }
    }
}

#include "common.h"
#include "mmx6/globals.h"
#include "mmx6/rock_08.h"
#define M2C_UNK s32

#define OUB(p, o) (*(u8*)((u8*)(p) + (o)))
#define OH(p, o) (*(s16*)((u8*)(p) + (o)))
#define OW(p, o) (*(s32*)((u8*)(p) + (o)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
s32 set_animation(void*, s32);
M2C_UNK animate_object();
M2C_UNK move_object(void*);
s32 random_byte();

void func_800F0AB0(void* self) {
    u8 v;
    // !FAKE: depin: dropping it breaks the match (68/73)
    register s32 t asm("$2");

    animate_object();
    move_object((s32)self);
    t = OW(self, 0x20);
    if (t > 0) {
        if (D_800F6AF8 + 0x680 < OH(self, 0xA)) {
            v = OUB(self, 0x47);
            if (v != 4) {
                if (v != 5) {
                    OUB(self, 0x89) = D_800CCF5F + 1;
                    if (!(random_byte() & 1)) {
                        play_sound(2, 0x27, self);
                    } else {
                        play_sound(2, 0x28, self);
                    }
                    set_animation(self, 3);
                    t = OUB(self, 6) + 1;
                    OUB(self, 6) = t;
                }
            }
        }
    } else {
        if (OH(self, 0xA) < D_800F6AF8 + 0x780) {
            v = OUB(self, 0x47);
            if (v != 4) {
                if (v != 5) {
                    OUB(self, 0x89) = D_800CCF5F + 1;
                    if (!(random_byte() & 1)) {
                        play_sound(2, 0x27, self);
                    } else {
                        play_sound(2, 0x28, self);
                    }
                    set_animation(self, 3);
                    t = OUB(self, 6) + 1;
                    OUB(self, 6) = t;
                }
            }
        }
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_08/nonmatchings/E9860", func_800F0BD4);
// clang-format on

#include "common.h"
#define M2C_UNK s32

#define FLD(p, type, off) (*(type*)((u8*)(p) + (off)))

M2C_UNK animate_object();
s32 random_byte();
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
extern u8 D_800F6288[];

void func_800F12D4(void* arg0) {
    void* parent;
    s8 t;
    s32 r;

    parent = FLD(arg0, void*, 0x7C);
    FLD(arg0, s32, 0x8C) = check_enemy_hits(arg0);
    if (FLD(arg0, s32, 0x8C) < 0) {
        FLD(arg0, u8, 0x5) = 2;
        FLD(arg0, s16, 0x90) = 0x3C;
        FLD(parent, u8, 0x7) = 1;
        return;
    }
    func_80030ECC(arg0);
    if (FLD(parent, s8, 0x5) != 8) {
        if (FLD(parent, u8, 0x15) != 0) {
            FLD(arg0, s16, 0xA) =
                FLD(parent, s16, 0xA) + (s8)D_800F6288[FLD(arg0, s8, 0x2) * 4];
        } else {
            FLD(arg0, s16, 0xA) =
                FLD(parent, s16, 0xA) - (s8)D_800F6288[FLD(arg0, s8, 0x2) * 4];
        }
    }
    if (FLD(parent, s8, 0x5) != 0xA && FLD(parent, s8, 0x4) != 2) {
        {
            u8* p = D_800F6288;
            p -= -(FLD(arg0, s8, 0x2) * 4);
            FLD(arg0, s16, 0xE) = FLD(parent, s16, 0xE) - (s8)p[3];
        }
    }
    FLD(arg0, u8, 0x15) = FLD(parent, u8, 0x15);
    if (FLD(parent, s8, 0x5) == 3) {
        FLD(arg0, u8, 0x4) = 2;
        return;
    }
    t = FLD(parent, s8, 0x45);
    if (t == 1) {
        animate_object(arg0);
    } else if (t == 2) {
        r = random_byte();
        FLD(arg0, u8, 0x6) = 0;
        FLD(arg0, u8, 0x5) = (u32)r % 3 + 3;
    }
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
M2C_UNK func_80049EBC(void*, M2C_UNK, M2C_UNK, M2C_UNK);
extern M2C_UNK D_800F629C;
extern M2C_UNK D_800F62A4;

void func_800F1470(void* arg0) {
    s32 i;
    s32 t;

    if (!(M2C_FIELD(arg0, u8*, 0x90) & 7)) {
        M2C_FIELD(arg0, u16*, 0x42) |= 0x8000;
    }
    if (!(M2C_FIELD(arg0, u8*, 0x90) & 0xF)) {
        t = M2C_FIELD(arg0, s8*, 2) * 16;
        func_80049EBC(arg0, 1, t, t);
    }
    if (M2C_FIELD(arg0, s16*, 0x90)++ >= 0x79) {
        if (M2C_FIELD(arg0, u8*, 0x96) == 0) {
            for (i = 0; i < M2C_FIELD(arg0, s8*, 2); i++) {
                func_800477E4(6, &D_800F629C, arg0);
            }
        } else {
            for (i = 0; i < M2C_FIELD(arg0, s8*, 2); i++) {
                func_800477E4(6, &D_800F62A4, arg0);
            }
        }
        for (i = 0; i < M2C_FIELD(arg0, s8*, 2) * 4; i++) {
            func_80049EBC(arg0, 1, (s8)M2C_FIELD(arg0, u8*, 2) * 16,
                          (s8)M2C_FIELD(arg0, u8*, 2) * 16);
        }
        M2C_FIELD(arg0, u8*, 4) = 2;
    }
}

#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
extern s16 D_800970AA;
extern s16 D_800F6AFA;

void func_800F15E8(void* arg0) {
    s32 angle;
    s32 t;

    switch (M2C_FIELD(arg0, s8*, 0x2)) {
    case 1: {
        s32 x = D_800F6AFA;
        s32 e = M2C_FIELD(arg0, s16*, 0xE) - 0x52B;
        angle = ratan2(x - e, D_800970AA - M2C_FIELD(arg0, s16*, 0xA));
    } break;
    case 2: {
        s32 x = D_800F6AFA;
        s32 e = M2C_FIELD(arg0, s16*, 0xE) - 0x51B;
        angle = ratan2(x - e, D_800970AA - M2C_FIELD(arg0, s16*, 0xA));
    } break;
    case 3: {
        s32 x = D_800F6AFA;
        s32 e = M2C_FIELD(arg0, s16*, 0xE) - 0x50B;
        angle = ratan2(x - e, D_800970AA - M2C_FIELD(arg0, s16*, 0xA));
    } break;
    case 4: {
        s32 x = D_800F6AFA;
        s32 e = M2C_FIELD(arg0, s16*, 0xE) - 0x4FB;
        angle = ratan2(x - e, D_800970AA - M2C_FIELD(arg0, s16*, 0xA));
    } break;
    }
    t = rcos(angle) * 16;
    M2C_FIELD(arg0, s32*, 0x20) = t * 3;
    t = -rsin(angle) * 16;
    M2C_FIELD(arg0, s32*, 0x24) = t * 3;
    play_sound(2, 0x35, arg0);
    M2C_FIELD(arg0, u8*, 0x6) += 1;
}

#include "common.h"
#include "mmx6/rock_08.h"
#define M2C_UNK s32

#define FLD(p, type, off) (*(type*)((u8*)(p) + (off)))

M2C_UNK animate_object();
M2C_UNK move_object(void*);
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
extern s16 D_800F6AFA;

void func_800F1728(void* arg0) {
    void* parent;
    s32 r;
    s16 x;
    s16 y;
    s32 a, b, c, d;
    s16 dx;
    s16 dy;

    parent = FLD(arg0, void*, 0x7C);
    animate_object();
    move_object(arg0);
    FLD(arg0, s32, 0x8C) = check_enemy_hits(arg0);
    if (FLD(arg0, s32, 0x8C) < 0) {
        FLD(arg0, u8, 0x5) = 2;
        FLD(arg0, s16, 0x90) = 0x1E;
        FLD(parent, u8, 0x7) = 2;
        return;
    }
    func_80030ECC(arg0);
    x = FLD(arg0, s16, 0xA);
    dx = D_800F6AF8;
    r = FLD(arg0, s8, 0x2) * 16;
    if ((a = r + 0x7E0, dx + a < x) || (b = r - 0x620, x < dx - b) ||
        (dy = D_800F6AFA, c = r + 0x580, dy + c < (y = FLD(arg0, s16, 0xE))) ||
        (d = r - 0x450, y < dy - d)) {
        FLD(parent, u8, 0x7) = 2;
        FLD(arg0, u8, 0x4) = 2;
    }
}

#include "common.h"
#include "mmx6/rock_08.h"
#define M2C_UNK s32

#define FLD(p, type, off) (*(type*)((u8*)(p) + (off)))

M2C_UNK start_pad_vibration(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK animate_object();
M2C_UNK apply_object_motion(s32);
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
extern s16 D_800F6AFA;

void func_800F180C(void* arg0) {
    void* parent;
    s32 r;
    s16 x;
    s16 y;
    s32 a, b, c, d;
    s16 dx;
    s16 dy;
    // !FAKE: depin: dropping it breaks the match (104/108)
    register s32 v asm("$2");

    parent = FLD(arg0, void*, 0x7C);
    animate_object();
    apply_object_motion(arg0);
    FLD(arg0, s32, 0x8C) = check_enemy_hits(arg0);
    if (FLD(arg0, s16, 0xE) > FLD(arg0, s16, 0x92)) {
        play_sound(2, 0x36, parent);
        start_pad_vibration(5);
        v = FLD(arg0, u16, 0x92);
        FLD(arg0, s32, 0x20) = 0x30000;
        FLD(arg0, s32, 0x24) = 0;
        FLD(arg0, s32, 0x2C) = 0;
        FLD(arg0, s16, 0xE) = v;
        if (FLD(arg0, u8, 0x15) == 0) {
            FLD(arg0, s32, 0x20) = 0xFFFD0000;
        }
    }
    if (FLD(arg0, s16, 0xE) == FLD(arg0, s16, 0x92)) {
        D_800F6AF2++;
        if ((s16)(D_800F6AF2 % 60) == 0) {
            play_sound(2, 0x34, arg0);
        }
    }
    if (FLD(arg0, s32, 0x8C) < 0) {
        FLD(arg0, u8, 0x5) = 2;
        FLD(arg0, s16, 0x90) = 0x1E;
        FLD(parent, u8, 0x7) = 2;
        return;
    }
    func_80030ECC(arg0);
    x = FLD(arg0, s16, 0xA);
    dx = D_800F6AF8;
    r = FLD(arg0, s8, 0x2) * 16;
    if ((a = r + 0x7E0, dx + a < x) || (b = r - 0x620, x < dx - b) ||
        (dy = D_800F6AFA, c = r + 0x580, dy + c < (y = FLD(arg0, s16, 0xE))) ||
        (d = r - 0x450, y < dy - d)) {
        FLD(parent, u8, 0x7) = 2;
        FLD(arg0, u8, 0x4) = 2;
    }
}

#include "common.h"
#include "mmx6/rock_08.h"
#define M2C_UNK s32

#define FLD(p, type, off) (*(type*)((u8*)(p) + (off)))

M2C_UNK start_pad_vibration(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK animate_object();
M2C_UNK apply_object_motion(s32);
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
extern s16 D_800F6AFA;

void func_800F19BC(void* arg0) {
    void* parent;
    s32 r;
    s16 x;
    s16 y;
    s32 a, b, c, d;
    s16 dx;
    s16 dy;
    // !FAKE: depin: dropping it breaks the match (69/76)
    register s32 v asm("$3");
    // !FAKE: depin: dropping it breaks the match (72/76)
    register s32 k asm("$2");

    parent = FLD(arg0, void*, 0x7C);
    animate_object();
    apply_object_motion(arg0);
    if (FLD(arg0, s16, 0xE) > FLD(arg0, s16, 0x92)) {
        play_sound(2, 0x36, parent);
        start_pad_vibration(5);
        k = 0x38000;
        v = FLD(arg0, u16, 0x92);
        FLD(arg0, s32, 0x24) = k;
        FLD(arg0, s32, 0x2C) = 0x1C00;
        FLD(arg0, s16, 0xE) = v - 1;
    }
    if ((FLD(arg0, s32, 0x8C) = check_enemy_hits(arg0)) < 0) {
        FLD(arg0, u8, 0x5) = 2;
        FLD(arg0, s16, 0x90) = 0x3C;
        FLD(parent, u8, 0x7) = 2;
        return;
    }
    func_80030ECC(arg0);
    x = FLD(arg0, s16, 0xA);
    dx = D_800F6AF8;
    r = FLD(arg0, s8, 0x2) * 16;
    if ((a = r + 0x7E0, dx + a < x) || (b = r - 0x620, x < dx - b) ||
        (dy = D_800F6AFA, c = r + 0x580, dy + c < (y = FLD(arg0, s16, 0xE))) ||
        (d = r - 0x450, y < dy - d)) {
        FLD(parent, u8, 0x7) = 2;
        FLD(arg0, u8, 0x4) = 2;
    }
}

#include "../shared/rock_08/func_800F1AEC.c"
