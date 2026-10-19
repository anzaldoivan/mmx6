#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern struct X4_BackgroundObj D_800971F8[3];
extern s8 D_800CCEF6;
extern s16 D_800EA2C8[];

void func_800E9900(void* arg0) {
    s16* p;
    s32 v;
    s32 x;
    s16* t;
    struct X4_BackgroundObj* b;
    s32 i;
    // !FAKE: register pin, local-alloc order differs from retail
    register s32 one asm("$2");
    t = &D_800EA2C8[0x128];
    i = D_800CCEF6 - 1;
    p = t + i;
    v = *p;
    b = D_800971F8;
    one = 1;
    b->unk4C = one;
    M2C_FIELD(b, s32*, 0xC) = 0;
    x = v << 16;
    b->x_pos.val += x / 30;
    if (b->x_pos.i.hi >= v) {
        b->x_pos.i.hi = *p;
        M2C_FIELD(arg0, u8*, 1) += 1;
    }
}
