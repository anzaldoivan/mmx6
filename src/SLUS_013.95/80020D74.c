#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern u8 D_800911A8[];
void func_80020AA8(struct X4_AnimatedObj* arg0);

M2C_UNK func_80020D74(void) {
    u8* p = D_800911A8;

    func_80020AA8((struct X4_AnimatedObj*)p);
    p += 0x50;
    func_80020AA8((struct X4_AnimatedObj*)p);
    p += 0x50;
    if (*(s8*)p != 0) {
        func_80020AA8((struct X4_AnimatedObj*)p);
    }
}

/* Adapted from sozud/mmx4 @807a01b src/main/object_update.c:func_80021CC8, AGPL-3.0; proven shared with X6 by exact signature a99aed5959d6 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern struct X4_UnkObj D_800972F8[3];

void func_80020DC8(void) {
    struct X4_UnkObj* var_s0;

    for (var_s0 = &D_800972F8; var_s0 < &D_800972F8[COUNT(D_800972F8)];
         var_s0++) {
        func_80020E1C(var_s0);
    }
}

#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
extern M2C_UNK g_Player;
extern void (*D_80071388[])(struct X4_UnkObj*, struct X4_PlayerObj*);

void func_80020E1C(struct X4_UnkObj* arg0) {
    struct X4_PlayerObj* p = &g_Player;

    arg0->animation_step.fields.frame_index =
        p->animation_step.fields.frame_index;
    arg0->unk15 = p->unk15;
    arg0->unk38 = p->unk38;
    arg0->unk3C = p->unk3C;
    arg0->unk18 = arg0->x_pos;
    arg0->unk1C = arg0->y_pos;
    if (arg0->state == 0) {
        if (p->afterimage != 0) {
            if (p->afterimage > 0) {
                arg0->on_screen = 1;
                arg0->ext.afterimage.position_timer = 3;
                arg0->ext.afterimage.blink_timer = 8;
                arg0->ext.afterimage.palette_offset = (5 - arg0->unk2) * 2;
                arg0->x_pos = p->x_pos;
                arg0->y_pos = p->y_pos;
                arg0->state = 1;
                arg0->unk5 = 0;
                return;
            }
            p->afterimage = 0;
        }
    } else {
        if (p->afterimage == 0) {
            arg0->on_screen = 0;
            arg0->state = 0;
            return;
        }
        D_80071388[arg0->unk5](arg0, p);
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_80020F24(void* arg0, struct PlayerObj* arg1) {
    void* temp_a0;

    if (M2C_FIELD(arg0, s16*, 0x54) != 0) {
        M2C_FIELD(arg0, s16*, 0x54) =
            (s16)((u16)M2C_FIELD(arg0, s16*, 0x54) - 1);
    } else {
        temp_a0 = M2C_FIELD(arg0, void**, 0x50);
        M2C_FIELD(arg0, s16*, 0x54) = 3;
        M2C_FIELD(arg0, s32*, 8) = (s32)M2C_FIELD(temp_a0, s32*, 0x18);
        M2C_FIELD(arg0, s32*, 0xC) = (s32)M2C_FIELD(temp_a0, s32*, 0x1C);
    }
    if (arg1->afterimage < 0) {
        M2C_FIELD(arg0, u8*, 5) = (u8)(M2C_FIELD(arg0, u8*, 5) + 1);
    }
}

#include "common.h"

#define S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define S16(p, o) (*(s16*)((u8*)(p) + (o)))
#define S32(p, o) (*(s32*)((u8*)(p) + (o)))
#define PTR(p, o) (*(u8**)((u8*)(p) + (o)))

void func_80020F8C(u8* arg0, u8* arg1) {
    u8* t;

    if (S8(arg1, 0x8C) > 0) {
        S16(arg0, 0x54) = 3;
        S16(arg0, 0x56) = 8;
        S16(arg0, 0x58) = (5 - S8(arg0, 2)) * 2;
        S32(arg0, 8) = S32(arg1, 8);
        {
            s32 c = S32(arg1, 0xC);
            U8(arg0, 4) = 1;
            U8(arg0, 5) = 0;
            S32(arg0, 0xC) = c;
        }
        return;
    }
    if (S16(arg0, 0x56) != 0) {
        S16(arg0, 0x56)--;
        if (S16(arg0, 0x56) & 1) {
            t = PTR(arg0, 0x50);
            S32(arg0, 8) = S32(t, 0x18);
            S32(arg0, 0xC) = S32(t, 0x1C);
        }
    } else {
        U8(arg0, 5)++;
    }
}

#include "common.h"

#define S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define S16(p, o) (*(s16*)((u8*)(p) + (o)))
#define S32(p, o) (*(s32*)((u8*)(p) + (o)))

void func_8002103C(void* arg0, void* arg1) {
    void* p;

    if (S8(arg1, 0x8C) > 0) {
        S16(arg0, 0x54) = 3;
        S16(arg0, 0x56) = 8;
        S16(arg0, 0x58) = (5 - S8(arg0, 2)) * 2;
        S32(arg0, 0x8) = S32(arg1, 0x8);
        S32(arg0, 0xC) = S32(arg1, 0xC);
        S8(arg0, 4) = 1;
        S8(arg0, 5) = 0;
        return;
    }
    if (S16(arg0, 0x58) != 0) {
        p = *(void**)((u8*)arg0 + 0x50);
        S32(arg0, 0x8) = S32(p, 0x18);
        S32(arg0, 0xC) = S32(p, 0x1C);
        S16(arg0, 0x58) = S16(arg0, 0x58) - 1;
        return;
    }
    S8(arg0, 3) = 0;
    S8(arg0, 4) = 0;
    if (S8(arg0, 2) == 2) {
        S8(arg1, 0x8C) = 0;
    }
}

#include "common.h"

#define CUR (*(u8**)0x1F800064)

extern u8 D_800964A0[];
extern void (*D_80071360[])(s8*);

void func_800210E8(void) {
    s8* p;

    for (CUR = D_800964A0; CUR < D_800964A0 + 0xC00; CUR += 0x60) {
        p = (s8*)CUR;
        if (p[0] != 0) {
            D_80071360[p[1]](p);
        }
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);

void func_80021194(struct X4_AnimatedObj* arg0, s8* arg1) {
    s32 var_v1;
    s8 temp_a2;

    temp_a2 = arg0->unk2;
    var_v1 = 1;
    if (temp_a2 == 0) {
        var_v1 = 2;
    }
    if ((arg1[0x9B] == var_v1) || (arg1[0x9C] == var_v1)) {
        arg0->on_screen = 1;
        ((void (*)(void*, M2C_UNK))set_animation)(arg0, temp_a2 + 8);
        arg0->state++;
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04(); /* extern */

