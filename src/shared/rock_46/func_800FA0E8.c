#include "common.h"
#define M2C_UNK s32

void func_80025F34();
void func_800280F4(void);
void func_80029B8C(void);
s32 func_8002B2F8(s32);
M2C_UNK func_8002B838();
void func_8002C2B8();
void func_800E9ED4(void);
extern s8 D_80090D56;
extern s8 D_8009742C;
extern s8 D_800CF850;
extern u8 D_800EA510[];
extern u8 func_800FACCC[];

void func_800FA0E8(u8* arg0) {
    s32 i;

    func_8002B838();
    func_8002C2B8();
    func_80029B8C();
    func_800280F4();
    func_80025F34();
    {
        s8* p;
        s8* q;
        do {
            p = &D_80090D56;
            do {
                q = &D_8009742C;
            } while (0);
        } while (0);
        *p = 0;
        *q = 0;
        D_800CF850 = 0;
        ((void (*)(s32))func_8002B2F8)(0);
    }
    arg0[1]++;
    for (i = 0; i < 4; i++) {
        D_800EA510[i] = func_800FACCC[i];
    }
    func_800E9ED4();
}
