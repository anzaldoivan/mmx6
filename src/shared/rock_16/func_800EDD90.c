#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation_frame(void*, M2C_UNK, s8);
M2C_UNK func_8002CB50();
extern struct X4_EngineObj g_playthrough_state;
extern u8 D_800F1CF9;

void func_800EDD90(void* arg0) {
    s8 v;
    s8 r;

    if (D_800F1CF9 != 0) {
        v = g_playthrough_state.character_state.bytes[1];
        if (v == 8) {
            if (((u8*)&g_playthrough_state)[0x66] == 3) {
                r = 8;
            } else if (((u8*)&g_playthrough_state)[0x66] == 4) {
                r = 9;
            } else {
                r = 0xA;
            }
        } else {
            r = v;
        }
        ((void (*)(void*, s32, s8))set_animation_frame)(arg0, 3, r);
        func_8002CB50(arg0);
        return;
    }
    ((u8*)arg0)[3] = 0;
}
