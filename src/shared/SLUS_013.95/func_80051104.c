/* Adapted from sozud/mmx4 @29b62af src/main/items/item_08_boss_door.c:boss_door_block_player, AGPL-3.0; proven shared with X6 by exact signature 37a985cf43c2 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern struct X4_PlayerObj D_800970A0;

void func_80051104(struct X4_ItemObj* arg0) {
    volatile struct X4_PlayerObj* player = &D_800970A0;

    if (arg0->unk72 & 4) {
        player->unk71 = (u8)(player->unk71 & 0xB);
    }
    if (arg0->unk72 & 8) {
        player->unk71 = (u8)(player->unk71 & 7);
    }
}
