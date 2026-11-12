#define func_80041AB8 func_800E9E4C
#define D_80075FD8 D_800FB350
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

extern struct X4_BackgroundObj background_objects[3];

void func_800E9E88(struct X4_AnimatedObj* arg0) {
    if (D_800CCEED != 0) {
        background_objects[1].unk42 = 0x140;
        background_objects[1].unk4C = 1;
        background_objects[2].unk4 = 5;
        background_objects[2].x_pos.i.hi = background_objects[1].x_pos.i.hi / 4;
        background_objects[2].y_pos.i.hi = 0x1C0;
        background_objects[2].unk4C = 1;
        arg0->state++;
    }
}

#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj background_objects[3];

void func_800E9EF0(void) {
    background_objects[2].x_pos.i.hi = background_objects[1].x_pos.i.hi / 4;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);
extern u32* D_80095098;
extern u8 D_800FA900[];

#define SCRATCH_20 (*(u8**)0x1F800020)

void func_800E9F18(void* arg0) {
    struct X4_VisualObj* obj = arg0;
    u8* tbl;
    s32 a;
    s8 t;

    obj->state = 1;
    obj->unk6 = 0;
    obj->bg_offset = 0;
    obj->animation_table = (u32**)(D_800FA900 + 0xAFC);
    obj->unk40 = D_80095098[func_8002A47C(0x8B)] >> 7;
    obj->unk42 = (func_8002A47C(0x8B) * 4 + 0x20) % 16 |
                 ((func_8002A47C(0x8B) + 8) / 4 + 0x1E0) << 6;
    a = func_8002A47C(0x8B);
    tbl = SCRATCH_20;
    obj->unk3C = tbl + *(s32*)(tbl + a * 4);
    t = obj->unk2;
    if (t == 5) {
        obj->unk16 = t;
    } else {
        obj->unk16 = 0x11;
    }
    set_animation(obj, obj->unk2);
}

#define func_80041AB8 func_800EA02C
#define D_80075FD8 D_800FB41C
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

/* Adapted from sozud/mmx4 @4e16dfc src/main/misc/misc_00_static_sprite.c:spawn_common_effect, AGPL-3.0; proven shared with X6 by exact signature 1d1542c14e9b (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
struct X4_MiscObj* alloc_sprite_slot(void);

void func_800EA068(struct X4_MainObj* self, s8 arg1) {
    struct X4_MiscObj* misc;

    misc = alloc_sprite_slot();
    if (misc != NULL) {
        misc->active = 0x41;
        misc->id = 1;
        misc->unk2 = arg1;
        misc->unk15 = self->unk15;
        misc->x_pos = self->x_pos;
        misc->y_pos = self->y_pos;
    }
}

/* Adapted from sozud/mmx4 @4e16dfc src/main/misc/misc_01_common_effect.c:common_effect_animate, AGPL-3.0; proven shared with X6 by exact signature ed471c96b830 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32
M2C_UNK animate_object();
#define animate_object ((void (*)(struct X4_AnimatedObj*))animate_object)
void func_8002CB50(struct X4_BaseObj*);

void func_800EA0DC(struct X4_MiscObj* self) {
    animate_object(ANIMATED_OBJECT(self));
    if (self->animation_step.fields.event != 0) {
        self->state = 2;
    }
    func_8002CB50(BASE_OBJECT(self));
}
#undef animate_object

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EA11C(void) {
    clear_object_slot();
}

// clang-format off
INCLUDE_ASM("asm/rock_10/nonmatchings/E9860", func_800EA13C);

INCLUDE_ASM("asm/rock_10/nonmatchings/E9860", func_800EA4CC);
// clang-format on

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

M2C_UNK animate_object();
s32 func_80027BA0(s32 arg0, s32 arg1, s32 arg2, u8* arg3);
extern s16 D_80097220;
extern u8 D_800FA900[];

void func_800EA650(struct X4_AnimatedObj* self) {
    ((void (*)(struct X4_AnimatedObj*))animate_object)(self);
    if (self->animation_step.fields.event != 1) {
        return;
    }
    switch (self->unk2 & 0xF) {
    case 0:
        D_8009721C = 0xDA0;
        func_80027BA0(0, 0xC40, 0x150, D_800FA900 + 0x1590);
        break;
    case 1:
        D_8009721C = 0xEF0;
        func_80027BA0(0, 0xED0, 0x180, D_800FA900 + 0x1598);
        break;
    case 2:
        D_8009721C = 0x1180;
        func_80027BA0(0, 0x1020, 0x150, D_800FA900 + 0x15A0);
        break;
    case 3:
        D_8009721C = 0x12E0;
        func_80027BA0(0, 0x12B0, 0x160, D_800FA900 + 0x15A8);
        break;
    case 4:
        D_80097220 = 0x200;
        func_80027BA0(0, 0x1250, 0x1C0, D_800FA900 + 0x15B0);
        break;
    case 5:
        D_80097220 = 0x300;
        func_80027BA0(0, 0xF30, 0x2C0, D_800FA900 + 0x15B8);
        break;
    }
    self->action_phase++;
}

#include "common.h"
#include "mmx6/x4.h"

void func_800ED1CC(u8* arg0);
s32 func_80027BA0(s32 arg0, s32 arg1, s32 arg2, u8* arg3);
extern struct X4_BackgroundObj background_objects[3];
extern u8 D_800FBEC0[];
extern u8 D_800FBEC8[];
extern u8 D_800FBED0[];
extern u8 D_800FBED8[];
extern u8 D_800FBEE0[];
extern u8 D_800FBEE8[];
extern u8 D_800FBEF0[];

void func_800EA7C8(struct X4_AnimatedObj* self) {
    struct X4_BackgroundObj* bg;

    switch (self->unk2 & 0xF) {
    case 0: {
        bg = &background_objects[0];
        if (bg->x_pos.i.hi < self->x_pos.i.hi + 0x10) {
            return;
        }
        func_800ED1CC(D_800FBEC8);
        bg->unk26 = self->x_pos.u.hi + 0x10;
        self->action_phase++;
        return;
    }
    case 1: {
        bg = &background_objects[0];
        if (bg->x_pos.i.hi < self->x_pos.i.hi + 0x10) {
            return;
        }
        func_800ED1CC(D_800FBED0);
        bg->unk26 = self->x_pos.u.hi + 0x10;
        self->action_phase++;
        return;
    }
    case 2: {
        bg = &background_objects[0];
        if (bg->x_pos.i.hi < self->x_pos.i.hi + 0x10) {
            return;
        }
        func_800ED1CC(D_800FBED8);
        bg->unk26 = self->x_pos.u.hi + 0x10;
        self->action_phase++;
        return;
    }
    case 3: {
        bg = &background_objects[0];
        if (bg->x_pos.i.hi < self->x_pos.i.hi + 0x10) {
            return;
        }
        func_800ED1CC(D_800FBEE0);
        bg->unk26 = self->x_pos.u.hi + 0x10;
        self->action_phase++;
        return;
    }
    case 4: {
        bg = &background_objects[0];
        if (bg->y_pos.i.hi < self->y_pos.i.hi + 0x10) {
            return;
        }
        func_800ED1CC(D_800FBEE8);
        func_80027BA0(0, 0x1250, 0x1C0, D_800FBEC0);
        bg->unk26 = 0xF00;
        bg->unk2A = self->y_pos.u.hi + 0x20;
        bg->unk28 = self->y_pos.u.hi + 0x20;
        self->action_phase++;
        return;
    }
    case 5: {
        bg = &background_objects[0];
        if (bg->y_pos.i.hi < self->y_pos.i.hi + 0x10) {
            return;
        }
        func_800ED1CC(D_800FBEF0);
        func_80027BA0(0, 0xF30, 0x2C0, D_800FBEC0);
        bg->unk2A = self->y_pos.u.hi + 0x20;
        bg->unk28 = self->y_pos.u.hi + 0x20;
        self->action_phase++;
        return;
    }
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_10/nonmatchings/E9860", func_800EAA00);

INCLUDE_ASM("asm/rock_10/nonmatchings/E9860", func_800EABD8);

INCLUDE_ASM("asm/rock_10/nonmatchings/E9860", func_800EADA8);
// clang-format on

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* func_8002C32C();
s32 func_800ED06C(void* arg0);
extern u8 D_800FA900[];

void func_800EAF28(void* arg0) {
    void* c;
    s32 r;
    // !FAKE: depin: dropping it breaks the match (106/114)
    register s32 one asm("$3");

    r = func_800ED06C(arg0);
    one = 1;
    if (r == 0) {
        M2C_FIELD(arg0, u8*, 4) = 2;
        return;
    }
    M2C_FIELD(arg0, u8*, 0x16) = 6;
    M2C_FIELD(arg0, u8*, 0x60) = one;
    M2C_FIELD(arg0, s16*, 0x8A) = 0xB6;
    M2C_FIELD(arg0, s16*, 0x92) = M2C_FIELD(arg0, s16*, 0xA);
    M2C_FIELD(arg0, s16*, 0x94) = M2C_FIELD(arg0, s16*, 0xE);
    M2C_FIELD(arg0, u8*, 0x5C) = 0;
    M2C_FIELD(arg0, u8*, 0x67) = one;
    M2C_FIELD(arg0, s16*, 0x88) = 0;
    M2C_FIELD(arg0, s16*, 0x96) = 0;
    M2C_FIELD(arg0, s32*, 0x68) = 0;
    M2C_FIELD(arg0, u8**, 0x50) = D_800FA900 + 0x169C;
    M2C_FIELD(arg0, s32*, 0x54) = 0;
    M2C_FIELD(arg0, u8*, 4) = one;
    M2C_FIELD(arg0, u8*, 5) = 0;
    M2C_FIELD(arg0, u8*, 6) = 0;
    M2C_FIELD(arg0, u8*, 7) = 0;
    M2C_FIELD(arg0, u8*, 3) = 0;
    c = func_8002C32C();
    if (c != 0) {
        M2C_FIELD(c, u8*, 0) = 0x41;
        M2C_FIELD(c, u8*, 1) = 0x4F;
        M2C_FIELD(c, u8*, 2) = 0;
        M2C_FIELD(c, void**, 0x7C) = arg0;
        M2C_FIELD(c, u8*, 0x15) = M2C_FIELD(arg0, u8*, 0x15);
        M2C_FIELD(c, s16*, 0xA) = M2C_FIELD(arg0, s16*, 0xA);
        M2C_FIELD(c, s16*, 8) = 0;
        M2C_FIELD(c, s16*, 0xE) = M2C_FIELD(arg0, s16*, 0xE);
        M2C_FIELD(c, s16*, 0xC) = 0;
        M2C_FIELD(c, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
        M2C_FIELD(c, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
        M2C_FIELD(c, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
        M2C_FIELD(c, s16*, 0x40) = M2C_FIELD(arg0, s16*, 0x40);
        M2C_FIELD(c, u8*, 0x14) = M2C_FIELD(arg0, u8*, 0x14);
        M2C_FIELD(c, s32*, 0x84) = M2C_FIELD(arg0, s32*, 0x84);
        M2C_FIELD(arg0, void**, 0x8C) = c;
        M2C_FIELD(c, s16*, 0x8C) = M2C_FIELD(arg0, s16*, 0x90);
    }
    switch (M2C_FIELD(arg0, s32*, 0x84)) {
    case 0:
        M2C_FIELD(arg0, s32*, 0x20) = 0x100000;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        break;
    case 1:
        M2C_FIELD(arg0, s32*, 0x20) = 0x100000;
        M2C_FIELD(arg0, s32*, 0x24) = 0x100000;
        break;
    case 2:
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0x100000;
        break;
    case 3:
        M2C_FIELD(arg0, s32*, 0x20) = -0x100000;
        M2C_FIELD(arg0, s32*, 0x24) = 0x100000;
        break;
    case 4:
        M2C_FIELD(arg0, s32*, 0x20) = -0x100000;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        break;
    case 5:
        M2C_FIELD(arg0, s32*, 0x20) = -0x100000;
        M2C_FIELD(arg0, s32*, 0x24) = -0x100000;
        break;
    case 6:
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = -0x100000;
        break;
    case 7:
        M2C_FIELD(arg0, s32*, 0x20) = 0x100000;
        M2C_FIELD(arg0, s32*, 0x24) = -0x100000;
        break;
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_10/nonmatchings/E9860", func_800EB0F0);
// clang-format on

#include "common.h"
#include "mmx6/x4.h"

struct X4_MiscObj* alloc_sprite_slot(void);
#include "mmx6/state.h"
extern u8 D_800FA900[];

#define F(p, t, o) (*(t*)((u8*)(p) + (o)))
#define TBL(off) ((u8(*)[2])(D_800FA900 + (off)))

#define SPAWN_HEAD(m, u2)                                                      \
    do {                                                                       \
        F(m, u8, 0x0) = 0x41;                                                  \
        F(m, u8, 0x1) = 7;                                                     \
        F(m, u8, 0x2) = u2;                                                    \
        F(m, u8, 0x15) = F(self, u8, 0x15);                                    \
        F(m, u16, 0x40) = F(self, u16, 0x40);                                  \
        F(m, u16, 0x42) = F(self, u16, 0x42) & 0x7FFF;                         \
        F(m, s32, 0x30) = F(self, s32, 0x30);                                  \
        F(m, s32, 0x3C) = F(self, s32, 0x3C);                                  \
        F(m, u8, 0x14) = F(self, u8, 0x14);                                    \
    } while (0)

#define SPAWN_A(m, k16, a, b, c, off)                                          \
    m = alloc_sprite_slot();                                                   \
    if (m != 0) {                                                              \
        SPAWN_HEAD(m, 1);                                                      \
        t = F(self, u16, a);                                                   \
        F(m, u16, 0x8) = 0;                                                    \
        F(m, u16, 0xA) = t;                                                    \
        F(m, u16, 0xE) = F(self, u16, b);                                      \
        F(m, u16, 0xC) = 0;                                                    \
        F(m, u8*, 0x50) = self;                                                \
        F(m, u8, 0x16) = k16;                                                  \
        i = F(self, u16, 0x84);                                                \
        F(m, u16, 0x54) = i;                                                   \
        F(m, u16, 0x56) = F(self, u16, c);                                     \
        F(m, u8, 0x47) = TBL(off)[(s16)i][0] + F(m, u8, 0x56);                 \
        F(m, u8, 0x15) = TBL(off)[(s16)i][1];                                  \
        F(m, u8, 0x0) = 0x51;                                                  \
    }

#define SPAWN_B(m)                                                             \
    m = alloc_sprite_slot();                                                   \
    if (m != 0) {                                                              \
        SPAWN_HEAD(m, 0);                                                      \
        F(m, u16, 0xA) = F(self, u16, 0x92);                                   \
        F(m, u16, 0x8) = F(self, u16, 0x94);                                   \
        F(m, u16, 0xE) = F(self, u16, 0xA);                                    \
        F(m, u16, 0xC) = F(self, u16, 0xE);                                    \
        F(m, u8*, 0x50) = self;                                                \
        F(m, u8, 0x16) = 6;                                                    \
        F(m, u16, 0x54) = F(self, u16, 0x84);                                  \
        F(m, u16, 0x56) = F(self, u16, 0x88);                                  \
        F(m, u8, 0x0) = 0x51;                                                  \
    }

void func_800EB734(u8* self) {
    struct X4_MiscObj* m1;
    struct X4_MiscObj* m2;
    struct X4_MiscObj* m3;
    struct X4_MiscObj* m4;
    struct X4_MiscObj* m5;
    struct X4_MiscObj* m6;
    // !FAKE: depin: dropping it breaks the match (325/361)
    register s32 i asm("$5");
    u16 t;

    if (F(self, s8, 0x5) == 0) {
        F(self, s8, 0x5)++;
        F(self, u8, 0x6) = 0xD;
        if (D_80097420.frame_counter & 1) {
            SPAWN_A(m1, 5, 0x92, 0x94, 0x96, 0x13B0);
            SPAWN_B(m2);
            SPAWN_A(m3, 4, 0xA, 0xE, 0x88, 0x13A0);
        }
    } else {
        if (D_80097420.frame_counter & 1) {
            SPAWN_A(m4, 5, 0x92, 0x94, 0x96, 0x13B0);
            SPAWN_B(m5);
            SPAWN_A(m6, 4, 0xA, 0xE, 0x88, 0x13A0);
        }
        if (--F(self, s8, 0x6) == 0) {
            F(self, u8, 0x4)++;
        }
    }
}
#undef F
#undef TBL
#undef SPAWN_HEAD
#undef SPAWN_A
#undef SPAWN_B

// clang-format off
INCLUDE_ASM("asm/rock_10/nonmatchings/E9860", func_800EBCD8);
// clang-format on

#define func_80041AB8 func_800EC8F8
#define D_80075FD8 D_800FBF20
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#define func_80041AB8 func_800EC934
#define D_80075FD8 D_800FBFA0
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "common.h"
#include "mmx6/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern u8 D_800FA900[];

void func_800EC970(struct ObjectHeader* arg0) {
    if (D_8009716C == 0) {
        ((void (**)(void*))(D_800FA900 + 0x16B0))[arg0->state](arg0);
    }
}

#include "common.h"
#define M2C_UNK s32
M2C_UNK animate_object();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
s32 func_800EAA00(void*);
extern u8 D_800FA900[];

void func_800EC9B8(u8* self) {
    *(s32*)(self + 0x18) = *(s32*)(self + 0x8);
    *(s32*)(self + 0x1C) = *(s32*)(self + 0xC);
    ((void (*)(void*))animate_object)(self);
    ((void (**)(void*))(D_800FA900 + 0x1634))[*(s8*)(self + 5)](self);
    if ((*(s8*)(self + 2) & 0xF0) == 0x20) {
        if (func_800EAA00(self) != 0) {
            if (*(s8*)(self + 5) != 4) {
                self[5] = 4;
                self[6] = 0;
            }
        }
    }
    func_8002CCB0(self, 0x10, 0x10);
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
s32 func_800EAA00(void*);
extern u8 D_800FA900[];

void func_800ECA5C(u8* arg0) {
    *(s32*)(arg0 + 0x18) = *(s32*)(arg0 + 0x8);
    *(s32*)(arg0 + 0x1C) = *(s32*)(arg0 + 0xC);
    ((void (**)(u8*))(D_800FA900 + 0x1654))[*(s8*)(arg0 + 5)](arg0);
    func_8002CCB0(arg0, 0x30, 0x30);
    if (func_800EAA00(arg0) != 0) {
        if (*(s8*)(arg0 + 5) == 2) {
            play_sound(2, 0x20, arg0);
            *(s8*)(arg0 + 5) = 3;
            *(s8*)(arg0 + 6) = 0;
        }
    } else {
        arg0[0x89] = 0;
    }
}

#include "../shared/rock_10/func_800ECB00.c"

#define func_8003744C func_800ECB3C
#define D_80073C1C D_800FBF68
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800ECB78(void* arg0) {
    M2C_FIELD(arg0, s16*, 0x7C) = 3;
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#include "../shared/rock_10/func_800ECB90.c"

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800ECBE4(void* arg0) {
    if (M2C_FIELD(arg0, u8*, 0x89) == 2) {
        M2C_FIELD(arg0, u8*, 0x89) = 0U;
        M2C_FIELD(arg0, s16*, 0x7C) = 0x78;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#include "../shared/rock_10/func_800ECC10.c"

#define func_8003744C func_800ECC38
#define D_80073C1C D_800FBF78
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_800ED0AC(u8* arg0);
extern s16 D_800970AA;

void func_800ECC74(void* arg0) {
    s32 temp_a0;
    s32 temp_v1;
    s32 temp_v0;

    if (M2C_FIELD(arg0, u8*, 0x89) == 2) {
        M2C_FIELD(arg0, u8*, 0x89) = 0;
    }
    if (M2C_FIELD(arg0, u8*, 0x89) == 0) {
        temp_a0 = D_800970AA;
        temp_v1 = M2C_FIELD(arg0, s16*, 0xA);
        temp_v0 = temp_a0 - temp_v1;
        if (temp_v0 >= 0 ? temp_v0 < 0x91 : (temp_v1 - temp_a0) < 0x91) {
            M2C_FIELD(arg0, u8*, 0x88) = func_800ED0AC(arg0);
        }
        if ((M2C_FIELD(arg0, s8*, 2) & 0xF0) == 0x10) {
            set_animation(arg0, M2C_FIELD(arg0, u8*, 0x88) + 8);
        } else {
            set_animation(arg0, M2C_FIELD(arg0, u8*, 0x88));
        }
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800EABD8(void*, M2C_UNK); /* extern */

