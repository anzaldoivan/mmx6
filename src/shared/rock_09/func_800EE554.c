/* Adapted from sozud/mmx4 @807a01b src/main/mains/main_02_item_carrier.c:item_carrier_hover, AGPL-3.0; proven shared with X6 by exact signature 45fa9bb77d1e (see THIRD_PARTY.md). */
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
extern void (*D_800F62F8[])(struct X4_MainObj*);
M2C_UNK animate_object(void*);
M2C_UNK func_8002CB50();

void func_800EE554(struct X4_MainObj* self) {
    D_800F62F8[self->action_phase](self);
    animate_object(ANIMATED_OBJECT(self));
    func_8002CB50(MOVING_OBJECT(self));
}
