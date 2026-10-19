#include "common.h"
#include "mmx6/x4.h"

extern void (*D_80071214[])(struct X4_EngineObj*);
void func_800210E8();
void func_80025E1C();

void func_8001FFC0(struct X4_EngineObj* arg0) {
    D_80071214[arg0->unk7](arg0);
    func_800210E8();
    func_80025E1C();
}
