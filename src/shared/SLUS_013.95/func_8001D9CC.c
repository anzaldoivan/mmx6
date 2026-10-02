/* Adapted from sozud/mmx4 @29b62af src/main/11184.c:func_80020AC8, AGPL-3.0; proven shared with X6 by exact signature ffde10626a32 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern void (*D_800710D0[])(struct X4_EngineObj*);
void func_80025FB0();

void func_8001D9CC(struct X4_EngineObj* arg0) {
    D_800710D0[arg0->unk1](arg0);
    func_800206C0();
    func_8002ACA8();
    func_80025FB0();
}
