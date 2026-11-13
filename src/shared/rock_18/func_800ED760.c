#include "common.h"
#include "mmx6/x4.h"

void func_800206C0(void);
void func_800207D4(void);
void func_80020D18(void);
void func_80025FB0();
void func_8002ACA8();
extern void (*D_800F08FC[])(struct X4_EngineObj*);

void func_800ED760(struct X4_EngineObj* arg0) {
    D_800F08FC[arg0->unk1](arg0);
    func_800206C0();
    func_800207D4();
    func_80020D18();
    func_8002ACA8();
    func_80025FB0();
}
