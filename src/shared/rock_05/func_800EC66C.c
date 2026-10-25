#include "common.h"
#include "mmx6/x4.h"

extern struct X4_PlayerObj g_Player;
extern void (*D_800F3F6C[])(void*);

void func_800EC66C(s8* arg0) {
    if (g_Player.y_pos.i.hi < 0x1B0) {
        g_Player.y_pos.i.hi = 0x1B0;
    }
    D_800F3F6C[arg0[6]](arg0);
}
