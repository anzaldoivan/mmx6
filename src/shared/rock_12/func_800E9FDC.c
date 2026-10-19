#include "common.h"

void func_80055D74(s8);
void func_8005B7A4(s32, s32);
void func_8005B834(s32);
void func_8005BA04(void);
extern s8 D_80090D64[];

void func_800E9FDC(void) {
    func_80055D74(D_80090D64[5]);
    D_80090D64[5] = -1;
    func_8005BA04();
    func_8005B834(0);
    func_8005B7A4(0, 0);
}
