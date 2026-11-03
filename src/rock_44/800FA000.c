// clang-format off
INCLUDE_ASM("asm/rock_44/nonmatchings/FA000", D_800FA000);

INCLUDE_ASM("asm/rock_44/nonmatchings/FA000", func_800FA04C);

INCLUDE_ASM("asm/rock_44/nonmatchings/FA000", func_800FA2A8);
// clang-format on

#define func_800F1F50 func_800FA878
#include "../shared/rock_02/func_800F1F50.c"
#undef func_800F1F50

// clang-format off
INCLUDE_ASM("asm/rock_44/nonmatchings/FA000", func_800FA984);
// clang-format on

#define func_800F21B0 func_800FAAD8
#define g_Player g_Player
#include "../shared/rock_02/func_800F21B0.c"
#undef func_800F21B0
#undef g_Player

#define func_800F22E8 func_800FAC10
#define background_objects background_objects
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK animate_object();
M2C_UNK open_text_box(M2C_UNK, M2C_UNK, M2C_UNK);
s32 func_8002A47C(s32);
void* func_8002C458();
M2C_UNK move_object(void*);
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj g_playthrough_state;

void func_800FAC10(void* arg0) {
    void* p;
    s8 k;

    move_object((s32)arg0);
    ((void (*)(void*))animate_object)(arg0);
    if (M2C_FIELD(arg0, s16*, 0xE) > background_objects[0].unk2A + 0x60) {
        p = func_8002C458();
        if (p != 0) {
            M2C_FIELD(p, u8*, 0) = 0x41;
            M2C_FIELD(p, u8*, 1) = 0x15;
            M2C_FIELD(p, u8*, 2) = 3;
            M2C_FIELD(p, s32*, 8) = M2C_FIELD(arg0, s32*, 8);
            M2C_FIELD(p, s16*, 0xE) = background_objects[0].unk22 + 0xC0;
            M2C_FIELD(p, s16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
            M2C_FIELD(p, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
            M2C_FIELD(p, s32*, 0x3C) =
                SPAD20 + *(s32*)(func_8002A47C(M2C_FIELD(arg0, s8*, 1)) * 4 +
                                 SPAD20 + 4);
            M2C_FIELD(p, s16*, 0x40) = M2C_FIELD(arg0, s16*, 0x40);
            M2C_FIELD(p, void**, 0x7C) = arg0;
        }
        k = M2C_FIELD(arg0, s8*, 2);
        if (k == 0) {
            open_text_box(4, 0xFF, 0);
        } else {
            if (k == 1) {
                u8* e = (u8*)&g_playthrough_state;
                open_text_box(1, 0xFF, e[0x2E]);
                e[0x2E] = 1;
            } else {
                u8* e = (u8*)&g_playthrough_state;
                open_text_box(0, 0xFF, e[0x2E]);
                e[0x2E] = 1;
            }
        }
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    }
}
#undef func_800F22E8
#undef background_objects

#define func_800F2438 func_800FAD60
#include "../shared/rock_02/func_800F2438.c"
#undef func_800F2438

// clang-format off
INCLUDE_ASM("asm/rock_44/nonmatchings/FA000", func_800FAEAC);

INCLUDE_ASM("asm/rock_44/nonmatchings/FA000", func_800FB18C);
// clang-format on

#define func_800F2984 func_800FB2AC
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD4C (*(u8**)0x1F80004C)

M2C_UNK animate_object();
M2C_UNK move_object(void*);
extern struct X4_BackgroundObj background_objects[3];

void func_800FB2AC(void* arg0) {
    u8* sp;
    u8 t;

    sp = SPAD4C;
    t = sp[0x8B];
    if (t != 0) {
        sp[0x8B] = t - 1;
        if (!(SPAD4C[0x8B] & 3)) {
            M2C_FIELD(arg0, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) | 0x8000;
        } else {
            M2C_FIELD(arg0, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
        }
        sp = SPAD4C;
        if (sp[0x8B] == 0) {
            sp[0x8B] = 0x78;
        }
    }
    ((void (*)(void*))animate_object)(arg0);
    if (M2C_FIELD(arg0, s8*, 0x45) != 0) {
        M2C_FIELD(arg0, s32*, 0x68) = 0;
        ((void (*)(void*))move_object)(arg0);
        if (background_objects[0].unk22 - 0x40 >= M2C_FIELD(arg0, s16*, 0xE)) {
            M2C_FIELD(arg0, s16*, 0xE) = background_objects[0].unk22 - 0x40;
            if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
                M2C_FIELD(arg0, s16*, 0xA) =
                    background_objects[0].unk1C + 0x100;
                M2C_FIELD(arg0, u8*, 0x15) = 0;
            } else {
                M2C_FIELD(arg0, s16*, 0xA) = background_objects[0].unk1E + 0x40;
                M2C_FIELD(arg0, u8*, 0x15) = 0x40;
            }
            M2C_FIELD(arg0, s16*, 0x7C) = 0x32;
            M2C_FIELD(arg0, s32*, 0x20) = 0;
            M2C_FIELD(arg0, s32*, 0x24) = 0;
            M2C_FIELD(arg0, s32*, 0x2C) = 0;
            M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
            SPAD4C[0x8B] = 0x78;
        }
    }
}
#undef func_800F2984

// clang-format off
INCLUDE_ASM("asm/rock_44/nonmatchings/FA000", func_800FB3F0);
// clang-format on

#define func_800F2BE4 func_800FB50C
#define g_Player g_Player
#include "../shared/rock_02/func_800F2BE4.c"
#undef func_800F2BE4
#undef g_Player

// clang-format off
INCLUDE_ASM("asm/rock_44/nonmatchings/FA000", func_800FB630);

INCLUDE_ASM("asm/rock_44/nonmatchings/FA000", func_800FB7E4);
// clang-format on

#define func_800F303C func_800FB964
#include "../shared/rock_02/func_800F303C.c"
#undef func_800F303C

#define func_800F3164 func_800FBA8C
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define SPAD4C (*(s8**)0x1F80004C)

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK move_object(void*);
extern struct X4_BackgroundObj background_objects[3];

void func_800FBA8C(void* arg0) {
    struct X4_MainObj* self = arg0;
    s8* p = SPAD4C;

    if (p[0x89] == 0) {
        p[0x89] = 0x78;
    }
    ((void (*)(void*))move_object)(arg0);
    if (self->x_speed < 0) {
        if (background_objects[0].unk1E + 0x70 >= self->x_pos.i.hi &&
            self->unk15 == 0) {
            self->unk15 = 0x40;
        }
        if (background_objects[0].unk1E + 0x40 >= self->x_pos.i.hi) {
            self->x_pos.i.hi = background_objects[0].unk1E + 0x40;
            self->unk15 = 0x40;
            ((void (*)(s32, s32, void*))play_sound)(2, 0x23, self);
            ((void (*)(void*, s32))set_animation)(self, 0x12);
            self->action_phase++;
        }
    } else {
        if (self->x_pos.i.hi >= background_objects[0].unk1C + 0xD0 &&
            self->unk15 != 0) {
            self->unk15 = 0;
        }
        if (self->x_pos.i.hi >= background_objects[0].unk1C + 0x100) {
            self->x_pos.i.hi = background_objects[0].unk1C + 0x100;
            self->unk15 = 0;
            ((void (*)(s32, s32, void*))play_sound)(2, 0x23, self);
            ((void (*)(void*, s32))set_animation)(self, 0x12);
            self->action_phase++;
        }
    }
}
#undef func_800F3164

#define func_800F32B8 func_800FBBE0
#include "../shared/rock_02/func_800F32B8.c"
#undef func_800F32B8

#define func_800F33C0 func_800FBCE8
#define background_objects background_objects
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK move_object(void*);
extern struct X4_BackgroundObj background_objects[3];

void func_800FBCE8(void* arg0) {
    // !FAKE: inherited from src/shared/rock_02/func_800F33C0.c
    register s32 x asm("$5");
    // !FAKE: inherited from src/shared/rock_02/func_800F33C0.c
    register s32 l asm("$4");

    ((void (*)(void*))move_object)(arg0);
    if (M2C_FIELD(arg0, s32*, 0x20) < 0) {
        x = background_objects[0].unk1E;
        l = x - 0x140;
        if (M2C_FIELD(arg0, s16*, 0xA) >=
            x + (background_objects[0].unk1C - l) / 2) {
            return;
        }
    } else {
        x = background_objects[0].unk1E;
        l = x - 0x140;
        if (x + (background_objects[0].unk1C - l) / 2 >=
            M2C_FIELD(arg0, s16*, 0xA)) {
            return;
        }
    }
    play_sound(2, 0x23, arg0);
    set_animation(arg0, 7);
    M2C_FIELD(arg0, s16*, 0x7C) = 0;
    {
        // !FAKE: inherited from src/shared/rock_02/func_800F33C0.c
        register s32 t asm("$2") = M2C_FIELD(arg0, u8*, 6) + 1;
        M2C_FIELD(arg0, u8*, 6) = t;
    }
}
#undef func_800F33C0
#undef background_objects

// clang-format off
INCLUDE_ASM("asm/rock_44/nonmatchings/FA000", func_800FBDB4);

INCLUDE_ASM("asm/rock_44/nonmatchings/FA000", func_800FBF2C);
// clang-format on

#define func_800F370C func_800FC034
#include "../shared/rock_02/func_800F370C.c"
#undef func_800F370C

// clang-format off
INCLUDE_ASM("asm/rock_44/nonmatchings/FA000", func_800FC21C);

INCLUDE_ASM("asm/rock_44/nonmatchings/FA000", func_800FC808);
// clang-format on

#define func_800F4194 func_800FCABC
#include "../shared/rock_02/func_800F4194.c"
#undef func_800F4194

#define func_800F4480 func_800FCDA8
#include "../shared/rock_02/func_800F4480.c"
#undef func_800F4480

#define func_800F4620 func_800FCF48
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK animate_object();
extern struct X4_BackgroundObj background_objects[3];
extern u16 D_8009721A;

M2C_UNK move_object(void*);
void func_800FCF48(void* arg0) {
    void* parent;
    u8 t;

    parent = M2C_FIELD(arg0, void**, 0x7C);
    ((M2C_UNK(*)())animate_object)();
    ((M2C_UNK(*)())move_object)(arg0);
    t = M2C_FIELD(arg0, u8*, 0x8D);
    if (t == 0) {
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        if (M2C_FIELD(parent, s8*, 5) == 0xF) {
            M2C_FIELD(arg0, s32*, 0x54) = 0;
            M2C_FIELD(arg0, s32*, 0x50) = 0;
            M2C_FIELD(arg0, u8*, 0x8D) = 0x3C;
            M2C_FIELD(arg0, s16*, 0xE) = D_8009721A + 0x68;
            M2C_FIELD(arg0, u8*, 6) += 1;
            return;
        }
        if (M2C_FIELD(parent, s8*, 5) == 0x10) {
            if (M2C_FIELD(arg0, s8*, 2) == 9) {
                if (M2C_FIELD(parent, u8*, 0x15) != 0) {
                    {
                        s16 v = background_objects[0].unk1E - 0x16;
                        M2C_FIELD(arg0, s32*, 0x20) = 0x30000;
                        M2C_FIELD(arg0, s16*, 0xA) = v;
                    }
                } else {
                    // !FAKE: inherited from src/shared/rock_02/func_800F4620.c
                    goto right;
                }
            } else if (M2C_FIELD(parent, u8*, 0x15) == 0) {
                {
                    s16 v = background_objects[0].unk1E - 0x16;
                    M2C_FIELD(arg0, s32*, 0x20) = 0x30000;
                    M2C_FIELD(arg0, s16*, 0xA) = v;
                }
            } else {
            right: {
                s16 v = background_objects[0].unk1C + 0x157;
                M2C_FIELD(arg0, s32*, 0x20) = 0xFFFD0000;
                M2C_FIELD(arg0, s16*, 0xA) = v;
            }
            }
            {
                s16 e = background_objects[0].unk22 + 0x68;
                M2C_FIELD(arg0, u8*, 0x8D) = 0x3A;
                M2C_FIELD(arg0, u8*, 6) = 3;
                M2C_FIELD(arg0, s16*, 0xE) = e;
            }
            return;
        }
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        if (M2C_FIELD(parent, s8*, 6) >= 3) {
            {
                // !FAKE: inherited from src/shared/rock_02/func_800F4620.c
                register s32 vel2 asm("$2");
                // !FAKE: inherited from src/shared/rock_02/func_800F4620.c
                register s32 c asm("$2") = M2C_FIELD(parent, u8*, 0x15);
                if (c != 0) {
                    vel2 = 0x30000;
                } else {
                    vel2 = 0xFFFD0000;
                }
                M2C_FIELD(arg0, s32*, 0x20) = vel2;
            }
            M2C_FIELD(arg0, u8*, 0x8D) = 0;
            M2C_FIELD(arg0, u8*, 6) = 3;
        }
    } else {
        if (--M2C_FIELD(arg0, u8*, 0x8D) == 0 &&
            M2C_FIELD(parent, s8*, 5) == 0x11) {
            play_sound(2, 0x7F, arg0);
        }
    }
}
#undef func_800F4620

// clang-format off
INCLUDE_ASM("asm/rock_44/nonmatchings/FA000", func_800FD0F4);
// clang-format on

#define func_800F48EC func_800FD214
#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK animate_object();
s32 func_8002A47C(s32);
void* func_8002C458();
M2C_UNK move_object(void*);

void func_800FD214(void* arg0) {
    void* parent;
    void* p;
    s32 base;

    parent = M2C_FIELD(arg0, void**, 0x7C);
    ((M2C_UNK(*)())animate_object)();
    move_object((s32)arg0);
    if (M2C_FIELD(parent, s8*, 5) == 0x11) {
        if (M2C_FIELD(arg0, s8*, 2) == 9) {
            p = func_8002C458();
            if (p != 0 && (u8)(M2C_FIELD(arg0, u8*, 0x8D) % 20) == 0) {
                M2C_FIELD(p, s8*, 0) = 0x41;
                M2C_FIELD(p, s8*, 1) = 0x15;
                M2C_FIELD(p, s8*, 2) = 0;
                if (M2C_FIELD(parent, u8*, 0x15) == 0) {
                    M2C_FIELD(p, s16*, 0xA) = M2C_FIELD(arg0, s16*, 0xA) - 0x18;
                } else {
                    M2C_FIELD(p, s16*, 0xA) = M2C_FIELD(arg0, s16*, 0xA) + 0x18;
                }
                M2C_FIELD(p, s32*, 0xC) = M2C_FIELD(arg0, s32*, 0xC);
                M2C_FIELD(p, s16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
                M2C_FIELD(p, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
                base = func_8002A47C(0x37);
                M2C_FIELD(p, s32*, 0x3C) =
                    SPAD20 + *(s32*)(base * 4 + SPAD20 + 4);
                M2C_FIELD(p, s16*, 0x40) = M2C_FIELD(arg0, s16*, 0x40);
                M2C_FIELD(p, void**, 0x7C) = parent;
                play_sound(2, 0x1C, parent);
            }
        }
        if ((u8)++M2C_FIELD(arg0, u8*, 0x8D) >= 0x4D) {
            M2C_FIELD(arg0, u8*, 0x8D) = 0x28;
            play_sound(2, 0x80, arg0);
            M2C_FIELD(arg0, u8*, 6) = 6;
        }
    } else {
        if ((u8)--M2C_FIELD(arg0, u8*, 0x8D) == 0) {
            play_sound(2, 0x7F, arg0);
            M2C_FIELD(arg0, s32*, 0x20) = 0;
            M2C_FIELD(arg0, s32*, 0x24) = 0xFFFD0000;
            M2C_FIELD(arg0, u8*, 6)++;
        }
    }
}
#undef func_800F48EC

// clang-format off
INCLUDE_ASM("asm/rock_44/nonmatchings/FA000", func_800FD3E0);

INCLUDE_ASM("asm/rock_44/nonmatchings/FA000", func_800FD56C);

INCLUDE_ASM("asm/rock_44/nonmatchings/FA000", func_800FD86C);
// clang-format on
