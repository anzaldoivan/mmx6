#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK clear_object_slot();
extern struct X4_PlayerObj g_Player;
extern void (*D_80077BE8[])(void*, struct X4_PlayerObj*);

void func_80049410(void* arg0) {
    if (g_Player.unk5 == 0x14) {
        ((void (*)())clear_object_slot)(arg0, &g_Player);
        return;
    }
    D_80077BE8[((s8*)arg0)[4]](arg0, &g_Player);
}
