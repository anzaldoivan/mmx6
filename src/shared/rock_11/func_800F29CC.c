#include "common.h"

void func_800F4254(void* arg0, u8 arg1);
extern s8 D_800FD51A;
extern s8 D_800FD51B;
extern s8 D_800FD51E;
extern u8 D_800FD522;

#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define SH(p, o) (*(s16*)((u8*)(p) + (o)))

void func_800F29CC(void* arg0) {
    UB(arg0, 0x7) = 0;
    if (SH(arg0, 0x7C) != 0) {
        if (--SH(arg0, 0x7C) == 0x12) {
            D_800FD51B = 0;
            D_800FD51E = 0;
            D_800FD51A = 0;
            D_800FD522 = 0;
            func_800F4254(arg0, 0x10);
            func_800F4254(arg0, 0x11);
            func_800F4254(arg0, 0x12);
            func_800F4254(arg0, 0x13);
            UB(arg0, 0x6) = UB(arg0, 0x6) + 1;
        }
    }
}
