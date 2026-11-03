// clang-format off
INCLUDE_ASM("asm/rock_15/nonmatchings/E9860", D_800E9860);

INCLUDE_ASM("asm/rock_15/nonmatchings/E9860", func_800E9868);

INCLUDE_ASM("asm/rock_15/nonmatchings/E9860", func_800E99CC);
// clang-format on

#define func_80041AB8 func_800E9B60
#define D_80075FD8 D_800F5E14
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CA14(void*, void*); /* extern */
M2C_UNK func_8002CA54(void*, void*); /* extern */
extern u16 D_800CCEDC;

void func_800E9B9C(void* arg0) {
    if ((D_800CCEDC == 2) || (M2C_FIELD(arg0, s8*, 4) == 3)) {
        func_8002CA54(arg0, arg0);
        return;
    }
    func_8002CA14(arg0, arg0);
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800E9BF0(void* arg0) {
    M2C_FIELD(arg0, u8*, 5) = (u8)M2C_FIELD(arg0, u8*, 0x94);
}

// clang-format off
INCLUDE_ASM("asm/rock_15/nonmatchings/E9860", func_800E9BFC);
// clang-format on

#define func_800EC380 func_800E9C44
#include "../shared/rock_09/func_800EC380.c"
#undef func_800EC380

#define func_800EC3B8 func_800E9C7C
#define g_Player g_Player
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK animate_object();
M2C_UNK move_object();
s32 func_8002D354(void* arg0, s32 arg1, s32 arg2);
void set_velocity_from_angle(void*, s32);
extern struct X4_PlayerObj g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)

void func_800E9C7C(struct X4_MainObj* self) {
    struct X4_PlayerObj* pl;
    s32 v;
    s32 dx;

    animate_object();
    move_object(self);
    pl = &g_Player;
    set_velocity_from_angle(
        self,
        func_8002D354(self, pl->x_pos.val, pl->y_pos.val + 0xFFB00000) & 0xFF);
    v = self->x_speed + self->x_speed / 2;
    self->x_speed = v;
    v = (v < 0 ? -v : v) + 0x20000;
    dx = pl->x_pos.val - self->x_pos.val;
    if (dx < 0) {
        dx = self->x_pos.val - pl->x_pos.val;
    }
    if (v >= dx || --self->unk7C == 0) {
        self->action = 3;
        self->action_phase = 0;
    }
}
#undef g_Player
#undef func_800EC3B8
#undef g_Player

#define func_8003744C func_800E9D50
#define D_80073C1C D_800F5E58
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

// clang-format off
INCLUDE_ASM("asm/rock_15/nonmatchings/E9860", func_800E9D8C);

INCLUDE_ASM("asm/rock_15/nonmatchings/E9860", func_800E9DDC);
// clang-format on

#define func_800EC574 func_800E9E38
#include "../shared/rock_09/func_800EC574.c"
#undef func_800EC574

#define func_8003744C func_800E9E88
#define D_80073C1C D_800F5E64
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

// clang-format off
INCLUDE_ASM("asm/rock_15/nonmatchings/E9860", func_800E9EC4);
// clang-format on

#include "common.h"

#define M2C_UNK s32

M2C_UNK animate_object(); /* extern */
M2C_UNK move_object(s32); /* extern */

void func_800E9F20(s32 arg0) {
    animate_object();
    move_object(arg0);
}

#define func_8003744C func_800E9F4C
#define D_80073C1C D_800F5E6C
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

// clang-format off
INCLUDE_ASM("asm/rock_15/nonmatchings/E9860", func_800E9F88);
// clang-format on

#include "common.h"

#define M2C_UNK s32

M2C_UNK animate_object(); /* extern */
M2C_UNK move_object(s32); /* extern */

void func_800E9FF4(s32 arg0) {
    animate_object();
    move_object(arg0);
}

#define func_8003744C func_800EA020
#define D_80073C1C D_800F5E74
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

// clang-format off
INCLUDE_ASM("asm/rock_15/nonmatchings/E9860", func_800EA05C);
// clang-format on

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EA158(void* arg0) {
    if (M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
        return;
    }
    M2C_FIELD(arg0, s16*, 0x7C) = (s16)((u16)M2C_FIELD(arg0, s16*, 0x7C) - 1);
}

#define func_800EC8C0 func_800EA184
#include "../shared/rock_09/func_800EC8C0.c"
#undef func_800EC8C0

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object(); /* extern */
M2C_UNK move_object();    /* extern */

void func_800EA1BC(void* arg0) {
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0x20000;
    ((M2C_UNK(*)())move_object)();
    animate_object(arg0);
}

// clang-format off
INCLUDE_ASM("asm/rock_15/nonmatchings/E9860", func_800EA1F4);

INCLUDE_ASM("asm/rock_15/nonmatchings/E9860", func_800EA23C);
// clang-format on

#define func_800EC9D0 func_800EA294
#define g_Player g_Player
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();
M2C_UNK move_object();
s32 func_8002D354(void* arg0, s32 arg1, s32 arg2);
void set_velocity_from_angle(void*, s32);
extern struct X4_PlayerObj g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)

void func_800EA294(struct X4_MainObj* self) {
    ((void (*)())animate_object)();
    if (--self->unk7C == 0) {
        self->action = 8;
        self->action_phase = 0;
    }
    M2C_FIELD(self, s32*, 0x90) = M2C_FIELD(self, s32*, 0x90) + 1;
    M2C_FIELD(self, s32*, 0x90) = M2C_FIELD(self, u8*, 0x90) & 3;
    if (M2C_FIELD(self, u8*, 0x90) == 0) {
        set_velocity_from_angle(
            self,
            func_8002D354(self, g_Player.x_pos.val, g_Player.y_pos.val) & 0xFF);
    }
    move_object(self);
}
#undef g_Player
#undef func_800EC9D0
#undef g_Player

#define func_800F32A8 func_800EA334
#include "../shared/rock_08/func_800F32A8.c"
#undef func_800F32A8

#define func_800ECAA0 func_800EA364
#include "../shared/rock_09/func_800ECAA0.c"
#undef func_800ECAA0

#define func_80041AB8 func_800EA40C
#define D_80075FD8 D_800F5E90
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
extern s32 D_800741FC[];
extern M2C_UNK D_800F5E88;
extern M2C_UNK D_800F5E8C;

