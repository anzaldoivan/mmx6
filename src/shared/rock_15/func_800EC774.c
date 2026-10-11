#include "common.h"
#include "mmx6/x4.h"

struct X4_VisualObj* func_8002C398(void);

void func_800EC774(struct X4_VisualObj* arg0) {
    struct X4_VisualObj* obj;
    u8 bg;

    obj = func_8002C398();
    if (obj != 0) {
        obj->active = 0x41;
        obj->id = 0x15;
        obj->unk2 = 0;
        obj->unk50 = (struct X4_PlayerObj*)arg0;
        obj->unk42 = arg0->unk42;
        obj->animation_table = arg0->animation_table;
        obj->unk3C = arg0->unk3C;
        obj->unk40 = arg0->unk40;
        bg = arg0->bg_offset;
        obj->unk16 = 3;
        obj->bg_offset = bg;
        obj->unk15 = arg0->unk15;
        obj->x_pos = arg0->x_pos;
        obj->y_pos = arg0->y_pos;
    }
}
