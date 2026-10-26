#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern struct X4_EngineObj D_800CCED0;
void func_8003CF24(s32, s32, s32);
M2C_UNK player_spawn_visual(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2,
                            M2C_UNK arg3);

M2C_UNK func_8003D718(void* arg0) {
    u8* o = arg0;
    u8 m = D_800CCED0.sub_tanks[2];

    o[0xE7] = m;
    *(s32*)(o + 0xEC) = *(s32*)((u8*)&D_800CCED0 + 0x74 + ((s8*)o)[2] * 4);
    if (m == 2) {
        o[0xC9] = 0;
        player_spawn_visual(1, 0x1B, 5, 0);
        func_8003CF24(2, 0x19, 1);
        func_8003CF24(2, 0x18, 1);
        return;
    }
    o[0xC9] = D_800CCED0.unk60;
}
