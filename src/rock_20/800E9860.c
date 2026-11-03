// clang-format off
INCLUDE_ASM("asm/rock_20/nonmatchings/E9860", D_800E9860);
// clang-format on

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/rock_20.h"

void func_800F02A0(u8, s8, s32, s16);
void func_800F0784(s32);

#define ENG ((u8*)g_playthrough_state)
#define S_2 (((u8*)arg0)[0x2])
#define S_3 (((u8*)arg0)[0x3])
#define S_60 (((u8*)arg0)[0x60])

void func_800E98E0(void* arg0) {
    extern u8 g_playthrough_state[];
    u8* e = ENG;

    switch ((s8)e[0x27]) {
    case 0:
        if ((u32)(e[0x26] - 1) < 8U) {
            S_60 |= 1 << ((s8)e[0x26] - 1);
            func_800F02A0(0xF8, 2, 0x140, 0x3C);
        } else {
            func_800F02A0(0xF9, 2, 0x140, 0x3C);
        }
        func_800F02A0(0xF0, 2, 0x140, 0x9A);
        break;
    case 1:
        func_800F02A0(0xF7, 2, 0x140, 0x9A);
        if ((u32)(e[0x26] - 1) < 8U) {
            func_800F02A0(0xF8, 2, 0x140, 0x3C);
        } else {
            func_800F02A0(0xF9, 2, 0x140, 0x3C);
        }
        break;
    case 2:
        func_800F02A0(0xF7, 2, 0x140, 0x9A);
        if ((u32)(e[0x26] - 1) < 8U) {
            func_800F02A0(0xF8, 2, 0x140, 0x3C);
        } else {
            func_800F02A0(0xF9, 2, 0x140, 0x3C);
        }
        break;
    }
    func_800F02A0(0x91, 1, 0x1F, 0x18);
    S_3 = 0;
    func_800F0784(0);
    func_800F02A0(6, 2, 0xD2, 0x9A);
    func_800F02A0(7, 3, 0xD2, 0xA8);
    func_800F02A0(8, 4, 0xD2, 0xB6);
    func_800F02A0(9, 5, 0xD2, 0xC4);
    func_800F02A0(4, 6, 0xD2, 0xD2);
    func_800F02A0(0xF1, 3, 0x190, 0xA8);
    func_800F02A0(0xF2, 4, 0x190, 0xB6);
    func_800F02A0(0xF3, 5, 0x180, 0xC4);
    func_800F02A0(0xF4, 6, 0x1B0, 0xD2);
    D_800F48F0 = 6;
    {
        u8* f = ENG;
        f[0x28] = 1;
    }
    S_2++;
}

#undef ENG
#undef S_2
#undef S_3
#undef S_60

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"
#include "mmx6/rock_20.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern u16 D_800C4570;
extern s8 D_800CCEF8;
extern u16 D_800F36B0[];
extern u16 D_800F48EC;
#define D_800F48EC (*(s16*)&D_800F48EC)

void func_800E9B58(struct X4_EngineObj* arg0) {
    extern u8 g_playthrough_state[];
    u8* e;

    if (D_800C4570 & 0x8FF) {
        play_sound(0, 0x22, 0);
        D_800CCEF8 = D_800F48F0;
        arg0->unk2++;
        return;
    }
    if (--D_800F48EC == 0) {
        e = (u8*)&g_playthrough_state;
        e[0x28]++;
        if ((s8)e[0x28] >= D_800F48F0) {
            arg0->unk2++;
            e[0x28] = D_800F48F0;
            return;
        }
        D_800F48EE++;
        D_800F48EC = D_800F36B0[D_800F48EE];
    }
}
#undef D_800F48EC

// clang-format off
INCLUDE_ASM("asm/rock_20/nonmatchings/E9860", func_800E9C4C);

INCLUDE_ASM("asm/rock_20/nonmatchings/E9860", func_800E9D40);
// clang-format on

#include "common.h"
#include "mmx6/globals.h"
#include "mmx6/rock_20.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F02A0(u8, s8, s32, s16);
void func_800F04C8(void*, u8, s8, s32, s32);
s32 func_800F05AC(s32);
s32 func_800F05E8(u8);
s32 func_800F0724(u8, s32);
void func_800F0784(s32);
extern s8 D_800CCEF8;
extern s32 D_800F370C[];
extern s16 D_800F3920[];
extern u16 D_800F48EC;
extern u8 D_800F48F2;
extern u8 D_800F48F5;

