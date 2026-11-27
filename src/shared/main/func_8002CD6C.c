#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern struct X4_BackgroundObj D_800971F8[3];
extern u16 D_8009B79C;

M2C_UNK func_8002CD6C(void* arg0) {
    struct X4_MovingObj* p = arg0;
    s16 dx;
    s16 dy;
    s8 i;

    i = p->bg_offset;
    p->on_screen = 0;
    if (i < 0) {
        dx = p->x_pos.i.hi;
        dy = p->y_pos.i.hi;
    } else {
        dx = p->x_pos.i.hi - D_800971F8[i].x_pos.i.hi;
        dy = p->y_pos.i.hi - D_800971F8[i].y_pos.i.hi;
    }
    if ((u16)(dx + 0x60) < (u16)(D_8009B79C + 0xC0) &&
        (u16)(dy + 0x50) < 0x190) {
        p->on_screen = 1;
    }
}
