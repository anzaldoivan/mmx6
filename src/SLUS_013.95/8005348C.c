#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

extern struct X4_PlayerObj g_Player;
extern struct X4_EngineObj g_playthrough_state;
M2C_UNK func_8003D330();

void func_8005348C(struct X4_MainObj* arg0) {
    if (*(u16*)&arg0->bg_offset != 0) {
        g_Player.unk71 |= 8;
    }
    if (D_8008EAFC == 0) {
        if (arg0->unk2 & 0xF0) {
            g_playthrough_state.unk10 = 0;
        }
        g_playthrough_state.unk12 = 0;
        g_playthrough_state.unk13 = 0;
        g_playthrough_state.unk16 = 0;
        g_playthrough_state.unk11 = 0;
        g_playthrough_state.unk19 = 0;
        g_playthrough_state.unk18 = 0;
        g_playthrough_state.unk17 = 0;
        g_playthrough_state.unk14 = 0;
        g_playthrough_state.unk15 = 0;
        func_8003D330();
        arg0->state++;
    }
}

#define func_80041AB8 func_8005353C
#define D_80075FD8 D_8007ACFC
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EngineObj g_playthrough_state;
void* alloc_class3_slot();

void func_80053578(u8* arg0) {
    u8* temp_v0;

    if (((u32)((u8)g_playthrough_state.stage - 1) < 8U) &&
        ((g_playthrough_state.unk60 >> (g_playthrough_state.stage - 1)) & 1)) {
        g_playthrough_state.unkF = 1;
        return;
    }
    temp_v0 = ((u8 * (*)()) alloc_class3_slot)();
    if (temp_v0 != 0) {
        temp_v0[0] = 1;
        temp_v0[1] = 4;
        *(u8**)(arg0 + 0x14) = temp_v0;
    }
    *(s16*)(arg0 + 0x18) = 0;
    arg0[0x1A] = 5;
    arg0[0x1B] = 0;
    arg0[0x1C] = 0;
    arg0[4]++;
}

#include "common.h"
#include "mmx6/x4.h"

struct X4_QuadObj* alloc_class6_slot(void);
extern struct X4_EffectObj* D_800E4498[22];

void func_80053620(struct X4_EffectObj* self) {
    struct X4_QuadObj* q;

    if (self->ext.effect_24.timer == 0) {
        q = alloc_class6_slot();
        if (q != 0) {
            q->active = -0x7D;
            q->id = 3;
            q->unk2 = self->ext.effect_24.unk1B;
            D_800E4498[self->ext.effect_24.unk1B] = (struct X4_EffectObj*)q;
            self->ext.effect_24.timer = 10;
            if (++self->ext.effect_24.unk1B == 0x16) {
                self->ext.effect_24.unk1B = 0;
                self->ext.effect_24.timer = 0xB4;
                self->unk5++;
            }
        }
    } else {
        self->ext.effect_24.timer--;
    }
}

