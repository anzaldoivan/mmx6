#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
M2C_UNK clear_object_slot();

void func_801EE72C(struct X4_PlayerObj* arg0) {
    arg0->unk50 = 0;
    if (arg0->id != 0x15) {
        g_Player.shot_count--;
    }
    clear_object_slot();
}
#undef g_Player
