#include "common.h"
#include "mmx6/x4.h"

struct X4_VisualObj* func_8002C398(void);
s32 func_8002FF70();
void func_8003C7D8(void* arg0);
extern struct X4_Shot55Unk84 D_80073D60[];
extern u32* D_8007789C[];

void func_8003C6A4(void* arg0) {
    struct X4_VisualObj* self = arg0;
    struct X4_VisualObj* obj;
    u8 f;
    s32* t;
    s32 o;

    if (func_8002FF70() == 0x24) {
        func_8003C7D8(self);
        return;
    }
    obj = func_8002C398();
    if (obj != 0) {
        obj->active = 0x21;
        obj->id = 3;
        obj->unk2 = 2;
        obj->state = 0;
        obj->unk5 = 0;
        obj->unk6 = 0;
        obj->bg_offset = self->bg_offset;
        obj->unk38 = 0;
        t = SP_SPRITE_FRAMES;
        o = t[1];
        obj->animation_table = D_8007789C;
        obj->unk40 = 0;
        obj->unk42 = 0x7804;
        obj->unk16 = 1;
        obj->unk3C = (void*)((s8*)t + o);
        f = self->unk15;
        obj->unk15 = f;
        if (f == 0) {
            obj->x_pos.i.hi = self->x_pos.i.hi + D_80073D60[self->unk2].x;
        } else {
            obj->x_pos.i.hi = self->x_pos.i.hi - D_80073D60[self->unk2].x;
        }
        obj->y_pos.i.hi = self->y_pos.i.hi + D_80073D60[self->unk2].y;
    }
}