void func_800EA448(void* arg0) {
    M2C_FIELD(arg0, s32*, 0x24) = 0xFFFF0000;
    M2C_FIELD(arg0, s32*, 0x2C) = 0x3000;
    M2C_FIELD(arg0, void**, 0x68) = &D_800F5E88;
    M2C_FIELD(arg0, void**, 0x54) = &D_800F5E8C;
    M2C_FIELD(arg0, void**, 0x58) = &D_800741FC;
    M2C_FIELD(arg0, void**, 0x50) = &D_800F5E8C;
    {
        // !FAKE: depin: dropping it breaks the match (25/35)
        register s32 one asm("$5") = 1;
        M2C_FIELD(arg0, u8*, 0x3) = one;
        {
            // !FAKE: depin: dropping it breaks the match (29/35)
            register s32 k asm("$3") = 5;
            M2C_FIELD(arg0, u8*, 0x60) = k;
        }
        M2C_FIELD(arg0, u8*, 0x5C) = one;
    }
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, u8*, 0x4) = (u8)(M2C_FIELD(arg0, u8*, 0x4) + 1);
    M2C_FIELD(arg0, u16*, 0x42) = (u16)(M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF);
    set_animation(arg0, 2);
}

// clang-format off
INCLUDE_ASM("asm/rock_15/nonmatchings/E9860", func_800EA4D4);
// clang-format on

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EA5BC(void) {
    clear_object_slot();
}

#include "common.h"

void func_800EA5DC(void) {
}

// clang-format off
INCLUDE_ASM("asm/rock_15/nonmatchings/E9860", func_800EA5E4);
// clang-format on

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK start_pad_vibration(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK);

extern s32 D_800741FC[];
extern M2C_UNK D_8007433C;
extern u8 D_800F5FC0[];
extern u8 D_800F5FC8[];
extern u8 D_800F5FCC[];
extern u8 D_800F5FD0[];
extern u8 D_800F5FD4[];
extern u8 D_800F5FD8[];
extern u8 D_800F5FDC[];
extern u8 D_800F5FE0[];

void func_800EA770(struct X4_PlayerObj* self) {
    void* tbl;

    if (self->character == 0) {
        // !FAKE: depin: dropping it breaks the match (155/162)
        register void* p asm("$2");
        // !FAKE: depin: dropping it breaks the match (155/162)
        register s32 n asm("$4");
        // !FAKE: depin: dropping it breaks the match (49/162)
        register void* q asm("$3");
        s32 vx;
        s16 x;
        u8 dir;
        // !FAKE: depin: dropping it breaks the match (28/162)
        register s32 t asm("$2");

        func_8002943C(8, 2, 2);
        play_sound(2, 0x1D, self);
        start_pad_vibration(5);
        set_animation(self, 5);
        dir = self->facing;
        vx = -0x28000;
        if (dir != 0) {
            vx = 0x28000;
        }
        self->y_vel.val = -0x28000;
        self->x_vel.val = vx;
        self->x_accel = 0;
        self->gravity = 0;
        x = self->x_pos.i.hi;
        t = (dir != 0) ? x + 0x24 : x - 0x24;
        n = 4;
        self->x_pos.i.hi = t;
        p = D_800F5FC8;
        self->terrain_box = p;
        p = D_800F5FC0;
        self->unk50 = p;
        self->hp = 0;
        self->unk60 = n;
        self->unk54 = 0;
        q = &D_800741FC;
        self->unk58 = q;
        self->unk16 = n;
        self->y_pos.u.hi += 8;
    } else if (self->character == 1) {
        s32 vx;
        s16 x;
        u8 dir;

        play_sound(2, 0x1C, self);
        set_animation(self, 6);
        dir = self->facing;
        vx = -0x30000;
        if (dir != 0) {
            vx = 0x30000;
        }
        self->x_vel.val = vx;
        self->x_accel = 0;
        self->y_vel.val = 0;
        self->gravity = 0;
        x = self->x_pos.i.hi;
        self->x_pos.i.hi = (dir != 0) ? x + 0x20 : x - 0x20;
        self->hp = 6;
        self->unk60 = 4;
        self->terrain_box = D_800F5FD4;
        self->unk54 = D_800F5FD0;
        self->unk50 = D_800F5FCC;
        self->y_pos.u.hi -= 0x10;
        if (D_800CCF38 >= 2) {
            tbl = &D_8007433C;
        } else {
            tbl = &D_800741FC;
        }
        self->unk58 = tbl;
        self->unk16 = 6;
        M2C_FIELD(self, s16*, 0x8C) = 0x32;
    } else {
        s16 x;

        play_sound(2, 0x1B, self);
        set_animation(self, 6);
        self->x_vel.val = 0;
        self->x_accel = 0;
        self->y_vel.val = 0;
        self->gravity = 0;
        x = self->x_pos.i.hi;
        self->x_pos.i.hi = (self->facing != 0) ? x + 0x30 : x - 0x30;
        self->unk60 = 8;
        self->terrain_box = D_800F5FE0;
        self->unk54 = D_800F5FDC;
        self->unk50 = D_800F5FD8;
        self->unk58 = &D_8007433C;
        self->hp = 0;
        self->unk16 = 6;
        self->y_pos.u.hi -= 0x10;
    }
    self->on_screen = 0;
    self->collision_flags = 0;
    self->invincibility_timer = 0;
    self->unk42 &= 0x7FFF;
    self->state++;
}

// clang-format off
INCLUDE_ASM("asm/rock_15/nonmatchings/E9860", func_800EA9F8);
// clang-format on

#define func_800EA1D8 func_800EAC50
#define D_800FAA64 D_800F5F9C
#include "../shared/d1000/func_800EA1D8.c"
#undef func_800EA1D8
#undef D_800FAA64

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define FX(p, type, off) (*(type*)((u8*)(p) + (off)))

M2C_UNK set_animation(void*, M2C_UNK);
extern M2C_UNK D_8007433C;
extern struct X4_PlayerObj g_Player;
extern M2C_UNK D_800F5EA0;
extern M2C_UNK D_800F5EA4;
extern M2C_UNK D_800F5EA8;
extern M2C_UNK D_800F5F6C;

void func_800EAC9C(void* arg0) {
    struct X4_PlayerObj* pl;
    u8 b;
    s32 x;
    s32 y;

    FX(arg0, u8, 0x5C) = 0x20;
    FX(arg0, u8, 0x60) = 6;
    FX(arg0, u8, 0x61) = 0;
    FX(arg0, void*, 0x58) = &D_8007433C;
    pl = &g_Player;
    b = FX(pl, u8, 0x14);
    x = FX(arg0, s32, 0x8);
    y = FX(arg0, s32, 0xC);
    FX(arg0, s32, 0x20) = 0;
    FX(arg0, s32, 0x24) = 0;
    FX(arg0, s32, 0x28) = 0;
    FX(arg0, s32, 0x2C) = 0;
    FX(arg0, u8, 0x67) = 0;
    FX(arg0, u8, 0x70) = 0;
    FX(arg0, u8, 0x14) = b;
    FX(arg0, s32, 0x18) = x;
    FX(arg0, s32, 0x1C) = y;
    if (FX(pl, s32, 0x8) < x) {
        FX(arg0, u8, 0x15) = 0;
    } else {
        FX(arg0, u8, 0x15) = 0x40;
    }
    FX(arg0, void*, 0x30) = &D_800F5F6C;
    FX(arg0, u8, 0x16) = 4;
    FX(arg0, void*, 0x68) = &D_800F5EA0;
    FX(arg0, void*, 0x54) = &D_800F5EA8;
    FX(arg0, void*, 0x50) = &D_800F5EA4;
    set_animation(arg0, 0);
    FX(arg0, s16, 0x7C) = 0;
    FX(arg0, u8, 0x4) = 1;
    FX(arg0, u8, 0x5) = 4;
    FX(arg0, u8, 0x6) = 0;
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CA14(); /* extern */
M2C_UNK func_8002CA54(); /* extern */

void func_800EAD94(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 4) == 2) {
        ((M2C_UNK(*)())func_8002CA14)();
        return;
    }
    ((M2C_UNK(*)())func_8002CA54)();
}

