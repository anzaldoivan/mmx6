/* Adapted from sozud/mmx4 @29b62af src/main/items/item_08_boss_door.c:boss_door_update, AGPL-3.0; proven shared with X6 by exact signature 3841861bc21e (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern void (*D_80078DD4[])(struct X4_ItemObj*);

#define M2C_UNK s32
s32 func_8002CB50(struct X4_BaseObj*);
void func_80050DFC(struct X4_ItemObj* arg0) {
    arg0->unk18.val = arg0->x_pos.val;
    arg0->unk1C.val = arg0->y_pos.val;
    D_80078DD4[arg0->state](arg0);
    ((s32 (*)())func_8002CB50)(BASE_OBJECT(arg0));
}
