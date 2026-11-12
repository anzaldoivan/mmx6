#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

s32 play_sound(s32, s32, void*);
s32 func_800139F4(s32);
extern u8 option_values[];
#include "mmx6/state.h"

#define MODE (D_80097420.transition.active)
#define CUR (D_80097420.transition.selection)

void func_8002A76C(void) {
    u8 i;
    u8 j;
    u8 sel;
    u16 btn;
    u16 tmp;

    if (MODE == 0) {
        if ((g_pad1_buttons[2] & 0x800) ||
            ((g_pad1_buttons[2] & 0x40) && CUR == 0xB)) {
            play_sound(0, 0x22, 0);
            ((void (*)(s32))func_800139F4)(0x20);
            D_800E4188++;
            return;
        }
        if (g_pad1_buttons[2] & 0x1000) {
            play_sound(0, 0xC, 0);
            if (CUR == 0) {
                D_80097420.transition.selection = 0xB;
            } else {
                D_80097420.transition.selection--;
            }
        }
        if (g_pad1_buttons[2] & 0x4000) {
            play_sound(0, 0xC, 0);
            if (CUR == 0xB) {
                D_80097420.transition.selection = 0;
            } else {
                D_80097420.transition.selection++;
            }
        }
        sel = 0xFF;
        if (CUR < 7) {
            for (i = 4; i < 0x10; i++) {
                if ((1 << i) == D_80073610[CUR]) {
                    sel = i;
                    break;
                }
            }
            if (sel != 0xFF) {
                btn = g_pad1_buttons[2];
                for (i = 0; i < 8; i++) {
                    if (btn == D_80073620[i]) {
                        play_sound(0, 0x22, 0);
                        tmp = button_map[sel];
                        button_map[sel] = D_80073620[i];
                        for (j = 0; button_map[j] != 0; j++) {
                            if (j != sel && button_map[j] == D_80073620[i]) {
                                button_map[j] = tmp;
                            }
                        }
                        return;
                    }
                }
            }
        } else if (CUR < 0xB && (g_pad1_buttons[2] & 0x40)) {
            play_sound(0, 0x22, 0);
            g_temp_options ^= option_values[CUR - 7];
        }
    }
}

#include "common.h"
#include "mmx6/globals.h"

static inline void func_8002AA74_fill(u8* p, u8 c, u16 n) {
    while (n--) {
        *p++ = c;
    }
}

void func_8002AA74(void) {
    u8 c;
    u16 i;

    c = 0;
    for (i = 0; i < 32; i++) {
        func_8002AA74_fill(D_800964A0 + i * 96, c, 96);
    }
}

#include "common.h"
#include "mmx6/globals.h"

void func_8002AACC(u8* arg0) {
    u16 i;
    u16 j;
    u8* p;
    u8 v;

    v = 0;
    if (D_80097420.transition.active == 0) {
        arg0[6]++;
        D_800CCF99 = g_temp_options;
        for (i = 0; i < 32; i++) {
            p = &D_800964A0[i * 96];
            for (j = 95; j != 0xFFFF; j--) {
                *p++ = v;
            }
        }
        D_800E4188 = 0;
    }
}

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

extern void (*D_80073674[])();
void func_800210E8(void);
void func_80025E1C();

M2C_UNK func_8002AB58(s32 arg0) {
    D_80073674[D_800E4188](arg0);
    func_800210E8();
    func_80025E1C();
}

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

extern s32* D_80073680[][2];
// !FAKE: flat alias of the TU's D_80090C90[][16]; the 2-D type changes %lo offset folding
extern s32 D_80090C90_flat[];
#define D_80090C90 D_80090C90_flat
extern s16 D_80090D5C;
extern s16 D_80097430;
extern struct X4_EngineObj g_playthrough_state;
extern s16 D_800CF854;
static inline void func_8002ABA8_clear3(void) {
    s16* c = &D_800CF854;
    s16* b = &D_80097430;
    s16* a = &D_80090D5C;
    a[1] = 0;
    b[1] = 0;
    c[1] = 0;
}

void func_8002ABA8(void) {
    s32* src;
    s32 i;
    s32 j;

    func_8002ABA8_clear3();
    for (i = 0; i < 16; i++) {
        D_80090C90[i + 16] = 0;
    }
    src = D_80073680[g_playthrough_state.stage][g_playthrough_state.substage];
    D_800C4560 |= 1;
    if (src == 0) {
        for (j = 19; j < 31; j++) {
            D_80090C90[j] = -1;
        }
    } else {
        for (j = 0; j < 16; j++) {
            D_80090C90[j + 16] = *src++;
        }
    }
    func_8002ABA8_clear3();
}
#undef D_80090C90

