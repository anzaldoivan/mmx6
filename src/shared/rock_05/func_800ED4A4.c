#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
extern struct X4_BackgroundObj D_800971F8[3];

void func_800ED4A4(struct X4_MainObj* arg0) {
    if ((u32)((u8)arg0->unk2 - 8) < 2) {
        D_800971F8[0].unk28 = D_800971F8[0].unk2A;
        func_80016C48(5, 1, arg0);
        func_80012D9C(4);
    }
    arg0->unk7C = 0x78;
    arg0->unk6++;
}
