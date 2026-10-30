#include "common.h"
#include "psyq/libgpu.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_800122A4();

extern u8 D_8006D5FC[];
extern X4_RECT D_8006D884;
extern u16 g_wide_mode;
extern u16 g_screen_width;
extern u8 D_800C458C[];
extern struct X4_EngineObj g_playthrough_state;

// 0x80012890 set_resolution: switches screen resolution.
// basis: community tweaks-index.tsv:38
// callers: func_800146F4, func_8001CBE0, func_8001D3C0, func_8001D460 and others
void set_resolution(s32 arg0) {
    u8* p;
    u8* a;
    u8* b;
    u8* eng;
    s32 pad[2];

    if (g_wide_mode != arg0) {
        g_wide_mode = arg0;
        if ((u16)arg0 == 0) {
            g_screen_width = 0x140;
            ClearImage(&D_8006D884, 0, 0, 0);
            DrawSync(0);
        } else {
            g_screen_width = 0x200;
            ClearImage(&D_8006D884, 0, 0, 0);
            DrawSync(0);
        }
        p = D_800C458C;
        SetDefDrawEnv(p, 0, 0, g_screen_width, 0xF0);
        a = p - 0x14;
        SetDefDispEnv(a, 0, 0xF0, g_screen_width, 0xF0);
        SetDefDrawEnv(p + 0xF0, 0, 0xF0, g_screen_width, 0xF0);
        b = p + 0xDC;
        SetDefDispEnv(b, 0, 0, g_screen_width, 0xF0);
        {
            // !FAKE: depin: dropping it breaks the match (102/105)
            register s32 x asm("$7");
            s32 y;
            // !FAKE: depin: dropping it breaks the match (97/105)
            register u8* src asm("$3");
            src = D_8006D5FC;
            eng = (u8*)&g_playthrough_state;
            x = src[0];
            y = src[2];
            eng[0xD0] = x;
            eng[0xD1] = y;
            func_800122A4((s8)x, (s8)y);
        }
        ClearOTagR((s32)(p + 0x5C), 0x20);
        a[0x2A] = 0;
        a[0x2C] = 1;
        a[0x2D] = 0;
        a[0x2E] = 0;
        a[0x2F] = 0;
        ClearOTagR((s32)(p + 0x14C), 0x20);
        b[0x2A] = 0;
        b[0x2C] = 1;
        b[0x2D] = 0;
        b[0x2E] = 0;
        b[0x2F] = 0;
    }
}
