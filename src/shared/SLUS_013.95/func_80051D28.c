#include "common.h"
#include "mmx6/x4.h"

struct X4_VisualObj* func_8002C398(void);
extern struct X4_PlayerObj D_800970A0;

void func_80051D28(struct X4_PlayerObj* arg0) {
    struct X4_PlayerObj* player = &D_800970A0;
    struct X4_VisualObj* obj1;
    struct X4_VisualObj* obj2;
    struct X4_VisualObj* obj3;
    struct X4_VisualObj* obj4;
    u8 step;
    s32 id;

    step = player->item_step;
    player->x_pos.val = arg0->x_pos.val;
    if (step == 2) {
        id = 0x25;
        obj1 = func_8002C398();
        if (obj1 != 0) {
            obj1->active = 0x49;
            obj1->id = id;
            obj1->unk2 = 0;
            obj1->bg_offset = arg0->bg_offset;
            obj1->unk50 = arg0;
        }
        obj2 = func_8002C398();
        if (obj2 != 0) {
            obj2->active = 0x49;
            obj2->id = id;
            obj2->unk2 = 1;
            obj2->bg_offset = arg0->bg_offset;
            obj2->unk50 = arg0;
        }
        obj3 = func_8002C398();
        if (obj3 != 0) {
            obj3->active = 0x49;
            obj3->id = id;
            obj3->unk2 = step;
            obj3->bg_offset = arg0->bg_offset;
            obj3->unk50 = arg0;
        }
        obj4 = func_8002C398();
        if (obj4 != 0) {
            obj4->active = 0x49;
            obj4->id = id;
            obj4->unk2 = 3;
            obj4->bg_offset = arg0->bg_offset;
            obj4->unk50 = arg0;
        }
        arg0->unk5++;
    }
}
