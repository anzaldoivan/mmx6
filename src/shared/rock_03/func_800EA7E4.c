#include "common.h"
#include "mmx6/x4.h"

#define SPAD (*(u8**)0x1F80004C)

void func_800EA7E4(struct X4_MainObj* arg0) {
    if (SPAD[0x87] == 1) {
        arg0->unk5 = 6;
        arg0->unk6 = 0;
    }
    if (--arg0->unk7C == 0) {
        arg0->unk5 = 4;
        arg0->unk6 = 0;
    }
}
