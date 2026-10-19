#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F41D0(void* arg0, u8 arg1, s16 arg2, s16 arg3);
extern struct X4_BackgroundObj D_800971F8[3];
extern s8 D_800FD51F;

void func_800F3B70(void* arg0) {
    M2C_FIELD(arg0, s16*, 0x7C) = 3;
    D_800FD51F = 0;
    func_800F41D0(arg0, 0x20, D_800971F8[0].x_pos.u.hi + 0x10,
                  D_800971F8[0].y_pos.u.hi + 8);
    func_800F41D0(arg0, 0x20, D_800971F8[0].x_pos.u.hi + 0x130,
                  D_800971F8[0].y_pos.u.hi + 8);
    M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
}
