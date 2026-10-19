#include "common.h"
#include "mmx6/x4.h"
extern struct X4_BackgroundObj D_800971F8[3];
void func_8002998C(struct X4_BackgroundObj* arg0) {
    struct X4_BackgroundObj* bg = D_800971F8;
    // !FAKE: regalloc
    register s32 x asm("$2") = bg->x_pos.i.hi >> 1;

    arg0->x_pos.i.hi = x + arg0->unk40;
    {
        // !FAKE: regalloc
        register s32 y asm("$3") = bg->y_pos.u.hi;

        arg0->y_pos.i.hi = y + arg0->unk42;
    }
}
