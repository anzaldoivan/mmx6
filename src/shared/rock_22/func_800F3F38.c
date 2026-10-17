#include "common.h"
#include "mmx6/x4.h"

extern struct X4_PlayerObj D_800970A0;
s32 func_8002D380(void*, void*);
void func_8002D3B4(void*, s32);

s32 func_800F3F38(void* arg0) {
    s32 ret;
    s16 dx;
    s16 dy;

    ret = 0;
    dx = D_800970A0.x_pos.i.hi - ((struct X4_PlayerObj*)arg0)->x_pos.i.hi;
    dy = D_800970A0.y_pos.i.hi - ((struct X4_PlayerObj*)arg0)->y_pos.i.hi;
    if ((dx < 0 ? -dx : dx) < 0x40 || (dy < 0 ? -dy : dy) >= 0x60) {
        ret = 1;
    }
    if ((dx < 0 ? -dx : dx) >= 0x80) {
        ret |= 2;
    }
    func_8002D3B4(arg0, func_8002D380(arg0, &D_800970A0));
    return ret;
}
