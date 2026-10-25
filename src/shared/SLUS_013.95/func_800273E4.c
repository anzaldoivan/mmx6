#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj background_objects[3];
extern u16 D_8009B79C;

void func_800274A0(s32 arg0, s32 arg1, s32 arg2);
void func_80027780(s32 arg0, s32 arg1, s32 arg2);

void func_800273E4(void) {
    struct X4_BackgroundObj* p;
    u32 i;
    s16 x;
    s16 y;
    s32 y0;
    s32 t;

    i = 0;
    p = background_objects;
    do {
        if (p->pad51[1] < 0) {
            x = p->x_pos.i.hi;
            y = p->y_pos.i.hi;
            y0 = y - 0x10;
            func_800274A0(i, x - 0x10, y0);
            t = x + 0x10;
            func_800274A0(i, t + D_8009B79C, y0);
            func_80027780(i, x, y0);
            func_80027780(i, x, y + 0x100);
        }
        i++;
        p++;
    } while (i < 3);
}
