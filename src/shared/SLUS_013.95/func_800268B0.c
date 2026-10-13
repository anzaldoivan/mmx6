#include "common.h"
#include "mmx6/x4.h"

extern u16 D_80090D6A;
extern struct X4_BackgroundObj D_800971F8[3];
void func_80027D6C(u32, s32, s32);

void func_800268B0(s32 arg0) {
    u32 count;
    u32 i;
    u32 j;
    u32 k;
    s32 y;
    s32 x;

    count = 0x40;
    if (D_80090D6A == 0) {
        count = 0x20;
    }
    for (i = 0; i < 3; i++) {
        y = D_800971F8[i].y_pos.i.hi / 16 + arg0;
        for (j = 0; j < 0x20; y++, j++) {
            if (y >= 0) {
                x = D_800971F8[i].x_pos.i.hi / 16 + arg0;
                for (k = 0; k < count; k++, x++) {
                    if (x >= 0) {
                        func_80027D6C(i, x, y);
                    }
                }
            }
        }
    }
}
