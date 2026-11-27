#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/engine_state.h"
#include "psyq/libgpu.h"

void* alloc_sprite_slot();
M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK set_animation(void*, M2C_UNK);
s32 func_80021AF0(s32 arg0);
void func_8002234C();
extern u32* D_80071C58[];
extern u16 D_80071D78[];
extern u16 D_800C4570;
extern s8 D_800CCEDC;
extern struct X4_VisualObj* D_800E33B0;
extern struct X4_VisualObj* D_800E33B4;
extern struct X4_VisualObj* D_800E33B8;
extern struct X4_VisualObj* D_800E33BC;
extern struct X4_VisualObj* D_800E33C0;
extern u16 D_800E33C6;
extern s16 D_800E33C8;
extern u16 D_800E33D8[];
extern u8 D_800E3418;
extern u8 D_800E3419;
extern u16 g_wide_mode;

/* load_palette returns nothing: calling it as void keeps v0 free after the call, which the `== 2` tests need. */
#define LOAD_PALETTE ((void (*)(M2C_UNK, M2C_UNK*, M2C_UNK))load_palette)

#define SCR_A0 (*(u8**)0x1F8000A0)
#define SCR_A8 (*(s32*)0x1F8000A8)

static inline void load_mugshot_palette(s32 n, s32 idx) {
    LOAD_PALETTE(n * 0x10 + 0x1E0, (M2C_UNK*)(SCR_A8 + idx * 0x200), 0x10);
}

static inline void load_mugshot_image(void) {
    X4_RECT r;
    s32 src;
    s32 n;

    src = 0x801F6000;
    n = 3;
    r.x = 0x140;
    r.y = 0x70;
    r.w = 0x40;
    r.h = 0x10;
    do {
        LoadImage((struct RECT*)&r, (unsigned long*)src);
        src += 0x800;
        n--;
        r.y += 0x10;
    } while (n >= 0);
}

