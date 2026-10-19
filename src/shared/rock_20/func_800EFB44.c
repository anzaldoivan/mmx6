#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800139F4(M2C_UNK);
void func_8001D218();
extern s8 D_80097424[];

void func_800EFB44(struct X4_EngineObj* arg0) {
    s8 v = arg0->unk2;

    if (v == 0) {
        ((void (*)(s32))func_800139F4)(8);
        arg0->unk2++;
    } else if (v == 1) {
        if (*D_80097424 == 0) {
            func_8001D218();
            arg0->unk2++;
        }
    } else if (v == 2) {
        arg0->unk1 = 8;
        arg0->unk2 = 0;
    }
}
