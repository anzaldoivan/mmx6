#ifdef NON_MATCHING
#include "common.h"

extern s8 D_800CD40C;
extern s8 D_80097418;
extern s32 D_800E2E1C;

void func_80018774(s32 arg0) {
    if ((*(u8*)&D_800CD40C) != 0) {
        D_800E2E1C = arg0;
        D_80097418 = 1;
    }
}
#else
// clang-format off
INCLUDE_ASM("main/nonmatchings/120A0", func_80018774);
// clang-format on
#endif

#include "common.h"
#include "mmx6/globals.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80064C94(M2C_UNK*, u32); /* extern */
#define func_80064C94 ((M2C_UNK(*)(M2C_UNK*, u8))func_80064C94)
extern s8 D_800CC869;
#define D_800CC869 (*(u8*)&D_800CC869)

void func_800187A0(s32 arg0) {
    u32 temp_v1;
    u8 temp_a1;

    temp_a1 = arg0 & 0xFF;
    D_800E2E15 = temp_a1;
    if (D_800CC869 == 1) {
        M2C_FIELD(&D_800E2E10, u8*, 0) = temp_a1;
        M2C_FIELD(&D_800E2E10, s8*, 1) = 0;
        M2C_FIELD(&D_800E2E10, u8*, 2) = temp_a1;
        M2C_FIELD(&D_800E2E10, s8*, 3) = 0;
    } else {
        temp_v1 = temp_a1 >> 1;
        M2C_FIELD(&D_800E2E10, u8*, 0) = (u8)temp_v1;
        M2C_FIELD(&D_800E2E10, s8*, 1) = (s8)temp_v1;
        M2C_FIELD(&D_800E2E10, u8*, 2) = (u8)temp_v1;
        M2C_FIELD(&D_800E2E10, s8*, 3) = (s8)temp_v1;
    }
    func_80064C94(&D_800E2E10, temp_a1);
}
#undef D_800CC869
#undef func_80064C94

#include "common.h"
#include "mmx6/globals.h"

extern s8 D_80097418;

void func_8001881C(void) {
    D_80097418 = 0;
    D_800E2E5C = 0;
    D_800E2E4C = 0;
}

#include "common.h"
#include "psyq/libcd.h"
#include "mmx6/globals.h"

#define M2C_UNK s32

s8 func_80064874(M2C_UNK, u8*); /* extern */
extern s8 D_800CD40C;

void func_80018838(void) {
    s8 temp_v0;

    temp_v0 = func_80064874(1, &D_800E2E40);
    if ((temp_v0 == 2) && !(D_800E2E40 & 0x40) &&
        (CdControl(0x1B, 0, &D_800E2E40) != 0)) {
        D_800CD40C = temp_v0;
        D_800E2E18 = (s32)temp_v0;
    }
}

#include "common.h"
#include "psyq/libcd.h"
#include "mmx6/globals.h"

#define M2C_UNK s32

extern s8 D_800E2E16;

void func_800188BC(void) {
    if (D_800E2E48 & D_800A21B4) {
        do {

        } while (CdControl(9, 0, &D_800E2E40) == 5);
        D_800E2E18 = 3;
        if (D_800E2E40 & 0x10) {
            D_800E2E16 = 1;
        }
    }
}

#include "common.h"
#include "psyq/libcd.h"
#include "mmx6/globals.h"

#define M2C_UNK s32

s8 func_80064874(M2C_UNK, u8*); /* extern */
extern s8 D_800E2E16;

void func_80018948(void) {
    s32 temp_v0;

    temp_v0 = func_80064874(1, 0);
    if ((temp_v0 == 2) && (D_800E2E4C != 0) && (D_800A21B4 == 0) &&
        (CdControl(0x1B, 0, &D_800E2E40) != 0)) {
        D_800E2E48 = 0;
        D_800E2E18 = temp_v0;
        if (D_800E2E40 & 0x10) {
            D_800E2E16 = 1;
        }
    }
}

#include "common.h"
#include "psyq/libcd.h"
#define M2C_UNK s32

