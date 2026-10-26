#include "common.h"
#include "psyq/libetc.h"
#include "psyq/libgpu.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern u8 D_800C4578[];
#define DB_DISP(i) (*(X4_DISPENV*)(D_800C4578 + (i) * 0xF0))
extern X4_DISPENV D_800E2E88[];

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
    SetDefDispEnv(D_800C4578, 0, 0, arg0, arg1);
    SetDefDispEnv(D_800C4578 + 0xF0, 0, 0xF0, arg0, arg1);
    {
        // !FAKE: depin: dropping it breaks the match (93/96)
        register s32 one asm("$3") = 1;
        D_800C4578[0x101] = one;
        D_800C4578[0x11] = one;
    }
    D_800C4578[0x100] = 0;
    D_800C4578[0x10] = 0;
}
#undef DB_DISP