void func_800ECD40(void* arg0) {
    s32 temp_v1;
    u8 temp_a0;
    u8 temp_v0;

    temp_a0 = M2C_FIELD(arg0, u8*, 0x86);
    temp_v0 = M2C_FIELD(arg0, u8*, 0x88);
    temp_v1 = temp_a0 - temp_v0;
    if ((temp_v1 >= 0 && temp_v1 != 4) ||
        (temp_v1 < 0 && temp_a0 != (temp_v0 - 4))) {
        func_800EABD8(arg0, 0);
    }
    M2C_FIELD(arg0, s16*, 0x7C) = 0x12E;
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#include "../shared/rock_10/func_800ECDB0.c"

#include "common.h"

void func_800ECDEC(void) {
}

#include "common.h"

#define F(type, off) (*(type*)((u8*)arg0 + (off)))

void func_800EADA8(void*, s32);

void func_800ECDF4(void* arg0) {
    u8 v = F(u8, 0x89);

    if (v == 0) {
        if (F(u8, 0x8C) == 1) {
            func_800EADA8(arg0, 0);
            F(u8, 0x8C) = 0;
        }
    } else if (v == 2) {
        F(u8, 0x89) = 0;
        F(u8, 0x8A) = 1;
    }
}
#undef F

#define func_8003744C func_800ECE54
#define D_80073C1C D_800FBF84
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800ECE90(void* arg0) {
    M2C_FIELD(arg0, s8*, 5) = 4;
    M2C_FIELD(arg0, s8*, 6) = 0;
}

#define func_8003744C func_800ECEA0
#define D_80073C1C D_800FBF8C
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

void func_800ECEDC(void) {
}

// clang-format off
INCLUDE_ASM("asm/rock_10/nonmatchings/E9860", func_800ECEE4);
// clang-format on

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800ECFD0(void* arg0) {
    void* temp_a1;

    temp_a1 = M2C_FIELD(arg0, void**, 0x8C);
    M2C_FIELD(arg0, u8*, 0x98) = (u8)M2C_FIELD(temp_a1, u8*, 0x98);
    if ((s8)M2C_FIELD(temp_a1, u8*, 0x98) == 2) {
        M2C_FIELD(arg0, u16*, 0xA) = (u16)M2C_FIELD(temp_a1, u16*, 0xA);
        M2C_FIELD(arg0, u16*, 0xE) = (u16)M2C_FIELD(temp_a1, u16*, 0xE);
    }
    M2C_FIELD(temp_a1, u8*, 0x98) = 0U;
}

#include "../shared/rock_10/func_800ED014.c"

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_800ED06C(void* arg0) {
    u8 temp_v1;
    void* temp_a0;

    temp_a0 = M2C_FIELD(arg0, void**, 0x7C);
    if (M2C_FIELD(temp_a0, s8*, 4) == 4) {
        return 0;
    }
    temp_v1 = M2C_FIELD(temp_a0, u8*, 0x89);
    if (temp_v1 == 1) {
        return 1;
    }
    return temp_v1 != 0;
}

#include "../shared/rock_10/func_800ED0AC.c"

// clang-format off
INCLUDE_ASM("asm/rock_10/nonmatchings/E9860", func_800ED1CC);
// clang-format on

#include "common.h"

void func_800ED288(void) {
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800ED290(void) {
    clear_object_slot();
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
void func_800EBCD8(void* arg0);

#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define SB(p, o) (*(s8*)((u8*)(p) + (o)))

void func_800ED2B0(void* arg0) {
    if (SB(arg0, 0x2) == 1) {
        func_8002CCB0(arg0, 0x80, 0x80);
    } else {
        func_800EBCD8(arg0);
    }
    UB(arg0, 0x4) += 1;
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800ED304(void) {
    clear_object_slot();
}

#define func_80041AB8 func_800ED324
#define D_80075FD8 D_800FBFB8
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "../shared/rock_10/func_800ED360.c"

#include "../shared/rock_10/func_800ED460.c"

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800ED4AC(void) {
    clear_object_slot();
}

// clang-format off
INCLUDE_ASM("asm/rock_10/nonmatchings/E9860", func_800ED4CC);

INCLUDE_ASM("asm/rock_10/nonmatchings/E9860", func_800ED668);
// clang-format on

#define func_800EC484 func_800ED834
#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
void* func_8002C458();
struct X4_MiscObj* alloc_sprite_slot(void);
void set_velocity_from_angle(void*, s32);

#define SPAD (*(u8**)0x1F80004C)

void func_800ED834(void* arg0) {
    u8* child;
    u8* child2;

    child = func_8002C458();
    if (child != 0) {
        play_sound(2, 0, arg0);
        child[0] = 0x41;
        child[1] = 4;
        M2C_FIELD(child, s32*, 8) = M2C_FIELD(arg0, s32*, 8);
        M2C_FIELD(child, s32*, 0xC) = M2C_FIELD(arg0, s32*, 0xC);
        child[2] = SPAD[0x85];
        M2C_FIELD(child, void**, 0x7C) = arg0;
        M2C_FIELD(child, s32*, 0x84) = 0;
        set_velocity_from_angle(child, (s8)SPAD[0x85] & 0xFE);
        SPAD[0x80] = 8;
        M2C_FIELD(arg0, u8*, 6) += 1;
        SPAD[0x82] += 1;
    }
    child2 = alloc_sprite_slot();
    if (child2 != 0) {
        child2[0] = 0x41;
        child2[1] = 6;
        M2C_FIELD(child2, s32*, 8) = M2C_FIELD(arg0, s32*, 8);
        M2C_FIELD(child2, s32*, 0xC) = M2C_FIELD(arg0, s32*, 0xC);
        child2[2] = SPAD[0x85];
        M2C_FIELD(child2, void**, 0x50) = arg0;
    }
    if (M2C_FIELD(arg0, s8*, 2) == 3) {
        SPAD[0x89] = 0x5A;
        M2C_FIELD(arg0, u8*, 5) = 7;
        M2C_FIELD(arg0, u8*, 6) = SPAD[0x8A];
        M2C_FIELD(arg0, s16*, 0x7C) = (s8)SPAD[0x8B];
        M2C_FIELD(arg0, u16*, 0xE) = M2C_FIELD(SPAD, u16*, 0x8E);
        M2C_FIELD(arg0, s32*, 0x24) = M2C_FIELD(SPAD, s32*, 0x90);
        M2C_FIELD(arg0, s32*, 0x2C) = M2C_FIELD(SPAD, s32*, 0x94);
    }
}
#undef func_800EC484

#define func_800EC640 func_800ED9F0
#include "../shared/rock_02/func_800EC640.c"
#undef func_800EC640

// clang-format off
INCLUDE_ASM("asm/rock_10/nonmatchings/E9860", func_800EDB34);

INCLUDE_ASM("asm/rock_10/nonmatchings/E9860", func_800EDBF8);

INCLUDE_ASM("asm/rock_10/nonmatchings/E9860", func_800EDD78);
// clang-format on

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
extern s32 D_800741FC[];
extern s32 D_800FC130[];
extern s32 D_800FC138[];
extern s8 D_800FC13C[];

void func_800EDE10(void* self) {
    void* parent;

    M2C_FIELD(self, s8*, 3) = 1;
    M2C_FIELD(self, void**, 0x68) = D_800FC138;
    M2C_FIELD(self, void**, 0x54) = D_800FC130;
    M2C_FIELD(self, void**, 0x50) = D_800FC130;
    M2C_FIELD(self, s32*, 0x28) = 0;
    M2C_FIELD(self, s32*, 0x2C) = 0;
    M2C_FIELD(self, s8*, 0x67) = 0;
    M2C_FIELD(self, s8*, 0x16) = 1;
    M2C_FIELD(self, void**, 0x58) = D_800741FC;
    M2C_FIELD(self, u8*, 4)++;
    parent = M2C_FIELD(self, void**, 0x7C);
    M2C_FIELD(self, u16*, 0x40) = M2C_FIELD(parent, u16*, 0x40);
    M2C_FIELD(self, u16*, 0x42) = M2C_FIELD(parent, u16*, 0x42) & 0x7FFF;
    M2C_FIELD(self, s32*, 0x30) = M2C_FIELD(parent, s32*, 0x30);
    M2C_FIELD(self, s32*, 0x3C) = M2C_FIELD(parent, s32*, 0x3C);
    M2C_FIELD(self, u8*, 0x15) = M2C_FIELD(parent, u8*, 0x15);
    M2C_FIELD(self, u8*, 0x14) = M2C_FIELD(parent, u8*, 0x14);
    M2C_FIELD(self, s8*, 0x60) = 3;
    M2C_FIELD(self, s8*, 0x5C) = 1;
    M2C_FIELD(self, s32*, 0x20) *= 2;
    M2C_FIELD(self, s32*, 0x24) *= 2;
    switch (M2C_FIELD(self, s8*, 2) & 0xFE) {
    case 2:
    case 4:
    case 6:
        M2C_FIELD(self, s16*, 0xA) += D_800FC13C[6];
        M2C_FIELD(self, s16*, 0xE) += D_800FC13C[7];
        break;
    case 10:
    case 12:
    case 14:
        M2C_FIELD(self, s16*, 0xA) += D_800FC13C[4];
        M2C_FIELD(self, s16*, 0xE) += D_800FC13C[5];
        break;
    case 8:
        M2C_FIELD(self, s16*, 0xA) += D_800FC13C[8];
        M2C_FIELD(self, s16*, 0xE) += D_800FC13C[9];
        break;
    case 18:
    case 20:
    case 22:
        M2C_FIELD(self, s16*, 0xA) += D_800FC13C[12];
        M2C_FIELD(self, s16*, 0xE) += D_800FC13C[13];
        break;
    case 26:
    case 28:
    case 30:
        M2C_FIELD(self, s16*, 0xA) += D_800FC13C[14];
        M2C_FIELD(self, s16*, 0xE) += D_800FC13C[15];
        break;
    case 24:
        M2C_FIELD(self, s16*, 0xA) += D_800FC13C[10];
        M2C_FIELD(self, s16*, 0xE) += D_800FC13C[11];
        break;
    default:
        if (M2C_FIELD(self, u8*, 0x15) & 0x40) {
            M2C_FIELD(self, s16*, 0xA) += D_800FC13C[2];
            M2C_FIELD(self, s16*, 0xE) += D_800FC13C[3];
        } else {
            M2C_FIELD(self, s16*, 0xA) += D_800FC13C[0];
            M2C_FIELD(self, s16*, 0xE) += D_800FC13C[1];
        }
        break;
    }
    set_animation(self, 6);
}

#include "common.h"
#include "mmx6/x4.h"

s32 set_animation(void*, s32);
extern u8 D_800FC15C[];

void func_800EE0A0(struct X4_MainObj* self) {
    struct X4_MainObj* parent;

    parent = (struct X4_MainObj*)self->attack_box;
    self->on_screen = 1;
    self->x_speed = 0;
    self->x_accel = 0;
    self->y_speed = 0;
    self->gravity = 0;
    self->unk16 = 0;
    self->unk40 = parent->unk40;
    self->unk42 = parent->unk42 & 0x7FFF;
    self->animation_table = parent->animation_table;
    self->sprite_frames = parent->sprite_frames;
    self->unk15 = parent->unk15;
    self->bg_offset = parent->bg_offset;
    ((void (*)(void*, s32))set_animation)(self, 7);
    switch (self->unk2 & 0xFE) {
    case 2:
    case 4:
    case 6:
        self->x_pos.i.hi += (s8)D_800FC15C[6];
        self->y_pos.i.hi += (s8)D_800FC15C[7];
        break;
    case 10:
    case 12:
    case 14:
        self->x_pos.i.hi += (s8)D_800FC15C[4];
        self->y_pos.i.hi += (s8)D_800FC15C[5];
        break;
    case 8:
        self->x_pos.i.hi += (s8)D_800FC15C[8];
        self->y_pos.i.hi += (s8)D_800FC15C[9];
        break;
    case 18:
    case 20:
    case 22:
        self->x_pos.i.hi += (s8)D_800FC15C[12];
        self->y_pos.i.hi += (s8)D_800FC15C[13];
        break;
    case 26:
    case 28:
    case 30:
        self->x_pos.i.hi += (s8)D_800FC15C[14];
        self->y_pos.i.hi += (s8)D_800FC15C[15];
        break;
    case 24:
        self->x_pos.i.hi += (s8)D_800FC15C[10];
        self->y_pos.i.hi += (s8)D_800FC15C[11];
        break;
    default:
        if (self->unk15 & 0x40) {
            self->x_pos.i.hi += (s8)D_800FC15C[2];
            self->y_pos.i.hi += (s8)D_800FC15C[3];
        } else {
            self->x_pos.i.hi += (s8)D_800FC15C[0];
            self->y_pos.i.hi += (s8)D_800FC15C[1];
        }
        break;
    }
    self->state++;
}

#define func_80041AB8 func_800EE2EC
#define D_80075FD8 D_800FC0A4
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

// clang-format off
INCLUDE_ASM("asm/rock_10/nonmatchings/E9860", func_800EE328);
// clang-format on

#define func_800ED09C func_800EE44C
#include "../shared/rock_02/func_800ED09C.c"
#undef func_800ED09C

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s16 D_800970AA;

void func_800EE524(void* arg0) {
    if ((D_800970AA - M2C_FIELD(arg0, s16*, 0xA)) >= 0xB0) {
        M2C_FIELD(arg0, s8*, 0x15) = 0x40;
        M2C_FIELD(arg0, s8*, 4) = 1;
        M2C_FIELD(arg0, s8*, 5) = 3;
    }
}

#include "common.h"

void func_800EE564(void) {
}

#define func_8003744C func_800EE56C
#define D_80073C1C D_800FC0D8
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800ED1F8 func_800EE5A8
#include "../shared/rock_02/func_800ED1F8.c"
#undef func_800ED1F8

#define func_800ED25C func_800EE60C
#include "../shared/rock_02/func_800ED25C.c"
#undef func_800ED25C

#define func_8003744C func_800EE668
#define D_80073C1C D_800FC0E0
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800ED2F4 func_800EE6A4
#include "../shared/rock_02/func_800ED2F4.c"
#undef func_800ED2F4

#define func_800ED370 func_800EE720
#include "../shared/rock_02/func_800ED370.c"
#undef func_800ED370

#define func_800ED3D4 func_800EE784
#define D_800FAE78 D_800FC0E8
#include "../shared/rock_02/func_800ED3D4.c"
#undef func_800ED3D4
#undef D_800FAE78

#define func_800ED420 func_800EE7D0
#include "../shared/rock_02/func_800ED420.c"
#undef func_800ED420

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EE820(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x45) != 0) {
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#define func_800ED498 func_800EE848
#include "../shared/rock_02/func_800ED498.c"
#undef func_800ED498

#define func_800ED520 func_800EE8D0
#include "../shared/rock_02/func_800ED520.c"
#undef func_800ED520

#define func_800ED3D4 func_800EE940
#define D_800FAE78 D_800FC100
#include "../shared/rock_02/func_800ED3D4.c"
#undef func_800ED3D4
#undef D_800FAE78

// clang-format off
INCLUDE_ASM("asm/rock_10/nonmatchings/E9860", func_800EE98C);
// clang-format on

#define func_800ED67C func_800EEA2C
#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
void* func_8002C458();
struct X4_MiscObj* alloc_sprite_slot(void);
void set_velocity_from_angle(void*, s32);

#define SPAD (*(u8**)0x1F80004C)

void func_800EEA2C(void* arg0) {
    u8* child;
    u8* child2;

    if (M2C_FIELD(arg0, s8*, 0x45) != 0) {
        child = func_8002C458();
        if (child != 0) {
            play_sound(2, 0, arg0);
            child[0] = 0x41;
            child[1] = 4;
            M2C_FIELD(child, s32*, 8) = M2C_FIELD(arg0, s32*, 8);
            M2C_FIELD(child, s32*, 0xC) = M2C_FIELD(arg0, s32*, 0xC);
            child[2] = SPAD[0x85];
            M2C_FIELD(child, void**, 0x7C) = arg0;
            M2C_FIELD(child, s32*, 0x84) = 0;
            set_velocity_from_angle(child, (s8)SPAD[0x85] & 0xFE);
            SPAD[0x80] = 8;
            M2C_FIELD(arg0, u8*, 6) += 1;
            SPAD[0x82] += 1;
        }
        child2 = alloc_sprite_slot();
        if (child2 != 0) {
            child2[0] = 0x41;
            child2[1] = 6;
            M2C_FIELD(child2, s32*, 8) = M2C_FIELD(arg0, s32*, 8);
            M2C_FIELD(child2, s32*, 0xC) = M2C_FIELD(arg0, s32*, 0xC);
            child2[2] = SPAD[0x85];
            M2C_FIELD(child2, void**, 0x50) = arg0;
        }
    }
}
#undef func_800ED67C

// clang-format off
INCLUDE_ASM("asm/rock_10/nonmatchings/E9860", func_800EEB68);
// clang-format on

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EEBC8(void* arg0) {
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EEBDC(void* arg0) {
    M2C_FIELD(arg0, s8*, 0x67) = -1;
    M2C_FIELD(arg0, s8*, 5) = 6;
    M2C_FIELD(arg0, s8*, 6) = 0;
}

#define func_8003744C func_800EEBF4
#define D_80073C1C D_800FC118
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800ED880 func_800EEC30
#include "../shared/rock_02/func_800ED880.c"
#undef func_800ED880

#include "common.h"

#define M2C_UNK s32

M2C_UNK animate_object(); /* extern */
M2C_UNK move_object(s32); /* extern */

void func_800EEC70(s32 arg0) {
    animate_object();
    move_object(arg0);
}

#define func_800ED8EC func_800EEC9C
#define D_800FAEB0 D_800FC120
#include "../shared/rock_02/func_800ED8EC.c"
#undef func_800ED8EC
#undef D_800FAEB0

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK); /* extern */
M2C_UNK animate_object(void*);         /* extern */
extern s16 D_800970AA;

void func_800EED30(void* arg0) {
    if ((D_800970AA - M2C_FIELD(arg0, s16*, 0xA)) > 0) {
        M2C_FIELD(arg0, s8*, 0x15) = 0x40;
    }
    set_animation(arg0, 1);
    animate_object(arg0);
    M2C_FIELD(arg0, s16*, 0x7E) = 0x20;
    M2C_FIELD(arg0, s16*, 0x7C) = 0x28;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0xFFFE0000;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#define func_800EDA04 func_800EEDB4
#include "../shared/rock_02/func_800EDA04.c"
#undef func_800EDA04

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();           /* extern */
M2C_UNK apply_object_motion(void*); /* extern */

void func_800EEE2C(void* arg0) {
    ((M2C_UNK(*)())animate_object)();
    apply_object_motion(arg0);
    if (M2C_FIELD(arg0, s32*, 0x24) == 0) {
        M2C_FIELD(arg0, s16*, 0x7C) = 0x28;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = -0x1000;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#define func_800EDAD4 func_800EEE84
#include "../shared/rock_02/func_800EDAD4.c"
#undef func_800EDAD4

#define func_800EDB48 func_800EEEF8
#define D_800FAEDC D_800FC14C
#include "../shared/rock_02/func_800EDB48.c"
#undef func_800EDB48
#undef D_800FAEDC

// clang-format off
INCLUDE_ASM("asm/rock_10/nonmatchings/E9860", func_800EEF64);
// clang-format on

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EF01C(void) {
    clear_object_slot();
}

#include "common.h"

void func_800EF03C(void) {
}

#define func_80048DC8 func_800EF044
#define D_80077BC0 D_800FC16C
#include "../shared/d1000/func_80048DC8.c"
#undef func_80048DC8
#undef D_80077BC0

#define func_800EDCE0 func_800EF090
#include "../shared/rock_02/func_800EDCE0.c"
#undef func_800EDCE0

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EF0F0(void) {
    clear_object_slot();
}

// clang-format off
INCLUDE_ASM("asm/rock_10/nonmatchings/E9860", func_800EF110);
// clang-format on

#define func_800EE70C func_800EF250
#define g_Player g_Player
#include "../shared/commander_yammark/func_800EE70C.c"
#undef func_800EE70C
#undef g_Player

#define func_800EE800 func_800EF344
#define D_80097420 D_80097420
#include "../shared/commander_yammark/func_800EE800.c"
#undef func_800EE800
#undef D_80097420

#define func_800EE8C4 func_800EF408
#define background_objects background_objects
#include "../shared/commander_yammark/func_800EE8C4.c"
#undef func_800EE8C4
#undef background_objects

// clang-format off
INCLUDE_ASM("asm/rock_10/nonmatchings/E9860", func_800EF508);

INCLUDE_ASM("asm/rock_10/nonmatchings/E9860", func_800EF8FC);
// clang-format on

#define func_800EA1D8 func_800EFA08
#define D_800FAA64 D_800FC1C0
#include "../shared/d1000/func_800EA1D8.c"
#undef func_800EA1D8
#undef D_800FAA64

// clang-format off
INCLUDE_ASM("asm/rock_10/nonmatchings/E9860", func_800EFA54);
// clang-format on

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CA14(); /* extern */
M2C_UNK func_8002CA54(); /* extern */

void func_800EFAD0(struct ObjectHeader* arg0) {
    if (arg0->state == 2) {
        func_8002CA14();
        return;
    }
    func_8002CA54();
}

#define func_800EEFCC func_800EFB10
#define g_Player g_Player
#include "../shared/commander_yammark/func_800EEFCC.c"
#undef func_800EEFCC
#undef g_Player

#include "common.h"
#include "mmx6/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s16 D_800970AA;

void func_800EFB88(void* arg0) {
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

void func_800EFBD4(void* arg0) {
    if (D_800970AA >= M2C_FIELD(arg0, s16*, 0xA)) {
        M2C_FIELD(arg0, u16*, 0x84) = (u16)D_800970AA;
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, s8*, 5) = 3;
        M2C_FIELD(arg0, s8*, 6) = 0;
    }
}

#define func_8003744C func_800EFC10
#define D_80073C1C D_800FC1E8
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_8003744C func_800EFC4C
#define D_80073C1C D_800FC284
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800EF144 func_800EFC88
#include "../shared/commander_yammark/func_800EF144.c"
#undef func_800EF144

#define func_800EF1E8 func_800EFD2C
#include "../shared/commander_yammark/func_800EF1E8.c"
#undef func_800EF1E8

#define func_800EF27C func_800EFDC0
#define D_80097420 D_80097420
#include "../shared/commander_yammark/func_800EF27C.c"
#undef func_800EF27C
#undef D_80097420

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EFE28(void) {
    clear_object_slot();
}

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20_800EFE48 (*(s32**)0x1F800020)

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);
extern u32* D_80095098;
extern s32 D_800FC29C;
extern s32 D_800FC2A0;
extern s32 D_800FC2A4;
extern s32 D_800FC2A8;
extern s32 D_800FC2AC;
extern s32 D_800FC2B0;
extern s32 D_800FC2B4;
extern s32 D_800FC2B8;
extern s32 D_800FC2BC;
extern s32 D_800FC2C0;
extern s32 D_800FC428;
extern void* D_800FCFF0;
extern void* D_800FCFF4;
extern void* D_800FCFF8;
extern void* D_800FCFFC;

#define F(type, off) M2C_FIELD(self, type*, off)

void func_800EFE48(void* self) {
    s32 a;
    s32 b;
    u8 c;

    F(s8, 0x5C) = 6;
    F(s8, 0x61) = 0;
    c = D_800970B4;
    F(s8, 0x67) = 0;
    F(void*, 0x30) = &D_800FC428;
    F(u8, 0x16) = 6;
    F(void*, 0x54) = 0;
    F(s32, 0x50) = 0;
    F(s8, 0x70) = 0;
    F(s32, 0x20) = 0;
    F(s32, 0x24) = 0;
    F(s32, 0x28) = 0;
    F(s32, 0x2C) = 0;
    F(s8, 0x99) = 1;
    F(s8, 0x8B) = 0;
    F(u8, 0x14) = c;
    F(s32, 0x18) = F(s32, 0x8);
    F(s32, 0x1C) = F(s32, 0xC);
    if (!(F(s8, 2) & 0xF0)) {
        F(void*, 0x68) = &D_800FC2AC;
        F(s8, 0x60) = 6;
        D_800FCFF0 = &D_800FC29C;
        D_800FCFF4 = &D_800FC2A0;
        D_800FCFF8 = &D_800FC2A8;
        D_800FCFFC = &D_800FC2A4;
    } else {
        F(u16, 0x40) = D_80095098[func_8002A47C(F(s8, 1)) + 1] >> 7;
        a = func_8002A47C(F(s8, 1));
        b = func_8002A47C(F(s8, 1)) + 1;
        a = (a + 1) * 4;
        F(s16, 0x42) = ((a + 0x20) % 16) | (((b + 8) / 4 + 0x1E0) << 6);
        F(u8*, 0x3C) =
            (u8*)SPAD20_800EFE48 + SPAD20_800EFE48[func_8002A47C(F(s8, 1)) + 1];
        F(s8, 0x60) = 7;
        F(void*, 0x68) = &D_800FC2C0;
        D_800FCFF0 = &D_800FC2B0;
        D_800FCFF4 = &D_800FC2B4;
        D_800FCFF8 = &D_800FC2BC;
        D_800FCFFC = &D_800FC2B8;
    }
    set_animation(self, 0);
    {
        // !FAKE: depin: dropping it breaks the match (134/137)
        register s32 t asm("$2") = F(u8, 2) & 0xF;
        if (!t) {
            F(u8, 0x15) = 0;
        } else {
            F(u8, 0x15) = 0x40;
        }
    }
    F(s8, 4) = 1;
    F(s8, 5) = 3;
    F(s8, 6) = 0;
}

#include "common.h"
#include "mmx6/globals.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();
s32 is_off_screen(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002F288(void*);
M2C_UNK func_80030ECC();
s32 check_enemy_hits(void*);
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
M2C_UNK func_80049E50(void*);
void func_8004E654(void*, s32);
extern M2C_UNK D_8007433C;
extern s32 D_800FC2AC;
extern s32 D_800FC2C4;
extern s32 D_800FC2C8;
extern s32 D_800FC2CC;
extern M2C_UNK D_800FC45C;
extern void (*D_800FC474[])(void*);
extern void* D_800FCFF0;
extern void* D_800FCFF4;
extern void* D_800FCFF8;
extern void* D_800FCFFC;

#define F(type, off) M2C_FIELD(self, type*, off)

void func_800F006C(void* self) {
    s32 r;
    u8 m;
    void* p;
    void* q;

    F(s32, 0x18) = F(s32, 0x8);
    F(s32, 0x1C) = F(s32, 0xC);
    ((M2C_UNK(*)())animate_object)();
    D_800FC474[F(s8, 5)](self);
    if (F(s8, 4) != 2) {
        if (F(u8, 0x8B) == 0) {
            F(void*, 0x50) = D_800FCFF0;
        } else {
            F(void*, 0x50) = D_800FCFF4;
        }
        func_80030ECC(self);
        F(void*, 0x50) = D_800FCFFC;
        func_80030ECC(self);
    }
    if (F(u8, 0x8B) == 0) {
        F(void*, 0x58) = &D_8007433C;
        F(void*, 0x54) = &D_800FC2C4;
        F(void*, 0x68) = &D_800FC2AC;
    } else {
        F(void*, 0x58) = &D_8007433C;
        F(void*, 0x54) = &D_800FC2C8;
        F(void*, 0x68) = &D_800FC2CC;
    }
    r = check_enemy_hits(self);
    if (r < 0 || (q = &D_800743DC, p = D_800FCFF8, F(void*, 0x54) = p,
                  F(void*, 0x58) = q, r = check_enemy_hits(self), r < 0)) {
        if (r != -0x38) {
            func_8004E654(self, 0x14);
        }
        // !FAKE: goto shares the dead block; copied block+return moved bytes
        goto dead;
    }
    if (is_off_screen(self, 0x60, 0x60) != 0) {
        F(s8, 4) = 4;
        return;
    }
    func_8002CCB0(self, 0x40, 0x40);
    m = F(u8, 0x70);
    if ((m & 0xC) == 0xC || (m & 3) == 3) {
    dead:
        F(void*, 0x68) = 0;
        func_80049E50(self);
        func_800477E4(4, &D_800FC45C, self);
        {
            // !FAKE: depin: dropping it breaks the match (121/123)
            register s32 a asm("$2") = 0x20;
            s32 b = 6;
            F(s16, 0x7E) = b;
            F(s16, 0x7C) = a;
        }
        F(s8, 3) = 0;
        F(s8, 4) = 2;
        return;
    }
    func_8002F288(self);
}

#include "../shared/rock_10/func_800F0258.c"

#define func_80041AB8 func_800F03F8
#define D_80075FD8 D_800FC460
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "../shared/rock_10/func_800F0434.c"

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CA14(); /* extern */
M2C_UNK func_8002CA54(); /* extern */

void func_800F04A0(void* arg0) {
    M2C_FIELD(arg0, s32*, 0x80) = 0;
    M2C_FIELD(arg0, s32*, 0x84) = 0;
    M2C_FIELD(arg0, s32*, 0x88) = 0;
    M2C_FIELD(arg0, s32*, 0x8C) = 0;
    M2C_FIELD(arg0, s32*, 0x94) = 0;
    if (M2C_FIELD(arg0, s8*, 4) == 4) {
        func_8002CA54();
        return;
    }
    func_8002CA14();
}

#include "common.h"

void func_800F04F0(void) {
}

#define func_8003744C func_800F04F8
#define D_80073C1C D_800FC494
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F33C4 func_800F0534
#include "../shared/rock_04/func_800F33C4.c"
#undef func_800F33C4

#include "common.h"

s32 func_800F09A0();

#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define H(p, o) (*(s16*)((u8*)(p) + (o)))
#define UH(p, o) (*(u16*)((u8*)(p) + (o)))

void func_800F0570(void* arg0) {
    if (!(UH(arg0, 0x7C) & 0x1F) && func_800F09A0() != 0) {
        UB(arg0, 5) = 4;
        UB(arg0, 6) = 0;
        return;
    }
    if (--H(arg0, 0x7C) == 0) {
        UB(arg0, 6)++;
    }
}

#include "../shared/rock_10/func_800F05EC.c"

#define func_8003744C func_800F0648
#define D_80073C1C D_800FC4A0
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/rock_10/func_800F0684.c"

#include "../shared/rock_10/func_800F06B8.c"

#define func_800EA6FC func_800F0710
#include "../shared/commander_yammark/func_800EA6FC.c"
#undef func_800EA6FC

#define func_8003744C func_800F073C
#define D_80073C1C D_800FC4AC
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/rock_10/func_800F0778.c"

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F07AC(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x45) == 2) {
        M2C_FIELD(arg0, s8*, 0x8B) = 1;
    }
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        M2C_FIELD(arg0, s16*, 0x7C) = 4;
        M2C_FIELD(arg0, s16*, 0x7E) = 0x1E;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#include "common.h"
#include "mmx6/x4.h"

s32 func_8002D380(void*, void*);
extern struct X4_PlayerObj g_Player;

#define F(type, off) (*(type*)((u8*)arg0 + (off)))

void func_800F07F4(void* arg0) {
    if (--F(s16, 0x7E) == 0) {
        if (F(u8, 0x15) == 0) {
            F(s16, 0xA) -= 6;
        } else {
            F(s16, 0xA) += 6;
        }
        F(u8, 0x81) = func_8002D380(arg0, &g_Player);
        if (F(u8, 0x15) == 0) {
            F(s16, 0xA) += 6;
        } else {
            F(s16, 0xA) -= 6;
        }
        F(u8, 0x6)++;
    }
}
#undef F

#include "../shared/rock_10/func_800F08A8.c"

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F08FC(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x45) == 2) {
        M2C_FIELD(arg0, s8*, 0x8B) = 0;
    }
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        M2C_FIELD(arg0, s8*, 5) = 3;
        M2C_FIELD(arg0, s8*, 6) = 0;
    }
}

#include "common.h"

void func_800F0930(void) {
}

#define func_8003744C func_800F0938
#define D_80073C1C D_800FC4C4
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

void func_800F0974(void) {
}

#include "common.h"

void func_800F097C(void) {
}

#include "common.h"

void func_800F0984(void) {
}

#include "common.h"

void func_800F098C(void) {
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F0994(void* arg0) {
    M2C_FIELD(arg0, u8*, 5) = (u8)M2C_FIELD(arg0, u8*, 0x94);
}

#define func_800EF764 func_800F09A0
#include "../shared/rock_31/func_800EF764.c"
#undef func_800EF764

#define func_80041AB8 func_800F09C4
#define D_80075FD8 D_800FC4DC
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "common.h"
#include "mmx6/globals.h"

extern s32 play_sound(s32, s32, void*);
extern s32 set_animation(void*, s32);
extern s32 D_800FC4D4;
extern s32 D_800FC4D8;

void func_800F0A00(u8* arg0) {
    *(s32**)(arg0 + 0x58) = &D_8007429C;
    arg0[4] = 1;
    arg0[3] = 1;
    arg0[0x16] = 0;
    *(u16*)(arg0 + 0x42) &= 0x7FFF;
    if (arg0[0x15] == 0) {
        *(u16*)(arg0 + 0xA) -= 6;
    } else {
        *(u16*)(arg0 + 0xA) += 6;
    }
    play_sound(2, 0x4F, arg0);
    *(s32**)(arg0 + 0x68) = &D_800FC4D8;
    *(s32**)(arg0 + 0x54) = &D_800FC4D4;
    *(s32**)(arg0 + 0x50) = &D_800FC4D4;
    arg0[0x5C] = 1;
    arg0[0x60] = 3;
    set_animation(arg0, 5);
}

#include "../shared/rock_10/func_800F0AB4.c"

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800F0B90(void) {
    clear_object_slot();
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern struct X4_PlayerObj g_Player;
u8 func_80030234(struct X4_PlayerObj*, s16, s16);
extern void (*D_800FC4E8[])(void*);
extern void (*D_800FC4F0)(void*);

#define F530_FLD(p, type, off) (*(type*)((u8*)(p) + (off)))
static inline u8 f530_tile(struct X4_PlayerObj* p, s16 x, s16 y) {
    if (p->terrain_box == 0) {
        return 0;
    }
    return func_80030234(p, x, y);
}
#define F530_TILE(dy)                                                          \
    f530_tile(&g_Player, g_Player.x_pos.i.hi,                                  \
              g_Player.terrain_box->unk1 +                                     \
                  (g_Player.y_pos.i.hi + g_Player.terrain_box->unk3) + (dy))
#define F530_MAX(a, b) ((a) > (b) ? (a) : (b))
#define F530_MIN(a, b) ((a) < (b) ? (a) : (b))
#define F530_ABS(x) ((x) >= 0 ? (x) : -(x))
#define F530_NEG()                                                             \
    {                                                                          \
        g_Player.x_pos.val =                                                   \
            F530_FLD(&g_Player, s32, 0x13C) +                                  \
            F530_MAX(dx - 0x38000, -F530_FLD(&g_Player, s32, 0x104));          \
        g_Player.y_pos.val += F530_ABS(                                        \
            F530_MAX(dx - 0x38000, -F530_FLD(&g_Player, s32, 0x104)));         \
    }
#define F530_POS()                                                             \
    {                                                                          \
        g_Player.x_pos.val =                                                   \
            F530_FLD(&g_Player, s32, 0x13C) +                                  \
            F530_MIN(dx + 0x38000, F530_FLD(&g_Player, s32, 0x104));           \
        g_Player.y_pos.val +=                                                  \
            F530_ABS(F530_MIN(dx + 0x38000, F530_FLD(&g_Player, s32, 0x104))); \
    }

void func_800F0BB0(u8* arg0) {
    s32 dx;

    arg0[0x21] = arg0[0x20];
    arg0[0x20] = F530_TILE(0);
    dx = g_Player.x_pos.val - F530_FLD(&g_Player, s32, 0x13C);
    if (g_Player.state == 1) {
    loop:
        switch (arg0[0x20]) {
        case 17:
        case 18:
        case 19:
        case 20:
            arg0[4] = 1;
            if (arg0[0x21] == 0x3C && g_Player.facing != 0 &&
                g_Player.action != 0xC) {
                g_Player.x_pos.val = F530_FLD(&g_Player, s32, 0x13C);
            } else {
                F530_NEG();
            }
            // !FAKE: goto enters the in-switch tail shared by the slope cases; if/else merge only halved them
            goto tail;
        case 21:
        case 22:
        case 23:
        case 24:
            arg0[4] = 1;
            if (arg0[0x21] == 0x3C && g_Player.facing == 0 &&
                g_Player.action != 0xC) {
                g_Player.x_pos.val = F530_FLD(&g_Player, s32, 0x13C);
            } else {
                F530_POS();
            }
            // !FAKE: goto enters the in-switch tail shared by the slope cases; if/else merge only halved them
            goto tail;
        case 25:
        case 26:
            arg0[4] = 1;
            if (arg0[0x21] == 0x3C && g_Player.facing != 0 &&
                g_Player.action != 0xC) {
                g_Player.x_pos.val = F530_FLD(&g_Player, s32, 0x13C);
            } else {
                F530_NEG();
            }
            // !FAKE: goto enters the in-switch tail shared by the slope cases; if/else merge only halved them
            goto tail;
        case 27:
        case 28:
            arg0[4] = 1;
            if (arg0[0x21] == 0x3C && g_Player.facing == 0 &&
                g_Player.action != 0xC) {
                g_Player.x_pos.val = F530_FLD(&g_Player, s32, 0x13C);
            } else {
                F530_POS();
            }
            // !FAKE: goto enters the in-switch tail shared by the slope cases; if/else merge only halved them
            goto tail;
        case 16:
            arg0[0x20] = F530_TILE(-0x10);
            // !FAKE: goto re-enters the switch; for(;;)+continue moved bytes
            goto loop;
        case 0:
            if (g_Player.latched_collision_flags & 8) {
                // !FAKE: goto shares case 60's call; copied call+break moved
                goto call;
            }
            if ((s8)arg0[4] == 2) {
                D_800FC4F0(arg0);
            }
            arg0[0x1C] = g_Player.action;
            break;
        default:
            arg0[4] = 1;
            arg0[0x1C] = g_Player.action;
            break;
        tail:
            switch (arg0[0x20] = F530_TILE(0)) {
            case 0:
                if ((s8)arg0[4] != 2) {
                    D_800FC4E8[(s8)arg0[4]](arg0);
                }
                arg0[0x1C] = g_Player.action;
                break;
            case 0x10 ... 0x1C:
            case 0x38:
                break;
            default:
                // !FAKE: goto shares case 60's call; copied call+break moved
                goto call;
            }
            break;
        case 60:
        call:
            D_800FC4E8[(s8)arg0[4]](arg0);
            arg0[0x1C] = g_Player.action;
            break;
        }
    }
    if (g_Player.x_pos.val != F530_FLD(&g_Player, s32, 0x13C)) {
        arg0[0x1E] =
            g_Player.x_pos.val < F530_FLD(&g_Player, s32, 0x13C) ? 0 : 0x40;
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_10/nonmatchings/E9860", func_800F1014);
// clang-format on

#define func_800F0CF4 func_800F1374
#define g_Player g_Player
#include "../shared/rock_07/func_800F0CF4.c"
#undef func_800F0CF4
#undef g_Player

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F1728(void* arg0) {
    M2C_FIELD(arg0, s8*, 0x1C) = 0;
    M2C_FIELD(arg0, s8*, 0x1E) = 0;
    M2C_FIELD(arg0, s32*, 0x14) = 0;
    M2C_FIELD(arg0, s32*, 0x18) = 0;
    M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
}

#define func_800EA704 func_800F1748
#define g_Player g_Player
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);

extern struct X4_PlayerObj g_Player;
#define PLAYER (*(struct X4_PlayerObj*)&g_Player)

void func_800F1748(struct X4_BaseObj* self) {
    if (M2C_FIELD(self, s8*, 0x67) != 0) {
        return;
    }
    if (M2C_FIELD(self, u8*, 0x80) & 3) {
        return;
    }
    if (M2C_FIELD(self, u8*, 0x83) != 0) {
        M2C_FIELD(self, u8*, 0x83)--;
        return;
    }
    if ((self->y_pos.i.hi - PLAYER.y_pos.i.hi >= 0
             ? self->y_pos.i.hi - PLAYER.y_pos.i.hi
             : PLAYER.y_pos.i.hi - self->y_pos.i.hi) < 0x28) {
        if (self->unk15 != 0) {
            if (PLAYER.x_pos.i.hi < self->x_pos.i.hi + 0x50) {
                M2C_FIELD(self, u8*, 0x81)++;
            } else {
                M2C_FIELD(self, u8*, 0x81) = 0;
            }
        } else {
            if (self->x_pos.i.hi - 0x50 < PLAYER.x_pos.i.hi) {
                M2C_FIELD(self, u8*, 0x81)++;
            } else {
                M2C_FIELD(self, u8*, 0x81) = 0;
            }
        }
        if (M2C_FIELD(self, u8*, 0x81) >= 0x3D) {
            self->action = 4;
            self->action_phase = 0;
            set_animation(self, 7);
            M2C_FIELD(self, u8*, 0x81) = 0;
            M2C_FIELD(self, u8*, 0x80) |= 2;
        }
    } else {
        M2C_FIELD(self, u8*, 0x81) = 0;
    }
}
#undef func_800EA704
#undef g_Player

#define func_800EA840 func_800F1884
#include "../shared/rock_06/func_800EA840.c"
#undef func_800EA840

#define func_800EA9E0 func_800F1A24
#define D_800950A0 D_800950A0
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);

extern s8 D_800950A0[];
extern struct X4_PlayerObj g_Player;

#define ABS(v) ((v) < 0 ? -(v) : (v))
#define OBJ(p) ((struct X4_BaseObj*)(p))

void func_800F1A24(struct X4_BaseObj* self) {
    s8* p;

    if (M2C_FIELD(self, s8*, 0x67) != 0) {
        return;
    }
    if (M2C_FIELD(self, u8*, 0x80) & 1) {
        return;
    }
    if (M2C_FIELD(self, u8*, 0x82) != 0) {
        M2C_FIELD(self, u8*, 0x82)--;
        return;
    }
    for (p = D_800950A0; p < D_800950A0 + 0x1400; p += 0xA0) {
        if (OBJ(p)->active == 0 || OBJ(p)->id != 0) {
            continue;
        }
        if (self->unk15 != 0) {
            struct X4_PlayerObj* pl = &g_Player;
            if (pl->facing == 0 && self->x_pos.val < pl->x_pos.val &&
                ABS(OBJ(p)->y_pos.i.hi - self->y_pos.i.hi) < 0x18 &&
                OBJ(p)->x_pos.i.hi < self->x_pos.i.hi + 0x80) {
                M2C_FIELD(self, u8*, 0x80) |= 1;
            }
        } else {
            struct X4_PlayerObj* pl = &g_Player;
            if (pl->facing != 0 && self->x_pos.val > pl->x_pos.val &&
                ABS(OBJ(p)->y_pos.i.hi - self->y_pos.i.hi) < 0x18 &&
                self->x_pos.i.hi - 0x80 < OBJ(p)->x_pos.i.hi) {
                M2C_FIELD(self, u8*, 0x80) |= 1;
            }
        }
        if (M2C_FIELD(self, u8*, 0x80) & 1) {
            self->action = 3;
            self->action_phase = 0;
            set_animation(self, 5);
            return;
        }
    }
}
#undef func_800EA9E0
#undef D_800950A0

// clang-format off
INCLUDE_ASM("asm/rock_10/nonmatchings/E9860", func_800F1C10);

INCLUDE_ASM("asm/rock_10/nonmatchings/E9860", func_800F1D4C);

INCLUDE_ASM("asm/rock_10/nonmatchings/E9860", func_800F1E8C);
// clang-format on

#define func_80041AB8 func_800F1FD8
#define D_80075FD8 D_800FC64C
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

// clang-format off
INCLUDE_ASM("asm/rock_10/nonmatchings/E9860", func_800F2014);
// clang-format on

#define func_800EB070 func_800F20B4
#include "../shared/rock_06/func_800EB070.c"
#undef func_800EB070

#include "common.h"
#include "mmx6/globals.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK); /* extern */
M2C_UNK animate_object();              /* extern */
M2C_UNK apply_object_motion(void*);    /* extern */

void func_800F2150(void* arg0) {
    ((M2C_UNK(*)())animate_object)();
    if (M2C_FIELD(arg0, s8*, 6) == 0) {
        M2C_FIELD(arg0, M2C_UNK**, 0x58) = &D_800743DC;
        apply_object_motion(arg0);
        if (M2C_FIELD(arg0, u8*, 0x70) & 8) {
            set_animation(arg0, 4);
            M2C_FIELD(arg0, s32*, 0x24) = 0;
            M2C_FIELD(arg0, s32*, 0x2C) = 0;
            M2C_FIELD(arg0, s32*, 0x20) = 0;
            M2C_FIELD(arg0, s32*, 0x28) = 0;
            M2C_FIELD(arg0, s8*, 6) = (s8)((u8)M2C_FIELD(arg0, s8*, 6) + 1);
        }
    } else if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        set_animation(arg0, 1);
        M2C_FIELD(arg0, s8*, 5) = 1;
        M2C_FIELD(arg0, s8*, 6) = 0;
        M2C_FIELD(arg0, s8*, 0x67) = 0;
    }
}

#include "common.h"

#define NULL ((void*)0)
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK set_animation(void*, M2C_UNK);       /* extern */
M2C_UNK animate_object();                    /* extern */
void* func_8002C458();                       /* extern */

void func_800F21F8(void* arg0) {
    void* temp_v0;

    ((M2C_UNK(*)())animate_object)();
    if (M2C_FIELD(arg0, s8*, 0x45) != 0) {
        M2C_FIELD(arg0, s8*, 0x45) = 0;
        temp_v0 = func_8002C458();
        if (temp_v0 != NULL) {
            play_sound(2, 0x2E, arg0);
            M2C_FIELD(temp_v0, s8*, 0) = 0x41;
            M2C_FIELD(temp_v0, s8*, 1) = 0x20;
            M2C_FIELD(temp_v0, s32*, 8) = (s32)M2C_FIELD(arg0, s32*, 8);
            M2C_FIELD(temp_v0, s32*, 0xC) = (s32)M2C_FIELD(arg0, s32*, 0xC);
            M2C_FIELD(temp_v0, s32*, 0x3C) = (s32)M2C_FIELD(arg0, s32*, 0x3C);
            M2C_FIELD(temp_v0, u16*, 0x40) = (u16)M2C_FIELD(arg0, u16*, 0x40);
            M2C_FIELD(temp_v0, u16*, 0x42) = (u16)M2C_FIELD(arg0, u16*, 0x42);
            M2C_FIELD(temp_v0, u8*, 0x14) = (u8)M2C_FIELD(arg0, u8*, 0x14);
            M2C_FIELD(temp_v0, s32*, 0x30) = (s32)M2C_FIELD(arg0, s32*, 0x30);
            M2C_FIELD(temp_v0, u8*, 0x15) = (u8)M2C_FIELD(arg0, u8*, 0x15);
        }
    }
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        M2C_FIELD(arg0, s8*, 5) = 1;
        M2C_FIELD(arg0, s8*, 6) = 0;
        set_animation(arg0, 1);
        M2C_FIELD(arg0, s8*, 0x83) = 0x78;
        M2C_FIELD(arg0, u8*, 0x80) = (u8)(M2C_FIELD(arg0, u8*, 0x80) & 0xFD);
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_10/nonmatchings/E9860", func_800F22FC);
// clang-format on

#include "../shared/rock_10/func_800F23E4.c"

#define func_80041AB8 func_800F2424
#define D_80075FD8 D_800FC668
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

// clang-format off
INCLUDE_ASM("asm/rock_10/nonmatchings/E9860", func_800F2460);
// clang-format on

#define func_800EB4D4 func_800F2518
#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();
s32 is_off_screen(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK move_object(s32);
M2C_UNK func_8002EE10(void*);
s32 func_80030ECC();
s32 check_enemy_hits(void*);
M2C_UNK func_80049D90(void*);

void func_800F2518(void* arg0) {
    s32 st;

    ((M2C_UNK(*)())animate_object)();
    move_object(arg0);
    if (func_80030ECC(arg0) != 0) {
        st = 2;
        // !FAKE: inherited from src/shared/rock_06/func_800EB4D4.c
        goto store;
    }
    if (check_enemy_hits(arg0) < 0) {
        st = 2;
        // !FAKE: inherited from src/shared/rock_06/func_800EB4D4.c
        goto store;
    }
    if (M2C_FIELD(arg0, u8*, 0x70) != 0 ||
        (func_8002EE10(arg0), M2C_FIELD(arg0, u8*, 0x70) != 0)) {
        func_80049D90(arg0);
        M2C_FIELD(arg0, u8*, 4) = M2C_FIELD(arg0, u8*, 4) + 1;
        return;
    }
    if (is_off_screen(arg0, 0x20, 0x20) == 0) {
        func_8002CCB0(arg0, 0x10, 0x10);
        return;
    }
    st = M2C_FIELD(arg0, u8*, 4) + 1;
store:
    M2C_FIELD(arg0, u8*, 4) = st;
}
#undef func_800EB4D4

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800F25E0(void) {
    clear_object_slot();
}

#define func_800ECAB8 func_800F2600
#define g_class4_slots g_class4_slots
#include "../shared/rock_06/func_800ECAB8.c"
#undef func_800ECAB8
#undef g_class4_slots

// clang-format off
INCLUDE_ASM("asm/rock_10/nonmatchings/E9860", func_800F2734);

INCLUDE_ASM("asm/rock_10/nonmatchings/E9860", func_800F29BC);

INCLUDE_ASM("asm/rock_10/nonmatchings/E9860", func_800F2BE4);

INCLUDE_ASM("asm/rock_10/nonmatchings/E9860", func_800F35F8);

INCLUDE_ASM("asm/rock_10/nonmatchings/E9860", func_800F37E4);

INCLUDE_ASM("asm/rock_10/nonmatchings/E9860", func_800F3B98);
// clang-format on

#include "../shared/rock_10/func_800F3BF8.c"

#include "common.h"

void func_800F3C98(void) {
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define FLD_F3CA0(expr, type, offset) (*(type*)((u8*)(expr) + (offset)))

s32 is_off_screen(void*, M2C_UNK, M2C_UNK);
s32 func_8002DCF4(void*, void*);
s32 check_enemy_hits(void*);

extern struct X4_PlayerObj g_Player;

void func_800F3CA0(void* arg0) {
    struct X4_PlayerObj* pl;
    void* tgt;
    s32 r;
    s32 q;
    s32 t;
    s32 c;

    pl = &g_Player;
    if (FLD_F3CA0(pl, s8, 0xD5) == 0) {
        tgt = pl;
    } else {
        tgt = &D_800CD340;
        if (FLD_F3CA0(tgt, s8, 0x5) == 0) {
            tgt = (u8*)tgt + 0xB0;
        }
    }
    do {
        FLD_F3CA0(arg0, u8, 0x5C) = 0x7F;
        FLD_F3CA0(arg0, s32, 0x18) = FLD_F3CA0(arg0, s32, 0x8);
        FLD_F3CA0(arg0, s32, 0x1C) = FLD_F3CA0(arg0, s32, 0xC);
        q = check_enemy_hits(arg0);
        FLD_F3CA0(arg0, u16, 0x42) &= 0x7FFF;
    } while (0);
    r = q;
    c = FLD_F3CA0(arg0, s16, 0x7C);
    t = FLD_F3CA0(arg0, u16, 0x7C);
    if (c == 0) {
        if (r > 0) {
            r -= 1;
            if (r == 0x2C) {
                FLD_F3CA0(arg0, u8, 0x3) = 1;
                FLD_F3CA0(arg0, s16, 0x7C) = 0x96;
                return;
            }
        }
        if (func_8002DCF4(arg0, tgt) != 0) {
            FLD_F3CA0(arg0, u8, 0x3) = 1;
            FLD_F3CA0(arg0, s16, 0x7C) = 0x96;
            FLD_F3CA0(arg0, s16, 0x7E) = 1;
            return;
        }
    } else {
        FLD_F3CA0(arg0, s16, 0x7C) = t - 1;
        if (FLD_F3CA0(arg0, s16, 0x7C) >= 0x1F) {
            if (FLD_F3CA0(arg0, s16, 0x7E) == 1 &&
                func_8002DCF4(arg0, tgt) == 0) {
                FLD_F3CA0(arg0, s16, 0x7C) = 0x3C;
                FLD_F3CA0(arg0, s16, 0x7E) = 0;
            }
        } else if (FLD_F3CA0(arg0, s16, 0x7C) & 1) {
            FLD_F3CA0(arg0, u8, 0x3) = 1;
        } else {
            FLD_F3CA0(arg0, u8, 0x3) = 0;
        }
        if (FLD_F3CA0(arg0, s16, 0x7C) == 0) {
            FLD_F3CA0(arg0, u8, 0x3) = 0;
            FLD_F3CA0(arg0, s16, 0x7E) = 0;
        }
    }
    if (is_off_screen(arg0, 0x50, 0xA0) == 1) {
        FLD_F3CA0(arg0, u8, 0x4) = 2;
    }
}
#undef FLD_F3CA0

#define func_800EA1D8 func_800F3E2C
#define D_800FAA64 D_800FC6E4
#include "../shared/d1000/func_800EA1D8.c"
#undef func_800EA1D8
#undef D_800FAA64

// clang-format off
INCLUDE_ASM("asm/rock_10/nonmatchings/E9860", func_800F3E78);
// clang-format on

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002CA54(); /* extern */

void func_800F3F34(void) {
    func_8002CA54();
}

// clang-format off
INCLUDE_ASM("asm/rock_10/nonmatchings/E9860", func_800F3F54);
// clang-format on

#define func_800EA224 func_800F40FC
#define g_Player g_Player
#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK animate_object();
M2C_UNK move_object(s32);
extern struct X4_PlayerObj g_Player;

#define EA_U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define EA_S16(p, o) (*(s16*)((u8*)(p) + (o)))
#define EA_S32(p, o) (*(s32*)((u8*)(p) + (o)))

void func_800F40FC(void* arg0) {
    struct X4_PlayerObj* p;
    s16 y;
    s16 x;
    s32 ang;
    s32 c;
    s32 t;
    s32 v;

    if (g_Player.x_pos.i.hi > EA_S16(arg0, 0xA)) {
        EA_U8(arg0, 0x15) = 0x40;
    } else {
        EA_U8(arg0, 0x15) = 0;
    }
    p = &g_Player;
    y = p->y_pos.i.hi + EA_S16(arg0, 0x82);
    x = p->x_pos.i.hi + EA_S16(arg0, 0x80);
    ang = ratan2(y - EA_S16(arg0, 0xE), x - EA_S16(arg0, 0xA));
    c = rcos(ang);
    v = c * 16;
    EA_S32(arg0, 0x20) = c * 64 + v;
    c = -rsin(ang);
    v = c * 16;
    EA_S32(arg0, 0x24) = c * 64 + v;
    if (((EA_S16(arg0, 0xA) - x >= 0) ? (EA_S16(arg0, 0xA) - x)
                                      : (x - EA_S16(arg0, 0xA))) < 0x10 &&
        ((EA_S16(arg0, 0xE) - y >= 0) ? (EA_S16(arg0, 0xE) - y)
                                      : (y - EA_S16(arg0, 0xE))) < 0x20) {
        EA_S32(arg0, 0x20) = 0;
        EA_S32(arg0, 0x24) = 0;
        if (!(*(u8*)&D_80097420 & 1)) {
            t = (EA_U8(arg0, 0x84) + 1) & 0x3F;
            EA_U8(arg0, 0x84) = t;
            EA_S16(arg0, 0xE) += rsin(t << 7) / 2096;
        }
    }
    animate_object(arg0);
    move_object(arg0);
}
#undef func_800EA224
#undef g_Player

#define func_80048DC8 func_800F42AC
#define D_80077BC0 D_800FC718
#include "../shared/d1000/func_80048DC8.c"
#undef func_80048DC8
#undef D_80077BC0

#define func_800EA420 func_800F42F8
#define D_800F3D58 D_800FC728
#include "../shared/rock_05/func_800EA420.c"
#undef func_800EA420
#undef D_800F3D58

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800F43F4(void) {
    clear_object_slot();
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK clear_object_slot(); /* extern */

void func_800F4414(void* arg0) {
    u16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u16*, 0x7C);
    M2C_FIELD(arg0, u16*, 0x7C) = (u16)(temp_v0 + 1);
    if ((s16)temp_v0 < 0x3C) {
        M2C_FIELD(arg0, u8*, 3) = (u8)(M2C_FIELD(arg0, u8*, 3) ^ 1);
        return;
    }
    clear_object_slot();
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object(); /* extern */

M2C_UNK move_object(s32);
void func_800F4468(struct MainObj* arg0) {
    arg0->x_speed = 0;
    arg0->y_speed = 0x50000;
    ((M2C_UNK(*)())animate_object)();
    ((M2C_UNK(*)())move_object)(arg0);
}

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SCRATCH_9C (*(s32**)0x1F80009C)

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK set_animation(void*, M2C_UNK);       /* extern */
#define SET_ANIM(o, n) ((void (*)(void*, s32))set_animation)((o), (n))
extern M2C_UNK D_8007433C;
extern s8 D_800CCEDC;
extern M2C_UNK D_800FC734;
extern M2C_UNK D_800FC738;
extern M2C_UNK D_800FC748;
extern M2C_UNK D_800FC74C;
extern M2C_UNK D_800FC750;
extern M2C_UNK D_800FC754;
extern M2C_UNK D_800FCBBC;
extern s32 D_800FD000;
extern s32 D_800FD004;

void func_800F44A0(void* arg0) {
    s32* tbl;
    s32 off;
    s8 sub;
    s32 kind;
    void* parent;
    s8 st;

    if (D_800CCEDC == 0xC && M2C_FIELD(arg0, s8*, 2) == 0) {
        tbl = SCRATCH_9C;
        off = *tbl;
        M2C_FIELD(arg0, s16*, 0x42) = 0x7948;
        M2C_FIELD(arg0, void**, 0x3C) = (u8*)tbl + off;
    }
    {
        // !FAKE: depin: dropping it breaks the match (254/261)
        register s32 m asm("$2");
        m = 0xA;
        M2C_FIELD(arg0, u8*, 0x60) = m;
    }
    M2C_FIELD(arg0, M2C_UNK**, 0x58) = &D_8007433C;
    M2C_FIELD(arg0, u8*, 0x5C) = 0;
    M2C_FIELD(arg0, u8*, 0x61) = 0;
    M2C_FIELD(arg0, u8*, 0x3) = 0;
    M2C_FIELD(arg0, u8*, 0x14) = D_800970B4;
    sub = M2C_FIELD(arg0, s8*, 2);
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, u8*, 0x67) = 0;
    M2C_FIELD(arg0, M2C_UNK**, 0x30) = &D_800FCBBC;
    kind = sub & 0xF0;
    if (kind == 0x00) {
        M2C_FIELD(arg0, s16*, 0x40) = 0x140;
        M2C_FIELD(arg0, u8*, 0x16) = 5;
        M2C_FIELD(arg0, M2C_UNK**, 0x50) = &D_800FC734;
        M2C_FIELD(arg0, M2C_UNK**, 0x54) = &D_800FC738;
        M2C_FIELD(arg0, s32*, 0x68) = 0;
        M2C_FIELD(arg0, u8*, 0x15) = 0;
        SET_ANIM(arg0, 4);
        D_800FD000 = 0;
        M2C_FIELD(arg0, s8*, 0x8A) = -1;
        M2C_FIELD(arg0, u8*, 0x8B) = 0;
        M2C_FIELD(arg0, u8*, 0x8C) = 0;
        M2C_FIELD(arg0, u8*, 0x8E) = 0;
        D_800FD004 = 0;
        M2C_FIELD(arg0, u8*, 0x4) = 1;
        M2C_FIELD(arg0, u8*, 0x5) = 8;
        M2C_FIELD(arg0, u8*, 0x6) = 0;
        M2C_FIELD(arg0, u8*, 0x7) = 0;
    } else if (kind == 0x10) {
        parent = M2C_FIELD(arg0, void**, 0x80);
        st = M2C_FIELD(parent, s8*, 4);
        if (st != 1) {
            M2C_FIELD(arg0, u8*, 0x4) = 7;
            M2C_FIELD(arg0, u8*, 0x3) = 0;
            return;
        }
        M2C_FIELD(arg0, u8*, 0x16) = 5;
        M2C_FIELD(arg0, u8*, 0x3) = st;
        switch (sub) {
        case 0x10:
            SET_ANIM(arg0, 0x18);
            M2C_FIELD(arg0, M2C_UNK**, 0x50) = &D_800FC748;
            M2C_FIELD(arg0, M2C_UNK**, 0x54) = &D_800FC74C;
            M2C_FIELD(arg0, u16*, 0xA) = M2C_FIELD(parent, u16*, 0xA);
            M2C_FIELD(arg0, u16*, 0xE) = M2C_FIELD(parent, u16*, 0xE) - 0x26;
            break;
        case 0x11:
            SET_ANIM(arg0, 0x19);
            M2C_FIELD(arg0, M2C_UNK**, 0x50) = &D_800FC750;
            M2C_FIELD(arg0, M2C_UNK**, 0x54) = &D_800FC754;
            M2C_FIELD(arg0, u16*, 0xA) = M2C_FIELD(parent, u16*, 0xA) - 0x26;
            M2C_FIELD(arg0, u16*, 0xE) = M2C_FIELD(parent, u16*, 0xE);
            break;
        case 0x12:
            SET_ANIM(arg0, 0x18);
            M2C_FIELD(arg0, M2C_UNK**, 0x50) = &D_800FC748;
            M2C_FIELD(arg0, M2C_UNK**, 0x54) = &D_800FC74C;
            M2C_FIELD(arg0, u16*, 0xA) = M2C_FIELD(parent, u16*, 0xA);
            M2C_FIELD(arg0, u16*, 0xE) = M2C_FIELD(parent, u16*, 0xE) + 0x26;
            break;
        case 0x13:
            SET_ANIM(arg0, 0x19);
            M2C_FIELD(arg0, M2C_UNK**, 0x50) = &D_800FC750;
            M2C_FIELD(arg0, M2C_UNK**, 0x54) = &D_800FC754;
            M2C_FIELD(arg0, u16*, 0xA) = M2C_FIELD(parent, u16*, 0xA) + 0x26;
            M2C_FIELD(arg0, u16*, 0xE) = M2C_FIELD(parent, u16*, 0xE);
            break;
        }
        M2C_FIELD(arg0, s32*, 0x68) = 0;
        M2C_FIELD(arg0, u8*, 0x15) = 0;
        M2C_FIELD(arg0, u8*, 0x4) = 3;
        M2C_FIELD(arg0, u8*, 0x5) = 2;
        M2C_FIELD(arg0, u8*, 0x6) = 0;
        M2C_FIELD(arg0, u8*, 0x7) = 0;
    } else if (kind == 0x20) {
        play_sound(2, 0x65, arg0);
        parent = M2C_FIELD(arg0, void**, 0x80);
        st = M2C_FIELD(parent, s8*, 4);
        if (st != 1) {
            M2C_FIELD(arg0, u8*, 0x4) = 7;
            M2C_FIELD(arg0, u8*, 0x3) = 0;
            return;
        }
        M2C_FIELD(arg0, u8*, 0x16) = 5;
        M2C_FIELD(arg0, u8*, 0x3) = st;
        SET_ANIM(arg0, 8);
        M2C_FIELD(arg0, M2C_UNK**, 0x50) = &D_800FC734;
        M2C_FIELD(arg0, M2C_UNK**, 0x54) = &D_800FC738;
        M2C_FIELD(arg0, s32*, 0x68) = 0;
        if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
            M2C_FIELD(arg0, u16*, 0xA) = M2C_FIELD(arg0, u16*, 0xA) + 0x20;
        } else {
            M2C_FIELD(arg0, u16*, 0xA) = M2C_FIELD(arg0, u16*, 0xA) - 0x20;
        }
        M2C_FIELD(arg0, u8*, 0x4) = 4;
        M2C_FIELD(arg0, u8*, 0x5) = 2;
        M2C_FIELD(arg0, u8*, 0x6) = 0;
        M2C_FIELD(arg0, u8*, 0x7) = 0;
    } else if (kind == 0x30) {
        parent = M2C_FIELD(arg0, void**, 0x80);
        st = M2C_FIELD(parent, s8*, 4);
        if (st != 1) {
            M2C_FIELD(arg0, u8*, 0x4) = 7;
            M2C_FIELD(arg0, u8*, 0x3) = 0;
            return;
        }
        switch (sub) {
        case 0x30:
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
            break;
        case 0x31:
            M2C_FIELD(arg0, u8*, 0x15) = 0;
            break;
        case 0x32:
            M2C_FIELD(arg0, u8*, 0x15) = 0;
            break;
        case 0x33:
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
            break;
        }
        M2C_FIELD(arg0, u8*, 0x16) = 5;
        M2C_FIELD(arg0, u8*, 0x3) = 1;
        SET_ANIM(arg0, 2);
        M2C_FIELD(arg0, M2C_UNK**, 0x50) = &D_800FC734;
        M2C_FIELD(arg0, M2C_UNK**, 0x54) = &D_800FC738;
        M2C_FIELD(arg0, s32*, 0x68) = 0;
        M2C_FIELD(arg0, u8*, 0x89) = 0;
        M2C_FIELD(arg0, u8*, 0x4) = 5;
        M2C_FIELD(arg0, u8*, 0x5) = 2;
        M2C_FIELD(arg0, u8*, 0x6) = 0;
        M2C_FIELD(arg0, u8*, 0x7) = 0;
    }
}

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

M2C_UNK animate_object();
M2C_UNK func_80030ECC();
s32 check_enemy_hits(void*);
extern M2C_UNK D_8007433C;
extern M2C_UNK D_80074E7C;
extern void (*D_800FCC80[])(void*);
extern s32 D_800FD000;

#define G(type, off) (*(type*)((u8*)self + (off)))

void func_800F48B4(void* self) {
    s32 r;
    u16 t;

    G(s32, 0x18) = G(s32, 0x8);
    G(s32, 0x1C) = G(s32, 0xC);
    ((M2C_UNK(*)())animate_object)();
    D_800FCC80[G(s8, 5)](self);
    if (G(s8, 5) != 8 && G(s8, 2) == 0) {
        D_800FD000++;
    }
    G(u8, 0x8D) = 0;
    r = check_enemy_hits(self);
    if (r < 0) {
        D_8009711A = 1;
        G(s8, 4) = 2;
        G(s8, 5) = 0;
        return;
    }
    if (r > 0) {
        if (r != 0x7F) {
            G(void*, 0x58) = &D_8007433C;
            if ((u32)(r - 0x19) < 2) {
                G(s16, 0x88) = 2;
            } else {
                G(s16, 0x88) = 0x1E;
            }
            if (r == 5 || r == 0xE || r == 0x24) {
                G(void*, 0x58) = &D_8007433C;
                G(u8, 0x8E) = 1;
                G(s16, 0x88) = 0x50;
                G(s8, 5) = 9;
                G(s8, 6) = 0;
            }
        } else {
            G(u8, 0x8D) = 1;
        }
    }
    t = G(u16, 0x88);
    if (G(s16, 0x88) != 0) {
        G(s16, 0x88) = t - 1;
        if (t & 2) {
            G(u16, 0x42) = G(u16, 0x42) | 0x8000;
        } else {
            G(u16, 0x42) = G(u16, 0x42) & 0x7FFF;
        }
        if (G(s16, 0x88) == 0) {
            G(u16, 0x42) = G(u16, 0x42) & 0x7FFF;
            if (G(u8, 0x8E) == 1) {
                G(void*, 0x58) = &D_8007433C;
                G(u8, 0x8E) = 0;
            } else {
                G(void*, 0x58) = &D_80074E7C;
            }
        }
    }
    func_80030ECC(self);
}

#undef G

// clang-format off
INCLUDE_ASM("asm/rock_10/nonmatchings/E9860", func_800F4A74);

INCLUDE_ASM("asm/rock_10/nonmatchings/E9860", func_800F4B9C);

INCLUDE_ASM("asm/rock_10/nonmatchings/E9860", func_800F4D7C);
// clang-format on

#include "../shared/rock_10/func_800F4F9C.c"

#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK move_object(s32);
extern M2C_UNK D_8007433C;
extern struct X4_PlayerObj g_Player;
extern s32 D_800FD004;

void func_800F50A0(void* arg0) {
    s32 ang;
    s32 d;

    {
        s32 px = g_Player.x_pos.i.hi;
        s32 py = g_Player.y_pos.i.hi;
        ang = ratan2(M2C_FIELD(arg0, s16*, 0xE) - py,
                     px - M2C_FIELD(arg0, s16*, 0xA));
    }
    M2C_FIELD(arg0, s32*, 0x20) = rcos(ang) << 4;
    M2C_FIELD(arg0, s32*, 0x24) = rsin(ang) << 4;
    d = g_Player.x_pos.i.hi - M2C_FIELD(arg0, s16*, 0xA);
    if (d >= 0) {
        d = d < 7;
    } else {
        d = M2C_FIELD(arg0, s16*, 0xA) - g_Player.x_pos.i.hi < 7;
    }
    if (d != 0) {
        d = g_Player.y_pos.i.hi - M2C_FIELD(arg0, s16*, 0xE);
        if (d >= 0) {
            if (d >= 7) {
                // !FAKE: goto keeps the block7/end order of the y range test; flag form and ternary moved bytes
                goto block7;
            }
        } else {
            if (M2C_FIELD(arg0, s16*, 0xE) - g_Player.y_pos.i.hi < 7) {
                // !FAKE: goto keeps the block7/end order of the y range test; flag form and ternary moved bytes
                goto end;
            }
            // !FAKE: goto keeps the block7/end order of the y range test; flag form and ternary moved bytes
            goto block7;
        }
        // !FAKE: goto keeps the block7/end order of the y range test; flag form and ternary moved bytes
        goto end;
    }
block7:
    if (M2C_FIELD(arg0, s32*, 0x20) >= 0) {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    } else {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
    }
    if (D_800FD004 != 0) {
        D_800FD004--;
    } else {
        move_object(arg0);
    }
end:
    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        set_animation(arg0, 6);
        {
            // !FAKE: depin: dropping it breaks the match (83/90)
            register void* p asm("$2") = &D_8007433C;
            M2C_FIELD(arg0, void**, 0x58) = p;
        }
        M2C_FIELD(arg0, u8*, 0x8E) = 1;
        M2C_FIELD(arg0, u8*, 7) = 0;
        M2C_FIELD(arg0, u8*, 6)++;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
s32 random_byte();
extern struct X4_PlayerObj g_Player;
extern struct X4_BackgroundObj background_objects[3];
extern M2C_UNK D_800FC734;
extern M2C_UNK D_800FC738;
void func_800F5208(struct X4_AnimatedObj* self) {
    s8 mode = ((s8*)self)[0x45];
    s16 x;

    if (mode == 1) {
        if (g_Player.x_pos.i.hi <= background_objects[0].x_pos.i.hi + 0xA0) {
            self->unk15 = 0;
            x = g_Player.x_pos.i.hi - 0x30;
            if (x - background_objects[0].x_pos.i.hi < 0x28) {
                x = background_objects[0].x_pos.i.hi + 0x28;
            }
            self->x_pos.i.hi = background_objects[0].x_pos.i.hi + 0x140 -
                               (x - background_objects[0].x_pos.i.hi);
        } else {
            self->unk15 = 0x40;
            x = g_Player.x_pos.i.hi + 0x30;
            if (x - background_objects[0].x_pos.i.hi > 0x108) {
                x = background_objects[0].x_pos.i.hi + 0x108;
            }
            self->x_pos.i.hi = background_objects[0].x_pos.i.hi + 0x140 -
                               (x - background_objects[0].x_pos.i.hi);
        }
        self->y_pos.i.hi = background_objects[0].y_pos.i.hi + 0x30;
        if (random_byte() & 1) {
            self->y_pos.i.hi = background_objects[0].y_pos.i.hi + 0x30;
        } else {
            self->y_pos.i.hi = background_objects[0].y_pos.i.hi + 0xA0;
        }
        set_animation(self, 0xE);
        {
            // !FAKE: depin: dropping it breaks the match (88/92)
            register s32* a asm("$2") = &D_800FC734;
            // !FAKE: depin: dropping it breaks the match (83/92)
            register s32* b asm("$3") = &D_800FC738;
            *(s32**)((u8*)self + 0x50) = a;
            *(s32**)((u8*)self + 0x54) = b;
        }
        self->unk7 = 3;
        self->action_phase++;
    } else if (mode == 2) {
        play_sound(2, 0x59, self);
    }
}

#include "../shared/rock_10/func_800F5378.c"

#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK move_object(s32);
extern M2C_UNK D_8007433C;
extern struct X4_BackgroundObj background_objects[3];

#define OFS_X M2C_FIELD(arg0, s16*, 0x84)
#define OFS_Y M2C_FIELD(arg0, s16*, 0x86)
#define ABS(x) ((x) < 0 ? -(x) : (x))

void func_800F55A0(struct X4_AnimatedObj* arg0) {
    s32 angle;
    s32 s;

    angle =
        ratan2(arg0->y_pos.i.hi - (background_objects[0].y_pos.i.hi + OFS_Y),
               (background_objects[0].x_pos.i.hi + OFS_X) - arg0->x_pos.i.hi);
    arg0->x_vel.val = rcos(angle) << 6;
    s = rsin(angle);
    arg0->y_vel.val = s << 6;
    if (D_800CCF38 >= 2) {
        arg0->x_vel.val = arg0->x_vel.val * 5 / 4;
        arg0->y_vel.val = arg0->y_vel.val * 5 / 4;
    }
    if (arg0->y_vel.val > 0) {
        if (arg0->x_vel.val != 0) {
            set_animation(arg0, 0x25);
        } else {
            set_animation(arg0, 0x27);
        }
    } else if (arg0->y_vel.val < 0) {
        if (arg0->x_vel.val != 0) {
            set_animation(arg0, 0x26);
        } else {
            set_animation(arg0, 0x28);
        }
    } else {
        set_animation(arg0, 0x25);
    }
    if (arg0->unk17 == 0x27 || arg0->unk17 == 0x28) {
        if (arg0->x_pos.i.hi - background_objects[0].x_pos.i.hi < 0xA0) {
            arg0->unk15 = 0x40;
        } else {
            arg0->unk15 = 0;
        }
    } else if (arg0->x_vel.val >= 0) {
        arg0->unk15 = 0x40;
    } else {
        arg0->unk15 = 0;
    }
    ((void (*)(struct X4_AnimatedObj*))move_object)(arg0);
    if (ABS(OFS_X - (arg0->x_pos.i.hi - background_objects[0].x_pos.i.hi)) <
        4) {
        if (ABS(OFS_Y - (arg0->y_pos.i.hi - background_objects[0].y_pos.i.hi)) <
            4) {
            arg0->x_pos.i.hi = background_objects[0].x_pos.i.hi + OFS_X;
            arg0->y_pos.i.hi = background_objects[0].y_pos.i.hi + OFS_Y;
            M2C_FIELD(arg0, s16*, 0x7E)++;
            if (M2C_FIELD(arg0, s16*, 0x7E) >= 4) {
                ((void (*)(void*, s32))set_animation)(arg0, 6);
                M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
                M2C_FIELD(arg0, u8*, 0x8E) = 1;
                arg0->unk7 = 0;
                arg0->action_phase++;
                return;
            }
            set_animation(arg0, 0x11);
            play_sound(2, 0x5A, arg0);
            M2C_FIELD(arg0, s32*, 0x50) = 0;
            M2C_FIELD(arg0, s32*, 0x54) = 0;
            arg0->action_phase = 4;
        }
    }
}

#undef OFS_X
#undef OFS_Y
#undef ABS

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void set_boss_level();
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
void func_800F74D8(void* arg0, s16 arg1, s16 arg2, u8 arg3);
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj g_playthrough_state;
extern u8 D_800E9E28[];

void func_800F5880(struct X4_AnimatedObj* arg0) {
    u8 sp10[4];
    s32 x;
    s32 y;

    __builtin_memcpy(sp10, D_800E9E28, 4);
    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        func_8003D308(0x14, 0x40);
    }
    if (*M2C_FIELD(arg0, s8**, 0x80) == 0) {
        g_playthrough_state.enable_boss = 1;
        g_playthrough_state.unk25 = 0;
        g_playthrough_state.boss_ptr = (struct X4_MainObj*)arg0;
        set_boss_level();
        M2C_FIELD(&g_playthrough_state, u8*, 0x8C) =
            sp10[M2C_FIELD(&g_playthrough_state, u8*, 0x8F)] + 0x20;
        x = (u16)background_objects[0].x_pos.i.hi + 0xF0;
        arg0->x_pos.i.hi = x;
        y = (u16)background_objects[0].y_pos.i.hi + 0x90;
        arg0->y_pos.i.hi = y;
        arg0->unk18.val = arg0->x_pos.val;
        arg0->unk1C.val = arg0->y_pos.val;
        func_800F74D8(arg0, x, y, 0);
        arg0->unk7 = 0;
        arg0->action_phase++;
    }
}

#include "../shared/rock_10/func_800F5990.c"

#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK move_object(s32);
extern struct X4_BackgroundObj background_objects[3];

#define ABS_LT7(d) (((d) < 0 ? -(d) : (d)) < 7)

void func_800F5AF0(struct X4_AnimatedObj* arg0) {
    s16 ox;
    s16 oy;
    s32 angle;
    s32 v;
    s32 t;
    s32 d;

    switch (arg0->unk2) {
    case 0x30:
        ox = 0x120;
        oy = 0x20;
        break;
    case 0x31:
        ox = 0x20;
        oy = 0x20;
        break;
    case 0x32:
        ox = 0x20;
        oy = 0x90;
        break;
    case 0x33:
        ox = 0x120;
        oy = 0x90;
        break;
    }
    angle = ratan2(arg0->y_pos.i.hi - (background_objects[0].y_pos.i.hi + oy),
                   (background_objects[0].x_pos.i.hi + ox) - arg0->x_pos.i.hi);
    do {
        v = rcos(angle);
        t = v * 16;
        arg0->x_vel.val = (v * 32 + t) * 2;
        v = rsin(angle);
        t = v * 16;
        arg0->y_vel.val = (v * 32 + t) * 2;
    } while (0);
    v = arg0->x_vel.val;
    if (v >= 0) {
        arg0->unk15 = 0x40;
    } else {
        arg0->unk15 = 0;
    }
    ((void (*)(struct X4_AnimatedObj*))move_object)(arg0);
    d = arg0->x_pos.i.hi - background_objects[0].x_pos.i.hi;
    if (ABS_LT7(ox - d)) {
        if (ABS_LT7(oy -
                    (arg0->y_pos.i.hi - background_objects[0].y_pos.i.hi))) {
            arg0->x_pos.i.hi = background_objects[0].x_pos.i.hi + ox;
            arg0->y_pos.i.hi = background_objects[0].y_pos.i.hi + oy;
            switch (arg0->unk2) {
            case 0x30:
                ((void (*)(void*, s32))set_animation)(arg0, 0x23);
                arg0->unk15 = 0;
                break;
            case 0x31:
                ((void (*)(void*, s32))set_animation)(arg0, 0x23);
                arg0->unk15 = 0x40;
                break;
            case 0x32:
                ((void (*)(void*, s32))set_animation)(arg0, 0x24);
                arg0->unk15 = 0x40;
                break;
            case 0x33:
                ((void (*)(void*, s32))set_animation)(arg0, 0x24);
                arg0->unk15 = 0;
                break;
            }
            arg0->action++;
        }
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_10/nonmatchings/E9860", func_800F5D58);

INCLUDE_ASM("asm/rock_10/nonmatchings/E9860", func_800F5F04);
// clang-format on

#include "common.h"
#include "psyq/libgte.h"
#include "mmx6/globals.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
extern M2C_UNK D_8007433C;
extern struct X4_PlayerObj g_Player;
extern s16 D_80097202;
extern s32 D_800FCF28;
extern s32 D_800FCF2C;
extern s32 D_800FCF30;
extern s32 D_800FCF34;
extern s32 D_800FCF38;
extern s32 D_800FCF3C;

void func_800F60AC(void* arg0) {
    s32 k;
    s8 t;
    s8 sub;
    s32 ang;
    s32 c;
    s32 dx;
    s32 dy;
    void* g;

    t = M2C_FIELD(M2C_FIELD(arg0, void**, 0x7C), s8*, 4);
    if (t != 1) {
        M2C_FIELD(arg0, u8*, 4) = 3;
        M2C_FIELD(arg0, u8*, 3) = 0;
        return;
    }
    M2C_FIELD(arg0, u8*, 0x60) = 0;
    M2C_FIELD(arg0, u8*, 0x5C) = t;
    M2C_FIELD(arg0, u8*, 0x16) = 4;
    M2C_FIELD(arg0, u8*, 0x67) = t;
    M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
    M2C_FIELD(arg0, void**, 0x68) = 0;
    M2C_FIELD(arg0, void**, 0x50) = 0;
    M2C_FIELD(arg0, void**, 0x54) = 0;
    M2C_FIELD(arg0, u8*, 4) = t;
    M2C_FIELD(arg0, u8*, 5) = 0;
    M2C_FIELD(arg0, u8*, 6) = 0;
    M2C_FIELD(arg0, u8*, 7) = 0;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    k = M2C_FIELD(arg0, s8*, 2) & 0xF0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    if (k == 0) {
        set_animation(arg0, 3);
        M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
        M2C_FIELD(arg0, void**, 0x54) = &D_800FCF28;
        M2C_FIELD(arg0, void**, 0x50) = &D_800FCF2C;
        M2C_FIELD(arg0, u8*, 0x60) = 8;
        if (M2C_FIELD(arg0, s8*, 2) == 0) {
            M2C_FIELD(arg0, u8*, 0x16) = 4;
            M2C_FIELD(arg0, s32*, 0x24) = 0;
            if (M2C_FIELD(arg0, s16*, 0xA) >= D_80097202 + 0xA0) {
                M2C_FIELD(arg0, u8*, 0x15) = 0;
                M2C_FIELD(arg0, s32*, 0x20) = -0x20000;
            } else {
                M2C_FIELD(arg0, u8*, 0x15) = 0x40;
                M2C_FIELD(arg0, s32*, 0x20) = 0x20000;
            }
            M2C_FIELD(arg0, u8*, 5) = 1;
        } else {
            M2C_FIELD(arg0, u8*, 0x16) = 4;
            if (M2C_FIELD(arg0, s16*, 0xA) >= D_80097202 + 0xA0) {
                M2C_FIELD(arg0, u8*, 0x15) = 0;
            } else {
                M2C_FIELD(arg0, u8*, 0x15) = 0x40;
            }
            M2C_FIELD(arg0, u8*, 5) = 2;
        }
    } else if (k == 0x10) {
        play_sound(2, 0x58, arg0);
        set_animation(arg0, 0x1C);
        M2C_FIELD(arg0, u8*, 0x60) = 4;
        M2C_FIELD(arg0, void**, 0x58) = &D_8007429C;
        M2C_FIELD(arg0, void**, 0x54) = &D_800FCF30;
        M2C_FIELD(arg0, void**, 0x50) = &D_800FCF34;
        M2C_FIELD(arg0, u8*, 0x16) = 4;
        M2C_FIELD(arg0, u8*, 0x15) = 0;
        switch (M2C_FIELD(arg0, s8*, 2)) {
        case 0x10:
            M2C_FIELD(arg0, s32*, 0x20) = 0;
            M2C_FIELD(arg0, s32*, 0x24) = 0x20000;
            break;
        case 0x11:
            M2C_FIELD(arg0, s32*, 0x20) = -0x20000;
            M2C_FIELD(arg0, s32*, 0x24) = 0;
            break;
        case 0x12:
            M2C_FIELD(arg0, s32*, 0x20) = 0;
            M2C_FIELD(arg0, s32*, 0x24) = -0x20000;
            break;
        case 0x13:
            M2C_FIELD(arg0, s32*, 0x20) = 0x20000;
            M2C_FIELD(arg0, s32*, 0x24) = 0;
            break;
        }
        if (D_800CCF38 >= 2) {
            M2C_FIELD(arg0, s32*, 0x20) = M2C_FIELD(arg0, s32*, 0x20) * 3 / 2;
            M2C_FIELD(arg0, s32*, 0x24) = M2C_FIELD(arg0, s32*, 0x24) * 3 / 2;
        }
        M2C_FIELD(arg0, u8*, 5) = 3;
    } else if (k == 0x20) {
        set_animation(arg0, 3);
        M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
        sub = M2C_FIELD(arg0, s8*, 2);
        M2C_FIELD(arg0, void**, 0x54) = &D_800FCF28;
        M2C_FIELD(arg0, void**, 0x50) = &D_800FCF2C;
        M2C_FIELD(arg0, u8*, 0x60) = 8;
        M2C_FIELD(arg0, u8*, 0x16) = 4;
        if (sub == 0x20) {
            M2C_FIELD(arg0, u8*, 5) = 4;
        } else if (sub == 0x21) {
            M2C_FIELD(arg0, u8*, 5) = 5;
        }
    } else if (k == 0x30) {
        play_sound(2, 0x58, arg0);
        set_animation(arg0, 0x22);
        M2C_FIELD(arg0, u8*, 3) = t;
        M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
        M2C_FIELD(arg0, void**, 0x54) = 0;
        M2C_FIELD(arg0, void**, 0x50) = &D_800FCF38;
        M2C_FIELD(arg0, void**, 0x68) = &D_800FCF3C;
        M2C_FIELD(arg0, u8*, 0x60) = 8;
        M2C_FIELD(arg0, u8*, 0x16) = 4;
        g = &g_Player;
        dx = M2C_FIELD(g, s16*, 0xA);
        dy = M2C_FIELD(g, s16*, 0xE);
        ang = ratan2(M2C_FIELD(arg0, s16*, 0xE) - dy,
                     dx - M2C_FIELD(arg0, s16*, 0xA));
        M2C_FIELD(arg0, s32*, 0x20) = rcos(ang) << 5;
        c = rsin(ang);
        M2C_FIELD(arg0, s32*, 0x24) = c << 5;
        if (D_800CCF38 >= 2) {
            M2C_FIELD(arg0, s32*, 0x24) = c << 6;
            M2C_FIELD(arg0, s32*, 0x20) = M2C_FIELD(arg0, s32*, 0x20) * 2;
        }
        if (M2C_FIELD(arg0, s32*, 0x20) != 0) {
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        } else {
            M2C_FIELD(arg0, u8*, 0x15) = 0;
        }
        M2C_FIELD(arg0, u8*, 5) = 6;
    }
}

#include "../shared/rock_10/func_800F6484.c"

#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK move_object(s32);
extern struct X4_BackgroundObj background_objects[3];

#define ABS_LT5(d) (((d) < 0 ? -(d) : (d)) < 5)

void func_800F65DC(struct X4_ShotObj* arg0) {
    struct X4_WeaponObj* w = arg0->unk7C;
    s32 angle;

    if (arg0->unk15 == 0) {
        s32 dy = arg0->y_pos.i.hi - 0x40;
        s32 dx = arg0->x_pos.i.hi - 0x40;
        angle = ratan2(dy - background_objects[0].y_pos.i.hi,
                       background_objects[0].x_pos.i.hi - dx);
    } else {
        s32 dy = arg0->y_pos.i.hi - 0x40;
        s32 dx = arg0->x_pos.i.hi - 0x110;
        angle = ratan2(dy - background_objects[0].y_pos.i.hi,
                       background_objects[0].x_pos.i.hi - dx);
    }
    arg0->x_vel.val = rcos(angle) << 6;
    arg0->y_vel.val = rsin(angle) << 6;
    do {
        ((void (*)(struct X4_ShotObj*))move_object)(arg0);
    } while (0);
    if (arg0->unk15 == 0) {
        s32 dx = arg0->x_pos.i.hi - 0x40;
        if (ABS_LT5(background_objects[0].x_pos.i.hi - dx)) {
            s32 dy = arg0->y_pos.i.hi - 0x40;
            if (ABS_LT5(background_objects[0].y_pos.i.hi - dy)) {
                w->unk7 = 4;
                arg0->unk50.data = 0;
                arg0->unk54 = 0;
                arg0->on_screen = 0;
                arg0->state = 3;
            }
        }
    } else {
        s32 dx = arg0->x_pos.i.hi - 0x110;
        if (ABS_LT5(background_objects[0].x_pos.i.hi - dx)) {
            s32 dy = arg0->y_pos.i.hi - 0x40;
            if (ABS_LT5(background_objects[0].y_pos.i.hi - dy)) {
                w->unk7 = 4;
                arg0->unk50.data = 0;
                arg0->unk54 = 0;
                arg0->on_screen = 0;
                arg0->state = 3;
            }
        }
    }
}

#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK move_object(s32);
extern struct X4_BackgroundObj background_objects[3];

#define ABS_LT5(d) (((d) < 0 ? -(d) : (d)) < 5)

void func_800F6794(struct X4_AnimatedObj* arg0) {
    s32 angle;

    if (arg0->unk15 == 0) {
        s32 dy = arg0->y_pos.i.hi - 0x40;
        s32 dx = arg0->x_pos.i.hi - 0x40;
        angle = ratan2(dy - background_objects[0].y_pos.i.hi,
                       background_objects[0].x_pos.i.hi - dx);
    } else {
        s32 dy = arg0->y_pos.i.hi - 0x40;
        s32 dx = arg0->x_pos.i.hi - 0x110;
        angle = ratan2(dy - background_objects[0].y_pos.i.hi,
                       background_objects[0].x_pos.i.hi - dx);
    }
    arg0->x_vel.val = rcos(angle) << 6;
    arg0->y_vel.val = rsin(angle) << 6;
    do {
        ((void (*)(struct X4_AnimatedObj*))move_object)(arg0);
    } while (0);
    if (arg0->unk15 == 0) {
        s32 dx = arg0->x_pos.i.hi - 0x40;
        if (ABS_LT5(background_objects[0].x_pos.i.hi - dx)) {
            s32 dy = arg0->y_pos.i.hi - 0x40;
            if (ABS_LT5(background_objects[0].y_pos.i.hi - dy)) {
                arg0->x_pos.i.hi = background_objects[0].x_pos.i.hi + 0x40;
                arg0->y_pos.i.hi = background_objects[0].y_pos.i.hi + 0x40;
                arg0->action_phase++;
            }
        }
    } else {
        s32 dx = arg0->x_pos.i.hi - 0x110;
        if (ABS_LT5(background_objects[0].x_pos.i.hi - dx)) {
            s32 dy = arg0->y_pos.i.hi - 0x40;
            if (ABS_LT5(background_objects[0].y_pos.i.hi - dy)) {
                arg0->x_pos.i.hi = background_objects[0].x_pos.i.hi + 0x110;
                arg0->y_pos.i.hi = background_objects[0].y_pos.i.hi + 0x40;
                arg0->action_phase++;
            }
        }
    }
}

#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK move_object(s32);
extern struct X4_BackgroundObj background_objects[3];

#define ABS_LT5(d) (((d) < 0 ? -(d) : (d)) < 5)

void func_800F6978(struct X4_AnimatedObj* arg0) {
    s32 angle;

    if (arg0->unk15 == 0) {
        s32 dy = arg0->y_pos.i.hi - 0x90;
        s32 dx = arg0->x_pos.i.hi - 0x30;
        angle = ratan2(dy - background_objects[0].y_pos.i.hi,
                       background_objects[0].x_pos.i.hi - dx);
    } else {
        s32 dy = arg0->y_pos.i.hi - 0x90;
        s32 dx = arg0->x_pos.i.hi - 0x110;
        angle = ratan2(dy - background_objects[0].y_pos.i.hi,
                       background_objects[0].x_pos.i.hi - dx);
    }
    arg0->x_vel.val = rcos(angle) << 6;
    arg0->y_vel.val = rsin(angle) << 6;
    do {
        ((void (*)(struct X4_AnimatedObj*))move_object)(arg0);
    } while (0);
    if (arg0->unk15 == 0) {
        s32 dx = arg0->x_pos.i.hi - 0x30;
        if (ABS_LT5(background_objects[0].x_pos.i.hi - dx)) {
            s32 dy = arg0->y_pos.i.hi - 0x90;
            if (ABS_LT5(background_objects[0].y_pos.i.hi - dy)) {
                arg0->x_pos.i.hi = background_objects[0].x_pos.i.hi + 0x30;
                arg0->y_pos.i.hi = background_objects[0].y_pos.i.hi + 0x90;
                arg0->action_phase++;
            }
        }
    } else {
        s32 dx = arg0->x_pos.i.hi - 0x110;
        if (ABS_LT5(background_objects[0].x_pos.i.hi - dx)) {
            s32 dy = arg0->y_pos.i.hi - 0x90;
            if (ABS_LT5(background_objects[0].y_pos.i.hi - dy)) {
                arg0->x_pos.i.hi = background_objects[0].x_pos.i.hi + 0x110;
                arg0->y_pos.i.hi = background_objects[0].y_pos.i.hi + 0x90;
                arg0->action_phase++;
            }
        }
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_10/nonmatchings/E9860", func_800F6B5C);
// clang-format on

#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK start_pad_vibration(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK move_object(s32);
extern struct X4_BackgroundObj background_objects[3];

#define OFS_X(p) (((s16*)(p))[0x48])
#define OFS_Y(p) (((s16*)(p))[0x49])

void func_800F6D58(struct X4_AnimatedObj* self) {
    s32 angle;
    s32 d;
    s32 off;
    s32 st;
    s32 v;

    angle = ratan2(
        self->y_pos.i.hi - (background_objects[0].y_pos.i.hi + OFS_Y(self)),
        (background_objects[0].x_pos.i.hi + OFS_X(self)) - self->x_pos.i.hi);
    self->x_vel.val = (rcos(angle) << 4) * (self->unk7 / 2 + 6);
    self->y_vel.val = (rsin(angle) << 4) * (self->unk7 / 2 + 6);
    if (self->x_vel.val >= 0) {
        self->unk15 = 0x40;
    } else {
        self->unk15 = 0;
    }
    move_object(self);
    {
        // !FAKE: depin: dropping it breaks the match (120/123)
        register struct X4_BackgroundObj* bg asm("$2") = background_objects;
        d = self->x_pos.i.hi - bg->x_pos.i.hi;
    }
    off = OFS_X(self);
    v = off - d;
    if (v >= 0 ? v < 6 : d - off < 6) {
        off = OFS_Y(self);
        d = self->y_pos.i.hi - background_objects[0].y_pos.i.hi;
        v = off - d;
        if (v >= 0 ? v < 6 : d - off < 6) {
            self->x_pos.i.hi = background_objects[0].x_pos.i.hi + OFS_X(self);
            self->y_pos.i.hi = background_objects[0].y_pos.i.hi + OFS_Y(self);
            self->unk7++;
            if (self->unk7 >= 7) {
                self->unk7 = 0;
                st = (u8)self->action_phase + 1;
            } else {
                play_sound(2, 0x55, self);
                start_pad_vibration(6);
                st = (u8)self->action_phase;
                st--;
            }
            self->action_phase = st;
        }
    }
}

#undef OFS_X
#undef OFS_Y

#include "../shared/rock_10/func_800F6F44.c"

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SCR_9C (*(s32**)0x1F80009C)
#define SCR_20 (*(s32**)0x1F800020)

s32 func_8002A47C(s32);
void* func_8002C458();
void* func_800F77A0(void*, s32);
extern s16 D_80097202;
#define D_80097202 (*(u16*)&D_80097202)
extern s8 D_800CCEDC;

void func_800F71F4(void* arg0) {
    void* p;
    void* q;
    s16 e;
    u8 f;
    s16 x;

    p = func_8002C458();
    if (p != 0) {
        M2C_FIELD(p, u8*, 0) = 0x41;
        M2C_FIELD(p, u8*, 1) = 0x10;
        M2C_FIELD(p, u8*, 2) = 0x20;
        M2C_FIELD(p, u8*, 0x15) = M2C_FIELD(arg0, u8*, 0x15);
        M2C_FIELD(p, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
        M2C_FIELD(p, u8*, 0x14) = M2C_FIELD(arg0, u8*, 0x14);
        if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
            M2C_FIELD(p, s16*, 0xA) = M2C_FIELD(arg0, s16*, 0xA) - 0x10;
        } else {
            M2C_FIELD(p, s16*, 0xA) = M2C_FIELD(arg0, s16*, 0xA) + 0x10;
        }
        M2C_FIELD(p, s16*, 8) = 0;
        M2C_FIELD(p, s16*, 0xE) = M2C_FIELD(arg0, s16*, 0xE);
        M2C_FIELD(p, s16*, 0x40) = 0x540;
        M2C_FIELD(p, s16*, 0xC) = 0;
        M2C_FIELD(p, void**, 0x7C) = arg0;
        if (D_800CCEDC == 0xC) {
            M2C_FIELD(p, s16*, 0x42) = 0x794C;
            M2C_FIELD(p, void**, 0x3C) = (u8*)SCR_9C + SCR_9C[1];
        } else {
            M2C_FIELD(p, s16*, 0x42) =
                (((func_8002A47C(M2C_FIELD(arg0, s8*, 1)) + 1) * 4 + 0x20) %
                 16) |
                (((func_8002A47C(M2C_FIELD(arg0, s8*, 1)) + 9) / 4 + 0x1E0)
                 << 6);
            M2C_FIELD(p, void**, 0x3C) =
                (u8*)SCR_20 +
                SCR_20[func_8002A47C(M2C_FIELD(arg0, s8*, 1)) + 1];
        }
    }
    f = (M2C_FIELD(arg0, u8*, 0x15) == 0) << 6;
    {
        s32 t;
        t = M2C_FIELD(p, u16*, 0xA) - D_80097202 - 0x140;
        x = D_80097202 - t;
    }
    e = M2C_FIELD(p, s16*, 0xE);
    q = func_800F77A0(p, 0);
    if (q != 0) {
        M2C_FIELD(q, u8*, 0) = 0x41;
        M2C_FIELD(q, u8*, 1) = 0x10;
        M2C_FIELD(q, u8*, 2) = 0x21;
        M2C_FIELD(q, u8*, 0x15) = f;
        M2C_FIELD(q, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
        M2C_FIELD(q, u8*, 0x14) = M2C_FIELD(arg0, u8*, 0x14);
        M2C_FIELD(q, s16*, 0xA) = x;
        M2C_FIELD(q, s16*, 8) = 0;
        M2C_FIELD(q, s16*, 0xE) = e;
        M2C_FIELD(q, s16*, 0x40) = 0x540;
        M2C_FIELD(q, s16*, 0xC) = 0;
        M2C_FIELD(q, void**, 0x7C) = arg0;
        M2C_FIELD(q, void**, 0x8C) = p;
        if (D_800CCEDC == 0xC) {
            M2C_FIELD(q, s16*, 0x42) = 0x794C;
            M2C_FIELD(q, void**, 0x3C) = (u8*)SCR_9C + SCR_9C[1];
        } else {
            M2C_FIELD(q, s16*, 0x42) =
                (((func_8002A47C(M2C_FIELD(arg0, s8*, 1)) + 1) * 4 + 0x20) %
                 16) |
                (((func_8002A47C(M2C_FIELD(arg0, s8*, 1)) + 9) / 4 + 0x1E0)
                 << 6);
            M2C_FIELD(q, void**, 0x3C) =
                (u8*)SCR_20 +
                SCR_20[func_8002A47C(M2C_FIELD(arg0, s8*, 1)) + 1];
        }
    }
}
#undef D_80097202
#undef SCR_9C
#undef SCR_20

#include "../shared/rock_10/func_800F74D8.c"

#include "../shared/rock_10/func_800F765C.c"

// clang-format off
INCLUDE_ASM("asm/rock_10/nonmatchings/E9860", func_800F77A0);
// clang-format on

#include "../shared/rock_10/func_800F78AC.c"

#define func_80041AB8 func_800F792C
#define D_80075FD8 D_800FCCA8
#define FAMILY_FIELD 5
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#include "../shared/rock_10/func_800F7968.c"

#define func_800F2FB0 func_800F79F4
#include "../shared/rock_04/func_800F2FB0.c"
#undef func_800F2FB0

#include "../shared/rock_10/func_800F7AE8.c"

#include "../shared/rock_10/func_800F7BF0.c"

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 is_off_screen(void*, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK apply_object_motion(void*);         /* extern */

void func_800F7CD4(void* arg0) {
    u16 temp_v0;

    if (M2C_FIELD(arg0, s8*, 5) == 0) {
        M2C_FIELD(arg0, s8*, 5) = (s8)((u8)M2C_FIELD(arg0, s8*, 5) + 1);
        M2C_FIELD(arg0, u16*, 0x7C) = 0U;
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0x4200;
    }
    apply_object_motion(arg0);
    if (is_off_screen(arg0, 0x40, 0x40) == 0) {
        temp_v0 = M2C_FIELD(arg0, u16*, 0x7C);
        M2C_FIELD(arg0, u16*, 0x7C) = (u16)(temp_v0 + 1);
        if (temp_v0 & 1) {
            M2C_FIELD(arg0, s8*, 3) = 1;
            return;
        }
        M2C_FIELD(arg0, s8*, 3) = 0;
        return;
    }
    M2C_FIELD(arg0, s8*, 4) = 7;
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800F7D70(void) {
    clear_object_slot();
}

#define func_8003744C func_800F7D90
#define D_80073C1C D_800FCCB4
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/rock_10/func_800F7DCC.c"

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
void func_800F9E04(struct X4_AnimatedObj*);
extern s16 D_800970AA;
extern struct X4_BackgroundObj background_objects[3];

void func_800F7E24(struct X4_AnimatedObj* self) {
    struct X4_BackgroundObj* bg;
    // !FAKE: depin: dropping it breaks the match (43/55)
    register s32 x asm("$3");
    s32 u;
    s32 c;
    s32 d;
    s32 lim;
    s8 ev = self->animation_step.fields.event;

    if (ev == 1) {
        play_sound(2, 0x59, self);
        set_animation(self, 0xC);
        d = D_800970AA;
        bg = background_objects;
        lim = bg->x_pos.i.hi + 0xA0;
        c = d < lim;
        u = bg->x_pos.u.hi;
        if (c) {
            x = u + 0x100;
        } else {
            x = u + 0x40;
        }
        self->x_pos.i.hi = x;
        self->y_pos.i.hi = bg->y_pos.i.hi + 0x50;
        do {
            func_800F9E04(self);
        } while (0);
        self->action_phase++;
    } else if (ev == 2) {
        play_sound(2, 0x59, self);
    } else if (ev == 3) {
        play_sound(2, 0x51, self);
    }
}

#include "../shared/rock_10/func_800F7F00.c"

#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_800F5D58();
extern M2C_UNK D_8007433C;

void func_800F7F70(u8* arg0) {
    if (*(u8*)(arg0 + 0x8D) == 1) {
        set_animation(arg0, 0xD);
        *(s32*)(arg0 + 0x50) = 0;
        *(s32*)(arg0 + 0x54) = 0;
        *(u16*)(arg0 + 0x7E) += 1;
        *(u8*)(arg0 + 0x6) += 1;
        return;
    }
    if (--*(s16*)(arg0 + 0x7C) == 0) {
        *(void**)(arg0 + 0x58) = &D_8007433C;
        *(u8*)(arg0 + 0x8E) = 1;
        func_800F5D58(arg0);
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
s32 set_animation(void*, s32);
void func_800F9E04(struct X4_AnimatedObj*);
extern struct X4_BackgroundObj background_objects[3];

void func_800F7FFC(struct X4_AnimatedObj* self) {
    s8 mode = ((s8*)self)[0x45];
    struct X4_BackgroundObj* bg;

    if (mode == 1) {
        play_sound(2, 0x59, self);
        ((void (*)(void*, s32))set_animation)(self, 0xC);
        bg = background_objects;
        if (self->x_pos.i.hi >= bg->x_pos.i.hi + 0xA0) {
            // !FAKE: depin: dropping it breaks the match (52/54)
            register s16 x asm("$3") = bg->x_pos.i.hi + 0x40;
            self->x_pos.i.hi = x;
        } else {
            // !FAKE: depin: dropping it breaks the match (48/54)
            register s16 x asm("$3") = bg->x_pos.i.hi + 0x100;
            self->x_pos.i.hi = x;
        }
        self->y_pos.i.hi = bg->y_pos.i.hi + 0x50;
        do {
            func_800F9E04(self);
        } while (0);
        self->action_phase = 2;
    } else if (mode == 2) {
        play_sound(2, 0x59, self);
    } else if (mode == 3) {
        play_sound(2, 0x51, self);
    }
}

#define func_8003744C func_800F80D4
#define D_80073C1C D_800FCCC8
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/rock_10/func_800F8110.c"

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
void func_800F9E04(struct X4_AnimatedObj*);
extern struct X4_BackgroundObj background_objects[3];

void func_800F815C(struct X4_AnimatedObj* self) {
    struct X4_BackgroundObj* bg;
    s8 ev = self->animation_step.fields.event;

    if (ev == 1) {
        play_sound(2, 0x59, self);
        set_animation(self, 0xC);
        bg = background_objects;
        self->x_pos.i.hi = bg->x_pos.i.hi + 0xA0;
        self->y_pos.i.hi = bg->y_pos.i.hi + 0x20;
        func_800F9E04(self);
        self->action_phase++;
    } else if (ev == 2) {
        play_sound(2, 0x59, self);
    } else if (ev == 3) {
        play_sound(2, 0x51, self);
    }
}

#include "../shared/rock_10/func_800F821C.c"

#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
s32 random_byte();
void func_800F5F04();
extern s16 D_800970AA;
extern s16 D_80097202;

void func_800F8278(u8* arg0) {
    s8 state;

    state = *(s8*)(arg0 + 0x45);
    if (state == 1) {
        {
            // !FAKE: depin: dropping it breaks the match (8/57)
            register u8* a asm("$4");
            func_800F5F04(a, 1);
        }
        set_animation(arg0, 1);
        if (D_800970AA > D_80097202 + 0xA0) {
            *(s16*)(arg0 + 0x7C) = 0;
        } else {
            *(s16*)(arg0 + 0x7C) = state;
        }
        *(u16*)(arg0 + 0x7E) = 0;
        if (random_byte() & 1) {
            *(u16*)(arg0 + 0x7E) = 0;
        } else {
            *(u16*)(arg0 + 0x7E) = 0xF;
        }
        if (!(random_byte() & 1)) {
            *(u16*)(arg0 + 0x7E) |= 0xF0;
        }
        arg0[7] = 0;
        arg0[6]++;
    } else if (state == 2) {
        play_sound(2, 0x51, arg0);
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800F5D58(); /* extern */

void func_800F835C(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        func_800F5D58();
    }
}

#define func_8003744C func_800F838C
#define D_80073C1C D_800FCD14
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/rock_10/func_800F83C8.c"

#include "../shared/rock_10/func_800F8404.c"

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
s32 random_byte();
void func_800F6F44(void* arg0, s32 arg1);

void func_800F8464(void* arg0) {
    s8 st = M2C_FIELD(arg0, s8*, 0x45);

    if (st == 2) {
        if (random_byte() & 1) {
            play_sound(2, 0x22, arg0);
        } else {
            play_sound(2, 0x23, arg0);
        }
        play_sound(2, 0x53, arg0);
        func_800F6F44(arg0, 0);
    } else if (st == 1) {
        set_animation(arg0, 0x16);
        {
            // !FAKE: depin: dropping it breaks the match (39/42)
            register s32 t asm("$2") = M2C_FIELD(arg0, u8*, 6) + 1;
            M2C_FIELD(arg0, u8*, 6) = t;
        }
    }
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
s32 random_byte();
void func_800F6F44(void* arg0, s32 arg1);
extern M2C_UNK D_80074E7C;

void func_800F850C(void* arg0) {
    s8 st = M2C_FIELD(arg0, s8*, 0x45);

    if (st == 2) {
        if (random_byte() & 1) {
            play_sound(2, 0x22, arg0);
        } else {
            play_sound(2, 0x23, arg0);
        }
        play_sound(2, 0x53, arg0);
        func_800F6F44(arg0, 1);
        M2C_FIELD(arg0, void**, 0x58) = &D_80074E7C;
        M2C_FIELD(arg0, u8*, 0x8E) = 0;
    } else if (st == 1) {
        set_animation(arg0, 0xA);
        {
            // !FAKE: depin: dropping it breaks the match (42/45)
            register s32 t asm("$2") = M2C_FIELD(arg0, u8*, 6) + 1;
            M2C_FIELD(arg0, u8*, 6) = t;
        }
    }
}

#include "../shared/rock_10/func_800F85C0.c"

#include "../shared/rock_10/func_800F862C.c"

#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
extern M2C_UNK D_8007433C;
extern M2C_UNK D_800FC734;
extern M2C_UNK D_800FC738;

void func_800F86F8(u8* arg0) {
    s8 temp_s1;

    temp_s1 = *(s8*)(arg0 + 0x45);
    if (temp_s1 == 1) {
        play_sound(2, 0x52, arg0);
        set_animation(arg0, 8);
        {
            // !FAKE: depin: dropping it breaks the match (36/39)
            register void* p asm("$2") = &D_8007433C;
            *(void**)(arg0 + 0x58) = p;
        }
        do {
        } while (0);
        {
            void* a = &D_800FC734;
            // !FAKE: depin: dropping it breaks the match (33/39)
            register void* b asm("$3") = &D_800FC738;
            *(void**)(arg0 + 0x50) = a;
            arg0[0x8E] = temp_s1;
            *(void**)(arg0 + 0x54) = b;
            arg0[6] = 8;
        }
    } else if (temp_s1 == 2) {
        play_sound(2, 0x59, arg0);
    }
}

#include "../shared/rock_10/func_800F8794.c"

// clang-format off
INCLUDE_ASM("asm/rock_10/nonmatchings/E9860", func_800F8848);
// clang-format on

#define func_8003744C func_800F8884
#define D_80073C1C D_800FCD3C
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F83C8 func_800F88C0
#include "../shared/rock_10/func_800F83C8.c"
#undef func_800F83C8

#define func_800F8BB4 func_800F88FC
#define background_objects background_objects
#include "../shared/rock_10/func_800F8BB4.c"
#undef func_800F8BB4
#undef background_objects

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
void func_800F9E04(struct X4_AnimatedObj*);
extern M2C_UNK D_800FC734;
extern M2C_UNK D_800FC738;

void func_800F89BC(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        play_sound(2, 0x56, arg0);
        set_animation(arg0, 0x17);
        func_800F9E04(arg0);
        M2C_FIELD(arg0, M2C_UNK**, 0x50) = &D_800FC734;
        M2C_FIELD(arg0, M2C_UNK**, 0x54) = &D_800FC738;
        M2C_FIELD(arg0, u8*, 6)++;
    }
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
s32 random_byte();
void func_800F9E3C(void*, s32);
extern M2C_UNK D_80074E7C;
extern s32 D_800FD004;

void func_800F8A30(void* arg0) {
    s8 st = M2C_FIELD(arg0, s8*, 0x45);

    if (st == 1) {
        if (random_byte() & 1) {
            play_sound(2, 0x24, arg0);
        } else {
            play_sound(2, 0x25, arg0);
        }
        set_animation(arg0, 0xA);
        M2C_FIELD(arg0, void**, 0x58) = &D_80074E7C;
        M2C_FIELD(arg0, u8*, 0x8E) = 0;
        D_800FD004 = 0;
        func_800F9E3C(arg0, 0x10);
        func_800F9E3C(arg0, 0x11);
        func_800F9E3C(arg0, 0x12);
        func_800F9E3C(arg0, 0x13);
        M2C_FIELD(arg0, s16*, 0x7C) = 0x258;
        M2C_FIELD(arg0, u8*, 7) = 1;
        M2C_FIELD(arg0, u8*, 6)++;
    } else if (st == 2) {
        play_sound(2, 0x57, arg0);
    }
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_800F5D58(); /* extern */

void func_800F8B1C(void) {
    func_800F5D58();
}

#define func_8003744C func_800F8B3C
#define D_80073C1C D_800FCD54
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F83C8 func_800F8B78
#include "../shared/rock_10/func_800F83C8.c"
#undef func_800F83C8

#include "../shared/rock_10/func_800F8BB4.c"

#include "../shared/rock_10/func_800F8C74.c"

#include "../shared/rock_10/func_800F8CE0.c"

#include "../shared/rock_10/func_800F8D4C.c"

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
s32 random_byte();
extern M2C_UNK D_80074E7C;
extern M2C_UNK D_800FC740;
extern M2C_UNK D_800FC744;

void func_800F8DAC(void* arg0) {
    s8 st;

    st = M2C_FIELD(arg0, s8*, 0x45);
    if (st == 1) {
        if (M2C_FIELD(arg0, s16*, 0xE) == (D_80097206 + 0x30)) {
            ((void (*)(void*, s32))set_animation)(arg0, 0x16);
            M2C_FIELD(arg0, u8*, 6)++;
            return;
        }
        if (random_byte() & 1) {
            play_sound(2, 0x22, arg0);
        } else {
            play_sound(2, 0x23, arg0);
        }
        play_sound(2, 0x54, arg0);
        ((void (*)(void*, s32))set_animation)(arg0, 0x1D);
        M2C_FIELD(arg0, M2C_UNK**, 0x58) = &D_80074E7C;
        M2C_FIELD(arg0, s8*, 0x60) = 0xA;
        M2C_FIELD(arg0, s8*, 0x8E) = 0;
        M2C_FIELD(arg0, M2C_UNK**, 0x50) = &D_800FC740;
        M2C_FIELD(arg0, M2C_UNK**, 0x54) = &D_800FC744;
        M2C_FIELD(arg0, s8*, 6) = 0xB;
    } else if (st == 2) {
        play_sound(2, 0x59, arg0);
    }
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
s32 random_byte();
void func_800F71F4(void* arg0);
extern M2C_UNK D_80074E7C;

void func_800F8EB0(void* arg0) {
    s8 st = M2C_FIELD(arg0, s8*, 0x45);

    if (st == 2) {
        if (random_byte() & 1) {
            play_sound(2, 0x22, arg0);
        } else {
            play_sound(2, 0x23, arg0);
        }
        play_sound(2, 0x53, arg0);
        func_800F71F4(arg0);
        M2C_FIELD(arg0, void**, 0x58) = &D_80074E7C;
        M2C_FIELD(arg0, u8*, 0x8E) = 0;
    } else if (st == 1) {
        set_animation(arg0, 0xA);
        {
            // !FAKE: depin: dropping it breaks the match (41/44)
            register s32 t asm("$2") = M2C_FIELD(arg0, u8*, 6) + 1;
            M2C_FIELD(arg0, u8*, 6) = t;
        }
    }
}

#include "../shared/rock_10/func_800F8F60.c"

#include "../shared/rock_10/func_800F8FD0.c"

// clang-format off
INCLUDE_ASM("asm/rock_10/nonmatchings/E9860", func_800F903C);
// clang-format on

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern M2C_UNK D_8007433C;
extern M2C_UNK D_800FC734;
extern M2C_UNK D_800FC738;

void func_800F9078(void* arg0) {
    s8 temp_v1;

    temp_v1 = M2C_FIELD(arg0, s8*, 0x45);
    if (temp_v1 == 1) {
        M2C_FIELD(arg0, s8*, 0x8E) = temp_v1;
        M2C_FIELD(arg0, M2C_UNK**, 0x58) = &D_8007433C;
        M2C_FIELD(arg0, s8*, 0x60) = 0xA;
        M2C_FIELD(arg0, M2C_UNK**, 0x50) = &D_800FC734;
        M2C_FIELD(arg0, M2C_UNK**, 0x54) = &D_800FC738;
        M2C_FIELD(arg0, s16*, 0x7C) = 0x1E;
        M2C_FIELD(arg0, s8*, 6) = 9;
    }
}

#define func_8003744C func_800F90CC
#define D_80073C1C D_800FCD84
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F83C8 func_800F9108
#include "../shared/rock_10/func_800F83C8.c"
#undef func_800F83C8

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
void func_800F9E04(struct X4_AnimatedObj*);
extern struct X4_BackgroundObj background_objects[3];

void func_800F9144(struct X4_AnimatedObj* arg0) {
    s8 s = M2C_FIELD(arg0, s8*, 0x45);

    if (s == 1) {
        play_sound(2, 0x59, arg0);
        set_animation(arg0, 0xC);
        func_800F9E04(arg0);
        arg0->unk15 = 0x40;
        arg0->x_pos.i.hi = background_objects[0].x_pos.i.hi + 0xA0;
        arg0->y_pos.i.hi = background_objects[0].y_pos.i.hi + 0x50;
        arg0->action_phase++;
    } else if (s == 2) {
        play_sound(2, 0x59, arg0);
    } else if (s == 3) {
        play_sound(2, 0x51, arg0);
    }
}

#include "../shared/rock_10/func_800F9204.c"

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
s32 random_byte();
void func_800F74D8(void* arg0, s16 arg1, s16 arg2, u8 arg3);
void func_800F765C(void* arg0, u8 arg1);
extern M2C_UNK D_80074E7C;

void func_800F9274(void* arg0) {
    s8 s = M2C_FIELD(arg0, s8*, 0x45);

    if (s == 2) {
        func_800F74D8(arg0, M2C_FIELD(arg0, s16*, 0xA),
                      M2C_FIELD(arg0, s16*, 0xE), 0x10);
    } else if (s == 3) {
        if (random_byte() & 1) {
            play_sound(2, 0x26, arg0);
        } else {
            play_sound(2, 0x27, arg0);
        }
        M2C_FIELD(arg0, u8*, 7) = 1;
        func_800F765C(arg0, 0x30);
        func_800F765C(arg0, 0x31);
        func_800F765C(arg0, 0x32);
        func_800F765C(arg0, 0x33);
    } else if (s == 1) {
        M2C_FIELD(arg0, void**, 0x58) = &D_80074E7C;
        M2C_FIELD(arg0, u8*, 0x8E) = 0;
        set_animation(arg0, 0x11);
        M2C_FIELD(arg0, s32*, 0x50) = 0;
        M2C_FIELD(arg0, s32*, 0x54) = 0;
        M2C_FIELD(arg0, s16*, 0x7E) = 0;
        {
            // !FAKE: depin: dropping it breaks the match (60/63)
            register s32 t asm("$2") = M2C_FIELD(arg0, u8*, 6) + 1;
            M2C_FIELD(arg0, u8*, 6) = t;
        }
    }
}

#include "../shared/rock_10/func_800F9370.c"

#include "../shared/rock_10/func_800F93C4.c"

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800F5D58(); /* extern */

void func_800F942C(void* arg0) {
    M2C_FIELD(arg0, s8*, 0x16) = 5;
    func_800F5D58();
}

#define func_8003744C func_800F9450
#define D_80073C1C D_800FCDA8
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8003D308(M2C_UNK, M2C_UNK); /* extern */

void func_800F948C(void* arg0) {
    func_8003D308(0x14, 0x40);
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#include "../shared/rock_10/func_800F94C4.c"

#include "../shared/rock_10/func_800F955C.c"

#include "../shared/rock_10/func_800F95CC.c"

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
void func_800F5F04();

void func_800F9614(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        func_800F5F04(arg0, 0);
        ((void (*)(void*, M2C_UNK))set_animation)(arg0, 5);
        M2C_FIELD(arg0, u8*, 6)++;
    }
}

#include "../shared/rock_10/func_800F9668.c"

#define func_800F4BA8 func_800F96DC
#include "../shared/rock_04/func_800F4BA8.c"
#undef func_800F4BA8

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_80040498(); /* extern */

void func_800F9720(void* arg0) {
    if (func_80040498() == 0) {
        M2C_FIELD(arg0, s16*, 0x7E) = 3;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#define func_800F4D48 func_800F975C
#include "../shared/rock_04/func_800F4D48.c"
#undef func_800F4D48

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8003D330();    /* extern */
M2C_UNK func_800F5D58(s32); /* extern */

void func_800F97E0(s32 arg0) {
    func_8003D330();
    func_800F5D58(arg0);
}

#define func_8003744C func_800F980C
#define D_80073C1C D_800FCDD4
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
extern s16 D_800970AA;
extern M2C_UNK D_800FC734;
extern M2C_UNK D_800FC738;
extern M2C_UNK D_800FC73C;

void func_800F9848(void* arg0) {
    s32 x;

    play_sound(2, 0x21, arg0);
    M2C_FIELD(arg0, u8*, 0x60) = 0xA;
    M2C_FIELD(arg0, M2C_UNK**, 0x50) = &D_800FC734;
    M2C_FIELD(arg0, M2C_UNK**, 0x54) = &D_800FC738;
    set_animation(arg0, 0x12);
    x = M2C_FIELD(arg0, s16*, 0xA);
    if (D_800970AA >= x) {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        M2C_FIELD(arg0, s32*, 0x20) = 0xFFF40000;
        M2C_FIELD(arg0, s32*, 0x28) = 0x4CCC;
    } else {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
        M2C_FIELD(arg0, s32*, 0x20) = 0xC0000;
        M2C_FIELD(arg0, s32*, 0x28) = 0x4CCC;
    }
    M2C_FIELD(arg0, M2C_UNK**, 0x68) = &D_800FC73C;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, u8*, 0x6) += 1;
}

#include "../shared/rock_10/func_800F990C.c"

#define func_80041FB0 func_800F99C8
#include "../shared/SLUS_013.95/func_80041FB0.c"
#undef func_80041FB0

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_800F5D58(); /* extern */

void func_800F99FC(void) {
    ((M2C_UNK(*)())func_800F5D58)();
}

#include "../shared/rock_10/func_800F9A1C.c"

#include "../shared/rock_10/func_800F9A80.c"

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F6F44(void* arg0, s32 arg1); /* extern */

void func_800F9ADC(void* arg0) {
    s8 temp_v1;

    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        temp_v1 = M2C_FIELD(arg0, s8*, 2);
        switch (temp_v1) { /* irregular */
        case 16:
            func_800F6F44(arg0, 0x10);
            break;
        case 17:
            func_800F6F44(arg0, 0x11);
            break;
        case 18:
            func_800F6F44(arg0, 0x12);
            break;
        case 19:
            func_800F6F44(arg0, 0x13);
            break;
        }
        M2C_FIELD(arg0, s16*, 0x7C) = 0x1E;
        M2C_FIELD(arg0, u8*, 5) = (u8)(M2C_FIELD(arg0, u8*, 5) + 1);
    }
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
extern M2C_UNK D_800FC748;
extern M2C_UNK D_800FC74C;
extern M2C_UNK D_800FC750;
extern M2C_UNK D_800FC754;

void func_800F9BA4(void* arg0) {
    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        switch (M2C_FIELD(arg0, s8*, 0x2)) {
        case 0x10:
            set_animation(arg0, 0x18);
            {
                // !FAKE: depin: dropping it breaks the match (22/59)
                register s32* a asm("$2") = &D_800FC748;
                // !FAKE: depin: dropping it breaks the match (29/59)
                register s32* b asm("$3") = &D_800FC74C;
                M2C_FIELD(arg0, s32**, 0x50) = a;
                M2C_FIELD(arg0, s32**, 0x54) = b;
            }
            break;
        case 0x12:
            set_animation(arg0, 0x18);
            {
                // !FAKE: depin: dropping it breaks the match (39/59)
                register s32* a asm("$2") = &D_800FC748;
                // !FAKE: depin: dropping it breaks the match (38/59)
                register s32* b asm("$3") = &D_800FC74C;
                M2C_FIELD(arg0, s32**, 0x50) = a;
                M2C_FIELD(arg0, s32**, 0x54) = b;
            }
            break;
        case 0x11:
        case 0x13:
            set_animation(arg0, 0x19);
            {
                // !FAKE: depin: dropping it breaks the match (55/59)
                register s32* a asm("$2") = &D_800FC750;
                // !FAKE: depin: dropping it breaks the match (30/59)
                register s32* b asm("$3") = &D_800FC754;
                M2C_FIELD(arg0, s32**, 0x50) = a;
                M2C_FIELD(arg0, s32**, 0x54) = b;
            }
            break;
        }
        M2C_FIELD(arg0, u8*, 0x5) = 2;
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F9C90(void* arg0) {
    if (M2C_FIELD(M2C_FIELD(arg0, void**, 0x80), s8*, 7) == 2) {
        M2C_FIELD(arg0, u8*, 5) = (u8)(M2C_FIELD(arg0, u8*, 5) + 1);
    }
}

#include "../shared/rock_10/func_800F9CC4.c"

#include "common.h"

extern s16 D_80097202;
#define D_80097202 (*(u16*)&D_80097202)

void func_800F9D18(u8* arg0) {
    u8* p = *(u8**)(arg0 + 0x80);
    u16 g = D_80097202;
    s32 t = *(u16*)(p + 0xA) - g;

    t -= 0x140;
    *(s16*)(arg0 + 0xA) = g - t;
    *(u16*)(arg0 + 0xE) = *(u16*)(p + 0xE);
}
#undef D_80097202

#include "../shared/rock_10/func_800F9D48.c"

#include "../shared/rock_10/func_800F9DA8.c"

#define func_800F32A8 func_800F9E04
#include "../shared/rock_08/func_800F32A8.c"
#undef func_800F32A8

#include "common.h"

void func_800F9E34(void) {
}

#include "../shared/rock_10/func_800F9E3C.c"

#include "../shared/rock_10/func_800F9EE4.c"

#define func_800F54B8 func_800F9FA4
#include "../shared/rock_04/func_800F54B8.c"
#undef func_800F54B8

#define func_80048DC8 func_800F9FE4
#define D_80077BC0 D_800FCF40
#include "../shared/d1000/func_80048DC8.c"
#undef func_80048DC8
#undef D_80077BC0

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 is_off_screen(void*, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK apply_object_motion(void*);         /* extern */

void func_800FA030(void* arg0) {
    u16 temp_v0;

    if (M2C_FIELD(arg0, s8*, 5) == 0) {
        M2C_FIELD(arg0, s8*, 5) = (s8)((u8)M2C_FIELD(arg0, s8*, 5) + 1);
        M2C_FIELD(arg0, u16*, 0x88) = 0U;
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0x4200;
    }
    apply_object_motion(arg0);
    if (is_off_screen(arg0, 0x40, 0x40) == 0) {
        temp_v0 = M2C_FIELD(arg0, u16*, 0x88);
        M2C_FIELD(arg0, u16*, 0x88) = (u16)(temp_v0 + 1);
        if (temp_v0 & 1) {
            M2C_FIELD(arg0, s8*, 3) = 1;
            return;
        }
        M2C_FIELD(arg0, s8*, 3) = 0;
        return;
    }
    M2C_FIELD(arg0, s8*, 4) = 3;
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800FA0CC(void) {
    clear_object_slot();
}

#define func_8003744C func_800FA0EC
#define D_80073C1C D_800FCF6C
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#define M2C_UNK s32

M2C_UNK move_object(s32);
extern s16 D_80097202;

void func_800FA128(u8* arg0) {
    // !FAKE: depin: dropping it breaks the match (33/35)
    register s32 t asm("$3");

    move_object((s32)arg0);
    {
        // !FAKE: depin: dropping it breaks the match (33/35)
        register s32 s asm("$2") = *(u8*)(arg0 + 0x15);
        if (s == 0) {
            if (D_80097202 + 0x20 >= *(s16*)(arg0 + 0xA)) {
                t = *(u8*)(arg0 + 0x6);
                {
                    s32 c;
                    c = 0x20000;
                    *(s32*)(arg0 + 0x20) = c;
                    c = 0x40;
                    *(u8*)(arg0 + 0x15) = c;
                }
                // !FAKE: goto shares the state-advance tail of both arms; duplicating the tail moved bytes
                goto block_5;
            }
        } else if (*(s16*)(arg0 + 0xA) >= D_80097202 + 0x120) {
            t = *(u8*)(arg0 + 0x6);
            *(s32*)(arg0 + 0x20) = 0xFFFE0000;
            *(u8*)(arg0 + 0x15) = 0;
        block_5:
            *(u8*)(arg0 + 0x6) = t + 1;
        }
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK move_object(s32);
extern s16 D_80097202;

void func_800FA1B4(struct X4_AnimatedObj* self) {
    move_object(self);
    {
        // !FAKE: the flag byte is read into the first return register
        register s32 flag asm("$2") = self->unk15;
        if (flag == 0) {
            if (D_80097202 + 0x70 < self->x_pos.i.hi) {
                return;
            }
        } else if (self->x_pos.i.hi < D_80097202 + 0xD0) {
            return;
        }
    }
    self->action_phase++;
}

#include "common.h"

s32 random_byte();

#define M2C_UNK s32
M2C_UNK move_object(s32);
void func_800FA230(void* arg0) {
    u8* self = arg0;
    u8* temp_s1;

    temp_s1 = *(u8**)(self + 0x7C);
    if (random_byte() & 1) {
        temp_s1[7] = 1;
        if (self[0x15] == 0) {
            self[0x15] = 0x40;
        } else {
            self[0x15] = 0;
        }
        self[6] = 3;
    } else {
        temp_s1[7] = 2;
        ((void (*)())move_object)(self);
        self[6] = 4;
    }
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK move_object(s32);
extern s16 D_80097202;

void func_800FA2B0(void* arg0) {
    void* temp_s1;
    s32 v;

    temp_s1 = M2C_FIELD(arg0, void**, 0x7C);
    ((void (*)(void*))move_object)(arg0);
    if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
        if (D_80097202 + 0x30 >= M2C_FIELD(arg0, s16*, 0xA)) {
            v = 3;
            M2C_FIELD(temp_s1, s8*, 7) = v;
            // !FAKE: goto shares the stop tail of both arms; duplicating the tail moved bytes
            goto block_5;
        }
    } else if (M2C_FIELD(arg0, s16*, 0xA) >= D_80097202 + 0x110) {
        v = 3;
        M2C_FIELD(temp_s1, s8*, 7) = v;
    block_5:
        M2C_FIELD(arg0, s32*, 0x50) = 0;
        M2C_FIELD(arg0, s32*, 0x54) = 0;
        M2C_FIELD(arg0, s8*, 3) = 0;
        M2C_FIELD(arg0, s8*, 4) = v;
    }
}

#define func_8003744C func_800FA340
#define D_80073C1C D_800FCF80
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/rock_10/func_800FA37C.c"

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800FA3D4(void* arg0) {
    if (M2C_FIELD(M2C_FIELD(arg0, void**, 0x7C), s8*, 6) == 8) {
        M2C_FIELD(arg0, s32*, 0x50) = 0;
        M2C_FIELD(arg0, s32*, 0x54) = 0;
        M2C_FIELD(arg0, s8*, 3) = 0;
        M2C_FIELD(arg0, s8*, 4) = 3;
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800FA408(void* arg0) {
    M2C_FIELD(M2C_FIELD(arg0, void**, 0x7C), s8*, 7) = 4;
    M2C_FIELD(arg0, s32*, 0x50) = 0;
    M2C_FIELD(arg0, s32*, 0x54) = 0;
    M2C_FIELD(arg0, s8*, 3) = 0;
    M2C_FIELD(arg0, s8*, 4) = 3;
}

#define func_8003744C func_800FA42C
#define D_80073C1C D_800FCF94
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

s32 random_byte();
extern s16 D_80097202;
#define D_80097202 (*(u16*)&D_80097202)

void func_800FA468(u8* arg0) {
    u16 temp_a0;

    if (arg0[0x15] == 0) {
        arg0[0x94] = 0;
    } else {
        arg0[0x94] = 1;
    }
    {
        s32 a = *(u16*)(arg0 + 0xA);
        s32 g = D_80097202;
        s32 d;
        temp_a0 = *(u16*)(arg0 + 0xE);
        *(s32*)(arg0 + 0x84) = 0;
        d = (a - g) - 0x140;
        *(s16*)(arg0 + 0x88) = g - d;
    }
    *(u16*)(arg0 + 0x8A) = temp_a0;
    if (random_byte(temp_a0) & 1) {
        *(s32*)(arg0 + 0x84) = 0;
    } else {
        *(s32*)(arg0 + 0x84) = 0xF;
    }
    if (!(random_byte() & 1)) {
        *(s32*)(arg0 + 0x84) |= 0xF0;
    }
    arg0[7] = 0;
    arg0[6]++;
}
#undef D_80097202

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800FA51C(struct ObjectHeader* arg0) {
    M2C_FIELD(M2C_FIELD(arg0, void**, 0x7C), s8*, 7) = 4;
    arg0->on_screen = 0;
    arg0->state = 3;
}

#include "common.h"
#include "mmx6/x4.h"

extern s16 D_80097202;
#define D_80097202 (*(u16*)&D_80097202)

void func_800FA538(struct X4_MainObj* self) {
    struct X4_MainObj* p;

    p = *(struct X4_MainObj**)((u8*)self + 0x8C);
    {
        s32 d = (p->x_pos.u.hi - D_80097202) - 0x140;
        self->x_pos.i.hi = D_80097202 - d;
    }
    self->y_pos.i.hi = p->y_pos.i.hi;
    self->animation_step.fields.frame_index =
        p->animation_step.fields.frame_index;
    self->on_screen = p->on_screen;
    if (p->unk15 == 0) {
        self->unk15 = 0x40;
    } else {
        self->unk15 = 0;
    }
    if (p->state != 1) {
        self->state = 3;
    }
}
#undef D_80097202

#include "../shared/rock_10/func_800FA5BC.c"

#include "common.h"

#define M2C_UNK s32

M2C_UNK move_object(); /* extern */

void func_800FA61C(void) {
    ((M2C_UNK(*)())move_object)();
}

#include "common.h"

void func_800FA63C(void) {
}

#include "../shared/rock_10/func_800FA644.c"

#include "../shared/rock_10/func_800FA710.c"

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800FA798(void) {
    clear_object_slot();
}

#include "../shared/rock_10/func_800FA7B8.c"

#include "../shared/rock_10/func_800FA81C.c"

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800FA89C(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        M2C_FIELD(arg0, s8*, 3) = 0;
        M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
    }
}

#define func_80041AB8 func_800FA8C4
#define D_80075FD8 D_800FCFD4
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

// clang-format off
INCLUDE_ASM("asm/rock_10/nonmatchings/E9860", D_800FA900);
// clang-format on
