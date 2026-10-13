#include "common.h"
#include "mmx6/x4.h"

extern u16 D_80090E70;
s32 func_80013AA4(s8 arg0);
struct X4_QuadObj* func_8002C7F0(void);
s32 func_8002D2D4();
s32 func_8002D30C();
void func_80049F98();

void func_80053A20(struct X4_BaseObj* self) {
    struct X4_QuadObj* q;
    u32 i;

    if (*(u16*)&self->bg_offset != 0) {
        register s32 b asm("$3");
        (*(u16*)&self->bg_offset)--;
        b = self->unk16 - 1;
        self->unk16 = b;
        if ((b << 24) == 0) {
            self->unk16 = 4;
            func_80049F98(self, 1, 0x60, 0x60, 2);
        }
        if (!(func_8002D30C() & 1)) {
            q = func_8002C7F0();
            if (q != 0) {
                q->active = 1;
                q->id = 4;
                func_8002D2D4();
                q->x_pos.u.lo = D_80090E70 & 0xFFF;
                q->x_pos.u.hi = self->x_pos.u.hi;
                q->y_pos.u.hi = self->y_pos.u.hi;
            }
        }
    } else {
        for (i = 0; i < 16; i++) {
            struct X4_QuadObj* p = func_8002C7F0();
            if (p != 0) {
                p->active = 1;
                p->id = 6;
                p->x_pos.u.hi = self->x_pos.u.hi;
                p->y_pos.u.hi = self->y_pos.u.hi;
                p->unk6 = i;
            }
        }
        func_80013AA4(0x19);
        {
            register s32 s asm("$2") = (u8)self->state + 1;
            self->state = s;
        }
    }
}
