#include "common.h"

extern u8 menu_armor_slots[];
extern u8 D_800F1CEB;

void func_800E9898(u8* arg0) {
    D_800F1CEB = 1;
    menu_armor_slots[0] = 0;
    if (arg0[0x5F] & 1) {
        D_800F1CEB = 2;
        menu_armor_slots[1] = 1;
    }
    if (arg0[0x5F] & 0x10) {
        menu_armor_slots[D_800F1CEB++] = 5;
    }
    if (arg0[0x5F] & 2) {
        menu_armor_slots[D_800F1CEB++] = 2;
    }
    if (arg0[0x5F] & 4) {
        menu_armor_slots[D_800F1CEB++] = 3;
    }
    if (arg0[0x5F] & 8) {
        menu_armor_slots[D_800F1CEB++] = 4;
    }
}

#include "common.h"

extern s32 D_800F0E74[];
extern s8 D_800F0ED4[];
extern s8 D_800F1C80[];
extern s8 D_800F1CD0[][5];

void func_800E99A4(u8* arg0) {
    s32* flags;
    s32* q;
    s8* d;
    s8* idx;
    s32 i;
    s32 j;
    s32 n;

    for (j = 0; j < 5; j++) {
        D_800F1CD0[0][j] = -1;
        D_800F1CD0[1][j] = -1;
    }

    flags = (s32*)(arg0 + 0x74);
    idx = (s8*)(arg0 + 0x8D);
    for (i = 0; i < 2; i++) {
        n = 0;
        for (j = 0; j < 0x12; j++) {
            if ((flags[i] & D_800F0E74[j]) && n < D_800F0ED4[idx[i]]) {
                D_800F1CD0[i][n] = j;
                n++;
            }
        }
        D_800F1C80[i] = n;
    }
    i = 0;
    q = flags;
    flags = 0;
    for (; i < 2; i++) {
        for (j = 0x12; j < 0x18; j++) {
            if (*(s32*)((u8*)q + (i << 2)) & D_800F0E74[j]) {
                D_800F1CD0[i][4] = j;
            }
        }
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_16/nonmatchings/E9860", func_800E9AF8);
// clang-format on

#include "common.h"

void* alloc_sprite_slot();
extern s32 D_800F0E74[];
extern u8 D_800F0EEC[];
extern u8 D_800F0EF4[];

void func_800E9F70(u8* arg0) {
    u8* obj;
    s32 i;

    if (arg0[0x5F] & 0x10) {
        for (i = 0; i < 2; i++) {
            obj = alloc_sprite_slot();
            if (obj != 0) {
                obj[0] = 1;
                obj[1] = 0x18;
                obj[2] = i;
            }
        }
    }
    for (i = 0; i < 0x18; i++) {
        if (*(s32*)(arg0 + 0x70) & D_800F0E74[i]) {
            obj = alloc_sprite_slot();
            if (obj != 0) {
                obj[0] = 1;
                obj[1] = 0x28;
                obj[2] = i;
            }
        }
    }
    for (i = 0; i < 8; i++) {
        if (arg0[0x69] & D_800F0EEC[i]) {
            obj = alloc_sprite_slot();
            if (obj != 0) {
                obj[0] = 1;
                obj[1] = 0x28;
                obj[2] = i + 0x18;
            }
        }
    }
    for (i = 0; i < 6; i++) {
        obj = alloc_sprite_slot();
        if (obj != 0) {
            obj[0] = 1;
            obj[1] = 0x28;
            obj[2] = i + 0x20;
        }
    }
    for (i = 0; i < 2; i++) {
        obj = alloc_sprite_slot();
        if (obj != 0) {
            obj[0] = 1;
            obj[1] = 0x28;
            obj[2] = i + 0x26;
        }
    }
    for (i = 0; i < 5; i++) {
        obj = alloc_sprite_slot();
        if (obj != 0) {
            obj[0] = 1;
            obj[1] = 0x28;
            obj[2] = i + 0x28;
        }
    }
    for (i = 0; i < 5; i++) {
        obj = alloc_sprite_slot();
        if (obj != 0) {
            obj[0] = 1;
            obj[1] = 0x28;
            obj[2] = i + 0x2D;
        }
    }
    for (i = 0; i < 5; i++) {
        obj = alloc_sprite_slot();
        if (obj != 0) {
            obj[0] = 1;
            obj[1] = 0x28;
            obj[2] = i + 0x32;
        }
    }
    for (i = 0; i < 2; i++) {
        obj = alloc_sprite_slot();
        if (obj != 0) {
            obj[0] = 1;
            obj[1] = 0x28;
            obj[2] = i + 0x37;
        }
    }
    for (i = 0; i < 4; i++) {
        if (arg0[0x5F] & D_800F0EF4[i]) {
            obj = alloc_sprite_slot();
            if (obj != 0) {
                obj[0] = 1;
                obj[1] = 0x28;
                obj[2] = i + 0x39;
            }
        }
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_16/nonmatchings/E9860", func_800EA27C);

INCLUDE_ASM("asm/rock_16/nonmatchings/E9860", func_800EA3FC);
// clang-format on

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

#include "common.h"

#define FX(p, type, off) (*(type*)((u8*)(p) + (off)))

void* alloc_sprite_slot();
extern s8 D_800F0F00[];
extern s8 D_800F0F08[];
extern u8 D_800F1CA9;
extern u8 D_800F1CF0[];

void func_800EAEF8(void* arg0) {
    // !FAKE: depin: dropping it breaks the match (89/98)
    register s32 tbl asm("$2");
    s32 idx;
    s8* p;
    s8* o;
    s32 a;
    s32 b;
    s32 n;

    if (D_800F1CA9 >= 9) {
        tbl = (s32)D_800F0F08;
        idx = FX(arg0, s16, 0xA) * 2;
    } else {
        tbl = (s32)D_800F0F00;
        idx = FX(arg0, s16, 0xA) * 2;
    }
    p = (s8*)(idx + tbl);
    a = *p;
    {
        s32 j = idx + 1;
        b = *(s8*)(j + tbl);
    }
    do {
    } while (0);
    if (FX(arg0, s16, 0x8) == 0) {
        o = alloc_sprite_slot(p);
        if (o != 0) {
            o[0] = 1;
            o[1] = 0xC;
            o[2] = a | 0x20;
        }
        if (b != -1) {
            o = alloc_sprite_slot();
            if (o != 0) {
                o[0] = 1;
                o[1] = 0xC;
                o[2] = b | 0x20;
            }
        }
    }
    FX(arg0, s16, 0x8)++;
    if (FX(arg0, s16, 0x8) >= 4) {
        D_800F1CF0[a] = 0;
        if (b != -1) {
            D_800F1CF0[b] = 0;
        }
        FX(arg0, s16, 0x8) = 0;
        n = (u16)FX(arg0, s16, 0xA) + 1;
        FX(arg0, s16, 0xA) = n;
        if (D_800F1CA9 >= 9) {
            if ((s16)n >= 5) {
                goto block;
            }
            return;
        }
        if ((s16)n >= 4) {
        block:
            FX(arg0, s16, 0xA) = 0;
            FX(arg0, u8, 0x2)++;
        }
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
extern u16 g_pad1_buttons[];
extern struct X4_EngineObj g_playthrough_state;
extern u8 menu_armor_slots[];
extern u8 D_800F1CEB;

#define EB080_SEL (g_playthrough_state.character_state.bytes[10])
#define EB080_DIR (g_playthrough_state.character_state.bytes[11])
#define EB080_DONE (g_playthrough_state.character_state.bytes[12])
#define EB080_F(o, t) (*(t*)((u8*)arg0 + (o)))

void func_800EB080(void* arg0) {
    s32 old;

    old = EB080_SEL;
    if (g_pad1_buttons[2] & 0x8000) {
        EB080_DIR = 1;
        EB080_SEL--;
        if (EB080_SEL < 0) {
            EB080_SEL = D_800F1CEB - 1;
        }
    } else if (g_pad1_buttons[2] & 0x2000) {
        EB080_DIR = 2;
        EB080_SEL++;
        if (EB080_SEL >= D_800F1CEB) {
            EB080_SEL = 0;
        }
    }
    if (old != EB080_SEL) {
        play_sound(5, 0, 0);
        EB080_F(0x8, s16) = 0;
        EB080_F(0x2, u8) += 1;
        return;
    }
    if (g_pad1_buttons[2] & 0x840) {
        u8 v = menu_armor_slots[old];
        EB080_F(0x5E, u8) = v;
        if (v == 5) {
            EB080_F(0x38, u8) = 1;
        } else {
            EB080_F(0x38, u8) = 0;
        }
        play_sound(5, 1, 0);
        EB080_DIR = 3;
        EB080_F(0x8, s16) = 0;
        EB080_F(0x2, u8) += 2;
        return;
    }
    if (g_pad1_buttons[2] & 0x10) {
        EB080_F(0x2, u8) = 9;
        EB080_DONE = 1;
        EB080_F(0x8, s16) = 0;
    }
}

#include "common.h"
#include "psyq/libgpu.h"
#define M2C_UNK s32

void func_8001D218();
M2C_UNK reset_level();
s32 func_80042F50(s32, s32);
void func_80042F7C(s8 arg0, s8* arg1, s8* arg2);

#include "mmx6/state.h"
extern M2C_UNK* D_800B91B8;
extern M2C_UNK D_800F0EE4;
extern s8 D_800F0F14[];

static inline void clr(s8* base, s32 idx) {
    s32 i;
    for (i = 0; i < 32; i++) {
        base[idx * 32 + i] = 0;
    }
}

#define A(n) clr(self + 0x178, func_80042F50((n), 0))
#define C(n) clr(self + 0x178, func_80042F50((n), 1))

static inline void pair(s8* self, s32 n) {
    s8 x;
    s8 y;
    func_80042F7C(n, &x, &y);
    clr(self + 0x178, func_80042F50(x, y));
}
#define B(n) pair(self, (n))

void func_800EB1FC(s8* self) {
    s32 i;
    s8* p;
    s32 idx;
    s8* q;
    s8* r;
    s8 x;
    s8 y;
    s8 v;

    if (D_80097420.transition.active == 0) {
        LoadImage(&D_800F0EE4, D_800B91B8);
        DrawSync(0);
        for (i = 15, p = self + 0x35; i >= 0; i--) {
            *p-- = 0;
        }
        self[0x464] = 0;
        func_8001D218();
        reset_level();
        if ((u8)(self[0xC] - 1) < 8) {
            for (i = 0; i < 3; i++) {
                v = D_800F0F14[i + (self[0xC] - 1) * 3];
                q = self + 0x168;
                q[v] = self[0xC];
                r = self + 0x465;
                r[i] = v;
            }
            switch (self[0xC]) {
            case 1:
                A(3);
                B(3);
                A(7);
                B(7);
                break;
            case 2:
                A(4);
                B(4);
                C(4);
                break;
            case 3:
                A(2);
                B(2);
                A(8);
                B(8);
                break;
            case 4:
                A(3);
                B(3);
                A(5);
                B(5);
                A(8);
                B(8);
                break;
            case 5:
                A(4);
                B(4);
                C(4);
                A(7);
                B(7);
                break;
            case 6:
                A(1);
                B(1);
                A(5);
                B(5);
                break;
            case 7:
                A(2);
                B(2);
                A(6);
                B(6);
                break;
            case 8:
                A(1);
                B(1);
                A(6);
                B(6);
                break;
            }
        }
        if (self[0xC] >= 9) {
            self[0] = 7;
        } else if (((u8)self[0x60] >> (self[0xC] - 1)) & 1) {
            self[0] = 7;
        } else {
            self[0] = 5;
        }
        self[1] = 0;
        self[2] = 0;
        self[3] = 0;
    }
}

#include "common.h"

void* alloc_sprite_slot();
extern s8 D_800F0F2C[];
extern s8 D_800F0F34[];
extern u8 D_800F1CA9;
extern u8 D_800F1CF0[];

void func_800EBACC(u8* arg0) {
    s8 a;
    s8 b;
    u8* obj;

    if (D_800F1CA9 >= 9) {
        a = D_800F0F34[*(s16*)(arg0 + 0xA) * 2];
        b = D_800F0F34[*(s16*)(arg0 + 0xA) * 2 + 1];
    } else {
        a = D_800F0F2C[*(s16*)(arg0 + 0xA) * 2];
        b = D_800F0F2C[*(s16*)(arg0 + 0xA) * 2 + 1];
    }
    if (*(s16*)(arg0 + 8) == 0) {
        obj = alloc_sprite_slot();
        if (obj != 0) {
            obj[0] = 1;
            obj[1] = 0xC;
            obj[2] = a | 0x40;
        }
        if (b != -1) {
            obj = alloc_sprite_slot();
            if (obj != 0) {
                obj[0] = 1;
                obj[1] = 0xC;
                obj[2] = b | 0x40;
            }
        }
        D_800F1CF0[a] = 1;
        if (b != -1) {
            D_800F1CF0[b] = 1;
        }
    }
    if (++*(s16*)(arg0 + 8) >= 4) {
        *(s16*)(arg0 + 8) = 0;
        ++*(s16*)(arg0 + 0xA);
        if (D_800F1CA9 >= 9) {
            if (*(s16*)(arg0 + 0xA) >= 5) {
                goto block;
            }
            return;
        }
        if (*(s16*)(arg0 + 0xA) >= 4) {
        block:
            *(s16*)(arg0 + 0xA) = 0;
            arg0[2]++;
        }
    }
}

#include "common.h"
#include "mmx6/x4.h"

void func_80027BA0(s32, s32, s32, void*);
extern struct X4_BackgroundObj background_objects[3];
extern s8 D_800CCEF7;
extern u8 D_800F0BC4[][6][8];
extern s16 D_800F0DA4[][3];
extern s8 D_800F1CA0[];
extern s8 D_800F1CB8[];
extern u8 D_800F1CC4[];
extern u8 D_800F1CF9;

void func_800EBC5C(struct X4_EngineObj* arg0) {
    s16 idx;
    s32 sel;

    if (++arg0->unk8 >= 5) {
        sel = D_800CCEF7;
        idx = D_800F0DA4[sel][0];
        func_80027BA0(idx, D_800F0DA4[sel][1], D_800F0DA4[sel][2],
                      (u8*)D_800F0BC4 + D_800F1CA0[sel] * 0x30 +
                          (D_800F1CB8[sel] - 1) * 8);
        background_objects[idx].unk4C = 1;
        D_800F1CF9 = 1;
        arg0->unk8 = 0;
        arg0->unk2 = 0;
        D_800F1CC4[0] = 0;
        D_800F1CC4[1] = 0;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_80027BA0(s32, s32, s32, void*);
extern struct X4_BackgroundObj background_objects[3];
extern s8 D_800CCEF9;
extern u8 D_800F0E2C[];
extern u8 D_800F0E44[];

#define PAIR_EBD6C(y, tbl, off)                                                \
    {                                                                          \
        u8* p = tbl;                                                           \
        func_80027BA0(0, 0x270, y, p + off);                                   \
        func_80027BA0(0, 0x870, y, p + off);                                   \
    }

void func_800EBD6C(struct X4_EngineObj* arg0) {
    if (arg0->unk5F & 0x10) {
        if (D_800CCEF9 != 0) {
            PAIR_EBD6C(0x20, D_800F0E2C, 8);
            background_objects[0].unk4C = 1;
            PAIR_EBD6C(0x50, D_800F0E44, 0);
            background_objects[0].unk4C = 1;
        } else {
            PAIR_EBD6C(0x20, D_800F0E2C, 0);
            background_objects[0].unk4C = 1;
            PAIR_EBD6C(0x50, D_800F0E44, 8);
            background_objects[0].unk4C = 1;
        }
    }
}

#undef PAIR_EBD6C

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
extern s8 part_slots_by_rank[];
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
            if (part_slots_by_rank[((s8*)arg0 + ENG_29)[0x8D]] != 0) {
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

#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EngineObj g_playthrough_state;
extern s8 D_800CCEF9;
extern s8 part_slots_by_rank[];
extern s8 D_800F0F80[][0x18];

s32 func_800EC1FC(s32 arg0) {
    if (D_800F0F80[0][arg0] != 0) {
        return D_800CCEF9 != 0;
    }
    if (D_800F0F80[1][arg0] != 0) {
        return D_800CCEF9 != 1;
    }
    if (D_800F0F80[2][arg0] != 0) {
        return part_slots_by_rank[(
                   (s8*)&g_playthrough_state +
                   g_playthrough_state.character_state.bytes[3])[0x8D]] == 0;
    }
    return 0;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
extern u16 D_800C4570;
extern struct X4_EngineObj g_playthrough_state;
extern s8 D_800F0FC8[][0x18];

#define EC28C_ENG_2A (g_playthrough_state.character_state.bytes[4])

void func_800EC28C(void* arg0) {
    s32 old;

    old = EC28C_ENG_2A;
    if (D_800C4570 & 0x8000) {
        EC28C_ENG_2A = D_800F0FC8[0][old];
    } else if (D_800C4570 & 0x2000) {
        EC28C_ENG_2A = D_800F0FC8[1][old];
    } else if (D_800C4570 & 0x1000) {
        EC28C_ENG_2A = D_800F0FC8[2][old];
    } else if (D_800C4570 & 0x4000) {
        EC28C_ENG_2A = D_800F0FC8[3][old];
    }
    if (old != EC28C_ENG_2A) {
        play_sound(5, 0, 0);
    }
}

#undef EC28C_ENG_2A

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
void* alloc_sprite_slot();
s32 func_800EC1FC(s32);
extern u16 D_800C4570;
extern struct X4_EngineObj g_playthrough_state;
extern s32 D_800F0E74[];
extern s8 D_800F0ED4[];
extern s8 D_800F1C80[];
extern s8 D_800F1CD0[][5];
extern s8 D_800F1CEA;

#define EC35C_ENG_29 (g_playthrough_state.character_state.bytes[3])
#define EC35C_ENG_2A (g_playthrough_state.character_state.bytes[4])
#define EC35C_F(o, t) (*(t*)((u8*)arg0 + (o)))

void func_800EC35C(void* arg0) {
    s32* p;
    s32* q;
    s32 a;
    s32 b;
    u8* o;
    s32 t;

    if (D_800C4570 & 0x840) {
        play_sound(5, 1, 0);
        if ((EC35C_F(0x70, s32) & D_800F0E74[EC35C_ENG_2A]) &&
            func_800EC1FC(EC35C_ENG_2A) == 0) {
            q = (s32*)((u8*)arg0 + 0x74);
            p = q + EC35C_ENG_29;
            a = *p;
            b = D_800F0E74[EC35C_ENG_2A];
            if (a & b) {
                *p = a & ~b;
                D_800F1CEA = 1;
                goto after;
            }
            if (EC35C_ENG_2A >= 0x12
                    ? D_800F1CD0[EC35C_ENG_29][4] == -1
                    : D_800F1C80[EC35C_ENG_29] <
                          D_800F0ED4[((s8*)arg0 + EC35C_ENG_29)[0x8D]]) {
                goto orarm;
            }
        }
        D_800F1CEA = 2;
        goto after;
    orarm:
        *p = a | b;
        D_800F1CEA = 1;
    after:
        t = 1;
        EC35C_F(2, u8) = t;
        if (D_800F1CEA == 2) {
            o = alloc_sprite_slot();
            if (o != 0) {
                o[0] = 1;
                o[1] = 0x28;
                o[2] = 0x3D;
            }
        }
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
void func_800EC28C(void*);
void func_800EC35C(void* arg0);
extern u16 g_pad1_buttons[];
extern u8 D_800F1CC4[];

void func_800EC508(struct X4_EngineObj* arg0) {
    s32 t;

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
        if (g_pad1_buttons[2] & 0x10) {
            if (arg0->unk5F & 0x10) {
                play_sound(5, 1, 0);
            }
            arg0->unk1 = 5;
            arg0->unk2 = 0;
        }
        func_800EC28C(arg0);
        func_800EC35C(arg0);
    }
}

#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj background_objects[3];
extern u8 D_800F1CC4[];

void func_800EC634(struct X4_EngineObj* arg0) {
    s16 d;

    if (background_objects[1].x_pos.i.hi > 0x400) {
        background_objects[1].x_pos.i.hi -= 0x200;
    } else {
        background_objects[1].x_pos.i.hi += 0x200;
    }
    d = (background_objects[1].x_pos.i.hi - 0x400 < 0)
            ? 0x400 - background_objects[1].x_pos.i.hi
            : background_objects[1].x_pos.i.hi - 0x400;
    if (d < 0x200) {
        D_800F1CC4[2] = 1;
        D_800F1CC4[5] = 1;
        D_800F1CC4[0] = 0;
        D_800F1CC4[1] = 0;
        background_objects[1].x_pos.i.hi = 0x400;
        background_objects[1].unk4C = 1;
        arg0->unk1 = 4;
        arg0->unk2 = 0;
        background_objects[2].unk3 = 1;
    }
    background_objects[0].x_pos.i.hi = background_objects[1].x_pos.i.hi;
    background_objects[0].unk4C = background_objects[1].unk4C;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
extern u16 g_pad1_buttons[];
extern s8 D_800CCEFB;
extern u8 D_800F1CC4[];
extern s8 D_800F1CCA[];

void func_800EC6E8(struct X4_EngineObj* arg0) {
    // !FAKE: depin: dropping it breaks the match (89/92)
    register s32 v asm("$3");

    if (g_pad1_buttons[2] & 0x5000) {
        play_sound(5, 0, 0);
        D_800F1CC4[2] = 1;
        D_800F1CC4[3] = 1;
        if (g_pad1_buttons[2] & 0x1000) {
            D_800F1CCA[0] = 2;
            D_800F1CCA[1] = 1;
            arg0->unk3 = D_800CCEFB;
            if (arg0->unk3 == 0) {
                arg0->unk3 = 7;
            } else {
                arg0->unk3 = arg0->unk3 - 1;
            }
        } else {
            D_800F1CCA[0] = 1;
            D_800F1CCA[1] = 2;
            arg0->unk3 = D_800CCEFB;
            if (arg0->unk3 >= 7) {
                arg0->unk3 = 0;
            } else {
                arg0->unk3 = arg0->unk3 + 1;
            }
        }
        arg0->unk8 = 0;
        arg0->unk2++;
        return;
    }
    if (g_pad1_buttons[2] & 4) {
        D_800F1CC4[2] = 2;
        D_800F1CC4[3] = 1;
        play_sound(5, 0, 0);
        v = 8;
    } else if (g_pad1_buttons[2] & 8) {
        D_800F1CC4[2] = 1;
        D_800F1CC4[3] = 2;
        play_sound(5, 0, 0);
        v = 5;
    } else {
        return;
    }
    arg0->unk1 = v;
    arg0->unk2 = 0;
    arg0->unk8 = 0;
}

#include "common.h"

extern void (*D_800F1068[])(u8*);
void func_8002048C(void);
void func_800207D4(void);
void func_80020378(void);
void func_800206C0(void);
void run_text_box(void);
void func_8002ACA8();
void func_80025FB0();

void func_800EC858(u8* arg0) {
    D_800F1068[*(s8*)(arg0 + 1)](arg0);
    func_8002048C();
    func_800207D4();
    func_80020378();
    func_800206C0();
    run_text_box();
    func_8002ACA8();
    func_80025FB0();
}

#include "common.h"
#include "mmx6/x4.h"

void func_80027C98(s32 arg0, s16 arg1, s16 arg2, u16* arg3);
extern struct X4_BackgroundObj background_objects[3];
extern u8 D_800F0BC4[][6][8];
// !FAKE: rect-row alias of the TU's u8 D_800F0BC4[][6][8]; a cast view folds +6 into the symbol
extern X4_RECT D_800F0BC4_r[][6];
#define D_800F0BC4 D_800F0BC4_r
extern s16 D_800F0DA4[][3];

void func_800EC8CC(s32 arg0) {
    X4_RECT rect;
    s16 idx;

    idx = D_800F0DA4[arg0][0];
    rect.w = D_800F0BC4[arg0][0].w;
    rect.h = D_800F0BC4[arg0][0].h;
    func_80027C98(idx, D_800F0DA4[arg0][1], D_800F0DA4[arg0][2], (u16*)&rect);
    background_objects[idx].unk4C = 1;
}
#undef D_800F0BC4

// clang-format off
INCLUDE_ASM("asm/rock_16/nonmatchings/E9860", func_800EC96C);
// clang-format on

#include "common.h"
#include "psyq/libgpu.h"
#define M2C_UNK s32

M2C_UNK reset_level();
void func_8002C2B8();
void init_checkpoint_positions(void);
void func_800280F4(void);
M2C_UNK func_80025F34();

extern M2C_UNK* D_800B91B8;
extern u8 D_800CC868;
extern M2C_UNK D_800F0EE4;
extern u8 D_800F1CB6;
extern u8 D_800F1CB7;

#define SCRATCH_44 (*(M2C_UNK**)0x1F800044)

void func_800ECA28(u8* arg0) {
    u8* p;
    u32 i;

    D_80097420.character_mode = 0;
    i = 0;
    p = arg0 + 0x26;
    do {
        p[i] = 0;
        i++;
    } while (i < 0x10);
    arg0[0x1F] = 0;
    arg0[0x24] = 0;
    *(s16*)(arg0 + 8) = 0;
    *(s16*)(arg0 + 0xA) = 0;
    reset_level(p);
    func_8002C2B8();
    init_checkpoint_positions();
    func_800280F4();
    func_80025F34();
    D_800F1CB6 = 0;
    D_800F1CB7 = 0;
    arg0[2] = 0;
    arg0[3] = 0;
    D_800CC868 = 0;
    arg0[1] = 1;
    StoreImage(&D_800F0EE4, D_800B91B8);
    DrawSync(0);
    LoadImage(&D_800F0EE4, SCRATCH_44);
    DrawSync(0);
}

#include "common.h"

void func_800ECB04(u8* arg0) {
    s32 t;

    if (D_80097420.transition.active == 0) {
        if (arg0[0x66] == 1) {
            arg0[1] = 9;
        } else {
            t = arg0[0x158];
            if (t < 8) {
                if (t >= 6) {
                    arg0[1] = 0xA;
                    arg0[2] = 0;
                    arg0[0x158] = 0xFF;
                    return;
                }
            }
            if (arg0[0x43B] != 0) {
                arg0[1] = 3;
            } else if (arg0[0x5F] & 0x10) {
                arg0[1] = 0xB;
            } else {
                arg0[1] = 3;
            }
        }
        arg0[2] = 0;
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern u8 D_800F1C90[];
extern u8 D_800F1CA9;

void func_800ECB90(void* arg0) {
    s32 i;
    M2C_FIELD(arg0, s16*, 8) = 0;
    M2C_FIELD(arg0, s16*, 0xA) = 0;
    M2C_FIELD(arg0, u8*, 2) = (u8)(M2C_FIELD(arg0, u8*, 2) + 1);
    for (i = 0; i < 9; i++) {
        D_800F1C90[i] = 0;
    }
    if (M2C_FIELD(arg0, u8*, 0x66) >= 3U) {
        D_800F1CA9 = 9;
        return;
    }
    D_800F1CA9 = 8;
}

#define func_80041AB8 func_800ECBF0
#define D_80075FD8 D_800F0EF8
#define FAMILY_FIELD 2
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#include "common.h"
#include "mmx6/x4.h"

extern s8 D_800CCEF6;
extern u8 D_800F1CF9;

void func_800ECC2C(struct X4_EngineObj* arg0) {
    arg0->unk8++;
    if ((s16)arg0->unk8 >= 8) {
        D_800CCEF6 = 0;
        D_800F1CF9 = 0;
        arg0->unk8 = 0;
        arg0->unkA = 0;
        arg0->unk2++;
    }
}

#include "common.h"

void func_800ECC78(void* arg0) {
    s32 temp_v0;

    temp_v0 = *(u16*)((u8*)arg0 + 8) + 1;
    *(u16*)((u8*)arg0 + 8) = temp_v0;
    if ((s16)temp_v0 >= 5) {
        *(u16*)((u8*)arg0 + 8) = 0;
        ((u8*)arg0)[2]++;
    }
}

#include "common.h"
#include "mmx6/x4.h"

#define FX(p, type, off) (*(type*)((u8*)(p) + (off)))

void* alloc_sprite_slot();
extern struct X4_EngineObj g_playthrough_state;
extern u8 menu_armor_slots[];

void func_800ECCB4(void* arg0) {
    u8 i;
    u8 v;
    s8* o;

    i = menu_armor_slots[1];
    g_playthrough_state.character_state.bytes[11] = 0;
    g_playthrough_state.character_state.bytes[12] = 0;
    g_playthrough_state.character_state.bytes[10] = i;
    v = menu_armor_slots[(s8)i];
    g_playthrough_state.character_state.bytes[2] = v;
    do {
        o = alloc_sprite_slot(arg0, &g_playthrough_state, v, i);
    } while (0);
    if (o != 0) {
        o[0] = 1;
        o[1] = 0x2B;
        o[2] = 0;
    }
    o = alloc_sprite_slot(o);
    if (o != 0) {
        o[0] = 1;
        o[1] = 0x2B;
        o[2] = 1;
    }
    o = alloc_sprite_slot(o);
    if (o != 0) {
        o[0] = 1;
        o[1] = 0x2B;
        o[2] = 2;
    }
    FX(arg0, u8, 2)++;
}

#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EngineObj g_playthrough_state;
extern u8 menu_armor_slots[];

void func_800ECD80(u8* arg0) {
    if (++*(s16*)(arg0 + 8) >= 8) {
        *(s16*)(arg0 + 8) = 0;
        g_playthrough_state.character_state.bytes[11] = 0;
        g_playthrough_state.character_state.bytes[2] =
            menu_armor_slots[g_playthrough_state.character_state.bytes[10]];
        arg0[2]--;
    }
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800139F4(M2C_UNK);
extern s8 D_800CCF01;

void func_800ECDE4(u8* arg0) {
    if ((s16)++ * (u16*)(arg0 + 8) >= 8) {
        *(u16*)(arg0 + 8) = 0;
        D_800CCF01 = 0;
        ((void (*)(s32))func_800139F4)(8);
        arg0[2]++;
    }
}

#define func_80041AB8 func_800ECE48
#define D_80075FD8 D_800F0F40
#define FAMILY_FIELD 2
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#include "common.h"
#include "mmx6/x4.h"

void func_800EBD6C(struct X4_EngineObj* arg0);
extern s16 D_80097256;
extern u8 D_800F1CC4[];

void func_800ECE84(struct X4_EngineObj* arg0) {
    if (D_80097256 == 0x200) {
        arg0->unk2 += 2;
        func_800EBD6C(arg0);
        return;
    }
    if (++arg0->unk8 >= 8) {
        arg0->unk8 = 0;
        D_800F1CC4[0] = 0;
        D_800F1CC4[3] = 0;
        arg0->unk2++;
        func_800EBD6C(arg0);
    }
}

#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj background_objects[3];
extern u8 D_800F1CC4[];

void func_800ECF14(struct X4_EngineObj* arg0) {
    if (background_objects[1].x_pos.i.hi >= 0x600) {
        background_objects[1].x_pos.i.hi += 0x200;
    } else {
        background_objects[1].x_pos.i.hi -= 0x200;
    }
    if ((u16)background_objects[1].x_pos.i.hi - 0x201 >= 0x5FFU) {
        D_800F1CC4[0] = 1;
        D_800F1CC4[3] = 1;
        D_800F1CC4[4] = 0;
        D_800F1CC4[5] = 0;
        background_objects[1].x_pos.i.hi = 0x200;
        background_objects[1].unk4C = 1;
        arg0->unk2++;
    }
    background_objects[0].x_pos.i.hi = background_objects[1].x_pos.i.hi;
    background_objects[0].unk4C = background_objects[1].unk4C;
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s8 D_800972A3;

void func_800ECFA0(void* arg0) {
    D_800972A3 = 0;
    if (!(M2C_FIELD(arg0, u8*, 0x5F) & 0x10)) {
        M2C_FIELD(arg0, s8*, 1) = 6;
        M2C_FIELD(arg0, u8*, 2) = 0U;
        M2C_FIELD(arg0, s16*, 8) = 0;
        return;
    }
    M2C_FIELD(arg0, u8*, 2) = (u8)(M2C_FIELD(arg0, u8*, 2) + 1);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
extern u16 D_800C4570;
extern u8 D_800F1CC4[];

void func_800ECFE0(struct X4_EngineObj* arg0) {
    s32 t;
    s32 v;

    v = D_800C4570;
    if (v & 4) {
        play_sound(5, 0, 0);
        D_800F1CC4[4] = 2;
        D_800F1CC4[5] = 1;
        arg0->unk8 = 0;
        arg0->unkA = 0;
        arg0->unk1 = 7;
        arg0->unk2 = 0;
        t = 1;
    } else if (v & 8) {
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
        arg0->unk8++;
        if ((s16)arg0->unk8 >= 0x3C) {
            arg0->unk1 = 6;
            arg0->unk2 = 0;
            arg0->unk8 = 0;
        }
    }
}

#define func_80041AB8 func_800ED0D8
#define D_80075FD8 D_800F0F6C
#define FAMILY_FIELD 2
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#include "common.h"

void func_800E99A4(u8* arg0);
extern s8 D_800F1CEA;

void func_800ED114(u8* arg0) {
    s16 t;

    t = ++*(s16*)(arg0 + 8);
    if (t >= 8) {
        D_800F1CEA = 0;
        ((void (*)())func_800E99A4)();
        *(s16*)(arg0 + 8) = 0;
        arg0[2]--;
    }
}

#define func_80041AB8 func_800ED170
#define D_80075FD8 D_800F1028
#define FAMILY_FIELD 2
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern u8 D_800F1CC4[];

void func_800ED1AC(void* arg0) {
    s32 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u16*, 8) + 1;
    M2C_FIELD(arg0, u16*, 8) = temp_v0;
    if ((s16)temp_v0 >= 8) {
        u8* p = D_800F1CC4;
        p[2] = 0;
        p[5] = 0;
        M2C_FIELD(arg0, u16*, 8) = 0;
        M2C_FIELD(arg0, u8*, 2) = (u8)(M2C_FIELD(arg0, u8*, 2) + 1);
    }
}

#define func_80041AB8 func_800ED1F4
#define D_80075FD8 D_800F1030
#define FAMILY_FIELD 2
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#include "common.h"
#include "mmx6/x4.h"

extern u8 D_800F1CC4[];

void func_800ED230(struct X4_EngineObj* arg0) {
    arg0->unk8++;
    if ((s16)arg0->unk8 >= 8) {
        arg0->unk8 = 0;
        D_800F1CC4[1] = 0;
        D_800F1CC4[4] = 0;
        arg0->unk2++;
    }
}

#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj background_objects[3];
extern u8 D_800F1CC4[];

void func_800ED27C(struct X4_EngineObj* arg0) {
    if (background_objects[1].x_pos.i.hi < 0x400) {
        background_objects[1].x_pos.i.hi -= 0x200;
    } else {
        background_objects[1].x_pos.i.hi += 0x200;
    }
    if (background_objects[1].x_pos.u.hi == 0 ||
        background_objects[1].x_pos.u.hi >= 0x600) {
        D_800F1CC4[1] = 1;
        D_800F1CC4[4] = 1;
        D_800F1CC4[2] = 0;
        D_800F1CC4[3] = 0;
        background_objects[1].x_pos.i.hi = 0x600;
        background_objects[1].unk4C = 1;
        arg0->unk2++;
        background_objects[2].unk3 = 0;
    }
    background_objects[0].x_pos.i.hi = background_objects[1].x_pos.i.hi;
    background_objects[0].unk4C = background_objects[1].unk4C;
}

#include "common.h"
#include "mmx6/x4.h"

struct X4_QuadObj* alloc_class6_slot(void);
extern s8 D_800CCEFC;
extern s8 D_800F1CCA[];

void func_800ED30C(struct X4_EngineObj* arg0) {
    struct X4_QuadObj* q;
    s32 i;

    i = 0;
    if (++arg0->unk8 >= 8) {
        D_800F1CCA[0] = 1;
        D_800F1CCA[1] = 1;
        D_800CCEFC = 0;
        arg0->unk8 = 0;
        arg0->unk2++;
        do {
            q = alloc_class6_slot();
            if (q != 0) {
                q->active = 3;
                q->id = 1;
                q->unk2 = i;
                q->unk34 = i + 0x18;
                q->unk36 = 0;
                q->bg_offset = -1;
            }
            i++;
        } while (i < 2);
    }
}

#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EngineObj g_playthrough_state;

void func_800ED3DC(u8* arg0) {
    if (g_playthrough_state.character_state.bytes[6] == 1) {
        s32 v = arg0[3];
        g_playthrough_state.character_state.bytes[6] = 2;
        g_playthrough_state.character_state.bytes[5] = v;
        arg0[2]++;
    }
}

#include "common.h"

extern s8 D_800CCEFC;
extern u8 D_800F1CC4[];
extern s8 D_800F1CCA[];

void func_800ED418(u8* arg0) {
    if (D_800CCEFC == 0) {
        D_800F1CCA[0] = 0;
        D_800F1CCA[1] = 0;
        D_800F1CC4[2] = 0;
        D_800F1CC4[3] = 0;
        arg0[2] -= 3;
    }
}

#define func_80041AB8 func_800ED460
#define D_80075FD8 D_800F1038
#define FAMILY_FIELD 2
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK open_text_box(M2C_UNK, M2C_UNK, M2C_UNK);
extern u8 D_800F0960[];
extern u8 func_800F095C[];

void func_800ED49C(void* arg0) {
    u8 v;

    func_800F095C[0] = D_800F0960[0];
    func_800F095C[1] = D_800F0960[1];
    func_800F095C[2] = D_800F0960[2];
    func_800F095C[3] = v = D_800F0960[3];
    ((void (*)(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK))open_text_box)(0, 0xFF, 0,
                                                                  v);
    M2C_FIELD(arg0, u8*, 2) = M2C_FIELD(arg0, u8*, 2) + 1;
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern u8 D_8008EAFC;

void func_800ED508(void* arg0) {
    if (D_8008EAFC == 0) {
        M2C_FIELD(arg0, s8*, 0x66) = 2;
        M2C_FIELD(arg0, s8*, 1) = 3;
        M2C_FIELD(arg0, s8*, 2) = 0;
    }
}

#define func_80041AB8 func_800ED534
#define D_80075FD8 D_800F1050
#define FAMILY_FIELD 2
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK open_text_box(M2C_UNK, M2C_UNK, M2C_UNK);
extern u8 D_800F0968[];
extern u8 func_800F095C[];

void func_800ED570(void* arg0) {
    func_800F095C[0] = D_800F0968[0];
    func_800F095C[1] = D_800F0968[1];
    func_800F095C[2] = D_800F0968[2];
    func_800F095C[3] = D_800F0968[3];
    ((void (*)(M2C_UNK, M2C_UNK, M2C_UNK))open_text_box)(2, 0xFF, 0);
    M2C_FIELD(arg0, u8*, 2) = M2C_FIELD(arg0, u8*, 2) + 1;
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern u8 D_8008EAFC;

void func_800ED5DC(void* arg0) {
    if (D_8008EAFC == 0) {
        M2C_FIELD(arg0, s8*, 0x66) = 3;
        M2C_FIELD(arg0, s8*, 0x43B) = 2;
        M2C_FIELD(arg0, s8*, 1) = 3;
        M2C_FIELD(arg0, s8*, 2) = 0;
    }
}

#define func_80041AB8 func_800ED60C
#define D_80075FD8 D_800F1058
#define FAMILY_FIELD 2
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK open_text_box(M2C_UNK, M2C_UNK, M2C_UNK);
extern u8 D_800F0964[];
extern u8 func_800F095C[];

void func_800ED648(void* arg0) {
    u8 v;

    func_800F095C[0] = D_800F0964[0];
    func_800F095C[1] = D_800F0964[1];
    func_800F095C[2] = D_800F0964[2];
    func_800F095C[3] = v = D_800F0964[3];
    ((void (*)(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK))open_text_box)(1, 0xFF, 0,
                                                                  v);
    M2C_FIELD(arg0, u8*, 2) = M2C_FIELD(arg0, u8*, 2) + 1;
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern u8 D_8008EAFC;

void func_800ED6B4(void* arg0) {
    if (D_8008EAFC == 0) {
        M2C_FIELD(arg0, s8*, 0x43B) = 1;
        M2C_FIELD(arg0, s8*, 1) = 3;
        M2C_FIELD(arg0, s8*, 2) = 0;
    }
}

#define func_80041AB8 func_800ED6E0
#define D_80075FD8 D_800F1060
#define FAMILY_FIELD 2
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

// clang-format off
INCLUDE_ASM("asm/rock_16/nonmatchings/E9860", func_800ED71C);
// clang-format on

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_8002CB50();
extern struct X4_EngineObj g_playthrough_state;
extern u16 D_800F111C[][2];

#define SEL (g_playthrough_state.character_state.bytes[1])
#define E66 ((u8)g_playthrough_state.character_state.bytes[0x40])

static inline s32 chr_idx_800EDB2C(s32 x) {
    if (x == 8) {
        if (E66 == 3) {
            return 8;
        }
        if (E66 == 4) {
            return 9;
        }
        return 10;
    }
    return x;
}

void func_800EDB2C(void* arg0) {
    s32 i;
    s32 y;

    if (SEL == 8) {
        y = 8;
        if (E66 != 3) {
            y = 10;
            if (E66 == 4) {
                y = 9;
            }
        }
        i = y;
    } else {
        i = SEL;
    }
    *(u16*)((u8*)arg0 + 0xA) = D_800F111C[i][0];
    *(u16*)((u8*)arg0 + 0xE) = D_800F111C[chr_idx_800EDB2C(SEL)][1];
    ((void (*)())func_8002CB50)(arg0);
}

#undef SEL
#undef E66

#define func_80041AB8 func_800EDBF4
#define D_80075FD8 D_800F118C
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_8002CB50();
extern struct X4_EngineObj g_playthrough_state;
extern u16 D_800F10F8[][2];

void func_800EDC30(struct X4_AnimatedObj* self) {
    self->x_pos.i.hi =
        D_800F10F8[g_playthrough_state.character_state.bytes[1]][0];
    self->y_pos.i.hi =
        D_800F10F8[g_playthrough_state.character_state.bytes[1]][1];
    if (g_playthrough_state.character_state.bytes[0] != 0) {
        set_animation(self, 4);
        self->unk6++;
    }
    func_8002CB50(self);
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CB50(); /* extern */
extern s8 D_800CCEF6;

void func_800EDCC0(void* arg0) {
    if (D_800CCEF6 != 0) {
        func_8002CB50();
        return;
    }
    M2C_FIELD(arg0, s8*, 3) = 0;
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_8002CB50();
extern struct X4_EngineObj g_playthrough_state;

void func_800EDD04(struct X4_AnimatedObj* self) {
    if ((*(s32*)&g_playthrough_state & 0xFFFF00) == 0x400) {
        set_animation(self, 0);
        self->unk6 = 0;
        func_8002CB50(self);
    }
}

#define func_8003744C func_800EDD54
#define D_80073C1C D_800F1168
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation_frame(void*, M2C_UNK, s8);
M2C_UNK func_8002CB50();
extern struct X4_EngineObj g_playthrough_state;
extern u8 D_800F1CF9;

void func_800EDD90(void* arg0) {
    s8 v;
    s8 r;

    if (D_800F1CF9 != 0) {
        v = g_playthrough_state.character_state.bytes[1];
        if (v == 8) {
            if (((u8*)&g_playthrough_state)[0x66] == 3) {
                r = 8;
            } else if (((u8*)&g_playthrough_state)[0x66] == 4) {
                r = 9;
            } else {
                r = 0xA;
            }
        } else {
            r = v;
        }
        ((void (*)(void*, s32, s8))set_animation_frame)(arg0, 3, r);
        func_8002CB50(arg0);
        return;
    }
    ((u8*)arg0)[3] = 0;
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8002CB50();
extern s8 D_800CCEF7;
extern u16 D_800F111C[][2];
extern u8 D_800F1CF0[];

void func_800EDE14(void* arg0) {
    s32 i;
    u32 n;

    i = *((u8*)arg0 + 2) & 0xF;
    n = i & 0xFF;
    if (n >= 8) {
        n = 8;
    }
    if (n == D_800CCEF7 || D_800F1CF0[n] != 0) {
        *(u16*)((u8*)arg0 + 0xA) = D_800F111C[i][0];
        *(u16*)((u8*)arg0 + 0xE) = D_800F111C[i][1];
        ((void (*)())func_8002CB50)(arg0);
        return;
    }
    *((u8*)arg0 + 3) = 0;
}

#include "common.h"

void func_800EC8CC(s32 arg0);

void func_800EDEB0(u8* arg0) {
    s32 t;

    if ((s8)++arg0[6] >= 4) {
        t = arg0[2];
        if (t & 0x20) {
            func_800EC8CC(t & 0xF);
        }
        arg0[3] = 0;
        arg0[4]++;
    }
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8002CB50();
extern u8 D_800F1CF0[];

void func_800EDF20(void* arg0) {
    if (*((*((u8*)arg0 + 2) & 0xF) + D_800F1CF0) != 0) {
        ((void (*)())func_8002CB50)(arg0, arg0);
        return;
    }
    *((u8*)arg0 + 3) = 0;
}

#define func_80041AB8 func_800EDF74
#define D_80075FD8 D_800F1174
#define FAMILY_FIELD 5
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EDFB0(void) {
    clear_object_slot();
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation_frame(void*, M2C_UNK, s8);
extern u16 D_800F11E0[];
extern u16 D_800F11F8[][2];

#define DFD0_S8(o) (*(s8*)((s8*)arg0 + (o)))
#define DFD0_U8(o) (*(u8*)((s8*)arg0 + (o)))
#define DFD0_S16(o) (*(s16*)((s8*)arg0 + (o)))
#define DFD0_U16(o) (*(u16*)((s8*)arg0 + (o)))
#define DFD0_PTR(o) (*(void**)((s8*)arg0 + (o)))
#define DFD0_SCRATCH (*(u8**)0x1F800020)

void func_800EDFD0(void* arg0) {
    s32 v;

    v = DFD0_S8(2);
    DFD0_S16(0x40) = 0x1800;
    DFD0_PTR(0x30) = D_800F11E0;
    DFD0_U8(0x16) = 3;
    if (v < 2) {
        u8* p;
        s32 a;
        p = DFD0_SCRATCH;
        p += *(s32*)(p + 0);
        DFD0_S16(0x42) = 0x780D;
        DFD0_PTR(0x3C) = p;
        a = D_800F11F8[v][0];
        DFD0_U16(0xA) = a;
        DFD0_U16(0xE) = D_800F11F8[v][1];
        DFD0_U8(5) = 0;
        ((void (*)(void*, s32, s32))set_animation_frame)(arg0, v, 0);
    } else if (v < 4) {
        u8* p;
        s32 a;
        p = DFD0_SCRATCH;
        p += *(s32*)(p + 8);
        DFD0_S16(0x42) = 0x788E;
        DFD0_PTR(0x3C) = p;
        a = D_800F11F8[v][0];
        DFD0_U16(0xA) = a;
        DFD0_U16(0xE) = D_800F11F8[v][1];
        DFD0_U8(5) = 0;
        ((void (*)(void*, s32, s32))set_animation_frame)(arg0, v, 1);
    } else if (v < 6) {
        u8* p;
        s32 a;
        DFD0_S16(0x42) = 0x7843;
        p = DFD0_SCRATCH;
        p += *(s32*)(p + 4);
        DFD0_PTR(0x3C) = p;
        a = D_800F11F8[v][0];
        DFD0_U16(0xA) = a;
        DFD0_U16(0xE) = D_800F11F8[v][1];
        DFD0_U8(5) = 0;
        ((void (*)(void*, s32, s32))set_animation_frame)(arg0, v, 1);
    } else if (v < 8) {
        u8* p;
        s32 w = v - 2;
        DFD0_S16(0x42) = 0x7843;
        p = DFD0_SCRATCH;
        p += *(s32*)(p + 4);
        DFD0_PTR(0x3C) = p;
        DFD0_U16(0xA) = D_800F11F8[w][0] + 0x600;
        DFD0_U16(0xE) = D_800F11F8[w][1];
        DFD0_U8(5) = 1;
        ((void (*)(void*, s32, s32))set_animation_frame)(arg0, w, 1);
    } else if (v < 10) {
        u8* p;
        s32 w = v - 6;
        p = DFD0_SCRATCH;
        p += *(s32*)(p + 8);
        DFD0_S16(0x42) = 0x788E;
        DFD0_PTR(0x3C) = p;
        DFD0_U16(0xA) = D_800F11F8[w][0] - 0x600;
        DFD0_U16(0xE) = D_800F11F8[w][1];
        DFD0_U8(5) = 1;
        ((void (*)(void*, s32, s32))set_animation_frame)(arg0, w, 1);
    }
    DFD0_U8(0x14) = 1;
    DFD0_U8(4)++;
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
extern void (*D_800F1218[])(void*);

void func_800EE1EC(u8* arg0) {
    D_800F1218[(s8)arg0[4]](arg0);
    func_8002CCB0(arg0, 0x60, 0x10);
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SB(p, o) M2C_FIELD(p, s8*, o)

M2C_UNK set_animation_frame(void*, M2C_UNK, s8);
extern u8 D_800F1CC4[];

void func_800EE240(void* arg0) {
    s8 idx;

    idx = SB(arg0, 0x2);
    set_animation_frame(arg0, idx, D_800F1CC4[idx]);
}

#include "common.h"

void func_800EE274(void) {
}

#define func_80041AB8 func_800EE27C
#define D_80075FD8 D_800F1210
#define FAMILY_FIELD 5
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */
extern s8 D_800CCF02;
extern void (*D_800F126C[])(s8*);

void func_800EE2B8(s8* arg0) {
    if (D_800CCF02 != 0) {
        clear_object_slot();
        return;
    }
    D_800F126C[arg0[4]](arg0);
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK set_animation_frame(void*, M2C_UNK, s8);
extern s8 D_800CCEF8;
extern s8 D_800CCF01;
extern u8 D_800F124C[];

#define E310_S8(o) (*(s8*)((s8*)arg0 + (o)))
#define E310_U8(o) (*(u8*)((s8*)arg0 + (o)))
#define E310_S16(o) (*(s16*)((s8*)arg0 + (o)))
#define E310_PTR(o) (*(void**)((s8*)arg0 + (o)))
#define E310_SCRATCH (*(u8**)0x1F800020)

void func_800EE310(void* arg0) {
    u8* p;
    s32 v;
    u8* q;

    E310_S16(0x40) = 0x1800;
    p = E310_SCRATCH;
    q = p + *(s32*)p;
    v = E310_S8(2);
    E310_PTR(0x30) = D_800F124C;
    E310_S16(0x42) = 0x780D;
    E310_U8(0x16) = 3;
    E310_PTR(0x3C) = q;
    if (v == 0) {
        E310_S16(0xA) = 0x5B0;
        E310_S16(0xE) = 0x6C;
        ((void (*)(void*, s32))set_animation)(arg0, 0);
        E310_U8(4) = 1;
    } else if (v == 1) {
        E310_S16(0xA) = 0x5B0;
        E310_S16(0xE) = 0x7C;
        ((void (*)(void*, s32, s8))set_animation_frame)(arg0, 1, D_800CCF01);
        E310_U8(4) = 2;
    } else {
        E310_S16(0xA) = 0x5B0;
        E310_S16(0xE) = 0x7C;
        ((void (*)(void*, s32))set_animation)(arg0, D_800CCEF8 + 2);
        E310_U8(4) = 3;
    }
    E310_U8(3) = 1;
    E310_U8(0x14) = 1;
}

#include "common.h"

void func_800EE408(void) {
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation_frame(void*, M2C_UNK, s8);
extern s8 D_800CCF01;

void func_800EE410(void* arg0) {
    set_animation_frame(arg0, 1, D_800CCF01);
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
extern s8 D_800CCEF8;

void func_800EE438(void* arg0) {
    set_animation(arg0, D_800CCEF8 + 2);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define S8(o) M2C_FIELD(arg0, s8*, o)
#define U8(o) M2C_FIELD(arg0, u8*, o)
#define U16(o) M2C_FIELD(arg0, u16*, o)
#define S16(o) M2C_FIELD(arg0, s16*, o)
#define PTR(o) M2C_FIELD(arg0, void**, o)
#define SCRATCH_PTR (*(u8**)0x1F800020)

M2C_UNK set_animation(void*, M2C_UNK);
extern struct X4_EngineObj g_playthrough_state;
extern u8 D_800F1284[];
extern u16 D_800F128C[][2];

void func_800EE460(void* arg0) {
    u8* p;
    s8 v;
    // !FAKE: depin: dropping it breaks the match (80/83)
    register u8 t asm("$3");
    u8* q;

    S16(0x40) = 0x1800;
    p = SCRATCH_PTR;
    v = S8(2);
    q = p + *(s32*)(p + 4);
    S16(0x42) = 0x78C3;
    PTR(0x30) = D_800F1284;
    PTR(0x3C) = q;
    if (v == 0) {
        u16(*tb)[2] = D_800F128C;
        struct X4_EngineObj* e = &g_playthrough_state;
        U8(0x16) = 0;
        U16(0xA) = tb[e->character_state.bytes[3]][0];
        U16(0xE) = D_800F128C[e->character_state.bytes[3]][1];
        set_animation(arg0, e->character_state.bytes[3]);
        t = e->character_state.bytes[3];
        U8(0x5) = 0;
        U8(0x7) = t;
    } else if (v == 1) {
        u16(*tb)[2] = D_800F128C;
        struct X4_EngineObj* e = &g_playthrough_state;
        U8(0x16) = 0;
        U16(0xA) = tb[e->character_state.bytes[3]][0] + 0x600;
        U16(0xE) = D_800F128C[e->character_state.bytes[3]][1];
        set_animation(arg0, e->character_state.bytes[3]);
        t = e->character_state.bytes[3];
        U8(0x5) = v;
        U8(0x7) = t;
    }
    U8(0x3) = 1;
    U8(0x14) = 1;
    U8(0x4)++;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj g_playthrough_state;
extern u16 D_800F128C[][2];

void func_800EE5AC(struct X4_AnimatedObj* self) {
    func_80017A04();
    if (g_playthrough_state.character_state.bytes[3] != self->unk7) {
        self->x_pos.i.hi =
            D_800F128C[g_playthrough_state.character_state.bytes[3]][0];
        self->y_pos.i.hi =
            D_800F128C[g_playthrough_state.character_state.bytes[3]][1];
        set_animation(self, g_playthrough_state.character_state.bytes[3]);
        self->unk7 = g_playthrough_state.character_state.bytes[3];
    }
    if (self->unk6 == 0) {
        if (g_playthrough_state.unk1 == 6) {
            self->on_screen = 0;
            self->unk6++;
            return;
        }
        func_8002CCB0(self, 0xA0, 0x10);
        if ((*(s32*)&g_playthrough_state & 0xFFFF00) == 0x40500 &&
            (D_80097420.frame_counter & 1)) {
            self->on_screen = 0;
        }
    } else if (g_playthrough_state.unk1 == 5 ||
               background_objects[self->bg_offset].x_pos.i.hi >= 0x400) {
        self->unk6--;
    }
}

#define func_80041AB8 func_800EE708
#define D_80075FD8 D_800F129C
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
extern struct X4_EngineObj g_playthrough_state;
extern u16 D_800F128C[][2];

void func_800EE744(struct X4_AnimatedObj* self) {
    func_80017A04();
    if (g_playthrough_state.character_state.bytes[3] != self->unk7) {
        self->x_pos.i.hi =
            D_800F128C[g_playthrough_state.character_state.bytes[3]][0] + 0x600;
        self->y_pos.i.hi =
            D_800F128C[g_playthrough_state.character_state.bytes[3]][1];
        set_animation(self, g_playthrough_state.character_state.bytes[3]);
        self->unk7 = g_playthrough_state.character_state.bytes[3];
    }
    func_8002CCB0(self, 0xA0, 0x10);
}

#define func_80041AB8 func_800EE7EC
#define D_80075FD8 D_800F1294
#define FAMILY_FIELD 5
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EE828(void) {
    clear_object_slot();
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define S8(o) M2C_FIELD(arg0, s8*, o)
#define U8(o) M2C_FIELD(arg0, u8*, o)
#define U16(o) M2C_FIELD(arg0, u16*, o)
#define S16(o) M2C_FIELD(arg0, s16*, o)
#define PTR(o) M2C_FIELD(arg0, void**, o)
#define SCRATCH_PTR (*(u8**)0x1F800020)

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK set_animation_frame(void*, M2C_UNK, s8);
M2C_UNK clear_object_slot();
s32 func_800EC1FC(s32);
extern struct X4_EngineObj g_playthrough_state;
extern s8 D_800CCEF9;
extern s8 D_800CCEFA;
extern u16 D_800F12A8[][2];
extern u16 D_800F1328[][2];
extern u16 D_800F1520[][2];
extern u8 D_800F1538[];
extern s8 D_800F1CD0[][5];
extern s8 D_800F1CE0[][5];

#define ENG_29 (g_playthrough_state.character_state.bytes[3])
#define ENG_2A (g_playthrough_state.character_state.bytes[4])

void func_800EE848(void* arg0) {
    u8* p;
    s8 v;
    s8 i;
    s8 t;
    s8 j;

    S16(0x40) = 0x1800;
    p = SCRATCH_PTR;
    v = S8(2);
    PTR(0x3C) = p + *(s32*)(p + 4);
    PTR(0x30) = D_800F1538;
    if (v < 0x20) {
        if (v >= 0x18) {
            ((void (*)(void*, s32, s8))set_animation_frame)(arg0, 0, v);
        } else if (func_800EC1FC(v) != 0) {
            ((void (*)(void*, s32, s8))set_animation_frame)(arg0, 1, S8(2));
        } else {
            ((void (*)(void*, s32, s8))set_animation_frame)(arg0, 0, S8(2));
        }
        U16(0xA) = D_800F12A8[S8(2)][0];
        U16(0xE) = D_800F12A8[S8(2)][1];
        U8(0x16) = 3;
        U8(0x5) = 0;
    } else if (v == 0x20 || v == 0x23) {
        if (!(g_playthrough_state.unk5F & 0x10) ||
            g_playthrough_state.unk1 == 6) {
            ((void (*)(void*, s32, s8))set_animation_frame)(arg0, 2, 1);
        } else if (g_playthrough_state.unk1 == 5) {
            ((void (*)(void*, s32, s8))set_animation_frame)(arg0, 2, 0);
        }
        if (S8(2) == 0x20) {
            U16(0xA) = 0x2D6;
        } else {
            U16(0xA) = 0x8D6;
        }
        U16(0xE) = 0x88;
        U8(0x16) = 3;
        U8(0x5) = 1;
    } else if (v == 0x21 || v == 0x24) {
        PTR(0x3C) = SCRATCH_PTR + *(s32*)(SCRATCH_PTR + 0xC);
        ((void (*)(void*, s32, s8))set_animation_frame)(arg0, 3, D_800CCEFA);
        if (S8(2) == 0x21) {
            U16(0xA) = 0x2D0;
        } else {
            U16(0xA) = 0x8D0;
        }
        U16(0xE) = 0x98;
        U8(0x16) = 3;
        U8(0x5) = 2;
    } else if (v == 0x22 || v == 0x25) {
        clear_object_slot(arg0);
        return;
    } else if ((u8)(U8(2) - 0x26) < 2) {
        ((void (*)(void*, s32))set_animation)(arg0, 5);
        if (S8(2) == 0x26) {
            U16(0xA) = D_800F12A8[ENG_2A][0];
        } else {
            U16(0xA) = D_800F12A8[ENG_2A][0] + 0x600;
        }
        U16(0xE) = D_800F12A8[ENG_2A][1];
        U8(0x16) = 1;
        U8(0x5) = 4;
    } else if (v < 0x2D) {
        S8(2) -= 0x28;
        ((void (*)(void*, s32, s8))set_animation_frame)(
            arg0, 6, D_800F1CE0[D_800CCEF9][S8(2)]);
        U16(0xA) = D_800F1328[S8(2)][0];
        U16(0xE) = D_800F1328[S8(2)][1];
        U8(0x16) = 3;
        U8(0x5) = 5;
    } else if (v < 0x32) {
        S8(2) -= 0x2D;
        ((void (*)(void*, s32))set_animation)(arg0, 7);
        i = S8(2);
        if (D_800F1CD0[ENG_29][i] != -1) {
            U16(0xA) = D_800F12A8[D_800F1CD0[ENG_29][i]][0];
            U16(0xE) = D_800F12A8[D_800F1CD0[ENG_29][i]][1];
        } else {
            U8(0x3) = 0;
        }
        U8(0x16) = 2;
        U8(0x5) = 6;
    } else if (S8(2) < 0x37) {
        S8(2) -= 0x32;
        t = D_800F1CD0[D_800CCEF9][S8(2)];
        if (t != -1) {
            ((void (*)(void*, s32, s8))set_animation_frame)(arg0, 0, t);
        }
        U16(0xA) = D_800F1328[S8(2)][0];
        U16(0xE) = D_800F1328[S8(2)][1];
        U8(0x16) = 2;
        U8(0x5) = 7;
    } else if (S8(2) < 0x3D) {
        S8(2) -= 0x37;
        ((void (*)(void*, s32, s8))set_animation_frame)(arg0, 8, S8(2));
        j = S8(2);
        U16(0xA) = D_800F1520[j][0];
        U16(0xE) = D_800F1520[j][1];
        if (j == 1) {
            U8(0x16) = 7;
        } else {
            U8(0x16) = 1;
        }
        U8(0x5) = 8;
    } else if (S8(2) == 0x3D) {
        ((void (*)(void*, s32))set_animation)(arg0, 9);
        U16(0xA) = D_800F12A8[ENG_2A][0];
        U16(0xE) = D_800F12A8[ENG_2A][1];
        U8(0x16) = 1;
        U8(0x5) = 9;
    }
    U8(0x14) = 1;
    U8(0x4)++;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation_frame(void*, M2C_UNK, s8);
M2C_UNK func_8002CB50();
s32 func_800EC1FC(s32);
extern struct X4_BackgroundObj background_objects[3];
extern u16 D_800F12A8[][2];

void func_800EEDA0(void* arg0) {
    s8 t;
    u16 v;

    t = *(s8*)((u8*)arg0 + 2);
    if (t >= 0x18) {
        set_animation_frame(arg0, 0, t);
    } else if (func_800EC1FC(t) != 0) {
        set_animation_frame(arg0, 1, *(s8*)((u8*)arg0 + 2));
    } else {
        set_animation_frame(arg0, 0, *(s8*)((u8*)arg0 + 2));
    }
    v = D_800F12A8[*(s8*)((u8*)arg0 + 2)][0];
    *(u16*)((u8*)arg0 + 0xA) = v;
    *(u16*)((u8*)arg0 + 0xE) = D_800F12A8[*(s8*)((u8*)arg0 + 2)][1];
    if (background_objects[*(s8*)((u8*)arg0 + 0x14)].x_pos.i.hi >= 0x400) {
        *(u16*)((u8*)arg0 + 0xA) = v + 0x600;
    }
    ((void (*)())func_8002CB50)(arg0);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80017A04();
M2C_UNK func_8002CB50();
extern struct X4_EngineObj g_playthrough_state;
extern u16 D_800F12A8[][2];

void func_800EEE80(void* arg0) {
    ((void (*)())func_80017A04)();
    if (*(s8*)((u8*)arg0 + 2) == 0x26) {
        *(u16*)((u8*)arg0 + 0xA) =
            D_800F12A8[g_playthrough_state.character_state.bytes[4]][0];
    } else {
        *(u16*)((u8*)arg0 + 0xA) =
            D_800F12A8[g_playthrough_state.character_state.bytes[4]][0] + 0x600;
    }
    *(u16*)((u8*)arg0 + 0xE) =
        D_800F12A8[g_playthrough_state.character_state.bytes[4]][1];
    if (g_playthrough_state.unk5F & 0x10) {
        if (g_playthrough_state.unk1 == 5) {
            *(u8*)((u8*)arg0 + 3) = 0;
        }
        if (g_playthrough_state.unk1 == 6) {
            ((void (*)())func_8002CB50)(arg0);
        }
    } else {
        ((void (*)())func_8002CB50)(arg0);
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation_frame(void*, M2C_UNK, s8);
M2C_UNK func_8002CB50();
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj g_playthrough_state;
extern u16 D_800F1328[][2];
extern s8 D_800F1CE0[][5];

void func_800EEF78(void* arg0) {
    u16 v;

    set_animation_frame(arg0, 6,
                  D_800F1CE0[g_playthrough_state.character_state.bytes[3]]
                            [*(s8*)((u8*)arg0 + 2)]);
    *(u16*)((u8*)arg0 + 0xA) = D_800F1328[*(s8*)((u8*)arg0 + 2)][0];
    v = D_800F1328[*(s8*)((u8*)arg0 + 2)][1];
    *(u16*)((u8*)arg0 + 0xE) = v;
    if (g_playthrough_state.character_state.bytes[3] != 0) {
        *(u16*)((u8*)arg0 + 0xE) = v + 0x2B;
    }
    if (background_objects[*(s8*)((u8*)arg0 + 0x14)].x_pos.i.hi > 0x400) {
        *(u16*)((u8*)arg0 + 0xA) += 0x600;
    }
    ((void (*)())func_8002CB50)(arg0);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_8002CB50();
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj g_playthrough_state;
extern u16 D_800F12A8[][2];
extern s8 D_800F1CD0[][5];

void func_800EF064(void* arg0) {
    s8 i;
    s8 t;
    u16 v;

    i = *(s8*)((u8*)arg0 + 2);
    t = D_800F1CD0[g_playthrough_state.character_state.bytes[3]][i];
    if (t != -1) {
        v = D_800F12A8[t][0];
        *(u16*)((u8*)arg0 + 0xA) = v;
        *(u16*)((u8*)arg0 + 0xE) =
            D_800F12A8[D_800F1CD0[g_playthrough_state.character_state.bytes[3]]
                                 [i]][1] +
            1;
        if (background_objects[*(s8*)((u8*)arg0 + 0x14)].x_pos.i.hi > 0x400) {
            *(u16*)((u8*)arg0 + 0xA) = v + 0x600;
        }
    }
    ((void (*)())func_8002CB50)(arg0);
    if (D_800F1CD0[g_playthrough_state.character_state.bytes[3]]
                  [*(s8*)((u8*)arg0 + 2)] == -1) {
        *(u8*)((u8*)arg0 + 3) = 0;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation_frame(void*, M2C_UNK, s8);
M2C_UNK func_8002CB50();
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj g_playthrough_state;
extern u16 D_800F1328[][2];
extern s8 D_800F1CD0[][5];

void func_800EF198(void* arg0) {
    s8 t;
    u16 v;

    *(u16*)((u8*)arg0 + 0xA) = D_800F1328[*(s8*)((u8*)arg0 + 2)][0];
    v = D_800F1328[*(s8*)((u8*)arg0 + 2)][1];
    *(u16*)((u8*)arg0 + 0xE) = v;
    if (g_playthrough_state.character_state.bytes[3] != 0) {
        *(u16*)((u8*)arg0 + 0xE) = v + 0x2B;
    }
    if (background_objects[*(s8*)((u8*)arg0 + 0x14)].x_pos.i.hi > 0x400) {
        *(u16*)((u8*)arg0 + 0xA) += 0x600;
    }
    ((void (*)())func_8002CB50)(arg0);
    t = D_800F1CD0[g_playthrough_state.character_state.bytes[3]]
                  [*(s8*)((u8*)arg0 + 2)];
    if (t != -1) {
        set_animation_frame(arg0, 0, t);
    } else {
        *(u8*)((u8*)arg0 + 3) = 0;
    }
}

#include "common.h"

extern void (*D_800F1588[])(void*);

void func_800EF298(void* arg0) {
    s8 c;

    D_800F1588[*(s8*)((u8*)arg0 + 4)](arg0);
    c = *(s8*)((u8*)arg0 + 0x45);
    if (c == 0x13) {
        *(s16*)((u8*)arg0 + 0x42) = 0x7849;
    } else {
        *(s16*)((u8*)arg0 + 0x42) =
            ((c + 0x30) % 16) | ((((c + 0x30) / 16) + 0x1E0) << 6);
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation_frame(void*, M2C_UNK, s8);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
extern struct X4_EngineObj g_playthrough_state;

void func_800EF31C(void* arg0) {
    if (!(g_playthrough_state.unk5F & 0x10) ||
        (g_playthrough_state.unk1 == 6)) {
        set_animation_frame(arg0, 2, 1);
    } else if (g_playthrough_state.unk1 == 5) {
        set_animation_frame(arg0, 2, 0);
    }
    func_8002CCB0(arg0, 0x60, 0x10);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation_frame(void*, M2C_UNK, s8);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
extern struct X4_EngineObj g_playthrough_state;
extern s32 D_800F0E74[];

#define EF3A0_ENG_2A (g_playthrough_state.character_state.bytes[4])
#define EF3A0_ENG_70 (*(s32*)((u8*)&g_playthrough_state + 0x70))
#define EF3A0_U8(o) (*(u8*)((s8*)arg0 + (o)))

void func_800EF3A0(void* arg0) {
    // !FAKE: depin: dropping it breaks the match (51/54)
    register s32 t asm("$2");
    set_animation_frame(arg0, 3, EF3A0_ENG_2A);
    t = g_playthrough_state.unk5F;
    if (t & 0x10) {
        if (g_playthrough_state.unk1 == 5) {
            EF3A0_U8(3) = 0;
        }
        if (g_playthrough_state.unk1 == 6) {
            func_8002CCB0(arg0, 0x60, 0x10);
        }
    } else {
        func_8002CCB0(arg0, 0x60, 0x10);
    }
    if (!(D_800F0E74[EF3A0_ENG_2A] & EF3A0_ENG_70)) {
        EF3A0_U8(3) = 0;
    }
}

#undef EF3A0_ENG_2A
#undef EF3A0_ENG_70
#undef EF3A0_U8

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation_frame(void*, M2C_UNK, s8);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
extern struct X4_EngineObj g_playthrough_state;
extern s32 D_800F0E74[];

#define EF478_ENG_2A (g_playthrough_state.character_state.bytes[4])
#define EF478_ENG_70 (*(s32*)((u8*)&g_playthrough_state + 0x70))
#define EF478_U8(o) (*(u8*)((s8*)arg0 + (o)))

void func_800EF478(void* arg0) {
    // !FAKE: depin: dropping it breaks the match (51/54)
    register s32 t asm("$2");
    set_animation_frame(arg0, 4, EF478_ENG_2A);
    t = g_playthrough_state.unk5F;
    if (t & 0x10) {
        if (g_playthrough_state.unk1 == 5) {
            EF478_U8(3) = 0;
        }
        if (g_playthrough_state.unk1 == 6) {
            func_8002CCB0(arg0, 0x60, 0x10);
        }
    } else {
        func_8002CCB0(arg0, 0x60, 0x10);
    }
    if (!(D_800F0E74[EF478_ENG_2A] & EF478_ENG_70)) {
        EF478_U8(3) = 0;
    }
}

#undef EF478_ENG_2A
#undef EF478_ENG_70
#undef EF478_U8

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_8002CB50();
extern struct X4_BackgroundObj background_objects[3];
extern u16 D_800F1520[][2];

void func_800EF550(void* arg0) {
    u16 v;

    v = D_800F1520[*(s8*)((u8*)arg0 + 2)][0];
    *(u16*)((u8*)arg0 + 0xA) = v;
    *(u16*)((u8*)arg0 + 0xE) = D_800F1520[*(s8*)((u8*)arg0 + 2)][1];
    if (background_objects[*(s8*)((u8*)arg0 + 0x14)].x_pos.i.hi >= 0x401) {
        *(u16*)((u8*)arg0 + 0xA) = v + 0x600;
    }
    ((void (*)())func_8002CB50)(arg0);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK clear_object_slot();
M2C_UNK func_8002CB50();
extern struct X4_EngineObj g_playthrough_state;
extern u16 D_800F12A8[][2];
extern s8 D_800F1CEA;

void func_800EF5D8(void* arg0) {
    *(u16*)((u8*)arg0 + 0xA) =
        D_800F12A8[(s8)g_playthrough_state.character_state.bytes[4]][0];
    *(u16*)((u8*)arg0 + 0xE) =
        D_800F12A8[(s8)g_playthrough_state.character_state.bytes[4]][1];
    ((void (*)())func_8002CB50)(arg0);
    if (D_800F1CEA != 2) {
        ((void (*)())clear_object_slot)(arg0);
    }
}

#define func_80041AB8 func_800EF654
#define D_80075FD8 D_800F1560
#define FAMILY_FIELD 5
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EF690(void) {
    clear_object_slot();
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation_frame(void*, M2C_UNK, s8);
s32 get_reploid_status();
extern s32 D_8006D674[];
extern struct X4_EngineObj g_playthrough_state;
extern s8 D_800CCEFB;
extern s32 D_800F0E74[];
extern u16 D_800F1668[];
extern u16 D_800F1680[][2];
extern u16 D_800F1688[][2];

#define F6B0_S8(o) (*(s8*)((s8*)arg0 + (o)))
#define F6B0_U8(o) (*(u8*)((s8*)arg0 + (o)))
#define F6B0_S16(o) (*(s16*)((s8*)arg0 + (o)))
#define F6B0_U16(o) (*(u16*)((s8*)arg0 + (o)))
#define F6B0_PTR(o) (*(void**)((s8*)arg0 + (o)))
#define F6B0_SCRATCH (*(u8**)0x1F800020)
#define F6B0_ENG2B (g_playthrough_state.character_state.bytes[5])

void func_800EF6B0(void* arg0) {
    u8* p;
    u8* q;
    u8* q2;
    s8 v;
    u8 u;
    s32 r;
    s32 w;
    s32 i;

    F6B0_S16(0x40) = 0x1800;
    p = F6B0_SCRATCH;
    v = F6B0_S8(2);
    F6B0_PTR(0x3C) = p + *(s32*)(p + 8);
    F6B0_S16(0x42) = 0x788E;
    F6B0_PTR(0x30) = D_800F1668;
    u = F6B0_U8(2);
    if (v < 2) {
        ((void (*)(void*, s32, s32))set_animation_frame)(arg0, v, 0);
        F6B0_U16(0xA) = D_800F1680[F6B0_S8(2)][0];
        F6B0_U16(0xE) = D_800F1680[F6B0_S8(2)][1];
        F6B0_U8(0x16) = 3;
        F6B0_U8(5) = 0;
    } else if (v < 0x12) {
        F6B0_S16(0x40) = 0x1800;
        F6B0_S16(0x42) = 0x7882;
        q = F6B0_SCRATCH;
        F6B0_PTR(0x3C) = q + *(s32*)(q + 0x10);
        F6B0_S8(2) = u - 2;
        if (get_reploid_status(F6B0_ENG2B * 16 + F6B0_S8(2)) >= 2) {
            F6B0_S8(0x47) = F6B0_U8(2) + F6B0_ENG2B * 16;
        } else {
            F6B0_S8(3) = 0;
        }
        F6B0_U16(0xA) = D_800F1688[F6B0_S8(2)][0] + 0x20;
        F6B0_U16(0xE) = D_800F1688[F6B0_S8(2)][1];
        F6B0_U8(0x16) = 3;
        F6B0_U8(5) = 1;
    } else if (v < 0x22) {
        F6B0_S8(2) = u - 0x12;
        ((void (*)(void*, s32, s32))set_animation_frame)(
            arg0, 2, get_reploid_status(D_800CCEFB * 16 + F6B0_S8(2), u));
        F6B0_U16(0xA) = D_800F1688[F6B0_S8(2)][0] + 0x59;
        F6B0_U16(0xE) = D_800F1688[F6B0_S8(2)][1];
        F6B0_U8(0x16) = 3;
        F6B0_U8(5) = 2;
    } else if (v < 0x32) {
        q2 = F6B0_SCRATCH;
        F6B0_PTR(0x3C) = q2 + *(s32*)(q2 + 0xC);
        F6B0_S16(0x42) = 0x78C2;
        F6B0_S8(2) = u - 0x22;
        r = get_reploid_status(F6B0_ENG2B * 16 + F6B0_S8(2));
        if (r == 2 && (w = D_8006D674[F6B0_ENG2B * 16 + F6B0_S8(2)]) != 0) {
            if (w == 1) {
                i = 0x18;
                r = 0;
            } else if (w == r) {
                i = 0x19;
                r = 0;
            } else {
                for (i = 0; i < 0x18; i++) {
                    if (D_800F0E74[i] == w) {
                        goto found;
                    }
                }
                i = 0;
            }
        found:
            ((void (*)(void*, s32, s32))set_animation_frame)(arg0, 3, i);
        } else {
            F6B0_S8(3) = 0;
        }
        F6B0_U16(0xA) = D_800F1688[F6B0_S8(2)][0] + 0xA8;
        F6B0_U16(0xE) = D_800F1688[F6B0_S8(2)][1];
        F6B0_U8(0x16) = 3;
        F6B0_U8(5) = 3;
    } else if (v < 0x34) {
        F6B0_S8(2) = u - 0x32;
        F6B0_U8(0x16) = 3;
        F6B0_U8(5) = 4;
    } else if (v < 0x36) {
        F6B0_S8(2) = u - 0x34;
        if (F6B0_S8(2) != 0) {
            F6B0_S16(0x42) = 0x780D;
            F6B0_PTR(0x3C) = F6B0_SCRATCH + *(s32*)F6B0_SCRATCH;
        }
        F6B0_U8(0x16) = 3;
        F6B0_U8(5) = 5;
    } else if (v < 0x39) {
        F6B0_S8(2) = u - 0x36;
        F6B0_U8(0x16) = 3;
        F6B0_U8(5) = 6;
    } else if (v < 0x3C) {
        F6B0_S8(2) = u - 0x39;
        F6B0_U8(0x16) = 3;
        F6B0_U8(5) = 7;
    } else if (v < 0x3F) {
        F6B0_S8(2) = u - 0x3C;
        F6B0_U8(0x16) = 3;
        F6B0_U8(5) = 8;
    } else if (v == 0x3F) {
        F6B0_S16(0x42) = 0x788F;
        F6B0_U8(0x16) = 7;
        F6B0_U8(0x47) = 0xCF;
        F6B0_U8(5) = 9;
    }
    F6B0_S8(0x14) = 1;
    F6B0_U8(4) = F6B0_U8(4) + 1;
}

#undef F6B0_S8
#undef F6B0_U8
#undef F6B0_S16
#undef F6B0_U16
#undef F6B0_PTR
#undef F6B0_SCRATCH
#undef F6B0_ENG2B

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
s32 get_reploid_status(s32);
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj g_playthrough_state;
extern u16 D_800F1688[][2];

void func_800EFAB4(struct X4_AnimatedObj* self) {
    u16 x;

    x = D_800F1688[self->unk2][0];
    self->x_pos.i.hi = x;
    self->y_pos.i.hi = D_800F1688[self->unk2][1];
    if (background_objects[self->bg_offset].x_pos.i.hi < 0x400) {
        self->x_pos.i.hi = x - 0x600;
    }
    func_8002CCB0(self, 0x40, 0x10);
    if (get_reploid_status(g_playthrough_state.character_state.bytes[5] * 16 +
                      self->unk2) >= 2) {
        self->animation_step.fields.frame_index =
            self->unk2 + g_playthrough_state.character_state.bytes[5] * 16;
        return;
    }
    self->on_screen = 0;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation_frame(void*, M2C_UNK, s8);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
s32 get_reploid_status(s32);
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj g_playthrough_state;
extern u16 D_800F1688[][2];

void func_800EFB94(struct X4_AnimatedObj* self) {
    s32 x;
    // !FAKE: depin: dropping it breaks the match (60/75)
    register s32 t asm("$3");

    ((void (*)(void*, s32, s32))set_animation_frame)(
        self, 2,
        get_reploid_status(g_playthrough_state.character_state.bytes[5] * 16 +
                      self->unk2));
    t = D_800F1688[self->unk2][0];
    x = t + 0x59;
    self->x_pos.i.hi = x;
    self->y_pos.i.hi = D_800F1688[self->unk2][1];
    t = self->bg_offset;
    if (background_objects[t].x_pos.i.hi < 0x400) {
        self->x_pos.i.hi = x - 0x600;
    }
    switch (get_reploid_status(g_playthrough_state.character_state.bytes[5] * 16 +
                          self->unk2)) {
    case 0:
    case 1:
        self->unk42 = 0x7905;
        break;
    case 2:
        self->unk42 = 0x788E;
        break;
    case 3:
        self->unk42 = 0x7904;
        break;
    case 4:
        self->unk42 = 0x7906;
        break;
    }
    func_8002CCB0(self, 0x20, 0x10);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation_frame(void*, M2C_UNK, s8);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
s32 get_reploid_status(s32);
extern s32 D_8006D674[];
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj g_playthrough_state;
extern s32 D_800F0E74[];
extern u16 D_800F1688[][2];

void func_800EFCC0(struct X4_AnimatedObj* self) {
    s32 r;
    s32 w;
    s32 i;
    s32 x;
    // !FAKE: depin: dropping it breaks the match (69/84)
    register s32 t asm("$3");

    t = D_800F1688[self->unk2][0];
    x = t + 0x9E;
    self->x_pos.i.hi = x;
    self->y_pos.i.hi = D_800F1688[self->unk2][1];
    t = self->bg_offset;
    if (background_objects[t].x_pos.i.hi < 0x400) {
        self->x_pos.i.hi = x - 0x600;
    }
    func_8002CCB0(self, 0x40, 0x10);
    r = get_reploid_status(g_playthrough_state.character_state.bytes[5] * 16 +
                      self->unk2);
    if (r == 2 &&
        (w = D_8006D674[g_playthrough_state.character_state.bytes[5] * 16 +
                        self->unk2]) != 0) {
        if (w == 1) {
            i = 0x18;
        } else if (w == r) {
            i = 0x19;
        } else {
            for (i = 0; i < 0x18; i++) {
                if (D_800F0E74[i] == w) {
                    goto found;
                }
            }
            i = 0;
        }
    found:
        ((void (*)(void*, s32, s32))set_animation_frame)(self, 3, i);
        return;
    }
    self->on_screen = 0;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
s32 get_reploid_status(s32);
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj g_playthrough_state;

void func_800EFE10(struct X4_AnimatedObj* self) {
    s32 count;
    s32 i;
    s32 base;

    count = 0;
    i = 0;
    do {
        if (get_reploid_status(g_playthrough_state.character_state.bytes[5] * 0x10 +
                          i) == 2) {
            count++;
        }
        i++;
    } while (i < 0x10);
    self->y_pos.i.hi = 0x97;
    base = self->unk2 * 0x18;
    self->x_pos.i.hi = base + 0x7C0;
    if (background_objects[self->bg_offset].x_pos.i.hi < 0x400) {
        self->x_pos.i.hi = base + 0x1C0;
    }
    if (self->unk2 == 0) {
        self->animation_step.fields.frame_index = count / 10 - 0x61;
    } else {
        self->animation_step.fields.frame_index = count % 10 - 0x61;
    }
    func_8002CCB0(self, 0x10, 0x10);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation_frame(void*, M2C_UNK, s8);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj g_playthrough_state;
extern s8 D_800CCEFB;
extern u16 D_800F16C8[][2];

void func_800EFF60(struct X4_AnimatedObj* self) {
    if (self->unk2 != 0) {
        set_animation_frame(self, 5, g_playthrough_state.character_state.bytes[5]);
        self->x_pos.i.hi =
            D_800F16C8[g_playthrough_state.character_state.bytes[5]][0] + 0x782;
        self->y_pos.i.hi =
            D_800F16C8[g_playthrough_state.character_state.bytes[5]][1] + 0xB1;
    } else {
        // !FAKE: depin: dropping it breaks the match (63/66)
        register s32 a asm("$2");
        // !FAKE: depin: dropping it breaks the match (29/66)
        register s32 b asm("$3");
        set_animation_frame(self, 4, D_800CCEFB);
        a = 0x732;
        b = 0x17;
        self->x_pos.i.hi = a;
        self->y_pos.i.hi = b;
    }
    if (background_objects[self->bg_offset].x_pos.i.hi < 0x400) {
        self->x_pos.i.hi -= 0x600;
    }
    func_8002CCB0(self, 0x60, 0x10);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
s32 get_reploid_status(s32);
extern struct X4_BackgroundObj background_objects[3];

void func_800F0068(struct X4_AnimatedObj* self) {
    s32 count;
    s32 i;
    s32 base;

    count = 0;
    i = 0;
    do {
        if (get_reploid_status(i) == 2) {
            count++;
        }
        i++;
    } while (i < 0x80);
    self->y_pos.i.hi = 0x35;
    base = self->unk2 * 0x18;
    self->x_pos.i.hi = base + 0x7A8;
    if (background_objects[self->bg_offset].x_pos.i.hi < 0x400) {
        self->x_pos.i.hi = base + 0x1A8;
    }
    if (self->unk2 == 0) {
        self->animation_step.fields.frame_index = count / 100 - 0x61;
    } else if (self->unk2 == 1) {
        if (count >= 100) {
            count -= 100;
        }
        self->animation_step.fields.frame_index = count / 10 - 0x61;
    } else {
        self->animation_step.fields.frame_index = count % 10 - 0x61;
    }
    func_8002CCB0(self, 0x20, 0x10);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
s32 get_reploid_status(s32);
extern struct X4_BackgroundObj background_objects[3];

void func_800F01D0(struct X4_AnimatedObj* self) {
    s32 count;
    s32 i;
    s32 base;

    count = 0;
    i = 0;
    do {
        if (get_reploid_status(i) == 3) {
            count++;
        }
        i++;
    } while (i < 0x80);
    self->y_pos.i.hi = 0x50;
    base = self->unk2 * 0x18;
    self->x_pos.i.hi = base + 0x7A8;
    if (background_objects[self->bg_offset].x_pos.i.hi < 0x400) {
        self->x_pos.i.hi = base + 0x1A8;
    }
    if (self->unk2 == 0) {
        self->animation_step.fields.frame_index = count / 100 - 0x61;
    } else if (self->unk2 == 1) {
        if (count >= 100) {
            count -= 100;
        }
        self->animation_step.fields.frame_index = count / 10 - 0x61;
    } else {
        self->animation_step.fields.frame_index = count % 10 - 0x61;
    }
    func_8002CCB0(self, 0x20, 0x10);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
s32 get_reploid_status(s32);
extern struct X4_BackgroundObj background_objects[3];

void func_800F0338(struct X4_AnimatedObj* self) {
    s32 count;
    s32 i;
    s32 base;

    count = 0;
    i = 0;
    do {
        if (get_reploid_status(i) == 4) {
            count++;
        }
        i++;
    } while (i < 0x80);
    self->y_pos.i.hi = 0x6A;
    base = self->unk2 * 0x18;
    self->x_pos.i.hi = base + 0x7A8;
    if (background_objects[self->bg_offset].x_pos.i.hi < 0x400) {
        self->x_pos.i.hi = base + 0x1A8;
    }
    if (self->unk2 == 0) {
        self->animation_step.fields.frame_index = count / 100 - 0x61;
    } else if (self->unk2 == 1) {
        if (count >= 100) {
            count -= 100;
        }
        self->animation_step.fields.frame_index = count / 10 - 0x61;
    } else {
        self->animation_step.fields.frame_index = count % 10 - 0x61;
    }
    func_8002CCB0(self, 0x20, 0x10);
}

#define func_80041AB8 func_800F04A0
#define D_80075FD8 D_800F1710
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#define func_80041AB8 func_800F04DC
#define D_80075FD8 D_800F16E8
#define FAMILY_FIELD 5
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation_frame(void*, M2C_UNK, s8);
M2C_UNK func_8002CB50();
extern struct X4_BackgroundObj background_objects[3];
extern u16 D_800F1680[][2];
extern s8 D_800F1CCA[];

void func_800F0518(void* arg0) {
    s8 t;
    u16 v;

    t = *(s8*)((u8*)arg0 + 2);
    set_animation_frame(arg0, t, D_800F1CCA[t]);
    v = D_800F1680[*(s8*)((u8*)arg0 + 2)][0];
    *(u16*)((u8*)arg0 + 0xA) = v;
    *(u16*)((u8*)arg0 + 0xE) = D_800F1680[*(s8*)((u8*)arg0 + 2)][1];
    if (background_objects[*(s8*)((u8*)arg0 + 0x14)].x_pos.i.hi < 0x400) {
        *(u16*)((u8*)arg0 + 0xA) = v - 0x600;
    }
    ((void (*)())func_8002CB50)(arg0);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK); /* extern */
extern struct X4_BackgroundObj background_objects[3];

void func_800F05C0(void* arg0) {
    M2C_FIELD(arg0, s16*, 0xA) = 0x791;
    M2C_FIELD(arg0, s16*, 0xE) = 0xC9;
    if (background_objects[M2C_FIELD(arg0, s8*, 0x14)].x_pos.i.hi < 0x400) {
        M2C_FIELD(arg0, s16*, 0xA) = 0x191;
    }
    func_8002CCB0(arg0, 0x60, 0x10);
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800F0638(void) {
    clear_object_slot();
}

#define func_80041AB8 func_800F0658
#define D_80075FD8 D_800F172C
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern u16 D_800F171C[];

void func_800F0694(void* arg0) {
    M2C_FIELD(arg0, u16*, 0xA) = 0x10;
    M2C_FIELD(arg0, u16*, 0xE) = 0x10;
    if (M2C_FIELD(arg0, s8*, 2) == 0) {
        M2C_FIELD(arg0, u16*, 0x16) = M2C_FIELD(arg0, u16*, 0x1E) =
            D_800F171C[0];
        M2C_FIELD(arg0, u16*, 0x1A) = M2C_FIELD(arg0, u16*, 0x22) =
            D_800F171C[1];
        M2C_FIELD(arg0, u16*, 0x26) = M2C_FIELD(arg0, u16*, 0x2E) =
            D_800F171C[2];
        M2C_FIELD(arg0, u16*, 0x2A) = M2C_FIELD(arg0, u16*, 0x32) =
            D_800F171C[3];
    } else {
        M2C_FIELD(arg0, u16*, 0x16) = M2C_FIELD(arg0, u16*, 0x1E) =
            D_800F171C[4];
        M2C_FIELD(arg0, u16*, 0x1A) = M2C_FIELD(arg0, u16*, 0x22) =
            D_800F171C[5];
        M2C_FIELD(arg0, u16*, 0x26) = M2C_FIELD(arg0, u16*, 0x2E) =
            D_800F171C[6];
        M2C_FIELD(arg0, u16*, 0x2A) = M2C_FIELD(arg0, u16*, 0x32) =
            D_800F171C[7];
    }
    M2C_FIELD(arg0, u16*, 0x38) = 0;
    M2C_FIELD(arg0, u8*, 4) = M2C_FIELD(arg0, u8*, 4) + 1;
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800328B0(void*, void*); /* extern */
extern s8 D_800CCEFC;

void func_800F0750(void* arg0) {
    s32 v;
    s32 q;
    s32 t;
    s32 n;

    n = M2C_FIELD(arg0, u16*, 0x38) + 1;
    M2C_FIELD(arg0, u16*, 0x38) = n;
    if (M2C_FIELD(arg0, s8*, 2) == 0) {
        t = (s16)n * 0x9C / 16;
        M2C_FIELD(arg0, s16*, 0x26) = t;
        M2C_FIELD(arg0, s16*, 0x1E) = t;
    } else {
        v = (s16)n * 0x9C;
        q = v >> 4;
        if (v < 0) {
            q = (v + 15) >> 4;
        }
        t = 0x138 - q;
        M2C_FIELD(arg0, s16*, 0x2E) = t;
        M2C_FIELD(arg0, s16*, 0x16) = t;
    }
    if (M2C_FIELD(arg0, s16*, 0x38) >= 0x10) {
        D_800CCEFC = 1;
        M2C_FIELD(arg0, u8*, 4) = M2C_FIELD(arg0, u8*, 4) + 1;
    }
    func_800328B0(arg0, arg0);
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800328B0(void*, void*); /* extern */
extern s8 D_800CCEFC;

void func_800F0828(void* arg0) {
    if (D_800CCEFC == 2) {
        M2C_FIELD(arg0, s16*, 0x38) = 0;
        M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
    }
    func_800328B0(arg0, arg0);
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800328B0(void*, void*); /* extern */
extern s8 D_800CCEFC;

void func_800F086C(void* arg0) {
    s32 v;
    s32 q;
    s32 t;
    s32 n;

    n = M2C_FIELD(arg0, u16*, 0x38) + 1;
    M2C_FIELD(arg0, u16*, 0x38) = n;
    if (M2C_FIELD(arg0, s8*, 2) == 0) {
        t = (s16)n * 0x9C / 16;
        M2C_FIELD(arg0, s16*, 0x2E) = t;
        M2C_FIELD(arg0, s16*, 0x16) = t;
    } else {
        v = (s16)n * 0x9C;
        q = v >> 4;
        if (v < 0) {
            q = (v + 15) >> 4;
        }
        t = 0x138 - q;
        M2C_FIELD(arg0, s16*, 0x26) = t;
        M2C_FIELD(arg0, s16*, 0x1E) = t;
    }
    if (M2C_FIELD(arg0, s16*, 0x38) >= 0x10) {
        D_800CCEFC = 0;
        M2C_FIELD(arg0, u8*, 4) = M2C_FIELD(arg0, u8*, 4) + 1;
    }
    ((void (*)())func_800328B0)(arg0);
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800F093C(void) {
    clear_object_slot();
}

// clang-format off
INCLUDE_ASM("asm/rock_16/nonmatchings/E9860", func_800F095C);

INCLUDE_ASM("asm/rock_16/nonmatchings/E9860", func_800F0DAC);

INCLUDE_ASM("asm/rock_16/nonmatchings/E9860", func_800F0DC4);

INCLUDE_ASM("asm/rock_16/nonmatchings/E9860", func_800F0DDC);
// clang-format on
