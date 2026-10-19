#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_80017A04(struct X4_AnimatedObj*);
s32 func_8002CBFC(struct X4_BaseObj*, s32, s32);
M2C_UNK func_8002D230(void*);

void func_801F11B0(struct X4_BaseObj* arg0) {
    if (func_8002CBFC(arg0, 0x18, 0x18) == 0) {
        func_80017A04((struct X4_AnimatedObj*)arg0);
        func_8002D230(arg0);
        return;
    }
    arg0->state++;
}
