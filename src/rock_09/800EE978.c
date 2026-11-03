#define func_800484D8 func_800EE978
#define D_80077BA4 D_800F6310
#include "../shared/SLUS_013.95/func_800484D8.c"
#undef func_800484D8
#undef D_80077BA4

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EE9C4(void) {
    clear_object_slot();
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20_EE9E4 (*(s32*)0x1F800020)

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);
M2C_UNK clear_object_slot();
s32 random_byte();
extern u32* D_80095098;
extern s32 g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern s16 D_800970AA;
extern s32 D_800F6350;

#define START(self)                                                            \
    {                                                                          \
        M2C_FIELD(self, s16*, 0x7C) = (random_byte() % 3 + 1) * 100 + 200;     \
        M2C_FIELD(self, u8*, 5) = 1;                                           \
        M2C_FIELD(self, u8*, 3) = 0;                                           \
        flag = 1;                                                              \
    }

void func_800EE9E4(void* self) {
    s32 flag = 0;
    s32 a;
    s32 b;

    if (D_800CD30A != 7) {
        clear_object_slot(self);
        return;
    }
    M2C_FIELD(self, u8*, 0) = 0x41;
    M2C_FIELD(self, u16*, 0x40) =
        D_80095098[func_8002A47C(M2C_FIELD(self, s8*, 1))] >> 7;
    a = func_8002A47C(M2C_FIELD(self, s8*, 1));
    b = func_8002A47C(M2C_FIELD(self, s8*, 1));
    M2C_FIELD(self, u16*, 0x42) =
        ((a * 4 + 0x20) % 16) | (((b + 8) / 4 + 0x1E0) << 6);
    M2C_FIELD(self, s32*, 0x3C) =
        SPAD20_EE9E4 +
        ((s32*)SPAD20_EE9E4)[func_8002A47C(M2C_FIELD(self, s8*, 1))];
    switch (M2C_FIELD(self, s8*, 2)) {
    case 0:
        if ((u32)((u16)D_800970AA - 0x141) < 0x8BF) {
            START(self);
        }
        break;
    case 1:
        if ((u32)((u16)D_800970AA - 0xC81) < 0x3BF) {
            START(self);
        }
        break;
    case 2:
        if ((u32)((u16)D_800970AA - 0x4E1) < 0x17F) {
            START(self);
        }
        break;
    case 3:
        if ((u32)((u16)D_800970AA - 0x1361) < 0x92F) {
            START(self);
        }
        break;
    case 4:
        if ((u32)((u16)D_800970AA - 1) < 0x41F) {
            START(self);
        }
        break;
    case 5:
        if ((u32)((u16)g_Player.x_pos.i.hi - 0x141) < 0x71F &&
            g_Player.y_pos.i.hi < 0x430) {
            START(self);
        }
        break;
    case 10:
        ((void (*)(void*, s32))set_animation)(self, 0);
        flag = 1;
        M2C_FIELD(self, s16*, 0x7C) = 0x28;
        M2C_FIELD(self, s32*, 0x54) = 0;
        M2C_FIELD(self, s32*, 0x50) = 0;
        M2C_FIELD(self, u8*, 5) = 3;
        M2C_FIELD(self, u8*, 3) = flag;
        break;
    case 11:
        M2C_FIELD(self, s16*, 0x7C) = 0x28;
        ((void (*)(void*, s32))set_animation)(self, 2);
        flag = 1;
        M2C_FIELD(self, s32*, 0x54) = 0;
        M2C_FIELD(self, s32*, 0x50) = 0;
        M2C_FIELD(self, u8*, 5) = 3;
        M2C_FIELD(self, u8*, 3) = flag;
        break;
    }
    if (flag) {
        struct X4_PlayerObj* p = &g_Player;
        M2C_FIELD(self, u8*, 0x5C) = 4;
        M2C_FIELD(self, u8*, 0x61) = 0;
        M2C_FIELD(self, u8*, 0x14) = M2C_FIELD(p, u8*, 0x14);
        M2C_FIELD(self, void**, 0x30) = &D_800F6350;
        M2C_FIELD(self, u8*, 0x16) = 4;
        M2C_FIELD(self, s32*, 0x68) = 0;
        M2C_FIELD(self, u8*, 0x67) = 0;
        M2C_FIELD(self, void**, 0x58) = &D_8007497C;
        M2C_FIELD(self, u8*, 0x60) = 6;
        M2C_FIELD(self, u8*, 0x15) = (M2C_FIELD(self, s32*, 8) <= p->x_pos.val)
                                     << 6;
        M2C_FIELD(self, u8*, 4) = 1;
        M2C_FIELD(self, u8*, 6) = 0;
    }
}
#undef g_Player
#undef SPAD20_EE9E4

#include "../shared/rock_09/func_800EECCC.c"

// clang-format off
INCLUDE_ASM("asm/rock_09/nonmatchings/E9860", func_800EEF04);

INCLUDE_ASM("asm/rock_09/nonmatchings/E9860", func_800EF004);
// clang-format on

#define func_800EFDB4 func_800EF060
#define D_800F6DD8 D_800F6370
#include "../shared/rock_04/func_800EFDB4.c"
#undef func_800EFDB4
#undef D_800F6DD8

#define func_800EFE78 func_800EF124
#define D_80097420 D_80097420
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK clear_object_slot();
#include "mmx6/state.h"

