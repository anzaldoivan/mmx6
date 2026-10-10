/* Adapted from sozud/mmx4 @29b62af src/main/items/item_01_stage_block.c:drop_item, AGPL-3.0; proven shared with X6 by exact signature 806a7421f0d6 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
void func_8004E680(struct X4_BaseObj* arg0, s8 arg1, s16 arg2, s16 arg3);

void func_8004E654(struct X4_BaseObj* arg0, s8 arg1) {
    func_8004E680(arg0, arg1, arg0->x_pos.i.hi, arg0->y_pos.i.hi);
}
