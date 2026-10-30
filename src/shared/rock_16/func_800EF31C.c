#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation_frame(void*, M2C_UNK, s8);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
extern struct X4_EngineObj g_playthrough_state;

void func_800EF31C(void* arg0) {
    if (!(g_playthrough_state.unk5F & 0x10) ||
        (g_playthrough_state.unk1 == 6)) {
        set_animation_frame(arg0, 2, 1);
    } else if (g_playthrough_state.unk1 == 5) {
        set_animation_frame(arg0, 2, 0);
    }
    func_8002CCB0(arg0, 0x60, 0x10);
}
