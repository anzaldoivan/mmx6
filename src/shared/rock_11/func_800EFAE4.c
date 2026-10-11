#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_80027BA0(s32 arg0, s32 arg1, s32 arg2, u8* arg3);
s32 func_8002D2D4();
void func_800F4664(s16 arg0, s16 arg1);
extern struct X4_BackgroundObj D_800971F8[3];
extern u8 D_800FC9C0[];
extern s8 D_800FD51C;
extern s8 D_800FD51F;
extern s8 D_800FD520;

#define F(type, off) M2C_FIELD(self, type*, off)

void func_800EFAE4(void* self) {
    s32 i;
    s32 row;
    s16 x;
    s32 y;

    i = 0;
    D_800FD520 = 0;
    D_800FD51C = 0;
    for (; i < D_800FD51F / 2 + 1;) {
        row = i << 5;
        x = 0x10 - (func_8002D2D4() & 0x1F);
        y = (s16)(0x10 - (func_8002D2D4() & 0x1F)) + 8;
        func_800F4664(x + (s16)(D_800971F8[0].x_pos.u.hi + 0x10),
                      D_800971F8[0].y_pos.i.hi + (row + y));
        i++;
        x = 0x10 - (func_8002D2D4() & 0x1F);
        y = (s16)(0x10 - (func_8002D2D4() & 0x1F)) + 8;
        func_800F4664(x + (s16)(D_800971F8[0].x_pos.u.hi + 0x130),
                      D_800971F8[0].y_pos.i.hi + (row + y));
    }
    func_80027BA0(0, D_800971F8[0].x_pos.i.hi, D_800971F8[0].y_pos.i.hi,
                  D_800FC9C0);
    func_80027BA0(0, D_800971F8[0].x_pos.i.hi + 0x120, D_800971F8[0].y_pos.i.hi,
                  D_800FC9C0 + 8);
    D_800FD51F = 0;
    D_800971F8[0].unk4C = 1;
    F(s16, 0x7C) = 0x42;
    F(u8, 0x6)++;
}

#undef F
