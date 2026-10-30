#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EngineObj g_playthrough_state;

#define SAVE_474 ((s32*)0x801F6474)

void func_8002163C(void) {
    s32* save = SAVE_474;
    s32* eng = (s32*)&g_playthrough_state;

    __builtin_memcpy(eng, save, 0x468);
}
