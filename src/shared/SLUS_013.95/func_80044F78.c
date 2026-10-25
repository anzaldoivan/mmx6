#include "common.h"
#include "mmx6/x4.h"

extern struct X4_PlayerObj g_Player;
extern void (*D_80076180[])(struct X4_PlayerObj*);

void func_80044F78(struct X4_PlayerObj* arg0) {
    struct X4_PlayerObj* p;
    s32 var_a1;

    arg0->unk18 = arg0->x_pos;
    arg0->unk1C = arg0->y_pos;
    p = &g_Player;
    var_a1 = ((s8*)p)[0xD3] != 0;
    if (p->ride_animation != 0) {
        var_a1 = 1;
    }
    if (p->weapon != 4) {
        var_a1 = 1;
    }
    if (p->unk5 != 0x28) {
        var_a1 = 1;
    }
    if (var_a1 != 0) {
        arg0->state = 2;
    }
    D_80076180[arg0->state](arg0);
}
