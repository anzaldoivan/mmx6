#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

struct X4_VisualObj* func_8002C398(void);

void func_800F9F7C(void* arg0, M2C_UNK arg1, M2C_UNK arg2) {
    struct X4_VisualObj* self = arg0;
    struct X4_VisualObj* obj;
    u8 kind = arg1;
    s16 angle = arg2;

    obj = func_8002C398();
    if (obj != 0) {
        obj->active = 0x41;
        obj->id = 0xA;
        obj->unk2 = kind;
        obj->unk15 = self->unk15;
        obj->animation_table = self->animation_table;
        obj->bg_offset = self->bg_offset;
        obj->x_pos.i.hi = self->x_pos.i.hi;
        obj->x_pos.i.lo = 0;
        obj->y_pos.i.hi = self->y_pos.i.hi;
        obj->y_pos.i.lo = 0;
        obj->unk50 = (struct X4_PlayerObj*)self;
        obj->unk40 = self->unk40;
        obj->unk42 = self->unk42 & 0x7FFF;
        obj->unk3C = self->unk3C;
        {
            s32 k = kind & 0xF0;
            if (k == 0) {
                obj->unk5A = angle;
                self->unk7++;
            } else if (k == 0x30) {
                obj->unk5A = angle;
            }
        }
    }
}
