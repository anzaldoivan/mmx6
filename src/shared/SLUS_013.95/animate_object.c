#include "common.h"
#include "mmx6/x4.h"

s32 animate_object(struct X4_AnimatedObj* arg0) {
    if (--arg0->animation_step.fields.duration == 0) {
        arg0->animation_cursor += arg0->animation_step.fields.relative_step;
        arg0->animation_step.packed = *arg0->animation_cursor;
    }
}
