#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8003D330();
extern struct X4_BackgroundObj D_800971F8[3];

void func_800EC0E8(struct X4_MainObj* arg0) {
    if ((s16)D_800971F8[1].unk42 >= -0x4F) {
        D_800971F8[1].unk42--;
        if (arg0->unk7C == 0) {
            func_8002943C(0xA, 2, 2);
            arg0->unk7C = 0xA;
        } else {
            arg0->unk7C--;
        }
        return;
    }
    func_80016C48(5, 3, arg0);
    func_8003D330();
    D_800971F8[0].unk26 = 0x1AD0;
    D_800971F8[0].unk24 = 0x1CC0;
    D_800971F8[1].unk3 = 0;
    D_800971F8[0].unk2E += 0x10;
    arg0->state = 2;
}
