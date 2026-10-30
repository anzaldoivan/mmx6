#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

s32 play_sound(s32 a0, s32 a1, void* arg2);
struct X4_VisualObj* func_8002C398(void);
extern u32* D_8007789C[];

#define SCRATCH_1C (*(u8**)0x1F80001C)
#define F_PTR(p, o) (*(u8**)((u8*)(p) + (o)))

void func_800383F8(void* arg0) {
    struct X4_VisualObj* self = arg0;
    struct X4_VisualObj* obj;
    u8* tbl;
    u8* p;
    s32 off;

    if (self->id == 0x3A) {
        play_sound(1, 9, self);
    } else if ((u8)(self->id - 0x38) >= 2) {
        play_sound(1, 0xC, self);
    }
    obj = func_8002C398();
    if (obj != 0) {
        obj->active = 0x21;
        obj->id = 3;
        if (self->id == 0x12 || self->id == 0x14 || self->id == 0x2E) {
            obj->unk2 = 4;
        } else {
            obj->unk2 = 3;
        }
        obj->bg_offset = self->bg_offset;
        tbl = SCRATCH_1C;
        off = *(s32*)(tbl + 4);
        obj->animation_table = D_8007789C;
        obj->unk40 = 0;
        obj->unk42 = 0x7802;
        obj->unk16 = 0;
        obj->unk3C = tbl + off;
        obj->x_pos.i.hi = self->x_pos.i.hi;
        obj->y_pos.i.hi = self->y_pos.i.hi;
        obj->unk15 = self->unk15 ^ 0x40;
        if ((u8)(self->id - 0x38) < 2) {
            obj->unk2 = 0xC;
        }
        if (self->id == 0x3A) {
            obj->unk2 = 0xC;
            p = F_PTR(self, 0x68);
            if (p != 0) {
                if (self->unk15 != 0) {
                    obj->x_pos.i.hi -= (s8)*p;
                } else {
                    obj->x_pos.i.hi += (s8)*p;
                }
            }
        }
    }
}
