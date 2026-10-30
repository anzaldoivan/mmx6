#include "common.h"
#define M2C_UNK s32

M2C_UNK clear_object_slot();
extern M2C_UNK g_Player;

void func_801EE940(void) {
    u8* p = (u8*)&g_Player;

    p[0x98]--;
    clear_object_slot();
}
