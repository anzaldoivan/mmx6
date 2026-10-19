#include "common.h"
#include "mmx6/x4.h"

void func_8003AAD0();
void func_8003B870(struct X4_PlayerObj* self);
extern s8 D_800CCEDF;

s32 func_8003A628(void* arg0) {
    if (D_800CCEDF != 0) {
        func_8003B870(arg0);
        return 1;
    }
    if (((s8*)arg0)[0xD0] <= 0) {
        return 0;
    }
    func_8003AAD0();
    return 1;
}
