#include "common.h"
#include "mmx6/x4.h"

extern struct X4_PlayerObj g_Player;
extern void (*D_800761BC[])(void*);

#define PL_S8(p, o) (*(s8*)((u8*)(p) + (o)))

void func_80045D68(void* arg0) {
    struct X4_PlayerObj* p;
    s32 var_a1;

    p = &g_Player;
    var_a1 = PL_S8(p, 0xD3) != 0;
    if (PL_S8(p, 0xD4) != 0) {
        var_a1 = 1;
    }
    if ((p->unk2 == 1) && (p->stock_charge != 2)) {
        var_a1 = 1;
    }
    if (((u8)p->unk2 == 0) && (p->weapon != 7)) {
        var_a1 = 1;
    }
    if (PL_S8(p, 0xD5) != 0) {
        var_a1 = 1;
    }
    if (((u8)p->unk2 == 0) && (p->shot_type == 0x10)) {
        var_a1 = 1;
    }
    if (p->hp == 0) {
        var_a1 = 1;
    }
    if (var_a1 != 0) {
        *((s8*)arg0 + 4) = 3;
    }
    D_800761BC[*((s8*)arg0 + 4)](arg0);
}

#undef PL_S8
