#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002D2D4();
M2C_UNK func_80049D90(void*);
void func_800F51F0(struct X4_AnimatedObj* arg0, u8 arg1);
extern s16 D_800970AA;
extern u16 D_800F70DC;

void func_800F2464(void* arg0) {
    s8 a;
    s16 y;
    s32 d;

    a = M2C_FIELD(M2C_FIELD(arg0, s8**, 0x80), s8*, 5);
    if (M2C_FIELD(arg0, s8*, 0x84) != a && a == 3 && (func_8002D2D4() & 1)) {
        if (M2C_FIELD(arg0, s8*, 2) == 0x12) {
            goto block_10;
        }
        goto block_12;
    }
    if (M2C_FIELD(arg0, s8*, 2) == 0x12) {
        y = M2C_FIELD(arg0, s16*, 0xA);
        d = y - D_800970AA;
        if (d < 0) {
            d = D_800970AA - y;
        }
        if (d < 0x21 || --M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        block_10:
            M2C_FIELD(arg0, u16**, 0x68) = &D_800F70DC;
            M2C_FIELD(arg0, s32*, 0x20) = 0;
            M2C_FIELD(arg0, s32*, 0x28) = 0;
            M2C_FIELD(arg0, s32*, 0x24) = 0;
            M2C_FIELD(arg0, s32*, 0x2C) = 0x4CCC;
            M2C_FIELD(arg0, u8*, 5) += 1;
        }
    } else if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
    block_12:
        func_80049D90(arg0);
        func_800F51F0(arg0, 0x10);
        func_800F51F0(arg0, 0x11);
        func_800F51F0(arg0, 0x12);
        M2C_FIELD(arg0, u8*, 4) = 5;
    }
}
