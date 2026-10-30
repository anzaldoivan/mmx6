/* Adapted from sozud/mmx4 @807a01b src/main/items/item_01_stage_block.c:drop_item, AGPL-3.0; proven shared with X6 by exact signature 806a7421f0d6 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
void drop_item(struct X4_BaseObj* arg0, s8 arg1, s16 arg2, s16 arg3);

void func_8004E654(struct X4_BaseObj* arg0, s8 arg1) {
    drop_item(arg0, arg1, arg0->x_pos.i.hi, arg0->y_pos.i.hi);
}
