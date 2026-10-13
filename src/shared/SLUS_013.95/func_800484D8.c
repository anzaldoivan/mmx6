/* Adapted from sozud/mmx4 @29b62af src/main/items/item_20_gravity_switch.c:gravity_switch_main, AGPL-3.0; proven shared with X6 by exact signature 590ed0325c72 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern void (*D_80077BA4[])(struct X4_ItemObj*);

#define M2C_UNK s32
s32 func_8002CB50(struct X4_BaseObj*);
void func_800484D8(struct X4_ItemObj* arg0) {
    D_80077BA4[arg0->unk5](arg0);
    ((s32 (*)())func_8002CB50)(BASE_OBJECT(arg0));
}
