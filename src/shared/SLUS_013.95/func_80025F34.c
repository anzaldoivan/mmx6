/* Adapted from sozud/mmx4 @807a01b src/main/144A4.c:func_80023CE0, AGPL-3.0; proven shared with X6 by exact signature 6affe00825b4 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern struct X4_EngineObj g_playthrough_state;
extern u8 D_80071D88[16][2];

void func_80025F34() {
    func_8002649C(
        0, D_80071D88[g_playthrough_state.stage][g_playthrough_state.substage]);
    func_8002798C();
}
