/* Adapted from sozud/mmx4 @29b62af src/main/144A4.c:func_80023CE0, AGPL-3.0; proven shared with X6 by exact signature 6affe00825b4 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern struct X4_EngineObj D_800CCED0;
extern u8 D_80071D88[16][2];

void func_80025F34() {
    func_8002649C(0, D_80071D88[D_800CCED0.stage][D_800CCED0.substage]);
    func_8002798C();
}
