// prog SLUS_013.95 | system object | range 0x8002D2B0-0x8002D2D0
#include "common.h"
#include "mmx6/object.h"

// 0x8002D2B0 move_object: adds x_vel to x_pos and subtracts y_vel from y_pos.
// basis: x4 exact 6534750cb678
// callers: none known
void move_object(void* arg0) {
    struct AnimatedObj* o = arg0;

    o->x_pos.val = (s32)(o->x_pos.val + o->x_vel.val);
    o->y_pos.val = (s32)(o->y_pos.val - o->y_vel.val);
}
