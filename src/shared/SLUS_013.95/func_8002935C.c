/* Adapted from sozud/mmx4 @6a6b455 src/main/background.c:func_80027D40, AGPL-3.0; proven shared with X6 by exact signature 6ee72b467391 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern struct X4_PlayerObj D_800970B0;
extern struct X4_BackgroundObj background_objects[3];
extern void (*D_80071E88[])(struct X4_BackgroundObj*);

void func_8002935C(void) {
    struct X4_BackgroundObj* ptr = &background_objects[1];
    if (ptr->unk44 != 0 && D_800970B0.update_delay == 0) {
        ptr->unk14.val = ptr->x_pos.val;
        ptr->unk18.val = ptr->y_pos.val;
        D_80071E88[ptr->unk4](ptr);
    }
}
