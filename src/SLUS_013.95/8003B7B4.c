#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8003CD9C();

M2C_UNK func_8003B7B4(void* arg0) {
    M2C_FIELD(arg0, s16*, 8) = 0;
    M2C_FIELD(arg0, s16*, 0xC) = 0;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, u16*, 0xA) = (M2C_FIELD(arg0, u16*, 0xA) & 0xFFF0) + 8;
    M2C_FIELD(arg0, s32*, 0x24) = M2C_FIELD(arg0, s32*, 0x11C);
    ((void (*)())func_8003CD9C)(arg0);
    M2C_FIELD(arg0, u8*, 5) = 0xF;
    M2C_FIELD(arg0, u8*, 6) = 0;
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8003CD9C();

M2C_UNK func_8003B810(void* arg0) {
    u8* p = (u8*)arg0;

    *(s16*)(p + 0x8) = 0;
    *(s16*)(p + 0xC) = 0;
    *(s32*)(p + 0x20) = 0;
    *(s32*)(p + 0x28) = 0;
    *(s32*)(p + 0x2C) = 0;
    *(u16*)(p + 0xA) = (*(u16*)(p + 0xA) & 0xFFF0) + 8;
    *(s32*)(p + 0x24) = -*(s32*)(p + 0x11C);
    ((void (*)())func_8003CD9C)(p);
    p[5] = 0x10;
    p[6] = 0;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_bgm_xa_track(M2C_UNK, M2C_UNK);
void func_8003B954(struct X4_PlayerObj* self);
M2C_UNK func_8003BA04(void*, M2C_UNK);
M2C_UNK func_8003CDF0();
M2C_UNK func_8003D10C(void*);
void func_8003F000(void* arg0);
M2C_UNK func_8003F3DC(void*);
extern struct X4_EngineObj g_playthrough_state;

void func_8003B870(struct X4_PlayerObj* self) {
    ((void (*)())func_8003CDF0)();
    ((void (*)(void*))func_8003F3DC)(self);
    g_playthrough_state.gameplay_locked = 1;
    if (g_playthrough_state.unkF & 0x10) {
        func_8003D10C(self);
        func_8003F000(self);
        if (self->unk2 == 0) {
            play_bgm_xa_track(4, 0x7F);
        } else {
            play_bgm_xa_track(5, 0x7F);
            self->weapon = 0;
        }
        self->unk5 = 0x19;
        self->unk6 = 0;
        return;
    }
    if (g_playthrough_state.unkF & 0x40) {
        self->state = 3;
        self->unk5 = 0;
        self->unk6 = 0;
        return;
    }
    func_8003BA04(self, 3);
    func_8003F000(self);
    if (self->unk2 != 0) {
        self->weapon = 0;
    }
    func_8003B954(self);
}

/* Adapted from sozud/mmx4 @807a01b src/main/player_enter.c:player_enter_beam_out, AGPL-3.0; proven shared with X6 by exact signature f6ae817e5d19 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
s32 play_sound(s32, s32, void*);

void func_8003B954(struct X4_PlayerObj* self) {
    ((s32(*)())play_sound)(1, 0xB, self);
    self->x_vel.val = 0;
    self->unk28 = 0;
    self->y_vel.val = FIXED(8);
    self->unk2C = 0;
    self->unk68 = 0;
    self->air_state = 1;
    self->unk5 = PLAYER_BEAM_OUT;
    self->unk6 = 0;
}

#include "common.h"
#define M2C_UNK s32

s32 func_8003A628(void*);
M2C_UNK func_8003BA04(void*, M2C_UNK);

M2C_UNK func_8003B9AC(void* arg0) {
    s32 var_a1;

    if (func_8003A628(arg0) == 0) {
        var_a1 = 0x51;
        if (*(s32*)((u8*)arg0 + 0x8C) & 0xFFFF0000) {
            var_a1 = 0x6D;
        }
        ((void (*)(void*, s32))func_8003BA04)(arg0, var_a1);
        *((u8*)arg0 + 5) = 0x1A;
        *((u8*)arg0 + 6) = 0;
    }
}

// clang-format off
INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/32208", func_8003BA04);
// clang-format on

#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation_frame(void*, M2C_UNK, s8);
extern u8 D_801EF620[];
extern u8 D_801F49F4[];

#define SCRATCH_14 (*(u8**)0x1F800014)
#define SCRATCH_1C (*(u8**)0x1F80001C)
#define FLD(p, T, o) (*(T)((u8*)(p) + (o)))

M2C_UNK func_8003BB94(void* arg0, M2C_UNK arg1, s8 arg2) {
    u8* self;
    u8* q;
    // !FAKE: retail loads the table offset into the first argument register
    register s32 t asm("$4");
    s32 a2r;
    u8 v;

    self = arg0;
    if (FLD(self, s8*, 0x2) == 0) {
        if (D_801F49F4[arg1] == 0) {
            FLD(self, u8**, 0x38) = SCRATCH_14 + *(s32*)(SCRATCH_14);
            q = SCRATCH_1C;
            t = *(s32*)q;
            FLD(self, volatile u8*, 0xDC) = 5;
        } else {
            FLD(self, u8**, 0x38) = SCRATCH_14 + *(s32*)(SCRATCH_14 + 0x28);
            q = SCRATCH_1C;
            t = *(s32*)(q + 0x48);
            FLD(self, volatile u8*, 0xDC) = 0x13;
        }
        // !FAKE: both outer arms share the offset add before the 0x3C store
        goto add;
    }
    v = D_801EF620[arg1];
    if (v == 0) {
        FLD(self, u8**, 0x38) = SCRATCH_14 + *(s32*)(SCRATCH_14);
        q = SCRATCH_1C;
        q = q + *(s32*)q;
    } else if (v == 1) {
        FLD(self, u8**, 0x38) = SCRATCH_14 + *(s32*)(SCRATCH_14 + 4);
        q = SCRATCH_1C;
        q = q + *(s32*)(q + 0x14);
    } else if (v == 2) {
        FLD(self, u8**, 0x38) = SCRATCH_14 + *(s32*)(SCRATCH_14 + 8);
        q = SCRATCH_1C;
        q = q + *(s32*)(q + 0x1C);
    } else {
        // !FAKE: arms without a slot skip the shared 0x3C store
        goto end;
    }
    // !FAKE: the inner arms skip the outer arms' offset add
    goto store;
add:
    q = q + t;
store:
    FLD(self, u8**, 0x3C) = q;
end:
    ((M2C_UNK(*)())set_animation_frame)(self, arg1, a2r);
}

// clang-format off
INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/32208", func_8003BD24);
// clang-format on

#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_8003AD18(void* arg0);
M2C_UNK func_8003CCBC();
void func_8003CF24(s32, s32, s32);
M2C_UNK player_spawn_visual(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2,
                            M2C_UNK arg3);
void func_8003D598(void*);
extern u16 D_80073CFC[];
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj g_playthrough_state;

void func_8003C1AC(void* arg0) {
    s8* e = (s8*)&g_playthrough_state;
    u8 t;
    if (M2C_FIELD(e, s8*, 0xC) == 0xC) {
        if (M2C_FIELD(e, s8*, 0xD) == 0) {
            M2C_FIELD(arg0, u16*, 0xE) = D_80073CFC[M2C_FIELD(e, s8*, 0x1D)];
        } else {
            M2C_FIELD(arg0, u16*, 0xE) = 0x1CB;
        }
    }
    {
        s8* f = (s8*)&g_playthrough_state;
        t = M2C_FIELD(f, u8*, 0x5E);
        M2C_FIELD(arg0, u8*, 0xE7) = t;
        M2C_FIELD(arg0, s32*, 0xEC) =
            *(s32*)(f - -(M2C_FIELD(arg0, s8*, 2) << 2) + 0x74);
        if (t == 2) {
            M2C_FIELD(arg0, u8*, 0xC9) = 0;
            player_spawn_visual(1, 0x1B, 5, 0);
            func_8003CF24(2, 0x19, 1);
            func_8003CF24(2, 0x18, 1);
        } else {
            M2C_FIELD(arg0, u8*, 0xC9) = M2C_FIELD(f, u8*, 0x60);
        }
    }
    func_8003D598(arg0);
    if (M2C_FIELD(arg0, s32*, 0xEC) & 8) {
        M2C_FIELD(arg0, s32*, 0x134) -= 0x1080;
    }
    if (M2C_FIELD(arg0, u8*, 0xE7) == 2) {
        M2C_FIELD(arg0, s32*, 0x110) = 0;
    }
    if (M2C_FIELD(arg0, s32*, 0xEC) & 0x10) {
        M2C_FIELD(arg0, s32*, 0x104) += 0x1A000;
        M2C_FIELD(arg0, s32*, 0x108) += 0x10800;
        M2C_FIELD(arg0, s32*, 0x10C) += 0xC00;
        M2C_FIELD(arg0, s32*, 0x12C) += 0x10800;
        M2C_FIELD(arg0, s32*, 0x130) += 0x10800;
    }
    if (M2C_FIELD(arg0, s32*, 0xEC) & 4) {
        M2C_FIELD(arg0, s32*, 0xF0) += 0x4000;
        M2C_FIELD(arg0, s32*, 0xF4) += 0x10000;
    }
    if (M2C_FIELD(arg0, s8*, 2) != 0) {
        M2C_FIELD(arg0, u16*, 0xE) -= 1;
    }
    M2C_FIELD(arg0, s16*, 0xC) = 0;
    M2C_FIELD(e, s8*, 0x1C) = 0;
    func_8003CCBC(arg0);
    func_8003AD18(arg0);
    {
        // !FAKE: depin: dropping it breaks the match (126/135)
        register s32 k asm("$2") = 4;
        M2C_FIELD(arg0, u8*, 0x92) = k;
    }
    M2C_FIELD(arg0, u8*, 0x71) |= 8;
    background_objects[0].unk44 = 1;
    background_objects[1].unk44 = 1;
    background_objects[2].unk44 = 1;
}

#include "common.h"

extern u8 D_801EE700[];
extern u8 D_801EE800[];
extern u8 D_801EE900[];
extern s32 D_801EEA00[];
extern u8 D_801EF620[];
extern u8 D_801F3B4C[];
extern u8 D_801F3C4C[];
extern u8 D_801F3D4C[];
extern u8 D_801F3E4C[];
extern s32 D_801F3F4C[];
extern u8 D_801F49F4[];

#define PB(o) (*(s8*)((u8*)arg0 + (o)))
#define PU(o) (*(u8*)((u8*)arg0 + (o)))
#define PP(o) (*(s32**)((u8*)arg0 + (o)))

void func_8003C3C8(void* arg0) {
    s32 base;
    s32 off;
    u8 v;
    u8 k;

    if (PB(0x2) == 0) {
        if (D_801F49F4[PU(0x17)] == 0) {
            v = D_801F3B4C[PU(0x47)];
        } else {
            k = PU(0xE7);
            if (k == 1) {
                v = D_801F3D4C[PU(0x47)];
            } else if (k == 2) {
                v = D_801F3E4C[PU(0x47)];
            } else {
                v = D_801F3C4C[PU(0x47)];
            }
        }
        off = v * 4;
        if (v == 0) {
            PP(0x54) = 0;
            return;
        }
        base = (s32)D_801F3F4C;
        goto end;
    }
    k = D_801EF620[PU(0x17)];
    if (k == 0) {
        v = D_801EE700[PU(0x47)];
    } else if (k == 1) {
        v = D_801EE800[PU(0x47)];
    } else if (k == 2) {
        v = D_801EE900[PU(0x47)];
    }
    off = v * 4;
    if (v == 0) {
        PP(0x54) = 0;
        return;
    }
    base = (s32)D_801EEA00;
end:
    off += base;
    PP(0x54) = (s32*)off;
}

#undef PB
#undef PU
#undef PP

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
void func_8003CF54(struct X4_PlayerObj*, s32);
extern u8 D_800CCF2F;

#define PAL_BUF (*(u8**)0x1F800024)
#define PAL_BUF_B ((u8*)((struct X4_PlayerObj*)0x1F800000)->y_vel.val)
#define PLAYER_FLAGS_EC(p) (*(s32*)((u8*)(p) + 0xEC))

void func_8003C4EC(struct X4_PlayerObj* self) {
    s32 flags;
    s32 load;

    if (self->unk2 == 0) {
        s8 weapon = self->weapon;
        if (weapon == 0) {
            func_8003CF54(self, 0);
        } else {
            load = 1;
            if (weapon == 2) {
                load = 0;
            } else if (weapon == 3) {
                load = 0;
            } else if (weapon == 4) {
                load = 0;
            } else if (weapon == 5) {
                load = 0;
            } else if (weapon == 7) {
                load = 0;
            }
            if (load != 0) {
                load_palette(1, (s32*)(PAL_BUF + ((self->weapon << 7) - 0x20)),
                             1);
            }
            load_palette(0, (s32*)(PAL_BUF + (self->weapon << 7)), 1);
            load_palette(0x13, (s32*)(PAL_BUF_B + ((self->weapon << 7) | 0x20)),
                         1);
        }
        flags = PLAYER_FLAGS_EC(self);
        if (flags & 0x80) {
            load_palette(0x14, (s32*)(PAL_BUF + 0x9E0), 1);
            return;
        }
        if (flags & 0x100) {
            load_palette(0x14, (s32*)(PAL_BUF + 0x9C0), 1);
            return;
        }
        if (flags & 0x40000) {
            load_palette(0x14, (s32*)(PAL_BUF + 0x9A0), 1);
        }
    } else {
        if (D_800CCF2F & 0x20) {
            load_palette(0, (s32*)(PAL_BUF + 0x1A0), 1);
            load_palette(0xD, (s32*)(PAL_BUF_B + 0x9A0), 3);
            return;
        }
        load_palette(0, (s32*)PAL_BUF, 1);
    }
}
#undef PAL_BUF
#undef PAL_BUF_B
#undef PLAYER_FLAGS_EC
