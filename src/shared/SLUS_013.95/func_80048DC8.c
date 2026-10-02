/* Adapted from sozud/mmx4 @29b62af src/main/items/item_00_breakable_wall.c:breakable_wall_update, AGPL-3.0; proven shared with X6 by exact signature 092b78e20e4a (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern void (*D_80077BC0[])(struct X4_ItemObj*);

void func_80048DC8(struct X4_ItemObj* arg0) {
    arg0->unk18.val = arg0->x_pos.val;
    arg0->unk1C.val = arg0->y_pos.val;
    D_80077BC0[arg0->state](arg0);
}
