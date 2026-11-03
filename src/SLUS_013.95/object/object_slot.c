#include "common.h"
#include "mmx6/object.h"

// 0x8002C9B0 clear_object_slot: zeroes the first eight bytes of an object slot.
// basis: code src/shared/SLUS_013.95/clear_object_slot.c:9 via=arg0
// callers: func_8002CA54, func_80033E00, func_80043018
void clear_object_slot(void* arg0) {
    struct ObjectHeader* o = arg0;

    o->active = 0;
    o->id = 0;
    o->unk2 = 0;
    o->on_screen = 0;
    o->state = 0;
    o->action = 0;
    o->action_phase = 0;
    o->unk7 = 0;
}
