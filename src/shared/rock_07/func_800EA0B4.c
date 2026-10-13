#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
M2C_UNK func_80030ECC();
extern struct X4_BackgroundObj D_800971F8[3];
extern void (*D_800F86A4[])(void*);

void func_800EA0B4(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x5) != 2 && M2C_FIELD(arg0, s8*, 0x5C) <= 0) {
        M2C_FIELD(arg0, u8*, 0x5C) = 0;
        M2C_FIELD(arg0, u8*, 0x4) = 2;
        M2C_FIELD(arg0, u8*, 0x3) = 0;
        M2C_FIELD(arg0, u8*, 0x5) = 0;
        M2C_FIELD(arg0, u8*, 0x6) = 0;
        return;
    }
    if (D_800971F8[0].x_pos.i.hi >= 0x1540 && M2C_FIELD(arg0, s8*, 0x5) != 9) {
        M2C_FIELD(arg0, u8*, 0x5) = 9;
        M2C_FIELD(arg0, u8*, 0x6) = 0;
    }
    M2C_FIELD(arg0, s32*, 0x18) = M2C_FIELD(arg0, s32*, 0x8);
    M2C_FIELD(arg0, s32*, 0x1C) = M2C_FIELD(arg0, s32*, 0xC);
    func_80017A04(arg0);
    D_800F86A4[M2C_FIELD(arg0, s8*, 0x5)](arg0);
    M2C_FIELD(arg0, s16*, 0xA) =
        M2C_FIELD(arg0, s16*, 0x82) +
        (D_800971F8[0].x_pos.i.hi + D_800971F8[1].x_pos.i.hi);
    {
        s32 t = D_800971F8[0].y_pos.u.hi + 0x3B8;
        t -= D_800971F8[1].y_pos.u.hi;
        M2C_FIELD(arg0, s16*, 0xE) = M2C_FIELD(arg0, s16*, 0x86) + t;
    }
    if (M2C_FIELD(arg0, s8*, 0x8F) >= 2) {
        func_80030ECC(arg0);
    }
}
