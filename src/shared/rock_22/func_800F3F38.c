#include "common.h"
#include "mmx6/x4.h"

extern struct X4_PlayerObj g_Player;
s32 func_8002D380(void*, void*);
void set_velocity_from_angle(void*, s32);

s32 func_800F3F38(void* arg0) {
    s32 ret;
    s16 dx;
    s16 dy;

    ret = 0;
    dx = g_Player.x_pos.i.hi - ((struct X4_PlayerObj*)arg0)->x_pos.i.hi;
    dy = g_Player.y_pos.i.hi - ((struct X4_PlayerObj*)arg0)->y_pos.i.hi;
    if ((dx < 0 ? -dx : dx) < 0x40 || (dy < 0 ? -dy : dy) >= 0x60) {
        ret = 1;
    }
    if ((dx < 0 ? -dx : dx) >= 0x80) {
        ret |= 2;
    }
    set_velocity_from_angle(arg0, func_8002D380(arg0, &g_Player));
    return ret;
}
