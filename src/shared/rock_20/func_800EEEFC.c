#include "common.h"
#include "mmx6/x4.h"

extern u8 D_8008EAFC;
extern struct X4_EngineObj g_playthrough_state;
extern u8 D_800F366C[];

void func_800EEEFC(u8* arg0) {
    if (D_8008EAFC == 0) {
        u8* e = (u8*)&g_playthrough_state;
        e[0x28] = 0x5F;
        if (arg0[0x5F] & 0x10) {
            u8* t = D_800F366C + 4;
            s32 i = ((s8*)e)[0x26] - 1;
            t -= -(i * 6);
            if (*(u16*)(t + 4) != 0) {
                arg0[2]++;
                return;
            }
        }
        arg0[2] = 0xB;
    }
}
