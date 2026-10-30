#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern u8 D_800970B5;
extern struct X4_EngineObj g_playthrough_state;

void func_800EB5C0(struct X4_MainObj* arg0) {
    g_playthrough_state.checkpoint = 2;
    arg0->unk7C = 0x7F;
    arg0->unk7E = 0x19;
    arg0->invincibility_timer = 0x19;
    arg0->unk42 &= 0x7FFF;
    arg0->unk5++;
    ((s8*)&g_playthrough_state)[0x26] = 1;
    func_8003D308(0x14, D_800970B5);
}