#include "common.h"
#include "mmx6/globals.h"

extern s32 D_80090C90[][16];
#define D_80090C90 (*(s32(*)[]) & D_80090C90)
extern s8 D_80090D56;
#define D_80090D56 (*(u8*)&D_80090D56)
extern s16 D_80090D5C;
extern s8 D_8009742C;
#define D_8009742C (*(u8*)&D_8009742C)
extern s16 D_80097430;
extern u16 D_80097754;
extern u16 D_800A21B6;
extern u16 D_800C8858;
extern s8 D_800CF850;
#define D_800CF850 (*(u8*)&D_800CF850)
extern s16 D_800CF854;

#define SCRATCH_PAL (*(u16**)0x1F800028)

void func_8002ACA8(void) {
    u16* dst;
    u16* src;
    u32 i;
    u32 j;
    s32 mask;
    u16 c;
    u32 r;
    u32 g;
    u32 b;
    u32 lim;

    if (((D_800CF854 | D_80097430 | D_80090D5C) != 0) || (D_800C4560 & 4)) {
        if ((D_80097754 != (u16)D_800CF854) ||
            (D_800C8858 != (u16)D_80097430) ||
            (D_800A21B6 != (u16)D_80090D5C) || (D_800C4560 != 0)) {
            dst = D_80097798;
            i = 0;
            src = SCRATCH_PAL;
            do {
                if ((i & 0x1F) == 0) {
                    mask = D_80090C90[i >> 5];
                }
                if (mask < 0) {
                    j = 0;
                    do {
                        c = *src++;
                        if (c == 0) {
                            *dst = 0;
                        } else {
                            if (D_800CF850) {
                                lim = (u16)D_800CF854;
                                r = 0;
                                if ((c & 0x1F) >= lim) {
                                    r = (c & 0x1F) - lim;
                                }
                            } else {
                                r = (c & 0x1F) + (u16)D_800CF854;
                                if (r >= 0x20) {
                                    r = 0x1F;
                                }
                            }
                            if (D_8009742C) {
                                lim = (u16)D_80097430;
                                g = 0;
                                if ((c & 0x3E0) >= lim) {
                                    g = (c & 0x3E0) - lim;
                                }
                            } else {
                                g = (c & 0x3E0) + (u16)D_80097430;
                                if (g >= 0x3E1) {
                                    g = 0x3E0;
                                }
                            }
                            if (D_80090D56) {
                                lim = (u16)D_80090D5C;
                                b = 0;
                                if ((c & 0x7C00) >= lim) {
                                    b = (c & 0x7C00) - lim;
                                }
                            } else {
                                b = (c & 0x7C00) + (u16)D_80090D5C;
                                if (b >= 0x7C01) {
                                    b = 0x7C00;
                                }
                            }
                            *dst = r | g | b | (c & 0x8000);
                        }
                        j++;
                        dst++;
                    } while (j < 0x10);
                } else {
                    j = 0;
                    do {
                        *dst++ = *src++;
                        j++;
                    } while (j < 0x10);
                }
                mask <<= 1;
                i++;
            } while (i < 0x200);
            D_800C4560 = 2;
            D_80097754 = D_800CF854;
            D_800C8858 = D_80097430;
            D_800A21B6 = D_80090D5C;
        }
    }
}

#undef D_80090C90
#undef D_80090D56
#undef D_8009742C
#undef D_800CF850

#include "common.h"
#include "mmx6/globals.h"

extern s32 D_80090C90[][16];
extern s16 D_80090D5C;
#define D_80090D5C ((u16*)&D_80090D5C)
extern s16 D_80097430;
#define D_80097430 ((u16*)&D_80097430)
extern s8 D_800CF850;
#define D_800CF850 ((u8*)&D_800CF850)
extern s16 D_800CF854;
#define D_800CF854 ((u16*)&D_800CF854)
#define PAL_SRC (*(u16**)0x1F800028)

