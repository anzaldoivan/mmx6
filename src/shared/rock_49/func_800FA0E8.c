#include "common.h"
#define M2C_UNK s32

void func_80025F34();
void func_800280F4(void);
void func_80029B8C(void);
s32 func_8002B2F8(s32);
M2C_UNK func_8002B838();
void func_8002C2B8();
extern s8 D_80090D56;
extern s8 D_8009742C;
extern s8 D_800CCF08;
extern s8 D_800CF850;
extern u8 D_800EA510[];
extern u8 D_800FA46C[];
extern u8 func_800FA468[];

void func_800FA0E8(u8* arg0) {
    s32 i;

    func_8002B838();
    func_8002C2B8();
    func_80029B8C();
    func_800280F4();
    func_80025F34();
    {
        s8* p;
        s8* r;
        do {
            p = &D_80090D56;
            do {
                r = &D_8009742C;
            } while (0);
        } while (0);
        *p = 0;
        *r = 0;
        D_800CF850 = 0;
        ((void (*)(s32))func_8002B2F8)(0);
    }
    i = 0;
    arg0[1]++;
    do {
        if (D_800CCF08 == 0) {
            D_800EA510[i] = func_800FA468[i];
        } else {
            D_800EA510[i] = D_800FA46C[i];
        }
        i++;
    } while (i < 4);
}
