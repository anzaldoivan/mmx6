#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern struct X4_BackgroundObj D_800971F8[3];
extern s8 D_800CCEF6;
extern s16 D_800EA2C8[];

void func_800E986C(void* arg0) {
    s16* p;
    s32 v;
    s32 x;
    s16* t;
    struct X4_BackgroundObj* b;
    s32 i;
    // !FAKE: register pin, local-alloc order differs from retail
    register s32 one asm("$2");
    t = &D_800EA2C8[0x120];
    i = D_800CCEF6 - 1;
    p = t + i;
    v = *p;
    b = D_800971F8;
    one = 1;
    b[1].unk4C = one;
    M2C_FIELD(&b[1], s32*, 0xC) = 0;
    x = v << 16;
    b[1].x_pos.val += x / 120;
    if (b[1].x_pos.i.hi >= v) {
        b[1].x_pos.i.hi = *p;
        M2C_FIELD(arg0, s16*, 4) = 0x1E;
        M2C_FIELD(arg0, u8*, 1) += 1;
    }
}
