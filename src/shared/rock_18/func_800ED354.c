#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, M2C_UNK);
extern struct X4_EngineObj D_80097420;
extern u16 D_800C4570;
extern s8 D_800CCED1;
extern void (*D_800F0914[])(struct X4_EngineObj*);

void func_800ED354(struct X4_EngineObj* arg0) {
    u8 var_s0;

    if (D_800CCED1 != 0) {
        struct X4_EngineObj* e = &D_80097420;
        var_s0 = (u8)e->unk7;
    } else {
        var_s0 = 0;
    }
    D_800F0914[arg0->unk1](arg0);
    {
        struct X4_EngineObj* e = &D_80097420;
        if (((u8)e->unk7 != var_s0) && !(D_800C4570 & 0x50)) {
            func_80016C48(0, 0xC, 0);
        }
    }
}
