#include "common.h"
#include "mmx6/x4.h"

extern u8 D_800720AC[];
extern struct X4_EngineObj g_playthrough_state;

void func_80029718(struct X4_BackgroundObj* arg0) {
    arg0->unk4 = D_800720AC[g_playthrough_state.stage * 4 +
                            g_playthrough_state.substage * 2];
}
