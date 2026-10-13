#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32

M2C_UNK func_8002048C();
void func_800206C0(void);
void func_800207D4(void);
void func_80025FB0();
void func_8002ACA8();
extern void (*D_80071118[])(struct X4_EngineObj*);

void func_8001E024(struct X4_EngineObj* arg0) {
    D_80071118[arg0->unk1](arg0);
    func_8002048C();
    func_800206C0();
    func_800207D4();
    func_8002ACA8();
    func_80025FB0();
}
