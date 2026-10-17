#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK func_80017A04(void*);                   /* extern */
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_8002D230(void*);                   /* extern */
M2C_UNK func_8003D330();                        /* extern */
s32 func_80040498();                            /* extern */
extern struct X4_BackgroundObj D_800971F8[3];
extern s8 D_800CCF5C;
extern u16 D_800FCE64;

void func_800FB54C(void* arg0) {
    if (func_80040498() != 0) {
        func_8002CCB0(arg0, 0x40, 0x40);
        return;
    }
    D_800971F8[0].unk26 = M2C_FIELD(arg0, u16*, 0x94);
    if (M2C_FIELD(arg0, s8*, 0x5C) < D_800CCF5C) {
        if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
            func_80016C48(0, 0xE, 0);
            M2C_FIELD(arg0, s16*, 0x7C) = 3;
        }
        M2C_FIELD(arg0, s8*, 0x5C)++;
        func_8002CCB0(arg0, 0x40, 0x40);
        return;
    }
    D_800971F8[0].unk48 = 8;
    func_8003D330();
    func_80017A04(arg0);
    func_8002D230(arg0);
    func_8002CCB0(arg0, 0x40, 0x40);
    D_800FCE64 = M2C_FIELD(arg0, u16*, 0xE);
    M2C_FIELD(arg0, u8*, 5) = 4;
    M2C_FIELD(arg0, u8*, 6) = 0;
}
