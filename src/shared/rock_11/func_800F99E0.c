#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void* alloc_class3_slot();
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern s8 D_800970A5;
extern struct X4_EngineObj g_playthrough_state;
extern s8* D_800FDA74;

void func_800F99E0(u8* arg0) {
    s8 s;
    s8* p;

    if (g_playthrough_state.unkF == 0) {
        s = D_800970A5;
        if (s == 0x14) {
            if (g_playthrough_state.stage != 0xC) {
                func_8003D308(0x1D, 0x40);
            }
            p = alloc_class3_slot();
            if (p != 0) {
                p[0] = 1;
                p[1] = 0x18;
                D_800FDA74 = p;
            }
            *(s16*)(arg0 + 0x7C) = s;
            arg0[6]++;
        }
    }
}
