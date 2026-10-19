#include "common.h"
#include "mmx6/x4.h"

void func_800EBD6C(struct X4_EngineObj* arg0);
extern s16 D_80097256;
extern u8 D_800F1CC4[];

void func_800ECE84(struct X4_EngineObj* arg0) {
    if (D_80097256 == 0x200) {
        arg0->unk2 += 2;
        func_800EBD6C(arg0);
        return;
    }
    if (++arg0->unk8 >= 8) {
        arg0->unk8 = 0;
        D_800F1CC4[0] = 0;
        D_800F1CC4[3] = 0;
        arg0->unk2++;
        func_800EBD6C(arg0);
    }
}