#define S_2 M2C_FIELD(self, u8*, 0x2)
#define S_3 M2C_FIELD(self, s8*, 0x3)
#define S_6C M2C_FIELD(self, s32*, 0x6C)
#define S_70 M2C_FIELD(self, s32*, 0x70)

void func_800E9E34(void* self) {
    s32* e;
    s32* f;
    s32 mask;
    s32 mask2;
    s32 i;
    s8 n;

    for (; (s8)D_800F48F2 >= 0; D_800F48F2++) {
        if (func_800F05E8(D_800F48F2) != 0) {
            if (D_800F48F7 == 0) {
                S_3 = 2;
                func_800F0784(2);
                func_800F02A0(0xBA, 2, 0xD2, 0x9A);
                D_800F48F7 = 1;
            }
            func_800F04C8(self, D_800F48F2, (s8)(D_800F48F5 + 2), 0xDC,
                          D_800F3920[(s8)D_800F48F5 + 1]);
            if (part_by_reploid[D_800F48F2] != 0) {
                i = func_800F05AC(part_by_reploid[D_800F48F2]);
                {
                    s32* t = D_800F370C;
                    e = &t[i * 3];
                }
                switch (e[0]) {
                case 1:
                    mask = 0x100 << ((u8)func_800F0724(D_800F48F2, 1) - 1);
                    if (!(S_6C & mask)) {
                        func_800F02A0(((u8*)e)[4], (s8)(D_800F48F5 + 2), 0x48,
                                      D_800F3920[(s8)D_800F48F5 + 1] - 4);
                    }
                    break;
                case 2:
                    mask2 = 0x01000000
                            << ((u8)func_800F0724(D_800F48F2, 2) - 1);
                    if (!(S_6C & mask2)) {
                        func_800F02A0(((u8*)e)[4], (s8)(D_800F48F5 + 2), 0x48,
                                      D_800F3920[(s8)D_800F48F5 + 1] - 4);
                    }
                    break;
                default:
                    f = &D_800F370C[i * 3];
                    if (!(S_70 & f[0])) {
                        func_800F02A0(((u8*)f)[4], (s8)(D_800F48F5 + 2), 0x48,
                                      D_800F3920[(s8)D_800F48F5 + 1] - 4);
                    }
                    break;
                }
            }
            if ((s8)++D_800F48F5 == 4) {
                D_800F48F2++;
                break;
            }
        }
    }
    n = D_800F48F5;
    if (n != 0) {
        D_800F48EE = 0;
        D_800CCEF8 = 1;
        D_800F48F0 = n + 1;
        D_800F48EC = D_800F36CC;
        S_2 = S_2 + 1;
    } else {
        S_2 = 4;
    }
}

#include "../shared/rock_20/func_800EA11C.c"

#include "common.h"
#include "mmx6/globals.h"
#include "mmx6/rock_20.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F02A0(u8, s8, s32, s16);
s32 func_800F05AC(s32);
s32 func_800F05E8(u8);
s32 func_800F0724(u8, s32);
void func_800F0784(s32);
extern s8 D_800CCEF8;
extern u8 D_800CCF2B[];
extern u8 D_800CCF31[];
extern s32 D_800F370C[];
extern s16 D_800F3920[];
extern u16 D_800F48EC;
extern u8 D_800F48F2;
extern u8 D_800F48F4;
extern u8 D_800F48F5;

#define S_2 M2C_FIELD(self, u8*, 0x2)
#define S_3 M2C_FIELD(self, s8*, 0x3)
#define S_38 M2C_FIELD(self, s8*, 0x38)
#define S_6C M2C_FIELD(self, s32*, 0x6C)
#define S_70 M2C_FIELD(self, s32*, 0x70)

#define LINE(a, b, pos)                                                        \
    {                                                                          \
        func_800F02A0((a), (s8)(D_800F48F5 + 2), 0x48,                         \
                      (pos)[(s8)D_800F48F5 + 1] - 4);                          \
        func_800F02A0((b), (s8)(D_800F48F5 + 2), 0xDC,                         \
                      (pos)[(s8)D_800F48F5 + 1]);                              \
    }

