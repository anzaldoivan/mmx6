#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
s32 func_80027BA0(s32 arg0, s32 arg1, s32 arg2, u8* arg3);
void func_800F41D0(void*, s16, s16, s16);
extern struct X4_BackgroundObj D_800971F8[3];
extern u8 D_800FC9B0[];
extern s8 D_800FD51C;
extern s8 D_800FD51F;
extern s8 D_800FD521;

#define F(type, off) M2C_FIELD(self, type*, off)
#define G(type, off) (*(type*)(p + (off)))

void func_800EF7FC(void* self) {
    s16 v;
    u8* p;

    if (--F(s16, 0x7C) == 0) {
        D_800FD51F++;
        F(s16, 0x7C) = 3;
        func_800F41D0(self, 0x20, D_800971F8[0].x_pos.u.hi + 0x10,
                      D_800971F8[0].y_pos.u.hi + 8 + D_800FD51F * 0x10);
        func_800F41D0(self, 0x20, D_800971F8[0].x_pos.u.hi + 0x130,
                      D_800971F8[0].y_pos.u.hi + 8 + D_800FD51F * 0x10);
        p = D_800FC9B0;
        v = 0x3B0 - (D_800FD51F - 1) * 0x10;
        G(s16, 0x2) = v;
        G(s16, 0xA) = v;
        G(s16, 0x6) = D_800FD51F;
        G(s16, 0xE) = D_800FD51F;
        func_80027BA0(0, D_800971F8[0].x_pos.i.hi, D_800971F8[0].y_pos.i.hi, p);
        func_80027BA0(0, D_800971F8[0].x_pos.i.hi + 0x120,
                      D_800971F8[0].y_pos.i.hi, p + 8);
        D_800971F8[0].unk4C = 1;
        if (D_800FD51F == 0xF) {
            func_80012D9C(5);
            func_80016C48(2, 0x35, self);
            D_800FD51C = 1;
            F(s16, 0x7C) = 0;
            F(s16, 0x7E) = 0;
            F(s8, 0x88) = 0;
            D_800FD521 = 0;
            F(u8, 0x6)++;
        }
    }
}

#undef F
#undef G
