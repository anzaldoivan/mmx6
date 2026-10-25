#include "common.h"
#include "mmx6/x4.h"

struct X4_VisualObj* func_8002C398(void);

#define SRC_W80(o) (*(s32*)((u8*)(o) + 0x80))
#define SRC_H86(o) (*(u16*)((u8*)(o) + 0x86))

void func_800FA31C(void* arg0) {
    struct X4_VisualObj* self = arg0;
    struct X4_VisualObj* obj;
    // !FAKE: depin: dropping it breaks the match (56/63)
    register s32 x asm("$2");

    obj = func_8002C398();
    if (obj != 0) {
        obj->active = 0x41;
        obj->id = 0xA;
        obj->unk2 = 0x20;
        obj->unk15 = self->unk15;
        obj->animation_table = self->animation_table;
        obj->bg_offset = self->bg_offset;
        obj->x_pos.i.hi = self->x_pos.i.hi;
        if (self->unk15 == 0) {
            x = self->x_pos.u.hi;
            x -= SRC_H86(self);
        } else {
            x = self->x_pos.u.hi;
            x += SRC_H86(self);
        }
        obj->x_pos.i.lo = x;
        obj->y_pos.i.hi = self->y_pos.i.hi + 6;
        obj->y_pos.i.lo = self->y_pos.i.hi + 6;
        *(s32*)&obj->unk50 = SRC_W80(self);
        obj->unk40 = self->unk40;
        obj->unk42 = self->unk42 & 0x7FFF;
        obj->unk3C = self->unk3C;
    }
}
