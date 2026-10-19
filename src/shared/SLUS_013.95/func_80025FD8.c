#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
extern M2C_UNK D_800970A0;
extern struct X4_EngineObj D_800CCED0;
extern u8 D_80071D80[];

void func_80025FD8(void) {
    s8* pl = (s8*)&D_800970A0;
    u8* e = (u8*)&D_800CCED0;
    if (*(u16*)(e + 0xC) == 0xC) {
        e[0x8F] = 3;
        return;
    }
    {
        s32 i = pl[2];
        e[0x8F] = D_80071D80[((s8*)(e - -i))[0x8D]];
    }
}
