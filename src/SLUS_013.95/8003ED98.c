// prog SLUS_013.95 | system movement | range 0x8003ED98-0x8003EEE0
#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/engine_state.h"

#define E_C9                                                                   \
    ({                                                                         \
        u8* e = (u8*)&g_playthrough_state;                                     \
        e[0xC9];                                                               \
    })

// 0x8003ED98 func_8003ED98: tests the fire input bits 0x10/0x20 and their press history.
// basis: none
// callers: update_player_charge
s32 func_8003ED98(struct X4_PlayerObj* p) {
    s32 h;
    s32 g;
    u16 t;

    if (p->action == 0x1F) {
        return 1;
    }
    if (p->stock_charge == 1) {
        return 1;
    }
    t = p->pressed_input;
    if ((t & 0x10) ||
        !(!(t & 0x20) &&
          (((p->input.buttons.held & 0x10) == 0) || !(E_C9 & 2)) &&
          (!(p->input.buttons.held & 0x20) || !(E_C9 & 2)))) {
        return 1;
    }
    if ((E_C9 & 1) && (p->weapon == 0)) {
        g = p->input.history;
        if ((g & 0x100010) == 0x100000) {
            return 1;
        }
        if ((g & 0x200020) == 0x200000) {
            return 1;
        }
    } else {
        h = p->input.history;
        if ((h & 0x100010) == 0x100000) {
            return 1;
        }
        if ((h & 0x200020) == 0x200000) {
            return 1;
        }
        if ((p->charge_timer != 0) && !(p->input.buttons.held & 0x10)) {
            return 1;
        }
        if ((p->special_charge_timer != 0) && !(p->input.buttons.held & 0x20)) {
            return 1;
        }
    }
    return 0;
}
#undef E_C9
