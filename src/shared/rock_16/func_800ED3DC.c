#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EngineObj D_800CCED0;

void func_800ED3DC(u8* arg0) {
    if (D_800CCED0.character_state.bytes[6] == 1) {
        s32 v = arg0[3];
        D_800CCED0.character_state.bytes[6] = 2;
        D_800CCED0.character_state.bytes[5] = v;
        arg0[2]++;
    }
}
