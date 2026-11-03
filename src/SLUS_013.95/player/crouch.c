#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"
#include "mmx6/movement.h"
#define M2C_UNK s32

// 0x80039C9C check_crouch_input: with D_800CCF99 bit 0x08 set and DOWN held, calls func_8003B9AC; returns 1 when taken.
// basis: community tweaks-index.tsv:259
// callers: none known
s32 check_crouch_input(void* arg0) {
    struct X4_PlayerObj* self = arg0;

    if (self->move_lock != 0) {
        return 0;
    }
    if (!(D_800CCF99 & 8)) {
        return 0;
    }
    if (!(self->input.buttons.held & 8)) {
        return 0;
    }
    func_8003B9AC(arg0);
    return 1;
}
