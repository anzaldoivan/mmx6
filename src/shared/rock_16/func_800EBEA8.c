#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
void func_80027BA0(s32, s32, s32, void*);
extern struct X4_BackgroundObj background_objects[3];
extern s8 D_80097244;
extern u16 g_pad1_buttons[];
extern struct X4_EngineObj g_playthrough_state;
extern u8 D_800F0E2C[];
extern u8 D_800F0E44[];
extern u8 D_800F0E64[];
extern s8 D_800F0EDC[];
extern u8 D_800F1CC4[];

#define ENG_29 (g_playthrough_state.character_state.bytes[3])
#define ENG_2A (g_playthrough_state.character_state.bytes[4])
#define PAIR(n, x0, x1, y, tbl, off)                                           \
    {                                                                          \
        u8* p = tbl;                                                           \
        func_80027BA0(n, x0, y, p + off);                                      \
        func_80027BA0(n, x1, y, p + off);                                      \
    }

void func_800EBEA8(struct X4_EngineObj* arg0) {
    s32 t;
    s8 old;

    t = g_pad1_buttons[2];
    if (t & 4) {
        play_sound(5, 0, 0);
        D_800F1CC4[4] = 2;
        D_800F1CC4[5] = 1;
        arg0->unk8 = 0;
        arg0->unkA = 0;
        arg0->unk1 = 7;
        arg0->unk2 = 0;
        t = 1;
    } else if (t & 8) {
        D_800F1CC4[4] = 1;
        D_800F1CC4[5] = 2;
        play_sound(5, 0, 0);
        t = 1;
        arg0->unk1 = 8;
        arg0->unk2 = 0;
        arg0->unk8 = 0;
    } else {
        t = 0;
    }
    if (t == 0) {
        old = ENG_29;
        if (g_pad1_buttons[2] & 0x5000) {
            if (ENG_29 != 0) {
                ENG_29 = 0;
            } else {
                ENG_29 = 1;
            }
        }
        if (old != ENG_29) {
            play_sound(5, 0, 0);
            if (ENG_29 != 0) {
                PAIR(0, 0x270, 0x870, 0x20, D_800F0E2C, 8);
                background_objects[0].unk4C = 1;
                PAIR(0, 0x270, 0x870, 0x50, D_800F0E44, 0);
                background_objects[0].unk4C = 1;
            } else {
                PAIR(0, 0x270, 0x870, 0x20, D_800F0E2C, 0);
                background_objects[0].unk4C = 1;
                PAIR(0, 0x270, 0x870, 0x50, D_800F0E44, 8);
                background_objects[0].unk4C = 1;
            }
            if (D_800F0EDC[((s8*)arg0 + ENG_29)[0x8D]] != 0) {
                PAIR(1, 0x2C0, 0x8C0, 0x20, D_800F0E64, 0);
                background_objects[1].unk4C = 1;
            } else {
                PAIR(1, 0x2C0, 0x8C0, 0x20, D_800F0E64, 8);
                background_objects[1].unk4C = 1;
            }
        }
        if (g_pad1_buttons[2] & 0x840) {
            play_sound(5, 1, 0);
            arg0->unk8 = 0;
            arg0->unk2++;
            ENG_2A = 0;
            if (ENG_29 != 0) {
                PAIR(0, 0x270, 0x870, 0x20, D_800F0E2C, 0x10);
                D_80097244 = 1;
            } else {
                PAIR(0, 0x270, 0x870, 0x50, D_800F0E44, 0x10);
                D_80097244 = 1;
            }
        }
    }
}
