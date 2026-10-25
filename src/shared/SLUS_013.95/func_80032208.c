#include "common.h"
#include "mmx6/x4.h"

s32 func_8002DCF4(void*, void*);
s32 func_8002DE54(void*, void*);
void func_8002DFA0(void*, void*);
void func_8002E0DC(void*, void*);
extern struct X4_PlayerObj g_Player;

#define F8(p, o) (*(u8*)((u8*)(p) + (o)))
#define S8(p, o) (*(s8*)((u8*)(p) + (o)))

s32 func_80032208(struct X4_MainObj* self, struct X4_PlayerObj* tgt) {
    s8 saved;
    s32 dx;
    s32 dy;

    if (tgt->unk68 == 0) {
        return 1;
    }
    if (self->unk66 == 0) {
        if (func_8002DE54(self, tgt) != 0) {
            tgt->unk71 = 0xF;
            if (tgt == &g_Player) {
                F8(tgt, 0xE6) = F8(self, 0x60);
            }
            return 1;
        }
    }
    saved = self->unk66;
    if (func_8002DCF4(self, tgt) != 0) {
        if (self->unk66 < -3 || self->unk66 > 3) {
            if (func_8002DE54(self, tgt) == 0) {
                self->unk66 = 0;
            } else if (self->unk66 > 0) {
                self->unk66 = self->unk66 - 2;
            } else {
                self->unk66 = self->unk66 + 2;
            }
        } else if (self->unk66 < -1 || self->unk66 > 1) {
            if (func_8002DE54(self, tgt) == 0) {
                if (self->unk66 > 0) {
                    self->unk66 = 1;
                } else {
                    self->unk66 = -1;
                }
            }
        }
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
    }
    self->unk66 = saved;
    return 0;
}
