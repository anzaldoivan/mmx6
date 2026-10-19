#include "common.h"
#include "mmx6/x4.h"

s32 func_80030DC0(u8* arg0, s8 arg1);
extern struct X4_PlayerObj D_800970A0;
extern s8 D_800CCEEC;

void func_8003D07C(s8 arg0) {
    struct X4_PlayerObj* p = &D_800970A0;

    *((s8*)p + 0xCA) = -1;
    if (p->hp & 0x7F) {
        if (arg0 != 0) {
            p->hp -= func_80030DC0((u8*)p, arg0);
        }
        if (p->hp > 0) {
            p->hp |= 0x80;
            return;
        }
        *((s8*)p + 0xCA) = 0;
        D_800CCEEC = 1;
        p->hp = -0x80;
    }
}
