#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK create_task(M2C_UNK, M2C_UNK*);
M2C_UNK func_800133A0();
M2C_UNK reset_level();
extern s32 D_8001E6E4;
extern u8 D_8006D620;
extern struct X4_EngineObj D_80097420;
extern struct X4_EngineObj g_playthrough_state;

void func_800ED7C4(u8* arg0) {
    s8* e = (s8*)&D_80097420;

    if (e[4] == 0) {
        reset_level();
        D_8006D620 = e[7];
        if (arg0[0x158] == 0xFF) {
            g_playthrough_state.state = 3;
            g_playthrough_state.unk1 = 0;
            g_playthrough_state.unk2 = 0;
            g_playthrough_state.unk3 = 0;
        } else {
            g_playthrough_state.state = 0x13;
            g_playthrough_state.unk1 = 0;
            g_playthrough_state.unk2 = 0;
            g_playthrough_state.unk3 = 0;
            ((u8*)&g_playthrough_state)[0x1D] =
                ((u8*)&g_playthrough_state)[0x158];
        }
        create_task(1, &D_8001E6E4);
        func_800133A0();
    }
}
