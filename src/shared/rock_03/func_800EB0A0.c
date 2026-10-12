#include "common.h"
#include "mmx6/x4.h"

s32 func_8002D2D4();
extern struct X4_BackgroundObj D_800971F8[3];
extern u16 D_800F729C[];

#define H(p, o) (*(s16*)((u8*)(p) + (o)))
#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define UH(p, o) (*(u16*)((u8*)(p) + (o)))

void func_800EB0A0(void* arg0) {
    s32 a;
    s32 d;
    s32 b;
    s32 e;

    a = H(arg0, 0xA) - 0xA0;
    d = D_800971F8[0].x_pos.i.hi - a;
    if (d >= 0) {
        if (d < 0xA0) {
            goto x_near;
        }
    } else if (a - D_800971F8[0].x_pos.i.hi < 0xA0) {
    x_near:
        b = H(arg0, 0xE) - 0x78;
        e = D_800971F8[0].y_pos.i.hi - b;
        if (e >= 0) {
            if (e < 0x78) {
                goto y_near;
            }
        } else if (b - D_800971F8[0].y_pos.i.hi < 0x78) {
        y_near:
            UH(arg0, 0x7C) = D_800F729C[func_8002D2D4() & 7];
            UB(arg0, 6) = UB(arg0, 6) + 1;
        }
    }
}
