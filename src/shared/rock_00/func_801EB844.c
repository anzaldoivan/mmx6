#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_80017A04(struct X4_AnimatedObj*);
M2C_UNK func_8003B114(s32);
M2C_UNK func_8003C4EC();
extern void (*D_801F3724[])(void*);

void func_801EB844(s8* arg0) {
    if (arg0[0xD3] != 0) {
        arg0[0xE0] = 0;
        ((void (*)())func_8003C4EC)();
        func_8003B114((s32)arg0);
        return;
    }
    func_80017A04((struct X4_AnimatedObj*)arg0);
    D_801F3724[arg0[6]](arg0);
}
