#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();
void func_8002CCB0(struct X4_BaseObj* arg0, s32 arg1, s32 arg2);
void func_800496C0(struct X4_VisualObj* arg0, struct X4_PlayerObj* arg1);

// 0x80049564 update_dust: dust animation control; stops on wall let-go/kick.
// basis: community tweaks-index.tsv:190
// callers: none known
void update_dust(struct X4_VisualObj* arg0, struct X4_PlayerObj* arg1) {
    s32 w;
    // !FAKE: depin: dropping it breaks the match (60/67)
    register s32 m asm("$2");
    s8 id;
    s32 hit;

    ((M2C_UNK(*)())func_80017A04)();
    m = 0xFFFF00;
    w = *(s32*)&arg1->state;
    id = arg1->unk5;
    m = w & m;
    hit = m == 0xB00;
    if (id == 0x34) {
        hit = 1;
    }
    if (id == 0x2F) {
        hit = 1;
    }
    if ((w & 0xFF00FF00) == 0x01004C00) {
        hit = 1;
    }
    if (hit != 0) {
        func_800496C0(arg0, arg1);
    } else {
        set_animation(arg0, 4);
        {
            // !FAKE: depin: dropping it breaks the match (64/67)
            register s32 t asm("$2") = (u8)arg0->state + 1;
            arg0->state = t;
        }
    }
    func_8002CCB0(arg0, 0x20, 0x20);
    if (arg1->unk5 == 0x2F && arg1->weapon != 0) {
        arg0->on_screen = 0;
    }
    if ((*(s32*)&arg1->state & 0xFF00FF00) == 0x01004C00) {
        arg0->on_screen = 0;
    }
}