#define HEADER()                                                               \
    if (D_800F48F8 == 0) {                                                     \
        func_800F02A0(0x24, 1, 0xC8, 0x9A);                                    \
        D_800F48F8 = 1;                                                        \
    }

void func_800EA1F0(void* self) {
    extern u8 g_playthrough_state[];
    s16* pos;
    s32* e;
    s32* f;
    s32 mask;
    s32 mask2;
    s32 i;
    u8* m;
    s8 n;

    {
        while ((s8)D_800F48F2 >= 0) {
            if (func_800F05E8(D_800F48F2) != 0) {
                if (part_by_reploid[D_800F48F2] != 0) {
                    if (D_800F48F7 == 0) {
                        S_3 = 2;
                        func_800F0784(2);
                        D_800F48F7 = 1;
                    }
                    i = func_800F05AC(part_by_reploid[D_800F48F2]);
                    {
                        s32* t = D_800F370C;
                        e = &t[i * 3];
                    }
                    switch (e[0]) {
                    case 1:
                        mask = 0x100 << ((u8)func_800F0724(D_800F48F2, 1) - 1);
                        if (!(S_6C & mask)) {
                            HEADER();
                            LINE(((u8*)e)[4], ((u8*)e)[5], D_800F3920);
                            D_800CCF2B[S_38] += 2;
                            S_6C |= mask;
                            D_800F48F5++;
                        }
                        break;
                    case 2:
                        mask2 = 0x01000000
                                << ((u8)func_800F0724(D_800F48F2, 2) - 1);
                        if (!(S_6C & mask2)) {
                            HEADER();
                            LINE(((u8*)e)[4], ((u8*)e)[5], D_800F3920);
                            D_800CCF31[S_38] += 2;
                            S_6C |= mask2;
                            D_800F48F5++;
                        }
                        break;
                    default: {
                        s32* t = D_800F370C;
                        f = &t[i * 3];
                    }
                        if (!(S_70 & f[0])) {
                            HEADER();
                            LINE(((u8*)f)[4], ((u8*)f)[5], D_800F3920);
                            S_70 |= f[0];
                            D_800F48F5++;
                        }
                        break;
                    }
                }
                if ((s8)D_800F48F5 == 4) {
                    D_800F48F2++;
                    break;
                }
            }
            D_800F48F2++;
        }
    }
    if ((s8)D_800F48F2 < 0 && (s8)D_800F48F5 < 4) {
        s8 req = D_800F48F4;
        if (req == 1) {
            D_800F48F4 = 0;
            if (D_800F48F7 == 0) {
                S_3 = 2;
                func_800F0784(2);
                D_800F48F7 = req;
            }
            if (D_800F48F8 == 0) {
                func_800F02A0(0x24, 1, 0xC8, 0x9A);
                D_800F48F8 = req;
            }
            switch (g_playthrough_state[0x69] ^ g_playthrough_state[0xC8]) {
            case 0x1:
                LINE(D_800F3844[1], D_800F3844[2], D_800F3920);
                break;
            case 0x2:
                LINE(D_800F3844[4], D_800F3844[5], D_800F3920);
                break;
            case 0x4:
                LINE(D_800F3844[7], D_800F3844[8], D_800F3920);
                break;
            case 0x8:
                LINE(D_800F3844[10], D_800F3844[11], D_800F3920);
                break;
            case 0x10:
                LINE(D_800F3844[13], D_800F3844[14], D_800F3920);
                break;
            case 0x20:
                LINE(D_800F3844[16], D_800F3844[17], D_800F3920);
                break;
            case 0x40:
                LINE(D_800F3844[19], D_800F3844[20], D_800F3920);
                break;
            case 0x80:
                LINE(D_800F3844[22], D_800F3844[23], D_800F3920);
                break;
            }
            D_800F48F5++;
        }
    }
    n = D_800F48F5;
    if (n != 0) {
        D_800F48EE = 0;
        D_800CCEF8 = 1;
        D_800F48F0 = n + 1;
        D_800F48EC = D_800F36CC;
        S_2 = S_2 + 1;
    } else {
        S_2 = 3;
    }
}

#define func_800EA11C func_800EAA80
#include "../shared/rock_20/func_800EA11C.c"
#undef func_800EA11C

#define func_800EA11C func_800EAB54
#include "../shared/rock_20/func_800EA11C.c"
#undef func_800EA11C
