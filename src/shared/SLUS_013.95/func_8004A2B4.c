#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
struct X4_VisualObj* find_free_visual_obj(void);
s32 random_byte();

// Spawns `arg4` visual objects (id 9) at random points of a box beside the object's hitbox (`arg1` picks the side), with
// a velocity mode from the low bits of `arg0`. The width is read into `w` before ry is combined from its two random
// bytes: that keeps the fourth random byte live at the width test, as retail's reload register choice needs (C0396).
M2C_UNK func_8004A2B4(M2C_UNK arg0, M2C_UNK arg1, void* arg2, M2C_UNK arg3,
                      M2C_UNK arg4) {
    u8 flags = arg0;
    u8 side = arg1;
    struct X4_MainObj* self = arg2;
    s16 margin = arg3;
    s16 count = arg4;
    struct X4_Unk_unk68* box;
    struct X4_VisualObj* obj;
    s16 left;
    s16 right;
    s16 top;
    s16 bottom;
    s16 i;
    s32 width;
    s32 height;
    u16 rx;
    u16 ry;
    s16 w;
    s32 r3;
    s32 r4;

    box = self->terrain_box;
    left = self->x_pos.i.hi;
    right = left;
    top = self->y_pos.i.hi + box->unk1;
    bottom = top;
    switch (side) {
    case 1:
        if (self->unk15 == 0) {
            left = left + box->unk0;
            left = left - box->unk2;
            right = left + box->unk2 * 2;
        } else {
            right = left - box->unk0;
            right = box->unk2 + right;
            left = right - box->unk2 * 2;
        }
        top = top - box->unk3;
        bottom = top;
        break;
    case 2:
        if (self->unk15 == 0) {
            left = left + box->unk0;
            left = left - box->unk2;
            right = left + box->unk2 * 2;
        } else {
            right = left - box->unk0;
            right = box->unk2 + right;
            left = right - box->unk2 * 2;
        }
        top = box->unk3 + top;
        bottom = top;
        break;
    case 3:
        if (self->unk15 == 0) {
            left = left + box->unk0;
            left = left - box->unk2;
            right = left;
        } else {
            right = left - box->unk0;
            left = box->unk2 + right;
            right = left;
        }
        top = top - box->unk3;
        bottom = box->unk3 + bottom;
        break;
    case 4:
        if (self->unk15 == 0) {
            left = left + box->unk0;
            left = box->unk2 + left;
            right = left;
        } else {
            right = left - box->unk0;
            left = right - box->unk2;
            right = left;
        }
        top = top - box->unk3;
        bottom = box->unk3 + bottom;
        break;
    }
    left = left - margin;
    right = right + margin;
    top = top - margin;
    bottom = bottom + margin;
    for (i = 0; i < count; i++) {
        width = right - left;
        height = bottom - top;
        obj = find_free_visual_obj();
        if (obj != 0) {
            obj->active = 0x21;
            obj->id = 9;
            obj->unk2 = 0;
            rx = (random_byte() << 8) + random_byte() + 1;
            r3 = random_byte();
            r4 = random_byte();
            w = width;
            ry = (r3 << 8) + r4 + 1;
            if (w == 0) {
                obj->x_pos.i.hi = left;
            } else {
                obj->x_pos.i.hi = left + rx % w;
            }
            if ((s16)height == 0) {
                obj->y_pos.i.hi = top;
            } else {
                obj->y_pos.i.hi = top + ry % (s16)height;
            }
            obj->x_pos.i.lo = 0;
            obj->y_pos.i.lo = 0;
            switch (flags & 3) {
            case 1:
                obj->x_vel.val = 0;
                obj->y_vel.val = 0x10000;
                break;
            case 2:
                if (obj->x_pos.i.hi < self->x_pos.i.hi) {
                    obj->x_vel.val = -0x18000;
                    obj->y_vel.val = 0;
                } else {
                    obj->x_vel.val = 0x18000;
                    obj->y_vel.val = 0;
                }
                break;
            default:
                obj->x_vel.val = 0;
                obj->y_vel.val = 0;
                break;
            }
            obj->unk15 = 0;
            obj->unk5C.value = flags >> 4;
            obj->state = 0;
            obj->unk5 = 0;
            obj->unk6 = 0;
        }
    }
}