void func_800187A0(s32 arg0);
#include "psyq/libsnd.h"
#include "mmx6/globals.h"
s8 func_80064874(M2C_UNK, u8*);

void func_800189E4(void) {
    s32 temp_v0;

    temp_v0 = func_80064874(1, 0);
    if (temp_v0 == 2) {
        if (D_800E2E4C == temp_v0) {
            if (CdControlB(9, 0, 0) != 0) {
                SsSetSerialAttr(0, 0, 0);
                D_800E2E14 = 0;
                func_800187A0(0);
                D_800E2E4C = 0;
                D_800E2E18 = 0;
            }
        } else {
            SsSetSerialAttr(0, 0, 0);
            D_800E2E14 = 0;
            func_800187A0(0);
            D_800E2E18 = 0;
        }
    }
}

#include "common.h"
#include "psyq/libcd.h"
#include "mmx6/globals.h"

#define M2C_UNK s32

s8 func_80064874(M2C_UNK, u8*); /* extern */
extern M2C_UNK D_800E2E04;

void func_80018A90(void) {
    s32 var_v0;

    if (func_80064874(1, 0) == 2) {
        if (D_800E2E60 == 0) {
            var_v0 = CdControl(0x15, &D_800E2E04, 0);
        } else {
            var_v0 = CdControlF(0x15, &D_800E2E04);
        }
        if (var_v0 != 0) {
            D_800E2E18 = 1;
        }
        D_800E2E4C = 2;
    }
}

#include "common.h"
#include "psyq/libcd.h"
#include "mmx6/globals.h"

#define M2C_UNK s32

s8 func_80064874(M2C_UNK, u8*); /* extern */
extern M2C_UNK D_800E2E64;

void func_80018B10(void) {
    if ((func_80064874(1, 0) == 2) && (CdControl(0xD, &D_800E2E64, 0) != 0)) {
        D_800E2E18 = 5;
    }
}

/* Adapted from sozud/mmx4 @4e16dfc src/main/55C4.c:func_80016E84, AGPL-3.0; proven shared with X6 by exact signature adc4ba01bdcd (see THIRD_PARTY.md). */
#include "common.h"
#include "psyq/libcd.h"
#include "psyq/libetc.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"
#define D_800E2E40 (*(u8(*)[]) & D_800E2E40)
extern s8 D_800E2E16;

#define M2C_UNK s32
/* libcd command, status and mode bits used here (values as in the SDK's libcd.h) */
#ifndef CdlSetmode
#define CdlSetmode 0x0E
#define CdlComplete 0x02
#define CdlModeSpeed 0x80
#define CdlModeRT 0x40
#define CdlModeSF 0x08
#endif
s8 func_80064874(M2C_UNK, u8*);
void func_80018B60(void) {
    u8 sp10;

    if (((int (*)())func_80064874)(1, 0) == CdlComplete) {
        sp10 = CdlModeSpeed | CdlModeRT | CdlModeSF;
        if (CdControl(CdlSetmode, &sp10, &D_800E2E40) != 0) {
            VSync(3);
            D_800E2E18 = 6;
            if (D_800E2E40[0] & 0x10) {
                D_800E2E16 = 1;
            }
        }
    }
}

#undef D_800E2E40

#include "common.h"

s32 func_80018BE0(s32 arg0, u8* arg1) {
    u16* src;
    u16* dst;
    u16* p;
    u32 flags;
    u32 bit;
    s32 n;
    u32 len;
    u32 off;
    u32 t;
    u16 tmp;

    src = (u16*)arg0;
    dst = (u16*)arg1;
    for (;;) {
        flags = *src++;
        bit = 0x8000;
        n = 16;
        do {
            if (!(bit & flags)) {
                tmp = *src++;
                bit >>= 1;
                n--;
                *dst++ = tmp;
                continue;
            }
            off = *src++;
            t = off & 0xF800;
            if (t != 0) {
                len = t >> 11;
                off &= 0x7FF;
            } else {
                len = *src++;
            }
            if ((len | off) == 0) {
                return;
            }
            if (off == 0) {
                bit >>= 1;
                n--;
                while (len != 0) {
                    *dst++ = 0;
                    len--;
                }
            } else {
                p = dst - off;
                bit >>= 1;
                n--;
                while (len != 0) {
                    *dst++ = *p++;
                    len--;
                }
            }
        } while (n != 0);
    }
}

