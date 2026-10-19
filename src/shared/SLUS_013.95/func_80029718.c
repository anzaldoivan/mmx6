#include "common.h"
#include "mmx6/x4.h"

extern u8 D_800720AC[];
extern struct X4_EngineObj D_800CCED0;

void func_80029718(struct X4_BackgroundObj* arg0) {
    arg0->unk4 = D_800720AC[D_800CCED0.stage * 4 + D_800CCED0.substage * 2];
}
