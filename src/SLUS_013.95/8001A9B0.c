#include "common.h"
#include "psyq/libetc.h"
#include "psyq/libgpu.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

void func_80012A34(void);
void func_8001ACC4(s32, s32, s32, s32);
s32 func_8001B184(s32, s32);
void func_8001B6D0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5,
                   s32 arg6, s32 arg7, s32 arg8, s32 arg9);
void func_8001B784(void);
void func_8001B7A8(void);
void func_8001B90C(u32 arg0);
void func_8001B984(s32);

extern X4_RECT D_80010090;
#define DB_DISP(i) (*(X4_DISPENV*)(g_draw_info_buffers + (i) * 0xF0))
extern s32 D_800E2E6C;

void func_8001A9B0(void) {
    X4_RECT rect = D_80010090;
    s32 a1;
    s32 done;
    s32 b0 = 0x80103000;
    // !FAKE: depin: dropping it breaks the match (22/197)
    register s32 b1 asm("$6") = 0x80107000;
    // !FAKE: depin: dropping it breaks the match (20/197)
    register s32 b2 asm("$7") = 0x80115000;
    s32 b3 = 0x80123000;

    D_800E2E70 = b0;
    D_800E2E74 = b1;
    D_800E2E78 = b2;
    D_800E2E7C = b3;
    func_8001ACC4(0x140, 0xF0, D_800E2E74, D_800E2E78);
    func_8001B90C(0x80);
    func_8001B984(1);
    D_800E2E65 = 1;
    done = ((s32(*)(s32, s32, s32, s32, s32, s32, s32, s32, s32,
                    s32))func_8001B6D0)(0xF3, 1, str_movie_table[2], D_800E2E7C,
                                        str_movie_table[3], D_800E2E74,
                                        D_800E2E78, D_800E2E70, 1, 1);
    D_800E2E6C = 0;
    if (done == 0) {
        do {
            a1 = 0;
            D_800E2E6C ^= 1;
            if (D_800E2E6C != 0) {
                a1 = 0xF0;
            }
            done = func_8001B184(0, a1);
            func_8001B784();
            VSync(0);
            func_80012A34();
            if (g_pad1_buttons[2] & str_movie_table[5]) {
                done = 1;
            }
            PutDispEnv(&DB_DISP(D_800E2E6C));
        } while (done == 0);
    }
    rect.x = 0;
    rect.y = 0;
    rect.w = 0x1E0;
    rect.h = 0x1E0;
    ClearImage(&rect, 0, 0, 0);
    DrawSync(0);
    func_8001B7A8();
    ((void (*)(s32))SetDispMask)(0);
    g_pad1_buttons[2] = 0;
    g_pad1_buttons[0] = 0;
    DB_DISP(0) = D_800E2E88[0];
    DB_DISP(1) = D_800E2E88[1];
    D_800E2E6C ^= 1;
    PutDispEnv(&DB_DISP(D_800E2E6C));
    DrawSync(0);
    VSync(0);
    DrawSync(0);
}
#undef DB_DISP

#include "common.h"
#include "psyq/libetc.h"
#include "psyq/libgpu.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define DB_DISP(i) (*(X4_DISPENV*)(g_draw_info_buffers + (i) * 0xF0))

void func_8001ACC4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    X4_RECT rect;

    D_800E2E88[0] = DB_DISP(0);
    D_800E2E88[1] = DB_DISP(1);
    ResetGraph(0);
    rect.x = 0;
    rect.y = 0;
    rect.w = 0x1E0;
    rect.h = 0x1E0;
    VSync(0);
    ClearImage(&rect, 0, 0, 0);
    DrawSync(0);
    SetDispMask(1);
    SetDefDispEnv(g_draw_info_buffers, 0, 0, arg0, arg1);
    SetDefDispEnv(g_draw_info_buffers + 0xF0, 0, 0xF0, arg0, arg1);
    {
        // !FAKE: depin: dropping it breaks the match (93/96)
        register s32 one asm("$3") = 1;
        g_draw_info_buffers[0x101] = one;
        g_draw_info_buffers[0x11] = one;
    }
    g_draw_info_buffers[0x100] = 0;
    g_draw_info_buffers[0x10] = 0;
}
#undef DB_DISP

