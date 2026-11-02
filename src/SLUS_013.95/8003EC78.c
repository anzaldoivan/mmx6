#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_8003C4EC(struct X4_PlayerObj* self);
void func_8003CF54(struct X4_PlayerObj*, s32);
s32 func_8003ED98(struct X4_PlayerObj* p);
void charge_special_weapon(void* arg0);
M2C_UNK func_8003F480();
s32 func_8003FF90(struct X4_PlayerObj*, s32);
void func_8003FFF4(struct X4_PlayerObj*);

void func_8003EC78(struct X4_PlayerObj* p) {
    u8* b = (u8*)p;
    s8 t;

    if (p->unk2 != 0) {
        return;
    }
    if (*(s8*)(b + 0xE0) != 0 && b[0xE7] == 4) {
        return;
    }
    t = p->unk5;
    if (t == 0) {
        return;
    }
    if (t == 1) {
        return;
    }
    if (t == 0x19) {
        return;
    }
    if (t == 0x18) {
        return;
    }
    if (*(s8*)(b + 0xD5) != 0) {
        return;
    }
    if (func_8003ED98(p) != 0) {
        func_8003F480(p);
        {
            // !FAKE: depin: dropping it breaks the match (70/72)
            register s32 a asm("$2") = *(s8*)(b + 0xA2);
            if (a != 0) {
                func_8003CF54(p, 0x32);
            } else {
                func_8003C4EC(p);
            }
        }
        if (*(s8*)(b + 0xA6) == 1) {
            b[0xA1] = 0x29;
        }
    } else if (!(*(s32*)(b + 0xEC) & 0x80000)) {
        charge_special_weapon(p);
        func_8003FFF4(p);
        if (func_8003FF90(p, 0) == 0) {
            func_8003FF90(p, 1);
        }
    }
}

#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EngineObj g_playthrough_state;
#define E_C9                                                                   \
    ({                                                                         \
        u8* e = (u8*)&g_playthrough_state;                                     \
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
