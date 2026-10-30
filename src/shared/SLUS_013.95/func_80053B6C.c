#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

s32 play_sound(s32 a0, s32 a1, void* arg2);
struct X4_QuadObj* alloc_class6_slot(void);
s32 random_byte();
s32 func_8002D30C();
void func_80049F98();
extern u16 D_80090E70;
extern s8 D_80097425;
extern u8 D_800C4560;
extern s8 D_800CCEF4;

void func_80053B6C(struct X4_EffectObj* self) {
    struct X4_QuadObj* q;
    struct X4_QuadObj* q2;
    s32 t;

    t = *((u8*)self + 0x16) - 1;
    *((u8*)self + 0x16) = t;
    if ((t << 24) == 0) {
        *((u8*)self + 0x16) = 4;
        func_80049F98(self, 1, 0x60, 0x60, 2);
    }
    if (!(func_8002D30C() & 1)) {
        q = alloc_class6_slot();
        if (q != 0) {
            q->active = 1;
            q->id = 4;
            random_byte();
            q->x_pos.u.lo = D_80090E70 & 0xFFF;
            q->x_pos.u.hi = self->x_pos.u.hi;
            q->y_pos.u.hi = self->y_pos.u.hi;
        }
    }
    if (!(random_byte() & 3)) {
        q2 = alloc_class6_slot();
        if (q2 != 0) {
            q2->active = 1;
            q2->id = 6;
            q2->x_pos.u.hi = self->x_pos.u.hi;
            q2->y_pos.u.hi = self->y_pos.u.hi;
        }
    }
    if (D_80097425 == 0) {
        self->state++;
        if (self->active & 0x80) {
            *(s16*)((u8*)self + 0x14) = 0xC8;
        } else {
            *(s16*)((u8*)self + 0x14) = 0x28;
        }
        do {
        } while (0);
        self->unk7 = 1;
        D_800CCEF4 = 0;
        play_sound(0, 5, 0);
        D_800C4560 = 1;
    }
}
