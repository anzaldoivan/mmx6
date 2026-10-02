/* Adapted from sozud/mmx4 @29b62af src/main/player_common.c:player_spawn_death_orb, AGPL-3.0; proven shared with X6 by exact signature 76c0b9feb772 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
void* func_8002C530();

void func_8003DAF4(s8 direction) {
    struct X4_MiscObj* obj;

    obj = func_8002C530();
    if (obj != NULL) {
        obj->active = 0x21;
        obj->id = 0x11;
        obj->unk2 = direction;
        obj->state = 0;
        obj->unk5 = 0;
        obj->unk6 = 0;
    }
}
