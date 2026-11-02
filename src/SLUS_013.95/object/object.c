#include "common.h"
#include "mmx6/object.h"

void move_object(void* arg0) {
    struct AnimatedObj* o = arg0;

    o->x_pos.val = (s32)(o->x_pos.val + o->x_vel.val);
    o->y_pos.val = (s32)(o->y_pos.val - o->y_vel.val);
}
