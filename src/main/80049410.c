#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK clear_object_slot();
extern struct X4_PlayerObj g_Player;
extern void (*D_80077BE8[])(void*, struct X4_PlayerObj*);

void func_80049410(struct ObjectHeader* arg0) {
    if (g_Player.action == 0x14) {
        ((void (*)())clear_object_slot)(arg0, &g_Player);
        return;
    }
    D_80077BE8[arg0->state](arg0, &g_Player);
}
