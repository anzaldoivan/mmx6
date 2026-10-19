#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EngineObj D_800CCED0;
extern u8 D_800F1CB0[];

void func_800ECD80(u8* arg0) {
    if (++*(s16*)(arg0 + 8) >= 8) {
        *(s16*)(arg0 + 8) = 0;
        D_800CCED0.character_state.bytes[11] = 0;
        D_800CCED0.character_state.bytes[2] =
            D_800F1CB0[D_800CCED0.character_state.bytes[10]];
        arg0[2]--;
    }
}