// Steps the text box state machine (unkD): case 0 counts down, then spawns the left and right speaker mugshot sprites
// (palette and image loads written as the PC port's two helpers, inlined); cases 2-6 wait on the pad or a timer and
// tear the mugshots down. Each block's `off` is block-local: a shared one went to greg and lost a2 (2.7 T9.c3).
void update_text_box(struct X4_AbcObj* arg0) {
    struct X4_VisualObj* obj;
    s32 n;
    s32 k;
    s16 x;

    switch (arg0->unkD) {
    case 0:
        if (--*(s16*)&arg0->unkA == 0) {
            if (D_800E33C6 & 0x8000) {
                obj = alloc_sprite_slot();
                if (obj != NULL) {
                    u8* base;
                    s32 off;

                    obj->active = 0x69;
                    load_mugshot_palette(0, D_800E33C6 & 3);
                    if ((D_800E33C6 & 3) == 2) {
                        load_mugshot_image();
                        obj->active = 9;
                    }
                    obj->id = 0x16; /*b1*/
                    obj->unk2 = 5;
                    obj->unk15 = 0x40;
                    obj->bg_offset = -1;
                    if (D_800E33C6 & 0x4000) {
                        obj->x_pos.u.hi = 0xA0;
                    } else {
                        obj->x_pos.u.hi = 0x50;
                    }
                    obj->y_pos.u.hi = 0x48;
                    obj->unk16 = 0x10;
                    obj->animation_table =
                        (u32**)D_80071C58[func_80021AF0(D_800E33C6 & 3)];
                    obj->unk40 = D_80071D78[D_800E33C6 & 3];
                    obj->unk42 = 0x7F80;
                    n = func_80021AF0(D_800E33C6 & 3);
                    base = SCR_A0;
                    off = *(s32*)(base + n * 4);
                    obj->state = 0;
                    obj->unk3C = base + off;
                    *(u8*)&obj->unk54 = *(u8*)&D_800E33C6 & 3;
                    *((u8*)&obj->unk54 + 1) = 2;
                    set_animation(obj, 2);
                    D_800E33BC = obj;
                }
            }
            if ((s32)(D_800E33C6 & 0xC000) == 0x8000) {
                obj = alloc_sprite_slot();
                if (obj != NULL) {
                    u8* base;
                    s32 off;

                    obj->active = 0x69;
                    load_mugshot_palette(1, (D_800E33C6 >> 4) & 3);
                    if (((D_800E33C6 >> 4) & 3) == 2) {
                        load_mugshot_image();
                        obj->active = 9;
                    }
                    obj->id = 0x16; /*b2*/
                    obj->unk2 = 5;
                    obj->bg_offset = -1;
                    obj->x_pos.u.hi = 0xF0;
                    obj->unk15 = 0;
                    obj->unk16 = 0x10;
                    obj->y_pos.u.hi = 0x48;
                    obj->animation_table =
                        (u32**)D_80071C58[func_80021AF0((D_800E33C6 >> 4) & 3)];
                    obj->unk40 = D_80071D78[(D_800E33C6 >> 4) & 3];
                    obj->unk42 = 0x7FC0;
                    n = func_80021AF0((D_800E33C6 >> 4) & 3);
                    base = SCR_A0;
                    off = *(s32*)(base + n * 4);
                    obj->state = 0;
                    obj->unk3C = base + off;
                    *(u8*)&obj->unk54 = (D_800E33C6 >> 4) & 3;
                    *((u8*)&obj->unk54 + 1) = 2;
                    set_animation(obj, 2);
                    D_800E33C0 = obj;
                }
            }
            arg0->unkC = 1;
            arg0->unkD = 1;
        }
        break;
    case 1:
        func_8002234C(arg0);
        break;
    case 2:
        if (*(u8*)&D_800C4570 != 0) {
            arg0->unkF = 0;
        }
        if (--*(s16*)&arg0->unkA == 0) {
            arg0->unkD = 1;
        }
        break;
    case 3:
        if (*(u8*)&D_800C4570 != 0) {
            if (D_800E33B8 != NULL && D_800E33B8->id == 0x16) {
                D_800E33B8->active = 0;
                D_800E33B8->on_screen = 0;
            }
            if (arg0->unk4 & 0x8000) {
                if (D_800E33B4 != NULL && D_800E33B4->id == 0x16) {
                    D_800E33B4->active = 0;
                    D_800E33B4->on_screen = 0;
                }
                if (D_800E33C0 != NULL && D_800E33C0->id == 0x16) {
                    D_800E33C0->active = 0;
                    D_800E33C0->on_screen = 0;
                }
                if (D_800E33BC != NULL && D_800E33BC->id == 0x16) {
                    D_800E33BC->active = 0;
                    D_800E33BC->on_screen = 0;
                }
                arg0->unkA = 0x32;
                arg0->unkD = 4;
                arg0->unkC = 0x80;
            } else {
                D_800E33C8 = 0;
                arg0->unkC = 1;
                if (g_wide_mode == 0) {
                    arg0->unk6 = -0x80;
                } else {
                    arg0->unk6 = -0xE0;
                }
                if (D_800CCEDC == 0xD) {
                    arg0->unk6 += 0x30;
                }
                arg0->unk8 = 0x1D;
                arg0->unkE++;
                func_8002234C(arg0);
            }
        }
        break;
    case 4:
        if (--*(s16*)&arg0->unkA == 0) {
            if (g_wide_mode == 0) {
                LOAD_PALETTE(0x15, D_800E33D8, 2);
            } else {
                LOAD_PALETTE(0x5E, D_800E33D8, 2);
            }
            g_playthrough_state.enable_boss = D_800E3419;
            g_playthrough_state.unk1F = D_800E3418;
            if (D_800E33B0 != NULL && D_800E33B0->id == 0x16) {
                D_800E33B0->active = 0;
                D_800E33B0->on_screen = 0;
            }
            if (D_800E33B4 != NULL && D_800E33B4->id == 0x16) {
                D_800E33B4->active = 0;
                D_800E33B4->on_screen = 0;
            }
            if (D_800E33B8 != NULL && D_800E33B8->id == 0x16) {
                D_800E33B8->active = 0;
                D_800E33B8->on_screen = 0;
            }
            if (D_800E33C0 != NULL && D_800E33C0->id == 0x16) {
                D_800E33C0->active = 0;
                D_800E33C0->on_screen = 0;
            }
            if (D_800E33BC != NULL && D_800E33BC->id == 0x16) {
                D_800E33BC->active = 0;
                D_800E33BC->on_screen = 0;
            }
            arg0->unkE = 0;
            arg0->unkD = 5;
            arg0->unkC = 0;
        }
        break;
    case 6:
        if (--*(s16*)&arg0->unkA == 0) {
            arg0->unkC = 0;
        }
        break;
    }
}