// clang-format off
#include "../shared/SLUS_013.95/func_8001AE44.c"
// clang-format on

#include "common.h"
#include "psyq/libcd.h"
#include "psyq/libetc.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#include "psyq/libpress.h"
extern s32 D_800E2EB0;
extern s32 D_800E2EC0[];
extern s32 D_800E2EC8;
extern s32 D_800E2ECC;
extern s32 D_800E2ED0;
extern s32 D_800E2ED8;
extern s32 D_800E2EE8[];
extern s32 D_800E2F08;
extern s32 D_800E2F0C;
extern X4_RECT D_800E2F10;
extern u32* D_800E2F18;
extern s32 D_800E2F1C;
extern s32 D_800E2F20;
extern u32 D_800E2F24;
extern u32 D_800E2F28;
extern s32 D_800E2F30;
extern s32 D_800E2F34;

s32 func_8001B184(s32 arg0, s32 arg1) {
    s32 sp10;
    s32* sp14;
    s32 ret;
    s32 t;
    u32 x;
    s32* p;
    s32 y;
    s32 n;
    s16 w;
    u32 i;

    i = 0;
    while (StGetNext(&sp10, &sp14) != 0) {
        VSync(0);
        i++;
        if (i >= 0x259) {
            return 1;
        }
    }
    w = 0x10;
    p = D_800E2EE8;
    D_800E2F10.x = arg0;
    D_800E2F10.y = arg1;
    D_800E2F08--;
    x = ((u16*)p)[8];
    D_800E2F30 = x;
    D_800E2F34 = ((u16*)p)[9];
    D_800E2EB0 = p[2];
    ret = (u32)p[2] >= (u32)D_800E2ECC;
    if (D_800E2ED0 != 0) {
        w = 0x18;
    }
    D_800E2F10.w = w;
    D_800E2F24 = 0;
    D_800E2F28 = x >> 4;
    D_800E2F10.h = D_800E2F34;
    D_800E2F18 = (u32*)D_800E2EC8;
    {
        s32 z = ((u16*)p)[9];
        s32 u;
        D_800E2F20 = D_800E2ED0 != 0 ? (u = z << 2, (z << 3) + u) : z * 8;
    }
    if (D_800E2F0C == 0) {
        D_800E2F1C = 0;
    } else {
        s32 u;
        y = D_800E2F34;
        D_800E2F1C = D_800E2ED0 != 0 ? (u = y << 2, (y << 3) + u) : y * 8;
    }
    DecDCTReset(1);
    DecDCTin(D_800E2EC0[D_800E2ED8], D_800E2ED0);
    do {
        n = D_800E2F20;
    } while (0);
    DecDCTout((X4_u_long*)D_800E2EC8, n);
    D_800E2EE8[0] = sp14[0];
    D_800E2EE8[1] = sp14[1];
    D_800E2EE8[2] = sp14[2];
    D_800E2EE8[3] = sp14[3];
    D_800E2EE8[4] = sp14[4];
    D_800E2EE8[5] = sp14[5];
    t = D_800E2ED8 == 0;
    D_800E2ED8 = t;
    D_800E2EE8[6] = sp14[6];
    D_800E2EE8[7] = sp14[7];
    ((u16*)D_800E2EE8)[8] = (((u16*)D_800E2EE8)[8] + 8) / 16 * 16;
    ((u16*)D_800E2EE8)[9] = (((u16*)D_800E2EE8)[9] + 8) / 16 * 16;
    DecDCTvlc(sp10, D_800E2EC0[t], t);
    StFreeRing(sp10);
    return ret;
}