void func_80021208(struct ObjectHeader* arg0, void* arg1) {
    if ((M2C_FIELD(arg1, s8*, 0x9B) == 0) &&
        (M2C_FIELD(arg1, s8*, 0x9C) == 0)) {
        arg0->on_screen = 0;
        arg0->state = 0;
        return;
    }
    func_80017A04();
}

/* Adapted from sozud/mmx4 @807a01b src/main/afterimage.c:func_800AEA58, AGPL-3.0; proven shared with X6 by exact signature 2a177c96c5fb (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"

void func_80021254(struct X4_UnkObj* self, struct X4_PlayerObj* player) {
    self->ext.afterimage.position_timer = 3;
    self->ext.afterimage.blink_timer = 8;
    self->ext.afterimage.palette_offset = (5 - self->unk2) * 2;
    self->x_pos.val = player->x_pos.val;
    self->y_pos.val = player->y_pos.val;
    self->state = 1;
    self->unk5 = 0;
}

#include "common.h"

void func_8002129C(u8* arg0, u8* arg1) {
    u8* self;
    u8* other;
    s8 temp_v0;
    // !FAKE: constant in second arg register
    register s32 one asm("$5");
    // !FAKE: field read in first arg register
    register s32 x asm("$4");
    // !FAKE: constant 8 in v1
    register s32 k8 asm("$3");

    other = arg1;
    self = arg0;
    temp_v0 = *(s8*)(other + 0x8C);
    if (temp_v0 != 0) {
        one = 1;
        if (temp_v0 > 0) {
            x = *(s8*)(self + 0x2);
            k8 = 8;
            *(s16*)(self + 0x54) = 3;
            *(u8*)(self + 0x3) = one;
            *(s16*)(self + 0x56) = k8;
            *(s16*)(self + 0x58) = (5 - x) * 2;
            *(s32*)(self + 0x8) = *(s32*)(other + 0x8);
            *(s32*)(self + 0xC) = *(s32*)(other + 0xC);
            *(u8*)(self + 0x4) = one;
            *(u8*)(self + 0x5) = 0;
            return;
        }
        *(s8*)(other + 0x8C) = 0;
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_8002130C(void* arg0) {
    void* temp_a1;

    temp_a1 = M2C_FIELD(arg0, void**, 0x50);
    M2C_FIELD(arg0, s32*, 8) = (s32)M2C_FIELD(temp_a1, s32*, 0x18);
    M2C_FIELD(arg0, s32*, 0xC) = (s32)M2C_FIELD(temp_a1, s32*, 0x1C);
}

/* Adapted from sozud/mmx4 @807a01b src/main/afterimage.c:func_800AE88C, AGPL-3.0; proven shared with X6 by exact signature fb1027ecedab (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern void (*D_80071388[])(struct X4_UnkObj*, struct X4_PlayerObj*);

void func_8002132C(struct X4_UnkObj* arg0, struct X4_PlayerObj* arg1) {
    if (arg1->afterimage == 0) {
        arg0->on_screen = 0;
        arg0->state = 0;
        return;
    }

    D_80071388[arg0->unk5](arg0, arg1);
}

/* Adapted from sozud/mmx4 @807a01b src/main/125BC.c:func_80021DBC, AGPL-3.0; proven shared with X6 by exact signature adb625a87261 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern struct X4_FixedMatrix2 D_80071394[16];

void func_80021380(s16* arg0, s16* arg1, s32 arg2) {
    struct X4_FixedMatrix2* matrix;
    s16 x;
    s16 y;
    s32 product0;
    s32 product1;
    s32 product2;
    s32 product3;

    matrix = &D_80071394[arg2 & 0xFF];
    x = *arg0;
    y = *arg1;
    product0 = x * matrix->m00;
    product1 = y * matrix->m01;
    product2 = x * matrix->m10;
    product3 = y * matrix->m11;
    *arg0 = (product0 >> 8) + (product1 >> 8);
    *arg1 = (product2 >> 8) + (product3 >> 8);
}

#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EngineObj g_playthrough_state;

#define SAVE_C_U8 ((u8*)0x801F600C)

void func_80021400(void) {
    u8* s = SAVE_C_U8;
    u8* e = (u8*)&g_playthrough_state;

    e[0x38] = s[0x38];
    e[0x5E] = s[0x5E];
    e[0xC] = s[0xC];
    e[0xD] = s[0xD];
}

#include "common.h"
#include "mmx6/x4.h"

extern u16 D_80090E70;
#include "mmx6/state.h"
extern struct X4_EngineObj g_playthrough_state;

#define SAVE_BASE ((s32*)0x801F6000)
#define SAVE_C ((s32*)0x801F600C)
#define SAVE_474 ((s32*)0x801F6474)

void func_80021434(void) {
    s32* base = SAVE_BASE;
    s32* save = SAVE_474;
    s32* eng = (s32*)&g_playthrough_state;
    s32* eng2;

    base[0] = 0;
    D_80097420.frame_counter = base[1];
    D_80090E70 = *(u16*)&base[2];
    __builtin_memcpy(save, eng, 0x468);
    eng2 = (s32*)&g_playthrough_state;
    save = SAVE_C;
    __builtin_memcpy(eng2, save, 0x468);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_80017B04(u8*, s16, s16);        /* extern */