#include "common.h"

void func_8001A330(u8, s32, s32, s32, s32, s32);
extern s32 D_800CCF60;

void func_80018CBC(void) {
    u8 d[6];
    s32 x;
    s32 h;
    s32 m;
    s32 s;

    if (D_800CCF60 > 0x57E3F) {
        d[0] = 9;
        d[1] = 9;
        d[2] = 5;
        d[3] = 9;
        d[4] = 9;
        d[5] = 9;
    } else {
        x = D_800CCF60;
        d[0] = x / 36000;
        h = x / 3600;
        d[1] = h % 60 % 10;
        m = x / 60 - h * 60;
        d[2] = m / 10;
        d[3] = m % 10;
        s = (x - x / 60 * 60) * 100 / 60;
        d[4] = s / 10;
        d[5] = s % 10;
    }
    func_8001A330(0x3C, 0xA8, 0xD8, 0x21, 1, 0);
    func_8001A330(d[0] + 0x21, 0xB8, 0xD8, 0x21, 1, 0);
    func_8001A330(d[1] + 0x21, 0xC8, 0xD8, 0x21, 1, 0);
    func_8001A330(0x2B, 0xD8, 0xD8, 0x21, 1, 0);
    func_8001A330(d[2] + 0x21, 0xE8, 0xD8, 0x21, 1, 0);
    func_8001A330(d[3] + 0x21, 0xF8, 0xD8, 0x21, 1, 0);
    func_8001A330(0x2C, 0x108, 0xD8, 0x21, 1, 0);
    func_8001A330(d[4] + 0x21, 0x118, 0xD8, 0x21, 1, 0);
    func_8001A330(d[5] + 0x21, 0x128, 0xD8, 0x21, 1, 0);
}

#include "common.h"

extern u8 D_800CCEDC;
#define D_800CCEDC (*(s8*)&D_800CCEDC)
void func_8001A330(u8, s32, s32, s32, s32, s32);
s32 get_reploid_status(s32);

void func_80018F98(void) {
    s32 i;
    s32 n;

    if (D_800CCEDC != 0) {
        n = 0;
        i = 0;
        do {
            if (get_reploid_status(i) == 2) {
                n += 1;
            }
            i += 1;
        } while (i < 0x80);
        func_8001A330(0x39, 0xB0, 0x68, 0x21, 1, 0);
        func_8001A330(n / 100 + 0x21, 0xC0, 0x68, 0x21, 1, 0);
        func_8001A330(n % 100 / 10 + 0x21, 0xD0, 0x68, 0x21, 1, 0);
        func_8001A330(n % 10 + 0x21, 0xE0, 0x68, 0x21, 1, 0);
    }
}
#undef D_800CCEDC

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

void func_8001A330(u8, s32, s32, s32, s32, s32);
extern struct X4_EngineObj g_playthrough_state;

void func_800190FC(void) {
    s32 v;

    if (g_playthrough_state.stage != 0) {
        v = *(s16*)((u8*)&g_playthrough_state + D_800970A2 * 2 + 0xD2);
        if (v >= 10000) {
            v = 9999;
        }
        func_8001A330(0x3B, 0xF0, 0x68, 0x21, 1, 0);
        func_8001A330(v / 1000 + 0x21, 0x100, 0x68, 0x21, 1, 0);
        func_8001A330(v % 1000 / 100 + 0x21, 0x110, 0x68, 0x21, 1, 0);
        func_8001A330(v % 100 / 10 + 0x21, 0x120, 0x68, 0x21, 1, 0);
        func_8001A330(v % 10 + 0x21, 0x130, 0x68, 0x21, 1, 0);
    }
}

#ifdef NON_MATCHING
#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define SP_A0 (*(s32*)SP(0xA0))

void func_8001A330(u8, s32, s32, s32, s32, s32);
void func_80019C84(void);
void func_80018CBC(void);
void func_80018F98(void);
void func_800190FC(void);
s32 get_player_mugshot(void);
void func_800239CC(struct X4_AnimatedObj*);

