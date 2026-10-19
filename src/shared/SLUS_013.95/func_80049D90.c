#include "common.h"
#include "mmx6/x4.h"

struct X4_VisualObj* func_8002C398(void);
extern u32* D_8007789C[];
extern u8 D_800970B4;

#define SCRATCH_1C (*(u8**)0x1F80001C)

void func_80049D90(void* arg0) {
    struct X4_VisualObj* self = arg0;
    struct X4_VisualObj* obj;
    u8* tbl;
    s32 off;
    u8 bg;

    obj = func_8002C398();
    if (obj != 0) {
        obj->active = 0x21;
        obj->id = 3;
        obj->unk2 = 1;
        bg = D_800970B4;
        obj->state = 0;
        obj->unk5 = 0;
        obj->unk6 = 0;
        obj->unk38 = 0;
        obj->bg_offset = bg;
        tbl = SCRATCH_1C;
        off = *(s32*)(tbl + 4);
        obj->animation_table = D_8007789C;
        obj->unk40 = 0;
        obj->unk42 = 0x7802;
        obj->unk16 = 0;
        obj->unk15 = 0;
        obj->unk3C = tbl + off;
        if (self->x_vel.val > 0) {
            obj->unk15 = 0x40;
        }
        obj->x_pos.i.hi = self->x_pos.i.hi;
        obj->y_pos.i.hi = self->y_pos.i.hi;
    }
}
