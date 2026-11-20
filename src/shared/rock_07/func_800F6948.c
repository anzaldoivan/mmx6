// rolefeed (3.1 T4): func_800F6948 of src/rock_07/E9860.c
#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

#include "mmx6/x4.h"

M2C_UNK start_pad_vibration(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
extern struct X4_BackgroundObj background_objects[3];

#include "common.h"
#include "mmx6/x4.h"

#define F32_AT(p, off) (*(X4_f32*)((u8*)(p) + (off)))

void* func_8002C458();
extern s16 D_800F9868;

void func_800F6948(struct X4_AnimatedObj* self, s32 arg1, s32 arg2) {
    struct X4_AnimatedObj* obj;
    u8 id = arg1;

    obj = func_8002C458();
    if (obj != 0) {
        obj->active = 0x41;
        obj->id = 0x16;
        obj->unk2 = id;
        obj->unk42 = self->unk42 & 0x7FFF;
        obj->animation_table = self->animation_table;
        obj->unk3C = self->unk3C;
        obj->unk40 = self->unk40;
        obj->unk15 = self->unk15;
        obj->bg_offset = self->bg_offset;
        F32_AT(obj, 0x84).val = arg2;
        obj->x_pos.i.hi = self->x_pos.i.hi;
        obj->x_pos.i.lo = 0;
        obj->y_pos.i.hi = self->y_pos.i.hi;
        obj->y_pos.i.lo = 0;
        F32_AT(obj, 0x7C).val = F32_AT(self, 0x80).val;
        D_800F9868 += 1;
    }
}
