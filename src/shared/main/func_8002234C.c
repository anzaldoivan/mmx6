#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/engine_state.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
s32 func_80021AF0(s32);
M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
void* alloc_sprite_slot();
extern u8 speaker_colors[];
extern u8 D_8006E484[];
extern u8 D_80071D70[];
extern u16 g_wide_mode;
extern u16 D_800C4570;
extern s8 D_800CCEDC;
extern u8 D_800E3148[][4];
extern struct X4_VisualObj* D_800E33B4;
extern struct X4_VisualObj* D_800E33B8;
extern s16 D_800E33C8;

#define B(p, o) (*(u8*)((u8*)(p) + (o)))
#define H(p, o) (*(u16*)((u8*)(p) + (o)))
#define SH(p, o) (*(s16*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))
#define P(p, o) (*(void**)((u8*)(p) + (o)))

void func_8002234C(u8* arg0) {
    struct X4_VisualObj* obj;
    s32 done;
    s16 n;
    s16 v;
    s32* q;
    s32 t;
    u8* tb;

    done = 0;
    do {
        H(arg0, 4) = **(u16**)arg0;
        if ((H(arg0, 4) & 0x1FF) != 0x1FF) {
            if (D_800E33C8 == 0 && D_800E33B4 == 0) {
                obj = alloc_sprite_slot();
                if (obj != 0) {
                    D_800E33B4 = obj;
                    obj->active = 9;
                    obj->id = 0x16;
                    obj->unk2 = 0;
                    obj->unk16 = 0x10;
                    /* PC-port shape: equal arms; the test leaves retail's dead g_wide_mode read. */
                    if (g_wide_mode == 0) {
                        obj->unk40 = 0x1F00;
                    } else {
                        obj->unk40 = 0x1F00;
                    }
                    obj->unk3C = D_800E3148;
                    if (g_wide_mode == 0) {
                        obj->unk42 = 0x7845;
                    } else {
                        obj->unk42 = 0x794E;
                    }
                    obj->bg_offset = -1;
                    /* x as an untyped s32 word, stored per arm: a union-member store lets sched hoist the
                     * g_wide_mode reload above it (fixed scalar vs varying struct) and the regs shift. */
                    if (g_playthrough_state.stage == 0xB) {
                        W(obj, 8) = 0xA80000;
                    } else {
                        W(obj, 8) = 0xA00000;
                    }
                    if (g_wide_mode == 1) {
                        obj->x_pos.u.hi += 0x60;
                    }
                    if (!(H(arg0, 4) & 0x800)) {
                        obj->y_pos.val = 0;
                    } else {
                        obj->y_pos.val = 0x780000;
                    }
                    if (g_playthrough_state.stage == 0xB) {
                        obj->y_pos.val = 0x840000;
                    } else if (g_playthrough_state.stage == 0xF) {
                        obj->y_pos.val = 0x780000;
                    }
                    obj->animation_step.fields.frame_index = 0;
                    obj->unk15 = 0;
                }
                tb = (u8*)D_800E3148;
                *(s16*)(tb + 2) = 1;
            }
            n = D_800E33C8;
            D_800E3148[n][4] = 0x20;
            D_800E3148[n][5] = H(arg0, 4);
            D_800E3148[n][4] |= (H(arg0, 4) & 0x100) >> 8;
            D_800E3148[n][6] = H(arg0, 6) >> 1;
            D_800E3148[n][4] |= (B(arg0, 6) & 1) << 7;
            D_800E3148[n][7] = B(arg0, 8);
            *(s16*)D_800E3148 = ++D_800E33C8;
            if (SH(arg0, 8) == 0x1D) {
                D_800E3148[D_800E33C8 - 1][4] |= 4;
                v = (H(arg0, 4) >> 9) & 3;
                if (SH(arg0, 0x12) != v) {
                    SH(arg0, 0x12) = v;
                    q = (s32*)(D_8006E484 +
                               speaker_colors[func_80021AF0(v)] * 32);
                    if (g_wide_mode == 0) {
                        load_palette(0x16, q, 1);
                    } else {
                        load_palette(0x5F, q, 1);
                    }
                }
            }
        } else {
            done = 1;
        }
        P(arg0, 0) = (u16*)P(arg0, 0) + 1;
        if (H(arg0, 4) & 0x4000) {
            t = g_wide_mode;
            H(arg0, 8) += 0x10;
            if (t == 0) {
                SH(arg0, 6) = -0x80;
            } else {
                SH(arg0, 6) = -0xE0;
            }
            if (g_playthrough_state.stage == 0xD) {
                H(arg0, 6) += 0x30;
            }
        } else {
            H(arg0, 6) += 0xB;
            if ((H(arg0, 4) & 0x1FF) < 0x40) {
                H(arg0, 6) += 1;
            }
        }
        if (B(arg0, 0xF) == 0) {
            H(arg0, 4) &= 0xEFFF;
        }
    } while (!(H(arg0, 4) & 0xB000));

    if (done == 0 && D_800CCEDC != 0xB) {
        play_sound(0, 0xE, 0);
    }
    if ((H(arg0, 4) & 0xB000) == 0x1000) {
        if ((u8)D_800C4570 != 0) {
            if (B(arg0, 0xF) != 0) {
                B(arg0, 0xF)--;
            }
        }
        SH(arg0, 0xA) = 4;
        B(arg0, 0xD) = 2;
    } else {
        B(arg0, 0xF) = 2;
        if (H(arg0, 4) & 0x2000) {
            obj = alloc_sprite_slot();
            if (obj != 0) {
                D_800E33B8 = obj;
                obj->active = 9;
                obj->id = 0x16;
                obj->unk2 = 1;
                obj->unk16 = 0x10;
                if (g_wide_mode == 0) {
                    obj->unk40 = 0x1F00;
                } else {
                    obj->unk40 = 0x1F00;
                }
                obj->unk3C = D_80071D70;
                if (g_wide_mode == 0) {
                    obj->unk42 = 0x7845;
                } else {
                    obj->unk42 = 0x794E;
                }
                obj->bg_offset = -1;
                obj->x_pos.u.hi = 0x98;
                if (g_wide_mode == 1) {
                    obj->x_pos.u.hi = 0xF8;
                }
                if (!(H(arg0, 4) & 0x800)) {
                    obj->y_pos.u.hi = 0x51;
                } else {
                    obj->y_pos.u.hi = 0xC5;
                }
                if (D_800CCEDC == 0xB) {
                    obj->y_pos.u.hi = 0xD5;
                } else if (D_800CCEDC == 0xF) {
                    obj->y_pos.u.hi = 0xC5;
                }
                obj->animation_step.fields.frame_index = 0;
                obj->unk15 = 0;
                *(u8*)&obj->unk54 = 0;
                obj->unk56 = 0x20;
            }
        }
        B(arg0, 0xC) = 0xFF;
        B(arg0, 0xD) = 3;
    }
}