extern u16 D_80070A48[][4];
extern u16 D_80070AE8[][4];
extern u16 D_80070B88[][4];
extern s8 D_80070BC8[];
extern s8 D_80070BE0[];
extern s16 D_80070BF8[][2];
extern u8 D_80070C08[][0x19];
extern u8 D_80070C3C[];
extern struct X4_PlayerObj g_Player;

#define P_UNK2 (g_Player.character)
#define P_UNKE7 (g_Player.armor)
#define CF_ENGINE ((struct X4_EngineObj*)D_800CF810)
#define CF_CUR (CF_ENGINE->unk14)
#define CF_B(i) ((u8)CF_ENGINE->character_state.bytes[(i) - 0x26])
#define ENG_39 ((u8)g_playthrough_state.player_initial_data[0x39 - 0x49])
#define ENG_464 (g_playthrough_state.player_initial_data[0x464 - 0x49])
#define ENG_6C                                                                 \
    ((s32)(*(union X4_CdSectorBuffer*)&g_playthrough_state).words[0x1B])
#define EX(t, i) ((t)[i][0])
#define EY(t, i) ((t)[i][1])
#define EB(t, i, o) (((u8*)(t)[i])[o])

void func_800192CC(void) {
    s32 e;
    VisObj50 obj;
    u16(*tb)[4];
    u16(*q)[4];
    s16(*r)[2];
    s32 c;
    s32 i;
    s32 j;
    s32 y;
    s32 count;
    s32 a;
    u8 v;
    u8 w;
    s32 k;
    s32 m;
    s32 idx;
    s32 base;
    s32 off;

    func_8001A330(0, 0x120, 0x80, 0x20, 1, 0);
    func_8001A330(1, 0x80, 0x80, 0x20, 1, 0);
    func_8001A330(2, 0xE8, 0xDC, 0x28, 1, 0);
    y = 0xC8;
    func_80019C84();
    if (P_UNK2 != 0) {
        y = 0xB8;
    }
    tb = P_UNK2 == 0 ? D_80070A48 : D_80070AE8;
    for (i = 0; i < 10; i++) {
        s32 ni = -i;
        u8* p0 = (u8*)&D_800CF810;
        u8* xb = p0 + 0x16;
        u8* fp = xb - ni;
        j = i + 10;
        if (fp[0] != 0) {
            if (CF_CUR == i && (D_80097420.frame_counter & 0x10) &&
                D_8008EAF0.unkC == 0) {
                func_8001A330(EB(tb, i, 4), EX(tb, i), EY(tb, i),
                              EB(tb, i, 6) + 0x20, 1, 0);
                func_8001A330(EB(tb, j, 4), EX(tb, j), EY(tb, j),
                              EB(tb, j, 6) + 0x20, 1, 0);
            } else {
                func_8001A330(EB(tb, i, 4), EX(tb, i), EY(tb, i),
                              EB(tb, i, 5) + 0x20, 1, 0);
                func_8001A330(EB(tb, j, 4), EX(tb, j), EY(tb, j),
                              EB(tb, j, 5) + 0x20, 1, 0);
            }
        }
    }
    c = CF_CUR;
    if (c < 10) {
        if (P_UNK2 == 0) {
            func_8001A330(0x47, D_80070A48[c + 10][0] - 0x10,
                          D_80070A48[c + 10][1], 0x21, 1, 0);
        } else {
            func_8001A330(0x47, D_80070AE8[c + 10][0] - 0x10,
                          D_80070AE8[c + 10][1], 0x21, 1, 0);
        }
    } else if (c == 0x17) {
        func_8001A330(0x47, 0x18, y, 0x21, 1, 0);
    }
    q = D_80070B88;
    for (i = 10; i < 0x12; i++) {
        s32 ni = -i;
        u8* p0 = (u8*)&D_800CF810;
        u8* xb = p0 + 0x16;
        u8* fp = xb - ni;
        j = i - 10;
        if (fp[0] != 0) {
            if (CF_CUR == i && (D_80097420.frame_counter & 0x10) &&
                D_8008EAF0.unkC == 0) {
                func_8001A330(EB(q, j, 4), EX(q, j), EY(q, j),
                              EB(q, j, 6) + 0x20, 1, 0);
            } else {
                func_8001A330(EB(q, j, 4), EX(q, j), EY(q, j),
                              EB(q, j, 5) + 0x20, 1, 0);
            }
        }
    }
    r = D_80070BF8;
    for (i = 0; i < 4; i++) {
        v = CF_B(i + 0x28);
        if (v != 0) {
            func_8001A330(D_80070C08[P_UNK2][v], r[i][0], r[i][1], 0x21, 1, 0);
        }
    }
    if (CF_B(0x2D) != 0) {
        w = CF_B(0x2D);
        func_8001A330(w + 0x1A, 0x28, y, 0x21, 1, 0);
        i = w - 1;
        if (ENG_464 != 0) {
            func_8001A330(w + 2, 0x68, y, 0x21, 1, 0);
        } else if (CF_CUR == 0x17 && (D_80097420.frame_counter & 0x10) &&
                   D_8008EAFC == 0) {
            func_8001A330(w + 2, 0x68, y, 0x2A, 1, 0);
        } else {
            func_8001A330(i + 3, 0x68, y, 0x21, 1, 0);
        }
    }
    func_8001A330(ENG_39 + 0x21, 0xCD, 0x33, 0x21, 1, 0);
    func_8001A330(D_80070C3C[CF_B(0x2C)], 0x128, 0x80, 0x21, 1, 0);
    count = 0;
    func_80018CBC();
    for (k = 0; k < 0x10; k++) {
        m = 1 << k;
        if (ENG_6C & m) {
            count++;
        }
    }
    func_8001A330(0x3A, 0xB8, 0x4E, 0x2A, 1, 0);
    func_8001A330(count / 10 + 0x21, 0xC8, 0x4E, 0x21, 1, 0);
    func_8001A330(count % 10 + 0x21, 0xD8, 0x4E, 0x21, 1, 0);
    func_80018F98();
    func_800190FC();
    obj.x = 0x10C;
    obj.y = 0x34;
    obj.bg_offset = -1;
    idx = get_player_mugshot();
    base = SP_A0;
    idx <<= 2;
    idx += base;
    off = *(s32*)idx;
    obj.unk42 = 0x7F80;
    obj.unk47 = 0;
    obj.unk15 = 0;
    obj.unk40 = 0;
    obj.unk16 = 5;
    obj.active = 0x61;
    obj.unk3C = (u8*)(base + off);
    func_800239CC((struct X4_AnimatedObj*)&obj);
    if (CF_CUR == 0x17) {
        a = CF_B(0x2D) + 0x18;
    } else if (P_UNK2 == 0) {
        if (CF_CUR == 9) {
            a = 0x10;
            if (P_UNKE7 != 1) {
                a = 0x11;
                if (P_UNKE7 == 4) {
                    a = 0xF;
                }
            }
            D_80070BC8[9] = a;
        }
        a = D_80070BC8[CF_CUR];
    } else {
        a = D_80070BE0[CF_CUR];
    }
    if (a != -1) {
        func_8001A330(a, 0x120, 0xBF, 0, 2, 2);
    }
}
#undef SP_A0
#undef P_UNK2
#undef P_UNKE7
#undef CF_ENGINE
#undef CF_CUR
#undef CF_B
#undef ENG_39
#undef ENG_464
#undef ENG_6C
#undef EX
#undef EY
#undef EB
#else
// clang-format off
INCLUDE_ASM("main/nonmatchings/120A0", func_800192CC);
// clang-format on
#endif

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

