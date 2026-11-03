#define func_80041AB8 func_800F1C9C
#define D_80075FD8 D_800F5F70
#define FAMILY_FIELD 5
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#include "common.h"

#define M2C_UNK s32

#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
void func_8002CCB0(struct X4_BaseObj*, s32, s32);
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern struct X4_PlayerObj g_Player;

void func_800F1CD8(s8* arg0) {
    struct X4_PlayerObj* pl = &g_Player;

    *(u8*)((s32)pl + 0xCA) = 0;
    func_8003D308(0x14, pl->facing);
    arg0[5] = 1;
    *(u16*)(arg0 + 0x42) &= 0x7FFF;
    set_animation(arg0, 5);
    *(s16*)(arg0 + 0x7C) = 0x7F;
    *(s16*)(arg0 + 0x7E) = 0x19;
    arg0[0x61] = 0x19;
    func_8002CCB0(arg0, 0x60, 0x60);
}

#include "../shared/rock_08/func_800F1D54.c"

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern void (*D_800F5F7C[])(s8*);

void func_800F1E48(s8* arg0) {
    if (arg0[7] == 1) {
        arg0[5] = 7;
        arg0[6] = 0;
        arg0[7] = 0;
        return;
    }
    if (M2C_FIELD(arg0, s16*, 0x82) != arg0[0x5C] && arg0[0x84] == 0) {
        arg0[5] = 8;
        arg0[6] = 0;
        arg0[0x84] = 1;
        return;
    }
    D_800F5F7C[arg0[6]](arg0);
}

#include "../shared/rock_08/func_800F1ED8.c"

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"
#include "mmx6/rock_08.h"

M2C_UNK animate_object();
M2C_UNK move_object(void*);

void func_800F1F64(void* arg0) {
    struct X4_MainObj* self = arg0;

    ((void (*)())animate_object)();
    ((void (*)(void*))move_object)(self);
    if (self->x_speed > 0) {
        if (D_800F6AF8 + 0x880 < self->x_pos.i.hi) {
            self->unk15 = 0;
            self->action = 3;
            self->action_phase = 0;
        }
    } else if (self->x_pos.i.hi < D_800F6AF8 + 0x590) {
        self->unk15 = 0x40;
        self->action = 3;
        self->action_phase = 0;
    }
}

#include "common.h"

void func_800F1FEC(void) {
}

#include "common.h"

void func_800F1FF4(void) {
}

#define func_8003744C func_800F1FFC
#define D_80073C1C D_800F5F8C
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#include "mmx6/globals.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F2038(void* arg0) {
    M2C_FIELD(arg0, M2C_UNK**, 0x58) = &D_80074C9C;
    if (M2C_FIELD(arg0, s8*, 0x87) < 0xA) {
        M2C_FIELD(arg0, s8*, 0x87) = (s8)((u8)M2C_FIELD(arg0, s8*, 0x87) + 1);
    }
    M2C_FIELD(arg0, s8*, 0x8B) = 0;
    M2C_FIELD(arg0, s8*, 0x84) = 0;
    M2C_FIELD(arg0, s16*, 0x7C) = (s16)(M2C_FIELD(arg0, s8*, 0x88) * 0xA);
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

// clang-format off
INCLUDE_ASM("asm/rock_08/nonmatchings/E9860", func_800F208C);
// clang-format on

#define func_800F1ED8 func_800F211C
#include "../shared/rock_08/func_800F1ED8.c"
#undef func_800F1ED8

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/rock_08.h"

extern s32 animate_object();
extern s32 move_object(void*);