/* Adapted from sozud/mmx4 @807a01b src/main/55C4.c:func_80019100, AGPL-3.0; proven shared with X6 by exact signature f2a2862257fa (see THIRD_PARTY.md). */
#include "common.h"
#include "psyq/libcd.h"
#include "psyq/libgpu.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "psyq/libpress.h"
extern s32 D_800E2ED0;
extern volatile s32 D_800E2F2C;
extern s32 D_800E2F0C;
extern X4_RECT D_800E2F10;
extern u32* D_800E2F18;
extern s32 D_800E2F1C;
extern s32 D_800E2F20;
extern u32 D_800E2F24;
extern u32 D_800E2F28;
extern s32 D_800E584C;

void func_8001B428(void) {
    u32* temp_a0;

    D_800E2F24 += 1;
    if (D_800E584C != 0) {
        StCdInterrupt();
        D_800E584C = 0;
    }
    if (D_800E2F0C == 0) {
        LoadImage(&D_800E2F10, D_800E2F18);
    }
    if ((u32)D_800E2F24 < (u32)D_800E2F28) {
        D_800E2F10.x += (D_800E2ED0 ? 0x18 : 0x10);
        temp_a0 = &D_800E2F18[D_800E2F1C];
        D_800E2F18 = temp_a0;
        DecDCTout(temp_a0, D_800E2F20);
        D_800E2F2C = 1;
        return;
    }
    D_800E2F2C = 0;
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

#include "psyq/libsnd.h"
M2C_UNK func_80064C94(M2C_UNK*, u32);
extern u32 D_80070CC0;
extern s8 D_800CC869;
#define D_800CC869 (*(u8*)&D_800CC869)
extern M2C_UNK D_800E2F3C;

void func_8001B520(void) {
    s32 i;
    s32 h;

    ((void (*)(M2C_UNK, M2C_UNK, M2C_UNK))SsSetSerialAttr)(0, 0, 1);
    if (D_800CC869 != 0) {
        i = 0;
        do {
            M2C_FIELD(&D_800E2F3C, s8*, 0) = i;
            M2C_FIELD(&D_800E2F3C, s8*, 1) = 0;
            M2C_FIELD(&D_800E2F3C, s8*, 2) = i;
            M2C_FIELD(&D_800E2F3C, s8*, 3) = 0;
            ((M2C_UNK(*)())func_80064C94)(&D_800E2F3C);
            i += 2;
        } while (D_80070CC0 >= i);
        return;
    }
    i = 0;
    do {
        h = i / 2;
        M2C_FIELD(&D_800E2F3C, s8*, 0) = h;
        M2C_FIELD(&D_800E2F3C, s8*, 1) = h;
        M2C_FIELD(&D_800E2F3C, s8*, 2) = h;
        M2C_FIELD(&D_800E2F3C, s8*, 3) = h;
        ((M2C_UNK(*)())func_80064C94)(&D_800E2F3C);
        i += 2;
    } while (D_80070CC0 >= i);
}
#undef D_800CC869

/* Adapted from sozud/mmx4 @807a01b src/main/55C4.c:func_800192F8, AGPL-3.0; proven shared with X6 by exact signature 9577b76e9365 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32
M2C_UNK func_80064C94(M2C_UNK*, u32);
#define func_80064C94 ((int (*)(X4_CdlATV * vol)) func_80064C94)
extern u32 D_80070CC0;
extern M2C_UNK D_800E2F3C;
#define D_800E2F3C (*(X4_CdlATV*)&D_800E2F3C)
extern s8 D_800CC869;
#define D_800CC869 (*(u8*)&D_800CC869)

#include "psyq/libsnd.h"
void func_8001B5FC(void) {
    s32 temp_v0;
    s32 var_s0;

    ((void (*)())SsSetSerialAttr)(0, 0, 0);
    if (D_800CC869 != 0) {
        var_s0 = D_80070CC0;
        if (var_s0 >= 0) {
            do {
                D_800E2F3C.val0 = var_s0;
                D_800E2F3C.val1 = 0;
                D_800E2F3C.val2 = var_s0;
                D_800E2F3C.val3 = 0;
                func_80064C94(&D_800E2F3C);
                var_s0 -= 2;
            } while (var_s0 >= 0);
        }
    } else {
        var_s0 = D_80070CC0;
        if (var_s0 >= 0) {
            do {
                temp_v0 = var_s0 / 2;
                D_800E2F3C.val0 = temp_v0;
                D_800E2F3C.val1 = temp_v0;
                D_800E2F3C.val2 = temp_v0;
                D_800E2F3C.val3 = temp_v0;
                func_80064C94(&D_800E2F3C);
                var_s0 -= 2;
            } while (var_s0 >= 0);
        }
    }
}
#undef D_800CC869
#undef D_800E2F3C
#undef func_80064C94

/* Adapted from sozud/mmx4 @807a01b src/main/55C4.c:func_80018AD0, AGPL-3.0; proven shared with X6 by exact signature fae0caed2311 (see THIRD_PARTY.md). */
#include "common.h"
s32 func_80016548(s32 arg0, s32* arg1);
extern s32 func_8001AE44(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);

// ! upstream returns s32; X6 siblings (play_str_movie.c, func_8001A9B0.c) declare it void
void func_8001B6D0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5,
                   s32 arg6, s32 arg7, s32 arg8, s32 arg9) {
    s32 local;

    func_8001AE44(func_80016548(arg0, &local), arg1, arg2, arg3, arg4, arg5,
                  arg6, arg7, arg8, arg9);
}

