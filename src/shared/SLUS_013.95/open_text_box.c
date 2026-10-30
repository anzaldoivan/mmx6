#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern struct X4_AbcObj D_8008EAF0;
extern struct X4_EngineObj g_playthrough_state;
extern u16 g_wide_mode;
extern s32 D_8006E408;
extern s32 D_800E33B0;
extern struct X4_QuadObj* D_800E33B4;
extern struct X4_QuadObj* D_800E33B8;
extern struct X4_QuadObj* D_800E33BC;
extern struct X4_QuadObj* D_800E33C0;
extern u8 D_800E33C4;
extern u16 D_800E33C6;
extern s16 D_800E33C8;
extern u16 D_800E33D8[];
extern u8 D_800E3418;
extern u8 D_800E3419;
void func_80022838(s32);
M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
struct X4_QuadObj* alloc_class6_slot(void);

#define SP_PALETTE_BASE (*(u8**)0x1F800028)
#define SP_MESSAGES (*(u8**)0x1F800048)

// 0x80021760 open_text_box: text box first page.
// basis: community tweaks-index.tsv:362
// callers: func_80020D18, func_80051AC8, func_80053274, func_800EA394 and others
void open_text_box(u16 arg0, u8 arg1, u8 arg2) {
    struct X4_AbcObj* abc = &D_8008EAF0;
    struct X4_QuadObj* q;
    u16* src;
    u16* dst;
    u8* base;
    u16* msg;
    u16 head;
    s16 v;
    s32 i;
    u8 a;
    u8 b;

    if (abc->unkC != 0) {
        if (abc->unkC == 0x80) {
            abc->unk10 = arg0 | 0x8000;
            return;
        }
        if (D_800E33B4 != 0 && D_800E33B4->id == 0x16) {
            D_800E33B4->active = 0;
            D_800E33B4->on_screen = 0;
        }
        if (D_800E33B8 != 0 && D_800E33B8->id == 0x16) {
            D_800E33B8->active = 0;
            D_800E33B8->on_screen = 0;
        }
        if (D_800E33C0 != 0 && D_800E33C0->id == 0x16) {
            D_800E33C0->active = 0;
            D_800E33C0->on_screen = 0;
        }
        if (D_800E33BC != 0 && D_800E33BC->id == 0x16) {
            D_800E33BC->active = 0;
            D_800E33BC->on_screen = 0;
        }
        abc->unkC = 0x80;
        abc->unkA = 0x32;
        abc->unkD = 4;
        abc->unk10 = arg0 | 0x8000;
        return;
    }
    abc->unk10 = 0;
    {
        s32 ff = 0xFF;
        D_800E33C4 = ff;
    }
    D_800E33B0 = 0;
    D_800E33B4 = 0;
    D_800E33B8 = 0;
    D_800E33BC = 0;
    D_800E33C0 = 0;
    abc->unkC = 0x80;
    abc->unkE = 0;
    if (arg2) {
        abc->unkA = 0x3C;
        abc->unkD = 6;
        return;
    }
    a = g_playthrough_state.enable_boss;
    b = g_playthrough_state.unk1F;
    dst = D_800E33D8;
    g_playthrough_state.unk1F = 0;
    g_playthrough_state.enable_boss = 0;
    D_800E3419 = a;
    D_800E3418 = b;
    if (g_wide_mode == 0) {
        src = (u16*)(SP_PALETTE_BASE + 0x2A0);
    } else {
        src = (u16*)(SP_PALETTE_BASE + 0xBC0);
    }
    for (i = 0; i < 0x20; i++) {
        *dst++ = *src++;
    }
    src = (u16*)&D_8006E408;
    if (g_wide_mode == 0) {
        load_palette(0x15, (s32*)src, 2);
    } else {
        load_palette(0x5E, (s32*)src, 2);
    }
    base = SP_MESSAGES;
    msg = (u16*)(base + ((s32*)base)[arg0]);
    abc->unk0 = msg;
    D_800E33C6 = *abc->unk0++;
    abc->unk4 = *abc->unk0;
    if (g_wide_mode == 0) {
        abc->unk6 = -0x80;
    } else {
        abc->unk6 = -0xE0;
    }
    if (g_playthrough_state.stage == 0xD) {
        abc->unk6 += 0x30;
    }
    abc->unk8 = 0x1D;
    abc->unkF = 1;
    ((s16*)abc)[9] = v = (abc->unk4 >> 9) & 3;
    func_80022838(v);
    D_800E33C8 = 0;
    if (g_playthrough_state.stage == 0xB) {
        abc->unkA = 1;
    } else {
        if (g_playthrough_state.stage != 0xF) {
            q = alloc_class6_slot();
            if (q != 0) {
                q->active = 0x1B;
                q->id = 2;
                q->unk2 = 0;
                if (!(abc->unk4 & 0x800)) {
                    q->ext.unk38 = 0;
                } else {
                    q->ext.unk38 = 0x78;
                }
            }
        }
        if (g_playthrough_state.stage == 0xB) {
            abc->unkA = 1;
        } else {
            abc->unkA = 0x32;
        }
    }
    abc->unkD = 0;
}
