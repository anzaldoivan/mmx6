#include "common.h"
#include "mmx6/x4.h"

s32 func_8002DCF4(void*, void*);
void func_8002DFA0(void*, void*);
void func_8002E0DC(void*, void*);

s32 func_800323D4(struct X4_MainObj* self, struct X4_PlayerObj* tgt) {
    s32 dx;
    s32 dy;

    if (tgt->unk68 == 0) {
        return 0;
    }
    if (func_8002DCF4(self, tgt) != 0) {
        func_8002DFA0(self, tgt);
        func_8002E0DC(self, tgt);
        if (tgt->unk6C < 0) {
            dx = (s16)-tgt->unk6C;
        } else {
            dx = tgt->unk6C;
        }
        dy = tgt->unk6E;
        if (dy < 0) {
            dy = (s16)-tgt->unk6E;
        }
        if (self->unk66 == 0) {
            if (dx < dy) {
                tgt->x_pos.i.hi += tgt->unk6C;
            } else {
                tgt->y_pos.i.hi += tgt->unk6E;
            }
        } else if (self->unk66 > 0) {
            tgt->x_pos.i.hi += tgt->unk6C;
        } else {
            tgt->y_pos.i.hi += tgt->unk6E;
        }
        return 1;
    }
    return 0;
}
