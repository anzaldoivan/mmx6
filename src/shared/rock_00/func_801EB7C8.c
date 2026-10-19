#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_80017A04(struct X4_AnimatedObj*);
M2C_UNK func_8003AFF4(s32);
s32 func_8003E174(void*);
extern void (*D_801F36F8[])(void*);

void func_801EB7C8(s8* arg0) {
    if (arg0[0xD3] != 0) {
        ((void (*)())func_8003AFF4)();
        return;
    }
    if (func_8003E174(arg0) == 0) {
        func_80017A04((struct X4_AnimatedObj*)arg0);
        D_801F36F8[arg0[6]](arg0);
    }
}
