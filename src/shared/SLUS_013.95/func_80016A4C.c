#include "common.h"

void func_80055D74(s8);
void func_80055DA4(void);
void func_80058574(void);
void func_8005B7A4(s32, s32);
void func_8005B834(s32);
void func_8005BA04(void);
void func_8005FD74(s32);
extern s8 D_80090D50[6];
extern s8 D_80090D64[];

void func_80016A4C(void) {
    s8 i;

    for (i = 0; i < 6; i++) {
        if (D_80090D50[i] != -1) {
            func_8005FD74(D_80090D50[i]);
            D_80090D50[i] = -1;
        }
    }
    for (i = 0; i < 6; i++) {
        if (D_80090D64[i] != -1) {
            func_80055D74(D_80090D64[i]);
            D_80090D64[i] = -1;
        }
    }
    func_8005BA04();
    func_8005B834(0);
    func_8005B7A4(0, 0);
    func_80055DA4();
    func_80058574();
}
