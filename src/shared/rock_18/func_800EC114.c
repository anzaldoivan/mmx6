#include "common.h"
#include "mmx6/x4.h"

void* alloc_sprite_slot();
void func_800EB15C(s32, s32);
void func_800EB7B8(s32, s32);
void func_800EBBC8(s32, s32, s32);
extern struct X4_EngineObj D_80097420;
extern u8 D_80097427;
extern struct X4_EngineObj g_playthrough_state;
extern struct X4_MiscObj g_displayed_sprites[];
extern struct X4_MiscObj D_800E2F90;
extern void* D_800E2F9C;
extern u8 D_800F0930[];
extern u8 D_800F0990[];
extern u8 D_800F09F0[];
extern u8 D_800F0A10[][0xC];

#define B(p, o) (*(u8*)((u8*)(p) + (o)))
#define SB(p, o) (*(s8*)((u8*)(p) + (o)))
#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define H(p, o) (*(s16*)((u8*)(p) + (o)))
#define UH(p, o) (*(u16*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))
#define T(t, b, i, sz, o) (*(t*)((u8*)(b) + (o) + (i) * (sz)))
#define SAVE ((u8*)D_800E2F90.y_pos.val)

static inline void spawnA(u8 spr, s16 x, s16 y) {
    u8* obj = alloc_sprite_slot();
    if (obj != NULL) {
        B(obj, 0) = 1;
        B(obj, 1) = 0x2D;
        B(obj, 2) = spr;
        H(obj, 0xA) = x;
        H(obj, 0xE) = y;
        B(obj, 0x58) = 1;
        B(obj, 0x59) = g_playthrough_state.unk1;
        B(obj, 0x5A) = D_80097427;
    }
}

static inline void spawnB(u8 spr, s16 x, s16 y) {
    u8* obj = alloc_sprite_slot();
    if (obj != NULL) {
        B(obj, 0) = 1;
        B(obj, 1) = 0x2D;
        B(obj, 2) = spr;
        H(obj, 0xA) = x;
        H(obj, 0xE) = y;
        B(obj, 0x58) = 1;
        B(obj, 0x59) = g_playthrough_state.unk1;
        B(obj, 0x5A) = D_80097420.unk7;
    }
}

void func_800EC114(void) {
    u32 i;
    u8 j;
    u8 count;
    u8 id;
    s16 x;
    s16 y;
    u8* e;
    s8* p;
    s32 n;
    s8 z = 0;

    for (i = 0; i < 0x60; i++) {
        e = (u8*)&g_displayed_sprites[i];
        if (SB(e, 1) == 0x2D && SB(e, 0x58) != 0) {
            s8* q = (s8*)e;
            s32 k = 0x60;
            while (k--) {
                *q++ = z;
            }
        }
    }
    g_playthrough_state.unk4 = 2;
    if (UB(SAVE, 0) == 0xFF) {
        {
            u8* obj = alloc_sprite_slot();
            if (obj != NULL) {
                B(obj, 0) = 1;
                B(obj, 1) = 0x2E;
                B(obj, 2) = 0x27;
                H(obj, 0xA) = 0x158;
                H(obj, 0xE) = 0x68;
                B(obj, 0x58) = 1;
                B(obj, 0x59) = g_playthrough_state.unk1;
                B(obj, 0x5A) = D_80097427;
            }
        }
        g_playthrough_state.unk4 = 1;
        return;
    }
    spawnA(0xA8, 0x108, 0x2E);
    for (j = 0; j < 8; j++) {
        if ((UB(SAVE, 0x3A) >> j) & 1) {
            if ((s8)(s32)g_playthrough_state.controlled_player == 0) {
                n = j;
                spawnB(T(u8, D_800F0930, n, 6, 0),
                       T(s16, D_800F0930, n, 6, 2) + 0xA,
                       T(s16, D_800F0930, n, 6, 4) + 4);
            } else {
                n = j + 8;
                spawnB(T(u8, D_800F0930, n, 6, 0),
                       T(s16, D_800F0930, n, 6, 2) + 0xA,
                       T(s16, D_800F0930, n, 6, 4) + 4);
            }
        }
    }
    spawnA(0xA9, 0x172, 0x2E);
    for (j = 0; j < 8; j++) {
        if ((UB(SAVE, 0x3C) >> j) & 1) {
            spawnB(T(u8, D_800F0990, j, 6, 0),
                   T(s16, D_800F0990, j, 6, 2) + 0xA,
                   T(s16, D_800F0990, j, 6, 4) + 4);
        }
    }
    spawnA(0xAA, 0x1DC, 0x2E);
    for (j = 0; j < 4; j++) {
        if (UH(SAVE, 0x14) & T(u16, D_800F09F0, j, 8, 0)) {
            spawnB(T(u8, D_800F09F0, j, 8, 2), T(s16, D_800F09F0, j, 8, 4) - 2,
                   T(u16, D_800F09F0, j, 8, 6) + 0xFFFC);
        }
    }
    spawnA(0x7A, 0x92, 0x5E);
    spawnA(0xAC, 0xAA, 0x60);
    count = 0;
    for (j = 0; j < 0x10; j++) {
        if (*(u32*)((u8*)D_800E2F9C + 0x10) & (1 << j)) {
            count++;
        }
    }
    spawnA(count / 10 + 0xAE, 0xBE, 0x60);
    spawnA(count % 10 + 0xAE, 0xD2, 0x60);
    spawnA(0x7B, 0xFC, 0x5E);
    spawnA(0xAC, 0x114, 0x60);
    count = 0;
    for (; j < 0x20; j++) {
        if (*(u32*)((u8*)D_800E2F9C + 0x10) & (1 << j)) {
            count++;
        }
    }
    spawnA(count / 10 + 0xAE, 0x128, 0x60);
    spawnA(count % 10 + 0xAE, 0x13C, 0x60);
    for (j = 0; j < 0x18; j++) {
        if (W(SAVE, 4) & *(s32*)&D_800F0A10[j][0]) {
            u8* r = D_800F0A10[j];
            spawnB(B(r, 4), H(r, 6) + 0xC, H(r, 8) + 4);
        }
    }
    spawnA(0xAB, 0x108, 0x86);
    spawnA(0x9D, 0x92, 0x93);
    id = UB(SAVE, 0x3D) + 0x84;
    spawnA(id, 0xB4, 0x95);
    spawnA(0xAD, 0xD2, 0x95);
    spawnA(0x9A, 0xE5, 0x93);
    func_800EBBC8(0xFE, 0x96, 0);
    if (UB(SAVE, 0x3B) & 0x10) {
        g_playthrough_state.unk4 = 0;
        spawnA(0x9E, 0x92, 0xA3);
        id = UB(SAVE, 0x3E) + 0x84;
        spawnA(id, 0xB4, 0xA5);
        spawnA(0xAD, 0xD2, 0xA5);
        spawnA(0x9A, 0xE5, 0xA3);
        func_800EBBC8(0xFE, 0xA6, 1);
    }
    spawnA(0x9B, 0x168, 0x8F);
    func_800EB7B8(0x180, 0x91);
    spawnA(0x9C, 0x168, 0xA3);
    func_800EB15C(0x184, 0xA5);
}
