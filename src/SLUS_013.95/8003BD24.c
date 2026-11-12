// prog SLUS_013.95 | system movement | range 0x8003BD24-0x8003C4E8
// clang-format off
#include "../shared/SLUS_013.95/func_8003BD24.c"
// clang-format on

#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_8003AD18(void* arg0);
void set_pose_size();
void load_buffered_palette(s32, s32, s32);
M2C_UNK player_spawn_visual(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2,
                            M2C_UNK arg3);
void set_base_move_stats(void*);
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
            load_buffered_palette(2, 0x19, 1);
            load_buffered_palette(2, 0x18, 1);
        } else {
            M2C_FIELD(arg0, u8*, 0xC9) = M2C_FIELD(f, u8*, 0x60);
        }
    }
    set_base_move_stats(arg0);
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
    set_pose_size(arg0);
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

// 0x8003C3C8 func_8003C3C8: sets the per-frame box pointer +0x54 from tables indexed by animation and frame.
// basis: none
// callers: update_player
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
    } else {
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
    }
    off += base;
    PP(0x54) = (s32*)off;
}

#undef PB
#undef PU
#undef PP