#define func_800EA554 func_800EADD4
#include "../shared/rock_09/func_800EA554.c"
#undef func_800EA554

#define func_800EA5FC func_800EAE7C
#include "../shared/rock_09/func_800EA5FC.c"
#undef func_800EA5FC

#define func_800EA708 func_800EAF88
#include "../shared/rock_09/func_800EA708.c"
#undef func_800EA708

#define func_800EA750 func_800EAFD0
#include "../shared/rock_09/func_800EA750.c"
#undef func_800EA750

#define func_800EA7CC func_800EB04C
#include "../shared/rock_09/func_800EA7CC.c"
#undef func_800EA7CC

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EB094(void) {
    clear_object_slot();
}

#define func_80048DC8 func_800EB0B4
#define D_80077BC0 D_800F5FE4
#include "../shared/d1000/func_80048DC8.c"
#undef func_80048DC8
#undef D_80077BC0

// clang-format off
INCLUDE_ASM("asm/rock_15/nonmatchings/E9860", func_800EB100);
// clang-format on

#define func_80048DC8 func_800EB2D4
#define D_80077BC0 D_800F6048
#include "../shared/d1000/func_80048DC8.c"
#undef func_80048DC8
#undef D_80077BC0

// clang-format off
INCLUDE_ASM("asm/rock_15/nonmatchings/E9860", func_800EB320);
// clang-format on

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CA14(); /* extern */

void func_800EB3CC(void* arg0) {
    M2C_FIELD(arg0, s8*, 3) = 0;
    ((M2C_UNK(*)())func_8002CA14)();
}

#include "common.h"

void func_800EB3EC(void) {
}

#define func_800ED014 func_800EB3F4
#include "../shared/rock_09/func_800ED014.c"
#undef func_800ED014

#define func_800ED0B4 func_800EB494
#include "../shared/rock_09/func_800ED0B4.c"
#undef func_800ED0B4

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);

extern struct X4_PlayerObj g_Player;
extern M2C_UNK D_800F6060;
extern M2C_UNK D_800F6064;
extern M2C_UNK D_800F6068;
extern M2C_UNK D_800F6154;

#define U8(o) M2C_FIELD(self, u8*, o)
#define S8(o) M2C_FIELD(self, s8*, o)
#define U16(o) M2C_FIELD(self, u16*, o)
#define S16(o) M2C_FIELD(self, s16*, o)
#define S32(o) M2C_FIELD(self, s32*, o)
#define PTR(o) M2C_FIELD(self, void**, o)

void func_800EB56C(void* self) {
    struct X4_PlayerObj* p = &g_Player;
    s32 x;
    s32 t;

    U8(0x0) = 0x41;
    U8(0x5C) = 0x1E;
    U8(0x61) = 0;
    U8(0x60) = 4;
    t = M2C_FIELD(p, u8*, 0x14);
    {
        // !FAKE: depin: dropping it breaks the match (82/93)
        register void* a asm("$2") = &D_800743DC;
        PTR(0x58) = a;
    }
    PTR(0x30) = &D_800F6154;
    U8(0x16) = 5;
    x = S32(0x8);
    PTR(0x68) = &D_800F6068;
    PTR(0x54) = &D_800F6060;
    PTR(0x50) = &D_800F6064;
    S32(0x20) = 0;
    S32(0x24) = 0;
    S32(0x28) = 0;
    S32(0x2C) = 0;
    U8(0x67) = 0;
    U8(0x14) = t;
    S32(0x18) = x;
    S32(0x1C) = S32(0xC);
    switch (U8(0x2) >> 4) {
    case 0:
        U8(0x15) = (p->x_pos.val >= x) << 6;
        break;
    case 1:
        U8(0x15) = 0;
        break;
    case 2:
        U8(0x15) = 0x40;
        break;
    }
    set_animation(self, 0);
    {
        // !FAKE: depin: dropping it breaks the match (79/93)
        register s32 v asm("$2") = 2;
        U8(0x5) = v;
        v = U8(0x4);
        U16(0x7C) = 0x28;
        S32(0x80) = 0;
        S32(0x84) = 0;
        S32(0x88) = 0;
        S32(0x8C) = 0;
        S32(0x90) = 0;
        S32(0x94) = 0;
        U8(0x6) = 0;
        U8(0x4) = v + 1;
    }
    if (S8(0x2) == 2) {
        U16(0x7C) = 0xA;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 is_off_screen(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
void func_800EC428(struct X4_MainObj* self);
extern M2C_UNK D_800F618C;
extern void (*D_800F61A8[])(void*);

void func_800EB6E0(void* arg0) {
    s32 r;
    u8 f;
    // !FAKE: depin: dropping it breaks the match (35/66)
    register s32 c asm("$2");

    M2C_FIELD(arg0, s32*, 0x18) = M2C_FIELD(arg0, s32*, 0x8);
    M2C_FIELD(arg0, s32*, 0x1C) = M2C_FIELD(arg0, s32*, 0xC);
    D_800F61A8[M2C_FIELD(arg0, s8*, 5)](arg0);
    func_800EC428(arg0);
    r = check_enemy_hits(arg0);
    func_80030ECC(arg0);
    c = 0xC;
    if (r < 0 || (f = M2C_FIELD(arg0, u8*, 0x70), (f & 0xC) == c) ||
        (f & 3) == 3) {
        func_800477E4(5, &D_800F618C, arg0);
        c = 0x1E;
        M2C_FIELD(arg0, s16*, 0x7C) = c;
        M2C_FIELD(arg0, u8*, 3) = 0;
        c = 5;
        M2C_FIELD(arg0, s16*, 0x7E) = c;
        M2C_FIELD(arg0, u8*, 4) = M2C_FIELD(arg0, u8*, 4) + 1;
        return;
    }
    if (is_off_screen(arg0, 0x60, 0x40) == 0) {
        func_8002CCB0(arg0, 0x30, 0x30);
        return;
    }
    M2C_FIELD(arg0, u8*, 4) = 4;
}

// clang-format off
INCLUDE_ASM("asm/rock_15/nonmatchings/E9860", func_800EB7E8);
// clang-format on

#include "../shared/rock_15/func_800EB950.c"

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
extern s32 D_800741FC[];
extern s32 D_800F6224;
extern s32 D_800F6228;

void func_800EBAAC(void* arg0) {
    void* temp_v1;

    M2C_FIELD(arg0, u8*, 3) = 1;
    M2C_FIELD(arg0, u8*, 0x60) = 5;
    M2C_FIELD(arg0, u8*, 0x5C) = 1;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, void**, 0x50) = &D_800F6224;
    M2C_FIELD(arg0, void**, 0x58) = &D_800741FC;
    M2C_FIELD(arg0, void**, 0x68) = &D_800F6228;
    M2C_FIELD(arg0, void**, 0x54) = &D_800F6224;
    M2C_FIELD(arg0, u8*, 4)++;
    M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
    temp_v1 = M2C_FIELD(arg0, void**, 0x7C);
    if (M2C_FIELD(arg0, s8*, 2) == 0) {
        if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
            M2C_FIELD(arg0, s16*, 0xA) = M2C_FIELD(temp_v1, s16*, 0xA) + 0x1A;
        } else {
            M2C_FIELD(arg0, s16*, 0xA) = M2C_FIELD(temp_v1, s16*, 0xA) - 0x1A;
        }
        M2C_FIELD(arg0, s16*, 0xE) = M2C_FIELD(temp_v1, s16*, 0xE) - 0x23;
    } else {
        if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
            M2C_FIELD(arg0, s16*, 0xA) = M2C_FIELD(temp_v1, s16*, 0xA) + 0x1A;
        } else {
            M2C_FIELD(arg0, s16*, 0xA) = M2C_FIELD(temp_v1, s16*, 0xA) - 0x1A;
        }
        M2C_FIELD(arg0, s16*, 0xE) = M2C_FIELD(temp_v1, s16*, 0xE) - 0x10;
    }
    set_animation(arg0, 7);
    M2C_FIELD(arg0, u8*, 5) = 0;
    M2C_FIELD(arg0, u8*, 0x8F) = 0x20;
    M2C_FIELD(arg0, u8*, 0x8D) = 0;
    M2C_FIELD(arg0, u8*, 0x8E) = 0;
    M2C_FIELD(arg0, u8*, 0x92) = 0;
    M2C_FIELD(arg0, u8*, 0x90) = 2;
    M2C_FIELD(arg0, u8*, 0x91) = 0;
    M2C_FIELD(arg0, u8*, 0x93) = 0;
    M2C_FIELD(arg0, u8*, 0x67) = 1;
    M2C_FIELD(arg0, s8*, 0x8C) = M2C_FIELD(arg0, s8*, 2) * 0x14 + 0x1E;
}