void func_800EF124(struct X4_BaseObj* self) {
    s32 a;
    s32 b;
    s32 c;

    a = *(u16*)((u8*)self + 0x80) + 1;
    b = *(u16*)((u8*)self + 0x82) - 1;
    *(u16*)((u8*)self + 0x80) = a;
    *(u16*)((u8*)self + 0x82) = b;
    if (!(D_80097420.frame_counter & 1)) {
        *(u16*)((u8*)self + 0xA) = a;
    } else {
        *(u16*)((u8*)self + 0xA) = b;
    }
    c = *(u16*)((u8*)self + 0x7C) - 1;
    *(u16*)((u8*)self + 0x7C) = c;
    if ((c << 16) == 0) {
        clear_object_slot();
    }
}
#undef func_800EFE78
#undef D_80097420

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EF19C(void) {
    clear_object_slot();
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK move_object(); /* extern */

void func_800EF1BC(void) {
    ((M2C_UNK(*)())move_object)();
}

#define func_8003744C func_800EF1DC
#define D_80073C1C D_800F6380
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

// clang-format off
INCLUDE_ASM("asm/rock_09/nonmatchings/E9860", func_800EF218);
// clang-format on

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EF264(void* arg0) {
    M2C_FIELD(arg0, s8*, 3) = 1;
    M2C_FIELD(arg0, s16*, 0x7C) = 0x32;
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

// clang-format off
INCLUDE_ASM("asm/rock_09/nonmatchings/E9860", func_800EF284);

INCLUDE_ASM("asm/rock_09/nonmatchings/E9860", func_800EF474);
// clang-format on

#define func_80046C64 func_800EF69C
#define D_800762A0 D_800F63EC
#include "../shared/d1000/func_80046C64.c"
#undef func_80046C64
#undef D_800762A0

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EF6DC(void) {
    clear_object_slot();
}

// clang-format off
INCLUDE_ASM("asm/rock_09/nonmatchings/E9860", func_800EF6FC);
// clang-format on

#define func_800EE70C func_800EF83C
#define g_Player g_Player
#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK func_8002B6B0();
M2C_UNK player_load_weapon_palette(void*);
M2C_UNK func_8003CDF0(void*);
M2C_UNK clear_flash_palette(void*);
M2C_UNK refresh_weapon_state(void*);
extern s32 g_Player;
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj g_playthrough_state;

#define F8(p, o) (*(s8*)((u8*)(p) + (o)))
#define FU8(p, o) (*(u8*)((u8*)(p) + (o)))
#define FU16(p, o) (*(u16*)((u8*)(p) + (o)))
#define F16(p, o) (*(s16*)((u8*)(p) + (o)))
#define F32(p, o) (*(s32*)((u8*)(p) + (o)))

void func_800EF83C(u8* arg0) {
    struct X4_PlayerObj* p = &g_Player;
    u8* q;
    u16 a;
    s32 two;

    if (F8(p, 0x5C) != 0) {
        background_objects[0].unk44 = 0;
        background_objects[1].unk44 = 0;
        background_objects[2].unk44 = 0;
        two = 2;
        q = (u8*)&g_playthrough_state;
        q[0x10] = two;
        q[0x11] = two;
        q[0x12] = two;
        q[0x13] = two;
        q[0x14] = two;
        q[0x15] = two;
        q[0x16] = two;
        q[0x17] = two;
        q[0x19] = two;
        arg0[0] |= 8;
        F32(arg0, 0x88) = F32(p, 0x68);
        F32(p, 0x68) = 0;
        FU8(p, 0x5) = 2;
        refresh_weapon_state(p);
        func_8003CDF0(p);
        clear_flash_palette(p);
        player_load_weapon_palette(p);
        func_8002B6B0();
        F16(arg0, 0x7C) = 0;
        a = FU16(p, 0xA);
        FU16(arg0, 0x80) = a;
        FU16(arg0, 0x82) = a;
        arg0[6]++;
        play_sound(1, 1, arg0);
    }
}
#undef func_800EE70C
#undef g_Player

#define func_800EE800 func_800EF930
#define D_80097420 D_80097420
#include "common.h"
#include "mmx6/x4.h"

extern s32 g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj g_playthrough_state;

#define FU16(p, o) (*(u16*)((u8*)(p) + (o)))

void func_800EF930(u8* arg0) {
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
#undef g_Player
#undef func_800EE800
#undef D_80097420

#define func_800EE8C4 func_800EF9F4
#define background_objects background_objects
#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8002B6B0();
M2C_UNK player_load_weapon_palette();
M2C_UNK func_8003CDF0();
M2C_UNK clear_flash_palette(void*);
M2C_UNK refresh_weapon_state(void*);
extern s32 g_Player;
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj g_playthrough_state;

void func_800EF9F4(void* arg0) {
    void* p;
    s32 v;

    if (M2C_FIELD(arg0, s16*, 0x7C) != 0) {
        M2C_FIELD(arg0, s16*, 0x7C) =
            (s16)((u16)M2C_FIELD(arg0, s16*, 0x7C) - 1);
        return;
    }
    play_sound(1, 1, arg0);
    p = &g_Player;
    background_objects[0].unk44 = 0;
    background_objects[1].unk44 = 0;
    background_objects[2].unk44 = 0;
    v = 2;
    g_playthrough_state.unk10 = v;
    g_playthrough_state.unk11 = v;
    g_playthrough_state.unk12 = v;
    g_playthrough_state.unk13 = v;
    g_playthrough_state.unk14 = v;
    g_playthrough_state.unk15 = v;
    g_playthrough_state.unk16 = v;
    g_playthrough_state.unk17 = v;
    g_playthrough_state.unk19 = v;
    M2C_FIELD(arg0, u8*, 0) |= 8;
    M2C_FIELD(arg0, s32*, 0x88) = M2C_FIELD(p, s32*, 0x68);
    M2C_FIELD(p, s32*, 0x68) = 0;
    M2C_FIELD(p, s8*, 5) = 2;
    refresh_weapon_state(p);
    func_8003CDF0(p);
    clear_flash_palette(p);
    player_load_weapon_palette(p);
    func_8002B6B0();
    M2C_FIELD(arg0, s16*, 0x7C) = 0;
    M2C_FIELD(arg0, s16*, 0x82) = M2C_FIELD(arg0, s16*, 0x80) =
        M2C_FIELD(p, s16*, 0xA);
    M2C_FIELD(arg0, u8*, 6) += 1;
}
#undef func_800EE8C4
#undef background_objects

// clang-format off
INCLUDE_ASM("asm/rock_09/nonmatchings/E9860", func_800EFAF4);

INCLUDE_ASM("asm/rock_09/nonmatchings/E9860", func_800EFEE8);
// clang-format on

#define func_800EA1D8 func_800EFFF4
#define D_800FAA64 D_800F6440
#include "../shared/d1000/func_800EA1D8.c"
#undef func_800EA1D8
#undef D_800FAA64

// clang-format off
INCLUDE_ASM("asm/rock_09/nonmatchings/E9860", func_800F0040);
// clang-format on

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CA14(); /* extern */
M2C_UNK func_8002CA54(); /* extern */

void func_800F00BC(struct ObjectHeader* arg0) {
    if (arg0->state == 2) {
        ((M2C_UNK(*)())func_8002CA14)();
        return;
    }
    ((M2C_UNK(*)())func_8002CA54)();
}

#define func_800EEFCC func_800F00FC
#define g_Player g_Player
#include "common.h"
#include "mmx6/x4.h"

s32 func_8002D654(s8*, u8*);
extern s32 g_Player;

#define F8(p, o) (*(s8*)((u8*)(p) + (o)))
#define FU16(p, o) (*(u16*)((u8*)(p) + (o)))

void func_800F00FC(s8* arg0) {
    u8* p = (u8*)&g_Player;
    u16 v;
    u16 w;

    if (func_8002D654(arg0, p) != 0) {
        if (arg0[2] == 2) {
            v = FU16(p, 0xA);
            FU16(arg0, 0x7C) = 0;
            arg0[5] = 3;
            arg0[6] = 0;
            FU16(arg0, 0x84) = v;
            return;
        }
        w = FU16(p, 0xA);
        arg0[5] = 2;
        arg0[6] = 0;
        FU16(arg0, 0x84) = w;
    }
}
#undef func_800EEFCC
#undef g_Player

#include "common.h"
#include "mmx6/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s16 D_800970AA;

void func_800F0174(void* arg0) {
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

void func_800F01C0(void* arg0) {
    if (D_800970AA >= M2C_FIELD(arg0, s16*, 0xA)) {
        M2C_FIELD(arg0, u16*, 0x84) = (u16)D_800970AA;
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, s8*, 5) = 3;
        M2C_FIELD(arg0, s8*, 6) = 0;
    }
}

#define func_8003744C func_800F01FC
#define D_80073C1C D_800F6468
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_8003744C func_800F0238
#define D_80073C1C D_800F6504
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800EF144 func_800F0274
#include "../shared/commander_yammark/func_800EF144.c"
#undef func_800EF144

#define func_800EF1E8 func_800F0318
#include "../shared/commander_yammark/func_800EF1E8.c"
#undef func_800EF1E8

#define func_800EF27C func_800F03AC
#define D_80097420 D_80097420
#include "../shared/commander_yammark/func_800EF27C.c"
#undef func_800EF27C
#undef D_80097420

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800F0414(void) {
    clear_object_slot();
}

#include "../shared/rock_09/func_800F0434.c"

// clang-format off
INCLUDE_ASM("asm/rock_09/nonmatchings/E9860", func_800F06B4);

INCLUDE_ASM("asm/rock_09/nonmatchings/E9860", func_800F0910);
// clang-format on

#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK animate_object();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK apply_object_motion(void*);
void func_800F0434(s8* self, u32 arg1);
extern s32 D_800F651C;
extern s16 D_800F6BEA;
extern s16 D_800F6BF0;

#define F(T, p, o) (*(T*)((u8*)(p) + (o)))

void func_800F0C8C(void* arg0) {
    s16 t;

    if (F(void*, arg0, 0x68) == 0) {
        if (F(s16, arg0, 0xE) >= (D_800F6BEA + D_800F6BF0) / 2) {
            F(void*, arg0, 0x68) = &D_800F651C;
        }
    }
    if ((F(u8, arg0, 0x70) & 8) && F(u8, arg0, 0x47) == 0x11) {
        func_800F0434(arg0, 4);
        F(s32, arg0, 0x24) = 0;
        F(u16, arg0, 0x7C) = 0;
        F(u8, arg0, 6)++;
    } else {
        t = ++F(s16, arg0, 0x7C);
        if ((s16)(t % 20) == 0) {
            play_sound(2, 0x38, arg0);
        }
    }
    animate_object(arg0);
    apply_object_motion(arg0);
    func_8002CCB0(arg0, 0x80, 0x80);
}

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#include "mmx6/x4.h"

M2C_UNK animate_object();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK apply_object_motion(void*);
s32 random_byte();
extern struct X4_EngineObj g_playthrough_state;
extern u8 D_800F6924[];

void func_800F0DB4(void* arg0) {
    u32 r;
    u8 i;
    s32 v;
    u8* e;

    r = random_byte() & 0xF;
    e = (u8*)&g_playthrough_state;
    M2C_FIELD(arg0, u8*, 0x87) = 0;
    if (M2C_FIELD(e, u8*, 0x68) == 2) {
        if (M2C_FIELD(e, s8*, 0x8C) / 2 < M2C_FIELD(arg0, s8*, 0x5C)) {
            if (r < 8) {
                M2C_FIELD(arg0, u8*, 0x86) = 0;
            } else {
                M2C_FIELD(arg0, u8*, 0x86) = 1;
            }
        } else if (r < 8) {
            M2C_FIELD(arg0, u8*, 0x86) = 0;
        } else {
            M2C_FIELD(arg0, u8*, 0x86) = M2C_FIELD(e, u8*, 0x68);
        }
    } else if (M2C_FIELD(e, s8*, 0x8C) / 2 < M2C_FIELD(arg0, s8*, 0x5C) ||
               r < 8) {
        M2C_FIELD(arg0, u8*, 0x86) = 0;
    } else {
        M2C_FIELD(arg0, u8*, 0x86) = 1;
    }
    i = M2C_FIELD(arg0, u8*, 0x87)++;
    v = D_800F6924[i + M2C_FIELD(arg0, u8*, 0x86) * 6];
    M2C_FIELD(arg0, u8*, 6) = 0;
    M2C_FIELD(arg0, u8*, 5) = v;
    animate_object(arg0);
    apply_object_motion(arg0);
    func_8002CCB0(arg0, 0x80, 0x80);
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s16 D_800F6BF2;
extern s16 D_800F6BF4;

#define POS M2C_FIELD(arg0, s16*, 0xA)

#define STEP(D)                                                                \
    {                                                                          \
        p = POS;                                                               \
        lim = D;                                                               \
        q = POS;                                                               \
        raw = D;                                                               \
        if (p < lim) {                                                         \
            POS = q + 3;                                                       \
            if (POS >= lim) {                                                  \
                POS = raw;                                                     \
                M2C_FIELD(arg0, s8*, 7) = 1;                                   \
            }                                                                  \
        } else {                                                               \
            POS = q - 3;                                                       \
            if (lim >= POS) {                                                  \
                POS = raw;                                                     \
                M2C_FIELD(arg0, s8*, 7) = 1;                                   \
            }                                                                  \
        }                                                                      \
    }

void func_800F0ED8(void* arg0) {
    s32 lim;
    u16 raw;
    s32 p;
    u16 q;

    if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
        STEP(D_800F6BF2)
    } else {
        STEP(D_800F6BF4)
    }
    if (M2C_FIELD(arg0, s8*, 7) != 0) {
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, s16*, 0x7E) = 0;
        M2C_FIELD(arg0, u8*, 6) += 1;
    }
}

#include "../shared/rock_09/func_800F0F9C.c"

#include "common.h"
#include "mmx6/x4.h"

extern s32 g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern s16 D_800F6BE8;

void func_800F1064(struct X4_MainObj* arg0) {
    s16 x;
    // !FAKE: depin: dropping it breaks the match (39/56)
    register s32 p asm("$6");
    s32 d;

    if (++arg0->unk7C == 0x3C) {
        p = g_Player.x_pos.i.hi;
        x = arg0->x_pos.i.hi;
        d = p - x;
        if (d >= 0) {
            if (d >= 0x40) {
                // !FAKE: range test needs per-sign compares jumping to one shared block (C0144); abs() form folds to a negate
                goto far;
            }
            // !FAKE: range test needs per-sign compares jumping to one shared block (C0144); abs() form folds to a negate
            goto near;
        }
        if ((d = x - p) >= 0x40) {
        far:
            if (arg0->x_pos.i.hi < D_800F6BE8) {
                arg0->unk15 = 0x40;
                arg0->x_speed = 0x40000;
            } else {
                arg0->unk15 = 0;
                arg0->x_speed = -0x40000;
            }
        } else {
        near:
            if (g_Player.x_pos.i.hi > arg0->x_pos.i.hi) {
                arg0->unk15 = 0x40;
            } else {
                arg0->unk15 = 0;
            }
        }
        arg0->y_speed = 0;
        arg0->gravity = 0x1000;
        arg0->action_phase = 8;
    }
}
#undef g_Player

// clang-format off
INCLUDE_ASM("asm/rock_09/nonmatchings/E9860", func_800F1144);

INCLUDE_ASM("asm/rock_09/nonmatchings/E9860", func_800F1284);
// clang-format on

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void* enemy_slot_alloc();
M2C_UNK clear_object_slot();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
extern struct X4_EngineObj g_playthrough_state;
extern u32 D_800F6C0C;

#define SB(p, o) (*(s8*)((u8*)(p) + (o)))
#define UH(p, o) (*(u16*)((u8*)(p) + (o)))
#define P(p, o) (*(void**)((u8*)(p) + (o)))

void func_800F139C(void* arg0) {
    void* parent;
    s8* p;

    parent = P(arg0, 0x80);
    if (SB(parent, 0) != 0) {
        if (SB(parent, 7) == 0) {
            if ((s16)--UH(arg0, 0x7E) == -1) {
                UH(arg0, 0x7E) = 5;
                UH(arg0, 0x42) ^= 0x8000;
            }
            func_8002CCB0(arg0, 0x80, 0x80);
        }
    } else {
        if (g_playthrough_state.stage != 0xC) {
            if (D_800F6C0C < 0x1519) {
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

// clang-format off
INCLUDE_ASM("asm/rock_09/nonmatchings/E9860", func_800F14D4);

INCLUDE_ASM("asm/rock_09/nonmatchings/E9860", func_800F17AC);

INCLUDE_ASM("asm/rock_09/nonmatchings/E9860", func_800F1900);
// clang-format on

#include "common.h"
#include "psyq/libgte.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

s32 random_byte();
void func_800F14D4(void*, s32);
extern s32 D_800F6ABC;
extern s32 D_800F6AC0;
extern s32 D_800F6AC4;
extern void* D_800F6C08;

void func_800F217C(struct X4_MainObj* self) {
    struct X4_MainObj* p;
    s16 angle;
    const u8* const* anim;

    p = D_800F6C08;
    anim = p->animation_table;
    self->unk42 &= 0x7FFF;
    self->animation_table = anim;
    self->bg_offset = p->bg_offset;
    self->unk16 = 3;
    self->air_state = 0;
    self->on_screen = 0;
    self->terrain_box = (void*)&D_800F6ABC;
    self->attack_box = &D_800F6AC0;
    self->hurt_box = &D_800F6AC4;
    self->collision_data = &D_800755FC;
    func_800F14D4(self, 0x16);
    self->unk15 = ((struct X4_MainObj*)D_800F6C08)->unk15;
    angle = (random_byte() % 3) * -0x1C7;
    self->x_speed = rcos(angle) * 0x10;
    self->y_speed = -rsin(angle) * 0x10;
    if (self->unk15 == 0) {
        self->x_pos.i.hi = ((struct X4_MainObj*)D_800F6C08)->x_pos.i.hi - 8;
        self->x_speed = -self->x_speed;
    } else {
        self->x_pos.i.hi = ((struct X4_MainObj*)D_800F6C08)->x_pos.i.hi + 8;
    }
    if (self->unk2 == 2) {
        self->y_pos.i.hi = ((struct X4_MainObj*)D_800F6C08)->y_pos.i.hi - 0x18;
    } else {
        self->y_pos.i.hi = ((struct X4_MainObj*)D_800F6C08)->y_pos.i.hi + 0x10;
        self->y_speed = -self->y_speed;
    }
    self->x_accel = 0;
    self->gravity = 0;
    self->hp = 4;
    self->contact_damage = 4;
    *(s32*)((u8*)self + 0x8C) = 0;
    self->action = 0;
    self->state++;
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK animate_object();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK apply_object_motion(void*);
s32 func_80030ECC(void*);
s32 check_enemy_hits(void*);
M2C_UNK func_80049E50(void*);
extern s32 g_Player;
extern s16 D_800970AA;
extern s8 D_800CCF5C;
extern s32 D_800F6BF8;
extern s32 D_800F6BFC;
extern void* D_800F6C08;

void func_800F2348(void* arg0) {
    s32 x;
    s32* pl;

    if (D_800F6BF8 != 0 || D_800F6BFC != 0) {
        M2C_FIELD(arg0, u8*, 4)++;
        return;
    }
    if (check_enemy_hits(arg0) < 0 || M2C_FIELD(arg0, u8*, 0x70) != 0 ||
        func_80030ECC(arg0) != 0) {
        func_80049E50(arg0);
        M2C_FIELD(arg0, u8*, 4)++;
        return;
    }
    switch (M2C_FIELD(arg0, s8*, 5)) {
    case 0:
        if (++M2C_FIELD(arg0, s32*, 0x8C) == 0x18) {
            M2C_FIELD(arg0, s32*, 0x20) = 0;
            M2C_FIELD(arg0, s32*, 0x24) = 0;
            M2C_FIELD(arg0, s32*, 0x8C) = 0;
            M2C_FIELD(arg0, u8*, 5)++;
        }
        break;
    case 1:
        if (++M2C_FIELD(arg0, s32*, 0x8C) == 0x28) {
            play_sound(2, 0x3C, arg0);
            if (D_800970AA > M2C_FIELD(arg0, s16*, 0xA)) {
                M2C_FIELD(arg0, u8*, 0x15) = 0x40;
            } else {
                M2C_FIELD(arg0, u8*, 0x15) = 0;
            }
            if (M2C_FIELD(D_800F6C08, s8*, 0x5C) > D_800CCF5C) {
                if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
                    M2C_FIELD(arg0, s32*, 0x20) = 0x30000;
                } else {
                    M2C_FIELD(arg0, s32*, 0x20) = -0x30000;
                }
            } else if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
                M2C_FIELD(arg0, s32*, 0x20) = 0x40000;
            } else {
                M2C_FIELD(arg0, s32*, 0x20) = -0x40000;
            }
            M2C_FIELD(arg0, u8*, 5)++;
        }
        break;
    case 2:
        pl = &g_Player;
        x = M2C_FIELD(arg0, s32*, 0xC);
        if (x < pl[3]) {
            M2C_FIELD(arg0, s32*, 0xC) = x + 0x8000;
            if (pl[3] < x + 0x8000) {
                M2C_FIELD(arg0, s32*, 0xC) = pl[3];
            }
        } else if (pl[3] < x) {
            M2C_FIELD(arg0, s32*, 0xC) = x - 0x8000;
            if (x - 0x8000 < pl[3]) {
                M2C_FIELD(arg0, s32*, 0xC) = pl[3];
            }
        }
        break;
    }
    func_8002CCB0(arg0, 0x20, 0x10);
    animate_object(arg0);
    apply_object_motion(arg0);
}

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

s32 random_byte();
void func_800F14D4(void*, s32);
extern s32 D_800F6AC8;
extern s32 D_800F6ACC;
extern s16 D_800F6AD8[];
extern s16 D_800F6B18[];
extern void* D_800F6C08;

void func_800F257C(struct X4_MainObj* self) {
    struct X4_MainObj* p;

    p = D_800F6C08;
    self->animation_table = p->animation_table;
    self->unk42 &= 0x7FFF;
    self->bg_offset = p->bg_offset;
    self->unk16 = 3;
    self->air_state = 0;
    self->on_screen = 0;
    self->terrain_box = 0;
    self->attack_box = &D_800F6AC8;
    self->hurt_box = &D_800F6ACC;
    self->collision_data = &D_800755FC;
    func_800F14D4(self, 0x17);
    if (self->unk2 == 4) {
        if (((struct X4_MainObj*)D_800F6C08)->unk15 == 0) {
            self->x_pos.i.hi =
                ((struct X4_MainObj*)D_800F6C08)->x_pos.i.hi +
                D_800F6AD8[((struct X4_MainObj*)D_800F6C08)
                               ->animation_step.fields.frame_index *
                           2];
        } else {
            self->x_pos.i.hi =
                ((struct X4_MainObj*)D_800F6C08)->x_pos.i.hi -
                D_800F6AD8[((struct X4_MainObj*)D_800F6C08)
                               ->animation_step.fields.frame_index *
                           2];
        }
        self->y_pos.i.hi =
            ((struct X4_MainObj*)D_800F6C08)->y_pos.i.hi +
            D_800F6AD8[((struct X4_MainObj*)D_800F6C08)
                               ->animation_step.fields.frame_index *
                           2 +
                       1];
        self->x_speed = 0x20000;
        self->unk15 = 0x40;
    } else {
        if (((struct X4_MainObj*)D_800F6C08)->unk15 == 0) {
            self->x_pos.i.hi =
                ((struct X4_MainObj*)D_800F6C08)->x_pos.i.hi +
                D_800F6B18[((struct X4_MainObj*)D_800F6C08)
                               ->animation_step.fields.frame_index *
                           2];
        } else {
            self->x_pos.i.hi =
                ((struct X4_MainObj*)D_800F6C08)->x_pos.i.hi -
                D_800F6B18[((struct X4_MainObj*)D_800F6C08)
                               ->animation_step.fields.frame_index *
                           2];
        }
        self->y_pos.i.hi =
            ((struct X4_MainObj*)D_800F6C08)->y_pos.i.hi +
            D_800F6B18[((struct X4_MainObj*)D_800F6C08)
                               ->animation_step.fields.frame_index *
                           2 +
                       1];
        self->x_speed = -0x20000;
        self->unk15 = 0;
    }
    self->y_speed = (random_byte() % 4 << 16) + 0x50000;
    self->x_accel = 0;
    self->gravity = 0x3000;
    self->hp = 4;
    self->contact_damage = 4;
    self->action = 0;
    self->state++;
}

#include "common.h"
#include "mmx6/x4.h"

void func_800F14D4(void*, s32);
extern s16 D_800F6AD8[];
extern s16 D_800F6B18[];
extern void* D_800F6C08;

void func_800F279C(struct X4_MainObj* self) {
    struct X4_MainObj* p;

    p = D_800F6C08;
    self->animation_table = p->animation_table;
    self->unk42 &= 0x7FFF;
    self->bg_offset = p->bg_offset;
    self->unk16 = 2;
    self->air_state = 0;
    self->on_screen = 0;
    self->terrain_box = 0;
    self->attack_box = 0;
    self->hurt_box = 0;
    self->collision_data = 0;
    func_800F14D4(self, 0x18);
    if (self->unk2 == 6) {
        if (((struct X4_MainObj*)D_800F6C08)->unk15 == 0) {
            self->x_pos.i.hi =
                ((struct X4_MainObj*)D_800F6C08)->x_pos.i.hi +
                D_800F6AD8[((struct X4_MainObj*)D_800F6C08)
                               ->animation_step.fields.frame_index *
                           2];
        } else {
            self->x_pos.i.hi =
                ((struct X4_MainObj*)D_800F6C08)->x_pos.i.hi -
                D_800F6AD8[((struct X4_MainObj*)D_800F6C08)
                               ->animation_step.fields.frame_index *
                           2];
        }
        self->y_pos.i.hi =
            ((struct X4_MainObj*)D_800F6C08)->y_pos.i.hi +
            D_800F6AD8[((struct X4_MainObj*)D_800F6C08)
                               ->animation_step.fields.frame_index *
                           2 +
                       1];
        self->unk15 = 0x40;
    } else {
        if (((struct X4_MainObj*)D_800F6C08)->unk15 == 0) {
            self->x_pos.i.hi =
                ((struct X4_MainObj*)D_800F6C08)->x_pos.i.hi +
                D_800F6B18[((struct X4_MainObj*)D_800F6C08)
                               ->animation_step.fields.frame_index *
                           2];
        } else {
            self->x_pos.i.hi =
                ((struct X4_MainObj*)D_800F6C08)->x_pos.i.hi -
                D_800F6B18[((struct X4_MainObj*)D_800F6C08)
                               ->animation_step.fields.frame_index *
                           2];
        }
        self->y_pos.i.hi =
            ((struct X4_MainObj*)D_800F6C08)->y_pos.i.hi +
            D_800F6B18[((struct X4_MainObj*)D_800F6C08)
                               ->animation_step.fields.frame_index *
                           2 +
                       1];
        self->unk15 = 0;
    }
    self->x_speed = 0;
    self->y_speed = 0;
    self->x_accel = 0;
    self->gravity = 0;
    self->hp = 0;
    self->contact_damage = 0;
    self->action = 0;
    self->state++;
}

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

void func_800F14D4(void*, s32);
extern s16 D_800F6AD8[];
extern s16 D_800F6B18[];
extern void* D_800F6C08;

#define OWNER ((struct X4_MainObj*)D_800F6C08)

void func_800F2968(struct X4_MainObj* self) {
    struct X4_MainObj* p;
    u8 bg;

    p = D_800F6C08;
    self->animation_table = p->animation_table;
    self->unk42 &= 0x7FFF;
    bg = p->bg_offset;
    self->unk16 = 3;
    self->air_state = 0;
    self->on_screen = 0;
    self->terrain_box = 0;
    self->attack_box = 0;
    self->hurt_box = 0;
    self->collision_data = &D_800755FC;
    self->bg_offset = bg;
    func_800F14D4(self, 0x19);
    self->unk15 = OWNER->unk15;
    if (self->unk2 == 8) {
        if (self->unk15 == 0) {
            self->x_pos.i.hi =
                OWNER->x_pos.i.hi +
                D_800F6AD8[OWNER->animation_step.fields.frame_index * 2];
        } else {
            self->x_pos.i.hi =
                OWNER->x_pos.i.hi -
                D_800F6AD8[OWNER->animation_step.fields.frame_index * 2];
        }
        self->y_pos.i.hi =
            OWNER->y_pos.i.hi +
            D_800F6AD8[OWNER->animation_step.fields.frame_index * 2 + 1];
    } else {
        if (self->unk15 == 0) {
            self->x_pos.i.hi =
                OWNER->x_pos.i.hi +
                D_800F6B18[OWNER->animation_step.fields.frame_index * 2];
        } else {
            self->x_pos.i.hi =
                OWNER->x_pos.i.hi -
                D_800F6B18[OWNER->animation_step.fields.frame_index * 2];
        }
        self->y_pos.i.hi =
            OWNER->y_pos.i.hi +
            D_800F6B18[OWNER->animation_step.fields.frame_index * 2 + 1];
    }
    self->y_speed = 0x80000;
    self->x_speed = 0;
    self->x_accel = 0;
    self->gravity = 0;
    self->hp = 4;
    self->contact_damage = 4;
    self->action = 0;
    self->state++;
}

#undef OWNER

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK animate_object();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK apply_object_motion(void*);
s32 func_80030ECC(void*);
s32 check_enemy_hits(void*);
void func_800F14D4(void*, s32);
extern s32 D_800F6AD0;
extern s32 D_800F6AD4;
extern s16 D_800F6BEA;
extern s16 D_800F6BF0;
extern s32 D_800F6BF8;
extern s32 D_800F6BFC;

void func_800F2B1C(void* arg0) {
    if (D_800F6BF8 != 0 || D_800F6BFC != 0) {
        M2C_FIELD(arg0, u8*, 4)++;
        return;
    }
    if (check_enemy_hits(arg0) < 0 ||
        D_800F6BEA + 0x40 < M2C_FIELD(arg0, s16*, 0xE) ||
        func_80030ECC(arg0) != 0) {
        M2C_FIELD(arg0, u8*, 4)++;
        return;
    }
    switch (M2C_FIELD(arg0, s8*, 5)) {
    case 0:
        if (M2C_FIELD(arg0, s16*, 0xE) < D_800F6BF0 - 0x28) {
            M2C_FIELD(arg0, s32*, 0x24) = 0;
            M2C_FIELD(arg0, s32*, 0x8C) = 0;
            M2C_FIELD(arg0, u8*, 5)++;
        }
        break;
    case 1:
        if (++M2C_FIELD(arg0, s32*, 0x8C) == 0x32) {
            func_800F14D4(arg0, 0x1B);
            play_sound(2, 0x3B, arg0);
            M2C_FIELD(arg0, void**, 0x50) = &D_800F6AD0;
            M2C_FIELD(arg0, void**, 0x54) = &D_800F6AD4;
            if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
                M2C_FIELD(arg0, s32*, 0x20) = -0x20000;
            } else {
                M2C_FIELD(arg0, s32*, 0x20) = 0x20000;
            }
            M2C_FIELD(arg0, s32*, 0x24) = -0x20000;
            M2C_FIELD(arg0, u8*, 5)++;
        }
        break;
    case 2:
        break;
    }
    func_8002CCB0(arg0, 0x20, 0x20);
    animate_object(arg0);
    apply_object_motion(arg0);
}

#include "common.h"
#include "mmx6/x4.h"

void func_800F14D4(void*, s32);
extern s16 D_800F6AD8[];
extern s16 D_800F6B18[];
extern void* D_800F6C08;

#define OWNER ((struct X4_MainObj*)D_800F6C08)

void func_800F2C7C(struct X4_MainObj* self) {
    struct X4_MainObj* p;
    const u8* const* tbl;
    u8 bg;

    p = D_800F6C08;
    tbl = p->animation_table;
    self->unk42 &= 0x7FFF;
    self->animation_table = tbl;
    bg = p->bg_offset;
    self->unk16 = 2;
    self->air_state = 0;
    self->on_screen = 0;
    self->terrain_box = 0;
    self->attack_box = 0;
    self->hurt_box = 0;
    self->collision_data = 0;
    self->bg_offset = bg;
    func_800F14D4(self, 0x1A);
    self->unk15 = OWNER->unk15;
    if (self->unk2 == 10) {
        if (self->unk15 == 0) {
            self->x_pos.i.hi =
                OWNER->x_pos.i.hi +
                D_800F6AD8[OWNER->animation_step.fields.frame_index * 2];
        } else {
            self->x_pos.i.hi =
                OWNER->x_pos.i.hi -
                D_800F6AD8[OWNER->animation_step.fields.frame_index * 2];
        }
        self->y_pos.i.hi =
            OWNER->y_pos.i.hi +
            D_800F6AD8[OWNER->animation_step.fields.frame_index * 2 + 1];
    } else {
        if (self->unk15 == 0) {
            self->x_pos.i.hi =
                OWNER->x_pos.i.hi +
                D_800F6B18[OWNER->animation_step.fields.frame_index * 2];
        } else {
            self->x_pos.i.hi =
                OWNER->x_pos.i.hi -
                D_800F6B18[OWNER->animation_step.fields.frame_index * 2];
        }
        self->y_pos.i.hi =
            OWNER->y_pos.i.hi +
            D_800F6B18[OWNER->animation_step.fields.frame_index * 2 + 1];
    }
    self->x_speed = 0;
    self->y_speed = 0;
    self->x_accel = 0;
    self->gravity = 0;
    self->hp = 0;
    self->contact_damage = 0;
    self->action = 0;
    self->state++;
}

#undef OWNER

#define func_800EB5A0 func_800F2E20
#define D_800F6A84 D_800F69A4
#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002F288(void*);
extern void (*D_800F69A4[])(void*);

void func_800F2E20(void* arg0) {
    M2C_FIELD(arg0, s32*, 0x18) = M2C_FIELD(arg0, s32*, 0x8);
    M2C_FIELD(arg0, u8*, 0x3) = 0;
    M2C_FIELD(arg0, s32*, 0x1C) = M2C_FIELD(arg0, s32*, 0xC);
    D_800F69A4[M2C_FIELD(arg0, s8*, 0x4)](arg0);
    func_8002F288(arg0);
}
#undef func_800EB5A0
#undef D_800F6A84

#include "common.h"

void func_800F2E80(void) {
}

#define func_8003744C func_800F2E88
#define D_80073C1C D_800F69D8
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#include "mmx6/globals.h"

#define NULL ((void*)0)
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* alloc_class3_slot();               /* extern */
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK); /* extern */

void func_800F2EC4(void* arg0) {
    void* temp_v0;

    if (D_800970A5 == 0x14) {
        D_8009723F = 2;
        func_8003D308(0x1D, 0x40);
        M2C_FIELD(arg0, s16*, 0x7C) = 0x28;
        temp_v0 = alloc_class3_slot();
        if (temp_v0 != NULL) {
            M2C_FIELD(temp_v0, s8*, 0) = 1;
            M2C_FIELD(temp_v0, s8*, 1) = 0x18;
            M2C_FIELD(temp_v0, u16*, 0xA) = (u16)M2C_FIELD(arg0, u16*, 0xA);
            M2C_FIELD(temp_v0, u16*, 0xE) = (u16)M2C_FIELD(arg0, u16*, 0xE);
            M2C_FIELD(arg0, void**, 0x80) = temp_v0;
        }
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
void func_800F0434(s8* self, u32 arg1);
extern s16 D_800970AA;

void func_800F2F5C(void* arg0) {
    if (D_800CCEDF == 0) {
        if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
            func_8003D308(0x14, 0x40);
        }
        if (*M2C_FIELD(arg0, s8**, 0x80) == 0) {
            M2C_FIELD(arg0, s32*, 0x24) = 0xFFFF0000;
            if (D_800970AA > M2C_FIELD(arg0, s16*, 0xA)) {
                M2C_FIELD(arg0, u8*, 0x15) = 0x40;
            } else {
                M2C_FIELD(arg0, u8*, 0x15) = 0;
            }
            func_800F0434(arg0, 0x1F);
            animate_object(arg0);
            {
                // !FAKE: depin: dropping it breaks the match (43/46)
                register s32 t asm("$2") = M2C_FIELD(arg0, u8*, 6) + 1;
                M2C_FIELD(arg0, u16*, 0x7C) = 0;
                M2C_FIELD(arg0, u8*, 6) = t;
            }
        }
    }
}

#include "../shared/rock_09/func_800F3014.c"

#include "../shared/rock_09/func_800F30F8.c"

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK start_pad_vibration(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK animate_object();
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK apply_object_motion(void*);
M2C_UNK func_80040488(M2C_UNK);
void func_800F0434(s8* self, u32 arg1);

void func_800F315C(void* arg0) {
    if (++M2C_FIELD(arg0, s16*, 0x7C) == 0xD) {
        play_sound(2, 0x39, arg0);
        func_80029478(0x3C, 2, 2);
        start_pad_vibration(5);
    }
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        func_800F0434(arg0, 0xA);
        func_80040488(0);
        D_800CCEF4 = 1;
        M2C_FIELD(arg0, s16*, 0x7C) = 0x3C;
        M2C_FIELD(arg0, u8*, 6) += 1;
    }
    animate_object(arg0);
    apply_object_motion(arg0);
    func_8002CCB0(arg0, 0x80, 0x80);
}

#include "../shared/rock_09/func_800F3220.c"

#include "../shared/rock_09/func_800F32B0.c"

#include "../shared/rock_09/func_800F3380.c"

#include "common.h"

void func_800F33E4(void) {
}

#define func_800F3380 func_800F33EC
#define D_800F69F8 D_800F69FC
#include "../shared/rock_09/func_800F3380.c"
#undef func_800F3380
#undef D_800F69F8

#include "../shared/rock_09/func_800F3450.c"

#include "common.h"
#include "mmx6/globals.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
s32 random_byte();
void func_800F0434(s8* self, u32 arg1);
extern u8 D_800E98C4[];

void func_800F3498(void* arg0) {
    u8 tbl[4];

    __builtin_memcpy(tbl, D_800E98C4, 4);
    if (++M2C_FIELD(arg0, s16*, 0x7C) == 8) {
        s16 n = M2C_FIELD(arg0, s16*, 0x7E);
        if (n == tbl[D_800CCF5F]) {
            func_800F0434(arg0, 0xA);
            M2C_FIELD(arg0, s16*, 0x7C) = 0;
            M2C_FIELD(arg0, u8*, 6) += 1;
            return;
        }
        if (n == 0) {
            play_sound(2, 0x22, arg0);
            func_800F0434(arg0, 0x13);
        }
        M2C_FIELD(arg0, u8*, 7) = random_byte() & 1;
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, s16*, 0x7E) += 1;
    }
}

#include "../shared/rock_09/func_800F3578.c"

#define func_800F3380 func_800F35DC
#define D_800F69F8 D_800F6A0C
#include "../shared/rock_09/func_800F3380.c"
#undef func_800F3380
#undef D_800F69F8

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
void func_800F0434(s8* self, u32 arg1);
extern s16 D_800970AA;

void func_800F3640(void* arg0) {
    s32 t = D_800970AA;

    if (M2C_FIELD(arg0, s16*, 0xA) < t) {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    } else {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
    }
    play_sound(2, 0x23, arg0);
    func_800F0434(arg0, 0xD);
    M2C_FIELD(arg0, s8*, 6) = 1;
}

#include "../shared/rock_09/func_800F36AC.c"

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
void func_800F0434(s8* self, u32 arg1);
extern s16 D_800970AA;

#define F(T, p, o) (*(T*)((u8*)(p) + (o)))

void func_800F371C(void* arg0) {
    if (D_800970AA > F(s16, arg0, 0xA)) {
        F(u8, arg0, 0x15) = 0x40;
    } else {
        F(u8, arg0, 0x15) = 0;
    }
    if (F(s8, arg0, 0x46) == 0) {
        play_sound(2, 0x3E, arg0);
        func_800F0434(arg0, 0x1E);
        F(u16, arg0, 0x7C) = 0;
    }
    if (++F(s16, arg0, 0x7C) == 0x3C) {
        F(s16, arg0, 0x7E) = 0;
        if (D_800CCF38 == 2) {
            F(s8, arg0, 6) = 0xC;
        } else {
            F(s8, arg0, 6) = 3;
        }
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK start_pad_vibration(M2C_UNK);             /* extern */
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);      /* extern */
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK); /* extern */

void func_800F37CC(void* arg0) {
    s32 temp_v0;
    s32 var_v0;

    temp_v0 = M2C_FIELD(arg0, s32*, 0x20);
    if (temp_v0 > 0) {
        var_v0 = M2C_FIELD(arg0, u8*, 0x70) & 1;
        if (var_v0 != 0) {
            play_sound(2, 0x3F, arg0);
            start_pad_vibration(3);
            M2C_FIELD(arg0, s32*, 0x20) = 0;
        }
    } else if (temp_v0 < 0) {
        var_v0 = M2C_FIELD(arg0, u8*, 0x70) & 2;
        if (var_v0 != 0) {
            play_sound(2, 0x3F, arg0);
            start_pad_vibration(3);
            M2C_FIELD(arg0, s32*, 0x20) = 0;
        }
    }
    if (M2C_FIELD(arg0, s32*, 0x20) == 0) {
        func_80029478(0x5A, 2, 3);
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, s8*, 6) = 5;
        M2C_FIELD(arg0, u16*, 0x7E) = (u16)(M2C_FIELD(arg0, u16*, 0x7E) + 1);
    }
}

#include "../shared/rock_09/func_800F3870.c"

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK start_pad_vibration(M2C_UNK);             /* extern */
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);      /* extern */
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK); /* extern */

