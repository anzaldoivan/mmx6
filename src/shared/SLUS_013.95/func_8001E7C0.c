#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern struct X4_EngineObj D_800CCED0;
void func_80012890(s32 arg0);
M2C_UNK func_80013DE8();

void func_8001E7C0(u8* arg0) {
    arg0[0] = 6;
    D_800CCED0.character_state.bytes[0] = arg0[0xC];
    D_800CCED0.character_state.bytes[1] = arg0[0xD];
    arg0[0xC] = 0xD;
    arg0[0xD] = 1;
    arg0[0x36] = D_800CCED0.character_state.bytes[0];
    func_80013DE8();
    func_80012890(1);
}