#include "../shared/rock_15/func_800EBC08.c"

#define func_800EA1D8 func_800EBD70
#define D_800FAA64 D_800F6194
#include "../shared/d1000/func_800EA1D8.c"
#undef func_800EA1D8
#undef D_800FAA64

#include "../shared/rock_15/func_800EBDBC.c"

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CA14(); /* extern */
M2C_UNK func_8002CA54(); /* extern */

void func_800EBE48(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 4) == 3) {
        ((M2C_UNK(*)())func_8002CA14)();
        return;
    }
    ((M2C_UNK(*)())func_8002CA54)();
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EBE88(void* arg0) {
    M2C_FIELD(arg0, u8*, 5) = (u8)M2C_FIELD(arg0, u8*, 0x94);
}

#define func_8003744C func_800EBE94
#define D_80073C1C D_800F61C4
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/rock_15/func_800EBED0.c"

#include "../shared/rock_15/func_800EBF3C.c"

#define func_8003744C func_800EBFA4
#define D_80073C1C D_800F61CC
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();
void func_800EC478(void*);
void func_800EC648(void*);

extern struct X4_EngineObj g_playthrough_state;

void func_800EBFE0(void* arg0) {
    animate_object();
    if ((s8)(s32)g_playthrough_state.controlled_player !=
        (M2C_FIELD(arg0, s32*, 0x84) & 1)) {
        set_animation(arg0, 2);
    } else {
        set_animation(arg0, 1);
    }
    if (M2C_FIELD(arg0, s8*, 2) == 0) {
        if ((M2C_FIELD(arg0, s32*, 0x84) == 2) &&
            ((s8)(s32)g_playthrough_state.controlled_player == 0)) {
            play_sound(2, 0x56, arg0);
            func_800EC648(arg0);
        } else {
            play_sound(2, 0x56, arg0);
            func_800EC478(arg0);
        }
    } else {
        play_sound(2, 0x56, arg0);
        func_800EC478(arg0);
    }
    M2C_FIELD(arg0, s16*, 0x7C) = 0x4B;
    if (M2C_FIELD(arg0, s8*, 2) == 2) {
        M2C_FIELD(arg0, s16*, 0x7C) = 0x32;
    }
    M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
}

#include "../shared/rock_15/func_800EC0E8.c"

#define func_8003744C func_800EC1BC
#define D_80073C1C D_800F61D4
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/rock_15/func_800EC1F8.c"

#include "common.h"
#define M2C_UNK s32

M2C_UNK animate_object();
void func_800EC574(void* arg0);

void func_800EC254(u8* arg0) {
    animate_object();
    {
        // !FAKE: depin: dropping it breaks the match
        register s32 d asm("$2") = *(u16*)(arg0 + 0x7C) - 1;
        *(s16*)(arg0 + 0x7C) = d;
        if ((d << 16) == 0) {
            func_800EC574(arg0);
            {
                s32 t = arg0[6];
                *(s16*)(arg0 + 0x7C) = 0x3C;
                arg0[6] = t + 1;
            }
        }
    }
}

#include "../shared/rock_15/func_800EC2B0.c"

#define func_8003744C func_800EC2F8
#define D_80073C1C D_800F61E0
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/rock_15/func_800EC334.c"

#include "../shared/rock_15/func_800EC378.c"

#include "../shared/rock_15/func_800EC3C8.c"

#include "../shared/rock_15/func_800EC428.c"

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* func_8002C458();

extern u8 D_800F606C[];
extern M2C_UNK D_800F6154;

#define U8(p, o) M2C_FIELD(p, u8*, o)
#define S8(p, o) M2C_FIELD(p, s8*, o)
#define U16(p, o) M2C_FIELD(p, u16*, o)
#define S32(p, o) M2C_FIELD(p, s32*, o)
#define PTR(p, o) M2C_FIELD(p, void**, o)