void func_800F389C(void* arg0) {
    if (M2C_FIELD(arg0, u8*, 0x70) & 4) {
        play_sound(2, 0x3F, arg0);
        start_pad_vibration(3);
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        func_80029478(0x5A, 2, 3);
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, s8*, 6) = 7;
        M2C_FIELD(arg0, u16*, 0x7E) = (u16)(M2C_FIELD(arg0, u16*, 0x7E) + 1);
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK start_pad_vibration(M2C_UNK);             /* extern */
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);      /* extern */
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK); /* extern */

void func_800F3910(void* arg0) {
    if (M2C_FIELD(arg0, u8*, 0x70) & 8) {
        play_sound(2, 0x3F, arg0);
        start_pad_vibration(3);
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
        func_80029478(0x5A, 2, 3);
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, s8*, 6) = 5;
        M2C_FIELD(arg0, u16*, 0x7E) = (u16)(M2C_FIELD(arg0, u16*, 0x7E) + 1);
    }
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
void func_800F0434(s8* self, u32 arg1);
extern s16 D_800970AA;

void func_800F398C(s8* arg0) {
    if (*(u8*)(arg0 + 0x47) == 0) {
        s32 g = D_800970AA;

        if (*(s16*)(arg0 + 0xA) < g) {
            arg0[0x15] = 0x40;
        } else {
            arg0[0x15] = 0;
        }
        play_sound(2, 0x14, arg0);
        play_sound(2, 0x40, arg0);
        func_800F0434(arg0, 0x1D);
        arg0[6] = 0xA;
    }
}

