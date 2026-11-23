
#include "common.h"
#include "mmx6/x4.h"

struct X4_VisualObj* find_free_visual_obj(void);

void func_8003D26C(void* p) {
    struct X4_VisualObj* arg0 = p;
    struct X4_VisualObj* obj;
    u8 bg;

    obj = find_free_visual_obj();
    if (obj != NULL) {
        obj->active = 0x21;
        obj->id = 1;
        bg = arg0->bg_offset;
        obj->state = 0;
        obj->unk5 = 0;
        obj->unk6 = 0;
        obj->bg_offset = bg;
    }
}