void func_800EC478(void* arg0) {
    void* e;
    s32 t;

    e = func_8002C458();
    if (e != 0) {
        U8(e, 0x0) = 0x41;
        U8(e, 0x1) = 0x25;
        if (S8(arg0, 0x2) == 2) {
            U8(e, 0x2) = D_800F606C[S32(arg0, 0x84)];
        } else {
            U8(e, 0x2) = (u8)D_800CCF08 ^ (U8(arg0, 0x84) & 1);
        }
        if (S32(arg0, 0x84) == 3 && D_800CCF08 == 0) {
            U8(e, 0x2) = U8(e, 0x2) + 1;
        }
        PTR(e, 0x7C) = arg0;
        t = U16(arg0, 0x42);
        PTR(e, 0x30) = &D_800F6154;
        U16(e, 0x42) = t;
        S32(e, 0x3C) = S32(arg0, 0x3C);
        U16(e, 0x40) = U16(arg0, 0x40);
        U8(e, 0x15) = U8(arg0, 0x15);
        t = U8(arg0, 0x14);
        U8(e, 0x16) = 4;
        U8(e, 0x14) = t;
    }
}

#include "../shared/rock_15/func_800EC574.c"

#include "../shared/rock_15/func_800EC648.c"

#define func_80041AB8 func_800EC710
#define D_80075FD8 D_800F6208
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EC74C(void) {
    clear_object_slot();
}

#include "common.h"

void func_800EC76C(void) {
}

#include "../shared/rock_15/func_800EC774.c"

#define func_80041AB8 func_800EC81C
#define D_80075FD8 D_800F6218
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "../shared/rock_15/func_800EC858.c"

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();                       /* extern */
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK); /* extern */

void func_800EC8A8(void* arg0) {
    void* temp_v1;

    animate_object();
    temp_v1 = M2C_FIELD(arg0, void**, 0x50);
    if ((M2C_FIELD(temp_v1, s8*, 0) == 0) ||
        (M2C_FIELD(temp_v1, s32*, 0x8C) != 0)) {
        M2C_FIELD(arg0, s8*, 4) = 2;
    }
    M2C_FIELD(arg0, u16*, 0xA) = (u16)M2C_FIELD(temp_v1, u16*, 0xA);
    M2C_FIELD(arg0, u16*, 0xE) = (u16)M2C_FIELD(temp_v1, u16*, 0xE);
    func_8002CCB0(arg0, 0x30, 0x30);
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EC918(void) {
    clear_object_slot();
}

#define func_80041AB8 func_800EC938
#define D_80075FD8 D_800F6244
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "../shared/rock_15/func_800EC974.c"

#include "common.h"
#include "mmx6/x4.h"

extern s32 D_800F622C[];
extern s32 D_800F6234[];

#define U8F(p, o) (*(u8*)((u8*)(p) + (o)))

void func_800ECA98(struct X4_MainObj* self) {
    u8 t;
    s32 c;
    s32 y;
    s32* q;

    t = U8F(self, 0x8F);
    if (t == 0) {
        q = D_800F622C;
        self->x_speed = *(s32*)(((self->unk15 >> 4) & 4) + (u8*)q);
        y = D_800F6234[self->unk2 != 0];
        self->unk42 &= 0x7FFF;
        self->action++;
        self->y_speed = y;
        return;
    }
    U8F(self, 0x8F) = t - 1;
    c = U8F(self, 0x90) - 1;
    U8F(self, 0x90) = c;
    if ((c & 0xFF) == 0xFF) {
        U8F(self, 0x90) = 2;
        self->unk42 &= 0x7FFF;
        return;
    }
    self->unk42 |= 0x8000;
}
#undef U8F

#include "../shared/rock_15/func_800ECB50.c"

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800ECC10(void) {
    clear_object_slot();
}

#include "common.h"

void func_800ECC30(void) {
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800ECC78(void*); /* extern */
M2C_UNK func_800ECD28();   /* extern */

void func_800ECC38(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 4) == 0) {
        func_800ECC78(arg0);
        return;
    }
    func_800ECD28();
}

#include "../shared/rock_15/func_800ECC78.c"

#include "../shared/rock_15/func_800ECD28.c"

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"
#include "mmx6/rock_15.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
extern s16 D_80097222;
extern struct X4_EngineObj g_playthrough_state;
extern M2C_UNK D_800F6360;
extern M2C_UNK D_800F6618;
extern u16 D_800F70DC;

void func_800ECDCC(void* arg0) {
    s8* e = (s8*)&g_playthrough_state;
    s32 t;

    M2C_FIELD(e, u8*, 0x31) = 1;
    M2C_FIELD(arg0, u8*, 0x60) = 0xA;
    M2C_FIELD(arg0, u8*, 0x5C) = 0;
    M2C_FIELD(arg0, u8*, 0x61) = 0;
    M2C_FIELD(arg0, void**, 0x58) = &D_8007591C;
    M2C_FIELD(arg0, u8*, 3) = 0;
    M2C_FIELD(arg0, u8*, 0x14) = D_800970B4;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, void**, 0x30) = &D_800F6618;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, u8*, 0x67) = 0;
    M2C_FIELD(arg0, u8*, 0x16) = 6;
    M2C_FIELD(arg0, s32*, 0x50) = 0;
    M2C_FIELD(arg0, s32*, 0x54) = 0;
    M2C_FIELD(arg0, void**, 0x68) = 0;
    t = M2C_FIELD(arg0, s8*, 2) & 0xF0;
    if (t == 0) {
        D_800F70E4 = arg0;
        M2C_FIELD(arg0, s16*, 0x40) = 0x140;
        set_animation(arg0, 0);
        M2C_FIELD(arg0, u8*, 0x89) = 0;
        M2C_FIELD(arg0, s8*, 0x88) = -1;
        M2C_FIELD(arg0, u8*, 0x8A) = 0;
        M2C_FIELD(arg0, u8*, 0x8C) = 0;
        M2C_FIELD(arg0, void**, 0x68) = &D_800F6360;
        M2C_FIELD(arg0, u8*, 4) = 1;
        if (!(M2C_FIELD(arg0, u8*, 2) & 0xF)) {
            M2C_FIELD(arg0, u8*, 0x15) = 0;
            D_800F70DC = 0;
            M2C_FIELD(arg0, u8*, 5) = 2;
        } else {
            M2C_FIELD(arg0, u8*, 0x5C) = M2C_FIELD(e, u8*, 0x8C);
            M2C_FIELD(arg0, u8*, 5) = 0xD;
        }
    } else if (t == 0x10) {
        M2C_FIELD(arg0, u8*, 0x5C) = t;
        M2C_FIELD(arg0, u8*, 0x60) = 8;
        M2C_FIELD(arg0, u8*, 0x16) = 5;
        if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
            M2C_FIELD(arg0, u16*, 0xA) -= 0x30;
        } else {
            M2C_FIELD(arg0, u16*, 0xA) += 0x30;
        }
        M2C_FIELD(arg0, s16*, 0xE) = D_80097222 + 0x68;
        M2C_FIELD(arg0, u8*, 4) = 3;
        M2C_FIELD(arg0, u8*, 5) = 0;
    }
    M2C_FIELD(arg0, u8*, 6) = 0;
    M2C_FIELD(arg0, u8*, 7) = 0;
}

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();
s32 random_byte();
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
M2C_UNK func_80049E50(void*);
void func_800EF080(void* arg0);
extern M2C_UNK D_8007433C;
extern s8 D_800CCF5C;
extern void (*D_800F6680[])(void*);