#include "common.h"

void func_800F0434(s8* self, u32 arg1);

#define F(T, p, o) (*(T*)((u8*)(p) + (o)))

void func_800F3A14(void* arg0) {
    if (F(s8, arg0, 0x46) == 0) {
        func_800F0434(arg0, 0x10);
        F(s16, arg0, 0x7C) = 0;
        F(u8, arg0, 6) = 0xB;
    }
}

#include "../shared/rock_09/func_800F3A58.c"

#include "../shared/rock_09/func_800F3AE8.c"

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK start_pad_vibration(M2C_UNK);             /* extern */
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);      /* extern */
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK); /* extern */

void func_800F3B50(void* arg0) {
    if (M2C_FIELD(arg0, u8*, 0x70) & 8) {
        play_sound(2, 0x3F, arg0);
        start_pad_vibration(3);
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
        func_80029478(0x5A, 2, 3);
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, s8*, 6) = 0xE;
    }
}

#include "../shared/rock_09/func_800F3BC0.c"

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK start_pad_vibration(M2C_UNK);        /* extern */
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */

void func_800F3C44(void* arg0) {
    u8 temp_v1;

    temp_v1 = M2C_FIELD(arg0, u8*, 0x70);
    if ((temp_v1 & 2) || (temp_v1 & 1)) {
        play_sound(2, 0x3F, arg0);
        start_pad_vibration(3);
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s8*, 6) = 0xC;
        M2C_FIELD(arg0, u16*, 0x7E) = (u16)(M2C_FIELD(arg0, u16*, 0x7E) + 1);
    }
}