void func_8002AF6C(s32 arg0, s32 mask) {
    u16* src;
    u16* dst;
    u32 i;
    u32 j;
    u32 r;
    u32 g;
    u32 b;
    u16 c;
    u16 out;

    if (D_800C4560 == 2) {
        src = D_80097798;
    } else if (D_800C4560 == 8) {
        src = D_8009E1B0;
    } else {
        src = PAL_SRC;
    }
    dst = D_8009E1B0;
    D_800C4560 = 8;
    for (i = 0; i < 0x200; i++) {
        if (!(i & 0x1F)) {
            mask = D_80090C90[arg0][i >> 5];
        }
        j = 0;
        if (mask < 0) {
            if (D_800CF850[arg0] != 0) {
                u16* d = dst;
                u16* s = src;
                s32 num = D_800CF854[arg0];
                s32 k;

                if (num >= 0x1F) {
                    num = 0x1F;
                }
                if (num == 0x1F) {
                    for (k = 0; k < 16; k++) {
                        *d++ = 0;
                    }
                } else {
                    for (k = 0; k < 16; k++) {
                        c = *s++;
                        r = (c & 0x1F) << 8;
                        g = (c & 0x3E0) << 8;
                        b = (c & 0x7C00) << 8;
                        r = (r - r * num / 32) >> 8;
                        g = (g - g * num / 32) >> 8;
                        b = (b - b * num / 32) >> 8;
                        r &= 0x1F;
                        g &= 0x3E0;
                        b &= 0x7C00;
                        out = r | g | b | (c & 0x8000);
                        if (out == 0 && c != 0) {
                            out = 0x8000;
                        }
                        *d++ = out;
                    }
                }
                src += 16;
                dst += 16;
            } else {
                u32 r2;
                u32 g2;
                u32 b2;
                u16 c2;

                for (j = 0; j < 16; j++) {
                    c2 = *src++;
                    r2 = (c2 & 0x1F) + D_800CF854[arg0];
                    if (r2 > 0x1F) {
                        r2 = 0x1F;
                    }
                    g2 = (c2 & 0x3E0) + D_80097430[arg0];
                    if (g2 > 0x3E0) {
                        g2 = 0x3E0;
                    }
                    b2 = (c2 & 0x7C00) + D_80090D5C[arg0];
                    if (b2 > 0x7C00) {
                        b2 = 0x7C00;
                    }
                    if (r2 == 0x1F && g2 == 0x3E0 && b2 == 0x7C00) {
                        *dst = 0x7FFF;
                    } else if (r2 | g2 | b2) {
                        *dst = r2 | g2 | b2 | (c2 & 0x8000);
                    } else {
                        *dst = 0;
                    }
                    dst++;
                }
            }
        } else {
            for (j = 0; j < 16; j++) {
                *dst++ = *src++;
            }
        }
        mask <<= 1;
    }
}

#undef D_80090D5C
#undef D_80097430
#undef D_800CF850
#undef D_800CF854
#undef PAL_SRC

#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
extern M2C_UNK g_Player;
void func_8002AF6C(s32 arg0, s32 mask);

void func_8002B29C(void) {
    struct X4_PlayerObj* p = &g_Player;

    if (((u8*)p)[0xE4] & 1) {
        ((void (*)())func_8002AF6C)(1);
    }
    if (((u8*)p)[0xE4] & 2) {
        ((void (*)())func_8002AF6C)(2);
    }
}

#include "common.h"
#include "mmx6/globals.h"

extern s32 D_80090C90[][16];
extern s16 D_80090D5C;
extern s16 D_80097430;
extern s16 D_800CF854;

s32 func_8002B2F8(s32 arg0) {
    s32 i;
    s32 j;
    s32 o;

    o = arg0 * 2;
    *(s16*)(o + (s32)&D_80090D5C) = 0;
    *(s16*)(o + (s32)&D_80097430) = 0;
    *(s16*)(o + (s32)&D_800CF854) = 0;
    for (i = 0, j = 15; i < 16; i++, j--) {
        ((s32*)D_80090C90)[arg0 * 16 + j] = 0;
    }
    D_800C4560 |= 1;
}

#include "common.h"

extern s32 D_80090C90[][16];
extern s16 D_80090D5C;
extern s16 D_80097430;
extern s16 D_800CF854;

void func_8002B36C(s32 arg0) {
    s32 i;
    s32 v;
    s32 t;

    v = -1;
    t = arg0 * 2;
    *(s16*)((u8*)&D_80090D5C + t) = 0;
    *(s16*)((u8*)&D_80097430 + t) = 0;
    *(s16*)((u8*)&D_800CF854 + t) = 0;
    for (i = 15; i >= 0; i--) {
        D_80090C90[arg0][i] = v;
    }
}