void func_800ECF54(void* arg0) {
    s32 r;
    u16 t;

    animate_object();
    {
        s32 i = M2C_FIELD(arg0, s8*, 5) * 4;
        (*(void (**)(void*))((s8*)D_800F6680 + i))(arg0);
    }
    func_800EF080(arg0);
    r = check_enemy_hits(arg0);
    if (r < 0) {
        if (M2C_FIELD(arg0, s8*, 2) == 0) {
            D_8009711A = 1;
            M2C_FIELD(arg0, s8*, 4) = 2;
            M2C_FIELD(arg0, s8*, 5) = 0;
            return;
        }
        func_80049E50(arg0);
        M2C_FIELD(arg0, s8*, 4) = 4;
        M2C_FIELD(arg0, s8*, 3) = 0;
        return;
    }
    if (r > 0 && r != 0x7F) {
        M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
        if ((u32)(r - 0x19) < 2) {
            M2C_FIELD(arg0, s16*, 0x86) = 2;
        } else {
            M2C_FIELD(arg0, s16*, 0x86) = 0x1E;
        }
        if (r == 5 || r == 0xE || r == 0x24 ||
            ((D_800CCF5C - M2C_FIELD(arg0, s8*, 0x5C)) % 6 == 0 &&
             !(random_byte() & 3))) {
            M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
            M2C_FIELD(arg0, s16*, 0x86) = 0x2710;
            M2C_FIELD(arg0, s8*, 5) = 3;
            M2C_FIELD(arg0, s8*, 6) = 0;
            return;
        }
    }
    t = M2C_FIELD(arg0, u16*, 0x86);
    if (M2C_FIELD(arg0, s16*, 0x86) != 0) {
        M2C_FIELD(arg0, s16*, 0x86) = t - 1;
        if (t & 2) {
            M2C_FIELD(arg0, u16*, 0x42) |= 0x8000;
        } else {
            M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
        }
        if (M2C_FIELD(arg0, s16*, 0x86) == 0) {
            M2C_FIELD(arg0, void**, 0x58) = &D_8007591C;
            M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
        }
    }
    func_80030ECC(arg0);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/rock_15.h"

#define F8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F16(p, o) (*(u16*)((u8*)(p) + (o)))
#define S16(p, o) (*(s16*)((u8*)(p) + (o)))
#define FP(p, o) (*(void**)((u8*)(p) + (o)))

void set_boss_level();
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
void func_800EF164();

extern u8 D_800E9860[];
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj g_playthrough_state;

void func_800ED124(void* arg0) {
    u8 tbl[4];
    s8 v;
    u8 add;

    __builtin_memcpy(tbl, D_800E9860 + 4, 4);
    if (--S16(arg0, 0x7C) == 0) {
        func_8003D308(0x14, 0x40);
    }
    v = *(s8*)D_800F70E0;
    if (v == 0) {
        g_playthrough_state.enable_boss = 1;
        g_playthrough_state.unk25 = 1;
        FP(&g_playthrough_state, 0x20) = arg0;
        F8(&g_playthrough_state, 0x8C) = 0x30;
        set_boss_level();
        {
            u8 c = F8(&g_playthrough_state, 0x8C);
            add = tbl[F8(&g_playthrough_state, 0x8F)];
            F8(&g_playthrough_state, 0x8C) = c + add;
        }
        F16(arg0, 0xA) = background_objects[0].unk26 + 0xF0;
        {
            u16 y = background_objects[0].unk2A;
            F8(arg0, 7) = 0;
            F16(arg0, 0xE) = y + 0x50;
        }
        func_800EF164(arg0, 0, background_objects, add);
        func_800EF164(arg0, 1);
        F8(arg0, 6)++;
    }
}

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK apply_object_motion(void*);
void func_800EF0B0(void*, s32);
extern s8 D_800CCF5C;
#define D_800CCF5C_U (*(u8*)&D_800CCF5C)

void func_800ED234(void* arg0) {
    s32 n;
    s32 i;
    s8 hp;
    s8 max;
    // !FAKE: depin: dropping it breaks the match (67/70)
    register s32 f asm("$2");

    apply_object_motion(arg0);
    f = M2C_FIELD(arg0, u8*, 0x70);
    if (f & 8) {
        play_sound(2, 0x82, arg0);
        max = D_800CCF5C_U;
        hp = M2C_FIELD(arg0, s8*, 0x5C);
        if (max * 3 / 4 < hp) {
            n = 4;
        } else if (max / 2 < hp) {
            n = 8;
        } else if (max / 4 < hp) {
            n = 0xC;
        } else {
            n = 0x10;
        }
        if (n != 0) {
            i = n;
            do {
                play_sound(2, 0x83, arg0);
                func_800EF0B0(arg0, 0x30);
                i--;
            } while (i != 0);
        }
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        M2C_FIELD(arg0, u16*, 0x84) = M2C_FIELD(arg0, u16*, 0xA);
        M2C_FIELD(arg0, u8*, 6) += 1;
    }
}
#undef D_800CCF5C_U

#include "common.h"
#include "mmx6/rock_15.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();
s32 is_off_screen(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
M2C_UNK func_80049E50(void*);
extern void (*D_800F6714[])(void*);

void func_800ED34C(void* arg0) {
    s32 r;
    s8 one;
    u16 t;

    one = M2C_FIELD(D_800F70E4, s8*, 4);
    if (one != 1) {
        M2C_FIELD(arg0, s8*, 4) = 4;
        M2C_FIELD(arg0, s8*, 3) = 0;
        return;
    }
    animate_object(arg0);
    {
        s32 i = M2C_FIELD(arg0, s8*, 5) * 4;
        (*(void (**)(void*))((s8*)D_800F6714 + i))(arg0);
    }
    M2C_FIELD(arg0, s8*, 0x88) = 0;
    r = check_enemy_hits(arg0);
    if (r < 0) {
        t = M2C_FIELD(arg0, u16*, 0xE);
        M2C_FIELD(arg0, u16*, 0x86) = t;
        M2C_FIELD(arg0, u16*, 0xE) = t - 0x40;
        func_80049E50(arg0);
        M2C_FIELD(arg0, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0x86) - 0x20;
        func_80049E50(arg0);
        M2C_FIELD(arg0, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0x86) + 0x20;
        func_80049E50(arg0);
        M2C_FIELD(arg0, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0x86) + 0x40;
        func_80049E50(arg0);
        M2C_FIELD(arg0, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0x86);
        func_80049E50(arg0);
        M2C_FIELD(arg0, s8*, 3) = 0;
        M2C_FIELD(arg0, s8*, 4) = 4;
        M2C_FIELD(arg0, s8*, 5) = 0;
        return;
    }
    if (r > 0) {
        M2C_FIELD(arg0, s8*, 0x88) = one;
    }
    func_80030ECC(arg0);
    if (is_off_screen(arg0, 0x20, 0x80) == one) {
        M2C_FIELD(arg0, s8*, 3) = 0;
        M2C_FIELD(arg0, s8*, 4) = 4;
    }
}

#include "common.h"

s32 random_byte();
extern s8 D_800CCF5C;
extern u8 D_800F6260[];
extern u8 D_800F62E0[];

s32 func_800ED484(void* arg0) {
    s8* obj = arg0;
    s8 state;
    u8* tbl;
    // !FAKE: depin: dropping it breaks the match (129/133)
    register u8 v asm("$4");
    u8 w;

    state = obj[0x88];
    obj[6] = 0;
    if (state == 0) {
        if (D_800CCF5C / 2 >= obj[0x5C]) {
            obj[0x89] = random_byte() & 0xF;
            obj[0x8A] = 0;
            obj[0x88] = 1;
            v = *(obj[0x89] * 8 + obj[0x8A] + D_800F62E0);
            ((u8*)obj)[0x8A]++;
            obj[5] = v;
            return;
        }
    } else if (state == 1) {
        if (D_800CCF5C / 2 < obj[0x5C]) {
            obj[0x89] = random_byte() & 0xF;
            obj[0x8A] = 0;
            obj[0x88] = 0;
            v = *(obj[0x89] * 8 + obj[0x8A] + D_800F6260);
            ((u8*)obj)[0x8A]++;
            obj[5] = v;
            return;
        }
    }
    switch (obj[0x88]) {
    case 0:
        tbl = D_800F6260;
        w = *(obj[0x8A] + (obj[0x89] << 3) + tbl);
        if (w == 0xE) {
            obj[0x89] = random_byte() & 0xF;
            obj[0x8A] = 0;
            obj[5] = *(obj[0x89] * 8 + tbl);
        } else {
            obj[5] = w;
        }
        ((u8*)obj)[0x8A]++;
        break;
    case 1:
        tbl = D_800F62E0;
        w = *(obj[0x8A] + (obj[0x89] << 3) + tbl);
        if (w == 0xE) {
            obj[0x89] = random_byte() & 0xF;
            obj[0x8A] = 0;
            obj[5] = *(obj[0x89] * 8 + tbl);
        } else {
            obj[5] = w;
        }
        ((u8*)obj)[0x8A]++;
        break;
    case -1:
        obj[0x89] = random_byte() & 0xF;
        obj[0x8A] = 0;
        v = *(obj[0x89] * 8 + obj[0x8A] + D_800F6260);
        ((u8*)obj)[0x8A]++;
        obj[0x88] = 0;
        obj[5] = v;
        break;
    }
}

#include "common.h"
#include "mmx6/globals.h"
#include "mmx6/rock_15.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
extern M2C_UNK D_8007433C;

void func_800ED698(void* arg0) {
    s32 t;
    s8 one;
    s32 four;

    M2C_FIELD(arg0, s8*, 3) = 0;
    one = M2C_FIELD(D_800F70E4, s8*, 4);
    if (one != 1) {
        M2C_FIELD(arg0, s8*, 4) = 2;
        return;
    }
    four = 4;
    M2C_FIELD(arg0, s8*, 0x60) = 0;
    M2C_FIELD(arg0, s8*, 0x5C) = one;
    M2C_FIELD(arg0, s8*, 0x16) = four;
    M2C_FIELD(arg0, s8*, 0x67) = one;
    M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
    M2C_FIELD(arg0, s32*, 0x68) = 0;
    M2C_FIELD(arg0, s32*, 0x50) = 0;
    M2C_FIELD(arg0, s32*, 0x54) = 0;
    M2C_FIELD(arg0, s8*, 4) = one;
    M2C_FIELD(arg0, s8*, 5) = 0;
    M2C_FIELD(arg0, s8*, 6) = 0;
    M2C_FIELD(arg0, s8*, 7) = 0;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    t = M2C_FIELD(arg0, s8*, 2) & 0xF0;
    if (t == 0) {
        ((void (*)(void*, s32))set_animation)(arg0, 9);
        M2C_FIELD(arg0, s8*, 0x60) = 0xA;
        M2C_FIELD(arg0, s8*, 0x16) = four;
        M2C_FIELD(arg0, s8*, 5) = 0;
    } else if (t == 0x10) {
        ((void (*)(s32, s32, void*))play_sound)(2, 0x87, arg0);
        ((void (*)(void*, s32))set_animation)(arg0, 0xF);
        M2C_FIELD(arg0, s8*, 0x60) = 6;
        M2C_FIELD(arg0, s8*, 0x16) = four;
        M2C_FIELD(arg0, s8*, 5) = one;
    } else if (t == 0x20) {
        ((void (*)(void*, s32))set_animation)(arg0, 0x12);
        M2C_FIELD(arg0, s8*, 0x16) = four;
        M2C_FIELD(arg0, s8*, 5) = 2;
    } else if (t == 0x30) {
        ((void (*)(void*, s32))set_animation)(arg0, 0xE);
        M2C_FIELD(arg0, void**, 0x58) = &D_8007429C;
        M2C_FIELD(arg0, s8*, 0x60) = 6;
        M2C_FIELD(arg0, s8*, 0x16) = four;
        M2C_FIELD(arg0, s8*, 5) = 3;
        M2C_FIELD(arg0, s16*, 0x8C) = M2C_FIELD(arg0, s16*, 0xA);
        M2C_FIELD(arg0, s16*, 0x8E) = M2C_FIELD(arg0, s16*, 0xE);
    }
}

#include "common.h"
#include "mmx6/rock_15.h"
#define M2C_UNK s32

M2C_UNK animate_object();
s32 is_off_screen(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
M2C_UNK func_80049E50(void*);
extern void (*D_800F6758[])(s8*);

void func_800ED808(s8* arg0) {
    s8 one;

    one = *((s8*)D_800F70E4 + 4);
    if (one != 1) {
        arg0[4] = 2;
        arg0[3] = 0;
        return;
    }
    *(s32*)(arg0 + 0x18) = *(s32*)(arg0 + 0x8);
    *(s32*)(arg0 + 0x1C) = *(s32*)(arg0 + 0xC);
    animate_object(arg0);
    D_800F6758[arg0[5]](arg0);
    if (arg0[4] != one) {
        arg0[3] = 0;
        return;
    }
    if (check_enemy_hits(arg0) < 0) {
        arg0[3] = 0;
        func_80049E50(arg0);
        arg0[4] = 2;
        return;
    }
    func_80030ECC(arg0);
    if ((arg0[2] & 0xF0) == 0x30) {
        if (is_off_screen(arg0, 0x70, 0x30) != 0) {
            arg0[4] = 2;
            return;
        }
        // !FAKE: goto reaches the shared func_8002CCB0 call from the 0x30 arm; else-if with a copied call moved bytes
        goto call;
    }
    if (is_off_screen(arg0, 0x30, 0x30) == 0) {
        if ((arg0[2] & 0xF0) != 0x20) {
        call:
            func_8002CCB0(arg0, 0x20, 0x20);
        }
    } else {
        arg0[4] = 2;
    }
}

#include "common.h"
#include "mmx6/rock_15.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);
extern s32 D_800F6734;

#define SPAD20_800ED948 (*(s32*)0x1F800020)

void func_800ED948(void* arg0) {
    s32 base;
    s32 idx;
    void* p;
    s32 v;

    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        p = D_800F70E4;
        M2C_FIELD(arg0, s16*, 0x40) = M2C_FIELD(p, s16*, 0x40) + 0x400;
        v = (((func_8002A47C(M2C_FIELD(p, s8*, 1)) + 1) * 4 + 0x20) % 16) |
            (((func_8002A47C(M2C_FIELD(D_800F70E4, s8*, 1)) + 9) / 4 + 0x1E0)
             << 6);
        {
            void* q = D_800F70E4;
            M2C_FIELD(arg0, s16*, 0x42) = v;
            idx = func_8002A47C(M2C_FIELD(q, s8*, 1));
        }
        base = SPAD20_800ED948;
        M2C_FIELD(arg0, s32*, 0x3C) = base + M2C_FIELD(idx * 4 + base, s32*, 4);
        set_animation(arg0, 0x11);
        {
            // !FAKE: depin: dropping it breaks the match (63/70)
            register s32* a asm("$2") = &D_800F6734;
            M2C_FIELD(arg0, s32**, 0x50) = a;
        }
        {
            // !FAKE: depin: dropping it breaks the match (63/70)
            register s32 k asm("$2") = 0x1E;
            M2C_FIELD(arg0, s16*, 0x88) = k;
        }
        M2C_FIELD(arg0, u8*, 6) += 1;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
s32 random_byte();
extern s32 D_800F6364;

void func_800EDA60(struct X4_MainObj* self) {
    s32 a;
    s32 b;
    s32 c;
    s32 q;

    set_animation(self, 0x12);
    self->on_screen = 1;
    self->terrain_box = (void*)&D_800F6364;
    a = ((u32)random_byte() % 40 & 0xFF) + 10;
    b = ((u32)random_byte() % 30 & 0xFF) + 30;
    c = ((u32)random_byte() % 10 & 0xFF) + 15;
    q = (b << 16) / ((c * c) >> 1);
    self->gravity = q;
    self->x_accel = 0;
    self->y_speed = q * c;
    switch (self->unk2 & 0xF) {
    case 0:
        self->x_speed = (-a << 16) / c;
        break;
    case 2:
        if (random_byte() & 1) {
            self->x_speed = (-a << 16) / c;
            break;
        }
    case 1:
        self->x_speed = (a << 16) / c;
        break;
    }
    self->action_phase++;
}

#include "common.h"
#include "mmx6/rock_15.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);

void func_800EDC04(s8* arg0) {
    s8 one;
    s32 sel;
    s32 sub;
    u16 x;
    s32 v;

    one = *((s8*)D_800F70E4 + 4);
    if (one != 1) {
        arg0[3] = 0;
        arg0[4] = 2;
        return;
    }
    arg0[0x16] = 4;
    arg0[3] = 0;
    arg0[4] = one;
    sel = arg0[2] & 0xF0;
    arg0[6] = 0;
    if (sel == 0) {
        set_animation(arg0, 5);
        x = *(u16*)(arg0 + 0xA);
        sub = (u8)arg0[2] & 0xF;
        *(u16*)(arg0 + 0x5C) = x;
        *(u16*)(arg0 + 0x5E) = *(u16*)(arg0 + 0xE);
        if (sub == 0) {
            // !FAKE: zero arm placed after else arm; else-if chain moved bytes
            goto zero;
        }
        if (sub == one) {
            // !FAKE: plus arm placed after zero arm; else-if chain moved bytes
            goto plus;
        }
        arg0[5] = 0;
        *(s16*)(arg0 + 0x54) = 0x1E;
        return;
    zero:
        v = x - 0x40;
        // !FAKE: zero arm jumps over the plus arm to the shared store
        goto store;
    plus:
        v = x + 0x40;
    store:
        *(u16*)(arg0 + 0xA) = v;
        arg0[5] = 0;
        *(s16*)(arg0 + 0x54) = 0x1E;
    } else if (sel == 0x10) {
        if (!((u8)arg0[2] & 0xF)) {
            arg0[0x16] = 4;
            set_animation(arg0, 0xB);
        }
        arg0[3] = one;
        arg0[5] = one;
    }
}

#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK move_object(s32);

void func_800EDCF4(void* arg0) {
    void* parent;
    s32 angle;
    s32 d;
    s32 a;
    s32 b;

    parent = M2C_FIELD(arg0, void**, 0x50);
    {
        // !FAKE: depin: dropping it breaks the match (69/73)
        register s32 py asm("$2") = M2C_FIELD(parent, s16*, 0xE);
        angle =
            ratan2(M2C_FIELD(arg0, s16*, 0xE) - py,
                   M2C_FIELD(parent, s16*, 0xA) - M2C_FIELD(arg0, s16*, 0xA));
    }
    M2C_FIELD(arg0, s32*, 0x20) = rcos(angle) * 0x10;
    M2C_FIELD(arg0, s32*, 0x24) = rsin(angle) * 0x10;
    if (M2C_FIELD(arg0, s32*, 0x20) < 0) {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
    } else {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    }
    move_object(arg0);
    a = M2C_FIELD(parent, s16*, 0xA);
    b = M2C_FIELD(arg0, s16*, 0xA);
    d = a - b;
    if (d >= 0) {
        if (d < 3) {
            // !FAKE: range test needs per-sign compares jumping to one shared block (C0144); abs() form folds to a negate
            goto near_x;
        }
        return;
    }
    if (b - a < 3) {
    near_x:
        a = M2C_FIELD(parent, s16*, 0xE);
        b = M2C_FIELD(arg0, s16*, 0xE);
        d = a - b;
        if (d >= 0) {
            if (d < 3) {
                // !FAKE: range test needs per-sign compares jumping to one shared block (C0144); abs() form folds to a negate
                goto near_y;
            }
            return;
        }
        if (b - a < 3) {
        near_y:
            M2C_FIELD(parent, u8*, 0x7)--;
            M2C_FIELD(arg0, u8*, 0x6)++;
        }
    }
}