#define func_800F3380 func_800F3CB0
#define D_800F69F8 D_800F6A4C
#include "../shared/rock_09/func_800F3380.c"
#undef func_800F3380
#undef D_800F69F8

#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
void func_800F0434(s8* self, u32 arg1);
extern s16 D_800970AA;

#define F(T, p, o) (*(T*)((u8*)(p) + (o)))

void func_800F3D14(void* arg0) {
    if (D_800970AA > F(s16, arg0, 0xA)) {
        F(u8, arg0, 0x15) = 0x40;
    } else {
        F(u8, arg0, 0x15) = 0;
    }
    play_sound(2, 0x24, arg0);
    func_800F0434(arg0, 0xD);
    F(u8, arg0, 6) = 1;
}

#define func_800F36AC func_800F3D80
#include "../shared/rock_09/func_800F36AC.c"
#undef func_800F36AC

#include "../shared/rock_09/func_800F3DF0.c"

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s16 D_800F6BE8;

void func_800F3E8C(void* arg0) {
    if (M2C_FIELD(arg0, s16*, 0x7E) >= 4) {
        M2C_FIELD(arg0, s8*, 6) = 6;
        return;
    }
    if (M2C_FIELD(arg0, s16*, 0xA) < D_800F6BE8) {
        M2C_FIELD(arg0, s8*, 0x15) = 0x40;
    } else {
        M2C_FIELD(arg0, s8*, 0x15) = 0;
    }
    M2C_FIELD(arg0, s8*, 6) = 4;
}

