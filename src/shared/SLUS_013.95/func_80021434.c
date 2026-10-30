#include "common.h"
#include "mmx6/x4.h"

extern u16 D_80090E70;
extern s32 D_80097420;
extern struct X4_EngineObj g_playthrough_state;

#define SAVE_BASE ((s32*)0x801F6000)
#define SAVE_C ((s32*)0x801F600C)
#define SAVE_474 ((s32*)0x801F6474)

void func_80021434(void) {
    s32* base = SAVE_BASE;
    s32* save = SAVE_474;
    s32* eng = (s32*)&g_playthrough_state;
    s32* eng2;

    base[0] = 0;
    D_80097420 = base[1];
    D_80090E70 = *(u16*)&base[2];
    __builtin_memcpy(save, eng, 0x468);
    eng2 = (s32*)&g_playthrough_state;
    save = SAVE_C;
    __builtin_memcpy(eng2, save, 0x468);
}