void func_800F21A8(struct X4_AnimatedObj* arg0) {
    u8 temp_v1;
    // !FAKE: depin: dropping it breaks the match (37/39)
    register s32 t asm("$2");

    animate_object();
    move_object(arg0);
    if ((t = arg0->x_vel.val) > 0) {
        if ((D_800F6AF8 + 0x6C0) >= arg0->x_pos.i.hi) {
            return;
        }
    } else if (arg0->x_pos.i.hi >= (D_800F6AF8 + 0x740)) {
        return;
    }
    temp_v1 = arg0->animation_step.fields.frame_index;
    if (temp_v1 == 4) {
        return;
    }
    if (temp_v1 == 5) {
        return;
    }
    arg0->action_phase++;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();
M2C_UNK move_object(void*);
s32 random_byte();

void func_800F2244(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    s32 r;

    r = random_byte() & 0xF;
    ((void (*)(void*))animate_object)(arg0);
    if (r < 5) {
        ((void (*)(void*, s32))set_animation)(arg0, 0);
        self->action = 5;
        self->action_phase = 0;
        return;
    }
    if (r < 0xA) {
        self->action = 6;
        self->action_phase = 0;
        self->input.buttons.held = 0x5A;
        return;
    }
    ((void (*)(void*))move_object)(arg0);
    self->action = 2;
    self->action_phase = 1;
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern void (*D_800F5FA0[])(void*);

void func_800F22D8(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x7) == 1) {
        M2C_FIELD(arg0, s8*, 0x5) = 7;
        M2C_FIELD(arg0, s8*, 0x6) = 0;
        M2C_FIELD(arg0, s8*, 0x7) = 0;
        return;
    }
    D_800F5FA0[M2C_FIELD(arg0, s8*, 0x6)](arg0);
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();

void func_800F2334(void* arg0) {
    ((void (*)(void*, s32))set_animation)(arg0, 0);
    ((void (*)(void*))animate_object)(arg0);
    M2C_FIELD(arg0, s16*, 0x7C) = 0x28;
    M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
}

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

#define OUB(p, o) (*(u8*)((u8*)(p) + (o)))
#define OH(p, o) (*(u16*)((u8*)(p) + (o)))

s32 set_animation(void*, s32);
M2C_UNK animate_object();

void func_800F2378(void* arg0) {
    // !FAKE: depin: dropping it breaks the match (31/35)
    register s32 t asm("$2");

    animate_object();
    t = OH(arg0, 0x7C) - 1;
    OH(arg0, 0x7C) = t;
    if ((s16)t == 0) {
        if (D_800CCF5F < 2) {
            OUB(arg0, 0x89) = 0;
        } else if (D_800CCF5F == 2) {
            OUB(arg0, 0x89) = 1;
        } else {
            OUB(arg0, 0x89) = 2;
        }
        set_animation(arg0, 2);
        t = OUB(arg0, 6) + 1;
        OUB(arg0, 6) = t;
    }
}

#include "../shared/rock_08/func_800F2404.c"

#include "common.h"
#include "mmx6/rock_08.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define B(p, o) M2C_FIELD(p, u8*, o)
#define SB(p, o) M2C_FIELD(p, s8*, o)
#define H(p, o) M2C_FIELD(p, s16*, o)
#define UH(p, o) M2C_FIELD(p, u16*, o)

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();

void func_800F24F0(void* arg0) {
    animate_object();
    {
        // !FAKE: depin: dropping it breaks the match (29/33)
        register s32 t asm("$2") = H(arg0, 0x7C);
        if (t != 0) {
            H(arg0, 0x7C)--;
            return;
        }
    }
    {
        // !FAKE: depin: dropping it breaks the match (31/33)
        register void* a asm("$4") = arg0;
        if (SB(arg0, 0x89) != 0) {
            SB(arg0, 0x89)--;
            set_animation(a, 2);
            {
                // !FAKE: depin: dropping it breaks the match (30/33)
                register s32 c asm("$2") = B(arg0, 0x6) - 1;
                B(arg0, 0x6) = c;
            }
            return;
        }
    }
    D_800F6AF0 = 0;
    B(arg0, 0x5) = 2;
    B(arg0, 0x6) = 0;
}

// clang-format off
INCLUDE_ASM("asm/rock_08/nonmatchings/E9860", func_800F2574);
// clang-format on

#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);

void func_800F25D0(void* arg0) {
    ((void (*)(void*, s32))set_animation)(arg0, 0);
    ((u8*)arg0)[6] = ((u8*)arg0)[6] + 1;
}

#include "../shared/rock_08/func_800F2604.c"

#define func_8003744C func_800F2660
#define D_80073C1C D_800F5FB8
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/rock_08/func_800F269C.c"

#include "common.h"
#include "mmx6/rock_08.h"
#define M2C_UNK s32

M2C_UNK animate_object();
M2C_UNK move_object(void*);

void func_800F2708(u8* arg0) {
    // !FAKE: depin: dropping it breaks the match (42/44)
    register s32 t asm("$2");

    animate_object();
    move_object(arg0);
    t = *(s32*)(arg0 + 0x20);
    if (t > 0) {
        if (D_800F6AF8 + 0x880 < *(s16*)(arg0 + 0xA)) {
            arg0[0x15] = 0;
            if (*(s8*)(arg0 + 0x87) < 10) {
                arg0[0x87]++;
            }
            arg0[5] = 3;
            arg0[6] = 0;
        }
    } else if (*(s16*)(arg0 + 0xA) < D_800F6AF8 + 0x590) {
        arg0[0x15] = 0x40;
        if (*(s8*)(arg0 + 0x87) < 10) {
            arg0[0x87]++;
        }
        arg0[5] = 3;
        arg0[6] = 0;
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_08/nonmatchings/E9860", func_800F27B8);
// clang-format on

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define ABS(x) ((x) < 0 ? -(x) : (x))

s32 set_animation(void*, s32);

void func_800F2814(void* arg0) {
    s8 t;

    set_animation(arg0, 4);
    t = M2C_FIELD(arg0, s8*, 0x88);
    if (t == 1) {
        M2C_FIELD(arg0, s16*, 0x7C) =
            (0x200000 / ABS(M2C_FIELD(arg0, s32*, 0x20))) + 6;
    } else if (t == 2) {
        M2C_FIELD(arg0, s16*, 0x7C) =
            (0x400000 / ABS(M2C_FIELD(arg0, s32*, 0x20))) + 6;
    } else if (t == 3) {
        M2C_FIELD(arg0, s16*, 0x7C) =
            0x600000 / ABS(M2C_FIELD(arg0, s32*, 0x20));
    } else {
        M2C_FIELD(arg0, s16*, 0x7C) =
            (0x800000 / ABS(M2C_FIELD(arg0, s32*, 0x20))) - 6;
    }
    if (M2C_FIELD(arg0, s8*, 0x8B) == 1) {
        M2C_FIELD(arg0, s16*, 0x7C) =
            (0x200000 / ABS(M2C_FIELD(arg0, s32*, 0x20))) + 8;
    }
    M2C_FIELD(arg0, u8*, 0x6)++;
}

#include "../shared/rock_08/func_800F2970.c"

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F29C8(void* arg0) {
    if (M2C_FIELD(arg0, s32*, 0x20) > 0) {
        M2C_FIELD(arg0, s8*, 0x15) = 0;
    } else {
        M2C_FIELD(arg0, s8*, 0x15) = 0x40;
    }
    M2C_FIELD(arg0, s8*, 5) = 6;
    M2C_FIELD(arg0, s8*, 6) = 0;
    M2C_FIELD(arg0, s16*, 0x7C) = 0x28;
}

#include "common.h"

void func_800F29FC(void) {
}

#include "common.h"

void func_800F2A04(void) {
}

#include "common.h"

void func_800F2A0C(void) {
}

#define func_8003744C func_800F2A14
#define D_80073C1C D_800F5FD8
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8003D308(M2C_UNK, M2C_UNK); /* extern */

void func_800F2A50(void* arg0) {
    func_8003D308(0x14, 0x40);
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"
#include "mmx6/rock_08.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

struct X4_EffectObj* alloc_class3_slot(void);
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK); /* extern */
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj g_playthrough_state;

void func_800F2A88(void* arg0) {
    s32 temp_v1;
    u8* temp_v0;

    if ((g_playthrough_state.unkF == 0) && (D_800970A5 == 0x14)) {
        if (g_playthrough_state.stage != 0xC) {
            M2C_FIELD(arg0, s16*, 0x7C) = 0x64;
        } else {
            background_objects[0].unk2A = 0xD0;
            M2C_FIELD(arg0, s16*, 0x7C) = 0xA;
        }
        func_8003D308(0x1D, 0x40);
        M2C_FIELD(arg0, u8*, 0x86) = background_objects[0].unk48;
        background_objects[0].unk48 = 1;
        background_objects[0].unk47 = 2;
        temp_v1 = (u16)D_800F6AF8 + 0x660;
        background_objects[0].unk26 = temp_v1;
        background_objects[0].unk24 = temp_v1;
        temp_v0 = (u8*)alloc_class3_slot();
        if (temp_v0 != 0) {
            temp_v0[0] = 1;
            temp_v0[1] = 0x18;
            M2C_FIELD(arg0, void**, 0x8C) = temp_v0;
        }
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#include "../shared/rock_08/func_800F2B78.c"

// clang-format off
INCLUDE_ASM("asm/rock_08/nonmatchings/E9860", func_800F2C24);
// clang-format on

#include "../shared/rock_08/func_800F2C74.c"

#include "common.h"
#include "mmx6/globals.h"
#include "mmx6/rock_08.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK animate_object();
M2C_UNK func_8003D330();
extern s8 D_800CCF5C;

void func_800F2CDC(void* arg0) {
    // !FAKE: depin: dropping it breaks the match (25/38)
    register s32 a asm("$4");

    animate_object();
    {
        // !FAKE: depin: dropping it breaks the match (33/38)
        register s32 t asm("$2") = M2C_FIELD(arg0, u16*, 0x7E) - 1;
        M2C_FIELD(arg0, s16*, 0x7E) = t;
        if ((t << 16) == 0) {
            play_sound(0, 0xE, 0);
            M2C_FIELD(arg0, s16*, 0x7E) = 3;
        }
    }
    if ((s8)++M2C_FIELD(arg0, u8*, 0x5C) == D_800CCF5C) {
        a = M2C_FIELD(arg0, u8*, 0x86);
        D_800F6AF0 = 0;
        D_80097240 = a;
        M2C_FIELD(arg0, u8*, 5) = 2;
        M2C_FIELD(arg0, u8*, 6) = 0;
        func_8003D330(a);
    }
}

#include "common.h"

void func_800F2D74(void) {
}

#define func_8003744C func_800F2D7C
#define D_80073C1C D_800F5FF8
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/rock_08/func_800F2DB8.c"

// clang-format off
INCLUDE_ASM("asm/rock_08/nonmatchings/E9860", func_800F2E10);
// clang-format on

#include "common.h"

#define M2C_UNK s32

M2C_UNK animate_object(); /* extern */

void func_800F2F04(void) {
    animate_object();
}

#include "../shared/rock_08/func_800F2F24.c"

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define FX(p, type, off) (*(type*)((u8*)(p) + (off)))

s32 set_animation(void*, s32);
M2C_UNK animate_object();
void func_800F32A8(struct X4_AnimatedObj* self);
extern M2C_UNK D_8007433C;
extern M2C_UNK D_800F5DE8;
extern M2C_UNK D_800F5DEC;

void func_800F2FA0(void* arg0) {

    FX(arg0, u16, 0x7C) = FX(arg0, u16, 0x7C) + 1;
    ((void (*)())animate_object)();
    if (FX(arg0, s16, 0x7C) >= 0x29) {
        if (FX(arg0, u16, 0x80) & 1) {
            FX(arg0, u16, 0x80) = 0x3C;
        } else {
            FX(arg0, u16, 0x80) = 0x3B;
        }
        func_800F32A8(arg0);
        ((void (*)(void*, s32))set_animation)(arg0, 0);
        FX(arg0, s8, 0x5) = 3;
        FX(arg0, s8, 0x6) = 0;
        FX(arg0, void*, 0x50) = &D_800F5DE8;
        FX(arg0, void*, 0x54) = &D_800F5DEC;
        FX(arg0, void*, 0x58) = &D_8007433C;
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_08/nonmatchings/E9860", func_800F3048);
// clang-format on

#define func_800F1ED8 func_800F30A4
#include "../shared/rock_08/func_800F1ED8.c"
#undef func_800F1ED8

#include "common.h"
#include "mmx6/rock_08.h"
#define M2C_UNK s32

M2C_UNK animate_object();

void func_800F3130(u8* arg0) {
    animate_object();
    if (((s8*)arg0)[7] == 2) {
        if (--((s8*)arg0)[0x89] == 0) {
            arg0[5] = 7;
            arg0[6] = 0;
            D_800F6AF0 = 0;
        } else {
            arg0[6]++;
        }
        arg0[7] = 0;
    }
}

#include "../shared/rock_08/func_800F31A8.c"

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
s32 set_animation(void*, s32);
s32 random_byte();

void func_800F3230(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 7) == 3) {
        M2C_FIELD(arg0, s8*, 7) = 0;
        set_animation(arg0, 3);
        if (!(random_byte() & 1)) {
            play_sound(2, 0x27, arg0);
        } else {
            play_sound(2, 0x28, arg0);
        }
        M2C_FIELD(arg0, s8*, 6) = 2;
    }
}

#include "../shared/rock_08/func_800F32A8.c"

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F32D8(void* arg0) {
    M2C_FIELD(arg0, s8*, 5) = 3;
    M2C_FIELD(arg0, s8*, 6) = 0;
}

#define func_80048DC8 func_800F32E8
#define D_80077BC0 D_800F62AC
#include "../shared/d1000/func_80048DC8.c"
#undef func_80048DC8
#undef D_80077BC0

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800F3334(void) {
    clear_object_slot();
}

#include "../shared/rock_08/func_800F3354.c"

#define func_8003744C func_800F33E0
#define D_80073C1C D_800F62B8
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#include "mmx6/rock_08.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
extern s16 D_800970AA;

void func_800F341C(u8* arg0) {
    s32 temp_a1;
    s32 y;

    y = *(s16*)(arg0 + 0xA) + 0x10;
    temp_a1 = ((D_800970AA - y) << 0x10) / 40;
    *(s32*)(arg0 + 0x28) = 0;
    {
        s32 k1 = 0x1400;
        *(s32*)(arg0 + 0x2C) = k1;
    }
    {
        // !FAKE: depin: dropping it breaks the match (36/42)
        register s32 k2 asm("$2") = 0x28000;
        *(s32*)(arg0 + 0x24) = k2;
    }
    *(s32*)(arg0 + 0x20) = temp_a1;
    if (temp_a1 > 0) {
        arg0[0x15] = 0x40;
    } else {
        arg0[0x15] = 0;
    }
    play_sound(2, 0x35, arg0);
    D_800F6AF2 = 0;
    arg0[6] = arg0[6] + 1;
}

#define func_8003744C func_800F34C4
#define D_80073C1C D_800F62C0
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/rock_08/func_800F3500.c"

#define func_8003744C func_800F3580
#define D_80073C1C D_800F62C8
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/rock_08/func_800F35BC.c"

#include "../shared/rock_08/func_800F3678.c"

// clang-format off
INCLUDE_ASM("asm/rock_08/nonmatchings/E9860", func_800F3710);
// clang-format on