#include "../shared/rock_09/func_800F3EE0.c"

#include "../shared/rock_09/func_800F3F5C.c"

#include "../shared/rock_09/func_800F3FE4.c"

#define func_800F3A58 func_800F4028
#define D_800F6924 D_800F6924
#include "../shared/rock_09/func_800F3A58.c"
#undef func_800F3A58
#undef D_800F6924

#define func_800F3380 func_800F40B8
#define D_800F69F8 D_800F6A70
#include "../shared/rock_09/func_800F3380.c"
#undef func_800F3380
#undef D_800F69F8

#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
void func_800F0434(s8* self, u32 arg1);
extern s16 D_800970AA;

#define F(T, p, o) (*(T*)((u8*)(p) + (o)))

void func_800F411C(void* arg0) {
    if (D_800970AA > F(s16, arg0, 0xA)) {
        F(u8, arg0, 0x15) = 0x40;
    } else {
        F(u8, arg0, 0x15) = 0;
    }
    play_sound(2, 0x25, arg0);
    func_800F0434(arg0, 0xD);
    F(u8, arg0, 6) = 1;
}

#define func_800F36AC func_800F4188
#include "../shared/rock_09/func_800F36AC.c"
#undef func_800F36AC

#define func_800F3DF0 func_800F41F8
#include "../shared/rock_09/func_800F3DF0.c"
#undef func_800F3DF0

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s16 D_800F6BE8;