extern u8 D_80070C84[][6];
u32 func_800260C4(s32 arg0, s32 arg1, s32 arg2);
u8 func_8002624C(u8, u8, s32, s32);

#define SCR_BUF (*(s32*)0x1F800000)
#define SCR_PRIM (*(u8**)0x1F800100)
#define SCR_TPAGE (*(u32**)0x1F800104)
#define SETADDR(p, a) (((X4_P_TAG*)(p))->addr = (u32)(a))

void func_800199E0(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4, s32 arg5,
                   s32 arg6) {
    u8* prim;
    u32* tp;
    s32 x1;
    s32 y1;
    u32 c;
    s32 lo;

    x1 = arg0 + arg2;
    tp = SCR_TPAGE;
    prim = SCR_PRIM;
    y1 = arg1 + arg3;
    prim[3] = 8;
    prim[7] = 0x38;
    *(s16*)(prim + 0x8) = arg0;
    *(s16*)(prim + 0xA) = arg1;
    *(s16*)(prim + 0x10) = x1;
    *(s16*)(prim + 0x12) = arg1;
    *(s16*)(prim + 0x20) = x1;
    *(s16*)(prim + 0x22) = y1;
    *(s16*)(prim + 0x18) = arg0;
    *(s16*)(prim + 0x1A) = y1;
    prim[4] = D_80070C84[arg4][0];
    prim[5] = D_80070C84[arg4][1];
    prim[6] = D_80070C84[arg4][2];
    prim[0xC] = D_80070C84[arg4][3];
    prim[0xD] = D_80070C84[arg4][4];
    prim[0xE] = D_80070C84[arg4][5];
    prim[0xC] = func_8002624C(prim[0xC], prim[4], arg5, arg6);
    prim[0xD] = func_8002624C(prim[0xD], prim[5], arg5, arg6);
    prim[0xE] = func_8002624C(prim[0xE], prim[6], arg5, arg6);
    prim[0x1E] = prim[0xE];
    prim[0x1C] = prim[0xC];
    prim[0x1D] = prim[0xD];
    prim[0x14] = prim[4];
    prim[0x15] = prim[5];
    prim[0x16] = prim[6];
    if (D_8008EAFC != 0) {
        c = func_800260C4(prim[4], prim[5], prim[6]) >> 1;
        prim[6] = c;
        prim[5] = c;
        prim[4] = c;
        c = func_800260C4(prim[0xC], prim[0xD], prim[0xE]) >> 1;
        prim[0xE] = c;
        prim[0xD] = c;
        prim[0xC] = c;
        c = func_800260C4(prim[0x14], prim[0x15], prim[0x16]) >> 1;
        prim[0x16] = c;
        prim[0x15] = c;
        prim[0x14] = c;
        c = func_800260C4(prim[0x1C], prim[0x1D], prim[0x1E]) >> 1;
        prim[0x1E] = c;
        prim[0x1D] = c;
        prim[0x1C] = c;
    }
    ((u8*)tp)[3] = 1;
    lo = 4;
    tp[1] = 0xE1000000;
    SETADDR(D_8008EB08[SCR_BUF][0][lo], tp);
    SETADDR(tp, prim);
    D_8008EB08[SCR_BUF][0][lo] = (X4_P_TAG*)prim;
    SCR_PRIM += 0x28;
    SCR_TPAGE += 2;
}

