/* Adapted from sozud/mmx4 @807a01b src/main/object_update.c:func_80021C14, AGPL-3.0; proven shared with X6 by exact signature cac1f7cae392 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern struct X4_EngineObj D_800CCED0;
extern struct X4_RideArmorObj D_800CD340;
extern void (*D_80071380[])(struct X4_RideArmorObj*);

void func_80020A08(void) {
    if (D_800CCED0.unk10 == 0) {
        if (D_800CD340.active != 0) {
            D_80071380[D_800CD340.id](&D_800CD340);
            return;
        }
    } else if (D_800CD340.active != 0) {
        if (D_800CD340.active & 8) {
            D_80071380[D_800CD340.id](&D_800CD340);
            return;
        }
        if (D_800CD340.on_screen != 0) {
            func_8002CD6C(&D_800CD340);
        }
    }
}