/* Adapted from sozud/mmx4 @807a01b src/main/effects/effect_24_boss_warning.c:boss_warning_wait, AGPL-3.0; proven shared with X6 by exact signature ec91c859e783 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"

void func_800536D0(struct X4_EffectObj* self) {
    if (--self->ext.effect_24.timer == 0) {
        self->unk5++;
    }
}

/* Adapted from sozud/mmx4 @807a01b src/main/effects/effect_24_boss_warning.c:boss_warning_wait_tiles, AGPL-3.0; proven shared with X6 by exact signature f64138f8e32d (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern struct X4_EffectObj* D_800E4498[22];

void func_80053704(struct X4_EffectObj* self) {
    struct X4_EffectObj* spawned;
    struct X4_EffectObj** entry;
    u32 index;
    s32 count;
    s32 expected;

    spawned = self->ext.effect_24.spawned_effect;
    if (spawned->id != 4 || *(u16*)spawned == 0x400) {
        index = 0;
        count = 0;
        expected = 1;
        entry = D_800E4498;
        do {
            if ((*entry)->unk5 == expected) {
                count++;
            }
            index++;
            entry++;
        } while (index < 0x16U);
        if (count == 0x16) {
            self->ext.effect_24.unk1B = 0;
            self->unk5++;
        }
    }
}

#include "common.h"
#include "mmx6/x4.h"
extern struct X4_EffectObj* D_800E4498[22];

void func_8005378C(struct X4_EffectObj* self) {
    D_800E4498[self->ext.effect_24.unk1B]->unk5++;
    if (++self->ext.effect_24.unk1B == 0x16) {
        self->ext.effect_24.timer = 0x3C;
        self->unk5++;
    }
}

/* Adapted from sozud/mmx4 @807a01b src/main/effects/effect_24_boss_warning.c:boss_warning_finish, AGPL-3.0; proven shared with X6 by exact signature 7ccb25922a7c (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"

void func_800537F0(struct X4_EffectObj* self) {
    self->ext.effect_24.unk1A = 0xA;
    if (--self->ext.effect_24.timer == 0) {
        self->state++;
    }
}

/* Adapted from sozud/mmx4 @807a01b src/main/effects/effect_24_boss_warning.c:boss_warning_main, AGPL-3.0; proven shared with X6 by exact signature f335fb55e436 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern void (*D_8007ACE8[])(struct X4_EffectObj*);
s32 play_sound(s32, s32, void*);

void func_80053828(struct X4_EffectObj* self) {
    D_8007ACE8[self->unk5](self);
    if (self->ext.effect_24.unk1A == 0) {
        play_sound(0, SATURN_SOUND(0x13, 0x15), 0);
        self->ext.effect_24.unk1A = 0x3C;
    } else {
        self->ext.effect_24.unk1A--;
    }
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_8005389C(void) {
    ((M2C_UNK(*)())clear_object_slot)();
}

#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void start_pad_vibration(s32);
void stop_cd_audio();
void func_8002C0DC(s32, s32);
struct X4_QuadObj* alloc_class6_slot(void);
void func_80049E50(struct X4_MainObj* self);
extern s8 D_800CCEEB;

void func_800538BC(void* arg0) {
    void* temp_v0;
    void* temp_v0_2;
    void* temp_v0_3;
    u16 temp_v0_4;

    temp_v0 = ((void* (*)())alloc_class6_slot)();
    if (temp_v0 != 0) {
        M2C_FIELD(temp_v0, s8*, 0) = 1;
        M2C_FIELD(temp_v0, s8*, 1) = 4;
        M2C_FIELD(temp_v0, u16*, 8) = (u16)M2C_FIELD(arg0, u16*, 0x1C);
        M2C_FIELD(temp_v0, u16*, 0xA) = (u16)M2C_FIELD(arg0, u16*, 0xA);
        M2C_FIELD(temp_v0, u16*, 0xE) = (u16)M2C_FIELD(arg0, u16*, 0xE);
    }
    temp_v0_2 = ((void* (*)())alloc_class6_slot)(temp_v0);
    if (temp_v0_2 != 0) {
        M2C_FIELD(temp_v0_2, s8*, 0) = 1;
        M2C_FIELD(temp_v0_2, s8*, 1) = 4;
        M2C_FIELD(temp_v0_2, s16*, 8) =
            (s16)((M2C_FIELD(arg0, u16*, 0x1C) + 0x555) & 0xFFF);
        M2C_FIELD(temp_v0_2, u16*, 0xA) = (u16)M2C_FIELD(arg0, u16*, 0xA);
        M2C_FIELD(temp_v0_2, u16*, 0xE) = (u16)M2C_FIELD(arg0, u16*, 0xE);
    }
    temp_v0_3 = ((void* (*)())alloc_class6_slot)(temp_v0_2);
    if (temp_v0_3 != 0) {
        M2C_FIELD(temp_v0_3, s8*, 0) = 1;
        M2C_FIELD(temp_v0_3, s8*, 1) = 4;
        M2C_FIELD(temp_v0_3, s16*, 8) =
            (s16)((M2C_FIELD(arg0, u16*, 0x1C) + 0xAAA) & 0xFFF);
        M2C_FIELD(temp_v0_3, u16*, 0xA) = (u16)M2C_FIELD(arg0, u16*, 0xA);
        M2C_FIELD(temp_v0_3, u16*, 0xE) = (u16)M2C_FIELD(arg0, u16*, 0xE);
    }
    func_8002C0DC(0x82, 0);
    temp_v0_4 = M2C_FIELD(arg0, u16*, 0x14);
    if (temp_v0_4 != 0) {
        M2C_FIELD(arg0, u16*, 0x14) = (u16)(temp_v0_4 - 1);
        func_80049E50(arg0);
        return;
    }
    M2C_FIELD(arg0, u16*, 0x14) = 0x64;
    M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
    if (M2C_FIELD(arg0, s8*, 2) != 1) {
        ((s32(*)())stop_cd_audio)();
        D_800CCEEB = 0;
    }
    start_pad_vibration(0xA);
}

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

s32 func_80013AA4(s8 arg0);
struct X4_QuadObj* alloc_class6_slot(void);
s32 random_byte();
s32 func_8002D30C();
void func_80049F98();

void func_80053A20(struct X4_BaseObj* self) {
    struct X4_QuadObj* q;
    u32 i;

    if (*(u16*)&self->bg_offset != 0) {
        // !FAKE: depin: dropping it breaks the match (74/83)
        register s32 b asm("$3");
        (*(u16*)&self->bg_offset)--;
        b = self->unk16 - 1;
        self->unk16 = b;
        if ((b << 24) == 0) {
            self->unk16 = 4;
            func_80049F98(self, 1, 0x60, 0x60, 2);
        }
        if (!(func_8002D30C() & 1)) {
            q = alloc_class6_slot();
            if (q != 0) {
                q->active = 1;
                q->id = 4;
                random_byte();
                q->x_pos.u.lo = D_80090E70 & 0xFFF;
                q->x_pos.u.hi = self->x_pos.u.hi;
                q->y_pos.u.hi = self->y_pos.u.hi;
            }
        }
    } else {
        for (i = 0; i < 16; i++) {
            struct X4_QuadObj* p = alloc_class6_slot();
            if (p != 0) {
                p->active = 1;
                p->id = 6;
                p->x_pos.u.hi = self->x_pos.u.hi;
                p->y_pos.u.hi = self->y_pos.u.hi;
                p->unk6 = i;
            }
        }
        func_80013AA4(0x19);
        {
            // !FAKE: depin: dropping it breaks the match (80/83)
            register s32 s asm("$2") = (u8)self->state + 1;
            self->state = s;
        }
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

s32 play_sound(s32 a0, s32 a1, void* arg2);
struct X4_QuadObj* alloc_class6_slot(void);
s32 random_byte();
s32 func_8002D30C();
void func_80049F98();
#include "mmx6/state.h"
#include "mmx6/globals.h"

void func_80053B6C(struct X4_EffectObj* self) {
    struct X4_QuadObj* q;
    struct X4_QuadObj* q2;
    s32 t;

    t = *((u8*)self + 0x16) - 1;
    *((u8*)self + 0x16) = t;
    if ((t << 24) == 0) {
        *((u8*)self + 0x16) = 4;
        func_80049F98(self, 1, 0x60, 0x60, 2);
    }
    if (!(func_8002D30C() & 1)) {
        q = alloc_class6_slot();
        if (q != 0) {
            q->active = 1;
            q->id = 4;
            random_byte();
            q->x_pos.u.lo = D_80090E70 & 0xFFF;
            q->x_pos.u.hi = self->x_pos.u.hi;
            q->y_pos.u.hi = self->y_pos.u.hi;
        }
    }
    if (!(random_byte() & 3)) {
        q2 = alloc_class6_slot();
        if (q2 != 0) {
            q2->active = 1;
            q2->id = 6;
            q2->x_pos.u.hi = self->x_pos.u.hi;
            q2->y_pos.u.hi = self->y_pos.u.hi;
        }
    }
    if (D_80097420.transition.fade_amount == 0) {
        self->state++;
        if (self->active & 0x80) {
            *(s16*)((u8*)self + 0x14) = 0xC8;
        } else {
            *(s16*)((u8*)self + 0x14) = 0x28;
        }
        do {
        } while (0);
        self->unk7 = 1;
        D_800CCEF4 = 0;
        play_sound(0, 5, 0);
        D_800C4560 = 1;
    }
}

#define func_80041AB8 func_80053CDC
#define D_80075FD8 D_8007AD08
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "common.h"
#include "mmx6/globals.h"

#define NULL ((void*)0)
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

struct X4_QuadObj* alloc_class6_slot(void); /* extern */
s32 random_byte();                          /* extern */

