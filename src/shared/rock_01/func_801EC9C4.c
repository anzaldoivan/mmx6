#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80017A04();
M2C_UNK func_8003BA04(void*, M2C_UNK);
extern struct X4_EngineObj g_playthrough_state;

void func_801EC9C4(s8* p) {
    if ((u8)p[0x17] == 6) {
        u8* g = (u8*)&g_playthrough_state;
        if (p[0x5C] >= (s8)((s8)(g - -p[2])[0x5B] / 3)) {
            func_8003BA04(p, 5);
            return;
        }
    }
    func_80017A04(p);
}
