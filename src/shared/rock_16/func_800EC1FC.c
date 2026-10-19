#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EngineObj D_800CCED0;
extern s8 D_800CCEF9;
extern s8 D_800F0EDC[];
extern s8 D_800F0F80[][0x18];

s32 func_800EC1FC(s32 arg0) {
    if (D_800F0F80[0][arg0] != 0) {
        return D_800CCEF9 != 0;
    }
    if (D_800F0F80[1][arg0] != 0) {
        return D_800CCEF9 != 1;
    }
    if (D_800F0F80[2][arg0] != 0) {
        return D_800F0EDC[((s8*)&D_800CCED0 +
                           D_800CCED0.character_state.bytes[3])[0x8D]] == 0;
    }
    return 0;
}
