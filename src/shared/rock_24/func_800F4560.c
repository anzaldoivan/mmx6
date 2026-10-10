#include "common.h"
#define M2C_UNK s32

#ifndef M2C_FIELD
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#endif

M2C_UNK func_80017A04(void*);
void func_80027BA0(s32, s32, s32, void*);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
M2C_UNK func_80049E50(void*);
extern s8 D_80097244;
extern u8 D_800F7518[];
extern u8 D_800F7548[];
extern s16 D_800F77F8;
extern s16 D_800F77FA;
extern s16 D_800F77FC;

void func_800F4560(void* arg0) {
    s32 d;

    switch (M2C_FIELD(arg0, s8*, 5)) {
    case 0:
        if (D_800F77F8 != 0) {
            d = D_800F77FA - M2C_FIELD(arg0, s16*, 0xA);
            if (d >= 0) {
                if (d < 0x18) {
                    goto near_x;
                }
            } else if ((M2C_FIELD(arg0, s16*, 0xA) - D_800F77FA) < 0x18) {
            near_x:
                d = D_800F77FC - M2C_FIELD(arg0, s16*, 0xE);
                if (d >= 0) {
                    if (d < 0x60) {
                        goto near_y;
                    }
                } else if ((M2C_FIELD(arg0, s16*, 0xE) - D_800F77FC) < 0x60) {
                near_y:
                    func_80049E50(arg0);
                    M2C_FIELD(arg0, s32*, 0x8C) = 0;
                    M2C_FIELD(arg0, s8*, 5)++;
                }
            }
        }
    draw:
        func_8002CCB0(arg0, 0x40, 0x20);
        break;
    case 1:
        if (++M2C_FIELD(arg0, s32*, 0x8C) == 0x14) {
            M2C_FIELD(arg0, s32*, 0x8C) = 0;
            ((s32(*)(s32, s32, s32, void*))func_80027BA0)(
                0, M2C_FIELD(arg0, s16*, 0xA) - 0x10,
                M2C_FIELD(arg0, s16*, 0xE) - 0x18,
                D_800F7548 + M2C_FIELD(arg0, s8*, 2) * 8);
            D_80097244 = 1;
            M2C_FIELD(arg0, s8*, 5)++;
        }
        if (M2C_FIELD(arg0, s32*, 0x8C) & 1) {
            func_8002CCB0(arg0, 0x40, 0x20);
        }
        break;
    case 2:
        if (++M2C_FIELD(arg0, s32*, 0x8C) == 0xB4) {
            M2C_FIELD(arg0, s32*, 0x8C) = 0;
            M2C_FIELD(arg0, s8*, 5)++;
        }
        break;
    case 3:
        if (++M2C_FIELD(arg0, s32*, 0x8C) == 0x3C) {
            ((s32(*)(s32, s32, s32, void*))func_80027BA0)(
                0, M2C_FIELD(arg0, s16*, 0xA) - 0x10,
                M2C_FIELD(arg0, s16*, 0xE) - 0x18,
                D_800F7518 + M2C_FIELD(arg0, s8*, 2) * 8);
            D_80097244 = 1;
            M2C_FIELD(arg0, s8*, 5) = 0;
        }
        if (M2C_FIELD(arg0, s32*, 0x8C) & 1) {
            func_8002CCB0(arg0, 0x40, 0x20);
        }
        break;
    }
    func_80017A04(arg0);
    func_8002D230(arg0);
}