/* Adapted from sozud/mmx4 @807a01b src/main/55C4.c:func_80018EEC, AGPL-3.0; proven shared with X6 by exact signature e997ebfce7dc (see THIRD_PARTY.md). */
#include "common.h"
extern s32 D_800E2ED0;
extern s32 D_800E2ED4;
extern volatile s32 D_800E2F2C;

void func_8001B784(void) {
    do {

    } while (D_800E2F2C != 0);
    D_800E2ED0 = D_800E2ED4;
}

#include "common.h"
#include "psyq/libcd.h"
#include "psyq/libetc.h"

#define M2C_UNK s32

#include "mmx6/x4.h"

void func_8001B5FC(void);
X4_CdlCB func_800648B4(X4_CdlCB func);
void func_80064DD4(s32);
#include "psyq/libpress.h"

void func_8001B7A8(void) {
    u8 sp10;

    sp10 = 0x80;
    func_8001B5FC();
    DecDCTReset(0);
    do {

    } while (CdControlB(9, 0, 0) == 0);
    VSync(0);
    func_80064DD4(0);
    func_800648B4(0);
    DecDCToutCallback(0);
    StUnSetRing();
    do {

    } while (CdReset(0) == 0);
    VSync(3);
    do {

    } while (CdControl(0xE, (s32)&sp10, 0) == 0);
    VSync(3);
}

#include "common.h"
#include "psyq/libgpu.h"
#define M2C_UNK s32

void func_8001B84C(s32* arg0, s32 arg1, s32 arg2, u32 arg3, s32 arg4,
                   s32 arg5) {
    s16 rect[4];
    s32 h;
    u32 i;
    u32 t;

    h = 0x10;
    if (arg5 != 0) {
        h = 0x18;
    }
    rect[0] = arg1;
    rect[1] = arg2;
    rect[2] = h;
    rect[3] = arg4;
    t = (u32)(h * arg4) >> 1;
    for (i = 0; i < arg3 >> 4; i++) {
        LoadImage((M2C_UNK*)rect, arg0);
        DrawSync(0);
        arg0 += t;
        rect[0] += h;
    }
}

#include "common.h"

extern s32 D_800E2F0C;

