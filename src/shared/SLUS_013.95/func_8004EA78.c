#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04();
s32 func_8002CBFC(struct X4_AnimatedObj* arg0, s32 arg1, s32 arg2);
void func_8002CCB0(struct X4_BaseObj* arg0, s32 arg1, s32 arg2);
s32 func_8004EECC(void*);
s32 func_8004FE8C();
void func_8004FF00(u8, s32);
extern s32 D_80097420;

void func_8004EA78(u8* arg0) {
    s8 temp_s1;

    ((M2C_UNK(*)())func_80017A04)();
    if (func_8004FE8C(arg0) != 0) {
        if (arg0[0x84] == 0) {
            if (arg0[0x7E] == 0) {
                if (arg0[0x82] == 0) {
                    func_800179A4(arg0, 0);
                } else {
                    func_800179A4(arg0, 0xB);
                }
            } else if (arg0[0x82] == 0) {
                func_800179A4(arg0, 5);
            } else {
                func_800179A4(arg0, 0xE);
            }
        } else if (arg0[0x82] == 0) {
            func_800179A4(arg0, 0x17);
        } else {
            func_800179A4(arg0, 0x1E);
        }
    }
    if (func_8004EECC(arg0) == 0) {
        temp_s1 = ((s8*)arg0)[7];
        if (temp_s1 == 2) {
            func_8004FF00(arg0[2], 4);
            arg0[4] = 6;
            arg0[5] = temp_s1;
            arg0[6] = 0;
            goto block_24;
        }
        if (arg0[0x7E] == 1) {
            *(s16*)(arg0 + 0xE) =
                *(u16*)(arg0 + 0x7C) + (rsin((D_80097420 & 0x7F) << 5) >> 0xA);
        }
        if (func_8002CBFC(arg0, 0x30, 0x30) == 0) {
            if (arg0[0x84] == 0) {
                func_8002CCB0(arg0, 0x10, 0x20);
            } else {
                func_8002CCB0(arg0, 0x20, 0x20);
            }
            return;
        }
        if (arg0[2] != 0x80) {
            arg0[3] = 0;
            arg0[4] = 7;
            goto block_24;
        }
    } else {
    block_24:
        arg0[7] = 0;
    }
}
