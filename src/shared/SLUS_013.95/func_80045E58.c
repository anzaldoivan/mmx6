#include "common.h"
#include "mmx6/x4.h"

extern struct X4_PlayerObj g_Player;
extern void (*D_8007622C[])(s8*);

void func_80045E58(s8* arg0) {
    s8* p;
    s32 flag;

    p = (s8*)&g_Player;
    flag = p[0xD3] != 0;
    if (p[0xD4] != 0) {
        flag = 1;
    }
    if (p[0x93] != 7) {
        flag = 1;
    }
    if (flag != 0) {
        arg0[4] = 3;
    }
    D_8007622C[arg0[4]](arg0);
}