void func_800F4294(void* arg0) {
    if (M2C_FIELD(arg0, s16*, 0x7E) >= 4) {
        M2C_FIELD(arg0, s8*, 6) = 6;
        return;
    }
    if (M2C_FIELD(arg0, s16*, 0xA) < D_800F6BE8) {
        M2C_FIELD(arg0, s8*, 0x15) = 0x40;
    } else {
        M2C_FIELD(arg0, s8*, 0x15) = 0;
    }
    M2C_FIELD(arg0, s8*, 6) = 4;
}

#define func_800F3EE0 func_800F42E8
#define D_800F698C D_800F698C
#include "../shared/rock_09/func_800F3EE0.c"
#undef func_800F3EE0
#undef D_800F698C

#define func_800F3F5C func_800F4364
#include "../shared/rock_09/func_800F3F5C.c"
#undef func_800F3F5C

#define func_800F3FE4 func_800F43EC
#include "../shared/rock_09/func_800F3FE4.c"
#undef func_800F3FE4

#define func_800F3A58 func_800F4430
#define D_800F6924 D_800F6924
#include "../shared/rock_09/func_800F3A58.c"
#undef func_800F3A58
#undef D_800F6924

#define func_800F3380 func_800F44C0
#define D_800F69F8 D_800F6A94
#include "../shared/rock_09/func_800F3380.c"
#undef func_800F3380
#undef D_800F69F8

