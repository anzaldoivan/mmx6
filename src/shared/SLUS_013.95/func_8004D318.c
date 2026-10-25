#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define F32(p, off) (*(s32*)((u8*)(p) + (off)))

extern struct X4_BackgroundObj background_objects[3];
extern u16 D_8009B79C;
struct X4_QuadObj* func_8002C7F0(void);
M2C_UNK func_8002C9B0();
void func_8004D598(void* arg0);
s32 func_80065944(s32);
s32 func_80065A14(s32);

void func_8004D318(struct X4_QuadObj* self) {
    struct X4_QuadObj* q;
    s16 dx;
    s16 dy;

    if (self->unk2 == 0) {
        dx = self->x_pos.i.hi - background_objects[self->bg_offset].x_pos.i.hi;
        dy = self->y_pos.i.hi - background_objects[self->bg_offset].y_pos.i.hi;
        if (dx < 0 || D_8009B79C < dx || dy < 0 || dy >= 0xF1) {
            ((M2C_UNK(*)())func_8002C9B0)(self);
            return;
        }
        if (F32(self, 0x38) == 0) {
            if (0xF0 - dy < dy) {
                F32(self, 0x3C) = dy;
            } else {
                F32(self, 0x3C) = 0xF0 - dy;
            }
        } else if (F32(self, 0x38) == 0x400) {
            if (D_8009B79C - dx < dx) {
                F32(self, 0x3C) = dx;
            } else {
                F32(self, 0x3C) = D_8009B79C - dx;
            }
        } else {
            F32(self, 0x3C) = dx;
            if (dx < dy) {
                F32(self, 0x3C) = dy;
            }
            if (F32(self, 0x3C) < D_8009B79C - dx) {
                F32(self, 0x3C) = D_8009B79C - dx;
            }
            if (F32(self, 0x3C) < 0xF0 - dy) {
                F32(self, 0x3C) = 0xF0 - dy;
            }
            F32(self, 0x3C) = (F32(self, 0x3C) * 0x16A0) >> 12;
        }
        F32(self, 0x50) = func_80065A14(F32(self, 0x38));
        F32(self, 0x4C) = func_80065944(F32(self, 0x38));
        F32(self, 0x54) = -func_80065944(F32(self, 0x38));
        q = func_8002C7F0();
        if (q != 0) {
            q->active = self->active;
            q->id = self->id;
            q->x_pos.i.hi = self->x_pos.i.hi;
            q->y_pos.i.hi = self->y_pos.i.hi;
            q->unk36 = self->unk36;
            q->bg_offset = self->bg_offset;
            q->unk34 = self->unk34;
            q->unk2 = 1;
            F32(q, 0x38) = F32(self, 0x38);
            F32(q, 0x50) = F32(self, 0x50);
            F32(q, 0x4C) = F32(self, 0x4C);
            F32(q, 0x54) = F32(self, 0x54);
            F32(q, 0x3C) = F32(self, 0x3C);
        }
    }
    self->on_screen = 1;
    F32(self, 0x44) = 4;
    F32(self, 0x40) = 4;
    F32(self, 0x48) = 0x30;
    ((void (*)(void*, void*))func_8004D598)(self, q);
    self->state++;
}
