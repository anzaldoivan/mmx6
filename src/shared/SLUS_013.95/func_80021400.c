#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EngineObj D_800CCED0;

#define SAVE_C_U8 ((u8*)0x801F600C)

void func_80021400(void) {
    u8* s = SAVE_C_U8;
    u8* e = (u8*)&D_800CCED0;

    e[0x38] = s[0x38];
    e[0x5E] = s[0x5E];
    e[0xC] = s[0xC];
    e[0xD] = s[0xD];
}
