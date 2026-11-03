#include "common.h"
#include "psyq/2mbyte.h"
#include "psyq/libetc.h"
#include "psyq/libgpu.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

void func_800123D0(void);
void init_system(void);
void func_80012A34(void);
void func_80012C54(void);
void func_80012EB4(void);
void func_800131AC(void);
void func_8001651C(void);
void func_80017A48(void);
void func_80017A88(void);
void func_80017C40(void);
s32 func_80018290(void);
void func_800185B4(void);
void func_80027A50(void);

#include "mmx6/state.h"

#define SCRATCH0 (*(s32*)0x1F800000)
#define SCRATCH70 (*(s32*)0x1F800070)
#define SCRATCH74 (*(s32*)0x1F800074)
#define SCRATCH7C (*(s32*)0x1F80007C)
#define SETADDR(p, a) (((X4_P_TAG*)(p))->addr = (u32)(a))
#define GETADDR(p) (((X4_P_TAG*)(p))->addr)
#define OT_E4 ((u8*)g_cur_draw_info + 0xE4)

void func_800120A0(void) {
    u8* p;

    __main();
    init_system();
    while (1) {
        VSync(0);
        PutDispEnv(g_cur_draw_info);
        PutDrawEnv((u8*)g_cur_draw_info + 0x14);
        DrawOTag((u8*)g_cur_draw_info + 0xEC);
        SCRATCH0 ^= 1;
        g_cur_draw_info =
            (struct X4_DrawInfo*)(g_draw_info_buffers + SCRATCH0 * 0xF0);
        ClearOTagR((s32)((u8*)g_cur_draw_info + 0x70), 0x20);
        func_800123D0();
        SETADDR(D_800CF948 + SCRATCH0 * 0xC, GETADDR(OT_E4));
        SETADDR(OT_E4, D_800CF948 + SCRATCH0 * 0xC);
        SETADDR(D_800CF908 + SCRATCH0 * 0xC, GETADDR(OT_E4));
        SETADDR(OT_E4, D_800CF908 + SCRATCH0 * 0xC);
        func_800185B4();
        func_80018290();
        func_80012A34();
        func_80017A48();
        D_80097420.frame_counter++;
        func_800131AC();
        func_8001651C();
        SCRATCH70 = VSync(1);
        DrawSync(0);
        func_80017A88();
        func_80017C40();
        func_80027A50();
        DrawSync(0);
        SCRATCH7C = SCRATCH74;
        func_80012C54();
        func_80012EB4();
    }
}

#include "common.h"
#include "psyq/libgpu.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

extern struct X4_EngineObj g_playthrough_state;

void func_800122A4(s8 arg0, s8 arg1) {
    s16 r[4];
    s16 t[4];
    u8* e;
    u8* e2;
    s16 v;

    ((s16*)D_8006D5FC)[0] = arg0;
    ((s16*)D_8006D5FC)[1] = arg1;
    e = (u8*)&g_playthrough_state;
    t[0] = (s8)e[0xD0];
    t[2] = (s8)e[0xD0];
    t[1] = (s8)e[0xD1];
    t[3] = (s8)e[0xD1] + 0xF0;
    SetDrawOffset(D_800CF908, &t[0]);
    SetDrawOffset(D_800CF908 + 0xC, &t[2]);
    if ((s8)e[0xD0] < 0) {
        r[0] = 0;
        r[2] = g_screen_width + (s8)e[0xD0];
    } else {
        r[0] = (s8)e[0xD0];
        r[2] = g_screen_width - (s8)e[0xD0];
    }
    e2 = (u8*)&g_playthrough_state;
    if ((s8)e2[0xD1] < 0) {
        v = (s8)e2[0xD1] + 0xF0;
        r[1] = 0;
    } else {
        v = 0xF0 - (s8)e2[0xD1];
        r[1] = (s8)e2[0xD1];
    }
    r[3] = v;
    do {
    } while (0);
    SetDrawArea(D_800CF948, r);
    r[1] += 0xF0;
    SetDrawArea(D_800CF948 + 0xC, r);
}

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

extern struct X4_EngineObj g_playthrough_state;
extern u8 D_800CF8A0[];
extern u8 D_800CF8B8[];

#define SCR_BUF (*(s32*)0x1F800000)
#define ENG_D0 (*(s8*)(eng + 0xD0))
#define ENG_D1 (*(s8*)(eng2 + 0xD1))
#define OT_E8 ((X4_P_TAG*)((u8*)g_cur_draw_info + 0xE8))
#define SETADDR(p, a) (((X4_P_TAG*)(p))->addr = (u32)(a))
#define GETADDR(p) (((X4_P_TAG*)(p))->addr)
#define H(p, o) (*(s16*)((p) + (o)))

void func_800123D0(void) {
    u8* prim;
    u8* eng;
    u8* eng2;

    eng = (u8*)&g_playthrough_state;
    if (ENG_D0 != 0) {
        prim = D_800CF8A0 + SCR_BUF * 0x30;
        prim[3] = 5;
        prim[7] = 0x28;
        prim[4] = 0;
        prim[5] = 0;
        prim[6] = 0;
        if (ENG_D0 > 0) {
            H(prim, 0x8) = 0;
            H(prim, 0xA) = 0;
            H(prim, 0xC) = ENG_D0;
            H(prim, 0xE) = 0;
            H(prim, 0x10) = 0;
            H(prim, 0x12) = 0xF0;
            H(prim, 0x14) = ENG_D0;
            H(prim, 0x16) = 0xF0;
        } else {
            u16 w = g_screen_width;
            H(prim, 0x8) = ENG_D0 + w;
            H(prim, 0xA) = 0;
            H(prim, 0xC) = ENG_D0 + w - ENG_D0;
            H(prim, 0xE) = 0;
            H(prim, 0x10) = ENG_D0 + w;
            H(prim, 0x12) = 0xF0;
            H(prim, 0x14) = ENG_D0 + w - ENG_D0;
            H(prim, 0x16) = 0xF0;
        }
        SETADDR(prim, GETADDR(OT_E8));
        SETADDR(OT_E8, prim);
    }
    eng2 = (u8*)&g_playthrough_state;
    if (*(s8*)(eng2 + 0xD1) != 0) {
        prim = D_800CF8B8 + SCR_BUF * 0x30;
        prim[3] = 5;
        prim[7] = 0x28;
        prim[4] = 0;
        prim[5] = 0;
        prim[6] = 0;
        if (ENG_D1 > 0) {
            u16 w = g_screen_width;
            H(prim, 0x8) = 0;
            H(prim, 0xA) = 0;
            H(prim, 0xC) = w;
            H(prim, 0xE) = 0;
            H(prim, 0x10) = 0;
            H(prim, 0x12) = ENG_D1;
            H(prim, 0x14) = w;
            H(prim, 0x16) = ENG_D1;
        } else {
            u16 w;
            H(prim, 0x8) = 0;
            w = g_screen_width;
            H(prim, 0xA) = ENG_D1 + 0xF0;
            H(prim, 0xC) = w;
            H(prim, 0xE) = ENG_D1 + 0xF0;
            H(prim, 0x10) = 0;
            H(prim, 0x12) = 0xF0;
            H(prim, 0x14) = w;
            H(prim, 0x16) = 0xF0;
        }
        SETADDR(prim, GETADDR(OT_E8));
        SETADDR(OT_E8, prim);
    }
}
