#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8002C9B0();
extern s32 D_800FCA84;

void func_800FC898(s32 arg0) {
    u8* p = *(u8**)((u8*)&D_800FCA84 + 0x3DC);

    p[7]--;
    func_8002C9B0(arg0, p);
}