// clang-format off
INCLUDE_ASM("asm/rock_09/nonmatchings/E9860", func_800F4524);
// clang-format on

#include "../shared/rock_09/func_800F45C0.c"

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F45F8(void* arg0) {
    if (M2C_FIELD(arg0, u8*, 0x70) & 8) {
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#include "../shared/rock_09/func_800F462C.c"

#include "../shared/rock_09/func_800F468C.c"

#define func_80041AB8 func_800F46F0
#define D_80075FD8 D_800F6AA8
#define FAMILY_FIELD 5
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
void func_800F0434(s8* self, u32 arg1);

void func_800F472C(s8* self) {
    M2C_FIELD(self, s16*, 0x7C) = 0x7F;
    M2C_FIELD(self, s16*, 0x7E) = 0x19;
    M2C_FIELD(self, s8*, 0x61) = 0x19;
    M2C_FIELD(self, u16*, 0x42) &= 0x7FFF;
    func_800F0434(self, 0x20);
    M2C_FIELD(self, u8*, 5)++;
    func_8003D308(0x14, D_800970B5);
    func_8002CCB0(self, 0x80, 0x80);
}

#include "../shared/rock_09/func_800F47A0.c"

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

void func_800F14D4(void*, s32);
extern s32 D_800F6AB4;
extern s32 D_800F6AB8;
extern void* D_800F6C08;

void func_800F48A0(struct X4_MainObj* self) {
    struct X4_MainObj* p;
    u8 bg;

    p = D_800F6C08;
    self->animation_table = p->animation_table;
    self->unk42 &= 0x7FFF;
    bg = p->bg_offset;
    self->unk16 = 4;
    self->air_state = 0;
    self->on_screen = 0;
    self->terrain_box = 0;
    self->attack_box = 0;
    self->bg_offset = bg;
    if (self->unk2 == 0) {
        self->hurt_box = &D_800F6AB4;
    } else {
        self->hurt_box = &D_800F6AB8;
    }
    self->collision_data = &D_800755FC;
    if (self->unk2 == 0) {
        func_800F14D4(self, 0xB);
    } else {
        func_800F14D4(self, 0xC);
    }
    self->x_speed = 0;
    self->y_speed = 0;
    self->x_accel = 0;
    self->gravity = 0;
    self->hp = 0x10;
    self->contact_damage = 0;
    *(s32*)((u8*)self + 0x8C) = 0;
    *(s32*)((u8*)self + 0x90) = 0;
    self->action = 0;
    self->action_phase = 0;
    self->state++;
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800F4988(void) {
    clear_object_slot();
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800F49A8(void) {
    clear_object_slot();
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK animate_object();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK apply_object_motion(void*);
s32 func_80030ECC(void*);
s32 check_enemy_hits(void*);
extern s16 D_800F6BEA;
extern s32 D_800F6BF8;
extern s32 D_800F6BFC;
void func_800F49C8(struct X4_MainObj* arg0) {
    struct X4_MainObj* self;

    if (D_800F6BF8 != 0 || D_800F6BFC != 0) {
        self = arg0;
        // !FAKE: goto keeps self loaded per arm before the shared inc; one || chain moved bytes
        goto inc;
    }
    self = arg0;
    if (check_enemy_hits(self) < 0 || D_800F6BEA + 0x40 < self->y_pos.i.hi ||
        func_80030ECC(self) != 0) {
    inc:
        self->state++;
        return;
    }
    func_8002CCB0(self, 0x20, 0x20);
    animate_object(self);
    apply_object_motion(self);
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800F4A70(void) {
    clear_object_slot();
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object(void*);                  /* extern */
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK apply_object_motion(void*);             /* extern */
extern s32 D_800F6BF8;
extern s32 D_800F6BFC;

void func_800F4A90(void* arg0) {
    if ((D_800F6BF8 != 0) || (D_800F6BFC != 0) ||
        (M2C_FIELD(arg0, s8*, 0x46) == 0)) {
        M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
        return;
    }
    func_8002CCB0(arg0, 0x20, 0x20);
    animate_object(arg0);
    apply_object_motion(arg0);
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800F4B10(void) {
    clear_object_slot();
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800F4B30(void) {
    clear_object_slot();
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object(void*);                  /* extern */
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK apply_object_motion(void*);             /* extern */
extern s32 D_800F6BF8;
extern s32 D_800F6BFC;

void func_800F4B50(void* arg0) {
    if ((D_800F6BF8 != 0) || (D_800F6BFC != 0) ||
        (M2C_FIELD(arg0, s8*, 0x46) == 0)) {
        M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
        return;
    }
    func_8002CCB0(arg0, 0x20, 0x20);
    animate_object(arg0);
    apply_object_motion(arg0);
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800F4BD0(void) {
    clear_object_slot();
}

// clang-format off
INCLUDE_ASM("asm/rock_09/nonmatchings/E9860", D_800F4BF0);
// clang-format on
