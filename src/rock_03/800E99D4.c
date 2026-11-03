// clang-format off
INCLUDE_ASM("asm/rock_03/nonmatchings/E9860", func_800E99D4);
// clang-format on

#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
void func_800EAB3C(u8* arg0, u8 arg1);
extern u8 D_800F70C4[];
#define SPAD4C (*(u8**)0x1F80004C)

void func_800E9B80(u8* arg0) {
    s8 t;

    play_sound(2, 6, arg0);
    *(u8**)(arg0 + 0x50) = SPAD4C + 0x80;
    t = arg0[2];
    *(u8**)(arg0 + 0x54) = SPAD4C + 0x80;
    if (t == 0) {
        set_animation(arg0, 2);
        SPAD4C[0x81] = 0x1A - D_800F70C4[(s8)arg0[0x45] - 1];
        SPAD4C[0x83] = D_800F70C4[(s8)arg0[0x45] - 1];
        func_800EAB3C(arg0, 0);
    } else if (t == 1) {
        set_animation(arg0, 0x10);
        ((s8*)SPAD4C)[0x81] = -0x1E;
        SPAD4C[0x83] = D_800F70C4[(s8)arg0[0x45] - 1];
        func_800EAB3C(arg0, 1);
    }
    arg0[6]++;
}

#undef SPAD4C

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
extern u8 D_800F6CBC[];
extern u8 D_800F6CC0[];
extern u8 D_800F70C4[];
#define SPAD4C (*(u8**)0x1F80004C)

void func_800E9C98(u8* arg0) {
    s8 t = arg0[2];

    if (t == 0) {
        SPAD4C[0x81] = 0x1A - D_800F70C4[(s8)arg0[0x45] - 1];
        SPAD4C[0x83] = D_800F70C4[(s8)arg0[0x45] - 1];
    } else if (t == 1) {
        ((s8*)SPAD4C)[0x81] = -0x1E;
        SPAD4C[0x83] = D_800F70C4[(s8)arg0[0x45] - 1];
    }
    if ((s8)arg0[0x45] == 0x1C) {
        s8 s = arg0[2];
        *(u8**)(arg0 + 0x50) = D_800F6CBC;
        *(u8**)(arg0 + 0x54) = D_800F6CC0;
        if (s == 0) {
            ((void (*)(void*, s32))set_animation)(arg0, 4);
        } else if (s == 1) {
            ((void (*)(void*, s32))set_animation)(arg0, 0x12);
        }
        if (D_800CCF38 >= 2) {
            *(s16*)(arg0 + 0x7C) = 0xF;
        } else {
            *(s16*)(arg0 + 0x7C) = 0x1E;
        }
        arg0[6]++;
    }
}

#undef SPAD4C

#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

