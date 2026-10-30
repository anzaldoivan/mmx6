#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
extern struct X4_EngineObj g_playthrough_state;

M2C_UNK func_8004E78C(M2C_UNK arg0) {
    u8 v = arg0;
    u8* e = (u8*)&g_playthrough_state;

    e[0x10] = v;
    e[0x11] = v;
    e[0x12] = v;
    e[0x13] = v;
    e[0x14] = v;
    e[0x15] = v;
    e[0x16] = v;
    e[0x17] = v;
    e[0x19] = v;
}
