#include "common.h"
#include "mmx6/x4.h"

void func_8001D218();
extern s8 D_80097424;
extern struct X4_EngineObj g_playthrough_state;
extern u8 D_800CD40C;

void func_800E9EF0(u8* arg0) {
    s32 i;
    u8* p;
    u8* e;

    if ((D_800CD40C == 0) && (D_80097424 == 0)) {
        func_8001D218();
        i = 0xF;
        e = (u8*)&g_playthrough_state;
        p = arg0 + 0x35;
        arg0[0xC] = e[0x26];
        arg0[0xD] = e[0x27];
        arg0[0] = 7;
        arg0[1] = 0;
        arg0[2] = 0;
        arg0[3] = 0;
        do {
            *p = 0;
            i -= 1;
            p -= 1;
        } while (i >= 0);
    }
}