void func_8002000C(void);                 /* extern */
void func_8002012C(void);                 /* extern */
void func_80020258(void);                 /* extern */
void func_80020378(void);                 /* extern */
void func_8002048C(void);                 /* extern */
void func_800205A0();                     /* extern */
void func_800206C0(void);                 /* extern */
void func_800207D4(void);                 /* extern */
void update_layer_objects(void);          /* extern */
void func_80020A08(void);                 /* extern */
M2C_UNK func_80020D74();                  /* extern */
void func_80020DC8(void);                 /* extern */
void func_8002927C(void);                 /* extern */
void func_8002935C(void);                 /* extern */
M2C_UNK func_800293CC();                  /* extern */
void func_80029D18(void);                 /* extern */
void func_8002ACA8();                     /* extern */
M2C_UNK func_8002E84C();                  /* extern */
void func_8002F288(struct X4_PlayerObj*); /* extern */
void func_80034DCC(void);                 /* extern */
extern M2C_UNK g_Player;
extern s32 D_801F6000;
#define D_801F6000 (*(s32*)0x801F6000)
#define D_801F68DC ((u16*)0x801F68DC)

#define P (*(struct X4_PlayerObj*)&g_Player)

void func_80021500(void) {
    struct X4_PlayerObj* p = &P;

    p->input.buttons.previous = p->input.buttons.held;
    if (D_801F6000 != 0x9C4) {
        p->input.buttons.held = D_801F68DC[D_801F6000];
        D_801F6000++;
    } else {
        p->input.buttons.held = 0;
    }
    p->pressed_input = p->input.buttons.held &
                       (p->input.buttons.held ^ p->input.buttons.previous);
    func_8002E84C();
    func_80020A08();
    func_80034DCC();
    func_8002012C();
    update_layer_objects();
    func_8002000C();
    func_80020258();
    func_80020378();
    func_800205A0();
    func_800206C0();
    func_800207D4();
    func_80029D18();
    func_8002048C();
    func_8002F288((struct X4_PlayerObj*)&g_Player);
    func_8002927C();
    func_8002935C();
    func_800293CC();
    func_8002ACA8();
    func_80020D74();
    func_80020DC8();
    func_80017B04(&g_Player, 0x140, 0);
}
#undef P
#undef D_801F68DC
#undef D_801F6000

