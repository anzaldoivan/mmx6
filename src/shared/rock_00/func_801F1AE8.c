#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern M2C_UNK D_800970A0;
#define D_800970A0 (*(struct X4_PlayerObj*)&D_800970A0)
extern void (*D_801F3AA0[])(struct X4_PlayerObj*);

#define F_S8(p, o) (*(s8*)((u8*)(p) + (o)))

void func_801F1AE8(struct X4_PlayerObj* arg0) {
    struct X4_PlayerObj* player = &D_800970A0;
    s32 var_a1;

    var_a1 = F_S8(player, 0xD3) != 0;
    if (F_S8(player, 0xD4) != 0) {
        var_a1 = 1;
    }
    if (player->weapon != 6) {
        var_a1 = 1;
    }
    if (var_a1 != 0) {
        arg0->state = 2;
    }
    D_801F3AA0[arg0->state](arg0);
}
#undef D_800970A0