void func_80053D18(void* arg0) {
    void* temp_v0;
    void* temp_v0_2;
    void* temp_v0_3;

    random_byte();
    M2C_FIELD(arg0, u16*, 0x1C) = (u16)(D_80090E70 & 0xFFF);
    temp_v0 = ((void* (*)())alloc_class6_slot)();
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, s8*, 0) = 1;
        M2C_FIELD(temp_v0, s8*, 1) = 4;
        M2C_FIELD(temp_v0, u16*, 8) = (u16)M2C_FIELD(arg0, u16*, 0x1C);
        M2C_FIELD(temp_v0, u16*, 0xA) = (u16)M2C_FIELD(arg0, u16*, 0xA);
        M2C_FIELD(temp_v0, u16*, 0xE) = (u16)M2C_FIELD(arg0, u16*, 0xE);
    }
    temp_v0_2 = ((void* (*)())alloc_class6_slot)(temp_v0);
    if (temp_v0_2 != NULL) {
        M2C_FIELD(temp_v0_2, s8*, 0) = 1;
        M2C_FIELD(temp_v0_2, s8*, 1) = 4;
        M2C_FIELD(temp_v0_2, s16*, 8) =
            (s16)((M2C_FIELD(arg0, u16*, 0x1C) + 0x555) & 0xFFF);
        M2C_FIELD(temp_v0_2, u16*, 0xA) = (u16)M2C_FIELD(arg0, u16*, 0xA);
        M2C_FIELD(temp_v0_2, u16*, 0xE) = (u16)M2C_FIELD(arg0, u16*, 0xE);
    }
    temp_v0_3 = ((void* (*)())alloc_class6_slot)(temp_v0_2);
    if (temp_v0_3 != NULL) {
        M2C_FIELD(temp_v0_3, s8*, 0) = 1;
        M2C_FIELD(temp_v0_3, s8*, 1) = 4;
        M2C_FIELD(temp_v0_3, s16*, 8) =
            (s16)((M2C_FIELD(arg0, u16*, 0x1C) + 0xAAA) & 0xFFF);
        M2C_FIELD(temp_v0_3, u16*, 0xA) = (u16)M2C_FIELD(arg0, u16*, 0xA);
        M2C_FIELD(temp_v0_3, u16*, 0xE) = (u16)M2C_FIELD(arg0, u16*, 0xE);
    }
    M2C_FIELD(arg0, s16*, 0x14) = 8;
    M2C_FIELD(arg0, s8*, 0x16) = 4;
    M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

