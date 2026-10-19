#include "common.h"
#include "mmx6/x4.h"

extern void (*D_800762C8[])(struct X4_MainObj*);
extern s8 D_80097180;
extern s8 D_800CCEF7;

void func_80047394(struct X4_MainObj* arg0) {
    D_800CCEF7 = 0;
    if (D_80097180 != 2) {
        D_800762C8[arg0->unk5](arg0);
    }
}
