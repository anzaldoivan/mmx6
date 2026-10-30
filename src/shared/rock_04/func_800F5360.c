#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002A47C(s32);
void* enemy_slot_alloc();
extern s8 D_800CCEDC;

void func_800F5360(void* arg0, s32 arg1) {
    struct X4_AnimatedObj* src = arg0;
    struct X4_AnimatedObj* obj;
    u8 a1 = arg1;

    obj = enemy_slot_alloc();
    if (obj != 0) {
        obj->active = 0x41;
        obj->id = 0x36;
        obj->unk15 = src->unk15;
        M2C_FIELD(obj, void**, 0x80) = src;
        obj->unk2 = a1;
        obj->x_pos.i.hi = src->x_pos.i.hi;
        obj->x_pos.i.lo = 0;
        obj->y_pos.i.hi = src->y_pos.i.hi;
        obj->y_pos.i.lo = 0;
        if (D_800CCEDC != 0xC) {
            obj->unk42 = (((func_8002A47C(src->id) + 1) * 4 + 0x20) % 16) |
                         (((func_8002A47C(src->id) + 9) / 4 + 0x1E0) << 6);
        } else {
            obj->unk42 = 0x794C;
        }
        obj->animation_table = src->animation_table;
        obj->unk3C = src->unk3C;
        obj->unk40 = src->unk40;
        obj->bg_offset = src->bg_offset;
        M2C_FIELD(obj, u8*, 0x47) = M2C_FIELD(src, u8*, 0x47);
    }
}