struct X4_QuadObj* alloc_class6_slot(void);
s32 random_byte();
s32 func_8002D30C();
void func_80049F98();

void func_80053E44(struct X4_EffectObj* self) {
    struct X4_QuadObj* q;
    struct X4_QuadObj* q2;
    // !FAKE: depin: dropping it breaks the match (63/72)
    register s32 c asm("$2");
    s32 t;

    c = *(u16*)((u8*)self + 0x14);
    if (c != 0) {
        *(u16*)((u8*)self + 0x14) = c - 1;
        t = *((u8*)self + 0x16) - 1;
        *((u8*)self + 0x16) = t;
        if ((t << 24) == 0) {
            *((u8*)self + 0x16) = 4;
            func_80049F98(self, 1, 0x60, 0x60, 2);
        }
        if (!(func_8002D30C() & 1)) {
            q = alloc_class6_slot();
            if (q != 0) {
                q->active = 1;
                q->id = 4;
                random_byte();
                q->x_pos.u.lo = D_80090E70 & 0xFFF;
                q->x_pos.u.hi = self->x_pos.u.hi;
                q->y_pos.u.hi = self->y_pos.u.hi;
            }
        }
    } else {
        self->state++;
        q2 = alloc_class6_slot();
        if (q2 != 0) {
            q2->active = 1;
            q2->id = 8;
            q2->x_pos.u.hi = self->x_pos.u.hi;
            q2->y_pos.u.hi = self->y_pos.u.hi;
        }
        *(u16*)((u8*)self + 0x14) = 10;
    }
}

#include "common.h"

void func_80013A48(s8 arg0);

