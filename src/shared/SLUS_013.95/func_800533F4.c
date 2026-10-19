#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern struct X4_EngineObj D_800CCED0;
extern u8 D_8007A124[];

s32 func_800533F4(M2C_UNK arg0) {
    u8* p;
    u8* t = D_8007A124;
    s32 b;
    s32 i;
    do {
    } while (0);
    i = D_800CCED0.substage;
    i += D_800CCED0.stage * 2;
    p = i + t;
    b = (1 << arg0) & 0xFFFF;
    return ((((u16*)&D_800CCED0) + *p)[0x4F] & b) != 0;
}
