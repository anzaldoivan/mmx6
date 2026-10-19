#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern struct X4_EngineObj D_800CCED0;
extern u8 D_8007A124[];

M2C_UNK func_80053440(M2C_UNK arg0) {
    s32 b = 1 << arg0;
    u16* h = (u16*)((u8*)&D_800CCED0 + 0x9E) +
             D_8007A124[D_800CCED0.substage + D_800CCED0.stage * 2];
    *h |= b;
}