#ifdef NON_MATCHING
#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

void func_800199E0(s16, s16, s16, s16, s32, s32, s32);
void func_80023ED8(void*);
u32 func_800260C4(s32, s32, s32);

extern u8 D_80070C98[];
extern u8 D_8007397C[];
extern u8 D_800CF826[];
extern struct X4_PlayerObj g_Player;

#define PH (((union X4_ShotUnk8C*)&g_Player)->halves)
#define P_MAX (PH[0xA5])
#define CF_B(i) (D_800CF810[i])
#define BUF8(o) (*(s8*)((u8*)buf + (o) - 0x20))
#define BUF16(o) (*(s16*)((u8*)buf + (o) - 0x20))

#define GAUGE_BOX(x, y, ww, h)                                                 \
    {                                                                          \
        s16 w = (ww);                                                          \
        u8 r;                                                                  \
        u8 g;                                                                  \
        r = 0;                                                                 \
        g = 0;                                                                 \
        BUF8(0x57) = -1;                                                       \
        BUF16(0x2A) = (x);                                                     \
        BUF16(0x2E) = (y);                                                     \
        BUF16(0x36) = 0;                                                       \
        BUF16(0x3A) = 0;                                                       \
        BUF16(0x3E) = (w);                                                     \
        BUF16(0x42) = 0;                                                       \
        BUF16(0x46) = (w);                                                     \
        BUF16(0x4A) = (h);                                                     \
        BUF16(0x4E) = 0;                                                       \
        BUF16(0x52) = (h);                                                     \
        if (D_8008EAF0.unkC != 0) {                                            \
            g = (u8)(func_800260C4(0, 0, 0) >> 1);                             \
            r = g;                                                             \
        }                                                                      \
        BUF16(0x54) = (r >> 3) | ((g >> 3) << 5) | ((g >> 3) << 10);           \
        BUF8(0x20) = 0;                                                        \
        BUF8(0x56) = 4;                                                        \
        func_80023ED8(buf);                                                    \
    }

