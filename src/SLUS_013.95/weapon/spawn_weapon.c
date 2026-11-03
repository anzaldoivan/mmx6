#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#include "mmx6/weapon.h"

void* player_spawn_weapon(s8 arg0, s8 arg1, s8 arg2, s32 arg3) {
    struct ProjectileObj* p;

    p = func_8002C32C();
    if (p != 0) {
        p->active = arg0;
        p->id = arg1;
        p->unk2 = arg2;
        p->bg_offset = D_800970B4;
        if (arg3 != 0) {
            p->unk7C = (struct X4_WeaponObj*)arg3;
        }
        return p;
    }
    return 0;
}