M2C_UNK set_animation(void*, M2C_UNK);
s32 is_off_screen(s32, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
extern struct X4_PlayerObj g_Player;
extern s32 D_800F7154;
extern s32 D_800F7158;
extern s32 D_800F715C;

void func_800E9DCC(struct X4_MainObj* self) {
    s32 a;

    self->contact_damage = 4;
    self->hp = 1;
    self->collision_data = &D_8007429C;
    self->unk16 = 5;
    self->air_state = 1;
    set_animation(self, 0xA);
    {
        // !FAKE: depin: dropping it breaks the match (69/74)
        register void* r asm("$2") = &D_800F7154;
        // !FAKE: depin: dropping it breaks the match (65/74)
        register void* q asm("$3") = &D_800F7158;
        self->terrain_box = r;
        self->attack_box = q;
        self->state = 1;
        self->hurt_box = &D_800F715C;
    }
    self->action = 0;
    self->action_phase = 0;
    self->unk7 = 0;
    {
        s32 px = g_Player.x_pos.i.hi;
        s32 py = g_Player.y_pos.i.hi;
        a = ratan2(self->y_pos.i.hi - py, px - self->x_pos.i.hi);
    }
    self->x_accel = 0;
    self->gravity = 0;
    {
        s32 t = rcos(a);
        s32 u = t << 4;
        self->x_speed = (t << 6) + u;
    }
    {
        s32 t = rsin(a);
        s32 u = t << 4;
        self->y_speed = (t << 6) + u;
    }
    if (is_off_screen(self, 0x20, 0x20) == 0) {
        func_8002CCB0(self, 0x10, 0x10);
        return;
    }
    self->state++;
}

#include "../shared/commander_yammark/func_800E9EF4.c"

#include "../shared/commander_yammark/func_800EA0B0.c"

#define func_80041AB8 func_800EA264
#define D_80075FD8 D_800F70E0
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#define func_80041AB8 func_800EA2A0
#define D_80075FD8 D_800F7160
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#define func_80041AB8 func_800EA2DC
#define D_80075FD8 D_800F716C
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "../shared/commander_yammark/func_800EA318.c"

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002CA14(); /* extern */

void func_800EA404(void) {
    func_8002CA14();
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002CA54(); /* extern */

void func_800EA424(void) {
    func_8002CA54();
}

#define func_8003744C func_800EA444
#define D_80073C1C D_800F7110
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/commander_yammark/func_800EA480.c"

#include "../shared/commander_yammark/func_800EA4DC.c"

#define func_8003744C func_800EA564
#define D_80073C1C D_800F7118
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/commander_yammark/func_800EA5A0.c"

#define func_8003744C func_800EA5CC
#define D_80073C1C D_800F7124
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/commander_yammark/func_800EA608.c"

#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
void func_800EAB3C(u8* arg0, u8 arg1);

void func_800EA66C(u8* arg0) {
    s8 t;

    if (--*(s16*)(arg0 + 0x7C) == 0) {
        play_sound(2, 7, arg0);
        t = arg0[2];
        if (t == 0) {
            func_800EAB3C(arg0, 2);
        } else if (t == 1) {
            func_800EAB3C(arg0, 3);
        }
        *(u16*)(arg0 + 0x7C) = 0x14;
        arg0[6]++;
    }
}

#include "../shared/commander_yammark/func_800EA6FC.c"

#define func_8003744C func_800EA728
#define D_80073C1C D_800F7130
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/commander_yammark/func_800EA764.c"

#include "../shared/commander_yammark/func_800EA7E4.c"

#define func_8003744C func_800EA834
#define D_80073C1C D_800F7138
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK set_animation(void*, M2C_UNK);       /* extern */

void func_800EA870(void* arg0) {
    s8 temp_v1;

    play_sound(2, 6, arg0);
    temp_v1 = M2C_FIELD(arg0, s8*, 2);
    M2C_FIELD(arg0, s32*, 0x68) = 0;
    M2C_FIELD(arg0, s32*, 0x50) = 0;
    M2C_FIELD(arg0, s32*, 0x54) = 0;
    if (temp_v1 == 0) {
        set_animation(arg0, 0x16);
    } else if (temp_v1 == 1) {
        set_animation(arg0, 0x17);
    }
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EA8E8(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        M2C_FIELD(arg0, s16*, 0x7C) = 0x78;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#include "../shared/commander_yammark/func_800EA910.c"

#define func_8003744C func_800EA93C
#define D_80073C1C D_800F7144
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#define M2C_UNK s32

#define SPAD (*(u8**)0x1F80004C)

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK apply_object_motion();
void func_800EABF0(u8* arg0, s16 arg1, u8 arg2);

void func_800EA978(u8* arg0) {
    set_animation(arg0, 7);
    *(u16*)(arg0 + 0xE) = *(u16*)(SPAD + 0x84) - 0x1A;
    func_800EABF0(arg0, *(s16*)(SPAD + 0x84), 0x11);
    *(s32*)(arg0 + 0x20) = 0;
    *(s32*)(arg0 + 0x28) = 0;
    *(s32*)(arg0 + 0x24) = 0x88888;
    *(s32*)(arg0 + 0x2C) = 0x48D1;
    apply_object_motion(arg0);
    {
        // !FAKE: depin: dropping it breaks the match (32/35)
        register s32 t asm("$2") = arg0[6] + 1;
        arg0[6] = t;
    }
}

#include "../shared/commander_yammark/func_800EAA04.c"

#include "common.h"
#define M2C_UNK s32

#define SPAD (*(u8**)0x1F80004C)

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK apply_object_motion();
void func_800EABF0(u8* arg0, s16 arg1, u8 arg2);
extern s16 D_800970AA;

void func_800EAA78(u8* arg0) {
    s16 x;
    s32 d;

    set_animation(arg0, 7);
    *(u16*)(arg0 + 0xE) = *(u16*)(SPAD + 0x84) - 0x1A;
    func_800EABF0(arg0, *(s16*)(SPAD + 0x84), 0x11);
    d = D_800970AA;
    x = *(s16*)(arg0 + 0xA);
    *(s32*)(arg0 + 0x20) = (d - x) << 11;
    *(s32*)(arg0 + 0x28) = 0;
    *(s32*)(arg0 + 0x24) = 0x80000;
    *(s32*)(arg0 + 0x2C) = 0x8000;
    apply_object_motion(arg0);
    {
        // !FAKE: depin: dropping it breaks the match (36/39)
        register s32 t asm("$2") = arg0[6] + 1;
        arg0[6] = t;
    }
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK apply_object_motion(); /* extern */

void func_800EAB14(void) {
    apply_object_motion();
}

#include "common.h"

void func_800EAB34(void) {
}

#include "common.h"

void* alloc_sprite_slot();

void func_800EAB3C(u8* arg0, u8 arg1) {
    u8* obj;

    obj = alloc_sprite_slot();
    if (obj != 0) {
        obj[0] = 0x41;
        obj[1] = 5;
        obj[2] = arg1;
        obj[0x15] = arg0[0x15];
        *(u16*)(obj + 0x40) = *(u16*)(arg0 + 0x40);
        *(u16*)(obj + 0x42) = *(u16*)(arg0 + 0x42) & 0x7FFF;
        *(s32*)(obj + 0x30) = *(s32*)(arg0 + 0x30);
        *(s32*)(obj + 0x3C) = *(s32*)(arg0 + 0x3C);
        obj[0x14] = arg0[0x14];
        *(u16*)(obj + 0xA) = *(u16*)(arg0 + 0xA);
        *(u16*)(obj + 0x8) = 0;
        *(u16*)(obj + 0xE) = *(u16*)(arg0 + 0xE);
        *(u16*)(obj + 0xC) = 0;
        *(u8**)(obj + 0x50) = arg0;
    }
}

#include "../shared/commander_yammark/func_800EABF0.c"

#define func_80042C18 func_800EACB0
#include "../shared/commander_yammark/func_80042C18.c"
#undef func_80042C18

#include "../shared/commander_yammark/func_800EACE0.c"

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EADCC(void) {
    clear_object_slot();
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EADEC(void) {
    clear_object_slot();
}

#include "../shared/commander_yammark/func_800EAE0C.c"

#include "../shared/commander_yammark/func_800EAE94.c"

#include "common.h"
#include "mmx6/x4.h"

s32 random_byte();
extern struct X4_BackgroundObj background_objects[3];
extern u16 D_800F729C[];

#define H(p, o) (*(s16*)((u8*)(p) + (o)))
#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define UH(p, o) (*(u16*)((u8*)(p) + (o)))

void func_800EB0A0(void* arg0) {
    s32 a;
    s32 d;
    s32 b;
    s32 e;

    a = H(arg0, 0xA) - 0xA0;
    d = background_objects[0].x_pos.i.hi - a;
    if (d >= 0) {
        if (d < 0xA0) {
            // !FAKE: range test needs per-sign compares jumping to one shared block (C0144); abs() form folds to a negate
            goto x_near;
        }
    } else if (a - background_objects[0].x_pos.i.hi < 0xA0) {
    x_near:
        b = H(arg0, 0xE) - 0x78;
        e = background_objects[0].y_pos.i.hi - b;
        if (e >= 0) {
            if (e < 0x78) {
                // !FAKE: range test needs per-sign compares jumping to one shared block (C0144); abs() form folds to a negate
                goto y_near;
            }
        } else if (b - background_objects[0].y_pos.i.hi < 0x78) {
        y_near:
            UH(arg0, 0x7C) = D_800F729C[random_byte() & 7];
            UB(arg0, 6) = UB(arg0, 6) + 1;
        }
    }
}

#include "../shared/commander_yammark/func_800EB170.c"

#define func_80041AB8 func_800EB2C8
#define D_80075FD8 D_800F7254
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#define func_80041AB8 func_800EB304
#define D_80075FD8 D_800F7300
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#define func_80041AB8 func_800EB340
#define D_80075FD8 D_800F730C
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define SPAD (*(u8**)0x1F80004C)

M2C_UNK set_animation(void*, M2C_UNK);
void func_800EBABC(u8* arg0, u8 arg1);
extern s32 D_800F7180;
extern s32 D_800F7184;
extern s32 D_800F7234;

void func_800EB37C(struct X4_MainObj* self) {
    self->contact_damage = 4;
    self->unk7C = 0;
    self->hp = 8;
    self->invincibility_timer = 0;
    self->on_screen = 0;
    if (self->unk2 == 0) {
        SPAD[0x88] = 1;
        self->action = 2;
        self->terrain_box = 0;
        self->hurt_box = &D_800F7184;
        self->attack_box = &D_800F7180;
    } else {
        SPAD[0x88] = 0;
        self->action = 5;
        self->terrain_box = 0;
        self->hurt_box = 0;
        self->attack_box = 0;
    }
    {
        u8 g;
        s32 y;
        g = D_800970B4;
        self->unk15 = 0;
        self->animation_table = (void*)&D_800F7234;
        self->unk16 = 5;
        self->air_state = 0;
        self->collision_data = &D_800743DC;
        self->bg_offset = g;
        self->unk18.val = self->x_pos.val;
        y = self->y_pos.val;
        self->unk1C.val = y;
        set_animation(self, 0);
    }
    self->x_speed = 0;
    self->y_speed = 0;
    self->x_accel = 0;
    self->gravity = 0;
    self->state = 1;
    self->action_phase = 0;
    func_800EBABC(self, 0);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK animate_object();
s32 is_off_screen(s32, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
M2C_UNK func_80049E50(void*);
void func_8004E654(struct X4_BaseObj* arg0, s8 arg1);
void func_800EBC20(struct X4_MainObj* self);
extern void (*D_800F7264[])(struct X4_MainObj*);

void func_800EB490(struct X4_MainObj* self) {
    s8 st;

    self->unk18.val = self->x_pos.val;
    self->unk1C.val = self->y_pos.val;
    if (self->action != 5) {
        func_800EBC20(self);
    }
    animate_object(self);
    {
        // !FAKE: depin: dropping it breaks the match (53/59)
        register void** tbl asm("$2") = (void**)D_800F7264;
        // !FAKE: depin: dropping it breaks the match (57/59)
        register void* fn asm("$5") = tbl[self->action];
        ((void (*)(struct X4_MainObj*))fn)(self);
    }
    if (check_enemy_hits(self) < 0) {
        func_80049E50(self);
        func_8004E654((struct X4_BaseObj*)self, 0x12);
        st = 2;
    } else {
        func_80030ECC(self);
        if (is_off_screen((s32)self, 0x50, 0xA0) == 0) {
            if (self->action != 5) {
                func_8002CCB0(self, 0x30, 0x40);
            }
            return;
        }
        st = 3;
    }
    self->state = st;
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002CA14(); /* extern */

void func_800EB57C(void) {
    func_8002CA14();
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002CA54(); /* extern */

void func_800EB59C(void) {
    func_8002CA54();
}

#define func_8003744C func_800EB5BC
#define D_80073C1C D_800F727C
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/commander_yammark/func_800EB5F8.c"

#include "../shared/commander_yammark/func_800EB644.c"

#include "../shared/commander_yammark/func_800EB6C4.c"

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EB708(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        M2C_FIELD(arg0, s8*, 5) = 3;
        M2C_FIELD(arg0, s8*, 6) = 0;
    }
}

#define func_8003744C func_800EB728
#define D_80073C1C D_800F728C
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/commander_yammark/func_800EB764.c"

#define func_8003744C func_800EB7A8
#define D_80073C1C D_800F7294
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/commander_yammark/func_800EB7E4.c"

#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32

#define SPAD (*(u8**)0x1F80004C)
#define F16(p, o) (*(s16*)((u8*)(p) + (o)))
#define FU16(p, o) (*(u16*)((u8*)(p) + (o)))
#define F32(p, o) (*(s32*)((u8*)(p) + (o)))
#define FU8(p, o) (*(u8*)((u8*)(p) + (o)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
void func_800EBB70(u8* arg0, u8 arg1);

void func_800EB870(void* arg0) {
    s32 s;
    s32 c;

    F32(SPAD, 0x80) += F32(SPAD, 0x84);
    F32(SPAD, 0x80) &= 0xFFF;
    s = (rcos(F32(SPAD, 0x80)) << 4) >> 12;
    c = (rsin(F32(SPAD, 0x80)) << 4) >> 12;
    F16(arg0, 0xA) = F16(SPAD, 0x8A) + s;
    F16(arg0, 0xE) = F16(SPAD, 0x8C) - c;
    if (--F16(arg0, 0x7C) == 0) {
        F16(arg0, 0x7C) = 0x14;
        play_sound(2, 5, arg0);
        func_800EBB70(arg0, 0);
        if (--F16(arg0, 0x7E) == 0) {
            FU8(arg0, 0x5) = 2;
            FU8(arg0, 0x6) = 0;
        }
    }
}

#include "common.h"

void func_800EB984(void) {
}

#define func_8003744C func_800EB98C
#define D_80073C1C D_800F72EC
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define SPAD (*(u8**)0x1F80004C)

M2C_UNK set_animation(void*, M2C_UNK);
s32 random_byte();
void func_800EBC20(struct X4_MainObj* self);
extern struct X4_BackgroundObj background_objects[3];
extern s32 D_800F7180;
extern s32 D_800F7184;
extern u16 D_800F72AC[];

void func_800EB9C8(u8* arg0) {
    s32 i;

    if ((s16)-- * (u16*)(arg0 + 0x7C) == -1) {
        *(u16*)(SPAD + 0x8A) = *(u16*)(arg0 + 0xA);
        *(u16*)(SPAD + 0x8C) = *(u16*)(arg0 + 0xE);
        SPAD[0x88] = 3;
        set_animation(arg0, 4);
        i = random_byte() & 0xF;
        *(u16*)(arg0 + 0xA) =
            background_objects[0].x_pos.i.hi + D_800F72AC[i * 2];
        *(u16*)(arg0 + 0xE) =
            background_objects[0].y_pos.i.hi + D_800F72AC[(i * 2) | 1];
        func_800EBC20((struct X4_MainObj*)arg0);
        *(s32**)(arg0 + 0x54) = &D_800F7184;
        *(s32**)(arg0 + 0x50) = &D_800F7180;
        arg0[6]++;
    }
}

#include "../shared/commander_yammark/func_800EBABC.c"

#include "../shared/commander_yammark/func_800EBB70.c"

#define func_80042C18 func_800EBC20
#include "../shared/commander_yammark/func_80042C18.c"
#undef func_80042C18

#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
extern s32 D_800F72F8;
extern s32 D_800F72FC;

void func_800EBC50(u8* arg0) {
    arg0[0x60] = 4;
    arg0[0x5C] = 0;
    *(s32*)(arg0 + 0x20) = 0;
    *(s32*)(arg0 + 0x24) = 0;
    *(s32*)(arg0 + 0x28) = 0;
    *(s32*)(arg0 + 0x2C) = 0;
    arg0[0x16] = 4;
    arg0[0x67] = 1;
    *(s32*)(arg0 + 0x54) = 0;
    set_animation(arg0, 7);
    {
        // !FAKE: depin: dropping it breaks the match (35/39)
        register s32 k asm("$2") = -0x3FFF;
        *(s32*)(arg0 + 0x24) = k;
    }
    arg0[4] = 1;
    *(s32*)(arg0 + 0x20) = 0;
    *(s32*)(arg0 + 0x28) = 0;
    *(s32*)(arg0 + 0x2C) = 0;
    *(s32**)(arg0 + 0x50) = &D_800F72F8;
    *(s32**)(arg0 + 0x68) = &D_800F72FC;
    arg0[5] = 0;
    arg0[6] = 0;
    arg0[7] = 0;
    arg0[3] = 0;
}

#include "../shared/commander_yammark/func_800EBCEC.c"

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EBD80(void) {
    clear_object_slot();
}

#include "../shared/commander_yammark/func_800EBDA0.c"

#include "../shared/commander_yammark/func_800EBE14.c"

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EBF4C(void) {
    clear_object_slot();
}

#include "../shared/commander_yammark/func_800EBF6C.c"

#include "../shared/commander_yammark/func_800EC144.c"

#include "../shared/commander_yammark/func_800EC25C.c"

#include "../shared/commander_yammark/func_800EC300.c"

// clang-format off
INCLUDE_ASM("asm/rock_03/nonmatchings/E9860", func_800EC368);
// clang-format on

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002CA54(); /* extern */

void func_800EC434(void) {
    func_8002CA54();
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002CA14(); /* extern */

void func_800EC454(void) {
    func_8002CA14();
}

#define func_800EC394 func_800EC474
#define D_800EFA9C D_800F7428
#include "../shared/commander_yammark/func_800EC394.c"
#undef func_800EC394
#undef D_800EFA9C

#include "../shared/commander_yammark/func_800EC4BC.c"

#include "../shared/commander_yammark/func_800EC520.c"

#include "../shared/commander_yammark/func_800EC564.c"

#include "../shared/commander_yammark/func_800EC5F4.c"

#include "../shared/commander_yammark/func_800EC66C.c"

#define func_80041AB8 func_800EC6FC
#define D_80075FD8 D_800F7434
#define FAMILY_FIELD 7
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#include "../shared/commander_yammark/func_800EC738.c"

#include "../shared/commander_yammark/func_800EC7A4.c"

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();
M2C_UNK apply_object_motion(void*);

extern M2C_UNK D_800F73EC;
extern M2C_UNK D_800F73F4;
extern M2C_UNK D_800F73FC;

#define F(type, off) M2C_FIELD(arg0, type*, off)

void func_800EC800(void* arg0) {
    apply_object_motion(arg0);
    animate_object(arg0);
    if (F(u8, 0x47) == 0x17 || F(u8, 0x47) == 0x10) {
        play_sound(2, 9, arg0);
        F(void*, 0x68) = &D_800F73EC;
        F(void*, 0x54) = &D_800F73FC;
        F(void*, 0x50) = &D_800F73F4;
        F(void*, 0x58) = &D_800743DC;
        set_animation(arg0, 4);
        {
            // !FAKE: depin: dropping it breaks the match (37/40)
            register s32 v asm("$2") = F(u8, 0x7) + 1;
            F(u8, 0x7) = v;
        }
    }
}

#undef F

#include "../shared/commander_yammark/func_800EC8A0.c"

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

M2C_UNK set_animation(void*, M2C_UNK);
s32 is_off_screen(s32, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
M2C_UNK func_80049E50(void*);
void func_8004E654(struct X4_BaseObj* arg0, s8 arg1);
extern M2C_UNK D_800F7690;
extern void (*D_800F76A8[])(void*);

#define G(type, off) (*(type*)((u8*)self + (off)))

void func_800EC8F0(void* self) {
    s32 r;

    D_800F76A8[G(s8, 5)](self);
    r = check_enemy_hits(self);
    if (r == -2 || r == -0xB || r == -0x37) {
        func_80049E50(self);
        func_800477E4(4, &D_800F7690, self);
        func_8004E654((struct X4_BaseObj*)self, 0x15);
        G(s8, 4) = 2;
        return;
    }
    if (r < 0) {
        func_80049E50(self);
        func_800477E4(4, &D_800F7690, self);
        if (D_800CCF38 >= 2) {
            set_animation(self, 0xF);
        } else {
            set_animation(self, 5);
        }
        G(u8, 0x5C) = 0x20;
        G(s32, 0x54) = 0;
        G(s32, 0x50) = 0;
        G(s8, 5) = 5;
        return;
    }
    func_80030ECC(self);
    if (is_off_screen((s32)self, 0x40, 0x40) == 0) {
        func_8002CCB0(self, 0x30, 0x30);
    }
}
#undef G

#include "../shared/commander_yammark/func_800ECA2C.c"

#include "../shared/commander_yammark/func_800ECC38.c"

#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
extern s32 D_800741FC[];
extern M2C_UNK D_8007433C;
extern struct X4_PlayerObj g_Player;
extern M2C_UNK D_800F76EC;
extern M2C_UNK D_800F76F0;
extern M2C_UNK D_800F76F4;
extern M2C_UNK D_800F76F8;
extern M2C_UNK D_800F76FC;

void func_800ECDD4(void* arg0) {
    s32 angle;
    s32 vel;
    // !FAKE: depin: dropping it breaks the match (70/147)
    register s32 t asm("$2");
    struct X4_PlayerObj* pl;
    s32 sel;

    M2C_FIELD(arg0, u8*, 0x16) = 5;
    sel = M2C_FIELD(arg0, s8*, 0x2);
    M2C_FIELD(arg0, u8*, 0x6) = 0;
    M2C_FIELD(arg0, s16*, 0x8C) = 0;
    M2C_FIELD(arg0, u8*, 0x4) += 1;
    if (sel == 0) {
        u8 dir0;
        s32 x0;
        set_animation(arg0, 7);
        play_sound(2, 0x3E, arg0);
        dir0 = M2C_FIELD(arg0, u8*, 0x15);
        x0 = 0xFFFD0000;
        if (dir0 != 0) {
            x0 = 0x30000;
        }
        M2C_FIELD(arg0, s32*, 0x20) = x0;
        x0 = M2C_FIELD(arg0, s16*, 0xA);
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        if (dir0 != 0) {
            x0 += 0x10;
        } else {
            x0 -= 0x10;
        }
        M2C_FIELD(arg0, s16*, 0xA) = x0;
        x0 = 6;
        M2C_FIELD(arg0, u8*, 0x60) = x0;
        M2C_FIELD(arg0, void**, 0x68) = 0;
        M2C_FIELD(arg0, void**, 0x50) = &D_800F76EC;
        M2C_FIELD(arg0, void**, 0x54) = &D_800F76F0;
        M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
        M2C_FIELD(arg0, u8*, 0x5) = 0;
    } else if (sel == 1) {
        u8 dir1;
        s32 x1;
        s32 nx1;
        s32 px;
        s32 m;
        set_animation(arg0, 7);
        play_sound(2, 0x3E, arg0);
        pl = &g_Player;
        px = M2C_FIELD(pl, s16*, 0xA);
        angle = ratan2(M2C_FIELD(pl, s16*, 0xE) - M2C_FIELD(arg0, s16*, 0xE),
                       px - M2C_FIELD(arg0, s16*, 0xA));
        t = rcos(angle);
        nx1 = t * 16;
        M2C_FIELD(arg0, s32*, 0x20) = (t << 6) + nx1;
        t = -rsin(angle);
        nx1 = t << 4;
        t = (t << 6) + nx1;
        M2C_FIELD(arg0, s32*, 0x24) = t;
        {
            // !FAKE: depin: dropping it breaks the match (128/147)
            register s32 d asm("$2");
            d = M2C_FIELD(arg0, u8*, 0x15);
            x1 = M2C_FIELD(arg0, s16*, 0xA);
            if (d == 0) {
                d = x1 - 0x10;
            } else {
                d = x1 + 0x10;
            }
            M2C_FIELD(arg0, s16*, 0xA) = d;
            d = 6;
            M2C_FIELD(arg0, u8*, 0x60) = d;
        }
        M2C_FIELD(arg0, void**, 0x50) = &D_800F76EC;
        M2C_FIELD(arg0, void**, 0x54) = &D_800F76F0;
        M2C_FIELD(arg0, void**, 0x68) = 0;
        M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
        {
            s32 st = 1;
            M2C_FIELD(arg0, u8*, 0x5) = st;
        }
    } else if (sel == 2) {
        u8 dir2;
        s32 x2;
        s32 nx2;
        set_animation(arg0, 6);
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        nx2 = 0xFFFE8000;
        M2C_FIELD(arg0, s32*, 0x24) = nx2;
        if (D_800CCF38 >= 2) {
            M2C_FIELD(arg0, s32*, 0x24) = 0xFFFD0000;
        }
        nx2 = M2C_FIELD(arg0, u8*, 0x15);
        x2 = M2C_FIELD(arg0, s16*, 0xA);
        if (nx2 == 0) {
            nx2 = x2 - 0x20;
        } else {
            nx2 = x2 + 0x20;
        }
        M2C_FIELD(arg0, s16*, 0xA) = nx2;
        M2C_FIELD(arg0, u8*, 0x5C) = 3;
        M2C_FIELD(arg0, u8*, 0x60) = 3;
        M2C_FIELD(arg0, void**, 0x68) = &D_800F76FC;
        M2C_FIELD(arg0, void**, 0x54) = &D_800F76F8;
        M2C_FIELD(arg0, void**, 0x50) = &D_800F76F4;
        M2C_FIELD(arg0, void**, 0x58) = D_800741FC;
        M2C_FIELD(arg0, u8*, 0x5) = 2;
        M2C_FIELD(arg0, s16*, 0xE) -= 0x10;
    }
}

#include "../shared/commander_yammark/func_800ED020.c"

#include "../shared/commander_yammark/func_800ED0F4.c"

#include "../shared/commander_yammark/func_800ED220.c"

#include "../shared/commander_yammark/func_800ED2F4.c"

#include "../shared/commander_yammark/func_800ED428.c"

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK clear_object_slot();
M2C_UNK func_8002CB50();
s32 is_off_screen(s32, M2C_UNK, M2C_UNK);
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
M2C_UNK func_80049E50(void*);
extern struct X4_BackgroundObj background_objects[3];
extern s32 D_800F7694;
extern void (*D_800F7738[])(void*);

#define F8(p, o) (*(s8*)((u8*)(p) + (o)))
#define FU8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F16(p, o) (*(s16*)((u8*)(p) + (o)))
#define F32(p, o) (*(s32*)((u8*)(p) + (o)))

void func_800ED584(void* arg0) {
    void* sub;
    s32 dir;

    sub = *(void**)((u8*)arg0 + 0x7C);
    if (check_enemy_hits(arg0) < 0 || F8(sub, 4) == 2 || F8(sub, 5) == 5) {
        if (F8(arg0, 2) == 2) {
            func_800477E4(2, &D_800F7694, arg0);
            func_80049E50(arg0);
        }
        F8(arg0, 4) = 2;
        return;
    }
    func_80030ECC(arg0);
    D_800F7738[F8(arg0, 5)](arg0);
    if (is_off_screen(arg0, 0x40, 0x40) == 0) {
        func_8002CB50(arg0);
    } else {
        if (F8(arg0, 2) != 2) {
            return;
        }
        if (F16(arg0, 0xE) - background_objects[F8(arg0, 0x14)].y_pos.i.hi >=
            0x12D) {
            clear_object_slot(arg0);
        }
    }
    if (F8(arg0, 2) == 2) {
        if (FU8(arg0, 0x70) & 8) {
            F8(arg0, 0x67) = 0;
            return;
        }
        dir = F32(arg0, 0x24);
        if (dir >= 0) {
            dir = 1;
        } else {
            dir = -1;
        }
        F8(arg0, 0x67) = dir;
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_03/nonmatchings/E9860", func_800ED704);
// clang-format on

#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK); /* extern */
extern M2C_UNK D_8007479C;
extern struct X4_PlayerObj g_Player;
extern M2C_UNK D_800F7448;
extern M2C_UNK D_800F744C;
extern M2C_UNK D_800F7650;

void func_800ED760(void* arg0) {
    void* temp = &g_Player;
    u8 b;
    s32 x;

    M2C_FIELD(arg0, u8*, 0x5C) = 0x20;
    M2C_FIELD(arg0, u8*, 0x60) = 8;
    M2C_FIELD(arg0, u8*, 0x61) = 0;
    b = M2C_FIELD(temp, u8*, 0x14);
    x = M2C_FIELD(arg0, s32*, 0x8);
    M2C_FIELD(arg0, void**, 0x58) = &D_8007479C;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, u8*, 0x70) = 0;
    M2C_FIELD(arg0, u8*, 0x14) = b;
    if (M2C_FIELD(temp, s32*, 0x8) < x) {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
    } else {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    }
    M2C_FIELD(arg0, void**, 0x30) = &D_800F7650;
    M2C_FIELD(arg0, u8*, 0x16) = 5;
    M2C_FIELD(arg0, s32*, 0x68) = 0;
    M2C_FIELD(arg0, void**, 0x54) = &D_800F744C;
    M2C_FIELD(arg0, void**, 0x50) = &D_800F7448;
    ((void (*)(void*, s32))set_animation)(arg0, 0);
    M2C_FIELD(arg0, s16*, 0x7C) = 0;
    M2C_FIELD(arg0, u8*, 0x4) = 1;
    M2C_FIELD(arg0, u8*, 0x5) = 1;
    M2C_FIELD(arg0, u8*, 0x7) = 0;
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CA14(); /* extern */
M2C_UNK func_8002CA54(); /* extern */

void func_800ED830(struct ObjectHeader* arg0) {
    if (arg0->state == 2) {
        func_8002CA14();
        return;
    }
    func_8002CA54();
}

#define func_8003744C func_800ED870
#define D_80073C1C D_800F76C0
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_8003744C func_800ED8AC
#define D_80073C1C D_800F76CC
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_8003744C func_800ED8E8
#define D_80073C1C D_800F76DC
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/commander_yammark/func_800ED924.c"

#include "../shared/commander_yammark/func_800ED984.c"

#include "../shared/commander_yammark/func_800ED9B8.c"

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK); /* extern */
M2C_UNK animate_object();              /* extern */

void func_800EDA84(void* arg0) {
    animate_object();
    if (M2C_FIELD(arg0, s8*, 0x45) == 2) {
        set_animation(arg0, 0);
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, s8*, 5) = 1;
    }
}

#include "../shared/commander_yammark/func_800EDACC.c"

#include "../shared/commander_yammark/func_800EDB00.c"

#include "../shared/commander_yammark/func_800EDBD4.c"

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK); /* extern */
M2C_UNK animate_object();              /* extern */

void func_800EDC24(void* arg0) {
    animate_object();
    if (M2C_FIELD(arg0, s8*, 0x45) == 2) {
        set_animation(arg0, 0);
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, s8*, 5) = 1;
    }
}

#include "../shared/commander_yammark/func_800EDC6C.c"

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK); /* extern */
M2C_UNK animate_object();              /* extern */

void func_800EDCA4(void* arg0) {
    animate_object();
    if (M2C_FIELD(arg0, s8*, 0x45) == 2) {
        set_animation(arg0, 0);
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, s8*, 5) = 1;
    }
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK animate_object(); /* extern */

void func_800EDCEC(void) {
    animate_object();
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EDD0C(void) {
    clear_object_slot();
}

// clang-format off
INCLUDE_ASM("asm/rock_03/nonmatchings/E9860", func_800EDD2C);
// clang-format on

#include "../shared/commander_yammark/func_800EDD88.c"

#include "../shared/commander_yammark/func_800EDE78.c"

#include "common.h"

#define M2C_UNK s32

M2C_UNK animate_object();                 /* extern */
M2C_UNK clear_object_slot(s32);           /* extern */
s32 is_off_screen(s32, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK move_object(s32);                 /* extern */

void func_800EDF30(s32 arg0) {
    animate_object();
    move_object(arg0);
    if (is_off_screen(arg0, 0x40, 0x40) == 1) {
        clear_object_slot(arg0);
    }
}

#define func_8003744C func_800EDF80
#define D_80073C1C D_800F7710
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_8003744C func_800EDFBC
#define D_80073C1C D_800F7724
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/commander_yammark/func_800EDFF8.c"

#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
M2C_UNK func_80049E50(void*);
extern s32 D_800F7694;
extern s32 D_800F7700;

#define F8(p, o) (*(s8*)((u8*)(p) + (o)))
#define FU16(p, o) (*(u16*)((u8*)(p) + (o)))
#define F16(p, o) (*(s16*)((u8*)(p) + (o)))
#define F32(p, o) (*(s32*)((u8*)(p) + (o)))

void func_800EE080(void* arg0) {
    u16 t;

    if (!(FU16(arg0, 0x8C) & 1)) {
        FU16(arg0, 0x42) ^= 0x8000;
    }
    t = FU16(arg0, 0x8C);
    FU16(arg0, 0x8C) = t + 1;
    if ((s16)t >= 0x33) {
        F32(arg0, 0x50) = (s32)&D_800F7700;
        F32(arg0, 0x54) = 0;
        func_800477E4(2, &D_800F7694, arg0);
        ((void (*)(void*))func_80049E50)(arg0);
        F8(arg0, 4) = 2;
    }
}

#define func_8003744C func_800EE118
#define D_80073C1C D_800F772C
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

struct X4_QuadObj* alloc_class6_slot(void);
M2C_UNK clear_object_slot();
extern u8 D_800F7544[][8];
extern u8 D_800F75C4[][8];
extern u8 D_800F7644[][8];
extern u8 D_800F76C4[][8];

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

void func_800EE154(void* self) {
    struct X4_QuadObj* q;
    s32 i;

    if (D_800CD30A != 8) {
        clear_object_slot(self);
        return;
    }
    i = SB(self, 2);
    B(self, 0) = 0x59;
    SB(self, 0x37) = -1;
    H(self, 0x34) = 0;
    SB(self, 0x36) = 0x12;
    if (i >= 0x40) {
        P(self, 0x3C) = D_800F7544[i];
        H(self, 0x40) = 0x28;
        H(self, 0x42) = 1;
        H(self, 0xA) = 0xA0;
        H(self, 0xE) = 0xF0;
        B(self, 4)++;
        return;
    }
    if (i >= 0x30) {
        P(self, 0x3C) = D_800F75C4[i];
        H(self, 0x40) = 0x28;
        H(self, 0x42) = 1;
        H(self, 0xA) = 0xA0;
        H(self, 0xE) = 0xF0;
        B(self, 4)++;
        return;
    }
    if (i >= 0x20) {
        P(self, 0x3C) = D_800F7644[i];
        H(self, 0x40) = -0x3C;
        H(self, 0x42) = -1;
        H(self, 0xA) = 0xA0;
        H(self, 0xE) = 0;
        B(self, 4)++;
        return;
    }
    if (i >= 0x10) {
        P(self, 0x3C) = D_800F76C4[i];
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

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define F16(n) M2C_FIELD(self, s16*, (n))

extern struct X4_PlayerObj g_Player;
extern u16 D_800F7784[];

void func_800EE344(struct X4_BaseObj* self) {
    u16* rect;
    s32 step;
    s32 neg;
    u16 cx;
    u16 cy;
    u16 w;
    u16 h;
    s16 left;
    s16 right;
    s16 top;
    s16 bottom;
    s32 n;

    rect = M2C_FIELD(self, u16**, 0x3C);
    cx = rect[0];
    w = rect[2];
    cy = rect[1];
    h = rect[3];
    F16(0x40) += M2C_FIELD(self, u16*, 0x42);
    left = cx - w;
    right = cx + w;
    top = cy - h;
    bottom = cy + h;
    if ((u16)(F16(0x40) + 0x80) > 0x100) {
        neg = F16(0x42);
        F16(0x42) = -neg;
    }
    if (g_Player.x_pos.i.hi < left || right < g_Player.x_pos.i.hi ||
        g_Player.y_pos.i.hi < top || bottom < g_Player.y_pos.i.hi) {
        if (--M2C_FIELD(self, s32*, 0x38) < 0) {
            M2C_FIELD(self, s32*, 0x38) = 0;
            F16(0x34) = 0;
            return;
        }
    } else {
        if (++M2C_FIELD(self, s32*, 0x38) >= 0x40) {
            M2C_FIELD(self, s32*, 0x38) = 0x3F;
        }
    }
    if (self->unk2 >= 0x40) {
        F16(0x1E) = 0x100;
        F16(0x26) = 0x100;
        F16(0x2A) = 0;
        F16(0x2E) = 0;
        F16(0x32) = 0;
        F16(0x16) = F16(0x40) + 0x78;
        F16(0x1A) = -self->y_pos.i.hi;
        F16(0x22) = -self->y_pos.i.hi;
    } else if (self->unk2 >= 0x30) {
        F16(0x16) = -0x100;
        F16(0x2E) = -0x100;
        F16(0x26) = 0;
        F16(0x2A) = 0;
        F16(0x32) = 0;
        F16(0x1A) = -self->y_pos.i.hi;
        F16(0x1E) = F16(0x40) - 0x78;
        F16(0x22) = -self->y_pos.i.hi;
    } else if (self->unk2 >= 0x20) {
        F16(0x16) = 0;
        F16(0x1A) = 0;
        F16(0x22) = 0;
        F16(0x1E) = 0x100;
        F16(0x26) = 0x100;
        F16(0x2E) = F16(0x40) + 0x78;
        F16(0x2A) = 0xF0;
        F16(0x32) = 0xF0;
    } else if (self->unk2 >= 0x10) {
        F16(0x16) = -0x100;
        F16(0x1A) = 0;
        F16(0x1E) = 0;
        F16(0x22) = 0;
        F16(0x2A) = 0xF0;
        F16(0x2E) = -0x100;
        F16(0x32) = 0xF0;
        F16(0x26) = F16(0x40) - 0x78;
    }
    n = M2C_FIELD(self, s32*, 0x38);
    F16(0x34) = D_800F7784[n / 4];
    self->on_screen = 1;
}

#define func_80046C64 func_800EE56C
#define D_800762A0 D_800F77A4
#include "../shared/d1000/func_80046C64.c"
#undef func_80046C64
#undef D_800762A0

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EE5AC(void) {
    ((M2C_UNK(*)())clear_object_slot)();
}

#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK); /* extern */
extern struct X4_PlayerObj g_Player;
extern M2C_UNK D_800F77B0;
extern M2C_UNK D_800F77B4;
extern M2C_UNK D_800F77B8;
extern M2C_UNK D_800F77EC;

void func_800EE5CC(void* arg0) {
    void* temp = &g_Player;

    M2C_FIELD(arg0, u8*, 0x5C) = 0x20;
    M2C_FIELD(arg0, u8*, 0x60) = 4;
    M2C_FIELD(arg0, u8*, 0x61) = 0;
    M2C_FIELD(arg0, u8*, 0x14) = M2C_FIELD(temp, u8*, 0x14);
    M2C_FIELD(arg0, u8*, 0x67) = 0;
    M2C_FIELD(arg0, u8*, 0x70) = 0;
    M2C_FIELD(arg0, s32*, 0x18) = M2C_FIELD(arg0, s32*, 0x8);
    M2C_FIELD(arg0, s32*, 0x1C) = M2C_FIELD(arg0, s32*, 0xC);
    if (M2C_FIELD(temp, s32*, 0x8) < M2C_FIELD(arg0, s32*, 0x18)) {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
    } else {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    }
    M2C_FIELD(arg0, void**, 0x30) = &D_800F77EC;
    M2C_FIELD(arg0, u8*, 0x16) = 6;
    M2C_FIELD(arg0, void**, 0x68) = &D_800F77B0;
    M2C_FIELD(arg0, void**, 0x54) = &D_800F77B8;
    M2C_FIELD(arg0, void**, 0x50) = &D_800F77B4;
    switch (M2C_FIELD(arg0, s8*, 0x2)) {
    case 0:
        ((void (*)(void*, s32))set_animation)(arg0, 0);
        M2C_FIELD(arg0, u8*, 0x5) = 1;
        break;
    case 1:
        ((void (*)(void*, s32))set_animation)(arg0, 0);
        M2C_FIELD(arg0, u8*, 0x5) = 1;
        break;
    case 2:
        ((void (*)(void*, s32))set_animation)(arg0, 0);
        M2C_FIELD(arg0, u8*, 0x5) = 1;
        break;
    case 3:
        M2C_FIELD(arg0, u8*, 0x3) = 0;
        M2C_FIELD(arg0, u8*, 0x5) = 4;
        break;
    case 4:
        M2C_FIELD(arg0, u8*, 0x3) = 0;
        M2C_FIELD(arg0, u8*, 0x5) = 5;
        break;
    }
    M2C_FIELD(arg0, s16*, 0x7C) = 0;
    M2C_FIELD(arg0, u8*, 0x4) = 1;
    M2C_FIELD(arg0, u8*, 0x6) = 0;
}

#include "../shared/commander_yammark/func_800EE70C.c"

#include "../shared/commander_yammark/func_800EE800.c"

#include "../shared/commander_yammark/func_800EE8C4.c"

#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800139A0(M2C_UNK);              /* extern */
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
void func_80029F38();                        /* extern */
M2C_UNK func_8002B36C(M2C_UNK);              /* extern */
M2C_UNK func_8002B6B0();                     /* extern */
extern s8 D_8008EAB0;
extern struct X4_PlayerObj g_Player;
extern struct X4_BackgroundObj background_objects[3];
#include "mmx6/state.h"
#include "mmx6/globals.h"
extern struct X4_EngineObj g_playthrough_state;
extern s16 D_800F782C[][16];

void func_800EE9C4(void* arg0) {
    s32 temp_a1;
    s32 temp_a0;
    s8 temp_a1_2;
    s16 temp_v1;
    s16 temp_y;
    s32 idx;

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
        temp_a1_2 = M2C_FIELD(arg0, s8*, 2);
        switch (temp_a1_2) {
        case 2:
            if (g_Player.character == 0) {
                M2C_FIELD(arg0, s16*, 0x7E) = 0;
                g_playthrough_state.checkpoint = 1;
                D_8008EAB0 = 1;
            } else {
                M2C_FIELD(arg0, s16*, 0x7E) = 1;
                g_playthrough_state.checkpoint = temp_a1_2;
                D_8008EAB0 = 1;
            }
            break;
        case 3:
            g_playthrough_state.checkpoint = 3;
            M2C_FIELD(arg0, s16*, 0x7E) = 2;
            break;
        case 4:
            g_playthrough_state.checkpoint = 3;
            M2C_FIELD(arg0, s16*, 0x7E) = 3;
            break;
        }
        idx = M2C_FIELD(arg0, s16*, 0x7E);
        temp_v1 = D_800F782C[idx][0];
        temp_y = D_800F782C[idx][1];
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
        background_objects[0].x_pos.i.hi =
            D_800F782C[M2C_FIELD(arg0, s16*, 0x7E)][2];
        background_objects[0].y_pos.i.hi =
            D_800F782C[M2C_FIELD(arg0, s16*, 0x7E)][3];
        background_objects[1].x_pos.i.hi =
            D_800F782C[M2C_FIELD(arg0, s16*, 0x7E)][4];
        background_objects[1].y_pos.i.hi =
            D_800F782C[M2C_FIELD(arg0, s16*, 0x7E)][5];
        background_objects[2].x_pos.i.hi =
            D_800F782C[M2C_FIELD(arg0, s16*, 0x7E)][6];
        background_objects[2].y_pos.i.hi =
            D_800F782C[M2C_FIELD(arg0, s16*, 0x7E)][7];
        background_objects[0].unk1E =
            D_800F782C[M2C_FIELD(arg0, s16*, 0x7E)][8];
        background_objects[0].unk1C =
            D_800F782C[M2C_FIELD(arg0, s16*, 0x7E)][9];
        background_objects[0].unk22 =
            D_800F782C[M2C_FIELD(arg0, s16*, 0x7E)][10];
        background_objects[0].unk20 =
            D_800F782C[M2C_FIELD(arg0, s16*, 0x7E)][11];
        background_objects[0].unk26 =
            D_800F782C[M2C_FIELD(arg0, s16*, 0x7E)][8];
        background_objects[0].unk24 =
            D_800F782C[M2C_FIELD(arg0, s16*, 0x7E)][9];
        background_objects[0].unk2A =
            D_800F782C[M2C_FIELD(arg0, s16*, 0x7E)][10];
        background_objects[0].unk28 =
            D_800F782C[M2C_FIELD(arg0, s16*, 0x7E)][11];
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
        background_objects[2].unk44 = 0;
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
        play_sound(1, 1, arg0);
    }
}

#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32

s32 func_8003AD18(void* arg0);
extern struct X4_PlayerObj g_Player;
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj g_playthrough_state;
extern s16 D_800F782C[][16];
#define EEDB8_TBL ((u16*)D_800F782C)

#define F16(p, o) (*(s16*)((u8*)(p) + (o)))
#define FU16(p, o) (*(u16*)((u8*)(p) + (o)))

void func_800EEDB8(u8* arg0) {
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
        g_Player.x_pos.i.hi = EEDB8_TBL[F16(arg0, 0x7E) * 16];
        g_Player.terrain_box = *(void**)(arg0 + 0x88);
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

#define func_800EA1D8 func_800EEEC4
#define D_800FAA64 D_800F77F8
#include "../shared/d1000/func_800EA1D8.c"
#undef func_800EA1D8
#undef D_800FAA64

#include "../shared/commander_yammark/func_800EEF10.c"

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CA14(); /* extern */
M2C_UNK func_8002CA54(); /* extern */

void func_800EEF8C(struct ObjectHeader* arg0) {
    if (arg0->state == 2) {
        func_8002CA14();
        return;
    }
    func_8002CA54();
}

#include "../shared/commander_yammark/func_800EEFCC.c"

#include "common.h"
#include "mmx6/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s16 D_800970AA;

void func_800EF044(void* arg0) {
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

void func_800EF090(void* arg0) {
    if (D_800970AA >= M2C_FIELD(arg0, s16*, 0xA)) {
        M2C_FIELD(arg0, u16*, 0x84) = (u16)D_800970AA;
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, s8*, 5) = 3;
        M2C_FIELD(arg0, s8*, 6) = 0;
    }
}

#define func_8003744C func_800EF0CC
#define D_80073C1C D_800F7820
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_8003744C func_800EF108
#define D_80073C1C D_800F78BC
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/commander_yammark/func_800EF144.c"

#include "../shared/commander_yammark/func_800EF1E8.c"

#include "../shared/commander_yammark/func_800EF27C.c"

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EF2E4(void) {
    ((M2C_UNK(*)())clear_object_slot)();
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32**)0x1F800020)

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);
M2C_UNK clear_object_slot();
s32 random_byte();
extern u32* D_80095098;
extern struct X4_BackgroundObj background_objects[3];
extern s32 D_800F78E8;

void func_800EF304(void* arg0) {
    s32 r;
    u8 t;

    if (D_800CD30A != 6) {
        clear_object_slot(arg0);
        return;
    }
    M2C_FIELD(arg0, u8*, 3) = 0;
    M2C_FIELD(arg0, s16*, 0x7C) = 0;
    M2C_FIELD(arg0, u8*, 0x5C) = 0;
    M2C_FIELD(arg0, u8*, 0x61) = 0;
    t = D_800970B4;
    M2C_FIELD(arg0, void**, 0x30) = &D_800F78E8;
    M2C_FIELD(arg0, u8*, 0x16) = 0;
    M2C_FIELD(arg0, void**, 0x68) = NULL;
    M2C_FIELD(arg0, void**, 0x54) = NULL;
    M2C_FIELD(arg0, void**, 0x50) = NULL;
    M2C_FIELD(arg0, u8*, 0x67) = 0;
    M2C_FIELD(arg0, s16*, 0x7C) = 5;
    M2C_FIELD(arg0, u8*, 0x60) = 0;
    M2C_FIELD(arg0, u8*, 0x14) = t;
    ((void (*)(void*, s32))set_animation)(arg0, 0);
    M2C_FIELD(arg0, u8*, 0x15) = 0;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    if (M2C_FIELD(arg0, s8*, 2) == 0) {
        M2C_FIELD(arg0, s16*, 0x40) =
            D_80095098[func_8002A47C(M2C_FIELD(arg0, s8*, 1))] >> 7;
        M2C_FIELD(arg0, s16*, 0x42) =
            ((func_8002A47C(M2C_FIELD(arg0, s8*, 1)) * 4 + 0x20) % 16) |
            (((func_8002A47C(M2C_FIELD(arg0, s8*, 1)) + 8) / 4 + 0x1E0) << 6);
        M2C_FIELD(arg0, s32*, 0x3C) =
            (s32)SPAD20 + SPAD20[func_8002A47C(M2C_FIELD(arg0, s8*, 1))];
        M2C_FIELD(arg0, u8*, 5) = 0;
    } else {
        r = random_byte();
        M2C_FIELD(arg0, s16*, 0xA) =
            background_objects[0].x_pos.i.hi + r * 2 + (random_byte() & 0x1F);
        M2C_FIELD(arg0, s16*, 0xE) = background_objects[0].y_pos.i.hi - 0x10;
        M2C_FIELD(arg0, s32*, 0x20) = -0x70000;
        M2C_FIELD(arg0, s32*, 0x24) = -0x70000;
        M2C_FIELD(arg0, u8*, 5) = 1;
    }
    M2C_FIELD(arg0, u8*, 4) = 1;
    M2C_FIELD(arg0, u8*, 6) = 0;
    M2C_FIELD(arg0, s32*, 0x18) = M2C_FIELD(arg0, s32*, 8);
    M2C_FIELD(arg0, s32*, 0x1C) = M2C_FIELD(arg0, s32*, 0xC);
}

#include "common.h"
#include "mmx6/x4.h"

#define F(p, t, o) (*(t*)((u8*)(p) + (o)))

extern struct X4_PlayerObj g_Player;
extern s8 D_800CCEDC;
extern u8 D_800F7900[];

s32 func_800EF4D4(u32 arg0) {
    s32 off;
    u8* p;
    u8* b;
    s32 c;

    arg0 &= 0xFFFF;
    c = D_800CCEDC;
    b = D_800F7900;
    off = arg0 * 10;
    p = off + b;
    if (c == F(p, u8, 8) && g_Player.x_pos.i.hi >= F(p, s16, 0) &&
        F(D_800F7900 + off, s16, 4) >= g_Player.x_pos.i.hi &&
        g_Player.y_pos.i.hi >= F(D_800F7900 + off, s16, 2) &&
        F(D_800F7900 + off, s16, 6) >= g_Player.y_pos.i.hi) {
        return 1;
    }
    return 0;
}

#define func_80048DC8 func_800EF578
#define D_80077BC0 D_800F78EC
#include "../shared/d1000/func_80048DC8.c"
#undef func_80048DC8
#undef D_80077BC0

#define func_80041AB8 func_800EF5C4
#define D_80075FD8 D_800F78F8
#define FAMILY_FIELD 5
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EF600(void) {
    ((M2C_UNK(*)())clear_object_slot)();
}

#include "common.h"
#include "mmx6/x4.h"

#ifndef M2C_FIELD
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#endif

extern struct X4_PlayerObj g_Player;
s32 func_800EF4D4(u32);
void func_800EF76C(void*, s32);

void func_800EF620(void* arg0) {
    u16 i;

    for (i = 0; i < 8; i++) {
        if (func_800EF4D4(i) != 0) {
            u8* p = (u8*)&g_Player;
            p[0x150] = 1;
            if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
                M2C_FIELD(arg0, s16*, 0x7C) = 5;
                func_800EF76C(arg0, 1);
            }
            return;
        }
    }
    {
        u8* p = (u8*)&g_Player;
        p[0x150] = 0;
    }
}

#include "../shared/commander_yammark/func_800EF6D4.c"

#define func_800EFEF8 func_800EF76C
#include "../shared/commander_yammark/func_800EFEF8.c"
#undef func_800EFEF8

// clang-format off
INCLUDE_ASM("asm/rock_03/nonmatchings/E9860", func_800EF810);
// clang-format on

#include "common.h"
#include "mmx6/globals.h"
#include "mmx6/rock_03.h"
#define M2C_UNK s32

M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
extern M2C_UNK D_8007433C;
extern void (*D_800F7BE8[])(void*);
extern u32 D_800F7DE0;

#define G(type, off) (*(type*)((u8*)self + (off)))

void func_800EFB9C(void* self) {
    s32 r;
    u8 t;

    r = check_enemy_hits(self);
    if (r < 0) {
        G(s8, 4) = 2;
        G(s8, 5) = 0;
        G(s8, 6) = 0;
        G(u16, 0x42) = G(u16, 0x42) & 0x7FFF;
        D_800F7DE4 = 1;
        D_8009711A = 1;
        func_8002CCB0(self, 0x40, 0x40);
        return;
    }
    func_80030ECC(self);
    if (r > 0 && r != 0x7F) {
        if ((u32)(r - 0x19) < 2) {
            G(u8, 0x84) = 2;
        } else {
            G(u8, 0x84) = 0x1E;
        }
        G(void*, 0x58) = &D_8007433C;
    }
    if ((r == 9 || r == 0x12 || r == 0x2D) && D_800F7E30 == 0) {
        D_800F7DE8 = 1;
        G(s8, 5) = 0xA;
        G(s8, 6) = 0;
    }
    t = G(u8, 0x84);
    if (t != 0) {
        G(u8, 0x84) = t + 0xFF;
        if (t & 2) {
            G(u16, 0x42) = G(u16, 0x42) | 0x8000;
        } else {
            G(u16, 0x42) = G(u16, 0x42) & 0x7FFF;
        }
        if (G(u8, 0x84) == 0) {
            G(void*, 0x58) = &D_80074BFC;
            G(u16, 0x42) = G(u16, 0x42) & 0x7FFF;
        }
    }
    D_800F7BE8[G(s8, 5)](self);
    if (G(s8, 5) != 2) {
        D_800F7DE0++;
    }
}

#undef G

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK apply_object_motion(void*);
s32 random_byte();
extern struct X4_EngineObj g_playthrough_state;
extern u8 D_800F7BA0[][6];
extern u16* D_800F7DF0;
extern s32 D_800F7E04;
extern s32 D_800F7E08;

void func_800EFD38(void* arg0) {
    u32 r;
    u8 frame;

    {
        struct X4_EngineObj* e = &g_playthrough_state;
        if (M2C_FIELD(arg0, s8*, 0x5C) <
            (s8)((s8)M2C_FIELD(e, u8*, 0x8C) / 3)) {
            D_800F7DF0 = (u16*)&D_800F7E08;
        } else if (M2C_FIELD(arg0, s8*, 0x5C) <
                   (s8)M2C_FIELD(e, u8*, 0x8C) * 2 / 3) {
            D_800F7DF0 = (u16*)&D_800F7E04;
        }
    }
    r = random_byte();
    M2C_FIELD(arg0, u8*, 0x87) = 0;
    r &= 0xF;
    if (D_800970A2 == 0) {
        struct X4_EngineObj* e = &g_playthrough_state;
        if ((s8)M2C_FIELD(e, u8*, 0x8C) / 2 < M2C_FIELD(arg0, s8*, 0x5C)) {
            if (r < 8) {
                M2C_FIELD(arg0, u8*, 0x86) = 0;
            } else {
                M2C_FIELD(arg0, u8*, 0x86) = 2;
            }
        } else if (r < 4) {
            M2C_FIELD(arg0, u8*, 0x86) = 0;
        } else if (r < 12) {
            M2C_FIELD(arg0, u8*, 0x86) = 4;
        } else {
            M2C_FIELD(arg0, u8*, 0x86) = 5;
        }
    } else {
        struct X4_EngineObj* e = &g_playthrough_state;
        if ((s8)M2C_FIELD(e, u8*, 0x8C) / 2 < M2C_FIELD(arg0, s8*, 0x5C)) {
            if (r < 8) {
                M2C_FIELD(arg0, u8*, 0x86) = 1;
            } else {
                M2C_FIELD(arg0, u8*, 0x86) = 3;
            }
        } else if (r < 4) {
            M2C_FIELD(arg0, u8*, 0x86) = 1;
        } else if (r < 12) {
            M2C_FIELD(arg0, u8*, 0x86) = 4;
        } else {
            M2C_FIELD(arg0, u8*, 0x86) = 5;
        }
    }
    frame =
        D_800F7BA0[M2C_FIELD(arg0, u8*, 0x86)][M2C_FIELD(arg0, u8*, 0x87)++];
    M2C_FIELD(arg0, u8*, 0x6) = 0;
    M2C_FIELD(arg0, u8*, 0x5) = frame;
    animate_object(arg0);
    apply_object_motion(arg0);
    func_8002CCB0(arg0, 0x40, 0x40);
}

#include "../shared/commander_yammark/func_800EFF18.c"

#include "../shared/commander_yammark/func_800F008C.c"

#define func_800EFF18 func_800F0360
#include "../shared/commander_yammark/func_800EFF18.c"
#undef func_800EFF18

#define func_800F008C func_800F04D4
#include "../shared/commander_yammark/func_800F008C.c"
#undef func_800F008C

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"
#include "mmx6/rock_03.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
extern M2C_UNK D_8007433C;
extern M2C_UNK D_800F7954;
extern u8 D_800F7BA0[][6];

void func_800F07A8(void* arg0) {
    u8 frame;

    if (M2C_FIELD(arg0, s16*, 0x7C) == 0x78) {
        play_sound(2, 0x23, arg0);
    }
    if (M2C_FIELD(arg0, s16*, 0x8E) == 0) {
        if ((s8)(M2C_FIELD(arg0, u8*, 0x7) += 2) >= 0x1E) {
            M2C_FIELD(arg0, s16*, 0x8E) = 1;
        }
    } else {
        if ((s8)(M2C_FIELD(arg0, u8*, 0x7) -= 2) < -0x1D) {
            M2C_FIELD(arg0, s16*, 0x8E) = 0;
        }
    }
    if (D_800F7E30 == 30) {
        if ((s8)(M2C_FIELD(arg0, u8*, 0x5C) -= 3) <= 0) {
            M2C_FIELD(arg0, u8*, 0x4) = 2;
            M2C_FIELD(arg0, u8*, 0x5C) = 0;
            M2C_FIELD(arg0, u8*, 0x5) = 0;
            M2C_FIELD(arg0, u8*, 0x6) = 0;
            M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
            D_800F7DE4 = 1;
            D_8009711A = 1;
            func_8002CCB0(arg0, 0x40, 0x40);
            return;
        }
        play_sound(2, 0x21, arg0);
        set_animation(arg0, 8);
        M2C_FIELD(arg0, void**, 0x50) = 0;
        M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
    } else if (D_800F7E30 == 1) {
        set_animation(arg0, 0);
        {
            // !FAKE: depin: dropping it breaks the match (132/136)
            register s32 a asm("$2") = (s32)&D_800F7954;
            // !FAKE: depin: dropping it breaks the match (76/136)
            register s32 b asm("$3") = (s32)&D_80074BFC;
            M2C_FIELD(arg0, s32*, 0x50) = a;
            M2C_FIELD(arg0, s32*, 0x58) = b;
        }
    }
    if (D_800F7E30 != 0) {
        D_800F7E30--;
    }
    M2C_FIELD(arg0, s16*, 0x7E)++;
    if (++M2C_FIELD(arg0, s16*, 0x7C) == 0x258) {
        set_animation(arg0, 0);
        {
            // !FAKE: depin: dropping it breaks the match (132/136)
            register s32 a asm("$2") = (s32)&D_800F7954;
            // !FAKE: depin: dropping it breaks the match (130/136)
            register s32 b asm("$3") = (s32)&D_80074BFC;
            M2C_FIELD(arg0, s32*, 0x50) = a;
            M2C_FIELD(arg0, s32*, 0x58) = b;
        }
        D_800F7E30 = 0;
        frame = D_800F7BA0[M2C_FIELD(arg0, u8*, 0x86)]
                          [M2C_FIELD(arg0, u8*, 0x87)++];
        M2C_FIELD(arg0, u8*, 0x6) = 0;
        M2C_FIELD(arg0, u8*, 0x5) = frame;
    }
}

#include "../shared/commander_yammark/func_800F09C8.c"

#define func_800F008C func_800F0B0C
#include "../shared/commander_yammark/func_800F008C.c"
#undef func_800F008C

#include "../shared/commander_yammark/func_800F0DE0.c"

#define func_800F09C8 func_800F0F1C
#include "../shared/commander_yammark/func_800F09C8.c"
#undef func_800F09C8

#define func_800F008C func_800F1060
#include "../shared/commander_yammark/func_800F008C.c"
#undef func_800F008C

#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
extern s16 D_800F7DC0;
extern s16 D_800F7DC2;
extern s16 D_800F7DCA;
extern s16 D_800F7DCC;
extern s16 D_800F7DCE;
extern s16 D_800F7DD0;

#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define H(p, o) (*(s16*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))

void func_800F1334(void* arg0) {
    s16 x;
    s16 y;
    s16 ang;

    if (H(arg0, 0xA) < (D_800F7DC0 + D_800F7DC2) / 2) {
        x = D_800F7DCA;
        UB(arg0, 0x15) = 0x40;
    } else {
        x = D_800F7DCC;
        UB(arg0, 0x15) = 0;
    }
    y = D_800F7DD0;
    H(arg0, 0x7E) = 1;
    if (H(arg0, 0xA) == x && H(arg0, 0xE) == y) {
        W(arg0, 0x20) = 0;
        W(arg0, 0x24) = 0;
    } else {
        ang = ratan2(y - H(arg0, 0xE), x - H(arg0, 0xA));
        W(arg0, 0x20) = rcos(ang) * 32;
        W(arg0, 0x24) = -rsin(ang) * 32;
    }
    if (W(arg0, 0x20) != 0) {
        ((void (*)(void*, s32))set_animation)(arg0, 2);
    } else {
        s32 v = W(arg0, 0x24);
        if (v > 0) {
            ((void (*)(void*, s32))set_animation)(arg0, 3);
        } else if (v < 0) {
            ((void (*)(void*, s32))set_animation)(arg0, 4);
        }
    }
    UB(arg0, 6)++;
}

#define func_800F008C func_800F1478
#include "../shared/commander_yammark/func_800F008C.c"
#undef func_800F008C

#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/rock_03.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
extern struct X4_PlayerObj g_Player;
extern u8 D_800F7BA0[][6];
extern s16 D_800F7E40[][4];

#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define H(p, o) (*(s16*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))

void func_800F174C(void* arg0) {
    s16 ang;
    u8 idx;

    if (H(arg0, 0x7C) == 0x5A) {
        play_sound(2, 0x2A, arg0);
    }
    if (!(H(arg0, 0x7C) & 7)) {
        if (g_Player.x_pos.i.hi > H(arg0, 0xA)) {
            UB(arg0, 0x15) = 0x40;
        } else {
            UB(arg0, 0x15) = 0;
        }
        ang = ratan2(g_Player.y_pos.i.hi - H(arg0, 0xE),
                     g_Player.x_pos.i.hi - H(arg0, 0xA));
        W(arg0, 0x20) = rcos(ang) << 5;
        W(arg0, 0x24) = -rsin(ang) << 5;
    }
    D_800F7E40[H(arg0, 0x8E)][0] = H(arg0, 0xA);
    D_800F7E40[H(arg0, 0x8E)][1] = H(arg0, 0xE);
    D_800F7E40[H(arg0, 0x8E)][2] = UB(arg0, 0x15);
    if (++H(arg0, 0x8E) == 0xD2) {
        H(arg0, 0x8E) = 0;
    }
    if (++H(arg0, 0x7C) == 0x1F4 || D_800F7E10 == 0) {
        set_animation(arg0, 0);
        idx = UB(arg0, 0x87)++;
        W(arg0, 0x20) = 0;
        W(arg0, 0x24) = 0;
        UB(arg0, 0x5) = D_800F7BA0[UB(arg0, 0x86)][idx];
        UB(arg0, 0x6) = 0;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void* enemy_slot_alloc();
M2C_UNK clear_object_slot();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
extern struct X4_EngineObj g_playthrough_state;
extern u32 D_800F7DE0;

#define SB(p, o) (*(s8*)((u8*)(p) + (o)))
#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define UH(p, o) (*(u16*)((u8*)(p) + (o)))
#define P(p, o) (*(void**)((u8*)(p) + (o)))

void func_800F1904(void* arg0) {
    void* parent;
    u8* p;

    parent = P(arg0, 0x80);
    if (SB(parent, 0) != 0) {
        if (SB(parent, 7) == 0) {
            if ((s16)--UH(arg0, 0x7E) == -1) {
                UH(arg0, 0x7E) = 5;
                UH(arg0, 0x42) ^= 0x8000;
            }
            func_8002CCB0(arg0, 0x40, 0x40);
        }
    } else {
        if (g_playthrough_state.stage != 0xC) {
            if (D_800F7DE0 < 0x1519) {
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

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"
#include "mmx6/rock_03.h"

extern struct X4_MainObj* D_800F7DEC;
extern u16* D_800F7DF0;
extern s16 D_800F7E20[];

void func_800F1A3C(struct X4_MainObj* arg0) {
    struct X4_MainObj* src;
    s16* p;
    s32 i;
    u8 t;
    u8 st;

    src = D_800F7DEC;
    arg0->unk40 = src->unk40;
    arg0->animation_table = src->animation_table;
    arg0->sprite_frames = src->sprite_frames;
    i = 0;
    arg0->unk42 = src->unk42 & 0x7FFF;
    t = D_800970B4;
    arg0->unk16 = 4;
    arg0->air_state = 0;
    arg0->on_screen = 0;
    arg0->terrain_box = 0;
    arg0->attack_box = 0;
    arg0->hurt_box = 0;
    arg0->collision_data = &D_80074BFC;
    arg0->unk62 = 0;
    arg0->invincibility_timer = 0;
    arg0->bg_offset = t;
    do {
        // !FAKE: goto enters the search loop at its test; a while loop with break moved bytes
        goto test;
    inc:
        i++;
    test:
        if (i < *(s16*)D_800F7DF0) {
            {
                s16* b = D_800F7E20;
                p = b + i;
            }
            if (*p != 0) {
                // !FAKE: goto enters the search loop at its test; a while loop with break moved bytes
                goto inc;
            }
            *p = 1;
            arg0->ext.main_33.unk88 = i;
        }
    } while (0);
    D_800F7E10++;
    do {
        st = arg0->state;
    } while (0);
    arg0->hp = 8;
    arg0->x_speed = 0;
    arg0->y_speed = 0;
    arg0->x_accel = 0;
    arg0->gravity = 0;
    arg0->contact_damage = 2;
    arg0->ext.main_33.unk84 = 0;
    arg0->unk7E = 0;
    arg0->action_phase = 0;
    do {
        arg0->state = st + 1;
    } while (0);
}

// clang-format off
INCLUDE_ASM("asm/rock_03/nonmatchings/E9860", func_800F1B54);

INCLUDE_ASM("asm/rock_03/nonmatchings/E9860", func_800F3AD8);
// clang-format on
