#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

struct X4_QuadObj* func_8002C7F0(void);
s32 func_8002D2D4();
s32 func_8002D30C();
void func_80049F98();
extern u16 D_80090E70;

void func_80053E44(struct X4_EffectObj* self) {
    struct X4_QuadObj* q;
    struct X4_QuadObj* q2;
    register s32 c asm("$2");
    s32 t;

    c = *(u16*)((u8*)self + 0x14);
    if (c != 0) {
        *(u16*)((u8*)self + 0x14) = c - 1;
        t = *((u8*)self + 0x16) - 1;
        *((u8*)self + 0x16) = t;
        if ((t << 24) == 0) {
            *((u8*)self + 0x16) = 4;
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
        self->state++;
        q2 = func_8002C7F0();
        if (q2 != 0) {
            q2->active = 1;
            q2->id = 8;
            q2->x_pos.u.hi = self->x_pos.u.hi;
            q2->y_pos.u.hi = self->y_pos.u.hi;
        }
        *(u16*)((u8*)self + 0x14) = 10;
    }
}
