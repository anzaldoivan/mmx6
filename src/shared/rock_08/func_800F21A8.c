#include "common.h"
#include "mmx6/x4.h"

extern s32 func_80017A04();
extern s32 move_object(void*);
extern s16 D_800F6AF8;

void func_800F21A8(struct X4_AnimatedObj* arg0) {
    u8 temp_v1;
    // !FAKE: depin: dropping it breaks the match (37/39)
    register s32 t asm("$2");

    func_80017A04();
    move_object(arg0);
    if ((t = arg0->x_vel.val) > 0) {
        if ((D_800F6AF8 + 0x6C0) >= arg0->x_pos.i.hi) {
            return;
        }
    } else if (arg0->x_pos.i.hi >= (D_800F6AF8 + 0x740)) {
        return;
    }
    temp_v1 = arg0->animation_step.fields.frame_index;
    if (temp_v1 == 4) {
        return;
    }
    if (temp_v1 == 5) {
        return;
    }
    arg0->unk6++;
}