void func_80053F64(void* arg0) {
    u8* p = (u8*)arg0;
    s32 temp_v0;

    temp_v0 = *(u16*)(p + 0x14) - 1;
    *(u16*)(p + 0x14) = temp_v0;
    if ((temp_v0 & 0xFFFF) == 0xFFFF) {
        func_80013A48(0x19);
        p[4] = p[4] + 1;
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_80053FB8(void* arg0) {
    if (D_80097420.transition.fade_amount == 0) {
        M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
    }
}

#include "common.h"
#include "mmx6/globals.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_80053FE4(void) {
    D_800CCEEC = 1;
    ((M2C_UNK(*)())clear_object_slot)();
}

/* Adapted from sozud/mmx4 @807a01b src/main/effects/effect_27_teleport_intro.c:teleport_intro_spawn_quads, AGPL-3.0; proven shared with X6 by exact signature 6c6bde588dbe (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/system.h"
struct X4_QuadObj* alloc_class6_slot(void);

void func_8005400C(struct X4_EffectObj* self) {
    struct X4_QuadObj* X4_quad;
    u32 var_i;

    switch (self->unk5) {
    case 0:
        X4_quad = alloc_class6_slot();
        if (X4_quad != NULL) {
            X4_quad->active = 0x81;
            X4_quad->id = 7;
            X4_quad->unk2 = 0;
            X4_quad->link.owner = self;
        }
        self->unk5 = 1;
        self->ext.effect_27.unk14++;
        return;
    case 1:
        var_i = 0;
        // spawn blue quads behind "READY"
        if (self->ext.effect_27.unk14 == 0) {
            self->ext.effect_27.unk14 = 0;
            do {
                X4_quad = alloc_class6_slot();
                if (X4_quad != NULL) {
                    X4_quad->active = 0x81;
                    X4_quad->id = 7;
                    X4_quad->unk2 = 1;
                    X4_quad->unk7 = var_i;
                    X4_quad->link.owner = self;
                    self->ext.effect_27.unk14++;
                }
                var_i += 1;
            } while (var_i < 0xA);
            self->unk5 = 2;
            return;
        }
        return;
    case 2:
        var_i = 0;
        if (self->ext.effect_27.unk14 == 0) {
            self->ext.effect_27.unk14 = 0;
            do {
                X4_quad = alloc_class6_slot();
                if (X4_quad != NULL) {
                    X4_quad->active = 0x81;
                    X4_quad->id = 7;
                    X4_quad->unk2 = 2;
                    X4_quad->unk7 = random_byte() & 3;
                    X4_quad->link.owner = self;
                    self->ext.effect_27.unk14++;
                }
                var_i += 1;
            } while (var_i < 8);
            self->unk5 = 3;
            return;
        }
        break;
    case 3:
        if (self->ext.effect_27.unk14 == 0) {
            self->ext.effect_27.unk14 = 0;
            self->ext.effect_27.unk16 = 1;
        }
        break;
    }
}

#define func_80041AB8 func_800541D4
#define D_80075FD8 D_8007AD28
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_80054210(void* arg0) {
    if (D_80097420.transition.active == 0) {
        M2C_FIELD(arg0, s8*, 0x14) = 0;
        M2C_FIELD(arg0, s8*, 0x15) = 0;
        M2C_FIELD(arg0, s8*, 0x16) = 0;
        M2C_FIELD(arg0, s8*, 4) = 1;
        M2C_FIELD(arg0, s8*, 5) = 0;
    }
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_80054240(void) {
    ((M2C_UNK(*)())clear_object_slot)();
}

void func_80054260(void) {
}

void func_80054268(void) {
}

void func_80054270(void) {
}

void func_80054278(void) {
}

void func_80054280(void) {
}

void func_80054288(void) {
}

void func_80054290(void) {
}

void func_80054298(void) {
}

void func_800542A0(void) {
}

void func_800542A8(void) {
}

void func_800542B0(void) {
}

void func_800542B8(void) {
}

void func_800542C0(void) {
}

void func_800542C8(void) {
}

void func_800542D0(void) {
}

void func_800542D8(void) {
}

void func_800542E0(void) {
}

void func_800542E8(void) {
}

void func_800542F0(void) {
}

void func_800542F8(void) {
}

void func_80054300(void) {
}

void func_80054308(void) {
}

void func_80054310(void) {
}

void func_80054318(void) {
}

void func_80054320(void) {
}

void func_80054328(void) {
}

void func_80054330(void) {
}

void func_80054338(void) {
}

void func_80054340(void) {
}

void func_80054348(void) {
}

void func_80054350(void) {
}

void func_80054358(void) {
}

void func_80054360(void) {
}

void func_80054368(void) {
}

void func_80054370(void) {
}

void func_80054378(void) {
}

void func_80054380(void) {
}

void func_80054388(void) {
}

void func_80054390(void) {
}

void func_80054398(void) {
}

void func_800543A0(void) {
}

void func_800543A8(void) {
}

void func_800543B0(void) {
}

void func_800543B8(void) {
}

void func_800543C0(void) {
}

void func_800543C8(void) {
}

void func_800543D0(void) {
}

void func_800543D8(void) {
}

void func_800543E0(void) {
}

void func_800543E8(void) {
}

void func_800543F0(void) {
}

void func_800543F8(void) {
}

void func_80054400(void) {
}

void func_80054408(void) {
}

void func_80054410(void) {
}

void func_80054418(void) {
}

void func_80054420(void) {
}

void func_80054428(void) {
}

void func_80054430(void) {
}

void func_80054438(void) {
}

void func_80054440(void) {
}

void func_80054448(void) {
}

void func_80054450(void) {
}

void func_80054458(void) {
}

void func_80054460(void) {
}

void func_80054468(void) {
}

void func_80054470(void) {
}

void func_80054478(void) {
}

void func_80054480(void) {
}

void func_80054488(void) {
}

void func_80054490(void) {
}

void func_80054498(void) {
}

void func_800544A0(void) {
}

void func_800544A8(void) {
}

void func_800544B0(void) {
}

void func_800544B8(void) {
}

void func_800544C0(void) {
}

void func_800544C8(void) {
}

void func_800544D0(void) {
}

void func_800544D8(void) {
}

void func_800544E0(void) {
}

void func_800544E8(void) {
}

void func_800544F0(void) {
}

void func_800544F8(void) {
}

void func_80054500(void) {
}

void func_80054508(void) {
}

void func_80054510(void) {
}

void func_80054518(void) {
}

void func_80054520(void) {
}

void func_80054528(void) {
}

void func_80054530(void) {
}

void func_80054538(void) {
}

void func_80054540(void) {
}

void func_80054548(void) {
}

void func_80054550(void) {
}

void func_80054558(void) {
}

void func_80054560(void) {
}

void func_80054568(void) {
}

void func_80054570(void) {
}

void func_80054578(void) {
}

void func_80054580(void) {
}

void func_80054588(void) {
}

void func_80054590(void) {
}

void func_80054598(void) {
}

void func_800545A0(void) {
}

void func_800545A8(void) {
}

void func_800545B0(void) {
}

void func_800545B8(void) {
}

void func_800545C0(void) {
}

void func_800545C8(void) {
}

void func_800545D0(void) {
}

void func_800545D8(void) {
}

void func_800545E0(void) {
}

void func_800545E8(void) {
}

void func_800545F0(void) {
}

void func_800545F8(void) {
}

void func_80054600(void) {
}

void func_80054608(void) {
}

void func_80054610(void) {
}

void func_80054618(void) {
}

void func_80054620(void) {
}

void func_80054628(void) {
}

void func_80054630(void) {
}

void func_80054638(void) {
}

void func_80054640(void) {
}

void func_80054648(void) {
}

void func_80054650(void) {
}

void func_80054658(void) {
}

void func_80054660(void) {
}

void func_80054668(void) {
}

void func_80054670(void) {
}

void func_80054678(void) {
}

void func_80054680(void) {
}

void func_80054688(void) {
}

void func_80054690(void) {
}

void func_80054698(void) {
}

void func_800546A0(void) {
}

void func_800546A8(void) {
}

void func_800546B0(void) {
}

void func_800546B8(void) {
}

void func_800546C0(void) {
}

void func_800546C8(void) {
}

void func_800546D0(void) {
}

void func_800546D8(void) {
}

void func_800546E0(void) {
}

void func_800546E8(void) {
}

void func_800546F0(void) {
}

void func_800546F8(void) {
}

void func_80054700(void) {
}

void func_80054708(void) {
}

void func_80054710(void) {
}

void func_80054718(void) {
}

void func_80054720(void) {
}

void func_80054728(void) {
}

void func_80054730(void) {
}

void func_80054738(void) {
}

void func_80054740(void) {
}

void func_80054748(void) {
}

void func_80054750(void) {
}

void func_80054758(void) {
}

void func_80054760(void) {
}

void func_80054768(void) {
}

void func_80054770(void) {
}

void func_80054778(void) {
}

void func_80054780(void) {
}

void func_80054788(void) {
}

void func_80054790(void) {
}

void func_80054798(void) {
}

void func_800547A0(void) {
}

void func_800547A8(void) {
}

void func_800547B0(void) {
}

void func_800547B8(void) {
}

void func_800547C0(void) {
}

void func_800547C8(void) {
}

void func_800547D0(void) {
}

void func_800547D8(void) {
}

void func_800547E0(void) {
}

void func_800547E8(void) {
}

void func_800547F0(void) {
}

void func_800547F8(void) {
}

void func_80054800(void) {
}

void func_80054808(void) {
}

void func_80054810(void) {
}

void func_80054818(void) {
}

void func_80054820(void) {
}

void func_80054828(void) {
}

void func_80054830(void) {
}

void func_80054838(void) {
}

void func_80054840(void) {
}

void func_80054848(void) {
}

void func_80054850(void) {
}

void func_80054858(void) {
}

void func_80054860(void) {
}

void func_80054868(void) {
}

void func_80054870(void) {
}

void func_80054878(void) {
}

void func_80054880(void) {
}

void func_80054888(void) {
}

void func_80054890(void) {
}

void func_80054898(void) {
}

void func_800548A0(void) {
}

void func_800548A8(void) {
}

void func_800548B0(void) {
}

void func_800548B8(void) {
}

void func_800548C0(void) {
}

void func_800548C8(void) {
}

void func_800548D0(void) {
}

void func_800548D8(void) {
}

void func_800548E0(void) {
}

void func_800548E8(void) {
}

void func_800548F0(void) {
}

void func_800548F8(void) {
}

void func_80054900(void) {
}

void func_80054908(void) {
}

void func_80054910(void) {
}

void func_80054918(void) {
}

void func_80054920(void) {
}

void func_80054928(void) {
}

void func_80054930(void) {
}

void func_80054938(void) {
}

void func_80054940(void) {
}

void func_80054948(void) {
}

void func_80054950(void) {
}

void func_80054958(void) {
}

void func_80054960(void) {
}

void func_80054968(void) {
}

void func_80054970(void) {
}

void func_80054978(void) {
}

void func_80054980(void) {
}

void func_80054988(void) {
}

void func_80054990(void) {
}

void func_80054998(void) {
}

void func_800549A0(void) {
}

void func_800549A8(void) {
}

void func_800549B0(void) {
}

void func_800549B8(void) {
}

void func_800549C0(void) {
}

void func_800549C8(void) {
}

void func_800549D0(void) {
}

void func_800549D8(void) {
}

void func_800549E0(void) {
}

void func_800549E8(void) {
}

void func_800549F0(void) {
}

void func_800549F8(void) {
}

void func_80054A00(void) {
}

void func_80054A08(void) {
}

void func_80054A10(void) {
}

void func_80054A18(void) {
}

void func_80054A20(void) {
}

void func_80054A28(void) {
}

void func_80054A30(void) {
}

void func_80054A38(void) {
}

void func_80054A40(void) {
}

void func_80054A48(void) {
}

void func_80054A50(void) {
}

void func_80054A58(void) {
}

void func_80054A60(void) {
}

void func_80054A68(void) {
}

void func_80054A70(void) {
}

void func_80054A78(void) {
}

void func_80054A80(void) {
}

void func_80054A88(void) {
}

void func_80054A90(void) {
}

void func_80054A98(void) {
}

void func_80054AA0(void) {
}

void func_80054AA8(void) {
}

void func_80054AB0(void) {
}

void func_80054AB8(void) {
}

void func_80054AC0(void) {
}

void func_80054AC8(void) {
}
