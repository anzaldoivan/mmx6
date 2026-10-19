#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_80017A04(struct X4_AnimatedObj*);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
void func_801F0858(void* arg0);

void func_801F07C4(void* arg0) {
    func_80017A04(arg0);
    if (((s8*)arg0)[0x46] == 0) {
        func_801F0858(arg0);
        return;
    }
    ((void (*)(void*, s32, s32))func_8002CCB0)(arg0, 0x30, 0x30);
}
