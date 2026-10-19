#include "common.h"
#include "mmx6/x4.h"

extern s8 D_800CCEF6;
extern u8 D_800F1CF9;

void func_800ECC2C(struct X4_EngineObj* arg0) {
    arg0->unk8++;
    if ((s16)arg0->unk8 >= 8) {
        D_800CCEF6 = 0;
        D_800F1CF9 = 0;
        arg0->unk8 = 0;
        arg0->unkA = 0;
        arg0->unk2++;
    }
}
