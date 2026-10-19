#include "common.h"
#include "mmx6/x4.h"

struct X4_AnimatedObj* func_8002A3AC(u8);

void func_8002A4E4(struct X4_StageObjectRecord* rec) {
    struct X4_AnimatedObj* obj;

    while (rec->object_type != 0xF) {
        obj = func_8002A3AC(rec->object_type);
        if (obj != 0) {
            obj->active = 1;
            obj->id = rec->id;
            obj->unk2 = rec->subtype;
            obj->x_pos.i.hi = rec->x;
            obj->y_pos.i.hi = rec->y;
            obj->backref = rec;
        }
        rec++;
    }
}