void func_8001B900(s32 arg0) {
    D_800E2F0C = arg0;
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80064C94(M2C_UNK*, u32); /* extern */
extern u32 D_80070CC0;
extern s8 D_800CC869;
#define D_800CC869 (*(u8*)&D_800CC869)
extern M2C_UNK D_800E2F3C;

void func_8001B90C(u32 arg0) {
    u32 temp_v1;

    D_80070CC0 = arg0;
    if (D_800CC869 != 0) {
        M2C_FIELD(&D_800E2F3C, s8*, 0) = (s8)arg0;
        M2C_FIELD(&D_800E2F3C, s8*, 1) = 0;
        M2C_FIELD(&D_800E2F3C, s8*, 2) = (s8)arg0;
        M2C_FIELD(&D_800E2F3C, s8*, 3) = 0;
    } else {
        temp_v1 = arg0 >> 1;
        M2C_FIELD(&D_800E2F3C, s8*, 0) = (s8)temp_v1;
        M2C_FIELD(&D_800E2F3C, s8*, 1) = (s8)temp_v1;
        M2C_FIELD(&D_800E2F3C, s8*, 2) = (s8)temp_v1;
        M2C_FIELD(&D_800E2F3C, s8*, 3) = (s8)temp_v1;
    }
    func_80064C94(&D_800E2F3C, arg0);
}
#undef D_800CC869

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80064C94(M2C_UNK*, u32);
extern u32 D_80070CC0;
extern s8 D_800CC869;
extern M2C_UNK D_800E2F3C;

void func_8001B984(s32 arg0) {
    u8 v;
    u32 t;

    D_800CC869 = arg0;
    if ((u8)arg0 != 0) {
        u8 l;
        M2C_FIELD(&D_800E2F3C, s8*, 0) = l = D_80070CC0;
        v = l;
        M2C_FIELD(&D_800E2F3C, s8*, 1) = 0;
        M2C_FIELD(&D_800E2F3C, s8*, 2) = v;
        M2C_FIELD(&D_800E2F3C, s8*, 3) = 0;
    } else {
        M2C_FIELD(&D_800E2F3C, s8*, 0) = t = D_80070CC0 >> 1;
        M2C_FIELD(&D_800E2F3C, s8*, 1) = t;
        M2C_FIELD(&D_800E2F3C, s8*, 2) = t;
        M2C_FIELD(&D_800E2F3C, s8*, 3) = t;
    }
    func_80064C94(&D_800E2F3C, v);
}

#include "common.h"

extern s32 D_800E2F08;

void func_8001BA04(void) {
    D_800E2F08 += 1;
}

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

extern struct X4_EngineObj g_playthrough_state;
void func_800122A4();

#define B(p, o) (*(u8*)((u8*)(p) + (o)))
#define H(p, o) (*(u16*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))

void func_8001BA1C(u8* arg0) {
    u8 i;
    u8 j;
    s8 v;
    u8* e = (u8*)&g_playthrough_state;

    B(e, 0x66) = arg0[1];
    B(e, 0x68) = arg0[2];
    W(e, 0x70) = W(arg0, 4);
    for (i = 0; i < 2; i++) {
        u8* d = e + 0x74;
        u8* s = arg0 + 8;
        s32 o = i * 4;
        *(s32*)(d + o) = *(s32*)(s + o);
    }
    W(e, 0x6C) = W(arg0, 0x10);
    H(e, 0x6A) = H(arg0, 0x14);
    for (i = 0; i < 16; i++) {
        u8* d = (u8*)button_map;
        u8* s = arg0 + 0x16;
        s32 o = i * 2;
        *(u16*)(o + d) = *(u16*)(s + o);
    }
    B(e, 0x61) = arg0[0x38];
    B(e, 0x62) = arg0[0x39];
    B(e, 0x5B) = arg0[0x36];
    B(e, 0x5C) = arg0[0x37];
    B(e, 0x60) = arg0[0x3A];
    B(e, 0x5F) = arg0[0x3B];
    B(e, 0x69) = arg0[0x3C];
    v = 2;
    if (H(arg0, 0x14) & D_80071080[3]) {
        v = 4;
    }
    B(e, 0x39) = v;
    B(e, 0x63) = 0;
    B(e, 0x64) = 0;
    B(e, 0x65) = 0;
    B(e, 0x8D) = arg0[0x3D];
    B(e, 0x8E) = arg0[0x3E];
    W(e, 0xCC) = W(arg0, 0x40);
    B(e, 0x43B) = arg0[0x3F];
    B(e, 0xC9) = arg0[0xCC];
    g_temp_options = arg0[0xCC];
    for (i = 0; i < 16; i++) {
        s32 o;
        if (i < 8) {
            u8* d0 = e + 0x158;
            u8* s0 = arg0 + 0xAE;
            *(d0 + i) = *(s0 + i);
        }
        {
            u8* D = e + 0xD8;
            u8* S = arg0 + 0x44;
            u8* d = e + 0x168;
            u8* s = arg0 + 0xBC;
            o = i * 4;
            *(s32*)(D + o) = *(s32*)(S + o);
            *(d + i) = *(s + i);
        }
    }
    for (i = 0; i < 21; i++) {
        u8* d = e + 0x9E;
        u8* s = arg0 + 0x84;
        s32 o = i * 2;
        *(u16*)(d + o) = *(u16*)(s + o);
    }
    for (i = 0; i < 22; i++) {
        for (j = 0; j < 32; j++) {
            u8* D = e + 0x178;
            u8* S = arg0 + 0xCE;
            s32 o = j + i * 32;
            *(D + o) = *(S + o);
        }
    }
    B(e, 0xD0) = arg0[0xB6];
    B(e, 0xD1) = arg0[0xB7];
    H(e, 0xD2) = H(arg0, 0xB8);
    H(e, 0xD4) = H(arg0, 0xBA);
    B(e, 0x438) = arg0[0xCD];
    for (i = 0; i < 9; i++) {
        u8* d = e + 0x43C;
        u8* s = arg0 + 0x390;
        s32 o = i * 4;
        *(s32*)(d + o) = *(s32*)(s + o);
    }
    B(e, 0x465) = arg0[0x3B4];
    B(e, 0x466) = arg0[0x3B5];
    B(e, 0x467) = arg0[0x3B6];
    func_800122A4(*(s8*)(e + 0xD0), *(s8*)(e + 0xD1));
}

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

extern s8 D_800CC869;
extern struct X4_EngineObj g_playthrough_state;

#define B(p, o) (*(u8*)((u8*)(p) + (o)))
#define H(p, o) (*(u16*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))

void func_8001BD40(void) {
    u8 i;
    u8 j;
    u8* a = (u8*)D_80070CC4;
    u8* e = (u8*)&g_playthrough_state;

    B(a, 0) = 1;
    B(a, 1) = B(e, 0x66);
    B(a, 2) = B(e, 0x68);
    B(a, 3) = D_800CC869;
    W(a, 4) = W(e, 0x70);
    for (i = 0; i < 2; i++) {
        u8* d = a + 8;
        u8* s = e + 0x74;
        s32 o = i * 4;
        *(s32*)(d + o) = *(s32*)(s + o);
    }
    W(a, 0x10) = W(e, 0x6C);
    H(a, 0x14) = H(e, 0x6A);
    for (i = 0; i < 16; i++) {
        u8* d = a + 0x16;
        u8* s = (u8*)button_map;
        s32 o = i * 2;
        *(u16*)(d + o) = *(u16*)(o + s);
    }
    B(a, 0x38) = B(e, 0x61);
    B(a, 0x39) = B(e, 0x62);
    B(a, 0x36) = B(e, 0x5B);
    B(a, 0x37) = B(e, 0x5C);
    B(a, 0x3A) = B(e, 0x60);
    B(a, 0x3B) = B(e, 0x5F);
    B(a, 0x3C) = B(e, 0x69);
    B(a, 0x3D) = B(e, 0x8D);
    B(a, 0x3E) = B(e, 0x8E);
    W(a, 0x40) = W(e, 0xCC);
    B(a, 0x3F) = B(e, 0x43B);
    B(a, 0xCC) = B(e, 0xC9);
    for (i = 0; i < 16; i++) {
        s32 o;
        if (i < 8) {
            u8* d0 = a + 0xAE;
            u8* s0 = e + 0x158;
            *(d0 + i) = *(s0 + i);
        }
        {
            u8* D = a + 0x44;
            u8* S = e + 0xD8;
            u8* d = a + 0xBC;
            u8* s = e + 0x168;
            o = i * 4;
            *(s32*)(D + o) = *(s32*)(S + o);
            *(d + i) = *(s + i);
        }
    }
    for (i = 0; i < 21; i++) {
        u8* d = a + 0x84;
        u8* s = e + 0x9E;
        s32 o = i * 2;
        *(u16*)(o + d) = *(u16*)(s + o);
    }
    for (i = 0; i < 22; i++) {
        for (j = 0; j < 32; j++) {
            u8* D = a + 0xCE;
            u8* S = e + 0x178;
            s32 o = j + i * 32;
            *(D + o) = *(S + o);
        }
    }
    B(a, 0xB6) = B(e, 0xD0);
    B(a, 0xB7) = B(e, 0xD1);
    H(a, 0xB8) = H(e, 0xD2);
    H(a, 0xBA) = H(e, 0xD4);
    B(a, 0xCD) = B(e, 0x438);
    for (i = 0; i < 9; i++) {
        u8* d = a + 0x390;
        u8* s = e + 0x43C;
        s32 o = i * 4;
        *(s32*)(d + o) = *(s32*)(s + o);
    }
    B(a, 0x3B4) = B(e, 0x465);
    B(a, 0x3B5) = B(e, 0x466);
    B(a, 0x3B6) = B(e, 0x467);
}

#undef B
#undef H
#undef W

#include "common.h"

#define M2C_UNK s32

#include "psyq/libapi.h"
#include "mmx6/globals.h"

void func_8001C024(void) {
    EnterCriticalSection();
    D_800E2F70 = OpenEvent(0xF4000001, 4, 0x2000, 0);
    D_800E2F74 = OpenEvent(0xF4000001, 0x100, 0x2000, 0);
    D_800E2F78 = OpenEvent(0xF4000001, 0x2000, 0x2000, 0);
    D_800E2F7C = OpenEvent(0xF4000001, 0x8000, 0x2000, 0);
    D_800E2F80 = OpenEvent(0xF0000011, 4, 0x2000, 0);
    D_800E2F84 = OpenEvent(0xF0000011, 0x100, 0x2000, 0);
    D_800E2F88 = OpenEvent(0xF0000011, 0x8000, 0x2000, 0);
    ExitCriticalSection();
    EnableEvent(D_800E2F70);
    EnableEvent(D_800E2F74);
    EnableEvent(D_800E2F78);
    EnableEvent(D_800E2F7C);
    EnableEvent(D_800E2F80);
    EnableEvent(D_800E2F84);
    EnableEvent(D_800E2F88);
}

#include "common.h"
#include "psyq/libcard.h"
#include "psyq/libetc.h"

#define M2C_UNK s32

s32 func_8001C824(void);
void func_8001C938(s32);
#include "psyq/libapi.h"
#include "mmx6/globals.h"

static inline s32 func_8001C1AC_try(s32 port) {
    s32 i = 3;
    s32 r;

    TestEvent(D_800E2F70);
    TestEvent(D_800E2F74);
    TestEvent(D_800E2F78);
    TestEvent(D_800E2F7C);
    do {
        if (_card_load(port << 4) != 0) {
            r = func_8001C824();
            if (r == 0) {
                return 0;
            }
        }
    } while (--i != 0);
    return r;
}

s32 func_8001C1AC(s32 arg0) {
    s32 r;

    r = func_8001C1AC_try(arg0);
    if (r != 2) {
        return r;
    }
    func_8001C938(arg0);
    VSync(300);
    r = func_8001C1AC_try(arg0);
    if (r != 2) {
        return r;
    }
    func_8001C938(arg0);
    VSync(300);
    r = func_8001C1AC_try(arg0);
    return r;
}