void func_80019C84(void) {
    s32 buf[0x18];
    s32 hp;
    s32 cur;
    s32 max;
    s32 i;
    s32 y;
    s32 k;
    u8* q;
    u8* f;
    u8* g7;

    {
        s8* xb = (s8*)&g_playthrough_state;
        s32 nc = -g_Player.character;
        max = (xb - nc)[0x5B] * 2;
    }
    hp = g_Player.hp & 0x7F;
    cur = hp * 2;
    GAUGE_BOX(0xB0, 0x55, max, 5);
    if ((g_Player.hp & 0x7F) < 9) {
        func_800199E0(0xB0, 0x55, hp * 2, 5, 1, max, cur);
    } else {
        func_800199E0(0xB0, 0x55, hp * 2, 5, 0, max, cur);
    }
    i = 1;
    if (g_Player.character == 0) {
        f = D_800CF826;
        g7 = D_8007397C;
        do {
            if (*(u8*)(i + (s32)f) != 0) {
                max = P_MAX;
                cur = (&PH[0x54])[*(u8*)(i + (s32)g7)];
                func_800199E0(0x28, i * 16 + 0x2B, cur * 0x60 / max, 5, 2, max,
                              cur);
            }
            i++;
        } while (i < 10);
    } else {
        f = D_800CF826;
        y = 0x3B0000;
        q = &D_80070C98[i];
        do {
            if (*(u8*)(i + (s32)f) != 0) {
                k = *q;
                if (k != 0) {
                    max = P_MAX;
                    cur = (&PH[0x54])[k];
                    func_800199E0(0x28, y >> 16, cur * 0x60 / max, 5, 2, max,
                                  cur);
                }
            }
            y += 0x100000;
            i++;
            q++;
        } while (i < 9);
    }
    if (CF_B(0x20) != 0) {
        GAUGE_BOX(0xD8, 0xA9, 0x18, 4);
        max = 0x20;
        {
            u8* e = (u8*)&g_playthrough_state;
            cur = e[0x63] & 0x7F;
        }
        func_800199E0(0xD8, 0xA9, cur * 0x18 / max, 4, 0, max, cur);
    }
    if (CF_B(0x21) != 0) {
        GAUGE_BOX(0xF8, 0xA9, 0x18, 4);
        max = 0x20;
        {
            u8* e = (u8*)&g_playthrough_state;
            cur = e[0x64] & 0x7F;
        }
        func_800199E0(0xF8, 0xA9, cur * 0x18 / max, 4, 0, max, cur);
    }
    if (CF_B(0x22) != 0) {
        GAUGE_BOX(0x118, 0xA9, 0x18, 4);
        max = 0x20;
        {
            u8* e = (u8*)&g_playthrough_state;
            cur = e[0x65] & 0x7F;
        }
        func_800199E0(0x118, 0xA9, cur * 0x18 / max, 4, 2, max, cur);
    }
}
#undef PH
#undef P_MAX
#undef CF_B
#undef BUF8
#undef BUF16
#undef GAUGE_BOX
#else
// clang-format off
INCLUDE_ASM("main/nonmatchings/120A0", func_80019C84);
// clang-format on
#endif

#include "common.h"
#include "mmx6/x4.h"

extern struct X4_MiscObj g_displayed_sprites[];

void func_800232D4(void*);
void func_800239CC(struct X4_AnimatedObj* arg0);

