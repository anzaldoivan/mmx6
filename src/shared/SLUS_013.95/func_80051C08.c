#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_8003D330();
extern struct X4_EngineObj D_800CCED0;

void func_80051C08(s8* arg0) {
    if (arg0[0x45] != 0) {
        func_8003D330();
        D_800CCED0.unk16 = 0;
        D_800CCED0.unk12 = 0;
        D_800CCED0.unk13 = 0;
        D_800CCED0.unk17 = 0;
        arg0[5]++;
    }
}
