#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern struct X4_EngineObj g_playthrough_state;

void func_8003FC88(void* arg0) {
    M2C_FIELD(arg0, s8*, 5) = 0x4B;
    M2C_FIELD(arg0, s8*, 6) = 0;
    M2C_FIELD(arg0, s8*, 7) = 0;
    g_playthrough_state.gameplay_locked = 1;
    M2C_FIELD(arg0, s8*, 0x67) = 1;
    M2C_FIELD(arg0, s8*, 0xE1) = 0;
    g_playthrough_state.unk16 = 1;
    g_playthrough_state.unk12 = 1;
    g_playthrough_state.unk13 = 1;
    g_playthrough_state.unk19 = 1;
    g_playthrough_state.unk18 = 1;
    g_playthrough_state.unk17 = 1;
    g_playthrough_state.unk14 = 1;
    g_playthrough_state.unk15 = 1;
}
