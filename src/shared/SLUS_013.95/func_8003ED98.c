#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EngineObj D_800CCED0;
#define E_C9                                                                   \
    ({                                                                         \
        u8* e = (u8*)&D_800CCED0;                                              \
        e[0xC9];                                                               \
    })

s32 func_8003ED98(struct X4_PlayerObj* p) {
    s32 h;
    s32 g;
    // !FAKE: depin: dropping it breaks the match (75/83)
    register s32 r asm("$2");
    u16 t;

    if (p->unk5 == 0x1F) {
        return 1;
    }
    if (p->stock_charge == 1) {
        return 1;
    }
    t = p->pressed_input;
    if (!(t & 0x10)) {
        if (!(t & 0x20) &&
            (((p->input.buttons.held & 0x10) == 0) || !(E_C9 & 2)) &&
            (!(p->input.buttons.held & 0x20) || !(E_C9 & 2))) {
            if ((E_C9 & 1) && (p->weapon == 0)) {
                g = p->input.history;
                if ((g & 0x100010) == 0x100000) {
                    return 1;
                }
                if ((g & 0x200020) == 0x200000) {
                    return 1;
                }
                goto ret0;
            }
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
            goto tail;
        }
    }
    return 1;
tail:
    if ((p->special_charge_timer == 0) ||
        (r = 1, ((p->input.buttons.held & 0x20) != 0))) {
    ret0:
        r = 0;
    }
    return r;
}
#undef E_C9
