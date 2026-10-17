#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80017A04();
s32 func_80040498();
extern struct X4_BackgroundObj D_800971F8[3];
extern s16 D_800F6AF8;

void func_800F2C74(struct X4_MainObj* arg0) {
    func_80017A04(arg0);
    if (func_80040498() == 0) {
        arg0->unk7E = 3;
        D_800971F8[0].unk26 = D_800F6AF8 + 0x640;
        D_800971F8[0].unk24 = D_800F6AF8 + 0x680;
        arg0->unk6++;
    }
}
