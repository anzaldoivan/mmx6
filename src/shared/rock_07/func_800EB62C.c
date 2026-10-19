#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_8002C9B0();
M2C_UNK func_8003D330();

void func_800EB62C(struct X4_MainObj* arg0) {
    struct X4_MainObj* p = (struct X4_MainObj*)arg0->ext.raw[2];

    if (p->active != 0) {
        if (p->unk7 == 0) {
            if (--arg0->unk7E == -1) {
                arg0->unk7E = 5;
                arg0->unk42 ^= 0x8000;
            }
        }
    } else {
        func_8003D330();
        func_8002C9B0(arg0);
    }
}
