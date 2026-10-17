#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
extern s32 D_800FD040[];
extern s32 D_800FD280[];
extern s32 D_800FD5A0;

void func_800F7B88(void* arg0) {
    void* s0;
    // !FAKE: pin table base register
    register s32 tbl asm("$6");
    s32 d;
    s32 x;
    s32 y;

    s0 = M2C_FIELD(arg0, void**, 0x84);
    func_80017A04(arg0);
    if (M2C_FIELD(arg0, s8*, 2) == 1) {
        tbl = (s32)D_800FD040;
    } else {
        tbl = (s32)D_800FD280;
    }
    x = *(s32*)(((M2C_FIELD(s0, s16*, 0x7C) << 3) +
                 (M2C_FIELD(s0, s16*, 0x7E) * 3 << 4)) +
                tbl);
    d = D_800FD5A0;
    x *= d;
    M2C_FIELD(arg0, s32*, 0x20) = x;
    tbl += ((M2C_FIELD(s0, s16*, 0x7C) << 3) +
            (M2C_FIELD(s0, s16*, 0x7E) * 3 << 4));
    y = ((s32*)tbl)[1] * d;
    M2C_FIELD(arg0, s32*, 0x24) = y;
    if (x == 0 && y == 0) {
        M2C_FIELD(arg0, u8*, 6)++;
    }
    M2C_FIELD(arg0, u8*, 6)++;
}