void func_8001A278(void) {
    struct X4_MiscObj* p;

    for (p = g_displayed_sprites; p < g_displayed_sprites + 0x60; p++) {
        if (p->on_screen != 0 && p->id == 0x16) {
            if (p->on_screen == 1) {
                func_800232D4(p);
            }
            if (p->on_screen == 2) {
                func_800239CC(p);
            }
        }
    }
}

// clang-format off
#include "../shared/main/func_8001A330.c"

#ifdef NON_MATCHING
#include "common.h"

#define SCRATCH_3C (*(u8**)0x1F80003C)

void func_8001A3D4(u8* o) {
    u8* p;
    s32 off;
    s32 c;

    *(s16*)(o + 0x40) = 0x1F00;
    p = SCRATCH_3C;
    off = *(s32*)(p + 4);
    c = 0x7C10;
    *(s16*)(o + 0x42) = c;
    *(s8*)(o + 0x14) = -1;
    *(s8*)(o + 0x16) = -1;
    *(u8**)(o + 0x3C) = p + off;
    switch (*(s8*)(o + 2)) {
    case 0:
    case 3:
        o[5] = 0;
        break;
    case 1:
    case 4:
        o[5] = 1;
        break;
    case 2:
    case 5:
        o[5] = 2;
        break;
    case 6:
        o[0x47] = 0x16;
        o[5] = 3;
        break;
    case 7:
        o[0x47] = 0x17;
        o[5] = 3;
        break;
    case 8:
        o[0x47] = 0x23;
        o[5] = 3;
        break;
    case 9:
        o[0x47] = 0x22;
        o[5] = 3;
        break;
    }
    o[4]++;
}

#undef SCRATCH_3C
#else
INCLUDE_ASM("main/nonmatchings/120A0", func_8001A3D4);
#endif
// clang-format on

#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EngineObj g_playthrough_state;

void func_8001A494(s8* arg0) {
    s8 q;
    s32 v;

    q = arg0[2] / 3;
    {
        s32 k = 0xD0;
        v = ((s8*)&g_playthrough_state - -q)[k];
    }
    if (q != 0) {
        v = -v;
    }
    if (v < 0) {
        arg0[0x47] = 0x24;
        arg0[3] = 1;
        return;
    }
    arg0[3] = 0;
}

#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EngineObj g_playthrough_state;

void func_8001A4FC(u8* arg0) {
    // !FAKE: row base in the first return register
    register s8* b asm("$2");
    // !FAKE: idx in the first argument register
    register s32 i asm("$4");
    // !FAKE: value in the second return register
    register s32 v asm("$3");

    i = (s8)((s8)arg0[2] / 3);
    b = (s8*)&g_playthrough_state;
    b -= -i;
    v = b[0xD0];
    if (v < 0) {
        v = -v;
    }
    if (v >= 10) {
        arg0[0x47] = 0x19;
        arg0[3] = 1;
        return;
    }
    arg0[3] = 0;
}

#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EngineObj g_playthrough_state;

void func_8001A570(u8* arg0) {
    s32 v;
    s8 i;
    s8* p;

    i = (s8)arg0[2] / 3;
    p = (s8*)&g_playthrough_state;
    v = __builtin_abs((p - -i)[0xD0]);
    arg0[3] = 1;
    arg0[0x47] = (v % 10) + 0x18;
}

#include "../shared/stage/func_8001A5F8.c"

#include "common.h"

extern void (*D_80070C6C[])(s8*);
extern u16 D_80070C44[][2];

void func_8001A604(s8* arg0) {
    D_80070C6C[arg0[5]](arg0);
    *(u16*)(arg0 + 0xA) = D_80070C44[arg0[2]][0];
    *(u16*)(arg0 + 0xE) = D_80070C44[arg0[2]][1];
}

#include "common.h"
#include "mmx6/globals.h"

void clear_object_slot(void* arg0);
extern void (*D_80070C7C[])(s8*);

void func_8001A674(s8* arg0) {
    if (D_800CCED1 == 0) {
        ((void (*)())clear_object_slot)();
    } else {
        D_80070C7C[arg0[4]](arg0);
    }
}
