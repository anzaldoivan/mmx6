#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
extern struct X4_BackgroundObj D_800971F8[3];
void func_800FA40C(void* arg0) {
    s32 v;

    v = D_800971F8[0].x_pos.u.hi + 0x10;
    D_800971F8[0].x_pos.u.hi = v;
    if ((s16)v >= 0x120) {
        D_800971F8[0].x_pos.u.hi = 0x120;
        D_800971F8[2].unk3 = 0;
        M2C_FIELD(arg0, s16*, 8) = 0x7B;
        M2C_FIELD(arg0, s16*, 0xA) = 0xB;
        M2C_FIELD(arg0, u8*, 1) = M2C_FIELD(arg0, u8*, 1) + 1;
    }
}
