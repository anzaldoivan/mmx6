#include "common.h"
#include "mmx6/x4.h"

extern u16 D_80090E70;
extern s32 D_80097420;
extern struct X4_EngineObj D_800CCED0;

#define SAVE_BASE ((s32*)0x801F6000)
#define SAVE_C ((s32*)0x801F600C)

void func_80021694(void) {
    s32* base = SAVE_BASE;
    s32* save = SAVE_C;
    s32* eng = (s32*)&D_800CCED0;

    base[0] = 0;
    base[1] = D_80097420;
    *(u16*)&base[2] = D_80090E70;
    __builtin_memcpy(save, eng, 0x468);
}
