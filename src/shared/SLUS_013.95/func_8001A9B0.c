#include "common.h"
#include "psyq/libetc.h"
#include "psyq/libgpu.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

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
extern u16 str_movie_table[];
extern u16 g_pad1_buttons[];
extern u8 g_draw_info_buffers[];
#define DB_DISP(i) (*(X4_DISPENV*)(g_draw_info_buffers + (i) * 0xF0))
extern s8 D_800E2E65;
extern s32 D_800E2E6C;
extern s32 D_800E2E70;
extern s32 D_800E2E74;
extern s32 D_800E2E78;
extern s32 D_800E2E7C;
extern X4_DISPENV D_800E2E88[];

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
