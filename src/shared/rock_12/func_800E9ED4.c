#include "common.h"

s32 func_80054B94(s32);
void func_80055D74(s8);
s32 func_80055F94(void*, s8, s32);
void func_8005A3CC(s8, u32, s32, s32);
void func_8005B7A4(s32, s32);
void func_8005B834(s32);
void func_8005BA24(void);
extern s8 D_80090D55;
extern s8 D_80090D64[];
extern s32 D_800E0D38;

void func_800E9ED4(void) {
    s32 t;

    if (D_80090D64[5] != -1) {
        func_80055D74(D_80090D64[5]);
    }
    t = func_80055F94((void*)D_800E0D38, D_80090D55, 1);
    D_80090D64[5] = t;
    func_8005A3CC(t, 0, 0x7F, 0x7F);
    func_8005B834(3);
    while (func_80054B94(3) == -1) {
    }
    func_8005BA24();
    func_8005B7A4(0x40, 0x40);
}
