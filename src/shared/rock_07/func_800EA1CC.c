#include "common.h"
#include "mmx6/x4.h"
struct X4_EffectObj* func_8002C3F8(void);
extern struct X4_BackgroundObj D_800971F8[3];

#define F8(p, o) (*(u8*)((u8*)(p) + (o)))
#define S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define F16(p, o) (*(s16*)((u8*)(p) + (o)))
#define U16(p, o) (*(u16*)((u8*)(p) + (o)))
#define F32(p, o) (*(void**)((u8*)(p) + (o)))

void func_800EA1CC(void* arg0) {
    void* obj;
    s32 v;
    register s32 w asm(
        "$2"); // !FAKE: depin: dropping it breaks the match (58/69)

    if (--F16(arg0, 0x7C) == 0) {
        obj = func_8002C3F8();
        if (obj != 0) {
            F8(obj, 0) = 1;
            F8(obj, 1) = 0x1A;
            F8(obj, 2) = 1;
            F16(obj, 0xA) =
                D_800971F8[0].x_pos.i.hi + D_800971F8[1].x_pos.i.hi + 0xA0;
            F16(obj, 0xE) =
                D_800971F8[0].y_pos.i.hi - D_800971F8[1].y_pos.i.hi + 0x390;
            F32(arg0, 0x88) = obj;
        }
        F8(arg0, 5)++;
    }
    if (--F16(arg0, 0x7E) == -1) {
        U16(arg0, 0x42) ^= 0x8000;
        S8(arg0, 0x61) -= 5;
        if (S8(arg0, 0x61) >= 0x1A) {
            S8(arg0, 0x61) = 0;
        }
        v = S8(arg0, 0x61);
        if ((w = v < 6) != 0) {
            w = 5;
        } else {
            w = v;
        }
        F16(arg0, 0x7E) = w;
    }
}
#undef F8
#undef S8
#undef F16
#undef U16
#undef F32
