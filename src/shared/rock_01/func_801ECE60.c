#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_8003AAD0();
void func_8003AD18(void* arg0);
void func_8003B870(struct X4_PlayerObj* self);
extern s8 D_800CCEDF;

void func_801ECE60(void* arg0) {
    s8* p = arg0;

    if (p[0x46] == 0) {
        p[0x8E] = 0;
        if (D_800CCEDF != 0) {
            func_8003B870((struct X4_PlayerObj*)p);
            return;
        }
        if (p[0xD0] != 0) {
            func_8003AAD0(p);
            return;
        }
        func_8003AD18(p);
    }
}
