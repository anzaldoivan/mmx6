// rolefeed (3.1 T4): func_80050DFC of src/main/4FF7C.c
#include "common.h"

void* enemy_slot_alloc();

#undef PA4

/* Adapted from sozud/mmx4 @4e16dfc src/main/items/item_08_boss_door.c:boss_door_update, AGPL-3.0; proven shared with X6 by exact signature 3841861bc21e (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern void (*D_80078DD4[])(struct X4_ItemObj*);

#define M2C_UNK s32
s32 func_8002CB50();
void func_80050DFC(struct X4_ItemObj* arg0) {
    arg0->unk18.val = arg0->x_pos.val;
    arg0->unk1C.val = arg0->y_pos.val;
    D_80078DD4[arg0->state](arg0);
    func_8002CB50(BASE_OBJECT(arg0));
}