#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EngineObj g_playthrough_state;

#define SAVE_474 ((s32*)0x801F6474)

void func_8002163C(void) {
    s32* save = SAVE_474;
    s32* eng = (s32*)&g_playthrough_state;

    __builtin_memcpy(eng, save, 0x468);
}

#include "common.h"
#include "mmx6/x4.h"

extern u16 D_80090E70;
extern struct X4_EngineObj g_playthrough_state;

#define SAVE_BASE ((s32*)0x801F6000)
#define SAVE_C ((s32*)0x801F600C)

void func_80021694(void) {
    s32* base = SAVE_BASE;
    s32* save = SAVE_C;
    s32* eng = (s32*)&g_playthrough_state;

    base[0] = 0;
    base[1] = D_80097420.frame_counter;
    *(u16*)&base[2] = D_80090E70;
    __builtin_memcpy(save, eng, 0x468);
}

#include "common.h"

extern u16 D_8009711C;
#define D_801F6000_VAL (*(s32*)0x801F6000)
#define D_801F68DC_ADDR 0x801F68DC

void func_8002170C(void) {
    if (D_801F6000_VAL != 0x9C4) {
        *(u16*)(D_801F6000_VAL * 2 + D_801F68DC_ADDR) = D_8009711C;
        D_801F6000_VAL += 1;
    }
}

void func_80021758(void) {
}
