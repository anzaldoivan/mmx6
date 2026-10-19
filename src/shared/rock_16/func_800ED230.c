#include "common.h"
#include "mmx6/x4.h"

extern u8 D_800F1CC4[];

void func_800ED230(struct X4_EngineObj* arg0) {
    arg0->unk8++;
    if ((s16)arg0->unk8 >= 8) {
        arg0->unk8 = 0;
        D_800F1CC4[1] = 0;
        D_800F1CC4[4] = 0;
        arg0->unk2++;
    }
}
