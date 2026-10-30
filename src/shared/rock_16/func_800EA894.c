#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
void func_80027BA0(s32, s32, s32, void*);
void func_800F0DDC();
extern struct X4_BackgroundObj background_objects[3];
extern u16 g_pad1_buttons[];
extern struct X4_EngineObj g_playthrough_state;
extern u8 D_800F0BAC[];
extern u8 D_800F0BC4[][6][8];
extern s16 D_800F0DA4[][3];
extern s8 D_800F1CA0[];
extern u8 D_800F1CB7;
extern s8 D_800F1CB8[];
extern u8 D_800F1CC4[];

#define ENG_SEL (g_playthrough_state.character_state.bytes[1])
#define ENG_26 (g_playthrough_state.character_state.bytes[0])
#define ENG_66 ((u8)g_playthrough_state.character_state.bytes[0x40])

void func_800EA894(struct X4_EngineObj* arg0) {
    s8 old;
    s16 idx;

    old = ENG_SEL;
    switch (g_pad1_buttons[0] & 0xF000) {
    case 0x1000:
        if (old != 8 && ((g_pad1_buttons[0] ^ g_pad1_buttons[2]) & 0x1000)) {
            if (arg0->unk8 != 0) {
                arg0->unk8--;
            } else {
                {
                    s32 m;
                    if (arg0->unkA++ < 3) {
                        m = 30;
                        arg0->unk8 = m;
                    } else {
                        m = 10;
                        arg0->unk8 = m;
                    }
                }
                play_sound(5, 0, 0);
                if (ENG_SEL >= 4) {
                    ENG_SEL -= 4;
                } else {
                    ENG_SEL += 4;
                }
            }
        }
        break;
    case 0x4000:
        if (old != 8 && ((g_pad1_buttons[0] ^ g_pad1_buttons[2]) & 0x4000)) {
            if (arg0->unk8 != 0) {
                arg0->unk8--;
            } else {
                {
                    s32 m;
                    if (arg0->unkA++ < 3) {
                        m = 30;
                        arg0->unk8 = m;
                    } else {
                        m = 10;
                        arg0->unk8 = m;
                    }
                }
                play_sound(5, 0, 0);
                if (ENG_SEL < 4) {
                    ENG_SEL += 4;
                } else {
                    ENG_SEL -= 4;
                }
            }
        }
        break;
    case 0x2000:
        if ((g_pad1_buttons[0] ^ g_pad1_buttons[2]) & 0x2000) {
            if (arg0->unk8 != 0) {
                arg0->unk8--;
            } else {
                {
                    s32 m;
                    if (arg0->unkA++ < 3) {
                        m = 30;
                        arg0->unk8 = m;
                    } else {
                        m = 10;
                        arg0->unk8 = m;
                    }
                }
                play_sound(5, 0, 0);
                if (ENG_SEL == 8) {
                    ENG_SEL = 2;
                } else if (ENG_66 >= 3 && ENG_SEL == 1) {
                    ENG_SEL = 8;
                } else if (ENG_SEL == 3 || ENG_SEL == 7) {
                    ENG_SEL -= 3;
                } else {
                    ENG_SEL += 1;
                }
            }
        }
        break;
    case 0x8000:
        if ((g_pad1_buttons[0] ^ g_pad1_buttons[2]) & 0x8000) {
            if (arg0->unk8 != 0) {
                arg0->unk8--;
            } else {
                {
                    s32 m;
                    if (arg0->unkA++ < 3) {
                        m = 30;
                        arg0->unk8 = m;
                    } else {
                        m = 10;
                        arg0->unk8 = m;
                    }
                }
                play_sound(5, 0, 0);
                if (ENG_SEL == 8) {
                    ENG_SEL = 1;
                } else if (ENG_66 >= 3 && ENG_SEL == 2) {
                    ENG_SEL = 8;
                } else if (ENG_SEL == 0 || ENG_SEL == 4) {
                    ENG_SEL += 3;
                } else {
                    ENG_SEL -= 1;
                }
            }
        }
        break;
    default:
        arg0->unk8 = 0;
        arg0->unkA = 0;
        break;
    }

    if (g_pad1_buttons[2] & 0x840) {
        if (ENG_SEL == 8) {
            u8 t = ((u8*)arg0)[0x66];
            if (t == 3) {
                arg0->stage = 0x10;
            } else if (t == 4) {
                arg0->stage = 0x11;
            } else {
                arg0->stage = 0xC;
            }
        } else {
            arg0->stage = D_800F0BAC[ENG_SEL];
        }
        if (arg0->stage != 0) {
            arg0->substage = D_800F1CB7;
            play_sound(5, 1, 0);
            arg0->unk2++;
            ENG_26 = 1;
            arg0->unk8 = 0;
            D_800F1CC4[0] = 1;
            D_800F1CC4[1] = 1;
        }
    } else if (g_pad1_buttons[2] & 4) {
        play_sound(5, 0, 0);
        D_800F1CC4[0] = 2;
        D_800F1CC4[1] = 1;
        arg0->unk8 = 0;
        arg0->unkA = 0;
        arg0->unk1 = 5;
        arg0->unk2 = 0;
    } else if (g_pad1_buttons[2] & 8) {
        play_sound(5, 0, 0);
        D_800F1CC4[0] = 1;
        D_800F1CC4[1] = 2;
        arg0->unk8 = 0;
        arg0->unkA = 0;
        arg0->unk1 = 7;
        arg0->unk2 = 0;
    }

    if (old != ENG_SEL) {
        idx = D_800F0DA4[old][0];
        func_80027BA0(idx, D_800F0DA4[old][1], D_800F0DA4[old][2],
                      D_800F0BC4[D_800F1CA0[old]][D_800F1CB8[old]]);
        background_objects[idx].unk4C = 1;
        idx = D_800F0DA4[ENG_SEL][0];
        func_80027BA0(idx, D_800F0DA4[ENG_SEL][1], D_800F0DA4[ENG_SEL][2],
                      (u8*)D_800F0BC4 + D_800F1CA0[ENG_SEL] * 0x30 +
                          (D_800F1CB8[ENG_SEL] - 1) * 8);
        background_objects[idx].unk4C = 1;
        func_80027BA0(1, 0x410, 0x60,
                      (u8*)func_800F0DDC + D_800F1CA0[ENG_SEL] * 8);
        background_objects[1].unk4C = 1;
    }
}
