#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

struct X4_VisualObj* func_8002C398(void);

M2C_UNK func_8004A0C0(s8 arg0, s16 arg1, s16 arg2, s32 arg3) {
    struct X4_VisualObj* obj;
    u8 v = arg3;

    obj = func_8002C398();
    if (obj != 0) {
        obj->active = 0x21;
        obj->id = 4;
        obj->unk2 = 0;
        obj->state = 0;
        obj->unk5 = 0;
        obj->unk6 = 0;
        obj->unk5C.value = v;
        obj->x_pos.i.hi = arg1;
        obj->x_pos.i.lo = 0;
        obj->y_pos.i.hi = arg2;
        obj->y_pos.i.lo = 0;
        obj->unk15 = 0;
        obj->bg_offset = 0;
        obj->unk16 = 1;
    }
    return (M2C_UNK)obj;
}
