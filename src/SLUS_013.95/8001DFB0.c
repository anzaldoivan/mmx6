#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

#include "mmx6/state.h"

void func_8001DFB0(void* arg0) {
    if (D_80097420.transition.active == 0) {
        M2C_FIELD(arg0, u8*, 1) = (u8)(M2C_FIELD(arg0, u8*, 1) + 1);
    }
}

/* Adapted from sozud/mmx4 @807a01b src/main/E47C.c:func_8001E6BC, AGPL-3.0; proven shared with X6 by exact signature 3affa1eca32f (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
/* siblings in the same TU declare it as s32; view it as the upstream state block */
void func_8001D218();

void func_8001DFDC(struct X4_GameInfo* arg0) {
    if (D_80097420.transition.active == 0) {
        arg0->unkD = 1;
        func_8001D218();
        arg0->mode = 0;
        arg0->unk0++;
    }
}

#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32

void func_8002048C(void);
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
