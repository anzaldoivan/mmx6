#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern M2C_UNK g_Player;
M2C_UNK func_8002C9B0();

void func_801F0F5C(void* a0) {
    u8* p = (u8*)&g_Player;

    p[0x98]--;
    p[0x99]--;
    func_8002C9B0(a0);
}
