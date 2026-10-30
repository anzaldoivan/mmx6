#include "common.h"
#define M2C_UNK s32

void func_80025F34();
void func_800280F4(void);
void init_checkpoint_positions(void);
s32 func_8002B2F8(s32);
M2C_UNK reset_level();
void func_8002C2B8();
void func_800E9ED4(void);
extern s8 D_80090D56;
extern s8 D_8009742C;
extern s8 D_800CCF08;
extern s8 D_800CF850;
extern u8 D_800EA510[];
extern u8 D_800FA9D4[];
extern u8 func_800FA9D0[];

void func_800FA384(u8* arg0) {
    s32 i;

    reset_level();
    func_8002C2B8();
    init_checkpoint_positions();
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
            D_800EA510[i] = func_800FA9D0[i];
        } else {
            D_800EA510[i] = D_800FA9D4[i];
        }
        i++;
    } while (i < 4);
    func_800E9ED4();
}
