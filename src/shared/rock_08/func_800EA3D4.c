#include "common.h"
#include "mmx6/x4.h"

extern struct X4_PlayerObj g_Player;
extern void (*D_800F4EB4[])(s8*);

void func_800EA3D4(s8* arg0) {
    struct X4_PlayerObj* p = &g_Player;

    if ((u32)(p->x_pos.u.hi - 1) < 0x77F && p->y_pos.i.hi >= 0x5E1 &&
        p->y_pos.i.hi < 0xA30) {
        D_800F4EB4[arg0[5]](arg0);
    }
}
