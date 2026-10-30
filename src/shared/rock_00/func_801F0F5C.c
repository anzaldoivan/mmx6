#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern M2C_UNK g_Player;
M2C_UNK clear_object_slot();

void func_801F0F5C(void* a0) {
    u8* p = (u8*)&g_Player;

    p[0x98]--;
    p[0x99]--;
    clear_object_slot(a0);
}
