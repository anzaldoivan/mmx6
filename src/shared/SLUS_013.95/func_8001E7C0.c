#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern struct X4_EngineObj g_playthrough_state;
void set_resolution(s32 arg0);
M2C_UNK func_80013DE8();

void func_8001E7C0(u8* arg0) {
    arg0[0] = 6;
    g_playthrough_state.character_state.bytes[0] = arg0[0xC];
    g_playthrough_state.character_state.bytes[1] = arg0[0xD];
    arg0[0xC] = 0xD;
    arg0[0xD] = 1;
    arg0[0x36] = g_playthrough_state.character_state.bytes[0];
    func_80013DE8();
    set_resolution(1);
}
